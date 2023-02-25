#include "Engine.h"
#include <functional>
#include <memory>

#include <iostream>


void Engine::WorkFunction(){
  auto compute_force = [](std::shared_ptr<State> s1, std::shared_ptr<State> s2){
    const double G = 6.6742e-11;
    auto dist = s1->GetPos().distance(s2->GetPos());
    std::cout << "distance is: " << dist << std::endl;
    return G * s1->GetMass() * s2->GetMass() / std::pow(dist, 2);
  };

  // todo find some smart way to do this using an agency matrix
  for (auto ent : entity_queue_){
    auto force_vec = v2d(); 
    std::cout << "loopin through boys: " << ent->GetMass() << std::endl;
    for (auto comp_ent : entity_queue_){
      if (ent == comp_ent){
        std::cout << "\tyeah fuckk (good variant)" << std::endl; 
        continue;
      }
      std::cout << "\tcomparing to this john: " << compute_force(ent, comp_ent) << std::endl;
    }
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