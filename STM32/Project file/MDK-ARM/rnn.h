#ifndef _RNN_H_
#define _RNN_H_

#include "main.h"
#include "room_temp_rnn.h"//调用网络推理所需的各种函数
#include "room_temp_rnn_data.h"//包含网络权重参数
#include "ai_platform.h"//包含各种定义和宏

//extern float rnnOutData[AI_ROOM_TEMP_RNN_OUT_1_SIZE];

void AI_Init_rnn(void);
void AI_Run_rnn(float *pIn, float *pOut);
float* rnn_to_main(void);

#endif