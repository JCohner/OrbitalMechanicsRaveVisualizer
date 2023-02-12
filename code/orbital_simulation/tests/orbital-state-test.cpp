#include <gtest/gtest.h>
#include "lin_alg/Vector2D.h"
#include "orbital_simulation/State.h"

TEST(OrbitalSimState, State) {
  auto s = State();
  EXPECT_EQ(s.q().x, 0);
  EXPECT_EQ(s.q().y, 0);
  EXPECT_EQ(s.qdot().x, 0);
  EXPECT_EQ(s.qdot().y, 0);
  EXPECT_EQ(s.qddot().x, 0);
  EXPECT_EQ(s.qddot().y, 0);
}

TEST(OrbitalSimState, StateConst) {
  auto q = v2d(1,2);
  auto qdot = v2d(2,3);
  auto s = State(q, qdot);
  EXPECT_EQ(s.q().x ,1);
  EXPECT_EQ(s.q().y ,2);
  EXPECT_EQ(s.qdot().x, 2);
  EXPECT_EQ(s.qdot().y, 3);
  EXPECT_EQ(s.qddot().x, 0);
  EXPECT_EQ(s.qddot().y, 0);
}