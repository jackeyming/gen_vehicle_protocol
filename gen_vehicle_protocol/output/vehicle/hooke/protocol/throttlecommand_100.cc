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

#include "modules/canbus/vehicle/hooke/protocol/throttlecommand_100.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

const int32_t Throttlecommand100::ID = 0x100;

// public
Throttlecommand100::Throttlecommand100() { Reset(); }

uint32_t Throttlecommand100::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Throttlecommand100::UpdateData(uint8_t* data) {
  set_p_driveenctrl(data, driveenctrl_);
  set_p_driveacc(data, driveacc_);
  set_p_drivethrottlepedaltarget(data, drivethrottlepedaltarget_);
  set_p_drivespeedtarget(data, drivespeedtarget_);
  set_p_checksum100(data, checksum100_);
}

void Throttlecommand100::Reset() {
  // TODO(All) :  you should check this manually
  driveenctrl_ = false;
  driveacc_ = 0.0;
  drivethrottlepedaltarget_ = 0.0;
  drivespeedtarget_ = 0.0;
  checksum100_ = 0;
}

Throttlecommand100* Throttlecommand100::set_driveenctrl(
    bool driveenctrl) {
  driveenctrl_ = driveenctrl;
  return this;
 }

// config detail: {'bit': 0, 'description': '加速使能', 'is_signed_var': False, 'len': 1, 'name': 'DriveEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Throttlecommand100::set_p_driveenctrl(uint8_t* data,
    bool driveenctrl) {
  int x = driveenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}


Throttlecommand100* Throttlecommand100::set_driveacc(
    double driveacc) {
  driveacc_ = driveacc;
  return this;
 }

// config detail: {'bit': 15, 'description': '车辆目标纵向加速度（可选）', 'is_signed_var': False, 'len': 10, 'name': 'DriveAcc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|10]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
void Throttlecommand100::set_p_driveacc(uint8_t* data,
    double driveacc) {
  driveacc = ProtocolData::BoundedValue(0.0, 10.0, driveacc);
  int x = driveacc / 0.010000;
  uint8_t t = 0;

  t = x & 0x3;
  Byte to_set0(data + 2);
  to_set0.set_value(t, 6, 2);
  x >>= 2;

  t = x & 0xFF;
  Byte to_set1(data + 1);
  to_set1.set_value(t, 0, 8);
}


Throttlecommand100* Throttlecommand100::set_drivethrottlepedaltarget(
    double drivethrottlepedaltarget) {
  drivethrottlepedaltarget_ = drivethrottlepedaltarget;
  return this;
 }

// config detail: {'bit': 31, 'description': '虚拟目标加速踏板位置', 'is_signed_var': False, 'len': 16, 'name': 'DriveThrottlePedalTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
void Throttlecommand100::set_p_drivethrottlepedaltarget(uint8_t* data,
    double drivethrottlepedaltarget) {
  drivethrottlepedaltarget = ProtocolData::BoundedValue(0.0, 100.0, drivethrottlepedaltarget);
  int x = drivethrottlepedaltarget / 0.100000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 4);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 3);
  to_set1.set_value(t, 0, 8);
}


Throttlecommand100* Throttlecommand100::set_drivespeedtarget(
    double drivespeedtarget) {
  drivespeedtarget_ = drivespeedtarget;
  return this;
 }

// config detail: {'bit': 47, 'description': '驾驶速度', 'is_signed_var': False, 'len': 10, 'name': 'DriveSpeedTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|40.95]', 'physical_unit': ' m/s', 'precision': 0.01, 'type': 'double'}
void Throttlecommand100::set_p_drivespeedtarget(uint8_t* data,
    double drivespeedtarget) {
  drivespeedtarget = ProtocolData::BoundedValue(0.0, 40.95, drivespeedtarget);
  int x = drivespeedtarget / 0.010000;
  uint8_t t = 0;

  t = x & 0x3;
  Byte to_set0(data + 6);
  to_set0.set_value(t, 6, 2);
  x >>= 2;

  t = x & 0xFF;
  Byte to_set1(data + 5);
  to_set1.set_value(t, 0, 8);
}


Throttlecommand100* Throttlecommand100::set_checksum100(
    int checksum100) {
  checksum100_ = checksum100;
  return this;
 }

// config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum100', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Throttlecommand100::set_p_checksum100(uint8_t* data,
    int checksum100) {
  checksum100 = ProtocolData::BoundedValue(0, 255, checksum100);
  int x = checksum100;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
