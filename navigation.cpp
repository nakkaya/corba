#include "WProgram.h"
#include "navigation.h"

navigation::navigation(engine *e){
  position = STRAIGHT;

  engin = e;
  qtr.init((unsigned char[]) {5 , 6 ,7}, 3);
}

void navigation::steer(){
  int bearing = getBearing();

  Serial.println(bearing);

  if(bearing == LEFT)
    engin->left();

  if(bearing == STRAIGHT)
    engin->straight();

  if(bearing == RIGHT)
    engin->right();

  //engin->forward(255,10);
}


int navigation::getBearing(){
  unsigned int val[3];
  qtr.read(val);

  int right = val[0];
  int middle = val[1];
  int left = val[2];
  

  // Serial.print("bwMean: "); Serial.print(bwMean); Serial.print("\t");
  // Serial.print("Left: ");Serial.print(left); Serial.print("\t");
  // Serial.print("Middle: ");Serial.print(middle); Serial.print("\t");
  // Serial.print("Right: ");Serial.print(right); Serial.print("\n");

  if(left <= middle && left <= right && position != RIGHT){
    position = LEFT;
    return RIGHT;
  }

  if(right <= left && right <= middle && position != LEFT){
    position = RIGHT;
    return LEFT;
  }

  if(middle <= left && middle <= right){
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
