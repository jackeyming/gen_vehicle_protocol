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

class Steeringcommand102 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Steeringcommand102();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 0, 'description': '转向使能', 'is_signed_var': False, 'len': 1, 'name': 'SteerEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Steeringcommand102* set_steerenctrl(bool steerenctrl);

  // config detail: {'bit': 15, 'description': '目标前轮转速 （方向盘转速）', 'is_signed_var': False, 'len': 8, 'name': 'SteerAngleSpeed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
  Steeringcommand102* set_steeranglespeed(int steeranglespeed);

  // config detail: {'bit': 31, 'description': '目标前轮转向角（方向盘转角）', 'is_signed_var': False, 'len': 16, 'name': 'SteerAngleTarget', 'offset': -500.0, 'order': 'motorola', 'physical_range': '[-465|465]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
  Steeringcommand102* set_steerangletarget(int steerangletarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum102', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Steeringcommand102* set_checksum102(int checksum102);

 private:

  // config detail: {'bit': 0, 'description': '转向使能', 'is_signed_var': False, 'len': 1, 'name': 'SteerEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_steerenctrl(uint8_t* data, bool steerenctrl);

  // config detail: {'bit': 15, 'description': '目标前轮转速 （方向盘转速）', 'is_signed_var': False, 'len': 8, 'name': 'SteerAngleSpeed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
  void set_p_steeranglespeed(uint8_t* data, int steeranglespeed);

  // config detail: {'bit': 31, 'description': '目标前轮转向角（方向盘转角）', 'is_signed_var': False, 'len': 16, 'name': 'SteerAngleTarget', 'offset': -500.0, 'order': 'motorola', 'physical_range': '[-465|465]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
  void set_p_steerangletarget(uint8_t* data, int steerangletarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum102', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_checksum102(uint8_t* data, int checksum102);

 private:
  bool steerenctrl_;
  int steeranglespeed_;
  int steerangletarget_;
  int checksum102_;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


