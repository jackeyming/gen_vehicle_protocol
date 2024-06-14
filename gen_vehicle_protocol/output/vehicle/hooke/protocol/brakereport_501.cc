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

#include "modules/canbus/vehicle/hooke/protocol/brakereport_501.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Brakereport501::Brakereport501() {}
const int32_t Brakereport501::ID = 0x501;

void Brakereport501::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_brakereport_501()->set_brakeenstate(brakeenstate(bytes, length));
  chassis->mutable_hooke()->mutable_brakereport_501()->set_brakeflt1(brakeflt1(bytes, length));
  chassis->mutable_hooke()->mutable_brakereport_501()->set_brakeflt2(brakeflt2(bytes, length));
  chassis->mutable_hooke()->mutable_brakereport_501()->set_brakepedalactual(brakepedalactual(bytes, length));
}

// config detail: {'bit': 1, 'description': '制动状态', 'is_signed_var': False, 'len': 2, 'name': 'brakeenstate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakereport501::brakeenstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 15, 'description': '制动故障信息1', 'is_signed_var': False, 'len': 8, 'name': 'brakeflt1', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakereport501::brakeflt1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 23, 'description': '制动故障信息2', 'is_signed_var': False, 'len': 8, 'name': 'brakeflt2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakereport501::brakeflt2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 31, 'description': '制动踏板位置反馈', 'is_signed_var': False, 'len': 16, 'name': 'brakepedalactual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
double Brakereport501::brakepedalactual(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
