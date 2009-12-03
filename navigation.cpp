#include "WProgram.h"
#include "navigation.h"

navigation::navigation(engine e){
  position = STRAIGHT;

  engin = e;
  qtr.init((unsigned char[]) {5 , 6 ,7}, 3);
}

void navigation::steer(){
  int bearing = getBearing();

  if(bearing == LEFT)
    engin.left();

  if(bearing == STRAIGHT)
    engin.straight();

  if(bearing == RIGHT)
    engin.right();
}


int navigation::getBearing(){
  unsigned int val[3];
  qtr.read(val);

  int right = val[0];
  int middle = val[1];
  int left = val[2];
  

  Serial.print("mean: "); Serial.println(bwMean);
  //Serial.print("sol: "); Serial.println(left);
  //Serial.print("orta: "); Serial.println(middle);
  //Serial.print("sag: "); Serial.println(right);

  if(left <= middle && left <= right && position != RIGHT){
    position = LEFT;
    return RIGHT;
  }

  if(right <= left && right <= middle && position != LEFT){
    position = RIGHT;
    return LEFT;
  }

  if(middle <= left && middle <= right && middle < bwMean){
    position = STRAIGHT;
    return STRAIGHT;
  }

  if (position == LEFT ) return RIGHT;
  if (position == RIGHT ) return LEFT;
}


void navigation::calibrate(){
  // engin.right();
  // engin.forward(255,100);

  // for (int i = 0; i < 84; i++){
  //   qtr.calibrate();
  //   delay(20);
  // }

  // engin.reverse(255,100);

  // engin.straight();
  // for (int i = 0; i < 84; i++){
  //   qtr.calibrate();
  //   delay(20);
  // }

  // engin.left();
  // engin.forward(255,100);

  // for (int i = 0; i < 84; i++){
  //   qtr.calibrate();
  //   delay(20);
  // }

  // engin.reverse(255,100);

  unsigned int val[3];
  qtr.read(val);
  
  int right = val[0];
  int middle = val[1];
  int left = val[2];

  bwMean = ((right - middle) + (left - middle))/2;
}
