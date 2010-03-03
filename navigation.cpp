#include "WProgram.h"
#include "navigation.h"

navigation::navigation(engine *e){
  engin = e;
  qtr.init((unsigned char[]) {2,3,4,5,6,7,9}, 7);
  lineLost = 0;
}

void navigation::calibrate(){
  waitButton();
  int i;  
  for (i = 0; i < 250; i++){  // make the calibration take about 5 seconds  
    qtr.calibrate(QTR_EMITTERS_ON);
    delay(20);  
  } 
  blink();
}

void navigation::turn(int line){
  int angle = map
    (line,READ_LINE_RIGHT,READ_LINE_LEFT,FRONT_SERVO_RIGHT,FRONT_SERVO_LEFT);
  engin->turnRaw(angle);
}

void navigation::steer(){
  unsigned int val[7];
  qtr.read(val);
  //int line = qtr.readLine(val,QTR_EMITTERS_ON,1);
  int line = qtr.readLine(val);

  if (line < READ_LINE_RIGHT)
    lineLost = LINE_LEFT;
  else if (line > READ_LINE_LEFT)
    lineLost = LINE_RIGHT;

#ifdef DEBUG
    Serial.print(line);
    Serial.print(" R< ");
    Serial.print(val[0]); Serial.print(" ");
    Serial.print(val[1]); Serial.print(" ");
    Serial.print(val[2]); Serial.print(" ");
    Serial.print(val[3]); Serial.print(" ");
    Serial.print(val[4]); Serial.print(" ");
    Serial.print(val[5]); Serial.print(" ");
    Serial.print(val[6]); Serial.print(" ");
    //Serial.print(val[7]); Serial.print(" ");
    Serial.print(" >L "); 
    Serial.print(" LL: "); Serial.println(lineLost);
#endif

  turn(line);
}
