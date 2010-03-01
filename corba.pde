#include <Servo.h>
#include "engine.h"
#include "navigation.h"
#include "config.h"

const int buttonPin = 12;
const int ledPin =  13;
const int servoPin = 11;
const int escPin = 10;

Servo servo;
Servo esc;
engine engine(&servo,&esc);
navigation navigation(&engine);

void waitButton(){
  digitalWrite(ledPin, HIGH);
  while(true)
    if (digitalRead(buttonPin) == LOW)
      break;
  digitalWrite(ledPin, LOW);
}

void setup(){
#ifdef DEBUG
  Serial.begin(9600);
#endif

  pinMode(buttonPin, INPUT); 
  pinMode(ledPin, OUTPUT);

  servo.attach(servoPin);
  esc.attach(escPin);

  engine.init();

#ifdef FORWARD
  waitButton();
  delay(2000);

  engine.forward(100);
#endif
}

void loop(){

  navigation.steer();
  delay(70);

#ifdef DELAY_LOOP
    delay(1000);
#endif
}
