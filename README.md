# This repository plays with

* [bazel package visibilty](https://bazel.build/concepts/visibility) to support architecural guidance during local build (e.g., [hexagonal architecture](https://en.wikipedia.org/wiki/Hexagonal_architecture_(software)) or clean architecure).
* make use of C++ template pre-instantiation to save build time and force well-organized implementation of templates.

# Visualization of dependency
Use [bazel query](https://bazel.build/query/quickstart) and copy output of to e.g. https://dreampuf.github.io/GraphvizOnline/

    ${BAZEL} query --notool_deps --noimplicit_deps "deps(//core_main:core_main)" --output graph

If you want to restrict the dependency graph to BUILD files, only:

    ${BAZEL} query --notool_deps --noimplicit_deps "kind(cc_library, deps(//core_main:core_main))" --output graph

Which libraries are used by the test target:

    ${BAZEL} query --notool_deps --noimplicit_deps "kind(cc_library, deps(//core_mapper:core_mapper_test)) union kind(cc_test, deps(//core_mapper:core_mapper_test))" --output graph --keep_going