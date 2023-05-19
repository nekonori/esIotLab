void setup()
{                        // ultrosonic HCSR -04 - proximity detection
    pinMode(D6, OUTPUT); // trigger pin
    pinMode(D7, INPUT);  // Echopin //rcr
}
void loop()
{ // put your main code here, to run repeatedly:
    // trigger sonic waves
    digitalWrite(D6, LOW);
    delayMicroseconds(2);
    digitalWrite(D6, HIGH);
    delayMicroseconds(10);
    // receive ECHO and find DISTANCE
    long duration = pulseIn(D7, HIGH);
    float dist = duration * 0.034 / 2;
    Serial.println("Distance is...");
    Serial.println(dist);
    delay(2000);
}