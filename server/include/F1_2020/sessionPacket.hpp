#ifndef SESSION_PACKET_H
#define SESSION_PACKET_H

#include "typeAlias.hpp"
#include "packetHeader.hpp"

/*
 * The session packet includes details about the current session in progress.
 *
 * Frequency: 2 per second
 * Size: 251 bytes (Packet size updated in Beta 3)
 * Version: 1
 */

struct MarshalZone
{
    float  m_zoneStart;   // Fraction (0..1) of way through the lap the marshal zone starts
    int8   m_zoneFlag;    // -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
};

struct WeatherForecastSample
{
    uint8     m_sessionType;                     // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P, 5 = Q1
                                                 // 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ, 10 = R, 11 = R2
                                                 // 12 = Time Trial
    uint8     m_timeOffset;                      // Time in minutes the forecast is for
    uint8     m_weather;                         // Weather - 0 = clear, 1 = light cloud, 2 = overcast
                                                 // 3 = light rain, 4 = heavy rain, 5 = storm
    int8      m_trackTemperature;                // Track temp. in degrees celsius
    int8      m_airTemperature;                  // Air temp. in degrees celsius
};

struct PacketSessionData
{
    PacketHeader    m_header;                    // Header

    uint8           m_weather;                   // Weather - 0 = clear, 1 = light cloud, 2 = overcast
                                                 // 3 = light rain, 4 = heavy rain, 5 = storm
    int8	    m_trackTemperature;          // Track temp. in degrees celsius
    int8	    m_airTemperature;            // Air temp. in degrees celsius
    uint8           m_totalLaps;                 // Total number of laps in this race
    uint16          m_trackLength;               // Track length in metres
    uint8           m_sessionType;               // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
                                                 // 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
                                                 // 10 = R, 11 = R2, 12 = Time Trial
    int8            m_trackId;                   // -1 for unknown, 0-21 for tracks, see appendix
    uint8           m_formula;                   // Formula, 0 = F1 Modern, 1 = F1 Classic, 2 = F2,
                                                 // 3 = F1 Generic
    uint16          m_sessionTimeLeft;           // Time left in session in seconds
    uint16          m_sessionDuration;           // Session duration in seconds
    uint8           m_pitSpeedLimit;             // Pit speed limit in kilometres per hour
    uint8           m_gamePaused;                // Whether the game is paused
    uint8           m_isSpectating;              // Whether the player is spectating
    uint8           m_spectatorCarIndex;         // Index of the car being spectated
    uint8           m_sliProNativeSupport;	 // SLI Pro support, 0 = inactive, 1 = active
    uint8           m_numMarshalZones;           // Number of marshal zones to follow
    MarshalZone     m_marshalZones[21];          // List of marshal zones – max 21
    uint8           m_safetyCarStatus;           // 0 = no safety car, 1 = full safety car
                                                 // 2 = virtual safety car
    uint8           m_networkGame;               // 0 = offline, 1 = online
    uint8           m_numWeatherForecastSamples; // Number of weather samples to follow
    WeatherForecastSample m_weatherForecastSamples[20];   // Array of weather forecast samples
};

#endif
