#include "Engine.h"

#include <iostream>

void Engine::WorkFunction(){
    for (auto ent : entity_queue_){
      std::cout << "loopin through boys: " << ent->GetMass() << std::endl;
    }
}

//runs simulation on all managed entities
void Engine::WorkThread() {
  while(is_running_){
    start_ = std::chrono::steady_clock::now();
    // going to start by doing this in the dumbest possible way
    WorkFunction();
    end_ = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count() < 1000){
      end_ = std::chrono::steady_clock::now();
    }
  }
}

void Engine::EnqueueEntity(std::shared_ptr<State> entity){
  std::cout << "new entry of mass: " << entity->GetMass() << " at pos: " << entity->GetPos() << std::endl;
  entity_queue_.push_back(entity); 
}