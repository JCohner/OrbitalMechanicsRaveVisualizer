#include <functional>

#include <iostream>

#include "lin_alg/Vector2D.h"
#include "orbital_simulation/State.h"
#include "orbital_simulation/Engine.h"

// random int gen
#include <cstdlib>
#include <ctime>

int main(){
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

  while(1){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;

} 