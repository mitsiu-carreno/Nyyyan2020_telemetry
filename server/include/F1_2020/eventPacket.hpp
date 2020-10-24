#ifndef EVENT_PACKET_H
#define EVENT_PACKET_H

#include "typeAlias.hpp"
#include "packetHeader.hpp"

/*
 *  This packet gives details of events that happen during the course of a session.
 *
 * Frequency: When the event occurs
 * Size: 35 bytes (Packet size updated in Beta 3)
 * Version: 1
 */


// The event details packet is different for each type of event.
// Make sure only the correct type is interpreted.
union EventDataDetails
{
    struct
    {
        uint8	vehicleIdx; // Vehicle index of car achieving fastest lap
        float	lapTime;    // Lap time is in seconds
    } FastestLap;

    struct
    {
        uint8   vehicleIdx; // Vehicle index of car retiring
    } Retirement;

    struct
    {
        uint8   vehicleIdx; // Vehicle index of team mate
    } TeamMateInPits;

    struct
    {
        uint8   vehicleIdx; // Vehicle index of the race winner
    } RaceWinner;

    struct
    {
    	uint8 penaltyType;          // Penalty type – see Appendices
        uint8 infringementType;     // Infringement type – see Appendices
        uint8 vehicleIdx;           // Vehicle index of the car the penalty is applied to
        uint8 otherVehicleIdx;      // Vehicle index of the other car involved
        uint8 time;                 // Time gained, or time spent doing action in seconds
        uint8 lapNum;               // Lap the penalty occurred on
        uint8 placesGained;         // Number of places gained by this
    } Penalty;

    struct
    {
        uint8 vehicleIdx; // Vehicle index of the vehicle triggering speed trap
        float speed;      // Top speed achieved in kilometres per hour
    } SpeedTrap;
};

struct PacketEventData
{
    PacketHeader    	m_header;             // Header
    
uint8           	m_eventStringCode[4]; // Event string code, see below
EventDataDetails	m_eventDetails;       // Event details - should be interpreted differently
                                              // for each type
};

struct EventKeyValue{
  char code[5];
  char event[26];
};


const struct EventKeyValue event_code_value[] {
  {"SSTA", "Session Started"},      // Sent when the session starts
  {"SEND", "Session Ended"},        // Sent when the session ends
  {"FTLP", "Fastest Lap"},          // When a driver achieves the fastest lap
  {"RTMT", "Retirement"},           // When a driver retires
  {"DRSE", "DRS enabled"},          // Race control have enabled DRS
  {"DRSD", "DRS disabled"},         // Race control have disabled DRS
  {"TMPT", "Team mate in pits"},    // Your team mate has entered the pits
  {"CHQF", "Chequered flag"},       // The chequered flag has been waved
  {"RCWN", "Race Winner"},          // The race winner is announced
  {"PENA", "Penalty Issued"},       // A penalty has been issued – details in event
  {"SPTP", "Speed Trap Triggered"}  // Speed trap has been triggered by fastest speed
};


#endif

