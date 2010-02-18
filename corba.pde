#include <Servo.h>
#include "engine.h"
#include "navigation.h"

#define DEBUG
#define FORWARD   //control power to rear wheel

const int buttonPin = 12;
const int ledPin =  13;
const int servoPin = 11;
const int escPin = 10;

Servo servo;
Servo esc;
engine engine(&servo,&esc);
//navigation navigation(&engine);

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

  waitButton();
  delay(2000);

  //engine.forward(101);
}

void loop(){
  //navigation.steer();
  //delay(70);
}
