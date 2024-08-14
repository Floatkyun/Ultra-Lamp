#include "Kalman.h"
#include "stdlib.h"
//Kalman kfp;

Kalman* Kalman_Init(int last_p, int now_p, int out, int kg, float q, float r)
{
	Kalman* a = (Kalman*)malloc(sizeof(Kalman));
	a->Last_P = 1;			
	a->Now_P = 0;		
	a->out = 0;			
	a->Kg = 0;		
	a->Q = 0;
	a->R = 0.01;
	return a;
}

/**
 *�������˲���
 *@param 	Kalman *kfp �������ṹ�����
 *   			float input ��Ҫ�˲��Ĳ����Ĳ���ֵ�����������Ĳɼ�ֵ��
 *@return �˲���Ĳ���������ֵ��
 */
float KalmanFilter(Kalman *kfp,float input)
{
   //Ԥ��Э����̣�kʱ��ϵͳ����Э���� = k-1ʱ�̵�ϵͳЭ���� + ��������Э����
   kfp->Now_P = kfp->Last_P + kfp->Q;
   //���������淽�̣����������� = kʱ��ϵͳ����Э���� / ��kʱ��ϵͳ����Э���� + �۲�����Э���
   kfp->Kg = kfp->Now_P / (kfp->Now_P + kfp->R);
   //��������ֵ���̣�kʱ��״̬����������ֵ = ״̬������Ԥ��ֵ + ���������� * ������ֵ - ״̬������Ԥ��ֵ��
   kfp->out = kfp->out + kfp->Kg * (input -kfp->out);//��Ϊ��һ�ε�Ԥ��ֵ������һ�ε����ֵ
   //����Э�����: ���ε�ϵͳЭ����� kfp->LastP ����һ������׼����
   kfp->Last_P = (1-kfp->Kg) * kfp->Now_P;
   return kfp->out;
}


