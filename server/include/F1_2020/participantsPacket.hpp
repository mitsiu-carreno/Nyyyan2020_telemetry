#ifndef PARTICIPANTS_PACKET_H
#define PARTICIPANTS_PACKET_H

#include "typeAlias.hpp"
#include "packetHeader.hpp"

/*
 * This is a list of participants in the race. If the vehicle is controlled by AI, then the name will be the driver name. If this is a multiplayer game, the names will be the Steam Id on PC, or the LAN name if appropriate.
 *
 * N.B. on Xbox One, the names will always be the driver name, on PS4 the name will be the LAN name if playing a LAN game, otherwise it will be the driver name. 

 * The array should be indexed by vehicle index.

 * Frequency: Every 5 seconds
 * Size: 1213 bytes (Packet size updated in Beta 3)
 * Version: 1 
 */

struct ParticipantData
{
    uint8      m_aiControlled;           // Whether the vehicle is AI (1) or Human (0) controlled
    uint8      m_driverId;               // Driver id - see appendix
    uint8      m_teamId;                 // Team id - see appendix
    uint8      m_raceNumber;             // Race number of the car
    uint8      m_nationality;            // Nationality of the driver
    char       m_name[48];               // Name of participant in UTF-8 format – null terminated
                                         // Will be truncated with … (U+2026) if too long
    uint8      m_yourTelemetry;          // The player's UDP setting, 0 = restricted, 1 = public
};

struct PacketParticipantsData
{
    PacketHeader    m_header;           // Header

    uint8           m_numActiveCars;	// Number of active cars in the data – should match number of
                                        // cars on HUD
    ParticipantData m_participants[22];
};


#endif

