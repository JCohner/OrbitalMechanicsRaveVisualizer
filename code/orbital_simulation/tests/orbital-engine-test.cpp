#include <gtest/gtest.h>
#include <memory>
#include "lin_alg/Vector2D.h"
#include "orbital_simulation/State.h"
#include "orbital_simulation/Engine.h"
#include "entities/EntityObject.h"

TEST(OrbitalSimEngine, Engine) {
  auto s = Engine();
  auto ball_pos = v2d(250, 250);
  auto ball = std::make_shared<Entity>();
  s.EnqueueEntity(ball);
  s.StartWork();
}
