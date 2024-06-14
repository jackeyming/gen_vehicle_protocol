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

#include "modules/canbus/vehicle/hooke/protocol/gearcommand_103.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

const int32_t Gearcommand103::ID = 0x103;

// public
Gearcommand103::Gearcommand103() { Reset(); }

uint32_t Gearcommand103::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Gearcommand103::UpdateData(uint8_t* data) {
  set_p_gearenctrl(data, gearenctrl_);
  set_p_geartarget(data, geartarget_);
  set_p_checksum103(data, checksum103_);
}

void Gearcommand103::Reset() {
  // TODO(All) :  you should check this manually
  gearenctrl_ = false;
  geartarget_ = 0;
  checksum103_ = 0;
}

Gearcommand103* Gearcommand103::set_gearenctrl(
    bool gearenctrl) {
  gearenctrl_ = gearenctrl;
  return this;
 }

// config detail: {'bit': 0, 'description': '档位控制使能', 'is_signed_var': False, 'len': 1, 'name': 'GearEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Gearcommand103::set_p_gearenctrl(uint8_t* data,
    bool gearenctrl) {
  int x = gearenctrl;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}


Gearcommand103* Gearcommand103::set_geartarget(
    int geartarget) {
  geartarget_ = geartarget;
  return this;
 }

// config detail: {'bit': 10, 'description': '目标档位', 'is_signed_var': False, 'len': 3, 'name': 'GearTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Gearcommand103::set_p_geartarget(uint8_t* data,
    int geartarget) {
  geartarget = ProtocolData::BoundedValue(0, 7, geartarget);
  int x = geartarget;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 3);
}


Gearcommand103* Gearcommand103::set_checksum103(
    int checksum103) {
  checksum103_ = checksum103;
  return this;
 }

// config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum103', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Gearcommand103::set_p_checksum103(uint8_t* data,
    int checksum103) {
  checksum103 = ProtocolData::BoundedValue(0, 255, checksum103);
  int x = checksum103;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
