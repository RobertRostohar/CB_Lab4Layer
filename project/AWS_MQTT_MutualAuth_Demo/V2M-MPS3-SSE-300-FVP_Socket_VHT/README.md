AWS coreMQTT Mutual Authentication Demo
=======================================

This demo application connects to **AWS MQTT broker** using TLS with mutual authentication between the client and the server.
It demonstrates the subscribe-publish workflow of MQTT.

Visit [*coreMQTT mutual authentication demo*](https://docs.aws.amazon.com/freertos/latest/userguide/mqtt-demo-ma.html) for further information.

Please note, that [*properly configured thing*](https://docs.aws.amazon.com/iot/latest/developerguide/iot-moisture-create-thing.html) is required to
successfully run the demo application.

Configuration
-------------
In uVision open Project window, expand `Target` and `demos_include` group and locate files:
- `aws_clientcredential.h`
- `aws_clientcredential_keys.h`.

Modify the following definitions:
- `clientcredentialMQTT_BROKER_ENDPOINT`: Remote Host Address (AWS IoT->Settings in AWS IoT console)
- `clientcredentialIOT_THING_NAME`: Thing Name (AWS IoT->Manage->Things->Name in AWS IoT console)
- `clientcredentialWIFI_SSID`: WiFi Access Point SSID (when connecting via WiFi, can be empty otherwise)
- `clientcredentialWIFI_PASSWORD`: WiFi Access Point Password (when connecting via WiFi, can be empty otherwise)
- `keyCLIENT_CERTIFICATE_PEM`: Client Certificate
- `keyCLIENT_PRIVATE_KEY_PEM`: Client Private Key

Once the application is configured you can:
- Build the application.
- Connect and configure the debugger.
- Run the application and view messages in a debug printf or terminal window.

MQTT messages can be viewed in the [**AWS IoT console**](https://docs.aws.amazon.com/iot/latest/developerguide/view-mqtt-messages.html).

Socket: VHT IoT Socket
-----------------------
This implementation uses an [IoT socket](https://mdk-packs.github.io/IoT_Socket/html/index.html) layer that connects to a 
[Arm Virtual Hardware](https://www.arm.com/products/development-tools/simulation/virtual-hardware).

Interface: AWS Socket
---------------------

The AWS Socket interface exposes [Secure Sockets](https://docs.aws.amazon.com/freertos/latest/userguide/secure-sockets.html) and
connects to [IoT socket](https://mdk-packs.github.io/IoT_Socket/html/index.html).

Board: ARM V2M-MPS3-SSE-300-FVP
----------------------------------------------

MPS3 platform for Corstone-300 simulated by Fixed Virtual Platform (FVP).

Running the FVP in uVision requires the following settings:
 - open "Options for Target"
 - select "Debug" tab
 - under "Use" select "Models ARMv8-M Debugger" and click "Settings" end enter the following:
   - Command: C:\Program Files\ARM\FVP_Corstone_SSE-300\models\Win64_VC2017\FVP_Corstone_SSE-300_Ethos-U55.exe (when FVP is installed in default directory)
   - Target: cpu0
   - Configuration File: fvp_config.txt

Running the FVP via command line (from project root directory and FVP executable in path):
 - `FVP_Corstone_SSE-300_Ethos-U55.exe -a Objects\image.axf` when using telnet as UART0 output or
 - `FVP_Corstone_SSE-300_Ethos-U55.exe -C mps3_board.telnetterminal0.start_telnet=0 -C mps3_board.uart0.out_file=- -a Objects\image.axf` when using stdout as UART0 output

The heap/stack setup and the CMSIS-Driver assignment is in configuration files of related software components.

### System Configuration

| System Component        | Setting
|:------------------------|:----------------------------------------
| Device                  | SSE-3000-MPS3
| Clock                   | 32 MHz
| Heap                    | 64 kB (configured in region_limit.h file)
| Stack (MSP)             | 1 kB (configured in region_limit.h file)

**STDIO** is routed to USART0

### CMSIS-Driver mapping

| CMSIS-Driver | Peripheral
|:-------------|:----------
| ETH_MAC0     | Ethernet LAN91C111
| ETH_PHY0     | Ethernet LAN91C111
| USART0       | USART0

| CMSIS-Driver VIO  | Physical board hardware
|:------------------|:-----------------------
| vioBUTTON0        | User Button PB1
| vioBUTTON1        | User Button PB2
| vioLED0           | User LED UL0
| vioLED1           | User LED UL1
| vioLED2           | User LED UL2
| vioLED3           | User LED UL3
| vioLED4           | User LED UL4
| vioLED5           | User LED UL5
| vioLED6           | User LED UL6
| vioLED7           | User LED UL7
