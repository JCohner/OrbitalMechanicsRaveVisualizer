#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "lin_alg/Vector2D.h"

#define PI 3.14159265f // unfortunately a good place for this

static int global_count = 0;

class Shape {
public:
  enum Type {NONE = 0, BALL = 1 };
  Shape () : type_(Shape::Type::NONE), centroid_(v2d(0,0)) {
    id_ = global_count++;
  }
  Shape (Shape::Type type, v2d pos) : type_(type), centroid_(pos ) {}
  /* Accessors */
  Shape::Type GetType() {return type_;}
  v2d GetCentroid() {return centroid_;}
  virtual void Render() {};
  friend bool operator==(const Shape & lhs, const Shape & rhs);
private:
  Shape::Type type_;
protected:
  v2d centroid_;
  int id_;
};



#endif /* __SHAPE_H__ */