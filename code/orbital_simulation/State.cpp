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

void State::UpdateState(){
  // update velocity
  std::cout << "\t\t\tinit vel: " << vel_ << "\r\n";
  vel_ += State::DELTA_T * acc_; // could use chrono for delta t calc...
  std::cout << "\t\t\tupdate vel: " << vel_ << "\r\n";
  std::cout << "\t\t\tinit pos: " << pos_ << "\r\n";
  pos_ += State::DELTA_T * vel_;
  std::cout << "\t\t\tupdate pos: " << pos_ << "\r\n";
}