# M5StickC Battery Monitor

- Reports battery status on serial ports and LCD.
- Needs a 3.3V compatible serial module on the receiving end for testing discharging.
- Only the output pin (defined in serial_TX_pin) and GND needs to be connected.
- Needs [not yet released AXP library](https://github.com/m5stack/M5StickC) and [Coulomb counter fix](https://github.com/m5stack/M5StickC/pull/93) for correct values.
