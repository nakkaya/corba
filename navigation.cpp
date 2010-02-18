#include "WProgram.h"
#include "navigation.h"

navigation::navigation(engine *e){
  engin = e;
  qtr.init((unsigned char[]) {2,3,4,5,6,7,8,9}, 8);
}

void navigation::steer(){
  unsigned int val[8];
  qtr.read(val);
  int line = qtr.readLine(val,QTR_EMITTERS_ON,1);

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
  Serial.print(val[7]); Serial.print(" ");
  Serial.println(" >Left");
#endif

  int angle = map(line,0,7000,70,130);
  angle = map(angle,70,130,130,70);
  engin->turnRaw(angle);
}
