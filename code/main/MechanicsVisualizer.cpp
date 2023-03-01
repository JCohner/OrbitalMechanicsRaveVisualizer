#include <thread>
#include <iostream> // replace with debug

// for random / random seed gen
#include <cstdlib>
#include <ctime>

#include "MechanicsVisualizer.h"

void MechanicsVisualizer::DrawThread(){
  canv_->StartWork();

  while(is_working_){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void MechanicsVisualizer::PhysicsThread(){
  // random
  std::srand(std::time(nullptr)); // use current time as seed for random generator
  eng_->StartWork();

  while(is_working_){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

// this object doesn't itself maintain a queue but enqueues to relevant member objects
void MechanicsVisualizer::EnqueueEntity(std::shared_ptr<Circle> circ){
  canv_->EnqueueEntity(std::dynamic_pointer_cast<Shape>(circ));
  eng_->EnqueueEntity(std::dynamic_pointer_cast<State>(circ));
}

void MechanicsVisualizer::Setup(){
  // instanitalize both our member work objects
  canv_ = Canvas::GetInstance();
  eng_ = std::make_unique<Engine>();

  //TODO replace with mouse / csv based insertion ASAP
  auto ball_state = State(10, {250, 250}, {5, 10}, {0,0});
  auto ball = std::make_shared<Circle>(10, ball_state);

  auto ball2_state = State(10, {650, 650}, {-10, -10}, {0,0});
  auto ball2 = std::make_shared<Circle>(10, ball2_state);

  EnqueueEntity(ball);
  EnqueueEntity(ball2);
}

void MechanicsVisualizer::StartWork(){
  is_working_ = true;
  draw_thread_ = std::thread(&MechanicsVisualizer::DrawThread, this);
  std::cout << "spawn draw on: " << draw_thread_.get_id() << "\r\n";
  physics_thread_ = std::thread(&MechanicsVisualizer::PhysicsThread, this);
  std::cout << "spawn phys on: " << physics_thread_.get_id() << "\r\n";
}

void MechanicsVisualizer::StopWork(){
  // draw_thread_.join();
  physics_thread_.join();
  std::cout << "both threads have been joined\r\n";
  is_working_ = false;
}