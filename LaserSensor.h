#ifndef LaserSensor_h
#define LaserSensor_h

class LaserSensor {
  public:
    /*10 个激光对应的IO口 Laser_pin_1对应原点位置的激光*/
    LaserSensor(int Laser_pin_1, int Laser_pin_2, int Laser_pin_3,int Laser_pin_4,
                int Laser_pin_5, int Laser_pin_6, int Laser_pin_7,int Laser_pin_8,
                                 int Laser_pin_9, int Laser_pin_10);

    // 获取坐标值
    int getCoordValue(void);

    // 获取亮灯数量
    int getLightNum(void);

    // 获取激光头状态 
    bool getLaserStatus(int index);

    int version(void);

  private:
    // Laser pin numbers:
    int Laser_pin_1;
    int Laser_pin_2;
    int Laser_pin_3;
    int Laser_pin_4;
    int Laser_pin_5;
    int Laser_pin_6;
    int Laser_pin_7;
    int Laser_pin_8;
    int Laser_pin_9;
    int Laser_pin_10;
};

#endif

