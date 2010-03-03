#ifndef navigation_h
#define navigation_h

#include "WProgram.h"
#include "PololuQTRSensors.h"
#include "engine.h"
#include "config.h"
#include "util.h"

#define READ_LINE_LEFT 5000
#define READ_LINE_RIGHT 1000
#define READ_LINE_CENTER (READ_LINE_LEFT+READ_LINE_RIGHT)/2

#define LINE_TRACKING 0
#define LINE_LEFT 1
#define LINE_RIGHT 2

class navigation{
public:
  navigation(engine *e);
  void calibrate();
  void steer();
private:
  void turn(int line);

  engine *engin;
  PololuQTRSensorsRC qtr;
  int lineLost;
};

#endif
