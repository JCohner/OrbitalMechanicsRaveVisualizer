#include <iostream>
#include <memory>
#include <chrono>

#include "lin_alg/Vector2D.h"
#include "gl_visualizer/Canvas.h"
#include "entities/Ball.h"

int main(){
  // make a ball object to visualize
  auto ball_pos = Vector2D(250, 250);
  auto ball = std::make_shared<Ball>(10, ball_pos);

  auto ball_pos_2 = Vector2D(400, 250);
  auto ball2 = std::make_shared<Ball>(35, ball_pos_2);

  // get instance of canvas
  auto canv = Canvas::GetInstance();
  canv->StartWork();
  canv->EnqueueShape(ball);
  canv->EnqueueShape(ball2);
  while(1){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
