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

class Vehicledoorreport519 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Vehicledoorreport519();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 0, 'description': '开门中', 'is_signed_var': False, 'len': 1, 'name': 'DoorOpenSta', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool dooropensta(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 1, 'description': '关门中', 'is_signed_var': False, 'len': 1, 'name': 'DoorCloseSta', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool doorclosesta(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 2, 'description': '开门到位', 'is_signed_var': False, 'len': 1, 'name': 'DoorOpenInplace', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool dooropeninplace(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'description': '关门到位', 'is_signed_var': False, 'len': 1, 'name': 'DoorCloseInplace', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool doorcloseinplace(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 4, 'description': '开门故障', 'is_signed_var': False, 'len': 1, 'name': 'DoorOpenTimeout', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool dooropentimeout(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 5, 'description': '关门故障', 'is_signed_var': False, 'len': 1, 'name': 'DoorCloseTimeout', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool doorclosetimeout(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 6, 'description': '门按钮使能状态', 'is_signed_var': False, 'len': 1, 'name': 'DoorButtonEnable', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool doorbuttonenable(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'is_signed_var': False, 'len': 2, 'name': 'DoorReportSta', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int doorreportsta(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


