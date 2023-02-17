cc_library(
  name = "orbital_state",
  srcs = ["State.cpp"],
  hdrs = ["State.h"],
  deps = [
    "//lin_alg:lin_alg"
  ],
  visibility = [
    "//visibility:public"
  ] 
)

cc_library(
  name = "orbital_engine",
  srcs = ["Engine.cpp"],
  hdrs = ["Engine.h"],
  visibility = [
    "//orbital_simulation/tests:__pkg__",
  ],
  deps = [
    ":orbital_state"
  ]
)