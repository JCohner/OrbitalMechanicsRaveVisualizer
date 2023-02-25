#include <iostream>
#include <memory>
#include <chrono>

#include "lin_alg/Vector2D.h"
#include "gl_visualizer/Canvas.h"
#include "shapes/Circle.h"

int main(){
  // make a ball object to visualize
  auto ball_pos = v2d(250, 250);
  auto ball = std::make_shared<Circle>(10, ball_pos);

  auto ball_pos_2 = v2d(400, 250);
  auto ball2 = std::make_shared<Circle>(35, ball_pos_2);

  // get instance of canvas
  auto canv = Canvas::GetInstance();
  canv->StartWork();
  canv->EnqueueEntity(ball);
  canv->EnqueueEntity(ball2);
  while(1){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
