#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>

SoftwareSerial serial(1, 4);
Adafruit_ADS1015 ads;
void setup() {
  // put your setup code here, to run once:
  serial.begin(9600);
  ads.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int16_t results;

  float multiplier = 3.0F;
  results = ads.readADC_Differential_0_1();
  serial.print(results); serial.print("("); serial.print(results * multiplier); serial.println("mV)");
  delay(1000);
}
