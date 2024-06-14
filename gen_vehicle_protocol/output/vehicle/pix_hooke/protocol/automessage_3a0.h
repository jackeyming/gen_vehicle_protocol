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
namespace pix_hooke {

class Automessage3a0 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Automessage3a0();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 7, 'description': '自驾状态', 'enum': {0: 'AUTODRIVEMODE_AUTOPLIOT_MODE', 1: 'AUTODRIVEMODE_RECEIVED_A_REMOTE_REQUEST', 2: 'AUTODRIVEMODE_ALLOW_REMOTE_TAKEOVER', 3: 'AUTODRIVEMODE_AUTO_EMERGENCY_STOP'}, 'is_signed_var': False, 'len': 8, 'name': 'AutoDriveMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Automessage3a0* set_autodrivemode(Automessage_3a0::AutodrivemodeType autodrivemode);

  // config detail: {'bit': 63, 'description': '自动驾驶心跳包', 'enum': {}, 'is_signed_var': False, 'len': 8, 'name': 'AutoHeartbeat', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Automessage3a0* set_autoheartbeat(Automessage_3a0::AutoheartbeatType autoheartbeat);

 private:

  // config detail: {'bit': 7, 'description': '自驾状态', 'enum': {0: 'AUTODRIVEMODE_AUTOPLIOT_MODE', 1: 'AUTODRIVEMODE_RECEIVED_A_REMOTE_REQUEST', 2: 'AUTODRIVEMODE_ALLOW_REMOTE_TAKEOVER', 3: 'AUTODRIVEMODE_AUTO_EMERGENCY_STOP'}, 'is_signed_var': False, 'len': 8, 'name': 'AutoDriveMode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_autodrivemode(uint8_t* data, Automessage_3a0::AutodrivemodeType autodrivemode);

  // config detail: {'bit': 63, 'description': '自动驾驶心跳包', 'enum': {}, 'is_signed_var': False, 'len': 8, 'name': 'AutoHeartbeat', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_autoheartbeat(uint8_t* data, Automessage_3a0::AutoheartbeatType autoheartbeat);

 private:
  Automessage_3a0::AutodrivemodeType autodrivemode_;
  Automessage_3a0::AutoheartbeatType autoheartbeat_;
};

}  // namespace pix_hooke
}  // namespace canbus
}  // namespace apollo


