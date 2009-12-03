#include "WProgram.h"
#include "engine.h"

engine::engine(){
  // motor pins must be outputs
  pinMode(PwmPinMotorA, OUTPUT);
  pinMode(PwmPinMotorB, OUTPUT);
  pinMode(DirectionPinMotorA, OUTPUT);
  pinMode(DirectionPinMotorB, OUTPUT);
}

void engine::forward(int speed, int time){
  analogWrite(PwmPinMotorB, speed);
  digitalWrite(DirectionPinMotorB, LOW);

  delay(time);

  analogWrite(PwmPinMotorB, 0);
  digitalWrite(DirectionPinMotorB, LOW);
}

void engine::reverse(int speed, int time){
  analogWrite(PwmPinMotorB, speed);
  digitalWrite(DirectionPinMotorB, HIGH);

  delay(time);

  analogWrite(PwmPinMotorB, 0);
  digitalWrite(DirectionPinMotorB, HIGH);
}

void engine::right(){
  analogWrite(PwmPinMotorA, 255);
  digitalWrite(DirectionPinMotorA, LOW);
}

void engine::left(){
  analogWrite(PwmPinMotorA, 255);
  digitalWrite(DirectionPinMotorA, HIGH);
}

void engine::straight(){
  analogWrite(PwmPinMotorA, 0);
  digitalWrite(DirectionPinMotorA, HIGH);
}

