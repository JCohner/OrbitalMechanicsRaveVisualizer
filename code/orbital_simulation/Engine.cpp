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
    auto grav_mass_mod_scalar = -G * s2->GetMass();

    auto accel = grav_mass_mod_scalar * (1.0 / std::pow(scalar_dist, 2)) * unit_vector;

    std::cout << "distance between object is: " << scalar_dist << " on a unit vec: " << unit_vector << "\r\n";
    std::cout << "resultant accel: " << accel << std::endl;
    return accel;
  };

  // todo find some smart way to do this using an adgency matrix
  for (auto e1 : entity_queue_){
    std::cout << "loopin through boys: " << e1->GetMass() << std::endl;
    
    // zero out accel
    e1->SetAccel(ACCEL_MODE::ZERO, {});

    // calculate effect of every other entity // TODO: use adgency matrix to make this better
    for (auto e2 : entity_queue_){
      if (e1 == e2){
        continue;
      }

      // vector representing accel due to object
      auto accel_from_obj = compute_accel(e1, e2);

      // increment accel vector acting on entity
      e1->SetAccel(ACCEL_MODE::INCREMENT, accel_from_obj);
    }

    // now do kinematics update:
    e1->UpdateState();
  }
}

//runs simulation on all managed entities
void Engine::WorkThread() {
  while(is_running_){
    start_ = std::chrono::steady_clock::now();
    // going to start by doing this in the dumbest possible way
    WorkFunction();
    end_ = std::chrono::steady_clock::now();
    // holds to 1000
    while (std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count() < 10){
      end_ = std::chrono::steady_clock::now();
    }
    std::cin.get();
  }
}

void Engine::EnqueueEntity(std::shared_ptr<State> entity){
  std::cout << "new entry of mass: " << entity->GetMass() << " at pos: " << entity->GetPos() << std::endl;
  entity_queue_.push_back(entity); 
}