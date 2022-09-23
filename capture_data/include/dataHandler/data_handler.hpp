#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include "type_alias_F1.hpp"
#include "header_packet.hpp"
#include "motion_packet.hpp"

namespace DataHandler{
  
  inline const short kPacketIdPadding = 
    sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_packetFormat)
    + sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_gameMajorVersion)
    + sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_gameMinorVersion)
    + sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_packetVersion);

  void DebugMotion(char *, PacketMotionData *);
  void MarshallPacket(char *, int);
  void WritePacket(uint16, float, float);
};

#endif
