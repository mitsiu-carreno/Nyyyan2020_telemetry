#include "constants.hpp"
#include "thread.hpp"
#include "typeAlias.hpp"
#include "packetHeader.hpp"
#include "motionPacket.hpp"
#include <string>

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
