#ifndef _FCN_H_
#define _FCN_H_

#include "main.h"
#include "room_state_fcn.h"//调用网络推理所需的各种函数
#include "room_state_fcn_data.h"//包含网络权重参数
#include "ai_platform.h"//包含各种定义和宏

//extern float fcnOutData[AI_ROOM_STATE_FCN_OUT_1_SIZE];

void AI_Init_fcn(void);
void AI_Run_fcn(float *pIn, float *pOut);
float* fcn_to_main(void);

#endif