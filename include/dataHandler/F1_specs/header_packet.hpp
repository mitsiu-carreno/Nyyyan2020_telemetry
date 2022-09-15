#ifndef F1_PACKET_HEADER_H
#define F1_PACKET_HEADER_H

#include <vector>
#include <cstring>
#include <iostream>
#include "F1_types_alias.hpp"

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
  private:
    static std::vector<std::pair<short, short>> header_descriptor;
    static void Debug(){
      for (const auto& attr:header_descriptor){
        std::cout << attr.first << " " << attr.second << "\n";
      }
    }

    static short GetTotalProps(){
      return HeaderMarshall::header_descriptor.size();
    }

    static short GetPropSize(short pos){
      return HeaderMarshall::header_descriptor.at(pos).first;
    }

    static void* GetStructOffset(char *struct_addr, short pos){
      return struct_addr + HeaderMarshall::header_descriptor.at(pos).second;
    }

  public:
    HeaderMarshall(void *struct_addr, char *buffer, int buffer_offset=0){
      for(short prop_pos {0}; prop_pos < this->GetTotalProps(); ++prop_pos){
        short required_bytes = this->GetPropSize(prop_pos);
        memcpy(
          this->GetStructOffset(reinterpret_cast<char*>(struct_addr), prop_pos),
          &buffer[buffer_offset],
          required_bytes
        );
        buffer_offset += required_bytes;
      }
    }
};


#endif
