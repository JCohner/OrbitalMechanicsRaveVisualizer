#ifndef __STATE_H__
#define __STATE_H__

#include <functional>

#include "lin_alg/Vector2D.h"

// Enum for setting mode of SetAccel
enum struct ACCEL_MODE {ZERO = 0, INCREMENT = 1, ABS = 2};

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
  void SetPos(v2d pos) { pos_ = pos;}
  void SetVel(v2d vel) { vel_ = vel;}
  void SetAccel(enum ACCEL_MODE mode, v2d acc);
  double GetMass() { return mass_;}
};



#endif /* __STATE_H__ */