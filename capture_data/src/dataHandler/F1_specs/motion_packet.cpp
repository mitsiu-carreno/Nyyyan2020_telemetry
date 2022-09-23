
#include <cstddef>  // offsetof

#include "motion_packet.hpp"
#include "F1_types_alias.hpp"

  // [0] = sizeof member attribute, [1] = struct offset to member attribute, [2] = sizeof one member attribute (identify arrays)
unsigned int MotionMarshall::motion_descriptor [][4] = {
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_header),
    offsetof(PacketMotionData, m_header),
    sizeof(PacketHeader),
    F1_types::kPacketHeader
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_carMotionData),
    offsetof(PacketMotionData, m_carMotionData),
    sizeof(CarMotionData),
    F1_types::kCarMotionData
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_suspensionPosition),
    offsetof(PacketMotionData, m_suspensionPosition),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_suspensionVelocity),
    offsetof(PacketMotionData, m_suspensionVelocity),
    sizeof(float),
    F1_types::kFloat

  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_suspensionAcceleration),
    offsetof(PacketMotionData, m_suspensionAcceleration),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_wheelSpeed),
    offsetof(PacketMotionData, m_wheelSpeed),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_wheelSlip),
    offsetof(PacketMotionData, m_wheelSlip),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_localVelocityX),
    offsetof(PacketMotionData, m_localVelocityX),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_localVelocityY),
    offsetof(PacketMotionData, m_localVelocityY),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_localVelocityZ),
    offsetof(PacketMotionData, m_localVelocityZ),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_angularVelocityX),
    offsetof(PacketMotionData, m_angularVelocityX),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_angularVelocityY),
    offsetof(PacketMotionData, m_angularVelocityY),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_angularVelocityZ),
    offsetof(PacketMotionData, m_angularVelocityZ),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_angularAccelerationX),
    offsetof(PacketMotionData, m_angularAccelerationX),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_angularAccelerationY),
    offsetof(PacketMotionData, m_angularAccelerationY),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_angularAccelerationZ),
    offsetof(PacketMotionData, m_angularAccelerationZ),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<PacketMotionData*>(0)->m_frontWheelsAngle),
    offsetof(PacketMotionData, m_frontWheelsAngle),
    sizeof(float),
    F1_types::kFloat
  },
};

unsigned int MotionMarshall::car_motion_descriptor [][4] = {
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldPositionX),
    offsetof(CarMotionData, m_worldPositionX),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldPositionY),
    offsetof(CarMotionData, m_worldPositionY),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldPositionZ),
    offsetof(CarMotionData, m_worldPositionZ),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldVelocityX),
    offsetof(CarMotionData, m_worldVelocityX),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldVelocityY),
    offsetof(CarMotionData, m_worldVelocityY),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldVelocityZ),
    offsetof(CarMotionData, m_worldVelocityZ),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldForwardDirX),
    offsetof(CarMotionData, m_worldForwardDirX),
    sizeof(int16),
    F1_types::kInt16
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldForwardDirY),
    offsetof(CarMotionData, m_worldForwardDirY),
    sizeof(int16),
    F1_types::kInt16
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldForwardDirZ),
    offsetof(CarMotionData, m_worldForwardDirZ),
    sizeof(int16),
    F1_types::kInt16
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldRightDirX),
    offsetof(CarMotionData, m_worldRightDirX),
    sizeof(int16),
    F1_types::kInt16
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldRightDirY),
    offsetof(CarMotionData, m_worldRightDirY),
    sizeof(int16),
    F1_types::kInt16
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_worldRightDirZ),
    offsetof(CarMotionData, m_worldRightDirZ),
    sizeof(int16),
    F1_types::kInt16
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_gForceLateral),
    offsetof(CarMotionData, m_gForceLateral),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_gForceLongitudinal),
    offsetof(CarMotionData, m_gForceLongitudinal),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_gForceVertical),
    offsetof(CarMotionData, m_gForceVertical),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_yaw),
    offsetof(CarMotionData, m_yaw),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_pitch),
    offsetof(CarMotionData, m_pitch),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarMotionData*>(0)->m_roll),
    offsetof(CarMotionData, m_roll),
    sizeof(float),
    F1_types::kFloat
  },
};
