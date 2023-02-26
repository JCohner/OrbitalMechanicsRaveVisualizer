#include <thread>
#include <iostream> // replace with debug

// for random / random seed gen
#include <cstdlib>
#include <ctime>

#include "MechanicsVisualizer.h"

void MechanicsVisualizer::DrawThread(){
  //TODO replace with mouse / csv based insertion ASAP
  auto ball_pos = v2d(250, 250);
  auto ball = std::make_shared<Circle>(10, ball_pos);

  auto ball_pos_2 = v2d(400, 250);
  auto ball2 = std::make_shared<Circle>(35, ball_pos_2);

  auto canv = Canvas::GetInstance();
  canv->StartWork();

  canv->EnqueueEntity(ball);
  canv->EnqueueEntity(ball2);
  while(is_working_){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}

void MechanicsVisualizer::PhysicsThread(){
  // random
  std::srand(std::time(nullptr)); // use current time as seed for random generator
  auto s = new Engine();
  s->StartWork();

  auto rand_doub = [](){return ((float)std::rand()/((float)RAND_MAX)) * 100.0;}; 
  auto rand_pos = [rand_doub]() {return v2d(rand_doub(),rand_doub());};

  auto b = std::make_shared<State>(10, rand_pos());
  auto c = std::make_shared<State>(5, rand_pos());
  auto d = std::make_shared<State>(1, rand_pos());


  s->EnqueueEntity(b);
  s->EnqueueEntity(c);
  s->EnqueueEntity(d);

  while(is_working_){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
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