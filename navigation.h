#ifndef navigation_h
#define navigation_h

#include "WProgram.h"
#include "config.h"
#include "engine.h"
#include "PololuQTRSensors.h"

#define TRACKING_WHITE 0

void calibrate(PololuQTRSensorsRC* qtr){
#ifdef POWER
  motor(MotorA,150);
  motor(MotorB,-150);
#endif

  int i;
  for (i = 0; i < 125; i++){
    qtr->calibrate(QTR_EMITTERS_ON);
    delay(20);
  }

#ifdef POWER
  motor(MotorA,0);
  motor(MotorB,0);
#endif
}

int readLine(PololuQTRSensorsRC* qtr){
  unsigned int val[6];
  qtr->readCalibrated(val);
  int line = qtr->readLine(val,QTR_EMITTERS_ON,TRACKING_WHITE);

#ifdef DEBUG
  Serial.print(line);
  Serial.print(" R< ");
  Serial.print(val[0]); Serial.print(" ");
  Serial.print(val[1]); Serial.print(" ");
  Serial.print(val[2]); Serial.print(" ");
  Serial.print(val[3]); Serial.print(" ");
  Serial.print(val[4]); Serial.print(" ");
  Serial.print(val[5]); Serial.print(" ");
  Serial.print(" >L ");
#endif

  return line;
}

#endif
