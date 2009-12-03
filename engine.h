#ifndef engine_h
#define engine_h

#define PwmPinMotorA 10
#define PwmPinMotorB 11
#define DirectionPinMotorA 12
#define DirectionPinMotorB 13

class engine{

public:
  engine();

  void straight();
  void left();
  void right();
  void reverse(int speed, int time);
  void forward(int speed, int time);
private:
};

#endif
