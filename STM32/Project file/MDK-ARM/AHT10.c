#include "AHT10.h"

/**
 * @brief  AHT10 ��ʼ��
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
 * @brief  AHT10 ��λ
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
 * @brief  AHT10��������
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
 * @brief  AHT10 �豸��ȡ ���ʪ�Ⱥ��¶�
 * @param  float *humidity��ʪ����Ϣ��
 *         float *temperature���¶���Ϣ��
 * @retval uint8_t��0-��ȡ��������; 1-��ȡ�豸ʧ�ܣ��豸һֱ����æ״̬�����ܻ�ȡ����
 */
uint8_t AHT10_Read_predata(float *humidity, float *temperature)
{
    //AHT10_TrigeMea();
    //HAL_Delay(75);
    static uint32_t humi, temp;
    uint8_t readdata[6];
    uint8_t BusyIndication, CalEnable;
    HAL_I2C_Master_Receive(&hi2c2, AHT10_Read_ADDRESS, readdata, 6, 0xFFFF);
    BusyIndication = (readdata[0] >> 7) & 0x01; // ״̬��־λ
    CalEnable = (readdata[0] >> 3) & 0x01;      // У׼��־λ
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

