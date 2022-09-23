#include <cstddef>

#include "car_telemetry_packet.hpp"
#include "type_alias_F1.hpp"

// [0] = sizeof member attribute, [1] = struct offset to memeber attribute, [2] = sizeof one member attribute (identify arrays)
unsigned int CarTelemetryMarshall::car_telemetry_packet_descriptor [][4] = {
  {
    sizeof(reinterpret_cast<PacketCarTelemetryData*>(0)->m_header),
    offsetof(PacketCarTelemetryData, m_header),
    sizeof(PacketHeader),
    F1_types::kPacketHeader
  },
  {
    sizeof(reinterpret_cast<PacketCarTelemetryData*>(0)->m_carTelemetryData),
    offsetof(PacketCarTelemetryData, m_carTelemetryData),
    sizeof(CarTelemetryData),
    F1_types::kCarTelemetryData
  },
  {
    sizeof(reinterpret_cast<PacketCarTelemetryData*>(0)->m_buttonStatus),
    offsetof(PacketCarTelemetryData, m_buttonStatus),
    sizeof(uint32),
    F1_types::kUint32
  },
  {
    sizeof(reinterpret_cast<PacketCarTelemetryData*>(0)->m_mfdPanelIndex),
    offsetof(PacketCarTelemetryData, m_mfdPanelIndex),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<PacketCarTelemetryData*>(0)->m_mfdPanelIndexSecondaryPlayer),
    offsetof(PacketCarTelemetryData, m_mfdPanelIndexSecondaryPlayer),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<PacketCarTelemetryData*>(0)->m_suggestedGear),
    offsetof(PacketCarTelemetryData, m_suggestedGear),
    sizeof(int8),
    F1_types::kInt8
  }
};

unsigned int CarTelemetryMarshall::car_telemetry_descriptor [][4] = {
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_speed),
    offsetof(CarTelemetryData, m_speed),
    sizeof(uint16),
    F1_types::kUint16
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_throttle),
    offsetof(CarTelemetryData, m_throttle),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_steer),
    offsetof(CarTelemetryData, m_steer),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_brake),
    offsetof(CarTelemetryData, m_brake),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_clutch),
    offsetof(CarTelemetryData, m_clutch),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_gear),
    offsetof(CarTelemetryData, m_gear),
    sizeof(int8),
    F1_types::kInt8
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_engineRPM),
    offsetof(CarTelemetryData, m_engineRPM),
    sizeof(uint16),
    F1_types::kUint16
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_drs),
    offsetof(CarTelemetryData, m_drs),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_revLightsPercent),
    offsetof(CarTelemetryData, m_revLightsPercent),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_brakesTemperature),
    offsetof(CarTelemetryData, m_brakesTemperature),
    sizeof(uint16),
    F1_types::kUint16
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_tyresSurfaceTemperature),
    offsetof(CarTelemetryData, m_tyresSurfaceTemperature),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_tyresInnerTemperature),
    offsetof(CarTelemetryData, m_tyresInnerTemperature),
    sizeof(uint8),
    F1_types::kUint8
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_engineTemperature),
    offsetof(CarTelemetryData, m_engineTemperature),
    sizeof(uint16),
    F1_types::kUint16
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_tyresPressure),
    offsetof(CarTelemetryData, m_tyresPressure),
    sizeof(float),
    F1_types::kFloat
  },
  {
    sizeof(reinterpret_cast<CarTelemetryData*>(0)->m_surfaceType),
    offsetof(CarTelemetryData, m_surfaceType),
    sizeof(uint8),
    F1_types::kUint8
  }
};
