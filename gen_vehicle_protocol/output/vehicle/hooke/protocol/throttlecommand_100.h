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

class Throttlecommand100 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Throttlecommand100();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 0, 'description': '加速使能', 'is_signed_var': False, 'len': 1, 'name': 'DriveEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Throttlecommand100* set_driveenctrl(bool driveenctrl);

  // config detail: {'bit': 15, 'description': '车辆目标纵向加速度（可选）', 'is_signed_var': False, 'len': 10, 'name': 'DriveAcc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|10]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
  Throttlecommand100* set_driveacc(double driveacc);

  // config detail: {'bit': 31, 'description': '虚拟目标加速踏板位置', 'is_signed_var': False, 'len': 16, 'name': 'DriveThrottlePedalTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  Throttlecommand100* set_drivethrottlepedaltarget(double drivethrottlepedaltarget);

  // config detail: {'bit': 47, 'description': '驾驶速度', 'is_signed_var': False, 'len': 10, 'name': 'DriveSpeedTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|40.95]', 'physical_unit': ' m/s', 'precision': 0.01, 'type': 'double'}
  Throttlecommand100* set_drivespeedtarget(double drivespeedtarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum100', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Throttlecommand100* set_checksum100(int checksum100);

 private:

  // config detail: {'bit': 0, 'description': '加速使能', 'is_signed_var': False, 'len': 1, 'name': 'DriveEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_driveenctrl(uint8_t* data, bool driveenctrl);

  // config detail: {'bit': 15, 'description': '车辆目标纵向加速度（可选）', 'is_signed_var': False, 'len': 10, 'name': 'DriveAcc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|10]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
  void set_p_driveacc(uint8_t* data, double driveacc);

  // config detail: {'bit': 31, 'description': '虚拟目标加速踏板位置', 'is_signed_var': False, 'len': 16, 'name': 'DriveThrottlePedalTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  void set_p_drivethrottlepedaltarget(uint8_t* data, double drivethrottlepedaltarget);

  // config detail: {'bit': 47, 'description': '驾驶速度', 'is_signed_var': False, 'len': 10, 'name': 'DriveSpeedTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|40.95]', 'physical_unit': ' m/s', 'precision': 0.01, 'type': 'double'}
  void set_p_drivespeedtarget(uint8_t* data, double drivespeedtarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum100', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_checksum100(uint8_t* data, int checksum100);

 private:
  bool driveenctrl_;
  double driveacc_;
  double drivethrottlepedaltarget_;
  double drivespeedtarget_;
  int checksum100_;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


