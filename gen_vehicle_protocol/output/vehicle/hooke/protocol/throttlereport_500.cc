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

#include "modules/canbus/vehicle/hooke/protocol/throttlereport_500.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Throttlereport500::Throttlereport500() {}
const int32_t Throttlereport500::ID = 0x500;

void Throttlereport500::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_throttlereport_500()->set_driveenstate(driveenstate(bytes, length));
  chassis->mutable_hooke()->mutable_throttlereport_500()->set_driveflt1(driveflt1(bytes, length));
  chassis->mutable_hooke()->mutable_throttlereport_500()->set_driveflt2(driveflt2(bytes, length));
  chassis->mutable_hooke()->mutable_throttlereport_500()->set_drivethrottlepedalactual(drivethrottlepedalactual(bytes, length));
}

// config detail: {'bit': 1, 'description': '驱动状态', 'is_signed_var': False, 'len': 2, 'name': 'driveenstate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Throttlereport500::driveenstate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 15, 'description': '驱动故障信息1', 'is_signed_var': False, 'len': 8, 'name': 'driveflt1', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Throttlereport500::driveflt1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 23, 'description': '驱动故障信息2（控制指令周期故障）', 'is_signed_var': False, 'len': 8, 'name': 'driveflt2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Throttlereport500::driveflt2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 31, 'description': '加速踏板位置反馈', 'is_signed_var': False, 'len': 16, 'name': 'drivethrottlepedalactual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
double Throttlereport500::drivethrottlepedalactual(const std::uint8_t* bytes, int32_t length) const {
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
