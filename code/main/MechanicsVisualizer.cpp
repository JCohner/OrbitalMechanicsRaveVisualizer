#include <thread>
#include <iostream> // replace with debug

#include "MechanicsVisualizer.h"

void MechanicsVisualizer::DrawThread(){

}

void MechanicsVisualizer::PhysicsThread(){

}

void MechanicsVisualizer::StartWork(){
  is_working_ = true;
  draw_thread_ = std::thread(&MechanicsVisualizer::DrawThread, this);
  std::cout << "spawn draw on: " << draw_thread_.get_id() << "\r\n";
  physics_thread_ = std::thread(&MechanicsVisualizer::DrawThread, this);
  std::cout << "spawn phys on: " << physics_thread_.get_id() << "\r\n";
}

void MechanicsVisualizer::StopWork(){
  draw_thread_.join();
  physics_thread_.join();
  std::cout << "both threads have been joined\r\n";
  is_working_ = false;
}