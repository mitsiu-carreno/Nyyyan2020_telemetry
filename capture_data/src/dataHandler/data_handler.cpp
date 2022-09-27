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
  static uint8 internal_lap_num = 0;
  switch(packet_id){
    case 2:
      PacketLapData data; // TODO change to pointer??
      MarshallLapPacket(buffer, &data);

      if(data.m_lapData[data.m_header.m_playerCarIndex].m_lapDistance >= 0){
        internal_lap_num = data.m_lapData[data.m_header.m_playerCarIndex].m_currentLapNum;
        DataHandler::WritePacket(
          0,
          internal_lap_num,
          data.m_header.m_sessionTime,
          data.m_lapData[data.m_header.m_playerCarIndex].m_currentLapTime,
          data.m_lapData[data.m_header.m_playerCarIndex].m_lapDistance,
          0,0,0,0
        );
      }
      
      //DataHandler::DebugLap(&data);
      break;
    case 6:
      PacketCarTelemetryData data2;
      MarshallCarTelemetryPacket(buffer, &data2);

      if(internal_lap_num != 0){
        DataHandler::WritePacket(
          1,
          internal_lap_num,
          data2.m_header.m_sessionTime,
          0,0,
          data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_speed,
          data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_throttle,
          data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_steer,
          data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_brake
        );
      }

      //DataHandler::DebugCarTelemetry(&data2);
      break;
  }
}

void DataHandler::WritePacket(bool car_tel, uint8 internal_lap_num, float session_time, float current_lap_time, float lap_distance, uint16 speed, float throttle, float steer, float brake){

    std::string file_name = "lap" + std::to_string(internal_lap_num) + ".csv"; 
    //std::string file_path = constants::kDataDirectory + "/\0" + std::to_string(session_id) + "/\0" + file_name;
    std::string file_path = "";
    //file_path.append(constants::kDataDirectory).append(std::to_string(session_id)).append("/").append(file_name);
    file_path.append(constants::kDataDirectory).append(file_name);

    std::ofstream write_file;
    write_file.open(file_path, std::ofstream::app);
    write_file << car_tel << "," << session_time << "," << current_lap_time << "," << lap_distance << "," << speed << "," << throttle << "," << steer << "," << brake <<  "\n";
    write_file.close();
}

