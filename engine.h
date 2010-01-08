#ifndef engine_h
#define engine_h

#define PwmPinMotorA 10
#define PwmPinMotorB 11
#define DirectionPinMotorA 12
#define DirectionPinMotorB 13

#include <Servo.h> 

class engine{

public:
  engine(Servo *s);

  void straight();
  void left();
  void right();
  void reverse(int speed, int time);
  void forward(int speed, int time);
private:
  Servo *servo;
};

#endif
