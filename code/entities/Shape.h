#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "lin_alg/Vector2D.h"

#define PI 3.14159265f // unfortunately a good place for this

class Shape {
public:
  enum Type {NONE = 0, BALL = 1 };
  Shape (Shape::Type type, Vector2D pos) : type_(type), centroid_(pos ) {}
  /* Accessors */
  Shape::Type GetType() {return type_;}
  Vector2D GetCentroid() {return centroid_;}
  virtual void Render() = 0;

private:
  Shape::Type type_;
protected:
  Vector2D centroid_;
};


#endif /* __SHAPE_H__ */