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

class Bmsreport512 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Bmsreport512();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'description': '电池电压', 'is_signed_var': False, 'len': 16, 'name': 'BatteryVoltage', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|300]', 'physical_unit': 'V', 'precision': 0.01, 'type': 'double'}
  double batteryvoltage(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'description': '电池电流', 'is_signed_var': True, 'len': 16, 'name': 'BatteryCurrent', 'offset': -3200.0, 'order': 'motorola', 'physical_range': '[-3200|3353.5]', 'physical_unit': 'A', 'precision': 0.1, 'type': 'double'}
  double batterycurrent(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'description': '电池SOC', 'is_signed_var': False, 'len': 8, 'name': 'BatterySoc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
  int batterysoc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'BatteryLeadacidVoltage', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'V', 'precision': 1.0, 'type': 'int'}
  int batteryleadacidvoltage(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


