//#include <Wire.h>
#include "Gy521.h"

Gy521 goo();

void setup(){
  Serial.begin(9600);
}
void loop(){
  goo.getAcData();
  goo.getGyData();
}
