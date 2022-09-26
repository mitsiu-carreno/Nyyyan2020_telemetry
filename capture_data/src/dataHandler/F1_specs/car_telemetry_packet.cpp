#include <cstring>
#include "car_telemetry_packet.hpp"

void MarshallCarTelemetry(char *buffer, CarTelemetryData *struct_addr, unsigned int &buffer_offset){
  memcpy(&struct_addr->m_speed, &buffer[buffer_offset], sizeof(struct_addr->m_speed));
  buffer_offset += sizeof(struct_addr->m_speed);
  
  memcpy(&struct_addr->m_throttle, &buffer[buffer_offset], sizeof(struct_addr->m_throttle));
  buffer_offset += sizeof(struct_addr->m_throttle);
  
  memcpy(&struct_addr->m_steer, &buffer[buffer_offset], sizeof(struct_addr->m_steer));
  buffer_offset += sizeof(struct_addr->m_steer);
  
  memcpy(&struct_addr->m_brake, &buffer[buffer_offset], sizeof(struct_addr->m_brake));
  buffer_offset += sizeof(struct_addr->m_brake);
  
  memcpy(&struct_addr->m_clutch, &buffer[buffer_offset], sizeof(struct_addr->m_clutch));
  buffer_offset += sizeof(struct_addr->m_clutch);
  
  memcpy(&struct_addr->m_gear, &buffer[buffer_offset], sizeof(struct_addr->m_gear));
  buffer_offset += sizeof(struct_addr->m_gear);
  
  memcpy(&struct_addr->m_engineRPM, &buffer[buffer_offset], sizeof(struct_addr->m_engineRPM));
  buffer_offset += sizeof(struct_addr->m_engineRPM);
  
  memcpy(&struct_addr->m_drs, &buffer[buffer_offset], sizeof(struct_addr->m_drs));
  buffer_offset += sizeof(struct_addr->m_drs);
  
  memcpy(&struct_addr->m_revLightsPercent, &buffer[buffer_offset], sizeof(struct_addr->m_revLightsPercent));
  buffer_offset += sizeof(struct_addr->m_revLightsPercent);

  for(unsigned int i{0}; i<car_telemetry_array_descriptor.at("m_brakesTemperature"); ++i){  
    memcpy(&struct_addr->m_brakesTemperature[i], &buffer[buffer_offset], sizeof(struct_addr->m_brakesTemperature));
    buffer_offset += sizeof(struct_addr->m_brakesTemperature);
  }
  
  for(unsigned int i{0}; i<car_telemetry_array_descriptor.at("m_tyresSurfaceTemperature"); ++i){  
    memcpy(&struct_addr->m_tyresSurfaceTemperature[i], &buffer[buffer_offset], sizeof(struct_addr->m_tyresSurfaceTemperature));
    buffer_offset += sizeof(struct_addr->m_tyresSurfaceTemperature);
  }
  
  for(unsigned int i{0}; i<car_telemetry_array_descriptor.at("m_tyresInnerTemperature"); ++i){  
    memcpy(&struct_addr->m_tyresInnerTemperature[i], &buffer[buffer_offset], sizeof(struct_addr->m_tyresInnerTemperature));
    buffer_offset += sizeof(struct_addr->m_tyresInnerTemperature);
  }
  
  memcpy(&struct_addr->m_engineTemperature, &buffer[buffer_offset], sizeof(struct_addr->m_engineTemperature));
  buffer_offset += sizeof(struct_addr->m_engineTemperature);
  
  for(unsigned int i{0}; i<car_telemetry_array_descriptor.at("m_tyresPressure"); ++i){  
    memcpy(&struct_addr->m_tyresPressure[i], &buffer[buffer_offset], sizeof(struct_addr->m_tyresPressure));
    buffer_offset += sizeof(struct_addr->m_tyresPressure);
  }
  
  for(unsigned int i{0}; i<car_telemetry_array_descriptor.at("m_surfaceType"); ++i){  
    memcpy(&struct_addr->m_surfaceType[i], &buffer[buffer_offset], sizeof(struct_addr->m_surfaceType));
    buffer_offset += sizeof(struct_addr->m_surfaceType);
  }
}

void MarshallCarTelemetryPacket(char *buffer, PacketCarTelemetryData *struct_addr){
  unsigned int buffer_offset = MarshallHeader(buffer, &struct_addr->m_header);

  for(unsigned int i{0}; i<car_telemetry_packet_array_descriptor.at("m_carTelemetryData"); ++i){
    MarshallCarTelemetry(buffer, &struct_addr->m_carTelemetryData[i], buffer_offset);
  }

  memcpy(&struct_addr->m_buttonStatus, &buffer[buffer_offset], sizeof(struct_addr->m_buttonStatus));
  buffer_offset += sizeof(struct_addr->m_buttonStatus); 

  memcpy(&struct_addr->m_mfdPanelIndex, &buffer[buffer_offset], sizeof(struct_addr->m_mfdPanelIndex));
  buffer_offset += sizeof(struct_addr->m_mfdPanelIndex); 

  memcpy(&struct_addr->m_mfdPanelIndexSecondaryPlayer, &buffer[buffer_offset], sizeof(struct_addr->m_mfdPanelIndexSecondaryPlayer));
  buffer_offset += sizeof(struct_addr->m_mfdPanelIndexSecondaryPlayer); 

  memcpy(&struct_addr->m_suggestedGear, &buffer[buffer_offset], sizeof(struct_addr->m_suggestedGear));
  buffer_offset += sizeof(struct_addr->m_suggestedGear); 

}
