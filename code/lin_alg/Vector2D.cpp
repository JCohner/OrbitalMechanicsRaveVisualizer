#include "Vector2D.h"


double Vector2D::angle(){
  double ang = atan2(this->y, this->x);
  return ang;
}