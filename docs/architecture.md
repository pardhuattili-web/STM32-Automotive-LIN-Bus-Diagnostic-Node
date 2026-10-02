# Architecture

The implementation separates the LIN transport/protocol layer from application signals and diagnostics.

```
USART/LIN HW
    |
lin_protocol
    |
lin_node ---- signal_db
    |
diagnostics
```

The protocol module owns protected-ID and checksum rules. The signal database owns application scaling/packing. The node layer owns state and error counters.

For hardware integration, connect an STM32 USART with LIN support to an automotive LIN transceiver. PWM/ADC integration is intentionally board-specific.