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

#include "modules/canbus/vehicle/hooke/protocol/vcureport1_505.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Vcureport1505::Vcureport1505() {}
const int32_t Vcureport1505::ID = 0x505;

void Vcureport1505::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_steermodestatus(steermodestatus(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_brakelightactual(brakelightactual(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_vehicleacc(vehicleacc(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_vehiclespeed(vehiclespeed(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_aebstate(aebstate(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_vehiclefrontcrashstate(vehiclefrontcrashstate(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_backcrashstate(backcrashstate(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_vehiclemodestate(vehiclemodestate(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_drivemodestatus(drivemodestatus(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_vehicleerrcode(vehicleerrcode(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_carworkstate(carworkstate(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_carpowerstate(carpowerstate(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_allowselfdrivingrun(allowselfdrivingrun(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_rcuconnectionstatus(rcuconnectionstatus(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_turnlightactual(turnlightactual(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_headlightactual(headlightactual(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_clearancelampactural(clearancelampactural(bytes, length));
  chassis->mutable_hooke()->mutable_vcureport1_505()->set_vcuchassisestopstafb(vcuchassisestopstafb(bytes, length));
}

// config detail: {'bit': 10, 'description': '当前转向状态', 'is_signed_var': False, 'len': 3, 'name': 'steermodestatus', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcureport1505::steermodestatus(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 3);

  int ret = x;
  return ret;
}

// config detail: {'bit': 11, 'description': '当前刹车灯状态', 'is_signed_var': False, 'len': 1, 'name': 'brakelightactual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcureport1505::brakelightactual(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 7, 'description': '纵向加（减）速度（可选）', 'is_signed_var': False, 'len': 12, 'name': 'vehicleacc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-10|10]', 'physical_unit': 'm/s^2', 'precision': 0.01, 'type': 'double'}
double Vcureport1505::vehicleacc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(4, 4);
  x <<= 4;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 23, 'description': '车速', 'is_signed_var': True, 'len': 16, 'name': 'vehiclespeed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-32.768|32.767]', 'physical_unit': 'm/s', 'precision': 0.001, 'type': 'double'}
double Vcureport1505::vehiclespeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  double ret = x * 0.001000;
  return ret;
}

// config detail: {'bit': 32, 'description': 'AEB状态', 'is_signed_var': False, 'len': 1, 'name': 'aebstate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcureport1505::aebstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 33, 'is_signed_var': False, 'len': 1, 'name': 'vehiclefrontcrashstate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcureport1505::vehiclefrontcrashstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 34, 'is_signed_var': False, 'len': 1, 'name': 'backcrashstate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcureport1505::backcrashstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 36, 'is_signed_var': False, 'len': 2, 'name': 'vehiclemodestate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcureport1505::vehiclemodestate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(3, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 3, 'name': 'drivemodestatus', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcureport1505::drivemodestatus(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 3);

  int ret = x;
  return ret;
}

// config detail: {'bit': 47, 'description': '故障码', 'is_signed_var': False, 'len': 8, 'name': 'vehicleerrcode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcureport1505::vehicleerrcode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 51, 'description': '车辆工作状态', 'is_signed_var': False, 'len': 4, 'name': 'carworkstate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcureport1505::carworkstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 53, 'description': '车辆电源状态', 'is_signed_var': False, 'len': 2, 'name': 'carpowerstate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcureport1505::carpowerstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 54, 'description': '允许自动驾驶行驶指令', 'is_signed_var': False, 'len': 1, 'name': 'allowselfdrivingrun', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcureport1505::allowselfdrivingrun(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 55, 'description': '遥控器连接状态', 'is_signed_var': False, 'len': 1, 'name': 'rcuconnectionstatus', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcureport1505::rcuconnectionstatus(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 57, 'description': '转向灯状态', 'is_signed_var': False, 'len': 2, 'name': 'turnlightactual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcureport1505::turnlightactual(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 58, 'description': '灯状态', 'is_signed_var': False, 'len': 1, 'name': 'headlightactual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcureport1505::headlightactual(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 60, 'description': '示宽灯状态', 'is_signed_var': False, 'len': 1, 'name': 'clearancelampactural', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcureport1505::clearancelampactural(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 63, 'description': '急停状态反馈', 'is_signed_var': False, 'len': 3, 'name': 'vcuchassisestopstafb', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcureport1505::vcuchassisestopstafb(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(5, 3);

  int ret = x;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
