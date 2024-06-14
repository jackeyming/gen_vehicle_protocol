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

class Automessage3a0 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Automessage3a0();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 7, 'description': '自驾状态', 'is_signed_var': False, 'len': 8, 'name': 'AutoDriveMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Automessage3a0* set_autodrivemode(int autodrivemode);

  // config detail: {'bit': 63, 'description': '自动驾驶心跳包', 'is_signed_var': False, 'len': 8, 'name': 'AutoHeartbeat', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Automessage3a0* set_autoheartbeat(int autoheartbeat);

 private:

  // config detail: {'bit': 7, 'description': '自驾状态', 'is_signed_var': False, 'len': 8, 'name': 'AutoDriveMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_autodrivemode(uint8_t* data, int autodrivemode);

  // config detail: {'bit': 63, 'description': '自动驾驶心跳包', 'is_signed_var': False, 'len': 8, 'name': 'AutoHeartbeat', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_autoheartbeat(uint8_t* data, int autoheartbeat);

 private:
  int autodrivemode_;
  int autoheartbeat_;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


