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
    "//entities:entity_objects",
    "//entities:entity_manager",
  ],
  visibility = [
    "//orbital_simulation/tests:__pkg__",
  ]
)

cc_binary(
  name = "draw",
  srcs = ["tests/test_draw.cpp"],
  deps = [
    ":gl_visualizer",
    "//entities:entity_objects",
  ],
)