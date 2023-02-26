#ifndef __MECHANCIS_VISUALIZER_H__
#define __MECHANCIS_VISUALIZER_H__

#include <thread>
#include <memory>


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

  Canvas* canv_; // TODO make smart pointer....
  std::unique_ptr<Engine> eng_;
  void EnqueueEntity(std::shared_ptr<Circle> circ);

public:
  void Setup(); // may be deprecated...
  void StartWork();
  void StopWork();
  bool IsWorking() {return is_working_;}
};




#endif /* __MECHANCIS_VISUALIZER_H__ */



