int sensor = 26;

void setup() {
Serial.begin(115200);
}

void loop() {
float lux = analogRead(sensor) * 0.64453125;
Serial.println(lux);

delay(100);
}