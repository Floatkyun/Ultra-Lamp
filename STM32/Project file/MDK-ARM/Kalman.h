#ifndef Kalman_H
#define Kalman_H

#include "main.h"

typedef struct 
{
    float Last_P;//�ϴι���Э���� ������Ϊ0 ! ! ! ! ! 
    float Now_P;//��ǰ����Э����
    float out;//�������˲������
    float Kg;//����������
    float Q;//��������Э����
    float R;//�۲�����Э����
}Kalman;

Kalman* Kalman_Init(int last_p, int now_p, int out, int kg, float q, float r);
float KalmanFilter(Kalman *kfp,float input);

#endif
