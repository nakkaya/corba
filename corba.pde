#include "engine.h"
#include "navigation.h"

const int buttonPin = 2;
const int ledPin =  8;

engine engine;
navigation navigation(engine);

void waitButton(){
  digitalWrite(ledPin, HIGH);
  while(true)
    if (digitalRead(buttonPin) == HIGH)
      break;
  digitalWrite(ledPin, LOW);
}

void setup(){
  Serial.begin(9600);

  pinMode(buttonPin, INPUT); 
  pinMode(ledPin, OUTPUT); 

  // waitButton();
  //navigation.calibrate();

  engine.straight();

  waitButton();
  delay(2000);
}

void loop(){

  navigation.steer();

  engine.forward(255,10);
  delay(50);
  //delay(1000);
}
