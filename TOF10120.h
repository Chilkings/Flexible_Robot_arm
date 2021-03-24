#ifndef TOF10120_h
#define TOF10120_h

class TOF10120 {
  public:
    /*10 个激光对应的IO口 Laser_pin_1对应原点位置的激光*/
    TOF10120(void);

    // 获取距离值
    int getLenthVal(void);

    // i2c读
    void SensorRead(unsigned char addr,unsigned char* datbuf,unsigned char cnt) ;

    // i2c写
    void SensorWrite(unsigned char addr,unsigned char* datbuf,unsigned char cnt) ;

    int version(void);

  private:
    unsigned short lenth_val = 0;
    unsigned char i2c_rx_buf[16];
};

#endif
