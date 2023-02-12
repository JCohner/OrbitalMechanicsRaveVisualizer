# visual object base class
cc_library(
  name = "entity_object",
  srcs = ["EntityObject.cpp"],
  hdrs = ["EntityObject.h"],
  deps = [
    "//lin_alg:lin_alg",
  ],
  visibility = [
    "//orbital_simulation/tests:__pkg__",
  ]
)

cc_library(
  name = "ball_entity",
  srcs = ["BallEntity.cpp"],
  hdrs = ["BallEntity.h"],
  deps = [
    ":entity_object",
  ],
  visibility = [
    "//orbital_simulation/tests:__pkg__",
  ]
)

# publicly visible lib
cc_library(
  name = "entity_objects",
  deps = [
    ":ball_entity",
  ],
  visibility = ["//visibility:public"],
)

cc_library(
  name = "entity_manager",
  # srcs = ["EntityManager.cpp"],
  hdrs = ["EntityManager.h"],
  visibility = [
    "//orbital_simulation:__pkg__"
  ],
  deps = [
    ":entity_object"
  ]
)