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

class Parkcommand104 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Parkcommand104();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 0, 'description': '驻车使能', 'enum': {0: 'PARKENCTRL_DISABLE', 1: 'PARKENCTRL_ABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ParkEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Parkcommand104* set_parkenctrl(Parkcommand_104::ParkenctrlType parkenctrl);

  // config detail: {'bit': 8, 'description': '驻车指令', 'enum': {0: 'PARKTARGET_RELEASE', 1: 'PARKTARGET_PARKINGTRIGGER'}, 'is_signed_var': False, 'len': 1, 'name': 'ParkTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Parkcommand104* set_parktarget(Parkcommand_104::ParktargetType parktarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum104', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Parkcommand104* set_checksum104(int checksum104);

 private:

  // config detail: {'bit': 0, 'description': '驻车使能', 'enum': {0: 'PARKENCTRL_DISABLE', 1: 'PARKENCTRL_ABLE'}, 'is_signed_var': False, 'len': 1, 'name': 'ParkEnCtrl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_parkenctrl(uint8_t* data, Parkcommand_104::ParkenctrlType parkenctrl);

  // config detail: {'bit': 8, 'description': '驻车指令', 'enum': {0: 'PARKTARGET_RELEASE', 1: 'PARKTARGET_PARKINGTRIGGER'}, 'is_signed_var': False, 'len': 1, 'name': 'ParkTarget', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  void set_p_parktarget(uint8_t* data, Parkcommand_104::ParktargetType parktarget);

  // config detail: {'bit': 63, 'description': '循环计数', 'is_signed_var': False, 'len': 8, 'name': 'CheckSum104', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_checksum104(uint8_t* data, int checksum104);

 private:
  Parkcommand_104::ParkenctrlType parkenctrl_;
  Parkcommand_104::ParktargetType parktarget_;
  int checksum104_;
};

}  // namespace pix_hooke
}  // namespace canbus
}  // namespace apollo


