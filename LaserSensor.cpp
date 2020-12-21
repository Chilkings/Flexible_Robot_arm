#include "Arduino.h"
#include "LaserSensor.h"

/********************************************************
 *
 * @file    LaserSensor.cpp
 * @author  QQS
 * @date    2020/12/21
 * @email   chilkings.mail@gnmail.com
 * @github  https://github.com/chilkings
 *
********************************************************/

LaserSensor::LaserSensor(int Laser_pin_1, int Laser_pin_2, int Laser_pin_3,int Laser_pin_4,
                int Laser_pin_5, int Laser_pin_6, int Laser_pin_7,int Laser_pin_8,
                                 int Laser_pin_9, int Laser_pin_10)
{
  // Arduino pins for the Laser control connection:
  this->Laser_pin_1 = Laser_pin_1;
  this->Laser_pin_2 = Laser_pin_2;
  this->Laser_pin_3 = Laser_pin_3;
  this->Laser_pin_4 = Laser_pin_4;
  this->Laser_pin_5 = Laser_pin_5;
  this->Laser_pin_6 = Laser_pin_6;
  this->Laser_pin_7 = Laser_pin_7;
  this->Laser_pin_8 = Laser_pin_8;
  this->Laser_pin_9 = Laser_pin_9;
  this->Laser_pin_10 = Laser_pin_10;


  // setup the pins on the microcontroller:
  pinMode(this->Laser_pin_1, INPUT_PULLUP);
  pinMode(this->Laser_pin_2, INPUT_PULLUP);
  pinMode(this->Laser_pin_3, INPUT_PULLUP);
  pinMode(this->Laser_pin_4, INPUT_PULLUP);
  pinMode(this->Laser_pin_5, INPUT_PULLUP);
  pinMode(this->Laser_pin_6, INPUT_PULLUP);
  pinMode(this->Laser_pin_7, INPUT_PULLUP);
  pinMode(this->Laser_pin_8, INPUT_PULLUP);
  pinMode(this->Laser_pin_9, INPUT_PULLUP);
  pinMode(this->Laser_pin_10, INPUT_PULLUP);
}



/*
 * Get Laser Light number
 */
int LaserSensor::getLightNum(void)
{
  return ( !digitalRead(this->Laser_pin_1) + !digitalRead(this->Laser_pin_2) + !digitalRead(this->Laser_pin_3) + !digitalRead(this->Laser_pin_4)
         + !digitalRead(this->Laser_pin_5) + !digitalRead(this->Laser_pin_6) + !digitalRead(this->Laser_pin_7) + !digitalRead(this->Laser_pin_8)
         + !digitalRead(this->Laser_pin_9) + !digitalRead(this->Laser_pin_10) );
}

/*
 * Get the coordinate value
 */
int LaserSensor::getCoordValue(void)
{
  int value=0;
  int LightNum=0;
  value = !digitalRead(this->Laser_pin_1)*0 + !digitalRead(this->Laser_pin_2)*40 + !digitalRead(this->Laser_pin_3)*80 + !digitalRead(this->Laser_pin_4)*120 +
          !digitalRead(this->Laser_pin_5)*160 + !digitalRead(this->Laser_pin_6)*200 + !digitalRead(this->Laser_pin_7)*240 + !digitalRead(this->Laser_pin_8)*280 +
          !digitalRead(this->Laser_pin_9)*320 + !digitalRead(this->Laser_pin_10)*360;
  LightNum = getLightNum();
  
  if(LightNum ==0 ) 
    return 0;
  else 
    return  value/LightNum;
}

/*
 * Get the Laser status
 */
bool LaserSensor::getLaserStatus(int index)
{
  switch (index) {
      case 1:  
            return digitalRead(this->Laser_pin_1);
      case 2:  
            return digitalRead(this->Laser_pin_2);
      case 3:  
            return digitalRead(this->Laser_pin_3);
      case 4:  
            return digitalRead(this->Laser_pin_4);
      case 5:  
            return digitalRead(this->Laser_pin_5);
      case 6:  
            return digitalRead(this->Laser_pin_6);
      case 7:  
            return digitalRead(this->Laser_pin_7);
      case 8:  
            return digitalRead(this->Laser_pin_8);
      case 9:  
            return digitalRead(this->Laser_pin_9);
      case 10:  
            return digitalRead(this->Laser_pin_10);
    }
}



/*
  version() returns the version of the library:
*/
int LaserSensor::version(void)
{
  return 1;
}
