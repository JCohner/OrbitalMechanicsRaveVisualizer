#include "Shape.h"

bool operator==(const Shape & lhs, const Shape & rhs){
  return (lhs.id_ == rhs.id_);
}