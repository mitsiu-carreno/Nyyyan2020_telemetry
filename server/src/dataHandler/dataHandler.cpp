#include "constants.hpp"
#include "thread.hpp"
#include <istream>
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

  void PrintData(char buffer[constants::kMaxBytesMsg]){
/*
    uint8 packet_type = buffer.header.m_packetId;
    thread::PrintSafe(std::to_string(packet_type));
*/

   
    //thread::PrintSafe("test: " + std::to_string(sizeof(buffer)) + "\n");

    char subTest [sizeof(PacketHeader) +1];

    std::memcpy(subTest, &buffer[0], sizeof(PacketHeader));
    
    PacketHeader *test = (struct PacketHeader*) subTest;
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
}
