
#include <cstddef>  // offsetof

#include "motion_packet.hpp"
#include "F1_types_alias.hpp"

std::vector<std::pair<short int, short int> > MotionMarshall::motion_descriptor = 
    {
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_header),
        offsetof(PacketMotionData, m_header)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_carMotionData),
        offsetof(PacketMotionData, m_carMotionData)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_suspensionPosition),
        offsetof(PacketMotionData, m_suspensionPosition)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_suspensionVelocity),
        offsetof(PacketMotionData, m_suspensionVelocity)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_suspensionAcceleration),
        offsetof(PacketMotionData, m_suspensionAcceleration)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_wheelSpeed),
        offsetof(PacketMotionData, m_wheelSpeed)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_wheelSlip),
        offsetof(PacketMotionData, m_wheelSlip)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_localVelocityX),
        offsetof(PacketMotionData, m_localVelocityX)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_localVelocityY),
        offsetof(PacketMotionData, m_localVelocityY)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_localVelocityZ),
        offsetof(PacketMotionData, m_localVelocityZ)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_angularVelocityX),
        offsetof(PacketMotionData, m_angularVelocityX)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_angularVelocityY),
        offsetof(PacketMotionData, m_angularVelocityY)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_angularVelocityZ),
        offsetof(PacketMotionData, m_angularVelocityZ)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_angularAccelerationX),
        offsetof(PacketMotionData, m_angularAccelerationX)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_angularAccelerationY),
        offsetof(PacketMotionData, m_angularAccelerationY)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_angularAccelerationZ),
        offsetof(PacketMotionData, m_angularAccelerationZ)
      },
      std::pair{
        sizeof(reinterpret_cast<struct PacketMotionData*>(0)->m_frontWheelsAngle),
        offsetof(PacketMotionData, m_frontWheelsAngle)
      }
    };
