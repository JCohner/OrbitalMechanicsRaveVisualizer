#ifndef __BALL_H__
#define __BALL_H__

#include "Shape.h" 

class Circle : public Shape {
public:
  Circle (double rad, v2d pos) : Shape(Shape::Type::BALL, pos), radius_(rad) {}
  double GetRadius() {return radius_;}
  void Render() override;
private:
  double radius_;
};

#endif