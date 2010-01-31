#ifndef navigation_h
#define navigation_h

#define SENSOR_LEFT 5
#define SENSOR_MIDDLE 6
#define SENSOR_RIGHT 7

#define LEFT 1
#define STRAIGHT 2
#define RIGHT 3

#include "WProgram.h"
#include "PololuQTRSensors.h"
#include "engine.h"

class navigation{
public:
  navigation(engine *e);
  void steer();
private:
  engine *engin;
  PololuQTRSensorsRC qtr;
  int position;
  int getBearing();
};

#endif
