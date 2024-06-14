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

class Bcmmessage55f5 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Bcmmessage55f5();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 0, 'description': '电阻型传感器输入口1', 'is_signed_var': False, 'len': 8, 'name': 'AdRVin1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': 'Ω', 'precision': 2.0, 'type': 'double'}
  double adrvin1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'description': '电阻型传感器输入口2', 'is_signed_var': False, 'len': 8, 'name': 'AdRVin2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': 'Ω', 'precision': 2.0, 'type': 'double'}
  double adrvin2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'description': '电阻型传感器输入口3', 'is_signed_var': False, 'len': 8, 'name': 'AdRVin3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': 'Ω', 'precision': 2.0, 'type': 'double'}
  double adrvin3(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 24, 'description': '电阻型传感器输入口4', 'is_signed_var': False, 'len': 8, 'name': 'AdRVin4', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|500]', 'physical_unit': 'Ω', 'precision': 2.0, 'type': 'double'}
  double adrvin4(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'description': '电压型传感器输入口1(烟雾传感器）', 'is_signed_var': False, 'len': 10, 'name': 'AdVVin1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3500]', 'physical_unit': 'mV', 'precision': 5.0, 'type': 'double'}
  double advvin1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'description': '电压型传感器输入口2（CO2传感器）', 'is_signed_var': False, 'len': 10, 'name': 'AdVVin2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3500]', 'physical_unit': 'mV', 'precision': 5.0, 'type': 'double'}
  double advvin2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 52, 'description': '电压型传感器输入口3', 'is_signed_var': False, 'len': 10, 'name': 'AdVVin3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3500]', 'physical_unit': 'mV', 'precision': 5.0, 'type': 'double'}
  double advvin3(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


