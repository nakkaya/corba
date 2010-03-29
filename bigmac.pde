#include "config.h"
#include "engine.h"
#include "Button.h"
#include "PololuQTRSensors.h"
#include "navigation.h"

Button button = Button(9,PULLDOWN);
PololuQTRSensorsRC qtr((unsigned char[]) {2,3,4,5,6,7}, 6);

int lastError = 0;
float KP = 0.1;
int KD = 5;

int M1 = 255;
int M2 = 255;

void setup(){
#ifdef DEBUG
  Serial.begin(9600);
#endif

  engineSetup();

  while(button.isPressed() == false);
  calibrate(&qtr);
  while(button.isPressed() == false);
}

void loop(){

  int pos = readLine(&qtr);

  int leftMotorSpeed = 200;
  int rightMotorSpeed = 200;

  int error = pos - 2500;
  int motorSpeed = KP * error + KD * (error - lastError);
  lastError = error;

  int m1Speed = M1 + motorSpeed;  
  int m2Speed = M2 - motorSpeed; 

  if (m1Speed < 0)
    m1Speed = 0;
  if (m2Speed < 0)
    m2Speed = 0;

  m1Speed = map(m1Speed,5,505,0,255);
  m2Speed = map(m2Speed,5,505,0,255);

#ifdef DEBUG
  Serial.print(motorSpeed); Serial.print(" ");
  Serial.print(m1Speed); Serial.print(" ");
  Serial.print(m2Speed); Serial.print(" ");
  Serial.println(error);
#endif

#ifdef POWER
  motor(MotorA,m1Speed,FORWARD);
  motor(MotorB,m2Speed,FORWARD);
#endif
}
