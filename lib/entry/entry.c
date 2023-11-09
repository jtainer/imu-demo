// 
// Entry point for user code
// 'setup' is called once after device reset
// 'loop' is called repeatedly
//
// 2023, Jonathan Tainer
//

#include "mux.h"
#include "imu.h"
#include "mpu6050.h"
#include "main.h"
#include <stdio.h>

#define IMU_CHANNELS 16
MPU6050_t imu[IMU_CHANNELS] = { 0 };

void setup(void) {
	I2C_MUX_Init();
	I2C_MUX_Select(0);
	while (MPU6050_Init(&hi2c1) == 1);
}

void loop(void) {
	MPU6050_Read_All(&hi2c1, &imu[0]);
	printf("Ax = %d\tAy = %d\t Az = %d\r\n",
		imu[0].Ax, imu[0].Ay, imu[0].Az);
	HAL_Delay(100);
}
