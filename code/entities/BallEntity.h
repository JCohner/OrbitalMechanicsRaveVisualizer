#ifndef __BALL_H__
#define __BALL_H__

#include "EntityObject.h" 

class Ball : public Entity {
public:
  Ball (double rad, v2d pos) : Entity(Entity::Type::BALL, pos), radius_(rad) {}
  double GetRadius() {return radius_;}
  void Render() override;
private:
  double radius_;
};

#endif