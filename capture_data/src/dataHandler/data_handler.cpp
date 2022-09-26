#include <fstream>

#include "data_handler.hpp"
#include "type_alias_F1.hpp"
#include "constants.hpp"
#include "header_packet.hpp"
#include "lap_packet.hpp"


void DataHandler::DebugCarTelemetry(PacketCarTelemetryData *data){
  printf("m_speed %u\n", data->m_carTelemetryData[data->m_header.m_playerCarIndex].m_speed);
  printf("m_throttle %f\n", data->m_carTelemetryData[data->m_header.m_playerCarIndex].m_throttle);
  printf("m_steer %f\n", data->m_carTelemetryData[data->m_header.m_playerCarIndex].m_steer);
  printf("m_brake %f\n", data->m_carTelemetryData[data->m_header.m_playerCarIndex].m_brake);
}

void DataHandler::DebugLap(PacketLapData *data){
  printf("m_currentLapTime %f\n", data->m_lapData[data->m_header.m_playerCarIndex].m_currentLapTime);
  printf("m_lapDistance %f\n",    data->m_lapData[data->m_header.m_playerCarIndex].m_lapDistance);
  printf("m_currentLapNum %u\n",  data->m_lapData[data->m_header.m_playerCarIndex].m_currentLapNum);
}

void DataHandler::ProcessBuffer(char *buffer, int packet_id){
  switch(packet_id){
    case 2:
      PacketLapData data; // TODO change to pointer??
      MarshallLapPacket(buffer, &data);
      
      DataHandler::DebugLap(&data);
      break;
    case 6:
      PacketCarTelemetryData data2;
      MarshallCarTelemetryPacket(buffer, &data2);

      DataHandler::DebugCarTelemetry(&data2);
      break;
  }
}

void DataHandler::WritePacket(uint64 session_id, uint8 lap_num, float session_time, float lap_time, float lap_distance){

    std::string file_name = "lap" + std::to_string(lap_num) + ".csv"; 
    //std::string file_path = constants::kDataDirectory + "/\0" + std::to_string(session_id) + "/\0" + file_name;
    std::string file_path = "";
    file_path.append(constants::kDataDirectory).append(std::to_string(session_id)).append("/").append(file_name);

    std::ofstream write_file;
    write_file.open(file_path, std::ofstream::app);
    write_file << session_time << "," << lap_time << "," << lap_distance << "\n";
    write_file.close();
}

