#include "Vector2D.h"

double v2d::angle(){
  double ang = atan2(this->y, this->x);
  return ang;
}
double v2d::length(){
  double len = sqrt(pow(this->x, 2) + pow(this->y, 2));
  return len;
}

v2d v2d::unit_vec_to(const v2d & vec){
  auto dist = this->distance(vec);
  auto vec_between = (*this - vec);
  return 1.0/dist * vec_between;
}

double v2d::distance(const v2d & vec){
  //taking this to be the distance between the endpoints of the vectors
  double delta_x = this->x - vec.x;
  double delta_y = this->y - vec.y;
  double dist = sqrt(pow(delta_x, 2) + pow(delta_y,2));
  return dist;
}

v2d operator+(v2d lhs, const v2d & rhs){
  v2d output;
  output.x = lhs.x + rhs.x;
  output.y = lhs.y + rhs.y;
  return output;
}

v2d& operator+=(v2d& lhs, const v2d & rhs){
  lhs = lhs + rhs;
  return lhs;
}

v2d operator-(v2d lhs, const v2d & rhs){
  v2d output;
  output.x = lhs.x - rhs.x;
  output.y = lhs.y - rhs.y;
  return output;
}

v2d& operator-=(v2d& lhs, const v2d & rhs){
  lhs = lhs - rhs;
  return lhs;
}

v2d operator*(double lhs, const v2d & rhs){
  v2d vec;
  vec.x = rhs.x * lhs;
  vec.y = rhs.y * lhs;
  return vec;
}

// double comparison things
bool operator==(const v2d & lhs, const v2d & rhs){
  return ((abs(lhs.x - rhs.x) < 1e-10) && ((abs(lhs.y - rhs.y) < 1e-10)));
}

//outstream op overload for vectors
std::ostream & operator<<(std::ostream & os, const v2d & v)
{
  os << "x: " << v.x << "\t";
  os << "y: " << v.y << "\n";
  return os;
} 
