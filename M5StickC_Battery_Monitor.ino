/*

    M5StickC Battery Monitor

    Reports battery status on serial port and LCD.
    Needs a 3.3V compatible serial module on the receiving end.
    Only the output pin (defined in serial_TX_pin) and GND
    needs to be connected.

    Copyright (C) 2020 MDE
    Licensed under the GNU GPLv3
*/

#include <M5StickC.h>


#define serial_RX_pin   26
#define serial_TX_pin   0


void setup() {
    M5.begin();
    M5.Axp.EnableCoulombcounter();

    Serial1.begin(115200, SERIAL_8N1, 26, 0);
    Serial1.printf("\r\nM5StickC Battery Monitor\r\n");
}


void loop() {
    Serial1.printf("GetBatState: %d\r\n", M5.Axp.GetBatState());
    Serial1.printf("GetCoulombchargeData: %ld\r\n", M5.Axp.GetCoulombchargeData());
    Serial1.printf("GetCoulombdischargeData: %ld\r\n", M5.Axp.GetCoulombdischargeData());
    Serial1.printf("GetCoulombData: %.4f\r\n", M5.Axp.GetCoulombData());
    Serial1.printf("\r\n");
    Serial1.printf("GetBatVoltage: %.4f\r\n", M5.Axp.GetBatVoltage());
    Serial1.printf("GetBatCurrent: %.4f\r\n", M5.Axp.GetBatCurrent());
    Serial1.printf("GetVinVoltage: %.4f\r\n", M5.Axp.GetVinVoltage());
    Serial1.printf("GetVinCurrent: %.4f\r\n", M5.Axp.GetVinCurrent());
    Serial1.printf("GetVBusVoltage: %.4f\r\n", M5.Axp.GetVBusVoltage());
    Serial1.printf("GetVBusCurrent: %.4f\r\n", M5.Axp.GetVBusCurrent());
    Serial1.printf("\r\n");
    Serial1.printf("GetTempInAXP192: %.1fC\r\n", M5.Axp.GetTempInAXP192());
    Serial1.printf("\r\n");

    Serial1.printf("GetBatPower: %.4f\r\n", M5.Axp.GetBatPower());
    Serial1.printf("GetBatChargeCurrent: %.4f\r\n", M5.Axp.GetBatChargeCurrent());
    Serial1.printf("GetAPSVoltage: %.4f\r\n", M5.Axp.GetAPSVoltage());
    Serial1.printf("GetBatCoulombInput: %.4f\r\n", M5.Axp.GetBatCoulombInput());
    Serial1.printf("GetBatCoulombOut: %.4f\r\n", M5.Axp.GetBatCoulombOut());
    Serial1.printf("\r\n");
    Serial1.printf("GetWarningLevel: %d\r\r\n", M5.Axp.GetWarningLevel());
    Serial1.printf("-----\r\n");

    delay(1000);
}
