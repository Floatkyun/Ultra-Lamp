//#include "stm32f4xx_hal.h"
#include "sgp30.h"

//I2C_HandleTypeDef hi2c2;

/**
 * @brief  SGP30 初始化
 * @param  void
 * @retval void
 */
void SGP30_Init(void)
{
		uint8_t cmd = 0x06;
    HAL_I2C_Master_Transmit(&hi2c2, 0x00, &cmd, 1, 0xFFFF);//?
		HAL_Delay(100);
    uint8_t senddata[] = {0x20,0x03};// Power on, Continuously H-Resolution Mode
    HAL_I2C_Master_Transmit(&hi2c2, SGP30_ADDRESS_WRITE, senddata, 2, 0xFFFF);
		HAL_Delay(100);
		printf("SGP30 init\n");
}

/**
 * @brief  SGP30 获取基准值
 * @param  uint16_t *eco2_baseline：存储获取到的eCO2基准值
 *         uint16_t *tvoc_baseline：存储获取到的TVOC基准值
 * @retval uint8_t：0-获取基准值正常; 1-无效的CRC校验
 */
uint8_t SGP30_GetBaseline(uint16_t *eco2_baseline, uint16_t *tvoc_baseline)
{
    uint8_t cmd[] = {0x20, 0x15};
    HAL_I2C_Master_Transmit(&hi2c2, SGP30_ADDRESS_WRITE, cmd, sizeof(cmd), HAL_MAX_DELAY);
    HAL_Delay(10); // Wait for measurement to complete
    uint8_t readdata[6];
    HAL_I2C_Master_Receive(&hi2c2, SGP30_ADDRESS_READ, readdata, sizeof(readdata), HAL_MAX_DELAY);
    
    // Check CRC
    uint8_t crc = 0xFF;
    for (int i = 0; i < 2; i++)
    {
        crc ^= readdata[i];
        for (int bit = 8; bit > 0; --bit)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x31;
            else
                crc = (crc << 1);
        }
    }
    
    if (crc != readdata[2])
        return 1; // Invalid CRC
    
    *eco2_baseline = (readdata[0] << 8) | readdata[1];
    *tvoc_baseline = (readdata[3] << 8) | readdata[4];
		//printf("SGP30 Baseline\n");
    return 0;
}


uint8_t SGP30_send_measure(void)
{
	uint8_t cmd[] = {0x20, 0x08};
	HAL_I2C_Master_Transmit(&hi2c2, SGP30_ADDRESS_WRITE, cmd, sizeof(cmd), HAL_MAX_DELAY);
	//printf("SGP30:send");
	return 0;
}

/**
 * @brief  SGP30 获取测量值
 * @param  uint16_t *eCO2：存储获取到的eCO2测量值
 *         uint16_t *TVOC：存储获取到的TVOC测量值
 * @retval uint8_t：0-获取测量值正常; 1-无效的CRC校验
 */
uint8_t SGP30_GetMeasurement(uint16_t *eCO2, uint16_t *TVOC)
{
		//uint8_t cmd[] = {0x20, 0x08};
    //HAL_I2C_Master_Transmit(&hi2c2, SGP30_ADDRESS_WRITE, cmd, sizeof(cmd), HAL_MAX_DELAY);
    //HAL_Delay(10); // Wait for measurement to complete
		
    uint8_t readdata[6] = {0};
    HAL_I2C_Master_Receive(&hi2c2, SGP30_ADDRESS_READ, readdata, sizeof(readdata), HAL_MAX_DELAY);
		//printf("origin data:");
    for(int i=0;i<=5;i++)
		{
			//printf("%u ",readdata[i]);
		}
		//printf("\n");
    // Check CRC
    uint8_t crc = 0xFF;
    for (int i = 0; i < 2; i++)
    {
        crc ^= readdata[i];
        for (int bit = 8; bit > 0; --bit)
        {
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x31;
            else
                crc = (crc << 1);
        }
    }

    //printf("SGP30 measure\n");
    if (crc != readdata[2]){
				printf("SGP30:busy\n");
        return 1; // Invalid CRC
		}
    //printf("SGP30:ok\n");
    *eCO2 = (readdata[0] << 8) | readdata[1];
    *TVOC = (readdata[3] << 8) | readdata[4];
    return 0;
}