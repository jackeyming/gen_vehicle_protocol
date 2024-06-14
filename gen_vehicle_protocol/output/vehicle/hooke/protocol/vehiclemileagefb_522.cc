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

#include "modules/canbus/vehicle/hooke/protocol/vehiclemileagefb_522.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Vehiclemileagefb522::Vehiclemileagefb522() {}
const int32_t Vehiclemileagefb522::ID = 0x522;

void Vehiclemileagefb522::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_vehiclemileagefb_522()->set_vehicleodo(vehicleodo(bytes, length));
  chassis->mutable_hooke()->mutable_vehiclemileagefb_522()->set_vehiclesubmileage(vehiclesubmileage(bytes, length));
  chassis->mutable_hooke()->mutable_vehiclemileagefb_522()->set_vcuremainingmile(vcuremainingmile(bytes, length));
}

// config detail: {'bit': 7, 'description': '总计里程', 'is_signed_var': False, 'len': 24, 'name': 'vehicleodo', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1677721.5]', 'physical_unit': 'km', 'precision': 0.1, 'type': 'double'}
double Vehiclemileagefb522::vehicleodo(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 2);
  t = t2.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.100000;
  return ret;
}

// config detail: {'bit': 31, 'description': '小计里程', 'is_signed_var': False, 'len': 24, 'name': 'vehiclesubmileage', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|167772.215]', 'physical_unit': 'km', 'precision': 0.001, 'type': 'double'}
double Vehiclemileagefb522::vehiclesubmileage(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 5);
  t = t2.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.001000;
  return ret;
}

// config detail: {'bit': 55, 'description': '剩余里程', 'is_signed_var': False, 'len': 8, 'name': 'vcuremainingmile', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'km', 'precision': 1.0, 'type': 'int'}
int Vehiclemileagefb522::vcuremainingmile(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
