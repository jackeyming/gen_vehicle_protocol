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

class Vehiclemodecommand105 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Vehiclemodecommand105();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 2, 'description': '转向模式控制', 'is_signed_var': False, 'len': 3, 'name': 'SteerModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vehiclemodecommand105* set_steermodectrl(int steermodectrl);

  // config detail: {'bit': 10, 'description': '驾驶模式控制', 'is_signed_var': False, 'len': 3, 'name': 'DriveModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vehiclemodecommand105* set_drivemodectrl(int drivemodectrl);

  // config detail: {'bit': 17, 'description': '转向灯控制', 'is_signed_var': False, 'len': 2, 'name': 'TurnLightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vehiclemodecommand105* set_turnlightctrl(int turnlightctrl);

  // config detail: {'bit': 18, 'description': '近光灯控制', 'is_signed_var': False, 'len': 1, 'name': 'HeadlightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vehiclemodecommand105* set_headlightctrl(bool headlightctrl);

  // config detail: {'bit': 20, 'description': '右转语音提示', 'is_signed_var': False, 'len': 1, 'name': 'TurnRightPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vehiclemodecommand105* set_turnrightprompts(bool turnrightprompts);

  // config detail: {'bit': 21, 'description': '左转语音提示', 'is_signed_var': False, 'len': 1, 'name': 'TurnLeftPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vehiclemodecommand105* set_turnleftprompts(bool turnleftprompts);

  // config detail: {'bit': 22, 'description': '倒挡语音提示', 'is_signed_var': False, 'len': 1, 'name': 'BackUpPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vehiclemodecommand105* set_backupprompts(bool backupprompts);

  // config detail: {'bit': 23, 'description': '自动驾驶警告语音提示', 'is_signed_var': False, 'len': 1, 'name': 'AutoPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vehiclemodecommand105* set_autoprompts(bool autoprompts);

  // config detail: {'bit': 24, 'description': 'VIN请求（车架号） （预留）', 'is_signed_var': False, 'len': 1, 'name': 'VehicleVinReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vehiclemodecommand105* set_vehiclevinreq(bool vehiclevinreq);

  // config detail: {'bit': 33, 'description': '门控制', 'is_signed_var': False, 'len': 2, 'name': 'VehicleDoorCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vehiclemodecommand105* set_vehicledoorctrl(int vehicledoorctrl);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum105', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vehiclemodecommand105* set_checksum105(int checksum105);

 private:

  // config detail: {'bit': 2, 'description': '转向模式控制', 'is_signed_var': False, 'len': 3, 'name': 'SteerModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_steermodectrl(uint8_t* data, int steermodectrl);

  // config detail: {'bit': 10, 'description': '驾驶模式控制', 'is_signed_var': False, 'len': 3, 'name': 'DriveModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_drivemodectrl(uint8_t* data, int drivemodectrl);

  // config detail: {'bit': 17, 'description': '转向灯控制', 'is_signed_var': False, 'len': 2, 'name': 'TurnLightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_turnlightctrl(uint8_t* data, int turnlightctrl);

  // config detail: {'bit': 18, 'description': '近光灯控制', 'is_signed_var': False, 'len': 1, 'name': 'HeadlightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_headlightctrl(uint8_t* data, bool headlightctrl);

  // config detail: {'bit': 20, 'description': '右转语音提示', 'is_signed_var': False, 'len': 1, 'name': 'TurnRightPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_turnrightprompts(uint8_t* data, bool turnrightprompts);

  // config detail: {'bit': 21, 'description': '左转语音提示', 'is_signed_var': False, 'len': 1, 'name': 'TurnLeftPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_turnleftprompts(uint8_t* data, bool turnleftprompts);

  // config detail: {'bit': 22, 'description': '倒挡语音提示', 'is_signed_var': False, 'len': 1, 'name': 'BackUpPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_backupprompts(uint8_t* data, bool backupprompts);

  // config detail: {'bit': 23, 'description': '自动驾驶警告语音提示', 'is_signed_var': False, 'len': 1, 'name': 'AutoPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_autoprompts(uint8_t* data, bool autoprompts);

  // config detail: {'bit': 24, 'description': 'VIN请求（车架号） （预留）', 'is_signed_var': False, 'len': 1, 'name': 'VehicleVinReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_vehiclevinreq(uint8_t* data, bool vehiclevinreq);

  // config detail: {'bit': 33, 'description': '门控制', 'is_signed_var': False, 'len': 2, 'name': 'VehicleDoorCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_vehicledoorctrl(uint8_t* data, int vehicledoorctrl);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum105', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_checksum105(uint8_t* data, int checksum105);

 private:
  int steermodectrl_;
  int drivemodectrl_;
  int turnlightctrl_;
  bool headlightctrl_;
  bool turnrightprompts_;
  bool turnleftprompts_;
  bool backupprompts_;
  bool autoprompts_;
  bool vehiclevinreq_;
  int vehicledoorctrl_;
  int checksum105_;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


