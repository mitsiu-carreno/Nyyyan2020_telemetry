#include <fstream>

#include "data_handler.hpp"
#include "type_alias_F1.hpp"
#include "constants.hpp"

void DataHandler::ProcessBuffer(char *buffer, int packet_id){
  switch(packet_id){
    case 0:
      break;
    case 2:
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

