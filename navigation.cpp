#include "WProgram.h"
#include "navigation.h"

navigation::navigation(engine *e){
  engin = e;
  qtr.init((unsigned char[]) {2,3,4,5,6,7,9}, 7);
  lineLost = 0;
}

void navigation::steer(){
  unsigned int val[7];
  qtr.read(val);
  //int line = qtr.readLine(val,QTR_EMITTERS_ON,1);
  int line = qtr.readLine(val);

#ifdef DEBUG
  Serial.print(line);
  Serial.print(" Right< ");
  Serial.print(val[0]); Serial.print(" "); 
  Serial.print(val[1]); Serial.print(" ");
  Serial.print(val[2]); Serial.print(" "); 
  Serial.print(val[3]); Serial.print(" ");
  Serial.print(val[4]); Serial.print(" "); 
  Serial.print(val[5]); Serial.print(" ");
  Serial.print(val[6]); Serial.print(" "); 
  //Serial.print(val[7]); Serial.print(" ");
  Serial.println(" >Left");
#endif

  if (line == 7000)
    lineLost = LINE_RIGHT;
  else if (line == 0)
    lineLost = LINE_LEFT;

#ifdef DEBUG
  Serial.print(" Line Lost: ");
  Serial.println(lineLost);
#endif

  if (lineLost == 0 ||
      (lineLost == 1 && line <= 3500  && line >= 7000) ||
      (lineLost == 2 && line <= 3500 && line >= 0) ){
    lineLost = 0;
    int angle = map(line,0,7000,FRONT_SERVO_RIGHT,FRONT_SERVO_LEFT);
    engin->turnRaw(angle);
  }
}
