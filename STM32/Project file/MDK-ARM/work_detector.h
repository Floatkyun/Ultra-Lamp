#ifndef _DETECTOR_H_
#define _DETECTOR_H_

#include "main.h"
#include "math.h"
#include "usart.h"

static int temp_water=0;//init
static int temp_work=0;//init
static int temp_game=0;
static int count_water=0;
static int count_work=0;
static int count_game=0;

static int temp_work_1=0;//init
static int temp_book_2=0;//init
static int temp_game_3=0;//init
static int temp_compu_4=0;//init
static int temp_mouse_5=0;//init
static int temp_water_6=0;//init

#define WATER_TIME  3//连续工作滤波判定
#define WORK_TIME   0
#define GAME_TIME   0

#define WORK_1_TIME   0
#define BOOK_2_TIME   0
#define GAME_3_TIME   0
#define COMPU_4_TIME  0
#define MOUSE_5_TIME  0
#define WATER_6_TIME  3

#define RECOVER_FROM_WORK  10
#define RECOVER_FROM_GAME  10

#define WORK_MAX     4.0*60/10//work消耗理智最快值
#define GAME_TURN    3.0*60.0/10.0//game由恢复变消耗
#define GAME_WORK_K  1.5*2.0//sigmoid总倍系数
#define GAME_WORK_A  0.1//sigmoid ex系数
#define RATE_DRINK   24.628//喝水进度条速率
#define LOSS_WATER   4.762//口渴速率 
#define GAME_MAX     6.0*60/10//game增长摸鱼最快值
#define WORK_FISH    2*60*60/10//work_to_fish
static int you_work_max = WORK_MAX;
static int you_game_turn = GAME_TURN;
static int you_game_max = GAME_MAX;
static float you_mode = 0.8;
			
typedef struct
{
	int (*work_counter)(uint8_t*);
	int (*book_counter)(uint8_t*);
	int (*game_counter)(uint8_t*);
	int (*compu_counter)(uint8_t*);
	int (*mouse_counter)(uint8_t*);
	int (*water_counter)(uint8_t*);
}counter;

typedef struct
{
	int (*drink_count_analyser)(uint8_t*);
	int (*work_count_analyser)(uint8_t*);
	int (*game_count_analyser)(uint8_t*);
	void (*stop_analyser)(int*,int*,int*);
}analyser;

typedef struct
{
	float (*increase_work_work)(int);
	float (*increase_game_work)(int);//only
	float (*increase_game_game)(int);
	float (*increase_work_game)(int);
	float (*work_to_lvgl_bar)(float);
	float (*game_to_lvgl_bar)(float);
}tqdm;

int drink_count_analyser(uint8_t *work_index_list) ;
int work_count_analyser(uint8_t *work_index_list);
int game_count_analyser(uint8_t *work_index_list);

int work_counter(uint8_t *work_index_list);
int book_counter(uint8_t *work_index_list);
int game_counter(uint8_t *work_index_list);
int compu_counter(uint8_t *work_index_list);
int mouse_counter(uint8_t *work_index_list);
int water_counter(uint8_t *work_index_list);

void stop_analyser(int *sum_work, int *sum_game, int *delay);

void work_detector_init();
void detector_init();

float increase_work_work(int sum_work);
float increase_game_work(int sum_game);
float increase_game_game(int sum_game);
float increase_work_game(int sum_work);
float work_to_lvgl_bar(float work);
float game_to_lvgl_bar(float game);

void work_set(int a, int b, int c, float d);
int get_work_max();
int get_game_max();
int get_game_turn();
float get_mode();

extern counter state_counter;
extern analyser state_analyser;
extern tqdm state_tqdm;


#endif