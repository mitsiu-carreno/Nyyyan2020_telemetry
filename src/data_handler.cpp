#include "constants.hpp"
#include "data_handler.hpp"

#include <iostream>
#include <string>

uint8 DataHandler::GetPacketId(char packet[constants::kMaxPacketSize]){
  PacketHeader *ph = reinterpret_cast<struct PacketHeader *>(&packet);
  std::cout << "Start......\n";
  std::cout << std::to_string(ph->m_packetFormat) << "\n";
  std::cout << std::to_string(ph->m_gameMajorVersion) << "\n";
  std::cout << std::to_string(ph->m_gameMinorVersion) << "\n";
  std::cout << std::to_string(ph->m_packetId) << "\n";

  //uint8 packetId = packet[40];
  //std::cout << packetId << "-TEST\n";
  //return packetId;
  return 1;
}



