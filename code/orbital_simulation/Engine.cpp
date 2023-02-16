#include "Engine.h"

#include <iostream>

//runs simulation on all managed entities
void Engine::WorkThread() {
  std::cout << "we fucking" << std::endl;
  for (auto ent : entity_queue_){
    std::cout << "suckle" << std::endl;
  }
}