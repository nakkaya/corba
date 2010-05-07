#ifndef navigation_h
#define navigation_h

#include "WProgram.h"
#include "config.h"
#include "engine.h"
#include "PololuQTRSensors.h"

#define LINE_LOST -1
#define EDGE_LEFT -2
#define EDGE_RIGHT -3

int TRACKING_WHITE = 1;

void calibrate(PololuQTRSensorsRC* qtr){
  revolve(CALIBRATION_SPEED,REVOLVE_LEFT);

  int i;
  for (i = 0; i < 125; i++){
    qtr->calibrate(QTR_EMITTERS_ON);
    delay(20);
  }

  revolve(0,REVOLVE_LEFT);
}

bool lineLost(unsigned int* vals){
  bool lost = true;
  
  if (TRACKING_WHITE == 0){
    for(int i=0;i<NUM_OF_SENSORS;i++){
      if (vals[i] > WHITE_TRASHOLD){
	lost =false;
      }
    }
  }else{
    for(int i=0;i<NUM_OF_SENSORS;i++){
      if (vals[i] < BLACK_TRASHOLD){
	lost =false;
      }
    }
  }
  return lost;
}

void detectTrackColor(unsigned int* vals){
  if ((vals[0] < WHITE_TRASHOLD) &&
      (vals[NUM_OF_SENSORS - 1] < WHITE_TRASHOLD))
    TRACKING_WHITE = 0;

  if ((vals[0] > BLACK_TRASHOLD) &&
      (vals[NUM_OF_SENSORS - 1]> BLACK_TRASHOLD))
    TRACKING_WHITE = 1;
}

int checkEdge(unsigned int* vals){ 
  if (TRACKING_WHITE == 0){
    if ((vals[NUM_OF_SENSORS - 1] > WHITE_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 2] > WHITE_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 3] > WHITE_TRASHOLD) &&
	(vals[0] < WHITE_TRASHOLD) &&
	(vals[1] < WHITE_TRASHOLD) &&
	(vals[2] < WHITE_TRASHOLD)){
      return EDGE_LEFT;
    }
    if ((vals[0] > WHITE_TRASHOLD) &&
	(vals[1] > WHITE_TRASHOLD) &&
	(vals[2] > WHITE_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 1] < WHITE_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 2] < WHITE_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 3] < WHITE_TRASHOLD)){
      return EDGE_RIGHT;
    }
  }else{
    if ((vals[NUM_OF_SENSORS - 1] < BLACK_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 2] < BLACK_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 3] < BLACK_TRASHOLD) &&
	(vals[0] > BLACK_TRASHOLD) &&
	(vals[1] > BLACK_TRASHOLD) &&
	(vals[2] > BLACK_TRASHOLD)){
      return EDGE_LEFT;
    }
    if ((vals[0] < BLACK_TRASHOLD) &&
	(vals[1] < BLACK_TRASHOLD) &&
	(vals[2] < BLACK_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 1] > BLACK_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 2] > BLACK_TRASHOLD) &&
	(vals[NUM_OF_SENSORS - 3] > BLACK_TRASHOLD)){
      return EDGE_RIGHT;
    }
  }
  return 0;
}

int readLine(PololuQTRSensorsRC* qtr){
  unsigned int val[NUM_OF_SENSORS];
  qtr->readCalibrated(val);

  detectTrackColor(val);

  int line = qtr->readLine(val,QTR_EMITTERS_ON,TRACKING_WHITE);

#ifdef DEBUG
  Serial.print(TRACKING_WHITE);   Serial.print(" ");
  Serial.print(line);   Serial.print(" R< ");
  Serial.print(val[0]); Serial.print(" ");
  Serial.print(val[1]); Serial.print(" ");
  Serial.print(val[2]); Serial.print(" ");
  Serial.print(val[3]); Serial.print(" ");
  Serial.print(val[4]); Serial.print(" ");
  Serial.print(val[5]); Serial.print(" ");
  Serial.print(val[6]); Serial.print(" ");
  Serial.print(val[7]); Serial.print(" >L ");

  if (lineLost(val) == true)
    Serial.print("Line Lost \n");
  if (checkEdge(val) != 0)
    Serial.print("Edge \n");
#endif

  if (lineLost(val) == true)
    return LINE_LOST;
#ifdef EDGED_TRACK
  else if (checkEdge(val) != 0)
    return checkEdge(val);
#endif
  else
    return line;
}

#endif
