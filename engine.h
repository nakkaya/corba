#ifndef engine_h
#define engine_h

#include <Servo.h> 
#include "config.h"

class engine{

public:
  engine(Servo *s,Servo *e);

  void init();
  void straight();
  void left();
  void right();
  void turnRaw(int angle);

  void forward(int speed);
private:
  Servo *servo;
  Servo *esc;
};

#endif
