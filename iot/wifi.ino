#include <ESP8266WIFI>
char *SSid = "phone";
char *Password = "pass" void setup()
{
    WiFi.begin(SSid, Password);
    Serial.begin(115200);
    Serial.print("Connecting...");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print("Waiting to connect")
            delay(1000);
    }
    Serial.println("Connection established");
    Serial.println("IP Address\t");
    Serial.println(WiFi.LocalIP());
}