#ifndef __Entity_H__
#define __Entity_H__

#include "lin_alg/Vector2D.h"

#define PI 3.14159265f // unfortunately a good place for this

class Entity {
public:
  enum Type {NONE = 0, BALL = 1 };
  Entity () : type_(Entity::Type::NONE), centroid_(v2d(0,0)) {}
  Entity (Entity::Type type, v2d pos) : type_(type), centroid_(pos ) {}
  /* Accessors */
  Entity::Type GetType() {return type_;}
  v2d GetCentroid() {return centroid_;}
  virtual void Render() {};

private:
  Entity::Type type_;
protected:
  v2d centroid_;
};


#endif /* __Entity_H__ */