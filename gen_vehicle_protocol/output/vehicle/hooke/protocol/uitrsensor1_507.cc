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

#include "modules/canbus/vehicle/hooke/protocol/uitrsensor1_507.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Uitrsensor1507::Uitrsensor1507() {}
const int32_t Uitrsensor1507::ID = 0x507;

void Uitrsensor1507::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_uitrsensor1_507()->set_uiuss8tofdirect(uiuss8tofdirect(bytes, length));
  chassis->mutable_hooke()->mutable_uitrsensor1_507()->set_uiuss9tofdirect(uiuss9tofdirect(bytes, length));
  chassis->mutable_hooke()->mutable_uitrsensor1_507()->set_uiuss10tofdirect(uiuss10tofdirect(bytes, length));
  chassis->mutable_hooke()->mutable_uitrsensor1_507()->set_uiuss11tofdirect(uiuss11tofdirect(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 16, 'name': 'uiuss8tofdirect', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'cm', 'precision': 0.01724, 'type': 'double'}
double Uitrsensor1507::uiuss8tofdirect(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.017240;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 16, 'name': 'uiuss9tofdirect', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'cm', 'precision': 0.01724, 'type': 'double'}
double Uitrsensor1507::uiuss9tofdirect(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.017240;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'uiuss10tofdirect', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'cm', 'precision': 0.01724, 'type': 'double'}
double Uitrsensor1507::uiuss10tofdirect(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.017240;
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 16, 'name': 'uiuss11tofdirect', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'cm', 'precision': 0.01724, 'type': 'double'}
double Uitrsensor1507::uiuss11tofdirect(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.017240;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
