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

#include "modules/canbus/vehicle/pix_hooke/protocol/brakecommand_101.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace pix_hooke {

using ::apollo::drivers::canbus::Byte;

const int32_t Brakecommand101::ID = 0x101;

// public
Brakecommand101::Brakecommand101() { Reset(); }

uint32_t Brakecommand101::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Brakecommand101::UpdateData(uint8_t* data) {
  set_p_brakeenctrl(data, brakeenctrl_);
  set_p_aebenctrl(data, aebenctrl_);
  set_p_brakedec(data, brakedec_);
  set_p_brakepedaltarget(data, brakepedaltarget_);
  set_p_checksum101(data, checksum101_);
}

void Brakecommand101::Reset() {
  // TODO(All) :  you should check this manually
  brakeenctrl_ = Brakecommand_101::BRAKEENCTRL_DISABLE;
  aebenctrl_ = Brakecommand_101::AEBENCTRL_DISABLE;
  brakedec_ = 0.0;
  brakepedaltarget_ = 0.0;
  checksum101_ = 0;
}

Brakecommand101* Brakecommand101::set_brakeenctrl(
    Brakecommand_101::BrakeenctrlType brakeenctrl) {
  brakeenctrl_ = brakeenctrl;
  return this;
 }

// config detail: {'bit': 0, 'description': '制动使能', 'enum': {0: 'BRAKEENCTRL_DISABLE', 1: 'BRAKEENCTRL_ABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'BrakeEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Brakecommand101::set_p_brakeenctrl(uint8_t* data,
    Brakecommand_101::BrakeenctrlType brakeenctrl) {
  int x = brakeenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}


Brakecommand101* Brakecommand101::set_aebenctrl(
    Brakecommand_101::AebenctrlType aebenctrl) {
  aebenctrl_ = aebenctrl;
  return this;
 }

// config detail: {'bit': 1, 'description': 'AEB使能', 'enum': {0: 'AEBENCTRL_DISABLE', 1: 'AEBENCTRL_ABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'AebEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Brakecommand101::set_p_aebenctrl(uint8_t* data,
    Brakecommand_101::AebenctrlType aebenctrl) {
  int x = aebenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 1, 1);
}


Brakecommand101* Brakecommand101::set_brakedec(
    double brakedec) {
  brakedec_ = brakedec;
  return this;
 }

// config detail: {'bit': 15, 'description': '目标减速度（可选）', 'is_signed_var': False, 'len': 10, 'name': 'BrakeDec', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|10]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
void Brakecommand101::set_p_brakedec(uint8_t* data,
    double brakedec) {
  brakedec = ProtocolData::BoundedValue(0.0, 10.0, brakedec);
  int x = brakedec / 0.010000;
  uint8_t t = 0;

  t = x & 0x3;
  Byte to_set0(data + 2);
  to_set0.set_value(t, 6, 2);
  x >>= 2;

  t = x & 0xFF;
  Byte to_set1(data + 1);
  to_set1.set_value(t, 0, 8);
}


Brakecommand101* Brakecommand101::set_brakepedaltarget(
    double brakepedaltarget) {
  brakepedaltarget_ = brakepedaltarget;
  return this;
 }

// config detail: {'bit': 31, 'description': '虚拟目标制动踏板位置', 'is_signed_var': False, 'len': 16, 'name': 'BrakePedalTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
void Brakecommand101::set_p_brakepedaltarget(uint8_t* data,
    double brakepedaltarget) {
  brakepedaltarget = ProtocolData::BoundedValue(0.0, 100.0, brakepedaltarget);
  int x = brakepedaltarget / 0.100000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 4);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 3);
  to_set1.set_value(t, 0, 8);
}


Brakecommand101* Brakecommand101::set_checksum101(
    int checksum101) {
  checksum101_ = checksum101;
  return this;
 }

// config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum101', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Brakecommand101::set_p_checksum101(uint8_t* data,
    int checksum101) {
  checksum101 = ProtocolData::BoundedValue(0, 255, checksum101);
  int x = checksum101;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}

}  // namespace pix_hooke
}  // namespace canbus
}  // namespace apollo
