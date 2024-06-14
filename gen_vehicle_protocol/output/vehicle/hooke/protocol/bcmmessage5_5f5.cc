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

#include "modules/canbus/vehicle/hooke/protocol/bcmmessage5_5f5.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Bcmmessage55f5::Bcmmessage55f5() {}
const int32_t Bcmmessage55f5::ID = 0x5F5;

void Bcmmessage55f5::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_bcmmessage5_5f5()->set_adrvin1(adrvin1(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage5_5f5()->set_adrvin2(adrvin2(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage5_5f5()->set_adrvin3(adrvin3(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage5_5f5()->set_adrvin4(adrvin4(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage5_5f5()->set_advvin1(advvin1(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage5_5f5()->set_advvin2(advvin2(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage5_5f5()->set_advvin3(advvin3(bytes, length));
}

// config detail: {'bit': 0, 'description': '电阻型传感器输入口1', 'is_signed_var': False, 'len': 8, 'name': 'adrvin1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': 'Ω', 'precision': 2.0, 'type': 'double'}
double Bcmmessage55f5::adrvin1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 2.000000;
  return ret;
}

// config detail: {'bit': 8, 'description': '电阻型传感器输入口2', 'is_signed_var': False, 'len': 8, 'name': 'adrvin2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': 'Ω', 'precision': 2.0, 'type': 'double'}
double Bcmmessage55f5::adrvin2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 2.000000;
  return ret;
}

// config detail: {'bit': 16, 'description': '电阻型传感器输入口3', 'is_signed_var': False, 'len': 8, 'name': 'adrvin3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': 'Ω', 'precision': 2.0, 'type': 'double'}
double Bcmmessage55f5::adrvin3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 2.000000;
  return ret;
}

// config detail: {'bit': 24, 'description': '电阻型传感器输入口4', 'is_signed_var': False, 'len': 8, 'name': 'adrvin4', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': 'Ω', 'precision': 2.0, 'type': 'double'}
double Bcmmessage55f5::adrvin4(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  double ret = x * 2.000000;
  return ret;
}

// config detail: {'bit': 32, 'description': '电压型传感器输入口1(烟雾传感器）', 'is_signed_var': False, 'len': 10, 'name': 'advvin1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3500]', 'physical_unit': 'mV', 'precision': 5.0, 'type': 'double'}
double Bcmmessage55f5::advvin1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 2);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 5.000000;
  return ret;
}

// config detail: {'bit': 42, 'description': '电压型传感器输入口2（CO2传感器）', 'is_signed_var': False, 'len': 10, 'name': 'advvin2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3500]', 'physical_unit': 'mV', 'precision': 5.0, 'type': 'double'}
double Bcmmessage55f5::advvin2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 4);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(2, 6);
  x <<= 6;
  x |= t;

  double ret = x * 5.000000;
  return ret;
}

// config detail: {'bit': 52, 'description': '电压型传感器输入口3', 'is_signed_var': False, 'len': 10, 'name': 'advvin3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3500]', 'physical_unit': 'mV', 'precision': 5.0, 'type': 'double'}
double Bcmmessage55f5::advvin3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 6);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(4, 4);
  x <<= 4;
  x |= t;

  double ret = x * 5.000000;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
