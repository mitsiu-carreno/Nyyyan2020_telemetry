#include <cstring>
#include "header_packet.hpp"

unsigned int MarshallHeader(char *buffer, PacketHeader *struct_addr, unsigned int buffer_offset){
  memcpy(&struct_addr->m_packetFormat, &buffer[buffer_offset], sizeof(struct_addr->m_packetFormat));
  buffer_offset += sizeof(struct_addr->m_packetFormat); 

  memcpy(&struct_addr->m_gameMajorVersion, &buffer[buffer_offset], sizeof(struct_addr->m_gameMajorVersion));
  buffer_offset += sizeof(struct_addr->m_gameMajorVersion);

  memcpy(&struct_addr->m_gameMinorVersion, &buffer[buffer_offset], sizeof(struct_addr->m_gameMinorVersion));
  buffer_offset += sizeof(struct_addr->m_gameMinorVersion);

  memcpy(&struct_addr->m_packetVersion, &buffer[buffer_offset], sizeof(struct_addr->m_packetVersion));
  buffer_offset += sizeof(struct_addr->m_packetVersion);

  memcpy(&struct_addr->m_packetId, &buffer[buffer_offset], sizeof(struct_addr->m_packetId));
  buffer_offset += sizeof(struct_addr->m_packetId);

  memcpy(&struct_addr->m_sessionUID, &buffer[buffer_offset], sizeof(struct_addr->m_sessionUID));
  buffer_offset += sizeof(struct_addr->m_sessionUID);

  memcpy(&struct_addr->m_sessionTime, &buffer[buffer_offset], sizeof(struct_addr->m_sessionTime));
  buffer_offset += sizeof(struct_addr->m_sessionTime);

  memcpy(&struct_addr->m_frameIdentifier, &buffer[buffer_offset], sizeof(struct_addr->m_frameIdentifier));
  buffer_offset += sizeof(struct_addr->m_frameIdentifier);

  memcpy(&struct_addr->m_playerCarIndex, &buffer[buffer_offset], sizeof(struct_addr->m_playerCarIndex));
  buffer_offset += sizeof(struct_addr->m_playerCarIndex);

  memcpy(&struct_addr->m_secondaryPlayerCarIndex, &buffer[buffer_offset], sizeof(struct_addr->m_secondaryPlayerCarIndex));
  buffer_offset += sizeof(struct_addr->m_secondaryPlayerCarIndex);

  return buffer_offset;
}
