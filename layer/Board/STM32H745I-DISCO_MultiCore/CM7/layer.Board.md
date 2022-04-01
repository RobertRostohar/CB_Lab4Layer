Board: STMicroelectronics STM32H745I-DISCO
------------------------------------------

The tables below list the device configuration for this board.

The heap/stack setup is in configuration files of related software components.

The example project can be re-configured to work on custom hardware. Refer to ["Migrate STM32 Based Example Projects to Custom Hardware"](https://github.com/MDK-Packs/Documentation/tree/master/Porting_to_Custom_Hardware) for information. 

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | STM32H745XIHx
| ICACHE                  | enabled
| DCACHE                  | enabled
| Heap                    | 64 kB (configured in startup file)
| Stack (MSP)             | 1 kB (configured in startup file)

### Clock Configuration

| Clock                   | Setting
|:------------------------|:----------------------------------------
| SYSCLK                  | 480 MHz (Cortex-M7 CPU Clock)
| HCLK                    | 240 MHz (Cortex-M4 CPU, Bus matrix Clocks)
| APB1                    | 120 MHz
| APB2                    | 120 MHz
| APB3                    | 120 MHz
| To USART1               | 120 MHz
| To USART3               | 120 MHz
| To SPI2                 | 192 MHz

### GPIO Configuration and usage

| GPIO          | Signal / Label | GPIO Settings                                 | Usage
|:--------------|:---------------|:----------------------------------------------|:-----
| PB11          | USART3_RX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_RX)
| PB10          | USART3_TX      | Alternate Function, Speed=Very High           | ST-LINK Virtual COM port (T_VCP_TX)
| PB7           | USART1_RX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D0 (RX)
| PB6           | USART1_TX      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D1 (TX)
| PI2           | SPI2_MISO      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D12 (MISO)
| PB15          | SPI2_MOSI      | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D11 (MOSI)
| PD3           | SPI2_SCK       | Alternate Function, Speed=Very High           | Arduino UNO R3 pin D13 (SCK)
| PH15          | ARDUINO_IO_D9  | Input mode                                    | Arduino UNO R3 pin D9
| PB4           | ARDUINO_IO_D10 | Output Push Pull, Level=High, Speed=Very High | Arduino UNO R3 pin D10
| PC14-OSC32_IN | RCC_OSC32_IN   |                                               | External Oscillator (LSE)
| PH0-OSC_IN    | RCC_OSC_IN     |                                               | External Oscillator (HSE)
| PC13          | vioBUTTON0     | not configured via CubeMX                     | Button USER
| PI13          | vioLED0        | not configured via CubeMX                     | LD6 Red
| PJ2           | vioLED1        | not configured via CubeMX                     | LD7 Green

### NVIC Configuration

 - Priority Group = 4 bits for preemption priority 0 bits for subpriority

| NVIC Interrupt                          | Preempt Priority | Code Generation
|:----------------------------------------|:-----------------|:---------------
| Non maskable interrupt                  | 0                | Generate IRQ handler
| Hard fault interrupt                    | 0                | Generate IRQ handler
| Memory Management fault                 | 0                | Generate IRQ handler
| Prefetch fault, memory access fault     | 0                | Generate IRQ handler
| Undefined instruction or illegal state  | 0                | Generate IRQ handler
| System service call via SWI instruction | 0                | none
| Debug monitor                           | 0                | Generate IRQ handler
| Pendable request for system service     | 0                | none
| Time base: System tick timer            | 0                | none
| DMA1 stream0 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| DMA1 stream1 global interrupt           | 8                | Generate IRQ handler, Call HAL handler
| USART1 global interrupt                 | 8                | Generate IRQ handler, Call HAL handler
| SPI2 global                             | 8                | Generate IRQ handler, Call HAL handler

### Connectivity Peripherals Configuration

| Peripheral   | Mode / Settings                                                                                                    | IRQ | DMA                                              | Note
|:-------------|:-------------------------------------------------------------------------------------------------------------------|:----|:-------------------------------------------------|:----
| SPI2         | Full-Duplex Master, Hardware NSS Signal=off, Do Not Generate Initialization Function Call                          | yes | SPI2_RX = DMA1 Stream 0, SPI2_TX = DMA1 Stream 1 | Arduino UNO R3 connector (CN2)
| USART1       | Asynchronous, Hardware Flow Control=off, Do Not Generate Initialization Function Call                              | yes | no                                               | Arduino UNO R3 connector (CN6)
| USART3       | Asynchronous, Hardware Flow Control=off, Baud Rate: 115200 Bits/s, Word Length: 8 Bits, Parity: None, Stop Bits: 1 | no  | no                                               | ST-LINK Virtual COM port

**STDIO** is routed to ST-LINK Virtual COM port (USART3)

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| SPI2         | SPI2
| USART1       | USART1
| USART3       | USART3

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | Button USER (PC13)
| vioLED0           | LD6 RED (PJ2)
| vioLED1           | LD7 GREEN (PI13)
