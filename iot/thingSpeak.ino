#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// Replace with your Wi-Fi credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Replace with your ThingSpeak channel details and write API key
unsigned long channelID = your_Channel_ID;
const char* writeAPIKey = "your_write_API_key";

// Analog input pin for temperature sensor
const int temperaturePin = A0;

WiFiClient client;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak client
  ThingSpeak.begin(client);
}

void loop() {
  // Read temperature sensor value
  int sensorValue = analogRead(temperaturePin);
  float temperature = (sensorValue / 1024.0) * 330.0;

  // Send temperature data to ThingSpeak
  ThingSpeak.writeField(channelID, 1, temperature, writeAPIKey);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" degrees Celsius");

  // Wait for 10 seconds before uploading again
  delay(10000);
}



