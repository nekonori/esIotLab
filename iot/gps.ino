#include <SoftwareSerial.h>

// Replace with your GPS module pins
const int GPS_TX_PIN = 2;
const int GPS_RX_PIN = 3;

SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN); // RX, TX

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600);

  // Configure GPS module
  gpsSerial.println("$PMTK251,9600*17"); // Set baud rate to 9600
  gpsSerial.println("$PMTK300,1000,0,0,0,0*1C"); // Set update rate to 1Hz
}

void loop() {
  // Read incoming GPS data
  while (gpsSerial.available()) {
    char incomingData = gpsSerial.read();
    Serial.print(incomingData);
  }

  delay(1000); // Wait for 1 second before reading again
}
