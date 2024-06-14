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
namespace pix_hooke {

class Vehiclemodecommand105 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Vehiclemodecommand105();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 2, 'description': '转向模式控制', 'enum': {0: 'STEERMODECTRL_STANDARD_STEER', 1: 'STEERMODECTRL_NON_DIRECTION_STEER', 2: 'STEERMODECTRL_SYNC_DIRECTION_STEER', 3: 'STEERMODECTRL_OPPOSITION_STEER'}, 'is_signed_var': False, 'len': 3, 'name': 'SteerModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_steermodectrl(Vehiclemodecommand_105::SteermodectrlType steermodectrl);

  // config detail: {'bit': 10, 'description': '驾驶模式控制', 'enum': {0: 'DRIVEMODECTRL_THROTTLE_PADDLE_DRIVE', 1: 'DRIVEMODECTRL_SPEED_DRIVE'}, 'is_signed_var': False, 'len': 3, 'name': 'DriveModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_drivemodectrl(Vehiclemodecommand_105::DrivemodectrlType drivemodectrl);

  // config detail: {'bit': 17, 'description': '转向灯控制', 'enum': {0: 'TURNLIGHTCTRL_TURNLAMP_OFF', 1: 'TURNLIGHTCTRL_LEFT_TURNLAMP_ON', 2: 'TURNLIGHTCTRL_RIGHT_TURNLAMP_ON', 3: 'TURNLIGHTCTRL_HAZARD_WARMING_LAMPSTS_ON'}, 'is_signed_var': False, 'len': 2, 'name': 'TurnLightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_turnlightctrl(Vehiclemodecommand_105::TurnlightctrlType turnlightctrl);

  // config detail: {'bit': 18, 'description': '近光灯控制', 'enum': {0: 'HEADLIGHTCTRL_OFF', 1: 'HEADLIGHTCTRL_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'HeadlightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_headlightctrl(Vehiclemodecommand_105::HeadlightctrlType headlightctrl);

  // config detail: {'bit': 20, 'description': '右转语音提示', 'enum': {0: 'TURNRIGHTPROMPTS_OFF', 1: 'TURNRIGHTPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'TurnRightPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_turnrightprompts(Vehiclemodecommand_105::TurnrightpromptsType turnrightprompts);

  // config detail: {'bit': 21, 'description': '左转语音提示', 'enum': {0: 'TURNLEFTPROMPTS_OFF', 1: 'TURNLEFTPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'TurnLeftPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_turnleftprompts(Vehiclemodecommand_105::TurnleftpromptsType turnleftprompts);

  // config detail: {'bit': 22, 'description': '倒挡语音提示', 'enum': {0: 'BACKUPPROMPTS_OFF', 1: 'BACKUPPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'BackUpPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_backupprompts(Vehiclemodecommand_105::BackuppromptsType backupprompts);

  // config detail: {'bit': 23, 'description': '自动驾驶警告语音提示', 'enum': {0: 'AUTOPROMPTS_OFF', 1: 'AUTOPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'AutoPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_autoprompts(Vehiclemodecommand_105::AutopromptsType autoprompts);

  // config detail: {'bit': 24, 'description': 'VIN请求（车架号） （预留）', 'enum': {0: 'VEHICLEVINREQ_VINREQDISABLE', 1: 'VEHICLEVINREQ_VINREQENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'VehicleVinReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_vehiclevinreq(Vehiclemodecommand_105::VehiclevinreqType vehiclevinreq);

  // config detail: {'bit': 33, 'description': '门控制', 'enum': {0: 'VEHICLEDOORCTRL_INVALID', 1: 'VEHICLEDOORCTRL_CLOSED_DOOR', 2: 'VEHICLEDOORCTRL_OPEN_DOOR'}, 'is_signed_var': False, 'len': 2, 'name': 'VehicleDoorCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Vehiclemodecommand105* set_vehicledoorctrl(Vehiclemodecommand_105::VehicledoorctrlType vehicledoorctrl);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum105', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vehiclemodecommand105* set_checksum105(int checksum105);

 private:

  // config detail: {'bit': 2, 'description': '转向模式控制', 'enum': {0: 'STEERMODECTRL_STANDARD_STEER', 1: 'STEERMODECTRL_NON_DIRECTION_STEER', 2: 'STEERMODECTRL_SYNC_DIRECTION_STEER', 3: 'STEERMODECTRL_OPPOSITION_STEER'}, 'is_signed_var': False, 'len': 3, 'name': 'SteerModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_steermodectrl(uint8_t* data, Vehiclemodecommand_105::SteermodectrlType steermodectrl);

  // config detail: {'bit': 10, 'description': '驾驶模式控制', 'enum': {0: 'DRIVEMODECTRL_THROTTLE_PADDLE_DRIVE', 1: 'DRIVEMODECTRL_SPEED_DRIVE'}, 'is_signed_var': False, 'len': 3, 'name': 'DriveModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_drivemodectrl(uint8_t* data, Vehiclemodecommand_105::DrivemodectrlType drivemodectrl);

  // config detail: {'bit': 17, 'description': '转向灯控制', 'enum': {0: 'TURNLIGHTCTRL_TURNLAMP_OFF', 1: 'TURNLIGHTCTRL_LEFT_TURNLAMP_ON', 2: 'TURNLIGHTCTRL_RIGHT_TURNLAMP_ON', 3: 'TURNLIGHTCTRL_HAZARD_WARMING_LAMPSTS_ON'}, 'is_signed_var': False, 'len': 2, 'name': 'TurnLightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_turnlightctrl(uint8_t* data, Vehiclemodecommand_105::TurnlightctrlType turnlightctrl);

  // config detail: {'bit': 18, 'description': '近光灯控制', 'enum': {0: 'HEADLIGHTCTRL_OFF', 1: 'HEADLIGHTCTRL_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'HeadlightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_headlightctrl(uint8_t* data, Vehiclemodecommand_105::HeadlightctrlType headlightctrl);

  // config detail: {'bit': 20, 'description': '右转语音提示', 'enum': {0: 'TURNRIGHTPROMPTS_OFF', 1: 'TURNRIGHTPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'TurnRightPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_turnrightprompts(uint8_t* data, Vehiclemodecommand_105::TurnrightpromptsType turnrightprompts);

  // config detail: {'bit': 21, 'description': '左转语音提示', 'enum': {0: 'TURNLEFTPROMPTS_OFF', 1: 'TURNLEFTPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'TurnLeftPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_turnleftprompts(uint8_t* data, Vehiclemodecommand_105::TurnleftpromptsType turnleftprompts);

  // config detail: {'bit': 22, 'description': '倒挡语音提示', 'enum': {0: 'BACKUPPROMPTS_OFF', 1: 'BACKUPPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'BackUpPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_backupprompts(uint8_t* data, Vehiclemodecommand_105::BackuppromptsType backupprompts);

  // config detail: {'bit': 23, 'description': '自动驾驶警告语音提示', 'enum': {0: 'AUTOPROMPTS_OFF', 1: 'AUTOPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'AutoPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_autoprompts(uint8_t* data, Vehiclemodecommand_105::AutopromptsType autoprompts);

  // config detail: {'bit': 24, 'description': 'VIN请求（车架号） （预留）', 'enum': {0: 'VEHICLEVINREQ_VINREQDISABLE', 1: 'VEHICLEVINREQ_VINREQENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'VehicleVinReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_vehiclevinreq(uint8_t* data, Vehiclemodecommand_105::VehiclevinreqType vehiclevinreq);

  // config detail: {'bit': 33, 'description': '门控制', 'enum': {0: 'VEHICLEDOORCTRL_INVALID', 1: 'VEHICLEDOORCTRL_CLOSED_DOOR', 2: 'VEHICLEDOORCTRL_OPEN_DOOR'}, 'is_signed_var': False, 'len': 2, 'name': 'VehicleDoorCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_vehicledoorctrl(uint8_t* data, Vehiclemodecommand_105::VehicledoorctrlType vehicledoorctrl);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum105', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_checksum105(uint8_t* data, int checksum105);

 private:
  Vehiclemodecommand_105::SteermodectrlType steermodectrl_;
  Vehiclemodecommand_105::DrivemodectrlType drivemodectrl_;
  Vehiclemodecommand_105::TurnlightctrlType turnlightctrl_;
  Vehiclemodecommand_105::HeadlightctrlType headlightctrl_;
  Vehiclemodecommand_105::TurnrightpromptsType turnrightprompts_;
  Vehiclemodecommand_105::TurnleftpromptsType turnleftprompts_;
  Vehiclemodecommand_105::BackuppromptsType backupprompts_;
  Vehiclemodecommand_105::AutopromptsType autoprompts_;
  Vehiclemodecommand_105::VehiclevinreqType vehiclevinreq_;
  Vehiclemodecommand_105::VehicledoorctrlType vehicledoorctrl_;
  int checksum105_;
};

}  // namespace pix_hooke
}  // namespace canbus
}  // namespace apollo


