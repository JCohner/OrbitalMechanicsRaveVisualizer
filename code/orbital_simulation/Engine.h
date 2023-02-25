#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <thread>
#include <iostream> // debug
#include <chrono>
#include <vector>

#include "State.h"


class Engine {
private:
  // quue of objects to be rendered in render thread
  std::vector<std::shared_ptr<State>> entity_queue_;

  void WorkThread(); // thread spawned as workthread
  void WorkFunction(); // function that does simulation
  
  std::thread work_thread_;
  bool is_running_ = false;

  // timing things
  std::chrono::time_point<std::chrono::steady_clock> start_;
  std::chrono::time_point<std::chrono::steady_clock> end_;
public:
  void StartWork() {
    is_running_ = true;
    work_thread_ = std::thread(&Engine::WorkThread, this);
  }
  void StopWork() {
    is_running_ = false;
    work_thread_.join();
    std::cout << "joined workthread" << std::endl;
  }
  void EnqueueEntity(std::shared_ptr<State> entity);
};


#endif /* __ENGINE_H__ */