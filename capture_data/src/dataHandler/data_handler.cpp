#include <fstream>

#include <sstream>
#include <iomanip>
/*
#include <stdio.h>  // Delete file
#include <cstring>  // strcpy & strcat
#include <stdlib.h> // itoa
#include <stdio.h>
#include <stdlib.h>
*/

#include "data_handler.hpp"
#include "type_alias_F1.hpp"
#include "constants.hpp"
#include "header_packet.hpp"
#include "lap_packet.hpp"


void DataHandler::DebugCarTelemetry(PacketCarTelemetryData *data){
  /*
  printf("(uint8  X.00)header->m_gameMajorVersion %u\n", data->m_header.m_gameMajorVersion);
  printf("(int8      0)cartel->m_suggestedGear %i\n", data->m_suggestedGear);
  printf("(uint16 2020)header->m_packetFormat %u\n", data->m_header.m_packetFormat);
  printf("(float      )header->m_sessionTime %f\n", data->m_header.m_sessionTime);
  printf("(uint64     )header->m_sessionUID %lu\n", data->m_header.m_sessionUID);
  printf("(uint32     )header->m_frameIdentifier %u\n\n", data->m_header.m_frameIdentifier);
  */
  printf("player_i %u\n", data->m_header.m_playerCarIndex);
  printf("0 %u\n", data->m_carTelemetryData[0].m_speed);
  printf("1 %u\n", data->m_carTelemetryData[1].m_speed);
  printf("2 %u\n", data->m_carTelemetryData[2].m_speed);
  printf("3 %u\n", data->m_carTelemetryData[3].m_speed);
  printf("4 %u\n", data->m_carTelemetryData[4].m_speed);
  printf("5 %u\n", data->m_carTelemetryData[5].m_speed);
  printf("6 %u\n", data->m_carTelemetryData[6].m_speed);
  printf("7 %u\n", data->m_carTelemetryData[7].m_speed);
  printf("8 %u\n", data->m_carTelemetryData[8].m_speed);
  printf("9 %u\n", data->m_carTelemetryData[9].m_speed);
  printf("10 %u\n", data->m_carTelemetryData[10].m_speed);
  printf("11 %u\n", data->m_carTelemetryData[11].m_speed);
  printf("12 %u\n", data->m_carTelemetryData[12].m_speed);
  printf("13 %u\n", data->m_carTelemetryData[13].m_speed);
  printf("14 %u\n", data->m_carTelemetryData[14].m_speed);
  printf("15 %u\n", data->m_carTelemetryData[15].m_speed);
  printf("16 %u\n", data->m_carTelemetryData[16].m_speed);
  printf("17 %u\n", data->m_carTelemetryData[17].m_speed);
  printf("18 %u\n", data->m_carTelemetryData[18].m_speed);
  printf("19 %u\n", data->m_carTelemetryData[19].m_speed);
  printf("20 %u\n", data->m_carTelemetryData[20].m_speed);
  printf("21 %u\n", data->m_carTelemetryData[21].m_speed);
  //printf("speed %u\n", data->m_carTelemetryData[data->m_header.m_playerCarIndex].m_speed);
  //printf("throttle %f\n", data->m_carTelemetryData[data->m_header.m_playerCarIndex].m_throttle);
  //printf("clutch %u\n\n", data->m_carTelemetryData[data->m_header.m_playerCarIndex].m_clutch);
  //printf("speed %u\n", data->m_carTelemetryData[0].m_speed);
  //printf("throttle %f\n", data->m_carTelemetryData[0].m_throttle);
  //printf("clutch %u\n\n", data->m_carTelemetryData[0].m_clutch);
}

void DataHandler::DebugLap(PacketLapData *data){
  printf("m_currentLapTime %f\n", data->m_lapData[data->m_header.m_playerCarIndex].m_currentLapTime);
  printf("m_lapDistance %f\n",    data->m_lapData[data->m_header.m_playerCarIndex].m_lapDistance);
  printf("m_currentLapNum %u\n\n",  data->m_lapData[data->m_header.m_playerCarIndex].m_currentLapNum);
}

void DataHandler::ProcessBuffer(char *buffer, int packet_id){
  // Creating a stringstream object
  std::stringstream ss;

  //const uint8 p_index = 0;

  switch(packet_id){
    case 2:
      PacketLapData data; // TODO change to pointer??
      MarshallLapPacket(buffer, &data);

      
      //if(data.m_lapData[data.m_header.m_playerCarIndex].m_lapDistance >= 1 
      //    && data.m_header.m_sessionTime > 1){

       
      // Formatting the output using manipulators
      ss << std::fixed << std::setprecision(6) 
        << data.m_header.m_packetFormat << "," 
        << static_cast<int>(data.m_header.m_gameMajorVersion) << "," 
        << static_cast<int>(data.m_header.m_gameMinorVersion) << "," 
        << static_cast<int>(data.m_header.m_packetVersion) << ","
        << static_cast<int>(data.m_header.m_packetId) << ","
        << data.m_header.m_sessionUID << "," 
        << data.m_header.m_sessionTime << "," 
        << data.m_header.m_frameIdentifier << ","
        << static_cast<int>(data.m_header.m_playerCarIndex) << ","
        << static_cast<int>(data.m_header.m_secondaryPlayerCarIndex) << ","
        
        << data.m_lapData[data.m_header.m_playerCarIndex].m_lastLapTime << ","
        << data.m_lapData[data.m_header.m_playerCarIndex].m_currentLapTime << ","
        << data.m_lapData[data.m_header.m_playerCarIndex].m_sector1TimeInMS << ","
        << data.m_lapData[data.m_header.m_playerCarIndex].m_sector2TimeInMS << ","
        << data.m_lapData[data.m_header.m_playerCarIndex].m_bestLapTime << ","
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_bestLapNum) << "," 
        << data.m_lapData[data.m_header.m_playerCarIndex].m_bestLapSector1TimeInMS << ","
        << data.m_lapData[data.m_header.m_playerCarIndex].m_bestLapSector2TimeInMS << ","
        << data.m_lapData[data.m_header.m_playerCarIndex].m_bestLapSector3TimeInMS << ","
        << data.m_lapData[data.m_header.m_playerCarIndex].m_bestOverallSector1TimeInMS << ","
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_bestOverallSector1LapNum) << "," 
        << data.m_lapData[data.m_header.m_playerCarIndex].m_bestOverallSector2TimeInMS << ","
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_bestOverallSector2LapNum) << "," 
        << data.m_lapData[data.m_header.m_playerCarIndex].m_bestOverallSector3TimeInMS << ","
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_bestOverallSector3LapNum) << "," 
        << data.m_lapData[data.m_header.m_playerCarIndex].m_lapDistance << ","
        << data.m_lapData[data.m_header.m_playerCarIndex].m_totalDistance << ","
        << data.m_lapData[data.m_header.m_playerCarIndex].m_safetyCarDelta << ","
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_carPosition) << "," 
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_currentLapNum) << ","
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_pitStatus) << "," 
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_sector) << "," 
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_currentLapInvalid) << "," 
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_penalties) << "," 
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_gridPosition) << "," 
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_driverStatus) << "," 
        << static_cast<int>(data.m_lapData[data.m_header.m_playerCarIndex].m_resultStatus);


        //<< data.m_lapData[p_index]. << ","
        //<< static_cast<int>(data.m_lapData[p_index].) << "," 

      DataHandler::WritePacket(0, ss.str().c_str());

      //DataHandler::DebugLap(&data);
      break;

    case 6:
      PacketCarTelemetryData data2;
      MarshallCarTelemetryPacket(buffer, &data2);
       
      // Formatting the output using manipulators
      ss << std::fixed << std::setprecision(6) 
        << data2.m_header.m_packetFormat << "," 
        << static_cast<int>(data2.m_header.m_gameMajorVersion) << "," 
        << static_cast<int>(data2.m_header.m_gameMinorVersion) << "," 
        << static_cast<int>(data2.m_header.m_packetVersion) << ","
        << static_cast<int>(data2.m_header.m_packetId) << ","
        << data2.m_header.m_sessionUID << "," 
        << data2.m_header.m_sessionTime << "," 
        << data2.m_header.m_frameIdentifier << ","
        << static_cast<int>(data2.m_header.m_playerCarIndex) << ","
        << static_cast<int>(data2.m_header.m_secondaryPlayerCarIndex) << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_speed << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_throttle << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_steer << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_brake << ","
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_clutch) << ","
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_gear) << "," 
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_engineRPM << ","
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_drs) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_revLightsPercent) << "," 
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_brakesTemperature[0] << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_brakesTemperature[1] << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_brakesTemperature[2] << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_brakesTemperature[3] << ","
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresSurfaceTemperature[0]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresSurfaceTemperature[1]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresSurfaceTemperature[2]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresSurfaceTemperature[3]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresInnerTemperature[0]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresInnerTemperature[1]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresInnerTemperature[2]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresInnerTemperature[3]) << "," 
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_engineTemperature << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresPressure[0] << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresPressure[1] << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresPressure[2] << ","
        << data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_tyresPressure[3] << ","
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_surfaceType[0]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_surfaceType[1]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_surfaceType[2]) << "," 
        << static_cast<int>(data2.m_carTelemetryData[data2.m_header.m_playerCarIndex].m_surfaceType[3]);


        //<< data2.m_carTelemetryData[p_index]. << ","
        //<< static_cast<int>(data2.) << ","
        //<< static_cast<int>(data2.m_carTelemetryData[p_index].) << "," 

      DataHandler::WritePacket(1, ss.str().c_str());

      //DataHandler::DebugCarTelemetry(&data2);
      break;
  }
}

void DataHandler::WritePacket(bool isCarTel, const char* data){
  std::string file_name = isCarTel ? "car_telem.csv" : "lap.csv"; 
  //std::string file_path = constants::kDataDirectory + "/\0" + std::to_string(session_id) + "/\0" + file_name;
  std::string file_path = "";
  //file_path.append(constants::kDataDirectory).append(std::to_string(session_id)).append("/").append(file_name);
  file_path.append(constants::kDataDirectory).append(file_name);

  std::ofstream write_file;
  write_file.open(file_path, std::ofstream::app);
  write_file << data <<  "\n";
  write_file.close();
}

void DataHandler::PrepareFiles(){
  std::string file_path = "";
  file_path.append(constants::kDataDirectory).append("car_telem.csv");

  std::ofstream file_h;
  file_h.open(file_path, std::ofstream::out);
  file_h 
    << "packetFormat" << ","
    << "gameMajorVersion" << ","
    << "gameMinorVersion" << ","
    << "packetVersion" << ","
    << "packetId" << ","
    << "sessionUID" << ","
    << "sessionTime" << ","
    << "frameIdentifier" << ","
    << "playerCarIndex" << ","
    << "secondaryPlayerCarIndex" << ","

    << "speed" << ","
    << "throttle" << ","
    << "steer" << ","
    << "brake" << ","
    << "clutch" << ","
    << "gear" << ","
    << "engineRPM" << ","
    << "drs" << ","
    << "revLightsPercent" << ","
    << "brakesTempRearL" << ","
    << "brakesTempRearR" << ","
    << "brakesTempFrontL" << ","
    << "brakesTempFrontR" << ","
    << "tyresSurfaceTempRearL" << ","
    << "tyresSurfaceTempRearR" << ","
    << "tyresSurfaceTempFrontL" << ","
    << "tyresSurfaceTempFrontR" << ","
    << "tyresInnerTempRearL" << ","
    << "tyresInnerTempRearR" << ","
    << "tyresInnerTempFrontL" << ","
    << "tyresInnerTempFrontR" << ","
    << "engineTemperature" << ","
    << "tyresPressureRearL" << ","
    << "tyresPressureRearR" << ","
    << "tyresPressureFrontL" << ","
    << "tyresPressureFrontR" << ","
    << "surfaceTypeRearL" << ","
    << "surfaceTypeRearR" << ","
    << "surfaceTypeFrontL" << ","
    << "surfaceTypeFrontR" << "\n";

  file_h.close();


  file_path = "";
  file_path.append(constants::kDataDirectory).append("lap.csv");

  file_h.open(file_path, std::ofstream::out);
  file_h 
    << "packetFormat" << ","
    << "gameMajorVersion" << ","
    << "gameMinorVersion" << ","
    << "packetVersion" << ","
    << "packetId" << ","
    << "sessionUID" << ","
    << "sessionTime" << ","
    << "frameIdentifier" << ","
    << "playerCarIndex" << ","
    << "secondaryPlayerCarIndex" << ","

    << "lastLapTime" << ","
    << "currentLapTime" << ","
    << "sector1TimeInMS" << ","
    << "sector2TimeInMS" << ","
    << "bestLapTime" << ","
    << "bestLapNum" << ","
    << "bestLapSector1TimeInMS" << ","
    << "bestLapSector2TimeInMS" << ","
    << "bestLapSector3TimeInMS" << ","
    << "bestOverallSector1TimeInMS" << ","
    << "bestOverallSector1LapNum" << ","
    << "bestOverallSector2TimeInMS" << ","
    << "bestOverallSector2LapNum" << ","
    << "bestOverallSector3TimeInMS" << ","
    << "bestOverallSector3LapNum" << ","
    << "lapDistance" << ","
    << "totalDistance" << ","
    << "safetyCarDelta" << ","
    << "carPosition" << ","
    << "currentLapNum" << ","
    << "pitStatus" << ","
    << "sector" << ","
    << "currentLapInvalid" << ","
    << "penalties" << ","
    << "gridPosition" << ","
    << "driverStatus" << ","
    << "resultStatus" << "\n";

  file_h.close();
}




