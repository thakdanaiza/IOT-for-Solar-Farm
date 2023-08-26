#include "Wire.h"
#include "Adafruit_INA219.h"

Adafruit_INA219 ina219_a;
Adafruit_INA219 ina219_b;

void setup() {
  Serial.begin(115200);
  Wire.begin(18, 19);
  Wire1.begin(21, 22);
  ina219_a.begin(&Wire);
  ina219_b.begin(&Wire1);

  Serial.print("BV");
  Serial.print("\t");  // Bus Voltage
  Serial.print("SV");
  Serial.print("\t");  // Shunt Voltage
  Serial.print("LV");
  Serial.print("\t");  // Load Voltage
  Serial.print("C");
  Serial.print("\t");  // Current
  Serial.print("P");
  Serial.print("\t");  // Power
  Serial.print("BV");
  Serial.print("\t");  // Bus Voltage
  Serial.print("SV");
  Serial.print("\t");  // Shunt Voltage
  Serial.print("LV");
  Serial.print("\t");  // Load Voltage
  Serial.print("C");
  Serial.print("\t");   // Current
  Serial.println("P");  // Power
}

void loop() {
  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  shuntvoltage = ina219_a.getShuntVoltage_mV();
  busvoltage = ina219_a.getBusVoltage_V();
  current_mA = ina219_a.getCurrent_mA();
  power_mW = ina219_a.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);

  Serial.print(busvoltage);
  Serial.print("\t");
  Serial.print(shuntvoltage);
  Serial.print("\t");
  Serial.print(loadvoltage);
  Serial.print("\t");
  Serial.print(current_mA);
  Serial.print("\t");
  Serial.print(power_mW);
  Serial.print("\t");

  shuntvoltage = ina219_b.getShuntVoltage_mV();
  busvoltage = ina219_b.getBusVoltage_V();
  current_mA = ina219_b.getCurrent_mA();
  power_mW = ina219_b.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);

  Serial.print(busvoltage);
  Serial.print("\t");
  Serial.print(shuntvoltage);
  Serial.print("\t");
  Serial.print(loadvoltage);
  Serial.print("\t");
  Serial.print(current_mA);
  Serial.print("\t");
  Serial.println(power_mW);
  delay(1000);
}