#include <Servo.h>
Servo servo;
void setup()
{
    servo.attach(D6);
    Serial.begin(9600);
    pinMode(A0, INPUT);
}
void loop()
{
    float x = analogRead(A0);
    x = map(x, 0, 1023, 0, 180);
    servo.write(x);
    delay(15);
}