#include "AHT10.h"

/**
 * @brief  AHT10 初始化
 * @param  void
 * @retval void
 */
void AHT10_Init(void)
{
    uint8_t senddata;
    senddata = AHT10_Init_com;
    HAL_I2C_Master_Transmit(&hi2c2, AHT10_Write_ADDRESS, &senddata, 1, 0xFFFF);
}

/**
 * @brief  AHT10 软复位
 * @param  void
 * @retval void
 */
void AHT10_SoftReset(void)
{
    uint8_t senddata;
    senddata = AHT10_SoftReset_com;
    HAL_I2C_Master_Transmit(&hi2c2, AHT10_Write_ADDRESS, &senddata, 1, 0xFFFF);
    HAL_Delay(20);
}

/**
 * @brief  AHT10触发测量
 * @param  void
 * @retval void
 */
void AHT10_TrigeMea(void)
{
    uint8_t senddata[3];
    senddata[0] = AHT10_TrigeMea_com;
    senddata[1] = 0x33; // DATA0
    senddata[2] = 0x00; // DATA1
    HAL_I2C_Master_Transmit(&hi2c2, AHT10_Write_ADDRESS, senddata, 3, 0xFFFF);
    //HAL_Delay(80);
}

/**
 * @brief  AHT10 设备读取 相对湿度和温度
 * @param  float *humidity：湿度信息；
 *         float *temperature：温度信息。
 * @retval uint8_t：0-读取数据正常; 1-读取设备失败，设备一直处于忙状态，不能获取数据
 */
uint8_t AHT10_Read_predata(float *humidity, float *temperature)
{
    //AHT10_TrigeMea();
    //HAL_Delay(75);
    static uint32_t humi, temp;
    uint8_t readdata[6];
    uint8_t BusyIndication, CalEnable;
    HAL_I2C_Master_Receive(&hi2c2, AHT10_Read_ADDRESS, readdata, 6, 0xFFFF);
    BusyIndication = (readdata[0] >> 7) & 0x01; // 状态标志位
    CalEnable = (readdata[0] >> 3) & 0x01;      // 校准标志位
    if (CalEnable == 0)
    {
        AHT10_SoftReset();
    }
    if (BusyIndication == 0)
    {
        humi = (readdata[1] << 12) | (readdata[2] << 4) | (readdata[3] >> 4);
        temp = ((readdata[3] & 0x0F) << 16) | (readdata[4] << 8) | (readdata[5]);
        *humidity = ((humi * 100.0) / 1048576);
        *temperature = ((float)temp / 1048576) * 200 - 50;
        return 0;
    }
    return 1;
}

