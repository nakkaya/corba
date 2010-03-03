#include "WProgram.h"
#include "util.h"

void waitButton(){
  digitalWrite(LED_PIN, HIGH);

  while(true){
    if (digitalRead(BUTTON_PIN) == LOW)
      break;
  }

  digitalWrite(LED_PIN, LOW);
}
