// 
// Entry point for user code
// 'setup' is called once after device reset
// 'loop' is called repeatedly
//
// Copyright (c) 2023 Jonathan Tainer
//

#include <stdio.h>
#include <math.h>
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
	imu[0].rotation.w=1;
	ssd1306_Init();
}

void loop(void) {
	MPU6050_Read_All(&hi2c1, &imu[0]);
	vec4 quat = imu[0].rotation;
	printf("w = %f\t\tx = %f\t\ty = %f\t\tz = %f\r\n",
		quat.w, quat.x, quat.y, quat.z);

	// Project acceleration vector onto XY plane and calculate rotation about Z axis
	static float theta0 = 0.f;
	float theta1 = atan2f(imu[0].Ax, imu[0].Ay);

	// Detect when the -PI/+PI boundary is crossed to handle it appropriately
	if (theta0-theta1 > M_PI) {
		theta0 -= 2*M_PI;
	}
	else if (theta1-theta0 > M_PI) {
		theta0 += 2*M_PI;
	}
	// Apply simple low pass filter
	theta0 = 0.9f*theta0 + 0.1f * theta1;

	// Draw a line that always points down
	uint8_t x0 = 128/2;
	uint8_t y0 = 64/2;
	uint8_t x1 = x0 + 32 * cosf(theta0);
	uint8_t y1 = y0 + 32 * sinf(theta0);
	
	ssd1306_Fill(Black);
	ssd1306_Line(x0,y0,x1,y1,White);
	ssd1306_UpdateScreen();
	HAL_Delay(10);
}
