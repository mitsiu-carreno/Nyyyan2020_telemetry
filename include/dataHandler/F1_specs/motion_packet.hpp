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
  private:
    static std::vector<std::pair<short, short>> motion_descriptor;
    
    static void Debug(){
      for (const auto& p:MotionMarshall::motion_descriptor){
        std::cout << p.first << " " << p.second << "\n";
      }
    }

    static short GetTotalProps(){
      return MotionMarshall::motion_descriptor.size();
    }

    static short GetPropSize(short pos){
      return MotionMarshall::motion_descriptor.at(pos).first;
    }

    static void* GetStructOffset(char *struct_addr, short pos){
      return struct_addr + MotionMarshall::motion_descriptor.at(pos).second;
    }
  
  public:
   MotionMarshall(void *struct_addr, char *buffer, int buffer_offset=0){
    for(short prop_pos {0}; prop_pos < this->GetTotalProps(); ++prop_pos){
      short required_bytes = this->GetPropSize(prop_pos);
      // TODO handle header better
      if(prop_pos == 0){
        HeaderMarshall(this->GetStructOffset(reinterpret_cast<char*>(struct_addr), prop_pos), buffer);
      }else{
      
        memcpy(
          this->GetStructOffset(reinterpret_cast<char*>(struct_addr), prop_pos),
          &buffer[buffer_offset],
          required_bytes
        );
      }
      buffer_offset += required_bytes;
    }
   }
};

#endif
