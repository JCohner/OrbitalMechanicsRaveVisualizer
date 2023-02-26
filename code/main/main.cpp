#include <csignal>
#include <iostream>
#include <chrono>

#include "MechanicsVisualizer.h"

auto mv = MechanicsVisualizer();

void signalHandler( int signum ) {
  std::cout << "Interrupt signal (" << signum << ") received.\n";
  mv.StopWork();
  exit(signum);  
}

int main(int argc, char *argv[]){
  signal(SIGINT, signalHandler);  
  mv.Setup();
  mv.StartWork();
  while (mv.IsWorking()){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  return 0;
}