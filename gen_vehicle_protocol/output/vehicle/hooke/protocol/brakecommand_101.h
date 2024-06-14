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

class Brakecommand101 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Brakecommand101();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 0, 'description': '制动使能', 'is_signed_var': False, 'len': 1, 'name': 'BrakeEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Brakecommand101* set_brakeenctrl(bool brakeenctrl);

  // config detail: {'bit': 1, 'description': 'AEB使能', 'is_signed_var': False, 'len': 1, 'name': 'AebEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Brakecommand101* set_aebenctrl(bool aebenctrl);

  // config detail: {'bit': 15, 'description': '目标减速度（可选）', 'is_signed_var': False, 'len': 10, 'name': 'BrakeDec', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|10]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
  Brakecommand101* set_brakedec(double brakedec);

  // config detail: {'bit': 31, 'description': '虚拟目标制动踏板位置', 'is_signed_var': False, 'len': 16, 'name': 'BrakePedalTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  Brakecommand101* set_brakepedaltarget(double brakepedaltarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum101', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Brakecommand101* set_checksum101(int checksum101);

 private:

  // config detail: {'bit': 0, 'description': '制动使能', 'is_signed_var': False, 'len': 1, 'name': 'BrakeEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_brakeenctrl(uint8_t* data, bool brakeenctrl);

  // config detail: {'bit': 1, 'description': 'AEB使能', 'is_signed_var': False, 'len': 1, 'name': 'AebEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_aebenctrl(uint8_t* data, bool aebenctrl);

  // config detail: {'bit': 15, 'description': '目标减速度（可选）', 'is_signed_var': False, 'len': 10, 'name': 'BrakeDec', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|10]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
  void set_p_brakedec(uint8_t* data, double brakedec);

  // config detail: {'bit': 31, 'description': '虚拟目标制动踏板位置', 'is_signed_var': False, 'len': 16, 'name': 'BrakePedalTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  void set_p_brakepedaltarget(uint8_t* data, double brakepedaltarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum101', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_checksum101(uint8_t* data, int checksum101);

 private:
  bool brakeenctrl_;
  bool aebenctrl_;
  double brakedec_;
  double brakepedaltarget_;
  int checksum101_;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


