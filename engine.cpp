#include "WProgram.h"
#include "engine.h"

engine::engine(Servo *s,Servo *e){
  servo = s;
  esc = e;
}

void engine::init(){
  left();
  forward(90);
}

void engine::forward(int speed){
  esc->write(speed);
}

void engine::right(){
  servo->write(160);
}

void engine::left(){
  servo->write(100);
}

void engine::straight(){
  servo->write(130);
}

