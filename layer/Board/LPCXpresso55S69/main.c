/* -----------------------------------------------------------------------------
 * Copyright (c) 2020 Arm Limited (or its affiliates). All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * -------------------------------------------------------------------------- */

#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "board.h"
#include "pin_mux.h"
#include "main.h"

// Callbacks for USART2 Driver
uint32_t USART2_GetFreq   (void) { return CLOCK_GetFlexCommClkFreq(2U); }
void     USART2_InitPins  (void) { /* Done in BOARD_InitBootPins function */ }
void     USART2_DeinitPins(void) { /* Not implemented */ }

int main (void) {

  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitDebugConsole();

  SystemCoreClockUpdate();

  osKernelInitialize();                         // Initialize CMSIS-RTOS
  app_initialize();                             // Initialize application
  osKernelStart();                              // Start thread execution
  for (;;) {}
}
