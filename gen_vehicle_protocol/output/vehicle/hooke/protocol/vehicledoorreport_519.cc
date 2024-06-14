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

#include "modules/canbus/vehicle/hooke/protocol/vehicledoorreport_519.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Vehicledoorreport519::Vehicledoorreport519() {}
const int32_t Vehicledoorreport519::ID = 0x519;

void Vehicledoorreport519::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_vehicledoorreport_519()->set_dooropensta(dooropensta(bytes, length));
  chassis->mutable_hooke()->mutable_vehicledoorreport_519()->set_doorclosesta(doorclosesta(bytes, length));
  chassis->mutable_hooke()->mutable_vehicledoorreport_519()->set_dooropeninplace(dooropeninplace(bytes, length));
  chassis->mutable_hooke()->mutable_vehicledoorreport_519()->set_doorcloseinplace(doorcloseinplace(bytes, length));
  chassis->mutable_hooke()->mutable_vehicledoorreport_519()->set_dooropentimeout(dooropentimeout(bytes, length));
  chassis->mutable_hooke()->mutable_vehicledoorreport_519()->set_doorclosetimeout(doorclosetimeout(bytes, length));
  chassis->mutable_hooke()->mutable_vehicledoorreport_519()->set_doorbuttonenable(doorbuttonenable(bytes, length));
  chassis->mutable_hooke()->mutable_vehicledoorreport_519()->set_doorreportsta(doorreportsta(bytes, length));
}

// config detail: {'bit': 0, 'description': '开门中', 'is_signed_var': False, 'len': 1, 'name': 'dooropensta', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vehicledoorreport519::dooropensta(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 1, 'description': '关门中', 'is_signed_var': False, 'len': 1, 'name': 'doorclosesta', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vehicledoorreport519::doorclosesta(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 2, 'description': '开门到位', 'is_signed_var': False, 'len': 1, 'name': 'dooropeninplace', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vehicledoorreport519::dooropeninplace(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 3, 'description': '关门到位', 'is_signed_var': False, 'len': 1, 'name': 'doorcloseinplace', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vehicledoorreport519::doorcloseinplace(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 4, 'description': '开门故障', 'is_signed_var': False, 'len': 1, 'name': 'dooropentimeout', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vehicledoorreport519::dooropentimeout(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 5, 'description': '关门故障', 'is_signed_var': False, 'len': 1, 'name': 'doorclosetimeout', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vehicledoorreport519::doorclosetimeout(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 6, 'description': '门按钮使能状态', 'is_signed_var': False, 'len': 1, 'name': 'doorbuttonenable', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vehicledoorreport519::doorbuttonenable(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 9, 'is_signed_var': False, 'len': 2, 'name': 'doorreportsta', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vehicledoorreport519::doorreportsta(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
