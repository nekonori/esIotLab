int outputpin = A0;
void setup()
{
    Serial.begin(9600);
}
void loop() // main loop
{
    int analogValue = analogRead(outputpin);
    float millivolts = (analogValue / 1024.0) * 3300;
    float celsius = millivolts / 10;
    Serial.print("in DegreeC= ");
    Serial.println(celsius);
    //----------Calculation for Fahrenheit ----------//
    float fahrenheit = ((celsius * 9) / 5 + 32);
    Serial.print(" in Farenheit = ");
    Serial.println(fahrenheit);
    delay(1000);
}