#ifndef _RNN_H_
#define _RNN_H_

#include "main.h"
#include "room_temp_rnn.h"//����������������ĸ��ֺ���
#include "room_temp_rnn_data.h"//��������Ȩ�ز���
#include "ai_platform.h"//�������ֶ���ͺ�

//extern float rnnOutData[AI_ROOM_TEMP_RNN_OUT_1_SIZE];

void AI_Init_rnn(void);
void AI_Run_rnn(float *pIn, float *pOut);
float* rnn_to_main(void);

#endif