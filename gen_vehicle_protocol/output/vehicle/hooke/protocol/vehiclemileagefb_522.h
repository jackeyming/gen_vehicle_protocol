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

class Vehiclemileagefb522 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Vehiclemileagefb522();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'description': '总计里程', 'is_signed_var': False, 'len': 24, 'name': 'VehicleOdo', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1677721.5]', 'physical_unit': 'km', 'precision': 0.1, 'type': 'double'}
  double vehicleodo(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'description': '小计里程', 'is_signed_var': False, 'len': 24, 'name': 'VehicleSubMileage', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|167772.215]', 'physical_unit': 'km', 'precision': 0.001, 'type': 'double'}
  double vehiclesubmileage(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'description': '剩余里程', 'is_signed_var': False, 'len': 8, 'name': 'VcuRemainingMile', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'km', 'precision': 1.0, 'type': 'int'}
  int vcuremainingmile(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


