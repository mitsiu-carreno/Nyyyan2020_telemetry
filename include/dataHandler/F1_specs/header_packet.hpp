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
  public:
    //static std::vector<std::pair<short, short>> header_descriptor;
    static unsigned int header_descriptor [10][4];

    /*
    static void Debug(){
      for(size_t row{0}; row < sizeof(HeaderMarshall::header_descriptor)/(sizeof(HeaderMarshall::header_descriptor[0])); ++row){
        for(size_t col{0}; col < sizeof(HeaderMarshall::header_descriptor[0])/ sizeof(HeaderMarshall::header_descriptor[0][0]); ++col){
            std::cout << HeaderMarshall::header_descriptor[row][col] << "\t";
        }
        std::cout << "\n";

      }
    }

    static void ValidatePosition(unsigned int pos){
      if(pos < sizeof(HeaderMarshall::header_descriptor)/sizeof(HeaderMarshall::header_descriptor[0]) ){
        return;
      }
      throw -1;
    }

    static unsigned int GetTotalProps(){
      return sizeof(HeaderMarshall::header_descriptor)/sizeof(HeaderMarshall::header_descriptor[0]);
    }

    static unsigned int GetPropSize(unsigned int pos){
      ValidatePosition(pos);
      return HeaderMarshall::header_descriptor[pos][0];
    }

    static void* GetStructOffset(char *struct_addr, unsigned int pos){
      ValidatePosition(pos);
      return struct_addr + HeaderMarshall::header_descriptor[pos][1];
    }

    static unsigned int GetNumberOfElements(unsigned int pos){
      ValidatePosition(pos);
      return HeaderMarshall::header_descriptor[pos][0] / HeaderMarshall::header_descriptor[pos][2];
    }

    static unsigned int GetPropType(unsigned int pos){
      ValidatePosition(pos);
      return HeaderMarshall::header_descriptor[pos][3];
    }
    */
    /*
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
    */
/*
  public:
    HeaderMarshall(void *struct_addr, char *buffer, int buffer_offset=0){
      for(size_t prop_pos {0}; prop_pos < this->GetTotalProps(); ++prop_pos){
        for(size_t arr_pos {1}; arr_pos <= this->GetNumberOfElements(prop_pos); ++arr_pos){
          unsigned int required_bytes = this->GetPropSize(prop_pos);
          memcpy(
            this->GetStructOffset(reinterpret_cast<char*>(struct_addr), prop_pos),
            &buffer[buffer_offset],
            required_bytes
          );
          buffer_offset += required_bytes;
        }
      }
    }
    */
};


#endif
