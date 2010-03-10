#include <Servo.h>
#include "engine.h"
#include "navigation.h"
#include "config.h"
#include "util.h"

const int servoPin = 11;
const int escPin = 10;

Servo servo;
Servo esc;
engine engine(&servo,&esc);
navigation navigation(&engine);

void setup(){
#ifdef DEBUG
  Serial.begin(9600);
#endif

  pinMode(BUTTON_PIN, INPUT); 
  pinMode(LED_PIN, OUTPUT);

  servo.attach(servoPin);
  esc.attach(escPin);

  engine.init();
  navigation.calibrate();

#ifdef FORWARD
  waitButton();
  delay(2000);

  engine.forward(102);
#endif
}

void loop(){

  navigation.steer();

#ifdef DELAY_LOOP
    delay(1000);
#endif
}
