SHELL:=/bin/bash
VERSION=0x03
DEBUG ?= 0

.PHONY: engine-test
engine-test:
	@bazel build //orbital_simulation/tests:orbital_engine_test --verbose_failures

.PHONY: run-engine-test
run-engine-test:
	@./bazel-bin/orbital_simulation/tests/orbital_engine_test

.PHONY: clean
clean:
	@bazel clean
