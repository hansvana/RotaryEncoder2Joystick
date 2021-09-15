/*
    Rotary Encoder - Polling Example
    
    The circuit:
    * encoder pin A to Arduino pin 2
    * encoder pin B to Arduino pin 3
    * encoder ground pin to ground (GND)
    
*/

#include <Rotary.h>
#include <Joystick.h>

Rotary r = Rotary(4, 7);
int buttonPin = 8;
int joystickLimit = 255;
float pos = joystickLimit / 2;
float changeSpeed = 1;

void setup() {
  Serial.begin(9600);
  r.begin(true);
  pinMode(buttonPin, INPUT);
  Joystick.begin();
}

void loop() {
  unsigned char result = r.process();
  if (result) {
    if (result == DIR_CW) {
      pos -= changeSpeed;
    } else {
      pos += changeSpeed;
    }

    if (pos < 0) pos = 0;
    if (pos > joystickLimit) pos = joystickLimit;
    
    Joystick.setXAxis(round(pos)-127);
    Serial.println(round(pos));
  }

  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("Button");
    pos = joystickLimit / 2;
  }
}
