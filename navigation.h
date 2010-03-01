#ifndef navigation_h
#define navigation_h

#include "WProgram.h"
#include "PololuQTRSensors.h"
#include "engine.h"
#include "config.h"

#define LINE_RIGHT 1
#define LINE_LEFT 2

class navigation{
public:
  navigation(engine *e);
  void steer();
private:
  engine *engin;
  PololuQTRSensorsRC qtr;
  int lineLost;
};

#endif
