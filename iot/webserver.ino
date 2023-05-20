#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "Hello from NodeMCU!");
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Start the server
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();
}
