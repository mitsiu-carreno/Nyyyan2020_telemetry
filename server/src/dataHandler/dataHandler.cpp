#include "constants.hpp"
#include "thread.hpp"
#include "typeAlias.hpp"
#include "packetHeader.hpp"
#include "motionPacket.hpp"
#include <string>
#include <cstdint>
#include <cstring>

typedef std::uint_fast8_t   uint8;
typedef std::int_fast8_t    int8;
typedef std::uint_fast16_t  uint16;
typedef std::int_fast16_t   int16;
typedef std::uint_fast32_t  uint32;
typedef std::int_fast32_t   int32;
typedef std::uint_fast64_t  uint64; 

struct PacketHeader
{
    uint16    m_packetFormat;             // 2020
    uint8     m_gameMajorVersion;         // Game major version - "X.00"
    uint8     m_gameMinorVersion;         // Game minor version - "1.XX"
    uint8     m_packetVersion;            // Version of this packet type, all start from 1
    uint8     m_packetId;                 // Identifier for the packet type, see below
    uint64    m_sessionUID;               // Unique identifier for the session
    float     m_sessionTime;              // Session timestamp
    uint32    m_frameIdentifier;          // Identifier for the frame the data was retrieved on
    uint8     m_playerCarIndex;           // Index of player's car in the array
    
   // ADDED IN BETA 2: 
    uint8     m_secondaryPlayerCarIndex;  // Index of secondary player's car in the array (splitscreen)
                                          // 255 if no second player
};

PacketHeader pHeader;



namespace datahandler{

  void PrintPacketHeader(PacketHeader *test){
    thread::PrintSafe("packet_format: " + std::to_string(test->m_packetFormat) + "\n");
    thread::PrintSafe("packet_major_version: " + std::to_string(test->m_gameMajorVersion) + "\n");
    thread::PrintSafe("packet_minor_version: " + std::to_string(test->m_gameMinorVersion) + "\n");
    thread::PrintSafe("packet_packet_version: " + std::to_string(test->m_packetVersion) + "\n");
    thread::PrintSafe("packet_id: " + std::to_string(test->m_packetId) + "\n");
    thread::PrintSafe("session_uid: " + std::to_string(test->m_sessionUID) + "\n");
    thread::PrintSafe("session_time: " + std::to_string(test->m_sessionTime) + "\n");
    thread::PrintSafe("frame_identifier: " + std::to_string(test->m_frameIdentifier) + "\n");
    thread::PrintSafe("player_car_index: " + std::to_string(test->m_playerCarIndex) + "\n");
    thread::PrintSafe("second_player_car_index: " + std::to_string(test->m_secondaryPlayerCarIndex) + "\n");
  }

  void PrintData(char (&buffer)[constants::kMaxBytesMsg]){

    // op1
    //char header_arr [sizeof(PacketHeader)];
    //memcpy(header_arr, &buffer[0], sizeof(PacketHeader));
    //PacketHeader *packet_header = reinterpret_cast<struct PacketHeader*>(header_arr);
    // op2
    PacketHeader *packet_header = reinterpret_cast<struct PacketHeader *>(&buffer);
    // Stop if casting fail
    if(packet_header == nullptr){
      return;
    }

    PrintPacketHeader(packet_header);

    switch(packet_header->m_packetId){
      case PacketIdDetail::motion:{
        thread::PrintSafe("motion package\n");
        
        PacketMotionData *test2 = reinterpret_cast<struct PacketMotionData*>(&buffer);
 
        thread::PrintSafe("x_position: " + std::to_string(test2->m_carMotionData[0].m_worldPositionX) + "\n");
        thread::PrintSafe("y_position: " + std::to_string(test2->m_carMotionData[0].m_worldPositionY) + "\n");
        thread::PrintSafe("force_longitudinal: " + std::to_string(test2->m_carMotionData[0].m_gForceLongitudinal) + "\n");
        thread::PrintSafe("force_lateral: " + std::to_string(test2->m_carMotionData[0].m_gForceLateral) + "\n\n");
        break;
      }
      default:
        thread::PrintSafe("other package\n");
        break;
    }
  }
}
