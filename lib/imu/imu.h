// 
// Driver for MPU6050 IMU
//
// 2023, Jonathan Tainer
//

#ifndef IMU_H
#define IMU_H

#include <stdint.h>

void IMU_WriteRegister(uint8_t regAddr, uint8_t regVal);

uint8_t IMU_ReadRegister(uint8_t regAddr);

void IMU_Init();

#endif
