#ifndef __BALL_H__
#define __BALL_H__

#include "Shape.h" 

class Circle : public Shape {
public:
  Circle (double rad, double mass, v2d pos) : Shape(Shape::Type::BALL, mass, pos), radius_(rad) {}
  Circle (double rad, State state) : Shape(Shape::Type::BALL, state), radius_(rad) {}
  double GetRadius() {return radius_;}
  void Render() override;
private:
  double radius_;
};

#endif