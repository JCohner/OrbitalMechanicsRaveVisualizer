SHELL:=/bin/bash
VERSION=0x03
DEBUG ?= 0

.PHONY: engine-test
engine-test:
	@bazel build //orbital_simulation/tests:orbital_engine_test --verbose_failures

.PHONY: run-engine-test
run-engine-test:
	@./bazel-bin/orbital_simulation/tests/orbital_engine_test


.PHONY: draw-test
draw-test:
	@bazel build //gl_visualizer:draw --verbose_failures

.PHONY: run-draw-test
run-draw-test:
	@./bazel-bin/gl_visualizer/draw

.PHONY: main
main:
	@bazel build //main:main --verbose_failures

.PHONY: run
run:
	@./bazel-bin/main/main || true

.PHONY: clean
clean:
	@bazel clean

.PHONY: visualize_deps
visualize_deps:
	@bazel query --noimplicit_deps 'deps(//main:mechanics_vis)' --output graph > simplified_graph.in
	@dot -Tpng < simplified_graph.in> graph.png
	@eog graph.png || true
	@rm simplified_graph.in
	@mv graph.png ../docs/