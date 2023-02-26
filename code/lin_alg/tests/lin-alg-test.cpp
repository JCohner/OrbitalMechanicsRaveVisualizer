#include <gtest/gtest.h>
#include "lin_alg/Vector2D.h"

TEST(LingAlg, v2d_Length) {
  auto vec1 = v2d(3,4);
  EXPECT_EQ(vec1.length(), 5);
  // todo check for expected output when yes or no file
}

TEST(LingAlg, v2d_Distance) {
  auto vec1 = v2d(4,0);
  auto vec2 = v2d(4,6);

  EXPECT_EQ(vec1.distance(vec2), 6);
  // todo check for expected output when yes or no file
}

TEST(LingAlg, v2d_Arithmetic) {
  auto vec1 = v2d(1,2);
  auto vec2 = v2d(3,4);

  auto vec3 = vec2 - vec1;

  EXPECT_EQ(vec3, v2d(2,2));
  // todo check for expected output when yes or no file
}

TEST(LingAlg, v2d_unit_vec) {
  auto vec1 = v2d(0,0);
  auto vec2 = v2d(3,4);

  auto vec3 = vec2.unit_vec_to(vec1);

  EXPECT_EQ(vec3, v2d(0.6,0.8));
  // todo check for expected output when yes or no file
}