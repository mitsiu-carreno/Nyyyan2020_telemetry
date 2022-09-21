#include <thread>
#include <iostream>
#include "socket.hpp"
#include "plot.hpp"


int main(){

  PositionData data;

  std::thread t1(sockethandler::ListenConnections, &data);
  DrawPlot(&data);

  t1.join();

  return 0;
}
