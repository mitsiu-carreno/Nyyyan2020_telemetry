#include "type_alias.hpp"

struct PacketHeader
{
    uint16    m_packetFormat;             // 2020
    uint8     m_gameMajorVersion;         // Game major version - "X.00"
    uint8     m_gameMinorVersion;         // Game minor version - "1.XX"
    uint8     m_packetVersion;            // Version of this packet type, all start from 1
    uint8     m_packetId;                 // Identifier for the packet type, see below
    uint64    m_sessionUID;               // Unique identifier for the session
    float     m_sessionTime;              // Session timestamp
    uint32    m_frameIdentifier;          // Identifier for the frame the data was retrieved on
    uint8     m_playerCarIndex;           // Index of player's car in the array
    
   // ADDED IN BETA 2: 
    uint8     m_secondaryPlayerCarIndex;  // Index of secondary player's car in the array (splitscreen)
                                          // 255 if no second player
};

enum PacketIdDetail{
  motion =0,                              // Contains all motion data for player’s car – only sent while player is in control
  session,                                // Data about the session – track, time left
  lap_data,                               // Data about all the lap times of cars in the session
  event,                                  // Various notable events that happen during a session
  participants,                           // List of participants in the session, mostly relevant for multiplayer
  car_setups,                             // Packet detailing car setups for cars in the race
  car_telemetry,                          // Telemetry data for all cars
  car_status,                             // Status data for all cars such as damage
  final_clasification,                    // Final classification confirmation at the end of a race
  lobby_info                              // Information about players in a multiplayer lobby
};
