#ifndef __SGP30_H__
#define __SGP30_H__
 
//#include "main.h"
#include "i2c.h"

#define SGP30_ADDRESS_WRITE             (0x58 << 1) // SGP30 I2C address
#define SGP30_ADDRESS_READ             (0Xb1) // SGP30 I2C address

void SGP30_Init(void);
uint8_t SGP30_GetBaseline(uint16_t *eco2_baseline, uint16_t *tvoc_baseline);
uint8_t SGP30_GetMeasurement(uint16_t *eCO2, uint16_t *TVOC);
uint8_t SGP30_send_measure(void);

#endif