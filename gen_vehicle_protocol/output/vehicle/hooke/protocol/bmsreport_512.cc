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

#include "modules/canbus/vehicle/hooke/protocol/bmsreport_512.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Bmsreport512::Bmsreport512() {}
const int32_t Bmsreport512::ID = 0x512;

void Bmsreport512::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_bmsreport_512()->set_batteryvoltage(batteryvoltage(bytes, length));
  chassis->mutable_hooke()->mutable_bmsreport_512()->set_batterycurrent(batterycurrent(bytes, length));
  chassis->mutable_hooke()->mutable_bmsreport_512()->set_batterysoc(batterysoc(bytes, length));
  chassis->mutable_hooke()->mutable_bmsreport_512()->set_batteryleadacidvoltage(batteryleadacidvoltage(bytes, length));
}

// config detail: {'bit': 7, 'description': '电池电压', 'is_signed_var': False, 'len': 16, 'name': 'batteryvoltage', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|300]', 'physical_unit': 'V', 'precision': 0.01, 'type': 'double'}
double Bmsreport512::batteryvoltage(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 23, 'description': '电池电流', 'is_signed_var': True, 'len': 16, 'name': 'batterycurrent', 'offset': -3200.0, 'order': 'motorola', 'physical_range': '[-3200|3353.5]', 'physical_unit': 'A', 'precision': 0.1, 'type': 'double'}
double Bmsreport512::batterycurrent(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  double ret = x * 0.100000 + -3200.000000;
  return ret;
}

// config detail: {'bit': 39, 'description': '电池SOC', 'is_signed_var': False, 'len': 8, 'name': 'batterysoc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
int Bmsreport512::batterysoc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'batteryleadacidvoltage', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'V', 'precision': 1.0, 'type': 'int'}
int Bmsreport512::batteryleadacidvoltage(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
