# Test Plan

## Unit tests

- PID parity generation
- PID corruption rejection
- Classic/enhanced checksum
- Frame encode/decode round trip
- Bad checksum rejection
- Signal clamping/scaling
- Diagnostic command handling

## Hardware validation

After HAL integration validate LIN timing, break/sync/header capture, transceiver dominant/recessive levels, master interoperability, timeout handling, PWM output, bus wake/sleep, and EMC/ESD behavior.

No physical timing or EMC result is claimed by this repository.