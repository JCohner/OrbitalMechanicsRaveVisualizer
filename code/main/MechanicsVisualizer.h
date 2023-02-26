#ifndef __MECHANCIS_VISUALIZER_H__
#define __MECHANCIS_VISUALIZER_H__

#include <thread>

#include "gl_visualizer/Canvas.h"
#include "shapes/Circle.h"

#include "orbital_simulation/Engine.h"
#include "orbital_simulation/State.h"

class MechanicsVisualizer {
private:
  std::thread draw_thread_;
  std::thread physics_thread_;

  void DrawThread();
  void PhysicsThread();

  bool is_working_ = false;

public:
  void StartWork();
  void StopWork();
  bool IsWorking() {return is_working_;}
};




#endif /* __MECHANCIS_VISUALIZER_H__ */



