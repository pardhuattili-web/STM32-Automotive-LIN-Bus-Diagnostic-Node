# LIN Frame Examples

## Master -> actuator command

ID `0x13`, payload `0x41` represents a 65% target duty in this project-local signal map.

## Slave -> temperature report

ID `0x22`, two-byte signed temperature using °C × 100.

These examples are deliberately project-local and are not an OEM-specific LIN database.