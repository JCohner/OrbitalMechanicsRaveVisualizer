# visual object base class
cc_library(
  name = "visual_object",
  srcs = ["Shape.cpp"],
  hdrs = ["Shape.h"],
  deps = [
    "//lin_alg:lin_alg",
  ],
)

cc_library(
  name = "ball",
  srcs = ["Ball.cpp"],
  hdrs = ["Ball.h"],
  deps = [
    ":visual_object",
  ]
)

# publicly visible lib
cc_library(
  name = "visual_objects",
  deps = [
    ":ball",
  ],
  visibility = ["//visibility:public"],
)