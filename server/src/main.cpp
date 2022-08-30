#include <string>
#include "thread.hpp"
#include "constants.hpp"

// Forward declaration of variable defined in globals.cpp
extern int gPort;

int main(int argc, char *argv[]){
  // argv[0] is the program name
  
  // If an argument is passed, use it as listening port 
  if(argv[1] != NULL){
    try{
      gPort = std::stoi(argv[1]);
    }catch(...){
      thread::PrintSafe("Couldn't use input PORT using " + std::to_string(gPort) + "\n");
      gPort = constants::kDefaultPort;
    }
  }

  //thread::HandleThreads();

  return 0;
}
