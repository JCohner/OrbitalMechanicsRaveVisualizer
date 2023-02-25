# visual object base class
cc_library(
  name = "shape",
  srcs = ["Shape.cpp"],
  hdrs = ["Shape.h"],
  deps = [
    "//lin_alg:lin_alg",
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
    "//orbital_simulation/tests:__pkg__",
  ]
)

# publicly visible lib
cc_library(
  name = "shapes",
  deps = [
    ":circle-shape",
  ],
  visibility = ["//visibility:public"],
)