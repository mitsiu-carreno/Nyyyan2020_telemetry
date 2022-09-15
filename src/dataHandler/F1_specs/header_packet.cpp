#include <cstddef>  // offsetof

#include "header_packet.hpp"
#include "F1_types_alias.hpp"

std::vector<std::pair<short int, short int> > HeaderMarshall::header_descriptor =
    {   // short = sizeof member attribute, short = struct offset to member attribute 
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_packetFormat),
        offsetof(PacketHeader, m_packetFormat)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_gameMajorVersion),
        offsetof(PacketHeader, m_gameMajorVersion)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_gameMinorVersion),
        offsetof(PacketHeader, m_gameMinorVersion)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_packetVersion),
        offsetof(PacketHeader, m_packetVersion)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_packetId),
        offsetof(PacketHeader, m_packetId)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_sessionUID),
        offsetof(PacketHeader, m_sessionUID)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_sessionTime),
        offsetof(PacketHeader, m_sessionTime)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_frameIdentifier),
        offsetof(PacketHeader, m_frameIdentifier)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_playerCarIndex),
        offsetof(PacketHeader, m_playerCarIndex)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketHeader*>(0)->m_secondaryPlayerCarIndex),
        offsetof(PacketHeader, m_secondaryPlayerCarIndex)
      }
    };
