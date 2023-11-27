#ifndef _AVOID_H_
#define _AVOID_H_
#include <Servo.h>
#include "config.h"
#include <NewPing.h>

NewPing mySensor(ULTRASONIC_SENSOR_TRIG, ULTRASONIC_SENSOR_ECHO, 400);
Servo myServo;

class Avoid_Obstecels {

public:
  int distanceLeft = 0;
  int distance = 0;
  int distanceRight = 0;

  void init(void);
  void rotateMotor(int rightMotorSpeed, int leftMotorSpeed);
  void set_motion();
};

#endif
