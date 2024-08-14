#ifndef __MYI2C_H
#define __MYI2C_H

#include "main.h"
#include "delay.h"

typedef struct I2C_Device
{
	GPIO_TypeDef *SLCGPIO_;
GPIO_TypeDef *SDAGPIO_;
	uint16_t SLCGPIOPIN_;
uint16_t SDAGPIOPIN_;
	
} I2C_Device;



I2C_Device MyI2C_Init(GPIO_TypeDef *SLCGPIO_,GPIO_TypeDef *SDAGPIO_,uint16_t SLCGPIOPIN_,uint16_t SDAGPIOPIN_);

 void MyI2C_W_SCL(int x,I2C_Device* Device);

 void MyI2C_W_SDA(int x,I2C_Device* Device) ;

 uint8_t MyI2C_R_SDA(I2C_Device* Device);

 void MyI2C_Start(I2C_Device* Device);

 void MyI2C_Stop(I2C_Device* Device);

 void MyI2C_SendByte(uint8_t Byte,I2C_Device* Device);

 uint8_t MyI2C_ReceiveByte(I2C_Device* Device);

 void MyI2C_SendAck(uint8_t AckByte,I2C_Device* Device);
 
 uint8_t MyI2C_ReceiveAck(I2C_Device* Device);


#endif