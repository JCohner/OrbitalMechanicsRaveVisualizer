#include <gtest/gtest.h>
#include "shapes/Circle.h"
#include "shapes/Shape.h"

TEST(Shape, Equality) {
  auto c = Circle(5, 10, {2,3});
  auto d = c;
  auto e = Circle(1, 10, {2,3});

  auto f = Circle(5, 1, {2,3});

  EXPECT_EQ(c,d);
  EXPECT_NE(c, e);
  EXPECT_NE(c, f);
}