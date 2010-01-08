#include "WProgram.h"
#include "engine.h"

engine::engine(Servo *s){
  // motor pins must be outputs
  pinMode(PwmPinMotorB, OUTPUT);
  pinMode(DirectionPinMotorB, OUTPUT);

  servo = s;
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
  servo->write(160);
}

void engine::left(){
  servo->write(100);
}

void engine::straight(){
  servo->write(130);
}

