#include "config.h"
#include "engine.h"
#include "Button.h"
#include "PololuQTRSensors.h"
#include "navigation.h"

Button button = Button(14,PULLDOWN);
const int ledPin = 15;
PololuQTRSensorsRC qtr((unsigned char[]) {2,3,4,5,6,7,8,9}, NUM_OF_SENSORS);

void setup(){
#ifdef DEBUG
  Serial.begin(9600);
#endif

  pinMode(ledPin, OUTPUT);
  engineSetup();

  while(button.isPressed() == false);
  calibrate(&qtr);
  while(button.isPressed() == false);
}

void loop(){
  int pos = readLine(&qtr);

if (pos != LINE_LOST){

    if (pos == EDGE_RIGHT){
      motor(MotorA,-150);
      motor(MotorB,150);
      
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
    }else if (pos == EDGE_LEFT){
      motor(MotorA,150);
      motor(MotorB,-150);
      
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
    }else{

      int error = pos - MIDDLE_POS;
      int m1Speed = 255;
      int m2Speed = 255;

      if (error < 0)
	m1Speed = map(error,-MIDDLE_POS,0,-255,255);
      else
	m2Speed = map(error,0,MIDDLE_POS,255,-255);

#ifdef DEBUG
      Serial.print(error);   Serial.print(" ");
      Serial.print(m1Speed); Serial.print(" "); Serial.println(m2Speed);
#endif

      motor(MotorA,m1Speed);
      motor(MotorB,m2Speed);
    }
  }
}
