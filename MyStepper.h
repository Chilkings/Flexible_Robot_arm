#ifndef MyStepper_h
#define MyStepper_h

class Stepper {
  public:
    /*转一圈所需的总步长 PUL对应的io口  DIR对应的io口   ENA对应的io口*/
    Stepper(int number_of_steps, int PUL_pin, int DIR_pin,
                                 int ENA_pin);

    // 设置步进电机移动速度
    void setSpeed(long whatSpeed);

    //步进电机步进 可正可负
    void step(int number_of_steps);

    //释放对电机的控制，使其可以自由移动
    void free(void);

    int version(void);

  private:
  
    int direction;            // Direction of rotation
    unsigned long step_delay; // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take

    // motor pin numbers:
    int PUL_pin;
    int DIR_pin;
    int ENA_pin;
};

#endif

