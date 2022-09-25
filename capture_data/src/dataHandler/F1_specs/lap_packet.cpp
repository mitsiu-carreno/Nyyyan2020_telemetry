#include <cstring>
#include "lap_packet.hpp"

void MarshallLap(char *buffer, LapData *struct_addr, unsigned int buffer_offset){
  memcpy(&struct_addr->m_lastLapTime, &buffer[buffer_offset], sizeof(struct_addr->m_lastLapTime));
  buffer_offset += sizeof(struct_addr->m_lastLapTime);

  memcpy(&struct_addr->m_currentLapTime, &buffer[buffer_offset], sizeof(struct_addr->m_currentLapTime));
  buffer_offset += sizeof(struct_addr->m_currentLapTime);

  memcpy(&struct_addr->m_sector1TimeInMS, &buffer[buffer_offset], sizeof(struct_addr->m_sector1TimeInMS));
  buffer_offset += sizeof(struct_addr->m_sector1TimeInMS);

  memcpy(&struct_addr->m_sector2TimeInMS, &buffer[buffer_offset], sizeof(struct_addr->m_sector2TimeInMS));
  buffer_offset += sizeof(struct_addr->m_sector2TimeInMS);

  memcpy(&struct_addr->m_bestLapTime, &buffer[buffer_offset], sizeof(struct_addr->m_bestLapTime));
  buffer_offset += sizeof(struct_addr->m_bestLapTime);

  memcpy(&struct_addr->m_bestLapNum, &buffer[buffer_offset], sizeof(struct_addr->m_bestLapNum));
  buffer_offset += sizeof(struct_addr->m_bestLapNum);

  memcpy(&struct_addr->m_bestLapSector1TimeInMS, &buffer[buffer_offset], sizeof(struct_addr->m_bestLapSector1TimeInMS));
  buffer_offset += sizeof(struct_addr->m_bestLapSector1TimeInMS);

  memcpy(&struct_addr->m_bestLapSector2TimeInMS, &buffer[buffer_offset], sizeof(struct_addr->m_bestLapSector2TimeInMS));
  buffer_offset += sizeof(struct_addr->m_bestLapSector2TimeInMS);

  memcpy(&struct_addr->m_bestLapSector3TimeInMS, &buffer[buffer_offset], sizeof(struct_addr->m_bestLapSector3TimeInMS));
  buffer_offset += sizeof(struct_addr->m_bestLapSector3TimeInMS);

  memcpy(&struct_addr->m_bestOverallSector1TimeInMS, &buffer[buffer_offset], sizeof(struct_addr->m_bestOverallSector1TimeInMS));
  buffer_offset += sizeof(struct_addr->m_bestOverallSector1TimeInMS);

  memcpy(&struct_addr->m_bestOverallSector1LapNum, &buffer[buffer_offset], sizeof(struct_addr->m_bestOverallSector1LapNum));
  buffer_offset += sizeof(struct_addr->m_bestOverallSector1LapNum);

  memcpy(&struct_addr->m_bestOverallSector2TimeInMS, &buffer[buffer_offset], sizeof(struct_addr->m_bestOverallSector2TimeInMS));
  buffer_offset += sizeof(struct_addr->m_bestOverallSector2TimeInMS);

  memcpy(&struct_addr->m_bestOverallSector2LapNum, &buffer[buffer_offset], sizeof(struct_addr->m_bestOverallSector2LapNum));
  buffer_offset += sizeof(struct_addr->m_bestOverallSector2LapNum);

  memcpy(&struct_addr->m_bestOverallSector3TimeInMS, &buffer[buffer_offset], sizeof(struct_addr->m_bestOverallSector3TimeInMS));
  buffer_offset += sizeof(struct_addr->m_bestOverallSector3TimeInMS);

  memcpy(&struct_addr->m_bestOverallSector3LapNum, &buffer[buffer_offset], sizeof(struct_addr->m_bestOverallSector3LapNum));
  buffer_offset += sizeof(struct_addr->m_bestOverallSector3LapNum);

  memcpy(&struct_addr->m_lapDistance, &buffer[buffer_offset], sizeof(struct_addr->m_lapDistance));
  buffer_offset += sizeof(struct_addr->m_lapDistance);

  memcpy(&struct_addr->m_totalDistance, &buffer[buffer_offset], sizeof(struct_addr->m_totalDistance));
  buffer_offset += sizeof(struct_addr->m_totalDistance);

  memcpy(&struct_addr->m_safetyCarDelta, &buffer[buffer_offset], sizeof(struct_addr->m_safetyCarDelta));
  buffer_offset += sizeof(struct_addr->m_safetyCarDelta);

  memcpy(&struct_addr->m_carPosition, &buffer[buffer_offset], sizeof(struct_addr->m_carPosition));
  buffer_offset += sizeof(struct_addr->m_carPosition);

  memcpy(&struct_addr->m_currentLapNum, &buffer[buffer_offset], sizeof(struct_addr->m_currentLapNum));
  buffer_offset += sizeof(struct_addr->m_currentLapNum);

  memcpy(&struct_addr->m_pitStatus, &buffer[buffer_offset], sizeof(struct_addr->m_pitStatus));
  buffer_offset += sizeof(struct_addr->m_pitStatus);

  memcpy(&struct_addr->m_sector, &buffer[buffer_offset], sizeof(struct_addr->m_sector));
  buffer_offset += sizeof(struct_addr->m_sector);

  memcpy(&struct_addr->m_currentLapInvalid, &buffer[buffer_offset], sizeof(struct_addr->m_currentLapInvalid));
  buffer_offset += sizeof(struct_addr->m_currentLapInvalid);

  memcpy(&struct_addr->m_penalties, &buffer[buffer_offset], sizeof(struct_addr->m_penalties));
  buffer_offset += sizeof(struct_addr->m_penalties);

  memcpy(&struct_addr->m_gridPosition, &buffer[buffer_offset], sizeof(struct_addr->m_gridPosition));
  buffer_offset += sizeof(struct_addr->m_gridPosition);

  memcpy(&struct_addr->m_driverStatus, &buffer[buffer_offset], sizeof(struct_addr->m_driverStatus));
  buffer_offset += sizeof(struct_addr->m_driverStatus);

  memcpy(&struct_addr->m_resultStatus, &buffer[buffer_offset], sizeof(struct_addr->m_resultStatus));
  buffer_offset += sizeof(struct_addr->m_resultStatus);

}
