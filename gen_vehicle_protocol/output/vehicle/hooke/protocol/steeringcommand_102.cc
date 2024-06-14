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

#include "modules/canbus/vehicle/hooke/protocol/steeringcommand_102.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

const int32_t Steeringcommand102::ID = 0x102;

// public
Steeringcommand102::Steeringcommand102() { Reset(); }

uint32_t Steeringcommand102::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Steeringcommand102::UpdateData(uint8_t* data) {
  set_p_steerenctrl(data, steerenctrl_);
  set_p_steeranglespeed(data, steeranglespeed_);
  set_p_steerangletarget(data, steerangletarget_);
  set_p_checksum102(data, checksum102_);
}

void Steeringcommand102::Reset() {
  // TODO(All) :  you should check this manually
  steerenctrl_ = false;
  steeranglespeed_ = 0;
  steerangletarget_ = 0;
  checksum102_ = 0;
}

Steeringcommand102* Steeringcommand102::set_steerenctrl(
    bool steerenctrl) {
  steerenctrl_ = steerenctrl;
  return this;
 }

// config detail: {'bit': 0, 'description': '转向使能', 'is_signed_var': False, 'len': 1, 'name': 'SteerEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Steeringcommand102::set_p_steerenctrl(uint8_t* data,
    bool steerenctrl) {
  int x = steerenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}


Steeringcommand102* Steeringcommand102::set_steeranglespeed(
    int steeranglespeed) {
  steeranglespeed_ = steeranglespeed;
  return this;
 }

// config detail: {'bit': 15, 'description': '目标前轮转速 （方向盘转速）', 'is_signed_var': False, 'len': 8, 'name': 'SteerAngleSpeed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
void Steeringcommand102::set_p_steeranglespeed(uint8_t* data,
    int steeranglespeed) {
  steeranglespeed = ProtocolData::BoundedValue(0, 250, steeranglespeed);
  int x = steeranglespeed;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 8);
}


Steeringcommand102* Steeringcommand102::set_steerangletarget(
    int steerangletarget) {
  steerangletarget_ = steerangletarget;
  return this;
 }

// config detail: {'bit': 31, 'description': '目标前轮转向角（方向盘转角）', 'is_signed_var': False, 'len': 16, 'name': 'SteerAngleTarget', 'offset': -500.0, 'order': 'motorola', 'physical_range': '[-465|465]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
void Steeringcommand102::set_p_steerangletarget(uint8_t* data,
    int steerangletarget) {
  steerangletarget = ProtocolData::BoundedValue(-465, 465, steerangletarget);
  int x = (steerangletarget - -500.000000);
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 4);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 3);
  to_set1.set_value(t, 0, 8);
}


Steeringcommand102* Steeringcommand102::set_checksum102(
    int checksum102) {
  checksum102_ = checksum102;
  return this;
 }

// config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum102', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Steeringcommand102::set_p_checksum102(uint8_t* data,
    int checksum102) {
  checksum102 = ProtocolData::BoundedValue(0, 255, checksum102);
  int x = checksum102;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
