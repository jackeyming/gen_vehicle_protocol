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

#include "modules/canbus/vehicle/hooke/protocol/bcmmessage4_5f4.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Bcmmessage45f4::Bcmmessage45f4() {}
const int32_t Bcmmessage45f4::ID = 0x5F4;

void Bcmmessage45f4::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_ltemp(ltemp(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_ntemp(ntemp(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_safebeltsta1(safebeltsta1(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_safebeltsta2(safebeltsta2(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_safebeltsta3(safebeltsta3(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_safebeltsta4(safebeltsta4(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_safebeltsta5(safebeltsta5(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_safebeltsta6(safebeltsta6(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_seatsta1(seatsta1(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_seatsta2(seatsta2(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_seatsta3(seatsta3(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_seatsta4(seatsta4(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_seatsta5(seatsta5(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_seatsta6(seatsta6(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_ioin13(ioin13(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_ioin14(ioin14(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_ioin15(ioin15(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_ioin16(ioin16(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_iocur1(iocur1(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_iocur2(iocur2(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_iocur3(iocur3(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_iocur4(iocur4(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_adcvin(adcvin(bytes, length));
  chassis->mutable_hooke()->mutable_bcmmessage4_5f4()->set_advvin5(advvin5(bytes, length));
}

// config detail: {'bit': 8, 'description': '交流充L线温度', 'is_signed_var': False, 'len': 8, 'name': 'ltemp', 'offset': -40.0, 'order': 'intel', 'physical_range': '[-40|215]', 'physical_unit': '℃', 'precision': 1.0, 'type': 'int'}
int Bcmmessage45f4::ltemp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  int ret = x + -40.000000;
  return ret;
}

// config detail: {'bit': 16, 'description': '交流充N线温度', 'is_signed_var': False, 'len': 8, 'name': 'ntemp', 'offset': -40.0, 'order': 'intel', 'physical_range': '[-40|215]', 'physical_unit': '℃', 'precision': 1.0, 'type': 'int'}
int Bcmmessage45f4::ntemp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x + -40.000000;
  return ret;
}

// config detail: {'bit': 24, 'description': '前左安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'safebeltsta1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::safebeltsta1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 25, 'description': '前中安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'safebeltsta2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::safebeltsta2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 26, 'description': '前右安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'safebeltsta3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::safebeltsta3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 27, 'description': '后左安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'safebeltsta4', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::safebeltsta4(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 28, 'description': '后中安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'safebeltsta5', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::safebeltsta5(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 29, 'description': '后右安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'safebeltsta6', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::safebeltsta6(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 30, 'description': '前左座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'seatsta1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::seatsta1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 31, 'description': '前中座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'seatsta2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::seatsta2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 32, 'description': '前右座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'seatsta3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::seatsta3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 33, 'description': '后左座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'seatsta4', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::seatsta4(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 34, 'description': '后中座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'seatsta5', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::seatsta5(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 35, 'description': '后右座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'seatsta6', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::seatsta6(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 36, 'description': '开关量输入口13', 'is_signed_var': False, 'len': 1, 'name': 'ioin13', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::ioin13(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 37, 'description': '开关量输入口14', 'is_signed_var': False, 'len': 1, 'name': 'ioin14', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::ioin14(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 38, 'description': '开关量输入口15', 'is_signed_var': False, 'len': 1, 'name': 'ioin15', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::ioin15(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 39, 'description': '开关量输入口16', 'is_signed_var': False, 'len': 1, 'name': 'ioin16', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::ioin16(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 40, 'description': '电流型输入口1', 'is_signed_var': False, 'len': 1, 'name': 'iocur1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::iocur1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 41, 'description': '电流型输入口2', 'is_signed_var': False, 'len': 1, 'name': 'iocur2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::iocur2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 42, 'description': '电流型输入口3', 'is_signed_var': False, 'len': 1, 'name': 'iocur3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::iocur3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 43, 'description': '电流型输入口4', 'is_signed_var': False, 'len': 1, 'name': 'iocur4', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::iocur4(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 44, 'description': '电流型传感器输入口', 'is_signed_var': False, 'len': 1, 'name': 'adcvin', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|20]', 'physical_unit': 'mV', 'precision': 1.0, 'type': 'bool'}
bool Bcmmessage45f4::adcvin(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 46, 'description': '电压型传感器输入口4(0~10V)', 'is_signed_var': False, 'len': 10, 'name': 'advvin5', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10000]', 'physical_unit': 'mV', 'precision': 10.0, 'type': 'double'}
double Bcmmessage45f4::advvin5(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  double ret = x * 10.000000;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
