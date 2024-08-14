/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "rtc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "fsmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#if 0
#include "room_temp_rnn.h"//调用网络推理所需的各种函数
#include "room_temp_rnn_data.h"//包含网络权重参数
#endif
#if 0
#include "room_state_fcn.h"//调用网络推理所需的各种函数
#include "room_state_fcn_data.h"//包含网络权重参数
#include "ai_platform.h"//包含各种定义和宏
#endif

#include "lcd.h"
#include "touch.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "gui_guider.h"
#include "events_init.h"


#include "pid.h"
#include "AHT10.h"
#include "ws2812.h"
#include "bh1750.h"
#include "sgp30.h"
#include "Kalman.h"
#include "rnn.h"
#include "fcn.h"
#include "work_detector.h"
#include "math.h"
#include "stdlib.h"

RTC_TimeTypeDef time;
RTC_DateTypeDef date;

char now_time[9] = {0};
	
int* loss_;
uint8_t rx_buf[11];
int target_=2000;

int count=0,count_led=0,count_ai = 0;
int a=0;

float temp=26,humi=50,lux=500;

static float pre_temp = 26;

uint16_t eCO2=65535,TVOC=401;
uint16_t base_eCO2,base_TVOC;

uint16_t num_of_led;
uint8_t bright = 128;
uint8_t check_light = 1;
bool flag_light = 1;

static float env_score = 60;

Kalman* kalman_temp;
Kalman* kalman_humi;
Kalman* kalman_co2;
Kalman* kalman_lux;
Kalman* kalman_pre_temp;
Kalman* kalman_score;

int para_work_max = 0;//可调参数
int para_game_max = 0;
int para_game_turn = 0;
int para_mode = 0;//
	
int sum_work = 0;
int sum_game = 0;
int sum_water = 0;
int delay = 0;

int now_work=0;
int now_game=0;
int now_drink=0;
int all_work=0;
int all_book=0;
int all_game=0;
int all_compu=0;
int all_mouse=0;
int all_water=0;

float tqdm_work = 0;
float tqdm_game = 0;
float tqdm_water = 100;

int over_game=0;
int over_work=0;
int need_drink=0;

float visual_rnn[6] = {17.0,16.0,15.0,17.0,19.0,26.0};
float visual_fcn[4] = {20,40,400,500};

lv_ui guider_ui;

int screens = 0;
int chat = 0;

int light_mode = 1;//0:手动，1：自动
int light_bright = 30;

int t=3;//main_time

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

#if 0//rnn

ai_handle rnn=AI_HANDLE_NULL;
static float rnnInData[AI_ROOM_TEMP_RNN_IN_1_SIZE]={17.0,16.0,15.0,17.0,19.0,26.0};
static float rnnOutData[AI_ROOM_TEMP_RNN_OUT_1_SIZE];
ai_u8 rnn_activations[AI_ROOM_TEMP_RNN_DATA_ACTIVATIONS_SIZE];

ai_buffer * rnn_input;
ai_buffer * rnn_output;


static void AI_Init_rnn(void)
{
  ai_error err;
  const ai_handle rnn_act_addr[] = { rnn_activations };
  err = ai_room_temp_rnn_create_and_init(&rnn, rnn_act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    printf("ai_rnn_create error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	else 
	{
		printf("RNN AI init success!\r\n");
	}
  rnn_input = ai_room_temp_rnn_inputs_get(rnn, NULL);
  rnn_output = ai_room_temp_rnn_outputs_get(rnn, NULL);
}


static void AI_Run_rnn(float *pIn, float *pOut)
{
	char logStr[100];
	int count = 0;
	float max = 0;
  ai_i32 batch;
  ai_error err;

  rnn_input[0].data = AI_HANDLE_PTR(pIn);
  rnn_output[0].data = AI_HANDLE_PTR(pOut);

  batch = ai_room_temp_rnn_run(rnn, rnn_input, rnn_output);
  if (batch != 1) {
    err = ai_room_temp_rnn_get_error(rnn);
    printf("AI ai_rnn_run error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	printf("rnn_result=%8.6f",rnnOutData[0]);
}
#endif

#if 0//fcn

ai_handle fcn=AI_HANDLE_NULL;
static float fcnInData[AI_ROOM_STATE_FCN_IN_1_SIZE]={20,40,400,500};
static float fcnOutData[AI_ROOM_STATE_FCN_OUT_1_SIZE];
ai_u8 fcn_activations[AI_ROOM_STATE_FCN_DATA_ACTIVATIONS_SIZE];

ai_buffer * fcn_input;
ai_buffer * fcn_output;

static void AI_Init_fcn(void)
{
  ai_error err;
  const ai_handle fcn_act_addr[] = { fcn_activations };
  err = ai_room_state_fcn_create_and_init(&fcn, fcn_act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    printf("ai_fcn_create error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	else 
	{
		printf("FCN AI init success!\r\n");
	}
  fcn_input = ai_room_state_fcn_inputs_get(fcn, NULL);
  fcn_output = ai_room_state_fcn_outputs_get(fcn, NULL);
}


static void AI_Run_fcn(float *pIn, float *pOut)
{
	char logStr[100];
	int count = 0;
	float max = 0;
  ai_i32 batch;
  ai_error err;

  fcn_input[0].data = AI_HANDLE_PTR(pIn);
  fcn_output[0].data = AI_HANDLE_PTR(pOut);

  batch = ai_room_state_fcn_run(fcn, fcn_input, fcn_output);
  if (batch != 1) {
    err = ai_room_state_fcn_get_error(fcn);
    printf("AI ai_network_run error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	printf("fcn_result=%8.6f,%8.6f",fcnOutData[0],fcnOutData[1]);
	env_score = (int)score(fcnOutData[1]);
	
	if(fcnOutData[0]<fcnOutData[1])
	{
		printf("fcn_result:环境条件好");
	}
	else	if(fcnOutData[0]>=fcnOutData[1])
	{
		printf("fcn_result:环境条件不好");
	}
}
#endif

char* int_to_string(int a)
{
	int length = snprintf(NULL, 0, "%d", a) + 1;
	char* str = (char*)malloc(length*sizeof(char));
  if (str == NULL) {
		free(str);
		return NULL; // 内存分配失败
  }	
	sprintf(str,"%d",a);
	return str;
}
char* float_to_string(float a)//?
{
	int length = snprintf(NULL, 0, "%.2f", a) + 1;
	char* str = (char*)malloc(length*sizeof(char));
  if (str == NULL) {
		free(str);
		return NULL; // 内存分配失败
  }	
	sprintf(str,"%.2f",a);
	return str;
}

void Run_ai()
{
	visual_rnn[5] = temp;
	AI_Run_rnn(visual_rnn,rnn_to_main());
	visual_fcn[0] = temp;
	visual_fcn[1] = humi;
	visual_fcn[2] = lux;
	visual_fcn[3] = (float)eCO2;
	AI_Run_fcn(visual_fcn,fcn_to_main());
}

float score(float x)//由fcnoutdata[1]生成env_score
{
	return 100.0*(16*(x-0.5)*(x-0.5)*(x-0.5)*(x-0.5)*(x-0.5)+0.5);
}

void measure_init(void)//AHT and BH1750 
{
		AHT10_Init();
		BH1750_Init();
		SGP30_Init();
//		RGB_RED(Pixel_NUM);
		HAL_Delay(10);
}
#if 0
//void start_measures(void)
//{
//		//AHT10_Read_predata(&humi,&temp);
//		//HAL_Delay(10);
//		//BH1750_ReadLightIntensity(&lux);
//		//HAL_Delay(10);
//		SGP30_GetBaseline(&base_eCO2,&base_TVOC);
//		HAL_Delay(1);
//		SGP30_GetMeasurement(&eCO2, &TVOC);
//		printf("humi:%f\n temp:%f\n lux:%f\n base_eCO2:%u\n base_TVOC:%u\n eCO2:%u\n TVOC:%u\n",humi,temp,lux,base_eCO2,base_TVOC,eCO2,TVOC);
//}
#endif
#if 0
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)//A上升沿触发中断
//{
//	printf("%d\n",bright);
//	
//	if(GPIO_Pin==GPIO_PIN_5 && check_light == 1 && flag_light == 1)
//	{
//		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==1)//B为高电平
//		{
//			bright-=10;
//			printf("low\n");
//			if(bright<=10)
//			{
//				printf("lowest\n");
//				bright=11;
//			}
//		}
//		else//B为低电平
//		{
//			bright+=10;
//			printf("high\n");
//			if(bright>=240)
//			{
//				printf("highest\n");
//				bright=239;
//			}
//		}
//		__HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, bright*4);
//		RGB_WHITE_Change(Pixel_NUM,bright);
//	}
//	if(GPIO_Pin==GPIO_PIN_6 && flag_light == 1)
//	{
//		check_light = 1 - check_light;
//		printf("turn");
//	}
//	flag_light = 0;
//	HAL_TIM_Base_Start_IT(&htim7);
//}
#endif
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim){
    if(htim->Instance==TIM2){	//定时器2中断 10ms	
			printf("loss_x :%d, loss_y :%d\n",loss_[0],-loss_[1]);//debug
		pid_x(loss_[0]*20);
		pid_y(-loss_[1]*20);
			count++;
			if(count==4)
			{
				HAL_TIM_Base_Stop_IT(&htim2);
				count=0;
			}
    }
		
		else if(htim->Instance==TIM3){ //定时器3中断 200ms
				//RGB_start();
				if(light_mode == 0)
				{
					RGB_WHITE_Change(Pixel_NUM,(light_bright/100.0)*255);
					__HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, (int)(pow(light_bright/100.0,2.2)*1000));
					//printf("b0\n");
				}
				else
				{
					if(light_mode == 1)//auto
					{
						float x = lux;
						float y ;
						if(x>=0 && x<=300)
							y = (7.0/30.0) * x + 30.0;
						else if(x>300)
							y = (-1.0/17.0) * (x-2000.0);
						
						if(y>=100)
							y=100;
						if(y<=0)
							y=0;
						
						__HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, (int)(pow(y/100.0,2.2)*1000));
						//printf("b1\n");
					}
					else
					{
						__HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, 0);
					}
				}
				count_led++;
				if(count_led == 5)
				{
					//printf("env_score: %d\n",(int)env_score);
					//printf("pre_temp: %d\n",(int)pre_temp);
					//printf("%d %d %d\n",guider_ui.screen_main_del,guider_ui.screen_work_setting_del,guider_ui.screen_work_del);
//					printf(float_to_string(10.25));
					if(screens == 0)//important
					{
						sum_work = 0;
						sum_game = 0;
						sum_water = 0;
						delay = 0;
						now_work=0;
						now_game=0;
						now_drink=0;
						all_work=0;
						all_book=0;
						all_game=0;
						all_compu=0;
						all_mouse=0;
						all_water=0;
						tqdm_work = 0;
						tqdm_game = 0;
						tqdm_water = 100;
						
						char *a = int_to_string((int)env_score);
						char *b = int_to_string((int)pre_temp);
						lv_label_set_text(guider_ui.screen_main_label_envscore, a);//screen_main
						free(a);
						lv_label_set_text(guider_ui.screen_main_label_temp_pre, b);//screen_main
						free(b);
						//printf("s0\n");
//						if(t>0)
//						{
							set_time();
//							t--;
//						}
					}
					else if(screens == 1)
					{
						sum_work = 0;
						sum_game = 0;
						sum_water = 0;
						delay = 0;
						now_work=0;
						now_game=0;
						now_drink=0;
						all_work=0;
						all_book=0;
						all_game=0;
						all_compu=0;
						all_mouse=0;
						all_water=0;
						tqdm_work = 0;
						tqdm_game = 0;
						tqdm_water = 100;
						//printf("s1\n");
					}
					else if(screens == 2)
					{						
						char *a = int_to_string((int)env_score);
						char *b = int_to_string((int)pre_temp);
						lv_label_set_text(guider_ui.screen_work_label_envscore, a);//screen_work
						free(a);
						lv_label_set_text(guider_ui.screen_work_label_temp_pre, b);//screen_work
						free(b);
						//printf("s2\n");
						
					}
					else if(screens == -1)
					{
						
					}

					//count_led=0;
				
/*
				if(count_led == 5)
				{
					char* a = "work_detector_stop\n";
					HAL_UART_Transmit(&huart2,(unsigned char*)a,sizeof(a),10000);
					
					printf(rx_buf);
				}
				*/
				//别删下面这段
				
					if(eCO2 >60000)
					{
						eCO2 = 400;
					}
//					temp = KalmanFilter(kalman_temp, temp);
//					humi = KalmanFilter(kalman_humi, humi);
//					eCO2 = KalmanFilter(kalman_co2, eCO2);
//					lux = KalmanFilter(kalman_lux, lux);
//					pre_temp = KalmanFilter(kalman_pre_temp, pre_temp);
//					env_score = KalmanFilter(kalman_score, env_score);
					
					//printf("env_score: %d\n",env_score);
					//printf("pre_temp: %d\n",pre_temp);

					transmit_message((int)temp,(int)humi,eCO2,(int)lux,rnn_to_main()[0],env_score);//important
					//printf("_|");
					pre_temp = rnn_to_main()[0];
					env_score = score(fcn_to_main()[1]);//impor
					BH1750_ReadLightIntensity(&lux);
					//printf("_|");
					//SGP30_GetBaseline(&base_eCO2,&base_TVOC);
					SGP30_GetMeasurement(&eCO2, &TVOC);
//					printf("_|");
					AHT10_Read_predata(&humi, &temp);
					//printf("humi:%f\n temp:%f\n lux:%f\n base_eCO2:%u\n base_TVOC:%u\n eCO2:%u\n TVOC:%u\n",humi,temp,lux,base_eCO2,base_TVOC,eCO2,TVOC);
					AHT10_TrigeMea();
//					printf("_|");
					SGP30_send_measure();
//					printf("_|");
					BH1750_TriggerMeasurement();
//					printf("_|");

					if(eCO2 >60000)
					{
						eCO2 = 400;
					}
					
					transmit_message((int)temp,(int)humi,eCO2,(int)lux,rnn_to_main()[0],env_score);
					pre_temp = rnn_to_main()[0];
  				env_score = score(fcn_to_main()[1]);//impor
					
						Run_ai();
//					printf("_|\n");
					count_led=0;
				}

				
		}
//		else if(htim->Instance==TIM7){ //定时器5中断 ms -> 消抖
//			if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1 && check_light == 1)//
//			{
//				printf("turn on the light\n");
//				bright = 128;
//				RGB_WHITE_Change(Pixel_NUM,bright);
//				__HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, bright*4);
//				check_light = 1;
//			}
//			if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==1 && check_light == 0)//
//			{
//				printf("turn off the light\n");
//				RGB_WHITE_Change(Pixel_NUM,0);
//				__HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, 0);
//				check_light = 0;
//			}			
//			
//			if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0)
//				check_light = 1-check_light;
//			flag_light = 1;
//			printf("7\n");
//			HAL_TIM_Base_Stop_IT(&htim7);
//		}
		
//		else if(htim->Instance==TIM12){
//			lv_task_handler();
//			lv_tick_inc(1);
//			
//		}
}

//void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc)
//{
//	printf("HELLO\n");
//	//HAL_RTC_GetTime(&hrtc,&time,RTC_FORMAT_BIN);
//	HAL_RTC_GetTime(hrtc,&time,RTC_FORMAT_BIN);
//	printf("Time:%02d:%02d:%02d\n",time.Hours,time.Minutes,time.Seconds); 
//	now_time[0] = (int)time.Hours/10 + '0';
//	now_time[1] = (int)time.Hours%10 + '0';
//	now_time[2] = ':';
//	now_time[3] = (int)time.Minutes/10 + '0';
//	now_time[4] = (int)time.Minutes%10 + '0';
//	'\0';
//	printf(now_time);now_time[5] = ':'	;
//	now_time[6] = (int)time.Seconds/10 + '0';
//	now_time[7] = (int)time.Seconds%10 + '0';
//	now_time[8] = 
//	printf("\n");
////	HAL_RTC_GetDate(&hrtc,&date,RTC_FORMAT_BIN);
////	printf("Date:20%02d-%02d-%02d",date.Year,date.Month,date.Date); 
//}
	

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{

	if(huart->Instance == USART2)
	{
//		printf(rx_buf);
//		printf("---------------------------\n");
		
		if(rx_buf[0]=='0' && screens == 2)
		{
		//printf("0\n");
		//printf(rx_buf);
		loss_= get_loss_from_usart(rx_buf+1);
	//uint8_t buffer[12];
	//sprintf(buffer, "loss0=%d",loss_[0] );
	//printf((uint8_t*)buffer);
	//sprintf(buffer, "loss1=%d",loss_[1] );
	//printf((uint8_t*)buffer);
		//printf("loss%d",loss_[0]);
		if(loss_[0]!=0 || loss_[1]!=0)
		{
			pid_x(loss_[0]*20);
		  pid_y(-loss_[1]*20);
		}

		//printf("l_x:%d, l_y:%d\n",loss_[0],-loss_[1]);
		HAL_TIM_Base_Start_IT(&htim2);
		}
		
		else if(rx_buf[0] == 'w')
		{
		now_work = state_analyser.work_count_analyser(rx_buf);
//		sum_work += now_work;
//		if(sum_work<=0)
//			sum_work=0;
		
		now_game = state_analyser.game_count_analyser(rx_buf);
		sum_game += now_game;
//		
//		float a=0;
//		if(now_work==1)
//			a=0.8;
//		else
//			a=0.2;
//		
		tqdm_game += 0.5*(now_game+1) - you_mode*now_work;//“摸鱼值”
		if(sum_game<=0)
			sum_game=0;

		if(now_game==-1)//game的非线性回溯处理另算
			now_game=0;
		
		printf("rx_buf6: %c\n",rx_buf[6]);
		now_drink = state_analyser.drink_count_analyser(rx_buf);
		sum_water += now_drink;
		
		if(now_game <=0 && now_work <= 0)
		{
			delay++;
		}
		else
		{
			delay=0;
		}
		
		if(now_game == 1 && now_work == 1)
		{
			printf("yixinduoyong\n");//一心多用
		}
		
		if(now_game == 2*(1-GAME_TIME))//game_to_work的非线性回溯处理:
		{
			for(int i=1;i<GAME_TIME;i++)
			{
				tqdm_work -= state_tqdm.increase_game_work(sum_game+i);
			}
			now_game=0;
		}
			
		int a=1;
		float b=1;
		if(now_game == 1 && now_work == -1)
			a=0;
		if(now_work == -1)
			b=0.2;//stay
		printf("now:%d,%d\n",now_work,now_game);
		
		tqdm_work += a*b*now_work + (float)now_game*state_tqdm.increase_game_work(sum_game);//“理智值”
		tqdm_water += now_drink*RATE_DRINK - LOSS_WATER;//喝水值
		
		if(tqdm_work>=get_work_max())
			tqdm_work = get_work_max();
		if(tqdm_game>=get_game_max())
			tqdm_game = get_game_max();
		if(tqdm_water>=100)
			tqdm_water = 100;
		if(tqdm_work<=0)
			tqdm_work = 0;
		if(tqdm_game<=0)
			tqdm_game = 0;
		if(tqdm_water<=0)
			tqdm_water = 0;

		printf("tqdm_work: %.3f\n",tqdm_work);
		printf("tqdm_game: %.3f\n",tqdm_game);
		printf("tqdm_water: %.3f\n",tqdm_water);
		printf(rx_buf);
		printf("\n");
		if(screens == 2)
		{
			//状态条：
			float game_bar = state_tqdm.game_to_lvgl_bar(tqdm_game);
			float work_bar = state_tqdm.work_to_lvgl_bar(tqdm_work);
			
			if(game_bar<=0)
				game_bar = 0;
			if(work_bar<=0)
				work_bar = 0;
			
			printf("work_bar: %.3f\n",work_bar);
			printf("game_bar: %.3f\n",game_bar);
			
			lv_bar_set_value(guider_ui.screen_work_drink_bar,(int)tqdm_water,LV_ANIM_ON);
			
			lv_bar_set_value(guider_ui.screen_work_game_bar,(int)game_bar,LV_ANIM_ON);
			
			lv_bar_set_value(guider_ui.screen_work_work_bar,(int)work_bar,LV_ANIM_ON);
			
			char* work = float_to_string(work_bar);
			char* game = float_to_string(game_bar);
			char* water = float_to_string(tqdm_water);
			
//			printf(work);
//			printf(work);
			printf(water);
			printf("\n");
			
			lv_label_set_text(guider_ui.screen_work_label_work_bar, work);
			lv_label_set_text(guider_ui.screen_work_label_game_bar, game);
			lv_label_set_text(guider_ui.screen_work_label_drink_bar, water);
			free(work);free(game);free(water);
			
			if(game_bar >= 80)
			{
				lv_obj_set_style_bg_color(guider_ui.screen_work_game_bar, lv_color_hex(0xb22222), LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_bg_color(guider_ui.screen_work_game_bar, lv_color_hex(0xb22222), LV_PART_INDICATOR|LV_STATE_DEFAULT);
				if(over_game==0)
				{
					over_game = 20;
					char a[]= "over_game\n";
					HAL_UART_Transmit(&huart2,(unsigned char*)a,sizeof(a),10000);
					printf(a);
				}
				over_game--;
			}
			else
			{
				over_game=0;
				lv_obj_set_style_bg_color(guider_ui.screen_work_game_bar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_bg_color(guider_ui.screen_work_game_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
			}
			
			if(work_bar <= 20)
			{
				lv_obj_set_style_bg_color(guider_ui.screen_work_work_bar, lv_color_hex(0xb22222), LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_bg_color(guider_ui.screen_work_work_bar, lv_color_hex(0xb22222), LV_PART_INDICATOR|LV_STATE_DEFAULT);
				if(over_work==0)
				{
					over_work=20;
					char a[]= "over_work\n";
					HAL_UART_Transmit(&huart2,(unsigned char*)a,sizeof(a),10000);
					printf(a);
				}
				over_work--;
			}
			else
			{
				over_work=0;
				lv_obj_set_style_bg_color(guider_ui.screen_work_work_bar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_bg_color(guider_ui.screen_work_work_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
			}
			
			if(tqdm_water <= 20)
			{
				lv_obj_set_style_bg_color(guider_ui.screen_work_drink_bar, lv_color_hex(0xb22222), LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_bg_color(guider_ui.screen_work_drink_bar, lv_color_hex(0xb22222), LV_PART_INDICATOR|LV_STATE_DEFAULT);
				if(need_drink==0)
				{
					need_drink = 40;
					char a[]= "over_drink\n";
					HAL_UART_Transmit(&huart2,(unsigned char*)a,sizeof(a),10000);
					printf(a);
				}
				need_drink--;
			}
			else
			{
				need_drink=0;
				lv_obj_set_style_bg_color(guider_ui.screen_work_drink_bar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
				lv_obj_set_style_bg_color(guider_ui.screen_work_drink_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
			}
			
		}
		//总计数：叉//连续工作：勾
		if(state_counter.work_counter(rx_buf)==1 ||
   		 state_counter.book_counter(rx_buf)==1 ||
		   state_counter.compu_counter(rx_buf)==1 ||
		   state_counter.mouse_counter(rx_buf)==1)
		{
			//printf("1\n");
			all_work+=1;
		}
		else
		{			
			//printf("0\n");
			all_work=0;
		}
		
		if(state_counter.game_counter(rx_buf)==1)
		{
			//printf("11\n");
			all_game+=1; 
		}
		else 
		{
			//printf("00\n");
			all_game=0;
		}
//		all_work+=state_counter.work_counter(rx_buf);
//		all_book+=state_counter.book_counter(rx_buf);
//		all_game+=state_counter.game_counter(rx_buf);
//		all_compu+=state_counter.compu_counter(rx_buf);
//		all_mouse+=state_counter.mouse_counter(rx_buf);
		all_water+=state_counter.water_counter(rx_buf);
		
		if(screens == 2)
		{
			char* work = int_to_string(all_work);
			char* game = int_to_string(all_game);
			char* water = int_to_string(all_water);
			
			//printf("w:%d,g:%d,w:%d\n",all_work,all_game,all_water);
			lv_label_set_text(guider_ui.screen_work_label_work_time, work);
			lv_label_set_text(guider_ui.screen_work_label_paly_time, game);
			lv_label_set_text(guider_ui.screen_work_label_drink_time, water);
		}
		
		}
		
		else if(rx_buf[0] == 'L')
		{
			if(rx_buf[1] == '0')
			{
				__HAL_TIM_SetCompare(&htim5, TIM_CHANNEL_2, 0);
				light_mode = 2;//close
			}
			else if(rx_buf[1] == '1')
			{
				light_mode = 1;//auto
			}
		}
		
		else if(rx_buf[0]=='t')
		{
			RTC_TimeTypeDef now;
			now.Hours = (rx_buf[1]-'0')*10 + rx_buf[2]-'0';
			now.Minutes = (rx_buf[4]-'0')*10 + rx_buf[5]-'0';
			now.Seconds = (rx_buf[7]-'0')*10 + rx_buf[8]-'0';
			HAL_RTC_SetTime(&hrtc,&now,RTC_FORMAT_BIN);
			RTC_TimeTypeDef tim;
			HAL_RTC_GetTime(&hrtc,&tim,RTC_FORMAT_BIN);
			printf("Time:%02d:%02d:%02d\n",tim.Hours,tim.Minutes,tim.Seconds); 			
		}
		


		HAL_UART_Receive_DMA(&huart2,rx_buf,11);
	}

}

// PWM DMA 完成回调函数
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Stop_DMA(&htim4, TIM_CHANNEL_1);
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void pwm_speed_1(int speed)//-3000 +3000
{
	speed=4500+speed;
	__HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_2, speed);
}
void pwm_speed_2(int speed)//-3000 +3000
{
	speed=4500+speed;
	__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, speed);
}
void test(int i)
{
	__HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_2, i);
}




/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_TIM9_Init();
  MX_TIM11_Init();
  MX_TIM2_Init();
  MX_USART2_UART_Init();
  MX_I2C2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM12_Init();
//  MX_FSMC_Init();
  MX_RTC_Init();
  MX_TIM5_Init();
  /* USER CODE BEGIN 2 */
	//__HAL_UART_ENABLE_IT(&huart2,UART_IT_IDLE);
	
	AI_Init_rnn();//AI初始化
	AI_Init_fcn();

	HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim11,TIM_CHANNEL_1);//舵机
	HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_2);//灯PWM
	
	HAL_TIM_Base_Start_IT(&htim3);//remember
	
	HAL_RTC_Init(&hrtc);
	
//	kalman_temp = Kalman_Init(0,0,0,0,0.2,3);
//	kalman_humi = Kalman_Init(0,0,0,0,0.2,3);
//	kalman_co2 = Kalman_Init(0,0,0,0,0.2,3);
//	kalman_lux = Kalman_Init(0,0,0,0,0.2,3);
//	kalman_pre_temp = Kalman_Init(0,0,0,0,0.2,3);
//	kalman_score = Kalman_Init(0,0,0,0,0.2,3);
	
//	HAL_UART_Transmit(&huart2,"ready",5,1000);
	HAL_UART_Receive_DMA(&huart2,rx_buf,11);
	
	work_detector_init();
	detector_init();
	
	measure_init();//measure initial
	
	pid_x(0);
	pid_y(0);
	printf("ready\n");
	
	
	lv_init();                          // lvgl初始化
  lv_port_disp_init();                // 显示设备初始化
  lv_port_indev_init();               // 输入设备初始化

	setup_ui(&guider_ui);
	events_init(&guider_ui);
	
	HAL_UART_Transmit(&huart2,"time\n",sizeof("time\n"),1000);
	HAL_Delay(5);
	HAL_RTC_GetTime(&hrtc,&time,RTC_FORMAT_BIN);
	printf("Time:%02d:%02d:%02d\n",time.Hours,time.Minutes,time.Seconds); 
	HAL_RTC_GetDate(&hrtc,&date,RTC_FORMAT_BIN);
	printf("Date:20%02d-%02d-%02d",date.Year,date.Month,date.Date); 

	//HAL_Delay(3000);
	//char a[]= "work_detector_start\n";
	//HAL_UART_Transmit(&huart2,(unsigned char*)a,sizeof(a),10000);
	//HAL_Delay(50000);	
	//char b[]= "work_detector_stop\n";
	//HAL_UART_Transmit(&huart2,(unsigned char*)b,sizeof(b),10000);
		
	
//	RGB_WHITE_Change(Pixel_NUM,bright);
//	HAL_Delay(1000);
//	__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250-1);
//	__HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_2, 250*6-1);
	HAL_Delay(100);
	__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+MAX_POS_Y/2-1);
		HAL_Delay(100);
		__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+MAX_POS_Y/2-20);
			HAL_Delay(100);
			__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+MAX_POS_Y/2-40);
				HAL_Delay(100);
				__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+MAX_POS_Y/2-60);
					HAL_Delay(100);
					__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+MAX_POS_Y/2-80);
						HAL_Delay(100);
						__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+MAX_POS_Y/2-100);
	__HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_2, (250+MAX_POS_X/2)*6-1);
//	HAL_Delay(1000);
//	__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+MAX_POS_Y-1);
//	__HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_2, (250+MAX_POS_X)*6-1);
//	HAL_Delay(1000);
//	__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+MAX_POS_Y/2-1);
//	__HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_2, (250+MAX_POS_X/2)*6-1);
//   HAL_Delay(100);
  //uint16_t test[24*2+1] = {34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,71,71,71,71,71,71,71,71,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,71,71,71,71,71,71,71,71,0};
	//int i=0;
	//pwm_speed_1(50);
//	HAL_UART_Transmit(&huart2,"",5,1000);
	//RGB_RED(Pixel_NUM);
	
	HAL_Delay(200);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
	  lv_task_handler();
	  //HAL_TIM_PWM_Start_DMA(&htim4, TIM_CHANNEL_1, (uint16_t *)test,24*2+1);
		//RGB_BLUE(Pixel_NUM);

		/*AI
		AI_Run_rnn(rnnInData ,rnnOutData );
		AI_Run_fcn(fcnInData ,fcnOutData);
		*/
//		led_loading();
		//BH1750_Init();
		//BH1750_ReadLightIntensity(&lux);
		//start_measures();
		//HAL_Delay(700);

		//RGB_start();
		//HAL_Delay(1000);
		//HAL_Delay(10);
		//RGB_RED(Pixel_NUM);
		//RGB_BLACK(Pixel_NUM);
		//HAL_Delay(1000);
		
		//i=(i+20)%150;
		//pwm_speed_1(115);
		//pwm_speed_1(20);
		//printf("1");
		//pid_x(target_);
		//HAL_Delay(10);
//HAL_Delay(100);
		//printf("runing");
		//HAL_UART_Transmit(&huart2,"10\n",3,1000);
		

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
