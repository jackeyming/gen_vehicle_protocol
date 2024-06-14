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

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/canbus/proto/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace hooke {

class Uitrsensor2508 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Uitrsensor2508();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 16, 'name': 'UiUss8ToFIndirect', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'cm', 'precision': 0.01724, 'type': 'double'}
  double uiuss8tofindirect(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 16, 'name': 'UiUss9ToFIndirect', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'cm', 'precision': 0.01724, 'type': 'double'}
  double uiuss9tofindirect(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'UiUss10ToFIndirect', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'cm', 'precision': 0.01724, 'type': 'double'}
  double uiuss10tofindirect(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 16, 'name': 'UiUss11ToFIndirect', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'cm', 'precision': 0.01724, 'type': 'double'}
  double uiuss11tofindirect(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


