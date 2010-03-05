#ifndef navigation_h
#define navigation_h

#include "WProgram.h"
#include "PololuQTRSensors.h"
#include "engine.h"
#include "config.h"
#include "util.h"

#define READ_LINE_LEFT 7000
#define READ_LINE_RIGHT 0

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
