#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include "F1_types_alias.hpp"
#include "packet_header.hpp"
#include "motion_packet.hpp"

namespace DataHandler{
  
  inline const short kPacketIdPadding = 
    sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_packetFormat)
    + sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_gameMajorVersion)
    + sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_gameMinorVersion)
    + sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_packetVersion);

  void PrintHeader(char [constants::kMaxPacketSize]);
  //void* GetPacketData(char [constants::kMaxPacketSize], int packet_id);
  void GetPacketData(char [constants::kMaxPacketSize], int);
};

#endif
