cc_library(
  name = "vector_2d",
  srcs = ["Vector2D.cpp"],
  hdrs = ["Vector2D.h"],
)

cc_library(
  name = "lin_alg",
  deps = [
    ":vector_2d",
  ],
  visibility = [
    "//gl_visualizer:__subpackages__",
    "//lin_alg/tests:__pkg__",
  ],
)