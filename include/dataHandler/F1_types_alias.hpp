#ifndef F1_TYPES_ALIAS_H
#define F1_TYPES_ALIAS_H

#include <cstdint>

typedef std::uint8_t   uint8;
typedef std::int8_t    int8;
typedef std::uint16_t  uint16;
typedef std::int16_t   int16;
typedef std::uint32_t  uint32;
typedef std::int32_t   int32;
typedef std::uint64_t  uint64;

enum F1_types{
  kUint8,
  kInt8,
  kUint16,
  kInt16,
  kFloat,
  kUint32,
  kInt32,
  kUint64,
  kPacketHeader,
  kCarMotionData,
  kMarshalZone,
  kWeatherForecastSample,
  kLapData,
  kEventDataDetails,
  kParticipantData,
  kCarSetupData,
  kCarTelemetryData,
  kCarStatusData,
  kFinalClassificationData,
  kLobbyInfoData,
};

#endif

