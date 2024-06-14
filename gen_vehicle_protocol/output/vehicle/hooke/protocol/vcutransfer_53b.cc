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

#include "modules/canbus/vehicle/hooke/protocol/vcutransfer_53b.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Vcutransfer53b::Vcutransfer53b() {}
const int32_t Vcutransfer53b::ID = 0x53B;

void Vcutransfer53b::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_vcutransfer_53b()->set_vcupadautostart(vcupadautostart(bytes, length));
  chassis->mutable_hooke()->mutable_vcutransfer_53b()->set_acouttemp(acouttemp(bytes, length));
  chassis->mutable_hooke()->mutable_vcutransfer_53b()->set_acintemp(acintemp(bytes, length));
}

// config detail: {'bit': 4, 'description': 'PAD自动驾驶启动按钮', 'is_signed_var': False, 'len': 1, 'name': 'vcupadautostart', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcutransfer53b::vcupadautostart(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 47, 'description': '车外温度', 'is_signed_var': True, 'len': 8, 'name': 'acouttemp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-128|127]', 'physical_unit': '℃', 'precision': 1.0, 'type': 'int'}
int Vcutransfer53b::acouttemp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  x <<= 24;
  x >>= 24;

  int ret = x;
  return ret;
}

// config detail: {'bit': 55, 'description': '车内温度', 'is_signed_var': True, 'len': 8, 'name': 'acintemp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-128|127]', 'physical_unit': '℃', 'precision': 1.0, 'type': 'int'}
int Vcutransfer53b::acintemp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  x <<= 24;
  x >>= 24;

  int ret = x;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
