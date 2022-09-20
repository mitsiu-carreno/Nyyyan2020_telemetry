#ifndef F1_MOTION_PACKET_H
#define F1_MOTION_PACKET_H

#include <vector>
#include <cstring>
#include "F1_types_alias.hpp"
#include "header_packet.hpp"

struct CarMotionData
  {
    float         m_worldPositionX;           // World space X position
    float         m_worldPositionY;           // World space Y position
    float         m_worldPositionZ;           // World space Z position
    float         m_worldVelocityX;           // Velocity in world space X
    float         m_worldVelocityY;           // Velocity in world space Y
    float         m_worldVelocityZ;           // Velocity in world space Z
    int16         m_worldForwardDirX;         // World space forward X direction (normalised)
    int16         m_worldForwardDirY;         // World space forward Y direction (normalised)
    int16         m_worldForwardDirZ;         // World space forward Z direction (normalised)
    int16         m_worldRightDirX;           // World space right X direction (normalised)
    int16         m_worldRightDirY;           // World space right Y direction (normalised)
    int16         m_worldRightDirZ;           // World space right Z direction (normalised)
    float         m_gForceLateral;            // Lateral G-Force component
    float         m_gForceLongitudinal;       // Longitudinal G-Force component
    float         m_gForceVertical;           // Vertical G-Force component
    float         m_yaw;                      // Yaw angle in radians
    float         m_pitch;                    // Pitch angle in radians
    float         m_roll;                     // Roll angle in radians
};

struct PacketMotionData
{
    PacketHeader    m_header;               	// Header

    CarMotionData   m_carMotionData[22];    	// Data for all cars on track

    // Extra player car ONLY data
    float         m_suspensionPosition[4];      // Note: All wheel arrays have the following order:
    float         m_suspensionVelocity[4];      // RL, RR, FL, FR
    float         m_suspensionAcceleration[4];	// RL, RR, FL, FR
    float         m_wheelSpeed[4];           	// Speed of each wheel
    float         m_wheelSlip[4];               // Slip ratio for each wheel
    float         m_localVelocityX;         	// Velocity in local space
    float         m_localVelocityY;         	// Velocity in local space
    float         m_localVelocityZ;         	// Velocity in local space
    float         m_angularVelocityX;		    // Angular velocity x-component
    float         m_angularVelocityY;           // Angular velocity y-component
    float         m_angularVelocityZ;           // Angular velocity z-component
    float         m_angularAccelerationX;       // Angular velocity x-component
    float         m_angularAccelerationY;	    // Angular velocity y-component
    float         m_angularAccelerationZ;       // Angular velocity z-component
    float         m_frontWheelsAngle;           // Current front wheels angle in radians
};

class MotionMarshall{
  public:
    //static std::vector<std::pair<short, short>> motion_descriptor;
    static unsigned int motion_descriptor [17][4];
    static unsigned int car_motion_descriptor [18][4];


    static void Debug(unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size){
      std::cout << "sizeof attr\tstruct offset\tsizeof one attr\tF1_type\n";
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
      throw -1;
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
    MotionMarshall(void *struct_addr, char *buffer, unsigned int packet_descriptor[][4], unsigned int packet_descriptor_size, unsigned int &buffer_offset){
      std::cout << "Debug\n";
      this->Debug(packet_descriptor, packet_descriptor_size);
      std::cout << "Buffer offset" << buffer_offset << "\n";

      for(size_t prop_pos {0}; prop_pos < this->GetTotalProps(packet_descriptor, packet_descriptor_size); ++prop_pos){
        for(size_t arr_pos {1}; arr_pos <= this->GetNumberOfElements(packet_descriptor, packet_descriptor_size, prop_pos); ++arr_pos){
          
          
          if(this->GetPropType(packet_descriptor, packet_descriptor_size, prop_pos) == F1_types::kPacketHeader){
   std::cout << "------Marshall header packet\n"; 
            MotionMarshall(
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
   std::cout << "------Marshall car motion packet\n"; 
            MotionMarshall(
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
          }else{
            unsigned int required_bytes = this->GetPropSize(packet_descriptor, packet_descriptor_size, prop_pos);

            std::cout <<  "From buffer position " << buffer_offset << " into struct position " << this->GetStructByteOffset(packet_descriptor, packet_descriptor_size, prop_pos, arr_pos) << " (struct addr) " << this->GetStructOffset(packet_descriptor, packet_descriptor_size, reinterpret_cast<char*>(struct_addr), prop_pos, arr_pos) << " coping "<< required_bytes <<"\n";


            for(size_t i{0}; i<required_bytes; ++i){
              printf("%x\t", buffer[buffer_offset+i]);
            }
            printf("\n");

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
