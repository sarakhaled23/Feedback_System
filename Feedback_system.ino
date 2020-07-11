#include <Servo.h>

Servo serv;
int AnalogOut = 0;
int NewAnalogOut = 0;

void setup() {
  Serial.begin(9600);
  serv.attach(7);
}

void loop() {
  
  int sensorValue = analogRead(A0);
  NewAnalogOut = map(sensorValue, 0, 1023, 0, 180);
  if (abs(NewAnalogOut - AnalogOut) > 2) {
    serv.write(AnalogOut);
    AnalogOut = NewAnalogOut;
  }
  
    delay(50);
}