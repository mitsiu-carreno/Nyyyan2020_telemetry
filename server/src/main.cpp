#include "thread.hpp"

// Forward declaration of variable defined in globals.cpp
extern int gPort;

int main(int argc, char *argv[]){
  // argv[0] is the program name
  
  // If an argument is passed, use it as listening port 
  if(argv[1] != NULL){
    // THIS NEED EXCEPTION HANDLING
    gPort = std::stoi(argv[1]);
  }

  thread::HandleThreads();

  return 0;
}
