#ifndef navigation_h
#define navigation_h

#include "WProgram.h"
#include "config.h"
#include "engine.h"
#include "PololuQTRSensors.h"


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

bool lineLost(unsigned int* vals){
  bool lost = true;
  
  if (TRACKING_WHITE == 0){
    for(int i=0;i<NUM_OF_SENSORS - 1;i++){
      if (vals[i] > WHITE_TRASHOLD){
	lost =false;
      }
    }
  }else{
    for(int i=0;i<NUM_OF_SENSORS - 1;i++){
      if (vals[i] < BLACK_TRASHOLD){
	lost =false;
      }
    }
  }
  return lost;
}

int readLine(PololuQTRSensorsRC* qtr){
  unsigned int val[NUM_OF_SENSORS];
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
  Serial.print(" >L");
#endif

  if (lineLost(val) == true)
    return -1;

  return line;
}

#endif
