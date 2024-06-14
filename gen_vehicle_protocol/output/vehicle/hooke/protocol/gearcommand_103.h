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

class Gearcommand103 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Gearcommand103();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 0, 'description': '档位控制使能', 'is_signed_var': False, 'len': 1, 'name': 'GearEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Gearcommand103* set_gearenctrl(bool gearenctrl);

  // config detail: {'bit': 10, 'description': '目标档位', 'is_signed_var': False, 'len': 3, 'name': 'GearTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Gearcommand103* set_geartarget(int geartarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum103', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Gearcommand103* set_checksum103(int checksum103);

 private:

  // config detail: {'bit': 0, 'description': '档位控制使能', 'is_signed_var': False, 'len': 1, 'name': 'GearEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_gearenctrl(uint8_t* data, bool gearenctrl);

  // config detail: {'bit': 10, 'description': '目标档位', 'is_signed_var': False, 'len': 3, 'name': 'GearTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_geartarget(uint8_t* data, int geartarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum103', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_checksum103(uint8_t* data, int checksum103);

 private:
  bool gearenctrl_;
  int geartarget_;
  int checksum103_;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


