#ifndef __PID_H
#define __PID_H

#define T 15

#define MAX_POS_X (1000)
#define MAX_POS_Y (450)

#define MAX_V (16*T)

#include "main.h"

int* get_loss_from_usart(uint8_t* buff);
void pid_test(float target);
void pid_x(float loss);
void pid_y(float loss);
#endif