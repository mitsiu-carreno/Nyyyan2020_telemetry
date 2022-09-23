#ifndef PACKET_MARSHALLING_H
#define PACKET_MARSHALLING_H

#include <cstring>
#include "type_alias_F1.hpp"
#include "motion_packet.hpp"
#include "header_packet.hpp"
#include "car_telemetry_packet.hpp"

class PacketMarshall{
  private:
    static void Debug(unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size){
      std::cout << "sizeof \tstruct \tsizeof \tF1_type\n";
      std::cout << "attr\toffset\tone attr\n";
      for(size_t row{0}; row < packet_descriptor_size/sizeof(packet_descriptor[0]); ++row){
        for(size_t col{0}; col < sizeof(packet_descriptor[0])/ sizeof(packet_descriptor[0][0]); ++col){
            std::cout << packet_descriptor[row][col] << "\t";
        }
        std::cout << "\n";

      }
    }

    static void ValidatePosition(unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size, unsigned int pos){
      if(pos < packet_descriptor_size/sizeof(packet_descriptor[0]) ){
        return;
      }
      throw -1; // TODO catch
    }

    static unsigned int GetTotalProps(unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size){
      return packet_descriptor_size/sizeof(packet_descriptor[0]);
    }

    static unsigned int GetPropSize(unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size, unsigned int pos){
      ValidatePosition(packet_descriptor, packet_descriptor_size, pos);
      return packet_descriptor[pos][0];
    }

    static void* GetStructOffset(unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size, char *struct_addr, unsigned int pos, unsigned int arr_pos){
      ValidatePosition(packet_descriptor, packet_descriptor_size, pos);
      return struct_addr + (packet_descriptor[pos][1] * arr_pos);
    }

    static unsigned int GetStructByteOffset(unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size, unsigned int pos, unsigned int arr_pos){
      ValidatePosition(packet_descriptor, packet_descriptor_size, pos);
      return packet_descriptor[pos][1] * arr_pos;
    }

    static unsigned int GetNumberOfElements(unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size,  unsigned int pos){
      ValidatePosition(packet_descriptor, packet_descriptor_size, pos);
      return packet_descriptor[pos][0] / packet_descriptor[pos][2];
    }

    static unsigned int GetPropType(unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size, unsigned int pos){
      ValidatePosition(packet_descriptor, packet_descriptor_size, pos);
      return packet_descriptor[pos][3];
    }

  public:
    PacketMarshall(void *struct_addr, char *buffer, unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size, unsigned int &buffer_offset){
      //this->Debug(packet_descriptor, packet_descriptor_size);

      for(size_t prop_pos {0}; prop_pos < this->GetTotalProps(packet_descriptor, packet_descriptor_size); ++prop_pos){
        for(size_t arr_pos {1}; arr_pos <= this->GetNumberOfElements(packet_descriptor, packet_descriptor_size, prop_pos); ++arr_pos){
          
          
          if(this->GetPropType(packet_descriptor, packet_descriptor_size, prop_pos) == F1_types::kPacketHeader){
   //std::cout << "------Marshall header packet\n"; 
            PacketMarshall(
                this->GetStructOffset(
                  packet_descriptor, 
                  packet_descriptor_size, 
                  reinterpret_cast<char*>(struct_addr), 
                  prop_pos,
                  arr_pos
                ), 
                buffer, 
                HeaderMarshall::header_descriptor, 
                sizeof(HeaderMarshall::header_descriptor),
                buffer_offset
            );
          }else if(this->GetPropType(packet_descriptor, packet_descriptor_size, prop_pos) == F1_types::kCarMotionData){
   //std::cout << "------Marshall car motion packet\n"; 
            PacketMarshall(
                this->GetStructOffset(
                  packet_descriptor, 
                  packet_descriptor_size, 
                  reinterpret_cast<char*>(struct_addr), 
                  prop_pos,
                  arr_pos
                ), 
                buffer, 
                MotionMarshall::car_motion_descriptor, 
                sizeof(MotionMarshall::car_motion_descriptor),
                buffer_offset
            );
          }else if(this->GetPropType(packet_descriptor, packet_descriptor_size, prop_pos) == F1_types::kCarTelemetryData){
            PacketMarshall(
                this->GetStructOffset(
                  packet_descriptor,
                  packet_descriptor_size,
                  reinterpret_cast<char*>(struct_addr),
                  prop_pos,
                  arr_pos
                ),
                buffer,
                CarTelemetryMarshall::car_telemetry_descriptor,
                sizeof(CarTelemetryMarshall::car_telemetry_descriptor),
                buffer_offset
            );
          }else{
            unsigned int required_bytes = this->GetPropSize(packet_descriptor, packet_descriptor_size, prop_pos);

            //std::cout <<  "From buffer position " << buffer_offset << " into struct position " << this->GetStructByteOffset(packet_descriptor, packet_descriptor_size, prop_pos, arr_pos) << " (struct addr) " << this->GetStructOffset(packet_descriptor, packet_descriptor_size, reinterpret_cast<char*>(struct_addr), prop_pos, arr_pos) << " coping "<< required_bytes <<"\n";

            /*
            for(size_t i{0}; i<required_bytes; ++i){
              printf("%x\t", buffer[buffer_offset+i]);
            }
            printf("\n");
            */

            memcpy(
              this->GetStructOffset(packet_descriptor, packet_descriptor_size, reinterpret_cast<char*>(struct_addr), prop_pos, arr_pos),
              &buffer[buffer_offset],
              required_bytes
            );
            buffer_offset += required_bytes;
          }
        }
      }
    }
};

#endif
