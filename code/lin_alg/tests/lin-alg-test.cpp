#include <gtest/gtest.h>
#include "lin_alg/Vector2D.h"

TEST(LingAlg, Vector2D_Length) {
  auto vec1 = Vector2D(3,4);
  EXPECT_EQ(vec1.length(), 5);
  // todo check for expected output when yes or no file
}

TEST(LingAlg, Vector2D_Distance) {
  auto vec1 = Vector2D(4,0);
  auto vec2 = Vector2D(4,6);

  EXPECT_EQ(vec1.distance(vec2), 6);
  // todo check for expected output when yes or no file
}

TEST(LingAlg, Vector2D_Arithmetic) {
  auto vec1 = Vector2D(1,2);
  auto vec2 = Vector2D(3,4);

  auto vec3 = vec2 - vec1;

  EXPECT_EQ(vec3, Vector2D(2,2));
  // todo check for expected output when yes or no file
}