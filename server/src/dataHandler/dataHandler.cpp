#include "constants.hpp"
#include "thread.hpp"
#include "type_alias.hpp"
#include "packetHeader.hpp"
#include "motion_packet.hpp"
#include <istream>
#include <string>
#include <cstdint>

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

  void PrintData(char buffer[constants::kMaxBytesMsg]){
/*
    uint8 packet_type = buffer.header.m_packetId;
    thread::PrintSafe(std::to_string(packet_type));
*/

   
    //thread::PrintSafe("test: " + std::to_string(sizeof(buffer)) + "\n");

    char subTest [sizeof(PacketHeader) +1];

    memcpy(subTest, &buffer[0], sizeof(PacketHeader));
    
    PacketHeader *test = (struct PacketHeader*) subTest;
    //PrintPacketHeader(*test);

    switch(test->m_packetId){
      case PacketIdDetail::motion:{
        thread::PrintSafe("motion package\n");
        
        char subsubTest [sizeof(PacketMotionData) +1];
        memcpy(subsubTest, &buffer[0], sizeof(PacketMotionData));
        PacketMotionData *test2 = (struct PacketMotionData*) subsubTest;
       
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
