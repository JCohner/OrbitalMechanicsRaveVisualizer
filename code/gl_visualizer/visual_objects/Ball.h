#ifndef __BALL_H__
#define __BALL_H__

#include "Shape.h" 

class Ball : public Shape {
public:
  Ball (double rad, Vector2D pos) : Shape(Shape::Type::BALL, pos), radius_(rad) {}
  double GetRadius() {return radius_;}
  void Render() override;
private:
  double radius_;
};

#endif