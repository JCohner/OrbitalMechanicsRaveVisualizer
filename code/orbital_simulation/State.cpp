#include "State.h"

#include <iostream>

void State::SetAccel(enum ACCEL_MODE mode, v2d acc) { 
  switch (mode){
  case ACCEL_MODE::ZERO:
    acc_ = v2d(0,0);
    break;
  case ACCEL_MODE::INCREMENT:
    acc_ += acc;
    break;
  case ACCEL_MODE::ABS:
    acc_ = acc;
    break;
  default:
    std::cout << "LOG ERROR SetAccel unkown mode: " << (int)mode << std::endl;
    break;
  } 
}