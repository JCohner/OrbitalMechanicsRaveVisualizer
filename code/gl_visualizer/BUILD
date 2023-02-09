cc_library(
  name = "gl_visualizer",
  srcs = ["Canvas.cpp"],
  hdrs = ["Canvas.h"],
  linkopts = ["-lglut",
              "-lGLU",
              "-lGL",
              "-lGLEW"
  ],
  deps = [
    "//lin_alg:vector_2d"
  ],
)

cc_binary(
  name = "draw",
  srcs = ["tests/test_draw.cpp"],
  deps = [":gl_visualizer"],
)