#include "Engine.h"

#include <iostream>

//runs simulation on all managed entities
void Engine::WorkThread() {
  std::cout << "we fucking" << std::endl;
  while(is_running_){
    start_ = std::chrono::steady_clock::now();
    for (auto ent : entity_queue_){
      std::cout << "suckle" << ent->GetPos() << std::endl;
    }
    end_ = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count() < 1000){
      end_ = std::chrono::steady_clock::now();
    }
  }
}