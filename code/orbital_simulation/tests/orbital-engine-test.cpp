#include <iostream>
#include "lin_alg/Vector2D.h"
#include "orbital_simulation/State.h"
#include "orbital_simulation/Engine.h"

int main(){
  auto s = new Engine();
  s->StartWork();

  auto pos = v2d(100,100);

  auto b = std::make_shared<State>(10, pos);

  s->EnqueueEntity(b);


  while(1){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;

} 