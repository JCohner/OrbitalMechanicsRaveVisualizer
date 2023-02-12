#ifndef __STATE_H__
#define __STATE_H__

#include <functional>

#include "lin_alg/Vector2D.h"

class State {
private:
  v2d pos_;
  v2d vel_;
  v2d acc_;
public:
  State() {}
  State(v2d pos, v2d vel, v2d accel = {}) : pos_(pos), vel_(vel), acc_(accel) {}
  std::function<v2d(void)> q = [this](){return this->pos_;};
  std::function<v2d(void)> qdot = [this](){return this->vel_;};
  std::function<v2d(void)> qddot = [this](){return this->acc_;};
};



#endif /* __STATE_H__ */