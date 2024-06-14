load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hooke_vehicle_factory",
    srcs = [
        "hooke_vehicle_factory.cc",
    ],
    hdrs = [
        "hooke_vehicle_factory.h",
    ],
    deps = [
        ":hooke_controller",
        ":hooke_message_manager",
        "//modules/canbus/vehicle:abstract_vehicle_factory",
    ],
)

cc_library(
    name = "hooke_message_manager",
    srcs = [
        "hooke_message_manager.cc",
    ],
    hdrs = [
        "hooke_message_manager.h",
    ],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle/hooke/protocol:canbus_hooke_protocol",
    ],
)

cc_library(
    name = "hooke_controller",
    srcs = [
        "hooke_controller.cc",
    ],
    hdrs = [
        "hooke_controller.h",
    ],
    deps = [
        ":hooke_message_manager",
        "//modules/drivers/canbus/can_comm:can_sender",
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle:vehicle_controller_base",
        "//modules/canbus/vehicle/hooke/protocol:canbus_hooke_protocol",
    ],
)

cpplint()
