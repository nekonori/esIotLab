#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
char msg[50];
const char *ssid = "phone";    // your network SSID (name)
const char *password = "pass"; // your network password
WiFiClient client;
unsigned long myChannelNumber = 0000000;   // Your channel number
const char *myWriteAPIKey = "xxxxxxxxxxx"; // Your WriteAPI Key
// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;
// Variable to hold temperature readings
float temperatureC;
int outputpin = A0;
void setup()
{
    Serial.begin(115200); // Initialize serial
    WiFi.mode(WIFI_STA);
    ThingSpeak.begin(client); // Initialize ThingSpeak
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.print("Attempting to connect");
        while (WiFi.status() != WL_CONNECTED)
        {
            WiFi.begin(ssid, password);
            delay(5000);
        }
        Serial.println("\nConnected.");
    }
}
void loop()
{
    if ((millis() - lastTime) > timerDelay || 1)
    {
        int analogValue = analogRead(outputpin);
        float millivolts = (analogValue / 1024.0) * 3300;
        temperatureC = millivolts / 80 + random(10);
        Serial.print("Temperature (ºC): ");
        Serial.println(temperatureC);
        int x = ThingSpeak.writeField(myChannelNumber, 1, temperatureC,
                                      myWriteAPIKey);
        if (x == 200)
        {
            Serial.println("Channel update successful.");
        }
        else
        {
            Serial.println("Problem updating channel. HTTP error code " +
                           String(x));
        }
        lastTime = millis();
    }
}