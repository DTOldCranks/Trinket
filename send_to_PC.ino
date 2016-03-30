#include <SoftwareSerial.h>
int counter = 0;

#define RXDATA    0      // SoftwareSerial receive pin.
#define TXDATA    1      // SoftwareSerial transmit pin.
#define ANASG1     1      // Analog channel 1 for strain gauge measurement
#define ANASG3     3      // Analog channel 3 for strain gauge measurement

SoftwareSerial serial(RXDATA, TXDATA);

void setup() {
  serial.begin(9600);
}

void loop() {
  serial.print("Voltage: ");
  int sensorValue1 = analogRead(ANASG1);
  int sensorValue3 = analogRead(ANASG3);
  float voltage1 = sensorValue1 * (5.0 / 1023.0 * 1000.0); // change to bits and convert to mV
  float voltage3 = sensorValue3 * (5.0 / 1023.0 * 1000.0);
  serial.print(abs(voltage1-voltage3));
  serial.println(" mV");
  delay(100); // wait half a sec
}
