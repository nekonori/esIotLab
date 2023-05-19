#include <Servo.h>
Servo newservo1;
void setup()
{ // put your setup code here, to run once:
    newservo1.attach(D6);
}
void loop()
{ // put your main code here, to run repeatedly:
    newservo1.write(180);
    delay(1000);
    newservo1.write(0);
    delay(1000);
}