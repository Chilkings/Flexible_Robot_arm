#include "Arduino.h"
#include "TOF10120.h"
#include <Wire.h>

/********************************************************
 *
 * @file    TOF10120.cpp
 * @author  QQS
 * @date    2021/03/24
 * @email   chilkings.mail@gnmail.com
 * @github  https://github.com/chilkings
 *
********************************************************/

TOF10120::TOF10120()
{
    Wire.begin();
}



/*
 * Get lenth value
 */
int TOF10120::getLenthVal(void)
{
  SensorRead(0x00,(this->i2c_rx_buf),2);
  this->lenth_val=this->i2c_rx_buf[0];
  this->lenth_val=this->lenth_val<<8;
  this->lenth_val|=this->i2c_rx_buf[1];
  return this->lenth_val;
}

/*
 * i2c read
 */
void TOF10120::SensorRead(unsigned char addr,unsigned char* datbuf,unsigned char cnt) 
{
    // step 1: instruct sensor to read echoes
    Wire.beginTransmission(82); // transmit to device #82 (0x52)
    // the address specified in the datasheet is 164 (0xa4)
    // but i2c adressing uses the high 7 bits so it's 82
    Wire.write(byte(addr));      // sets distance data address (addr)
    Wire.endTransmission();      // stop transmitting
    // step 2: wait for readings to happen
    delay(1);                   // datasheet suggests at least 30uS
    // step 3: request reading from sensor
    Wire.requestFrom((int)82, (int)cnt);    // request cnt bytes from slave device #82 (0x52)
    // step 5: receive reading from sensor
    if (cnt <= Wire.available()) { // if two bytes were received
        *datbuf++ = Wire.read();  // receive high byte (overwrites previous reading)
        *datbuf++ = Wire.read(); // receive low byte as lower 8 bits
    }
}

/*
 * i2c write
 */
void TOF10120::SensorWrite(unsigned char addr,unsigned char* datbuf,unsigned char cnt) 
{
    // step 1: instruct sensor to read echoes
    Wire.beginTransmission(82); // transmit to device #82 (0x52)
    // the address specified in the datasheet is 164 (0xa4)
    // but i2c adressing uses the high 7 bits so it's 82
    Wire.write(byte(addr));      // sets distance data address (addr)
    // step 2: wait for address to write
    delay(1);                   // datasheet suggests at least 30uS
    // step 3: send data to sensor
    Wire.write(datbuf, cnt);    // write cnt bytes to slave device
    Wire.endTransmission();      // stop transmitting
}



/*
  version() returns the version of the library:
*/
int TOF10120::version(void)
{
  return 1;
}
