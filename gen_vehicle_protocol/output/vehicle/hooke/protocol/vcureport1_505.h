/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/canbus/proto/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace hooke {

class Vcureport1505 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Vcureport1505();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 10, 'description': '当前转向状态', 'is_signed_var': False, 'len': 3, 'name': 'SteerModeStatus', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int steermodestatus(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'description': '当前刹车灯状态', 'is_signed_var': False, 'len': 1, 'name': 'BrakeLightActual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool brakelightactual(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'description': '纵向加（减）速度（可选）', 'is_signed_var': False, 'len': 12, 'name': 'VehicleAcc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-10|10]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
  double vehicleacc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'description': '车速', 'is_signed_var': True, 'len': 16, 'name': 'VehicleSpeed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-32.768|32.767]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
  double vehiclespeed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'description': 'AEB状态', 'is_signed_var': False, 'len': 1, 'name': 'AebState', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool aebstate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 33, 'is_signed_var': False, 'len': 1, 'name': 'VehicleFrontCrashState', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool vehiclefrontcrashstate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 34, 'is_signed_var': False, 'len': 1, 'name': 'BackCrashState', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool backcrashstate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 36, 'is_signed_var': False, 'len': 2, 'name': 'VehicleModeState', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int vehiclemodestate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 3, 'name': 'DriveModeStatus', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int drivemodestatus(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'description': '故障码', 'is_signed_var': False, 'len': 8, 'name': 'VehicleErrcode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int vehicleerrcode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 51, 'description': '车辆工作状态', 'is_signed_var': False, 'len': 4, 'name': 'CarWorkState', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int carworkstate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 53, 'description': '车辆电源状态', 'is_signed_var': False, 'len': 2, 'name': 'CarPowerState', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int carpowerstate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 54, 'description': '允许自动驾驶行驶指令', 'is_signed_var': False, 'len': 1, 'name': 'AllowSelfDrivingRun', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool allowselfdrivingrun(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'description': '遥控器连接状态', 'is_signed_var': False, 'len': 1, 'name': 'RcuConnectionStatus', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool rcuconnectionstatus(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 57, 'description': '转向灯状态', 'is_signed_var': False, 'len': 2, 'name': 'TurnLightActual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int turnlightactual(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 58, 'description': '灯状态', 'is_signed_var': False, 'len': 1, 'name': 'HeadlightActual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool headlightactual(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 60, 'description': '示宽灯状态', 'is_signed_var': False, 'len': 1, 'name': 'ClearanceLampActural', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool clearancelampactural(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 63, 'description': '急停状态反馈', 'is_signed_var': False, 'len': 3, 'name': 'VcuChassisEStopStaFb', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int vcuchassisestopstafb(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


