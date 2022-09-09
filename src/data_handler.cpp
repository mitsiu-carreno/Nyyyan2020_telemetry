#include <iostream>
#include <string>

#include "constants.hpp"
#include "data_handler.hpp"

void DataHandler::PrintHeader(char packet[constants::kMaxPacketSize]){
  
  std::cout << "Start......\n";
      PacketHeader * test = reinterpret_cast<PacketHeader *>(packet);
      std::cout << "Packet format\n";
      std::cout << test->m_packetFormat << "\n";
      printf("%x\n", test->m_packetFormat);
      std::cout <<"Game Major Version\n";
      std::cout << (int)test->m_gameMajorVersion << "\n";
  printf("%x\n", packet[2]);
      std::cout <<"Game Minor Version\n";
      std::cout << (int)test->m_gameMinorVersion <<"\n";
  printf("%x & %d", packet[3], packet[3]);
      std::cout <<"Paccket Version\n";
      std::cout << (int)test->m_packetVersion << "\n";
  printf("%x\n", packet[4]);
      std::cout <<"PacketId\n";
      std::cout << (int)test->m_packetId << "\n";
  printf("%x\n", packet[5]);
}

void DataHandler::GetPacketData(char packet[constants::kMaxPacketSize], int packet_id){
  void * packet_data = nullptr;
  switch(packet_id){
    case 0: 
      packet_data = reinterpret_cast<struct PacketMotionData*>(packet);
      break;
  } 
  if(packet_data != nullptr){
    PacketMotionData *packet = reinterpret_cast<struct PacketMotionData*>(packet_data);
    //std::cout << (int)reinterpret_cast<struct PacketMotionData*>(packet_data)->m_header.m_packetId << "\n";
    std::cout << (int)packet->m_header.m_packetId << "\n";
    //Plot(packet->m_carMotionData[packet->m_header.m_playerCarIndex].m_worldPositionX,
    //     packet->m_carMotionData[packet->m_header.m_playerCarIndex].m_worldPositionY);
    plot->UpdatePosition(packet->m_carMotionData[packet->m_header.m_playerCarIndex].m_worldPositionX,
      packet->m_carMotionData[packet->m_header.m_playerCarIndex].m_worldPositionY);
    
  }
  //return packet_data;
}

