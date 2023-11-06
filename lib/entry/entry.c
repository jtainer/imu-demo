// 
// Entry point for user code
// 'setup' is called once after device reset
// 'loop' is called repeatedly
//
// 2023, Jonathan Tainer
//

#include "mux.h"
#include "imu.h"
#include "main.h"
#include <stdio.h>

void setup(void) {
	I2C_MUX_Init();
	I2C_MUX_Select(0);
	IMU_Init();
}

void loop(void) {
	uint8_t whoami = IMU_ReadRegister(117);
	printf("%x\n", (unsigned int) whoami);
	HAL_Delay(1000);
}
