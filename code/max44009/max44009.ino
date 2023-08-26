#include "Wire.h"

#define Addr 0x4A

void setup() {

  // Initialise serial communication
  Serial.begin(115200);
  Wire.begin(21, 22);
  Wire.beginTransmission(Addr);
  Wire.write(0x02);
  Wire.write(0x40);
  Wire.endTransmission();
  
}

void loop() {
  unsigned int dataone[2];
  Wire.beginTransmission(Addr);
  Wire.write(0x03);
  Wire.endTransmission();

  // Request 2 bytes of data
  Wire.requestFrom(Addr, 2);

  // Read 2 bytes of data luminance msb, luminance lsb
  if (Wire.available() == 2) {
    dataone[0] = Wire.read();
    dataone[1] = Wire.read();
  }

  // Convert the data to lux
  int exponent = (dataone[0] & 0xF0) >> 4;
  int mantissa = ((dataone[0] & 0x0F) << 4) | (dataone[1] & 0x0F);
  float luminance = pow(2, exponent) * mantissa * 0.045;

  Serial.print("Ambient Light luminance 1 :");
  Serial.print(luminance);
  Serial.println(" lux");

  delay(500);
}