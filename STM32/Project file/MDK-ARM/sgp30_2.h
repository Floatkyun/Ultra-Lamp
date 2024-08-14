#ifndef __SGP30_H
#define __SGP30_H
#include "delay.h"
#include "main.h"
#include "MyI2C.h"

#define  SGP30_Address_W 0xB0
#define  SGP30_Address_R 0xB1

#define SLCGPIO GPIOB
#define SLCGPIOPIN GPIO_PIN_12
#define SDAGPIO GPIOB
#define SDAGPIOPIN GPIO_PIN_13

void SGP30_WriteReg(uint8_t Regaddress,uint8_t Data);

uint8_t SGP30_ReadWithAck(int Ack);

uint32_t SGP30_GetData(void);

I2C_Device SGP30_Init(void);

uint8_t SGP30_GetID(void);


#endif