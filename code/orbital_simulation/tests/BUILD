cc_test(
  name = "orbital_state_test",
  srcs = ["orbital-state-test.cpp"],
  size = "small",
  deps = [
    "@gtest//:gtest_main",
    "@gtest//:gtest",
    "//lin_alg:lin_alg",  
    "//orbital_simulation:orbital_state",
  ],
)

cc_binary(
  name = "orbital_engine_test",
  srcs = ["orbital-engine-test.cpp"],
  deps = [
    "//lin_alg:lin_alg",
    "//orbital_simulation:orbital_state",
    "//orbital_simulation:orbital_engine",
    "//entities:entity_object",
    "//entities:ball_entity",
  ],
  linkopts = [
    "-lpthread",
  ],
)