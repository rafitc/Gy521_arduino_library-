#ifndef Gy521_h
#define Gy521_h

#include "Arduino.h"
class Gy521
{
  public:
    Gy521();
    void getAcData();
    void getGyData();
    int16_t GyX,GyY,GyZ;
    int16_t AcX,AcY,AcZ;
        
  private:
    const int _MPU = 0x68;
};



#endif
