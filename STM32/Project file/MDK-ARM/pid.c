#include "tim.h"

#include "usart.h"
#include "pid.h"

float k_p_x=0.1;
float k_i_x=0;
float k_d_x=0;

float k_p_y=0.1;
float k_i_y=0;
float k_d_y=0;

float curr_loss_x=0;
float last_loss_x=0;
float sum_loss_x=0;
float curr_pos_x=MAX_POS_X/2;

float curr_loss_y=0;
float last_loss_y=0;
float sum_loss_y=0;
float curr_pos_y=MAX_POS_Y/2;


int* get_loss_from_usart(uint8_t* buff)
{
	static int loss[2];//
	int sum=0;
	for(int i=0;i<9;i++)
	{
		if(buff[i]<='9'&&buff[i]>='0')
		{
			sum=sum*10+buff[i]-'0';
		}
	}
	loss[0]=sum/1000;
	loss[1]=sum%1000;
	if(buff[0]=='-')
	{
		loss[0]=-loss[0];
	}
	if(buff[4]=='-')
	{
		loss[1]=-loss[1];
	}
	return loss;
}

void pwm_pos_x(int pos)//0 +6000
{
	pos=250+pos;
	__HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_2, pos*6-1);
}

void pwm_pos_y(int pos)//0 +3000
{
	pos=250+pos;
	__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, pos-1);
}

float pid_loss_x(float loss)
{
	last_loss_x=curr_loss_x;
	curr_loss_x=loss;
	sum_loss_x+=curr_loss_x;
	
	float next_v=k_p_x*curr_loss_x/600 + k_i_x*sum_loss_x/600 + k_d_x*(curr_loss_x-last_loss_x)/600;
	return next_v;
}

float pid_loss_y(float loss)
{
	last_loss_y=curr_loss_y;
	curr_loss_y=loss;
	sum_loss_y+=curr_loss_y;
	
	float next_v=k_p_y*curr_loss_y/600 + k_i_y*sum_loss_y/600 + k_d_y*(curr_loss_y-last_loss_y)/600;
	return next_v;
}

float xianfu(float next_v)
{
	if( next_v<(-MAX_V))
	{
		next_v=-MAX_V;
	}
	if (next_v>MAX_V)
	{
		next_v=MAX_V;
	}
	return next_v;
}

void set_pwm_x(float next_v)
{
	curr_pos_x=curr_pos_x+next_v;
	if (curr_pos_x>MAX_POS_X)
	{
		curr_pos_x=MAX_POS_X;
	}
	if (curr_pos_x<0)
	{
		curr_pos_x=0;
	}
	
	pwm_pos_x((int)(curr_pos_x));
}

void set_pwm_y(float next_v)
{
	curr_pos_y=curr_pos_y+next_v;
	if (curr_pos_y>MAX_POS_Y)
	{
		curr_pos_y=MAX_POS_Y;
	}
	if (curr_pos_y<0)
	{
		curr_pos_y=0;
	}
	//printf("pos:%f\n",curr_pos_y);
	pwm_pos_y((int)(curr_pos_y));
}

void pid_x(float loss)
{
	if (loss<800&&  loss>-800   )
	{
		loss=0;
	}
	float next_v=xianfu(pid_loss_x(loss));
	set_pwm_x(next_v);
}


void pid_y(float loss)
{
	if (loss<800 &&  loss>-800   )
	{
		loss=0;
	}
	float next_v=xianfu(pid_loss_y(loss));
	//printf("next_v:%f\n",next_v);
	set_pwm_y(next_v);

}







