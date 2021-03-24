#include "Mystepper.h"
#include "LaserSensor.h"
#include "Relay.h"
#include "TOF10120.h"
#define ApprochSensor 8

Stepper StepperX(1600, A1, A0, A2);
Stepper StepperY(1600, A3, A4, A5);
Stepper StepperZ(1600, A9, A8, A10);

Relay Valve1(6, false); //气阀一 常闭 onstructor receives (pin, isNormallyOpen) true = Normally Open, false = Normally Closed
Relay Valve2(7, false); //气阀二 常闭

LaserSensor LaserSensorX(52,50,48,46,44,42,40,38,36,34);
LaserSensor LaserSensorY(35,37,39,41,43,45,47,49,51,53);

TOF10120 TOF10120{}; //不带参数必须使用{}   TOF10120.getLenthVal()

void GoToDest(void);

void setup() {
  StepperX.setSpeed(200);
  StepperY.setSpeed(200);
  StepperZ.setSpeed(200);

  pinMode(ApprochSensor, INPUT);
  
  Valve1.begin();
  Valve2.begin();

  Valve1.turnOff();//两个气阀均关闭
  Valve2.turnOff();
  
  Serial.begin(9600);

}

void loop() {
    delay(2000);
    while(TOF10120.getLenthVal()<305)
    {
      StepperZ.step(200);
      Serial.println(TOF10120.getLenthVal());
      delay(5);
    }

    
    GoToDest();
    
    /*************充气**********/
    Valve1.turnOn();
    Valve2.turnOff();
    delay(2000); 

    //Serial.print("StepperZ:");
    //Serial.println(StepperZ.home());

    //int Zstep= StepperZ.Get_total_step();
    //StepperZ.home();

    while(TOF10120.getLenthVal()<305)
    {
      StepperZ.step(200);
      Serial.println(TOF10120.getLenthVal());
      delay(5);
    }
    
    /*********回到原点***********/
    StepperX.home();
    StepperY.home();

    while(TOF10120.getLenthVal()>235)
    {
      StepperZ.step(-200);
      Serial.println(TOF10120.getLenthVal());
      delay(5);
    }
    /**********放气************/
    Valve1.turnOff();
    Valve2.turnOn();
    
    while(1);
}

void GoToDest(void)
{
  Serial.print("x");
  for(int i=1;i<=10;i++)
    {
      Serial.print(LaserSensorX.getLaserStatus(i) );
    }
  Serial.println();
  Serial.print("y");
  for(int i=1;i<=10;i++)
    {
      Serial.print(LaserSensorY.getLaserStatus(i) );
    }
  Serial.println();
  StepperX.step(-(1600+LaserSensorX.getCoordValue()*40));
  StepperY.step((600+LaserSensorY.getCoordValue()*40));
  //while(digitalRead(ApprochSensor)==1)
  while(TOF10120.getLenthVal()>210)
  {
    StepperZ.step(-200);
    Serial.println(TOF10120.getLenthVal());
    delay(5);
  }
  StepperZ.free();
  StepperY.free();
  StepperX.free();
}
