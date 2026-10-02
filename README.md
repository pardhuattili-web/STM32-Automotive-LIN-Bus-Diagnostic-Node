# STM32 Automotive LIN Bus Diagnostic Node

A reference STM32 embedded implementation of an automotive LIN slave node. The firmware models a realistic body-electronics ECU: it receives LIN headers, validates protected identifiers and checksums, updates a small signal database, controls a PWM actuator, and exposes diagnostic information through a compact service layer.

> **Validation note:** Software/reference implementation. Real LIN timing, transceiver behavior, EMC robustness, and electrical validation require an STM32 board, a LIN transceiver, and physical measurement.

## Architecture
```
LIN Transceiver -> LIN Driver -> Frame Parser -> Signal Database
                                      |              |
                                      +-> Diagnostics -> Actuator Control
```

## Features

- LIN 2.x-style frame handling
- STM32 UART/LIN driver abstraction
- Protected identifier validation
- Classic/enhanced checksum support
- Frame timeout/error detection
- Typed signal database
- Temperature, switch and actuator signals
- PWM actuator control
- Diagnostic request/response layer
- Error counters and fault injection
- Host-side Python LIN test utility
- Unit tests for PID, checksum and signal encoding

## Example signal map

| ID | Direction | Signal | Encoding |
|---|---|---|---|
| 0x12 | Master -> Slave | Cabin switch states | bitmap |
| 0x13 | Master -> Slave | Target actuator duty | 0-100% |
| 0x22 | Slave -> Master | Temperature | °C × 100 |
| 0x23 | Slave -> Master | Actuator state | enum |
| 0x24 | Slave -> Master | Fault/status | bitmap |

These are project-local demonstration IDs, not an OEM database.

## Diagnostics

Example commands:
```text
0x01 READ_STATUS
0x02 READ_ERRORS
0x03 CLEAR_ERRORS
0x10 SET_ACTUATOR
```

## LIN concepts demonstrated

- Break/sync/header handling
- 6-bit ID plus P0/P1 protected identifier
- Classic and enhanced checksum calculation
- Frame timeout/error path
- Signal packing/unpacking

## Build

Designed for STM32CubeIDE + HAL. Recommended hardware:

- STM32F103 / STM32G0-class MCU
- USART with LIN capability
- LIN transceiver such as a TJA102x-class device
- GPIO inputs
- PWM-capable timer
- ADC input

Cube-generated startup and HAL files are intentionally not committed because they depend on the selected MCU and pinout.

## Testing

```bash
python tools/lin_test.py --demo
```

Unit-test sources are under `test/`.

## Validation status

Software-level protocol tests are provided. Physical LIN timing, wake/sleep behavior, EMC/ESD performance, transceiver characteristics, and actuator electrical behavior still require hardware validation.

## License

MIT
