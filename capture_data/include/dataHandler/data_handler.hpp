#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include "type_alias_F1.hpp"
#include "header_packet.hpp"

#include "lap_packet.hpp"
#include "car_telemetry_packet.hpp"

namespace DataHandler{
  
  inline const short kPacketIdPadding = 
    sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_packetFormat)
    + sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_gameMajorVersion)
    + sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_gameMinorVersion)
    + sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_packetVersion);

  void DebugCarTelemetry(PacketCarTelemetryData*);
  void DebugLap(PacketLapData*);
  void ProcessBuffer(char*, int);
  void WritePacket(uint64, uint8, float, float, float);
};

#endif
