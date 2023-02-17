#include <gtest/gtest.h>
#include "lin_alg/Vector2D.h"
#include "orbital_simulation/State.h"

TEST(OrbitalSimState, State) {
  auto s = State();
  EXPECT_EQ(s.GetPos().x, 0);
  EXPECT_EQ(s.GetPos().y, 0);
  EXPECT_EQ(s.GetVel().x, 0);
  EXPECT_EQ(s.GetVel().y, 0);
  EXPECT_EQ(s.GetAccel().x, 0);
  EXPECT_EQ(s.GetAccel().y, 0);
}

TEST(OrbitalSimState, StateConst) {
  auto q = v2d(1,2);
  auto qdot = v2d(2,3);
  auto s = State(10, q, qdot);
  EXPECT_EQ(s.GetPos().x ,1);
  EXPECT_EQ(s.GetPos().y ,2);
  EXPECT_EQ(s.GetVel().x, 2);
  EXPECT_EQ(s.GetVel().y, 3);
  EXPECT_EQ(s.GetAccel().x, 0);
  EXPECT_EQ(s.GetAccel().y, 0);
  EXPECT_EQ(s.GetMass(), 10);
}