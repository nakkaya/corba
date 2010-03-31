#include "config.h"
#include "engine.h"
#include "Button.h"
#include "PololuQTRSensors.h"
#include "navigation.h"

Button button = Button(9,PULLDOWN);
PololuQTRSensorsRC qtr((unsigned char[]) {2,3,4,5,6,7}, 6);

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

  int error = pos - 2500;
  int m1Speed = 255;
  int m2Speed = 255;

  if (error < 0)
    m1Speed = map(error,-2500,0,-255,255);
  else
    m2Speed = map(error,0,2500,255,-255);


#ifdef DEBUG
  Serial.print(m1Speed); Serial.print(" "); Serial.println(m2Speed);
#endif

#ifdef POWER
    motor(MotorA,m1Speed);
    motor(MotorB,m2Speed);
#endif

}
