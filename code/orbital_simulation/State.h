#ifndef __STATE_H__
#define __STATE_H__

#include <functional>

#include "lin_alg/Vector2D.h"

class State {
private:
  double mass_;
  v2d pos_;
  v2d vel_;
  v2d acc_;
public:
  State() {}
  State(double mass, v2d pos, v2d vel = {}, v2d accel = {}) :  mass_(mass), pos_(pos), vel_(vel), acc_(accel) {}
  v2d GetPos() { return pos_;}
  v2d GetVel() { return vel_;}
  v2d GetAccel() { return acc_;}
  double GetMass() { return mass_;}
};

#endif /* __STATE_H__ */