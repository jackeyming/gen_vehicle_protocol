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

#include "modules/canbus/vehicle/hooke/hooke_message_manager.h"

#include "modules/canbus/vehicle/hooke/protocol/automessage_3a0.h"
#include "modules/canbus/vehicle/hooke/protocol/brakecommand_101.h"
#include "modules/canbus/vehicle/hooke/protocol/gearcommand_103.h"
#include "modules/canbus/vehicle/hooke/protocol/parkcommand_104.h"
#include "modules/canbus/vehicle/hooke/protocol/steeringcommand_102.h"
#include "modules/canbus/vehicle/hooke/protocol/throttlecommand_100.h"
#include "modules/canbus/vehicle/hooke/protocol/vehiclemodecommand_105.h"

#include "modules/canbus/vehicle/hooke/protocol/bcmmessage4_5f4.h"
#include "modules/canbus/vehicle/hooke/protocol/bcmmessage5_5f5.h"
#include "modules/canbus/vehicle/hooke/protocol/bmsreport_512.h"
#include "modules/canbus/vehicle/hooke/protocol/brakereport_501.h"
#include "modules/canbus/vehicle/hooke/protocol/gearreport_503.h"
#include "modules/canbus/vehicle/hooke/protocol/parkreport_504.h"
#include "modules/canbus/vehicle/hooke/protocol/remotemessage_3b0.h"
#include "modules/canbus/vehicle/hooke/protocol/steeringreport_502.h"
#include "modules/canbus/vehicle/hooke/protocol/throttlereport_500.h"
#include "modules/canbus/vehicle/hooke/protocol/uitrsensor1_507.h"
#include "modules/canbus/vehicle/hooke/protocol/uitrsensor2_508.h"
#include "modules/canbus/vehicle/hooke/protocol/uitrsensor3_509.h"
#include "modules/canbus/vehicle/hooke/protocol/uitrsensor4_510.h"
#include "modules/canbus/vehicle/hooke/protocol/uitrsensor5_511.h"
#include "modules/canbus/vehicle/hooke/protocol/vcureport1_505.h"
#include "modules/canbus/vehicle/hooke/protocol/vcutransfer_53b.h"
#include "modules/canbus/vehicle/hooke/protocol/vehicledoorreport_519.h"
#include "modules/canbus/vehicle/hooke/protocol/vehiclemileagefb_522.h"
#include "modules/canbus/vehicle/hooke/protocol/vinresp1_514.h"
#include "modules/canbus/vehicle/hooke/protocol/vinresp2_515.h"
#include "modules/canbus/vehicle/hooke/protocol/vinresp3_516.h"
#include "modules/canbus/vehicle/hooke/protocol/wheelspeedreport_506.h"

namespace apollo {
namespace canbus {
namespace hooke {

HookeMessageManager::HookeMessageManager() {
  // Control Messages
  AddSendProtocolData<Automessage3a0, true>();
  AddSendProtocolData<Brakecommand101, true>();
  AddSendProtocolData<Gearcommand103, true>();
  AddSendProtocolData<Parkcommand104, true>();
  AddSendProtocolData<Steeringcommand102, true>();
  AddSendProtocolData<Throttlecommand100, true>();
  AddSendProtocolData<Vehiclemodecommand105, true>();

  // Report Messages
  AddRecvProtocolData<Bcmmessage45f4, true>();
  AddRecvProtocolData<Bcmmessage55f5, true>();
  AddRecvProtocolData<Bmsreport512, true>();
  AddRecvProtocolData<Brakereport501, true>();
  AddRecvProtocolData<Gearreport503, true>();
  AddRecvProtocolData<Parkreport504, true>();
  AddRecvProtocolData<Remotemessage3b0, true>();
  AddRecvProtocolData<Steeringreport502, true>();
  AddRecvProtocolData<Throttlereport500, true>();
  AddRecvProtocolData<Uitrsensor1507, true>();
  AddRecvProtocolData<Uitrsensor2508, true>();
  AddRecvProtocolData<Uitrsensor3509, true>();
  AddRecvProtocolData<Uitrsensor4510, true>();
  AddRecvProtocolData<Uitrsensor5511, true>();
  AddRecvProtocolData<Vcureport1505, true>();
  AddRecvProtocolData<Vcutransfer53b, true>();
  AddRecvProtocolData<Vehicledoorreport519, true>();
  AddRecvProtocolData<Vehiclemileagefb522, true>();
  AddRecvProtocolData<Vinresp1514, true>();
  AddRecvProtocolData<Vinresp2515, true>();
  AddRecvProtocolData<Vinresp3516, true>();
  AddRecvProtocolData<Wheelspeedreport506, true>();
}

HookeMessageManager::~HookeMessageManager() {}

}  // namespace hooke
}  // namespace canbus
}  // namespace apollo
