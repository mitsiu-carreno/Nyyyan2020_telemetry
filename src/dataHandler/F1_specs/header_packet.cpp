#include <cstddef>  // offsetof

#include "header_packet.hpp"
#include "F1_types_alias.hpp"

  // [0] = sizeof member attribute, [1] = struct offset to member attribute, [2] = sizeof one member attribute (identify arrays)
unsigned int HeaderMarshall::header_descriptor [10][4] ={
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_packetFormat),
    offsetof(PacketHeader, m_packetFormat),
    sizeof(uint16),
    F1_types::kUint16
  },
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_gameMajorVersion),
    offsetof(PacketHeader, m_gameMajorVersion),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_gameMinorVersion),
    offsetof(PacketHeader, m_gameMinorVersion),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_packetVersion),
    offsetof(PacketHeader, m_packetVersion),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_packetId),
    offsetof(PacketHeader, m_packetId),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_sessionUID),
    offsetof(PacketHeader, m_sessionUID),
    sizeof(uint64),
    F1_types::kUint64
  },
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_sessionTime),
    offsetof(PacketHeader, m_sessionTime),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_frameIdentifier),
    offsetof(PacketHeader, m_frameIdentifier),
    sizeof(uint32),
    F1_types::kUint32
  },
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_playerCarIndex),
    offsetof(PacketHeader, m_playerCarIndex),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<PacketHeader*>(0)->m_secondaryPlayerCarIndex),
    offsetof(PacketHeader, m_secondaryPlayerCarIndex),
    sizeof(uint8),
    F1_types::kUint8
  },
};

