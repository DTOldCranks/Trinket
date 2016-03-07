#include <SoftwareSerial.h>
int counter = 0;

#define RXDATA    0      // SoftwareSerial receive pin.
#define TXDATA    1      // SoftwareSerial transmit pin.
#define ANASG     1      // Analog channel 1 for strain gauge measurement

SoftwareSerial serial(RXDATA, TXDATA);

void setup() {
  serial.begin(9600);
}

void loop() {
  serial.print("Voltage: ");
  int sensorValue = analogRead(ANASG);
  float voltage = sensorValue * (5.0 / 1023.0 * 1000.0);
  serial.print(voltage);
  serial.println(" mV");
  delay(100); // wait half a sec
}
