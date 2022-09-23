#ifndef F1_PACKET_HEADER_H
#define F1_PACKET_HEADER_H

#include "type_alias_F1.hpp"

struct PacketHeader
{
    uint16    m_packetFormat;             // 2020
    uint8     m_gameMajorVersion;         // Game major version - "X.00"
    uint8     m_gameMinorVersion;         // Game minor version - "1.XX"
    uint8     m_packetVersion;            // Version of this packet type, all start from 1
    uint8     m_packetId;                 // Identifier for the packet type, see below
    uint64    m_sessionUID;               // Unique identifier for the session
    float     m_sessionTime;              // Session timestamp
    uint32    m_frameIdentifier;          // Identifier for the frame the data was retrieved on
    uint8     m_playerCarIndex;           // Index of player's car in the array

   // ADDED IN BETA 2:
    uint8     m_secondaryPlayerCarIndex;  // Index of secondary player's car in the array (splitscreen)
                                          // 255 if no second player
};

class HeaderMarshall{
  public:
    //static std::vector<std::pair<short, short>> header_descriptor;
    static unsigned int header_descriptor [10][4];
};


#endif
