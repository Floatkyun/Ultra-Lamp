#ifndef _BH1750_H_
#define _BH1750_H_

#include "i2c.h"

#define BH1750_ADDRESS_ground             (0x23 << 1) // BH1750 I2C address ground 010,0011
#define BH1750_ADDRESS_vcc                (0x5C << 1) // BH1750 I2C address vcc 101,1100

void BH1750_Init(void);
void BH1750_TriggerMeasurement(void);
uint8_t BH1750_ReadLightIntensity(float *lux);

#endif