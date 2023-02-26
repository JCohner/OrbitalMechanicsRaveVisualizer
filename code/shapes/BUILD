# visual object base class
cc_library(
  name = "shape",
  srcs = ["Shape.cpp"],
  hdrs = ["Shape.h"],
  deps = [
    "//orbital_simulation:orbital_state",
  ],
  linkopts = ["-lglut",
            "-lGLU",
            "-lGL",
            "-lGLEW",
            "-lpthread"],
  visibility = [
    "//orbital_simulation/tests:__pkg__",
  ]
)

cc_library(
  name = "circle-shape",
  srcs = ["Circle.cpp"],
  hdrs = ["Circle.h"],
  deps = [
    ":shape",
  ],
  visibility = [
  ]
)

# publicly visible lib
cc_library(
  name = "shapes",
  deps = [
    ":circle-shape",
  ],
  visibility = [
    "//gl_visualizer:__pkg__",
    "//shapes/tests:__pkg__",
  ], # just for tests/draw
)