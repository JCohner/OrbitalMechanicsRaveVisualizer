#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "lin_alg/Vector2D.h"
#include "orbital_simulation/State.h"

#define PI 3.14159265f // unfortunately a good place for this

static int global_count = 0;

// Shape is the base bulding block "entity" object
// Shape extends the State object by allowing it to be rendered and tracked
class Shape : public State {
public:
  enum Type {NONE = 0, BALL = 1 };
  Shape () : State(), type_(Shape::Type::NONE) {
    id_ = global_count++;
  }
  Shape (Shape::Type type, double mass, v2d pos) : State(mass, pos), type_(type){
    id_ = global_count++;
  }
  Shape (Shape::Type type, State state) : State(state), type_(type){
    id_ = global_count++;
  }
  /* Accessors */
  Shape::Type GetType() {return type_;}
  v2d GetCentroid() {return GetPos();}
  virtual void Render() {};
  friend bool operator==(const Shape & lhs, const Shape & rhs);
private:
  Shape::Type type_;
protected:
  int id_;
};



#endif /* __SHAPE_H__ */