#include <SoftwareSerial.h>

// Replace with your Bluetooth module pins
const int BT_TX_PIN = 2;
const int BT_RX_PIN = 3;

SoftwareSerial bluetooth(BT_RX_PIN, BT_TX_PIN); // RX, TX

void setup() {
  Serial.begin(115200);

  // Initialize Bluetooth Serial connection
  bluetooth.begin(9600);
}

void loop() {
  // Send data to Bluetooth module
  bluetooth.println("Hello, world!");

  // Wait for incoming data from Bluetooth module
  while (bluetooth.available()) {
    char incomingData = bluetooth.read();
    Serial.print(incomingData);
  }

  delay(1000); // Wait for 1 second before sending again
}
