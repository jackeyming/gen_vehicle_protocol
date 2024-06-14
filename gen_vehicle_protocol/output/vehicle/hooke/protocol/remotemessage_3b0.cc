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

#include "modules/canbus/vehicle/hooke/protocol/remotemessage_3b0.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace hooke {

using ::apollo::drivers::canbus::Byte;

Remotemessage3b0::Remotemessage3b0() {}
const int32_t Remotemessage3b0::ID = 0x3B0;

void Remotemessage3b0::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_hooke()->mutable_remotemessage_3b0()->set_remotedrivemode(remotedrivemode(bytes, length));
  chassis->mutable_hooke()->mutable_remotemessage_3b0()->set_remoteheartbeat(remoteheartbeat(bytes, length));
}

// config detail: {'bit': 7, 'description': '远控状态', 'is_signed_var': False, 'len': 8, 'name': 'remotedrivemode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Remotemessage3b0::remotedrivemode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 63, 'description': '远控心跳包', 'is_signed_var': False, 'len': 8, 'name': 'remoteheartbeat', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Remotemessage3b0::remoteheartbeat(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
