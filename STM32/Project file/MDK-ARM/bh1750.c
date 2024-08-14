//#include "stm32f4xx_hal.h"
#include "bh1750.h"
//I2C_HandleTypeDef hi2c2;

/**
 * @brief  BH1750 初始化
 * @param  void
 * @retval void
 */
void BH1750_Init(void)
{
    uint8_t senddata;
    senddata = 0x01; // Power on, Continuously H-Resolution Mode
    HAL_I2C_Master_Transmit(&hi2c2, BH1750_ADDRESS_ground, &senddata, 1, 0xFFFF);
		printf("BH1750 init\n");
}

/**
 * @brief  BH1750 触发测量
 * @param  void
 * @retval void
 */
void BH1750_TriggerMeasurement(void)
{
    uint8_t senddata;
    senddata = 0x20; // High resolution mode, measure at 1lx resolution, measurement time is typically 120ms
    HAL_I2C_Master_Transmit(&hi2c2, BH1750_ADDRESS_ground, &senddata, 1, 0xFFFF);
		//printf("BH1750 Trig\n");
    //HAL_Delay(10); // Wait for measurement to complete
}

/**
 * @brief  BH1750 读取光强数据
 * @param  float *lux：存储读取到的光强数据
 * @retval uint8_t：0-读取数据正常；1-传感器忙，无法获取数据
 */
uint8_t BH1750_ReadLightIntensity(float *lux)
{
		//BH1750_TriggerMeasurement();
    uint8_t readdata[2];
    HAL_I2C_Master_Receive(&hi2c2, BH1750_ADDRESS_ground, readdata, 2, 0xFFFF);
    *lux = ((readdata[0] << 8) | readdata[1]) / 1.2; // Convert raw data to lux (resolution of 1 lx)
    //printf("BH1750 measure\n");
    // Check if sensor is busy
    if ((readdata[0] & 0x80) != 0){
				//printf("BH1750:busy\n");
        return 1; // Sensor is busy, unable to get data
		}
    else{
				//printf("BH1750:ok\n");
        return 0; // Data reading is normal
		}
}

/**
 * @brief  Main function
 * @param  None
 * @retval None
 */
