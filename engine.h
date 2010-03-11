#ifndef engine_h
#define engine_h

#include <Servo.h> 
#include "config.h"

#define FRONT_SERVO_RIGHT 120
#define FRONT_SERVO_CENTER 90
#define FRONT_SERVO_LEFT 60

#define GEAR_ONE 99
#define GEAR_TWO 98
#define GEAR_THREE 97

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
