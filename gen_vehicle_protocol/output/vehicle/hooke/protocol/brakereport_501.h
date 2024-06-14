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

class Brakereport501 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Brakereport501();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 1, 'description': '制动状态', 'is_signed_var': False, 'len': 2, 'name': 'BrakeEnState', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int brakeenstate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'description': '制动故障信息1', 'is_signed_var': False, 'len': 8, 'name': 'BrakeFlt1', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int brakeflt1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'description': '制动故障信息2', 'is_signed_var': False, 'len': 8, 'name': 'BrakeFlt2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int brakeflt2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'description': '制动踏板位置反馈', 'is_signed_var': False, 'len': 16, 'name': 'BrakePedalActual', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.1, 'type': 'double'}
  double brakepedalactual(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


