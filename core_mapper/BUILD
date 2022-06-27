cc_library(
    name = "core_mapper_lib",
    srcs = [
        "CoreMapper.cpp",
    ],
    hdrs = [
        "CoreMapper.h",
    ],
    visibility = [
        "//core_main:__pkg__",
    ],
    deps = [
        "//boardnet:boardnet_lib",
        "//core_mapper_iface:core_mapper_iface_lib",
        "//core_ros",
    ],
)

cc_test(
    name = "core_mapper_test",
    size = "small",
    srcs = [
        "CoreMapperTest.cpp",
    ],
    deps = [
        ":core_mapper_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
