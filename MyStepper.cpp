#include "Arduino.h"
#include "MyStepper.h"

/********************************************************
 *
 * @file    MyStepper.cpp
 * @author  QQS
 * @date    2020/12/21
 * @email   chilkings.mail@gnmail.com
 * @github  https://github.com/chilkings
 *
********************************************************/

Stepper::Stepper(int number_of_steps, int PUL_pin, int DIR_pin,int ENA_pin)
{
  this->direction = 0;                     // 方向正转
  this->number_of_steps = number_of_steps; // 转一圈的总步长
  this->step_delay = 50;                   //设置默认速度
  this->direction = 0;                     //设置默认方向 正转
  this->total_step = 0;
  
  // Arduino pins for the motor control connection:
  this->PUL_pin = PUL_pin;
  this->DIR_pin = DIR_pin;
  this->ENA_pin = ENA_pin;

  // setup the pins on the microcontroller:
  pinMode(this->PUL_pin, OUTPUT);
  pinMode(this->DIR_pin, OUTPUT);
  pinMode(this->ENA_pin, OUTPUT);
}



/*
 * Sets the speed in revs per minute
 */
void Stepper::setSpeed(long whatSpeed)
{
  this->step_delay = whatSpeed;
}

/*
 * Free the motor control
 */
void Stepper::free(void)
{
  digitalWrite(this->ENA_pin, HIGH);
}

/*
 * Moves the motor steps_to_move steps.  If the number is negative,
 * the motor moves in the reverse direction.
 */
void Stepper::step(int steps_to_move)
{
  int steps_left = abs(steps_to_move);  // how many steps to take

  this->total_step += steps_to_move;

  if (steps_to_move > 0) { this->direction = 1; }
  if (steps_to_move < 0) { this->direction = 0; }
  
  digitalWrite(this->ENA_pin, LOW);               //使能控制IO
  digitalWrite(this->DIR_pin, this->direction);  //设置转动方向

  for (int i = 0; i < steps_left; i++) 
  {
    digitalWrite(this->PUL_pin, HIGH);
    delayMicroseconds(step_delay);
    digitalWrite(this->PUL_pin, LOW);
    delayMicroseconds(step_delay);
  }
  
}

int Stepper::Get_total_step(void)
{
    return this->total_step;
}

int Stepper::home(void)
{
  
  step(-this->total_step);
//  return this->total_step;
  this->total_step=0;
}

/*
  version() returns the version of the library:
*/
int Stepper::version(void)
{
  return 1;
}
