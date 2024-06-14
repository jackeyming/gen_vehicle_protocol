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

class Bcmmessage45f4 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Bcmmessage45f4();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 8, 'description': '交流充L线温度', 'is_signed_var': False, 'len': 8, 'name': 'Ltemp', 'offset': -40.0, 'order': 'intel', 'physical_range': '[-40|215]', 'physical_unit': '℃', 'precision': 1.0, 'type': 'int'}
  int ltemp(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'description': '交流充N线温度', 'is_signed_var': False, 'len': 8, 'name': 'Ntemp', 'offset': -40.0, 'order': 'intel', 'physical_range': '[-40|215]', 'physical_unit': '℃', 'precision': 1.0, 'type': 'int'}
  int ntemp(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 24, 'description': '前左安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'SafeBeltSta1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool safebeltsta1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'description': '前中安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'SafeBeltSta2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool safebeltsta2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 26, 'description': '前右安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'SafeBeltSta3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool safebeltsta3(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 27, 'description': '后左安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'SafeBeltSta4', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool safebeltsta4(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 28, 'description': '后中安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'SafeBeltSta5', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool safebeltsta5(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 29, 'description': '后右安全带状态', 'is_signed_var': False, 'len': 1, 'name': 'SafeBeltSta6', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool safebeltsta6(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 30, 'description': '前左座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'SeatSta1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool seatsta1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'description': '前中座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'SeatSta2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool seatsta2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'description': '前右座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'SeatSta3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool seatsta3(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 33, 'description': '后左座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'SeatSta4', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool seatsta4(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 34, 'description': '后中座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'SeatSta5', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool seatsta5(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 35, 'description': '后右座椅状态', 'is_signed_var': False, 'len': 1, 'name': 'SeatSta6', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool seatsta6(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 36, 'description': '开关量输入口13', 'is_signed_var': False, 'len': 1, 'name': 'IoIn13', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ioin13(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 37, 'description': '开关量输入口14', 'is_signed_var': False, 'len': 1, 'name': 'IoIn14', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ioin14(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 38, 'description': '开关量输入口15', 'is_signed_var': False, 'len': 1, 'name': 'IoIn15', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ioin15(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'description': '开关量输入口16', 'is_signed_var': False, 'len': 1, 'name': 'IoIn16', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ioin16(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'description': '电流型输入口1', 'is_signed_var': False, 'len': 1, 'name': 'IoCur1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool iocur1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 41, 'description': '电流型输入口2', 'is_signed_var': False, 'len': 1, 'name': 'IoCur2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool iocur2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'description': '电流型输入口3', 'is_signed_var': False, 'len': 1, 'name': 'IoCur3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool iocur3(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 43, 'description': '电流型输入口4', 'is_signed_var': False, 'len': 1, 'name': 'IoCur4', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool iocur4(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 44, 'description': '电流型传感器输入口', 'is_signed_var': False, 'len': 1, 'name': 'AdCVin', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|20]', 'physical_unit': 'mV', 'precision': 1.0, 'type': 'bool'}
  bool adcvin(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 46, 'description': '电压型传感器输入口4(0~10V)', 'is_signed_var': False, 'len': 10, 'name': 'AdVVin5', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10000]', 'physical_unit': 'mV', 'precision': 10.0, 'type': 'double'}
  double advvin5(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo


