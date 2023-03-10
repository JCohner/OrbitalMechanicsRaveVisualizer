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

TEST(OrbitalSimState, SetStateAccel) {
  auto q = State();
  q.SetAccel(ACCEL_MODE::ABS, {2,2});
  EXPECT_EQ(q.GetAccel(), v2d(2,2));
}

TEST(OrbitalSimState, UpdateState) {
  auto q = State();
  q.SetAccel(ACCEL_MODE::ABS, {2,2});
  // q's position is {0,0}, an accel of {1,1} will act on it for default: 0.1 s
  q.UpdateState();

  EXPECT_EQ(q.GetVel(), v2d(.2,.2));
  EXPECT_EQ(q.GetPos(), v2d(.03,.03));
}