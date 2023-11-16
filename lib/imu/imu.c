// 
// Driver for MPU6050 IMU
//
// Copyright (c) 2023 Jonathan Tainer
//

#include "main.h"
#include "imu.h"

#define I2C_IMU_ADDR	0b01101000
#define I2C_IMU_TIMEOUT	10

// MPU6050 Register Map
#define SELF_TEST_X	13	// R/W
#define SELF_TEST_Y	14	// R/W
#define SELF_TEST_Z	15	// R/W
#define SELF_TEST_A	16	// R/W
#define SMPLRT_DIV	25	// R/W
#define CONFIG		26	// R/W
#define GYRO_CONFIG	27	// R/W
#define ACCEL_CONFIG	28	// R/W
#define FIFO_EN		35	// R/W
#define I2C_MST_CTRL	36	// R/W
#define I2C_SLV0_ADDR	37	// R/W
#define I2C_SLV0_REG	38	// R/W
#define I2C_SLV0_CTRL	39	// R/W
#define I2C_SLV1_ADDR	40	// R/W
#define I2C_SLV1_REG	41	// R/W
#define I2C_SLV1_CTRL	42	// R/W
#define I2C_SLV2_ADDR	43	// R/W
#define I2C_SLV2_REG	44	// R/W
#define I2C_SLV2_CTRL	45	// R/W
#define I2C_SLV3_ADDR	46	// R/W
#define I2C_SLV3_REG	47	// R/W
#define I2C_SLV3_CTRL	48	// R/W
#define I2C_SLV4_ADDR	49	// R/W
#define I2C_SLV4_REG	50	// R/W
#define I2C_SLV4_DO	51	// R/W
#define I2C_SLV4_CTRL	52	// R/W
#define I2C_SLV4_DI	53	// R
#define I2C_MST_STATUS	54	// R
#define INT_PIN_CFG	55	// R/W
#define INT_ENABLE	56	// R/W
#define INT_STATUS	58	// R
#define ACCEL_XOUT_H	59	// R
#define ACCEL_XOUT_L	60	// R
#define ACCEL_YOUT_H	61	// R
#define ACCEL_YOUT_L	62	// R
#define ACCEL_ZOUT_H	63	// R
#define ACCEL_ZOUT_L	64	// R
#define TEMP_OUT_H	65	// R
#define TEMO_OUT_L	66	// R
#define GYRO_XOUT_H	67	// R
#define GYRO_XOUT_L	68	// R
#define GYRO_YOUT_H	69	// R
#define GYRO_YOUT_L	70	// R
#define GYRO_ZOUT_H	71	// R
#define GYRO_ZOUT_L	72	// R
#define EXT_SENS_DATA_00	73	// R
// #define EXT_SENS_DATA_01 ... EXT_SENS_DATA_23
#define I2C_SLV0_DO	99	// R/W
#define I2C_SLV1_DO	100	// R/W
#define I2C_SLV2_DO	101	// R/W
#define I2C_SLV3_DO	102	// R/W
#define I2C_MST_DELAY_CTRL	103	// R/W
#define SIGNAL_PATH_RESET	104	// R/W
#define USER_CTRL	106	// R/W
#define PWR_MGMT_1	107	// R/W
#define PWR_MGMT_2	108	// R/W
#define FIFO_COUNT_H	114	// R/W
#define FIFO_COUNT_L	115	// R/W
#define FIFO_R_W	116	// R/W
#define WHO_AM_I	117	// R


extern I2C_HandleTypeDef hi2c1;

void IMU_WriteRegister(uint8_t regAddr, uint8_t regVal) {
	uint8_t buf[] = { regAddr, regVal };
	HAL_I2C_Master_Transmit(&hi2c1, I2C_IMU_ADDR, buf, sizeof(buf), I2C_IMU_TIMEOUT);
}

uint8_t IMU_ReadRegister(uint8_t regAddr) {
	uint8_t regVal = 0;
	HAL_I2C_Mem_Read(&hi2c1, I2C_IMU_ADDR, regAddr, I2C_MEMADD_SIZE_8BIT, &regVal, 1, I2C_IMU_TIMEOUT);
	return regVal;
}

void IMU_Init() {
	return;
}
