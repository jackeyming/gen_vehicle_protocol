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

#include "modules/canbus/vehicle/hooke/protocol/steeringreport_502.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Steeringreport502::Steeringreport502() {}
const int32_t Steeringreport502::ID = 0x502;

void Steeringreport502::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_steeringreport_502()->set_steerenstate(steerenstate(bytes, length));
  chassis->mutable_hooke()->mutable_steeringreport_502()->set_steerflt1(steerflt1(bytes, length));
  chassis->mutable_hooke()->mutable_steeringreport_502()->set_steerflt2(steerflt2(bytes, length));
  chassis->mutable_hooke()->mutable_steeringreport_502()->set_steerangleactual(steerangleactual(bytes, length));
  chassis->mutable_hooke()->mutable_steeringreport_502()->set_steeranglespeedactual(steeranglespeedactual(bytes, length));
}

// config detail: {'bit': 1, 'description': '转向状态', 'is_signed_var': False, 'len': 2, 'name': 'steerenstate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steeringreport502::steerenstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 15, 'description': '转向故障信息1', 'is_signed_var': False, 'len': 8, 'name': 'steerflt1', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steeringreport502::steerflt1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 23, 'description': '转向故障信息2', 'is_signed_var': False, 'len': 8, 'name': 'steerflt2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steeringreport502::steerflt2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 31, 'description': '转向角度反馈', 'is_signed_var': False, 'len': 16, 'name': 'steerangleactual', 'offset': -500.0, 'order': 'motorola', 'physical_range': '[-465|465]', 'physical_unit': 'deg', 'precision': 1.0, 'type': 'int'}
int Steeringreport502::steerangleactual(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x + -500.000000;
  return ret;
}

// config detail: {'bit': 55, 'description': '转速反馈', 'is_signed_var': False, 'len': 8, 'name': 'steeranglespeedactual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'deg/s', 'precision': 1.0, 'type': 'int'}
int Steeringreport502::steeranglespeedactual(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
