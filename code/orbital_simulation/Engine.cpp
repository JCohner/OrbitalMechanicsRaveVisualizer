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

    std::cout << "\t\tdistance between object is: " << scalar_dist << " on a unit vec: " << unit_vector << "\r\n";
    std::cout << "\t\tresultant accel: " << accel << "\r\n";
    return accel;
  };

  // todo find some smart way to do this using an adgency matrix
  for (auto e1 : entity_queue_){
    std::cout << "\tLoopin ob Obj:" << e1->GetMass() << "\r\n";
    
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

    // edge_viscosity caluclation
    auto damping_coeff = -5 * pow( (e1->GetPos().distance(v2d(400,400)) / 800.0) , 2); // damps as a function of distance from origin
    std::cout << "\t\tdistance from center is: " << e1->GetPos().distance(v2d(400,400)) << " at vel: "<< e1->GetVel() << " which leads to a coeff: " << damping_coeff << "\r\n";
    auto decel_from_edge_closeness = (1.0 / e1->GetMass()) * (damping_coeff * e1->GetVel());
    std::cout << "\t\tinduced decell of: " << decel_from_edge_closeness << "\r\n";
    e1->SetAccel(ACCEL_MODE::INCREMENT, decel_from_edge_closeness);

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
    auto timing_us = std::chrono::duration_cast<std::chrono::microseconds>(end_ - start_).count();
    std::cout << "Work loop took: " << timing_us << "\r\n";
    // holds to 1ms
    while (timing_us < 1000){
      end_ = std::chrono::steady_clock::now();
      timing_us = std::chrono::duration_cast<std::chrono::microseconds>(end_ - start_).count();
    }
    std::cin.get();
  }
}

void Engine::EnqueueEntity(std::shared_ptr<State> entity){
  std::cout << "new entry of mass: " << entity->GetMass() << " at pos: " << entity->GetPos() << std::endl;
  entity_queue_.push_back(entity); 
}