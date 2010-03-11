#ifndef navigation_h
#define navigation_h

#include "WProgram.h"
#include "PololuQTRSensors.h"
#include "engine.h"
#include "config.h"
#include "util.h"

#define READ_LINE_LEFT 7000
#define READ_LINE_RIGHT 0
#define TRACKING_WHITE 1

class navigation{
public:
  navigation(engine *e);
  void calibrate();
  void steer();
private:
  void turn(int line);
  bool lineLost(unsigned int *vals);

  engine *engin;
  PololuQTRSensorsRC qtr;
};

#endif
