#include <iostream>
#include "lin_alg/Vector2D.h"
#include "orbital_simulation/State.h"
#include "entities/BallEntity.h"
#include "orbital_simulation/Engine.h"
int main(){
  auto s = new Engine();
  s->StartWork();

  auto b = std::make_shared<Ball>(5);

  // s->EnqueueEntity()


  while(1){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;

} 