#ifndef __IMU_H
#define _IMU_H
#include <Arduino.h>
#include <MPU6050_light.h>
#include <Wire.h>
#include <SPI.h>

class IMU{
  int *angles;
  MPU6050 *mpu;
  int readrate;
  int temp;
  unsigned int timer;
  signed long offset_x;
  signed long offset_y;
  signed long offset_z;
public:
IMU(){
this-> mpu = new MPU6050(Wire);
this->angles = new int[3];
this->temp = 0;
this->readrate = 1000;
};

void init();
void update();
void display();
int *getangels();
int getTemprature();
};
#endif 