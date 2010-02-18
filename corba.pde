#include <Servo.h>
#include "engine.h"
#include "navigation.h"

#define DEBUG
#define FORWARD   //control power to rear wheel

const int buttonPin = 12;
const int ledPin =  13;
const int servoPin = 11;

Servo servo;
//engine engine(&servo);
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

  //engine.straight();

  waitButton();
  delay(2000);
}

void loop(){

  //navigation.steer();
  //delay(70);
}
