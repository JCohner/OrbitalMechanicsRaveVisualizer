cc_library(
  name = "gl_visualizer",
  srcs = ["Canvas.cpp"],
  hdrs = ["Canvas.h"],
  linkopts = ["-lglut",
              "-lGLU",
              "-lGL",
              "-lGLEW",
              "-lpthread"
  ],
  deps = [
    "//lin_alg:lin_alg",
    "//gl_visualizer/visual_objects:visual_objects",
  ],
)

cc_binary(
  name = "draw",
  srcs = ["tests/test_draw.cpp"],
  deps = [
    ":gl_visualizer",
    "//gl_visualizer/visual_objects:visual_objects",
  ],
)