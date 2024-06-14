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

#include "modules/canbus/vehicle/pix_hooke/protocol/vehiclemodecommand_105.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace pix_hooke {

using ::apollo::drivers::canbus::Byte;

const int32_t Vehiclemodecommand105::ID = 0x105;

// public
Vehiclemodecommand105::Vehiclemodecommand105() { Reset(); }

uint32_t Vehiclemodecommand105::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Vehiclemodecommand105::UpdateData(uint8_t* data) {
  set_p_steermodectrl(data, steermodectrl_);
  set_p_drivemodectrl(data, drivemodectrl_);
  set_p_turnlightctrl(data, turnlightctrl_);
  set_p_headlightctrl(data, headlightctrl_);
  set_p_turnrightprompts(data, turnrightprompts_);
  set_p_turnleftprompts(data, turnleftprompts_);
  set_p_backupprompts(data, backupprompts_);
  set_p_autoprompts(data, autoprompts_);
  set_p_vehiclevinreq(data, vehiclevinreq_);
  set_p_vehicledoorctrl(data, vehicledoorctrl_);
  set_p_checksum105(data, checksum105_);
}

void Vehiclemodecommand105::Reset() {
  // TODO(All) :  you should check this manually
  steermodectrl_ = Vehiclemodecommand_105::STEERMODECTRL_STANDARD_STEER;
  drivemodectrl_ = Vehiclemodecommand_105::DRIVEMODECTRL_THROTTLE_PADDLE_DRIVE;
  turnlightctrl_ = Vehiclemodecommand_105::TURNLIGHTCTRL_TURNLAMP_OFF;
  headlightctrl_ = Vehiclemodecommand_105::HEADLIGHTCTRL_OFF;
  turnrightprompts_ = Vehiclemodecommand_105::TURNRIGHTPROMPTS_OFF;
  turnleftprompts_ = Vehiclemodecommand_105::TURNLEFTPROMPTS_OFF;
  backupprompts_ = Vehiclemodecommand_105::BACKUPPROMPTS_OFF;
  autoprompts_ = Vehiclemodecommand_105::AUTOPROMPTS_OFF;
  vehiclevinreq_ = Vehiclemodecommand_105::VEHICLEVINREQ_VINREQDISABLE;
  vehicledoorctrl_ = Vehiclemodecommand_105::VEHICLEDOORCTRL_INVALID;
  checksum105_ = 0;
}

Vehiclemodecommand105* Vehiclemodecommand105::set_steermodectrl(
    Vehiclemodecommand_105::SteermodectrlType steermodectrl) {
  steermodectrl_ = steermodectrl;
  return this;
 }

// config detail: {'bit': 2, 'description': '转向模式控制', 'enum': {0: 'STEERMODECTRL_STANDARD_STEER', 1: 'STEERMODECTRL_NON_DIRECTION_STEER', 2: 'STEERMODECTRL_SYNC_DIRECTION_STEER', 3: 'STEERMODECTRL_OPPOSITION_STEER'}, 'is_signed_var': False, 'len': 3, 'name': 'SteerModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_steermodectrl(uint8_t* data,
    Vehiclemodecommand_105::SteermodectrlType steermodectrl) {
  int x = steermodectrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 3);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_drivemodectrl(
    Vehiclemodecommand_105::DrivemodectrlType drivemodectrl) {
  drivemodectrl_ = drivemodectrl;
  return this;
 }

// config detail: {'bit': 10, 'description': '驾驶模式控制', 'enum': {0: 'DRIVEMODECTRL_THROTTLE_PADDLE_DRIVE', 1: 'DRIVEMODECTRL_SPEED_DRIVE'}, 'is_signed_var': False, 'len': 3, 'name': 'DriveModeCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_drivemodectrl(uint8_t* data,
    Vehiclemodecommand_105::DrivemodectrlType drivemodectrl) {
  int x = drivemodectrl;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 3);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_turnlightctrl(
    Vehiclemodecommand_105::TurnlightctrlType turnlightctrl) {
  turnlightctrl_ = turnlightctrl;
  return this;
 }

// config detail: {'bit': 17, 'description': '转向灯控制', 'enum': {0: 'TURNLIGHTCTRL_TURNLAMP_OFF', 1: 'TURNLIGHTCTRL_LEFT_TURNLAMP_ON', 2: 'TURNLIGHTCTRL_RIGHT_TURNLAMP_ON', 3: 'TURNLIGHTCTRL_HAZARD_WARMING_LAMPSTS_ON'}, 'is_signed_var': False, 'len': 2, 'name': 'TurnLightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_turnlightctrl(uint8_t* data,
    Vehiclemodecommand_105::TurnlightctrlType turnlightctrl) {
  int x = turnlightctrl;

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 2);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_headlightctrl(
    Vehiclemodecommand_105::HeadlightctrlType headlightctrl) {
  headlightctrl_ = headlightctrl;
  return this;
 }

// config detail: {'bit': 18, 'description': '近光灯控制', 'enum': {0: 'HEADLIGHTCTRL_OFF', 1: 'HEADLIGHTCTRL_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'HeadlightCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_headlightctrl(uint8_t* data,
    Vehiclemodecommand_105::HeadlightctrlType headlightctrl) {
  int x = headlightctrl;

  Byte to_set(data + 2);
  to_set.set_value(x, 2, 1);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_turnrightprompts(
    Vehiclemodecommand_105::TurnrightpromptsType turnrightprompts) {
  turnrightprompts_ = turnrightprompts;
  return this;
 }

// config detail: {'bit': 20, 'description': '右转语音提示', 'enum': {0: 'TURNRIGHTPROMPTS_OFF', 1: 'TURNRIGHTPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'TurnRightPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_turnrightprompts(uint8_t* data,
    Vehiclemodecommand_105::TurnrightpromptsType turnrightprompts) {
  int x = turnrightprompts;

  Byte to_set(data + 2);
  to_set.set_value(x, 4, 1);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_turnleftprompts(
    Vehiclemodecommand_105::TurnleftpromptsType turnleftprompts) {
  turnleftprompts_ = turnleftprompts;
  return this;
 }

// config detail: {'bit': 21, 'description': '左转语音提示', 'enum': {0: 'TURNLEFTPROMPTS_OFF', 1: 'TURNLEFTPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'TurnLeftPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_turnleftprompts(uint8_t* data,
    Vehiclemodecommand_105::TurnleftpromptsType turnleftprompts) {
  int x = turnleftprompts;

  Byte to_set(data + 2);
  to_set.set_value(x, 5, 1);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_backupprompts(
    Vehiclemodecommand_105::BackuppromptsType backupprompts) {
  backupprompts_ = backupprompts;
  return this;
 }

// config detail: {'bit': 22, 'description': '倒挡语音提示', 'enum': {0: 'BACKUPPROMPTS_OFF', 1: 'BACKUPPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'BackUpPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_backupprompts(uint8_t* data,
    Vehiclemodecommand_105::BackuppromptsType backupprompts) {
  int x = backupprompts;

  Byte to_set(data + 2);
  to_set.set_value(x, 6, 1);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_autoprompts(
    Vehiclemodecommand_105::AutopromptsType autoprompts) {
  autoprompts_ = autoprompts;
  return this;
 }

// config detail: {'bit': 23, 'description': '自动驾驶警告语音提示', 'enum': {0: 'AUTOPROMPTS_OFF', 1: 'AUTOPROMPTS_ON'}, 'is_signed_var': False, 'len': 1, 'name': 'AutoPrompts', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_autoprompts(uint8_t* data,
    Vehiclemodecommand_105::AutopromptsType autoprompts) {
  int x = autoprompts;

  Byte to_set(data + 2);
  to_set.set_value(x, 7, 1);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_vehiclevinreq(
    Vehiclemodecommand_105::VehiclevinreqType vehiclevinreq) {
  vehiclevinreq_ = vehiclevinreq;
  return this;
 }

// config detail: {'bit': 24, 'description': 'VIN请求（车架号） （预留）', 'enum': {0: 'VEHICLEVINREQ_VINREQDISABLE', 1: 'VEHICLEVINREQ_VINREQENABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'VehicleVinReq', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_vehiclevinreq(uint8_t* data,
    Vehiclemodecommand_105::VehiclevinreqType vehiclevinreq) {
  int x = vehiclevinreq;

  Byte to_set(data + 3);
  to_set.set_value(x, 0, 1);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_vehicledoorctrl(
    Vehiclemodecommand_105::VehicledoorctrlType vehicledoorctrl) {
  vehicledoorctrl_ = vehicledoorctrl;
  return this;
 }

// config detail: {'bit': 33, 'description': '门控制', 'enum': {0: 'VEHICLEDOORCTRL_INVALID', 1: 'VEHICLEDOORCTRL_CLOSED_DOOR', 2: 'VEHICLEDOORCTRL_OPEN_DOOR'}, 'is_signed_var': False, 'len': 2, 'name': 'VehicleDoorCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Vehiclemodecommand105::set_p_vehicledoorctrl(uint8_t* data,
    Vehiclemodecommand_105::VehicledoorctrlType vehicledoorctrl) {
  int x = vehicledoorctrl;

  Byte to_set(data + 4);
  to_set.set_value(x, 0, 2);
}


Vehiclemodecommand105* Vehiclemodecommand105::set_checksum105(
    int checksum105) {
  checksum105_ = checksum105;
  return this;
 }

// config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum105', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Vehiclemodecommand105::set_p_checksum105(uint8_t* data,
    int checksum105) {
  checksum105 = ProtocolData::BoundedValue(0, 255, checksum105);
  int x = checksum105;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}

}  // namespace pix_hooke
}  // namespace canbus
}  // namespace apollo
