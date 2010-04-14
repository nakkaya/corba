#ifndef engine_h
#define engine_h

#include "config.h"
#include "WProgram.h"

#define PwmPinMotorA 10
#define PwmPinMotorB 11
#define DirectionPinMotorA 12
#define DirectionPinMotorB 13

#define MotorA 0
#define MotorB 1

#define FORWARD 0
#define REVERSE 1

#define REVOLVE_LEFT 0
#define REVOLVE_RIGHT 1

void engineSetup(){
  // motor pins must be outputs
  pinMode(PwmPinMotorA, OUTPUT);
  pinMode(PwmPinMotorB, OUTPUT);
  pinMode(DirectionPinMotorA, OUTPUT);
  pinMode(DirectionPinMotorB, OUTPUT);
}

void motor(int motor,int speed){
#ifdef POWER
  int pwmPin = 10;
  int dirPin = 12;
  int dir = HIGH;

  if(motor == MotorB){
    pwmPin = 11;
    dirPin = 13;
  }

  if(speed < 0){
    dir = LOW;
    speed = -1 * speed;
  }

  analogWrite(pwmPin, speed);
  digitalWrite(dirPin, dir);
#endif
}

void revolve(int speed , int direction){
  if (direction == REVOLVE_LEFT ){
    motor(MotorA,speed);
    motor(MotorB,-speed);
  }else{
    motor(MotorA,-speed);
    motor(MotorB,speed);
  } 
}

#endif
