#include "Gy521.h"
#include "Arduino.h"
#include <Wire.h>

Gy521::Gy521()
{
  Wire.begin();
  Wire.beginTransmission(_MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
}

void Gy521::getAcData(){
  Wire.beginTransmission(_MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(_MPU,6,true);  
  AcX=Wire.read()<<8|Wire.read();    
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();   
 
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ);  
}
void Gy521::getGyData(){
  Wire.beginTransmission(_MPU);
  Wire.write(0x43);  
  Wire.endTransmission(false);
  Wire.requestFrom(_MPU,6,true);  
   
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();
  
  Serial.print("Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.println(GyZ);
  Serial.println(" ");
  delay(100);
}
