#include <iostream>
#include <string>
#include <fstream>

#include "constants.hpp"
#include "data_handler.hpp"
#include "header_packet.hpp"

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

void DataHandler::DebugMotion(char *buffer, PacketMotionData *packet_addr){

  std::cout << "-------Header packet\n";
      std::cout << "Packet format " << sizeof(packet_addr->m_header.m_packetFormat) << "\n";
  printf("struct: %u struct: %x packet: %x%x\n", packet_addr->m_header.m_packetFormat, packet_addr->m_header.m_packetFormat, buffer[0], buffer[1]);
      std::cout <<"Game Major Version " << sizeof(packet_addr->m_header.m_gameMajorVersion) <<"\n";
  printf("struct: %u struct: %x packet: %x\n", packet_addr->m_header.m_gameMajorVersion, packet_addr->m_header.m_gameMajorVersion, buffer[2]);
      std::cout <<"Game Minor Version " << sizeof(packet_addr->m_header.m_gameMinorVersion) <<"\n";
  printf("struct: %u struct: %x packet: %x\n", packet_addr->m_header.m_gameMinorVersion, packet_addr->m_header.m_gameMinorVersion, buffer[3]);
      std::cout <<"Paccket Version " << sizeof(packet_addr->m_header.m_packetVersion) <<"\n";
  printf("struct: %u struct: %x packet: %x\n", packet_addr->m_header.m_packetVersion, packet_addr->m_header.m_packetVersion, buffer[4]);
      std::cout <<"PacketId " << sizeof(packet_addr->m_header.m_packetId) <<"\n";
  printf("struct: %u struct: %x packet: %x\n", packet_addr->m_header.m_packetId, packet_addr->m_header.m_packetId, buffer[5]);
      std::cout <<"Session UID " << sizeof(packet_addr->m_header.m_sessionUID) <<"\n";
  printf("struct: %lu struct: %lx packet: %x%x%x%x%x%x%x%x\n", packet_addr->m_header.m_sessionUID, packet_addr->m_header.m_sessionUID, buffer[6], buffer[7], buffer[8], buffer[9], buffer[10], buffer[11], buffer[12], buffer[13]);
      std::cout <<"session time " << sizeof(packet_addr->m_header.m_sessionTime) <<"\n";
  printf("struct: %f struct: %f packet: %x%x%x%x\n", packet_addr->m_header.m_sessionTime, packet_addr->m_header.m_sessionTime, buffer[14], buffer[15], buffer[16], buffer[17]);
      std::cout <<"m_frameIdentifier " << sizeof(packet_addr->m_header.m_frameIdentifier) <<"\n";
  printf("struct: %u struct: %x packet: %x%x%x%x\n", packet_addr->m_header.m_frameIdentifier, packet_addr->m_header.m_frameIdentifier, buffer[18], buffer[19], buffer[20], buffer[21]);
      std::cout <<"m_playerCarIndex " << sizeof(packet_addr->m_header.m_playerCarIndex) <<"\n";
  printf("struct: %u struct: %x packet: %x\n", packet_addr->m_header.m_playerCarIndex, packet_addr->m_header.m_playerCarIndex, buffer[22]);
      std::cout << "m_secondaryPlayerCarIndex " << sizeof(packet_addr->m_header.m_secondaryPlayerCarIndex) << "\n";
  printf("struct: %u struct: %x packet: %x\n", packet_addr->m_header.m_secondaryPlayerCarIndex, packet_addr->m_header.m_secondaryPlayerCarIndex, buffer[23]);
  
  
  std::cout << "---------Motion packet\n";
  for(size_t i{0}; i<1; ++i){
    std::cout << "-----Car " << i << "\n";
    union {
        float f;
        uint32_t u;
    } f2u = { .f = packet_addr->m_carMotionData[i].m_worldPositionX };
        std::cout << "World space X position " << sizeof(packet_addr->m_carMotionData[i].m_worldPositionX) << "\n";
    printf("struct: %f struct: %x struct: 0x%" PRIx32 " packet: %x%x%x%x addr: %p\n", 
        packet_addr->m_carMotionData[i].m_worldPositionX, 
        (unsigned int)packet_addr->m_carMotionData[i].m_worldPositionX, 
        f2u.u, 
        buffer[24*(i+1)], buffer[25*(i+1)], buffer[26*(i+1)], buffer[27*(i+1)], 
        &packet_addr->m_carMotionData[i].m_worldPositionX
    );
        std::cout << "World space Y position " << sizeof(packet_addr->m_carMotionData[i].m_worldPositionY) << "\n";
    printf("struct: %f struct: %f packet: %x%x%x%x\n", packet_addr->m_carMotionData[i].m_worldPositionY, packet_addr->m_carMotionData[i].m_worldPositionY, buffer[28*(i+1)], buffer[29*(i+1)], buffer[30*(i+1)], buffer[31*(i+1)]);
        std::cout << "World space Z position " << sizeof(packet_addr->m_carMotionData[i].m_worldPositionZ) << "\n";
    printf("struct: %f struct: %f packet: %x%x%x%x\n", packet_addr->m_carMotionData[i].m_worldPositionZ, packet_addr->m_carMotionData[i].m_worldPositionZ, buffer[32*(i+1)], buffer[33*(i+1)], buffer[34*(i+1)], buffer[35*(i+1)]);
  }
  
  //printf("struct: %u struct: %x packet: %x%x\n", packet_addr->, packet_addr->, buffer[], buffer[]);

}

void DataHandler::MarshallPacket(char *buffer, int packet_id){
  void * ptr_packet_data = nullptr;
  switch(packet_id){
    case 0: 
      try{
        ptr_packet_data = new PacketMotionData;
      }catch(...){ // TODO catch actual exception
        std::cout << "FAILED TO STORE PACKET\n";
      }
      
   std::cout << "------Marshall motion packet-------------------------START\n"; 
      unsigned int buffer_offset = 0;
      MotionMarshall(ptr_packet_data, buffer, MotionMarshall::motion_descriptor, sizeof(MotionMarshall::motion_descriptor), buffer_offset); 
      std::cout << "---------------------------------------------------END\n";
      //DataHandler::DebugHeader(buffer, reinterpret_cast<PacketHeader*>(&(reinterpret_cast<PacketMotionData*>(ptr_packet_data)->m_header)));
      DataHandler::DebugMotion(buffer, reinterpret_cast<PacketMotionData*>(ptr_packet_data));
      break;
  } 
}

void WritePacket(){
  
    std::ofstream write_file;
    write_file.open("test", std::ofstream::app);
    //write_file << packet->m_carMotionData[packet->m_header.m_playerCarIndex].m_worldPositionX << "," << packet->m_carMotionData[packet->m_header.m_playerCarIndex].m_worldPositionY;
    write_file.close();
}

