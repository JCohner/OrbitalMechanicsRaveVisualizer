#ifndef __STATE_H__
#define __STATE_H__

#include <functional>

#include "lin_alg/Vector2D.h"

// Enum for setting mode of SetAccel
enum struct ACCEL_MODE {ZERO = 0, INCREMENT = 1, ABS = 2};

class State {
private:
  const double DELTA_T = 0.0001; // debating if i want to go with chrono for this
  double mass_ = 0;
  v2d pos_ = {};
  v2d vel_ = {};
  v2d acc_ = {};
public:
  State() {}
  State(double mass, v2d pos, v2d vel = {}, v2d accel = {}) :  mass_(mass), pos_(pos), vel_(vel), acc_(accel) {}
  v2d GetPos() { return pos_;}
  v2d GetVel() { return vel_;}
  v2d GetAccel() { return acc_;}
  double GetMass() { return mass_;}

  void SetAccel(enum ACCEL_MODE mode, v2d acc);
  void UpdateState();
};



#endif /* __STATE_H__ */