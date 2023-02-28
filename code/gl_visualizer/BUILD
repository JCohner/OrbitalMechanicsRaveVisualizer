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
    "//shapes:shapes",  
    ],
  visibility = [
    "//main:__pkg__",
  ]
)

cc_binary(
  name = "draw",
  srcs = ["tests/test_draw.cpp"],
  deps = [
    ":gl_visualizer",
    "//shapes:shapes",
  ],
)