#include "Engine.h"
#include <functional>
#include <memory>

#include <iostream>


void Engine::WorkFunction(){
  // compute the acceleration object 2 induces upon object 1
  // accel_1 = G * mass_2 * 1 / distance^2
  auto compute_accel = [](std::shared_ptr<State> s1, std::shared_ptr<State> s2){
    const double G = 6.6742e-11;
    
    auto scalar_dist = s1->GetPos().distance(s2->GetPos());
    auto unit_vector = s1->GetPos().unit_vec_to(s2->GetPos());
    auto grav_mass_mod_scalar = G * s2->GetMass();

    std::cout << "distance between object is: " << scalar_dist << " on a unit vec: " << unit_vector << std::endl;
    return  grav_mass_mod_scalar / std::pow(scalar_dist, 2) * unit_vector;
  };

  // todo find some smart way to do this using an adgency matrix
  for (auto ent : entity_queue_){
    std::cout << "loopin through boys: " << ent->GetMass() << std::endl;
    
    // zero out accel
    ent->SetAccel(ACCEL_MODE::ZERO, {});

    // calculate effect of every other entity // TODO: use adgency matrix to make this better
    for (auto comp_ent : entity_queue_){
      if (ent == comp_ent){
        continue;
      }

      // vector representing accel due to object
      auto accel_from_obj = compute_accel(ent, comp_ent);

      // increment accel vector acting on entity
      ent->SetAccel(ACCEL_MODE::INCREMENT, accel_from_obj);
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