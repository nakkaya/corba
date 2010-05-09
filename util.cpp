#include "WProgram.h"
#include "util.h"

void waitButton(){
  digitalWrite(LED_PIN, HIGH);

  while(digitalRead(BUTTON_PIN) == LOW){
    delay(100);
  }

  digitalWrite(LED_PIN, LOW);
}

void blink(){
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
}
