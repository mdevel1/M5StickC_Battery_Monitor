/*
 *  M5StickC Battery Monitor
 *
 *  Reports battery status on serial ports and LCD.
 *  Needs a 3.3V compatible serial module on the receiving end.
 *  Only the output pin (defined in serial_TX_pin) and GND
 *  needs to be connected.
 *
 *  Copyright (C) 2020 MDE
 *  Licensed under the GNU GPLv3
 */


#include <M5StickC.h>


#define serial_RX_pin   26
#define serial_TX_pin   0


#define log_serial(...) \
    Serial.printf(__VA_ARGS__); \
    Serial1.printf(__VA_ARGS__);


#define log_all(...) \
    M5.Lcd.printf(__VA_ARGS__); \
    log_serial(__VA_ARGS__);


void setup() {
    M5.begin();
    M5.Axp.EnableCoulombcounter();

    Serial.begin(115200);
    Serial1.begin(115200, SERIAL_8N1, 26, 0);
    log_serial("\r\nM5StickC Battery Monitor\r\n");
}


void loop() {
    log_all("BatU:%8.3f\r\n", M5.Axp.GetBatVoltage());
    log_all("BatI:%8.3f\r\n", M5.Axp.GetBatCurrent());
    log_all("VinU:%8.3f\r\n", M5.Axp.GetVinVoltage());
    log_all("VinI:%8.3f\r\n", M5.Axp.GetVinCurrent());
    log_all("VBusU:%7.3f\r\n", M5.Axp.GetVBusVoltage());
    log_all("VBusI:%7.3f\r\n", M5.Axp.GetVBusCurrent());
    log_serial("\r\n");
    log_all("TInAXP: %.1fC\r\n", M5.Axp.GetTempInAXP192());
    log_serial("\r\n");
    log_all("BatP: %7.3f\r\n", M5.Axp.GetBatPower());
    log_all("BatChargeI: %14.3f\r\n", M5.Axp.GetBatChargeCurrent());
    log_all("APSU: %7.3f\r\n", M5.Axp.GetAPSVoltage());
    log_all("BatCoulombIn:%13.3f\r\n", M5.Axp.GetBatCoulombInput());
    log_all("BatCoulombOut:%12.3f\r\n", M5.Axp.GetBatCoulombOut());
    log_serial("CoulombchargeData: %ld\r\n", M5.Axp.GetCoulombchargeData());
    log_serial("CoulombdischargeData: %ld\r\n", M5.Axp.GetCoulombdischargeData());
    log_all("CoulombData: %13.3f\r\n", M5.Axp.GetCoulombData());
    log_serial("\r\n");
    log_all("BatState:%4d\r\n", M5.Axp.GetBatState());
    log_all("WarningLevel:%13d\r\r\n", M5.Axp.GetWarningLevel());

    log_serial("-----\r\n");
    M5.Lcd.setCursor(0, 0);

    delay(1000);
}
