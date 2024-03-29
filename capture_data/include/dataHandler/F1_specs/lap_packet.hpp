#ifndef F1_LAP_H
#define F1_LAP_H

#include <unordered_map>
#include <string>
#include "type_alias_F1.hpp"
#include "header_packet.hpp"

struct LapData
{
    float    m_lastLapTime;               // Last lap time in seconds
    float    m_currentLapTime;            // Current time around the lap in seconds

    //UPDATED in Beta 3:
    uint16   m_sector1TimeInMS;           // Sector 1 time in milliseconds
    uint16   m_sector2TimeInMS;           // Sector 2 time in milliseconds
    float    m_bestLapTime;               // Best lap time of the session in seconds
    uint8    m_bestLapNum;                // Lap number best time achieved on
    uint16   m_bestLapSector1TimeInMS;    // Sector 1 time of best lap in the session in milliseconds
    uint16   m_bestLapSector2TimeInMS;    // Sector 2 time of best lap in the session in milliseconds
    uint16   m_bestLapSector3TimeInMS;    // Sector 3 time of best lap in the session in milliseconds
    uint16   m_bestOverallSector1TimeInMS;// Best overall sector 1 time of the session in milliseconds
    uint8    m_bestOverallSector1LapNum;  // Lap number best overall sector 1 time achieved on
    uint16   m_bestOverallSector2TimeInMS;// Best overall sector 2 time of the session in milliseconds
    uint8    m_bestOverallSector2LapNum;  // Lap number best overall sector 2 time achieved on
    uint16   m_bestOverallSector3TimeInMS;// Best overall sector 3 time of the session in milliseconds
    uint8    m_bestOverallSector3LapNum;  // Lap number best overall sector 3 time achieved on


    float    m_lapDistance;               // Distance vehicle is around current lap in metres – could
                                          // be negative if line hasn’t been crossed yet
    float    m_totalDistance;             // Total distance travelled in session in metres – could
                                          // be negative if line hasn’t been crossed yet
    float    m_safetyCarDelta;            // Delta in seconds for safety car
    uint8    m_carPosition;               // Car race position
    uint8    m_currentLapNum;             // Current lap number
    uint8    m_pitStatus;                 // 0 = none, 1 = pitting, 2 = in pit area
    uint8    m_sector;                    // 0 = sector1, 1 = sector2, 2 = sector3
    uint8    m_currentLapInvalid;         // Current lap invalid - 0 = valid, 1 = invalid
    uint8    m_penalties;                 // Accumulated time penalties in seconds to be added
    uint8    m_gridPosition;              // Grid position the vehicle started the race in
    uint8    m_driverStatus;              // Status of driver - 0 = in garage, 1 = flying lap
                                          // 2 = in lap, 3 = out lap, 4 = on track
    uint8    m_resultStatus;              // Result status - 0 = invalid, 1 = inactive, 2 = active
                                          // 3 = finished, 4 = disqualified, 5 = not classified
                                          // 6 = retired
};


struct PacketLapData
{
    PacketHeader    m_header;             // Header

    LapData         m_lapData[22];        // Lap data for all cars on track
};

const std::unordered_map<std::string, unsigned int> lap_packet_array_descriptor = {
  {"m_lapData", 22},
};

void MarshallLapPacket(char *, PacketLapData*);

#endif
