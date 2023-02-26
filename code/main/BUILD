cc_binary(
  name = "main",
  srcs = ["main.cpp"],
  deps = [
    ":mechanics_vis",
  ],
)

cc_library(
  name = "mechanics_vis",
  srcs = ["MechanicsVisualizer.cpp",],
  hdrs = ["MechanicsVisualizer.h",],
  deps = [
    "//gl_visualizer:gl_visualizer",
    "//orbital_simulation:orbital_engine",
  ]
)