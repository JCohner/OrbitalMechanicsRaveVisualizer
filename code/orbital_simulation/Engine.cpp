#include "Engine.h"

#include <iostream>

//runs simulation on all managed entities
void Engine::WorkThread(){
  for (auto ent : entity_queue_){
    std::cout << "suckle" << std::endl;
  }
}