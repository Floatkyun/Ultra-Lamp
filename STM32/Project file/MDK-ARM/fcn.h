#ifndef _FCN_H_
#define _FCN_H_

#include "main.h"
#include "room_state_fcn.h"//����������������ĸ��ֺ���
#include "room_state_fcn_data.h"//��������Ȩ�ز���
#include "ai_platform.h"//�������ֶ���ͺ�

//extern float fcnOutData[AI_ROOM_STATE_FCN_OUT_1_SIZE];

void AI_Init_fcn(void);
void AI_Run_fcn(float *pIn, float *pOut);
float* fcn_to_main(void);

#endif