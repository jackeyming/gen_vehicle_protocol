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

#include "modules/canbus/vehicle/pix_hooke/protocol/parkcommand_104.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace pix_hooke {

using ::apollo::drivers::canbus::Byte;

const int32_t Parkcommand104::ID = 0x104;

// public
Parkcommand104::Parkcommand104() { Reset(); }

uint32_t Parkcommand104::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Parkcommand104::UpdateData(uint8_t* data) {
  set_p_parkenctrl(data, parkenctrl_);
  set_p_parktarget(data, parktarget_);
  set_p_checksum104(data, checksum104_);
}

void Parkcommand104::Reset() {
  // TODO(All) :  you should check this manually
  parkenctrl_ = Parkcommand_104::PARKENCTRL_DISABLE;
  parktarget_ = Parkcommand_104::PARKTARGET_RELEASE;
  checksum104_ = 0;
}

Parkcommand104* Parkcommand104::set_parkenctrl(
    Parkcommand_104::ParkenctrlType parkenctrl) {
  parkenctrl_ = parkenctrl;
  return this;
 }

// config detail: {'bit': 0, 'description': '驻车使能', 'enum': {0: 'PARKENCTRL_DISABLE', 1: 'PARKENCTRL_ABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ParkEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Parkcommand104::set_p_parkenctrl(uint8_t* data,
    Parkcommand_104::ParkenctrlType parkenctrl) {
  int x = parkenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}


Parkcommand104* Parkcommand104::set_parktarget(
    Parkcommand_104::ParktargetType parktarget) {
  parktarget_ = parktarget;
  return this;
 }

// config detail: {'bit': 8, 'description': '驻车指令', 'enum': {0: 'PARKTARGET_RELEASE', 1: 'PARKTARGET_PARKINGTRIGGER'}, 'is_signed_var': False, 'len': 1, 'name': 'ParkTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
void Parkcommand104::set_p_parktarget(uint8_t* data,
    Parkcommand_104::ParktargetType parktarget) {
  int x = parktarget;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 1);
}


Parkcommand104* Parkcommand104::set_checksum104(
    int checksum104) {
  checksum104_ = checksum104;
  return this;
 }

// config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum104', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Parkcommand104::set_p_checksum104(uint8_t* data,
    int checksum104) {
  checksum104 = ProtocolData::BoundedValue(0, 255, checksum104);
  int x = checksum104;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}

}  // namespace pix_hooke
}  // namespace canbus
}  // namespace apollo
