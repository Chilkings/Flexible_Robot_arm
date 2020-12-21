#include "Mystepper.h"
#include "LaserSensor.h"

Stepper myStepper(1600, 9, 10, 8);
LaserSensor myLaserSensor(2,3,4,5,6,7,8,9,10,11);
const int stepsPerRevolution = 800;

void setup() {
  myStepper.setSpeed(200);
  
  Serial.begin(9600);
}

void loop() {
//  Serial.println("clockwise");
//  myStepper.step(stepsPerRevolution);
//  delay(500);
//
//  // step one revolution in the other direction:
//  Serial.println("counterclockwise");
//  myStepper.step(-stepsPerRevolution);
//  delay(500);                    // wait for a second
//
//  myStepper.free();
//  while(1);

    Serial.println(myLaserSensor.getLightNum());
    Serial.println(myLaserSensor.getCoordValue());
    delay(500);
}
