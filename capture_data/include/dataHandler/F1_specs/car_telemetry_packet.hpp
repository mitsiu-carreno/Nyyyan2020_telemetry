#ifndef F1_CAR_TELEM_H
#define F1_CAR_TELEM_H

#include <unordered_map>
#include <string>
#include "type_alias_F1.hpp"
#include "header_packet.hpp"

struct CarTelemetryData
{
    uint16    m_speed;                         // Speed of car in kilometres per hour
    float     m_throttle;                      // Amount of throttle applied (0.0 to 1.0)
    float     m_steer;                         // Steering (-1.0 (full lock left) to 1.0 (full lock right))
    float     m_brake;                         // Amount of brake applied (0.0 to 1.0)
    uint8     m_clutch;                        // Amount of clutch applied (0 to 100)
    int8      m_gear;                          // Gear selected (1-8, N=0, R=-1)
    uint16    m_engineRPM;                     // Engine RPM
    uint8     m_drs;                           // 0 = off, 1 = on
    uint8     m_revLightsPercent;              // Rev lights indicator (percentage)
    uint16    m_brakesTemperature[4];          // Brakes temperature (celsius)
    uint8     m_tyresSurfaceTemperature[4];    // Tyres surface temperature (celsius)
    uint8     m_tyresInnerTemperature[4];      // Tyres inner temperature (celsius)
    uint16    m_engineTemperature;             // Engine temperature (celsius)
    float     m_tyresPressure[4];              // Tyres pressure (PSI)
    uint8     m_surfaceType[4];                // Driving surface, see appendices
};

struct PacketCarTelemetryData
{
    PacketHeader    	m_header;	       // Header

    CarTelemetryData    m_carTelemetryData[22];

    uint32              m_buttonStatus;        // Bit flags specifying which buttons are being pressed
                                               // currently - see appendices

    // Added in Beta 3:
    uint8               m_mfdPanelIndex;       // Index of MFD panel open - 255 = MFD closed
                                               // Single player, race – 0 = Car setup, 1 = Pits
                                               // 2 = Damage, 3 =  Engine, 4 = Temperatures
                                               // May vary depending on game mode
    uint8               m_mfdPanelIndexSecondaryPlayer;   // See above
    int8                m_suggestedGear;       // Suggested gear for the player (1-8)
                                               // 0 if no gear suggested
};

const std::unordered_map<std::string, unsigned int> car_telemetry_packet_array_descriptor = {
  {"m_carTelemetryData", 22}
};

const std::unordered_map<std::string, unsigned int> car_telemetry_array_descriptor = {
  {"m_brakesTemperature", 4},
  {"m_tyresSurfaceTemperature", 4},
  {"m_tyresInnerTemperature", 4},
  {"m_tyresPressure", 4},
  {"m_surfaceType", 4}
};

void MarshallCarTelemetryPacket(char *, PacketCarTelemetryData*);

#endif
