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

#include "modules/canbus/vehicle/hooke/protocol/automessage_3a0.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

const int32_t Automessage3a0::ID = 0x3A0;

// public
Automessage3a0::Automessage3a0() { Reset(); }

uint32_t Automessage3a0::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Automessage3a0::UpdateData(uint8_t* data) {
  set_p_autodrivemode(data, autodrivemode_);
  set_p_autoheartbeat(data, autoheartbeat_);
}

void Automessage3a0::Reset() {
  // TODO(All) :  you should check this manually
  autodrivemode_ = 0;
  autoheartbeat_ = 0;
}

Automessage3a0* Automessage3a0::set_autodrivemode(
    int autodrivemode) {
  autodrivemode_ = autodrivemode;
  return this;
 }

// config detail: {'bit': 7, 'description': '自驾状态', 'is_signed_var': False, 'len': 8, 'name': 'AutoDriveMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Automessage3a0::set_p_autodrivemode(uint8_t* data,
    int autodrivemode) {
  autodrivemode = ProtocolData::BoundedValue(0, 255, autodrivemode);
  int x = autodrivemode;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 8);
}


Automessage3a0* Automessage3a0::set_autoheartbeat(
    int autoheartbeat) {
  autoheartbeat_ = autoheartbeat;
  return this;
 }

// config detail: {'bit': 63, 'description': '自动驾驶心跳包', 'is_signed_var': False, 'len': 8, 'name': 'AutoHeartbeat', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Automessage3a0::set_p_autoheartbeat(uint8_t* data,
    int autoheartbeat) {
  autoheartbeat = ProtocolData::BoundedValue(0, 255, autoheartbeat);
  int x = autoheartbeat;

  Byte to_set(data + 7);
  to_set.set_value(x, 0, 8);
}

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
