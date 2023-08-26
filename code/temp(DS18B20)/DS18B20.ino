
#include <OneWire.h>
#include <DallasTemperature.h>
#define DS18B20Pin 25 //กำหนดขาที่จะเชื่อมต่อ Sensor
OneWire oneWire(DS18B20Pin);
DallasTemperature sensors(&oneWire);
 
void setup(void) {
Serial.begin(9600);
Serial.println("Dallas Temperature IC Control Library");
sensors.begin();
}
 
void loop(void) {
Serial.println("Requesting temperatures...");
sensors.requestTemperatures(); //อ่านข้อมูลจาก library
Serial.print("Temperature is: ");
Serial.print(sensors.getTempCByIndex(0)); // แสดงค่า อูณหภูมิ 
Serial.println(" *C");
delay(1000);
}
