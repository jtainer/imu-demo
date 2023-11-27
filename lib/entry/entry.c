// 
// Entry point for user code
// 'setup' is called once after device reset
// 'loop' is called repeatedly
//
// Copyright (c) 2023 Jonathan Tainer
//

#include <stdio.h>
#include "main.h"
#include "mux.h"
#include "mpu6050.h"
#include "ssd1306.h"

#define IMU_CHANNELS 16
MPU6050_t imu[IMU_CHANNELS] = { 0 };

void setup(void) {
	I2C_MUX_Init();
	I2C_MUX_Select(0);
	while (MPU6050_Init(&hi2c1) == 1);
//	ssd1306_Init();
}

void loop(void) {
	static int screen_on = 0;
	screen_on = !screen_on;
	MPU6050_Read_All(&hi2c1, &imu[0]);
	printf("w = %d\t\tx = %d\t\ty = %d\t\tz = %d\n",
		(int)imu[0].rotation.w, (int)imu[0].rotation.x,
		(int)imu[0].rotation.y, (int)imu[0].rotation.z);
//	ssd1306_Fill(screen_on ? White : Black);
	HAL_Delay(10);
}
