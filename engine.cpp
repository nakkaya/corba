#include "WProgram.h"
#include "engine.h"

engine::engine(Servo *s,Servo *e){
  servo = s;
  esc = e;
}

void engine::init(){
  straight();
  forward(90);
}

void engine::forward(int speed){
  esc->write(speed);
}

void engine::right(){
  servo->write(FRONT_SERVO_RIGHT);
}

void engine::left(){
  servo->write(FRONT_SERVO_LEFT);
}

void engine::straight(){
  servo->write(FRONT_SERVO_CENTER);
}

void engine::turnRaw(int angle){
  servo->write(angle);
}
