#include "Vector2D.h"


double Vector2D::angle(){
  double ang = atan2(this->y, this->x);
  return ang;
}
double Vector2D::length(){
  double len = sqrt(pow(this->x, 2) + pow(this->y, 2));
  return len;
}

double Vector2D::distance(const Vector2D & vec){
  //taking this to be the distance between the endpoints of the vectors
  double delta_x = this->x - vec.x;
  double delta_y = this->y - vec.y;
  double dist = sqrt(pow(delta_x, 2) + pow(delta_y,2));
  return dist;
}

Vector2D operator+(Vector2D lhs, const Vector2D & rhs){
  Vector2D output;
  output.x = lhs.x + rhs.x;
  output.y = lhs.y + rhs.y;
  return output;
}

Vector2D& operator+=(Vector2D& lhs, const Vector2D & rhs){
  lhs = lhs + rhs;
  return lhs;
}

Vector2D operator-(Vector2D lhs, const Vector2D & rhs){
  Vector2D output;
  output.x = lhs.x - rhs.x;
  output.y = lhs.y - rhs.y;
  return output;
}

Vector2D& operator-=(Vector2D& lhs, const Vector2D & rhs){
  lhs = lhs - rhs;
  return lhs;
}

Vector2D operator*(double lhs, const Vector2D & rhs){
  Vector2D vec;
  vec.x = rhs.x * lhs;
  vec.y = rhs.y * lhs;
  return vec;
}

bool operator==(const Vector2D & lhs, const Vector2D & rhs){
  return ((lhs.x - rhs.x == 0) && (lhs.y - rhs.y == 0));
}
