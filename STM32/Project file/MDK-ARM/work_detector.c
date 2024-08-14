#include "work_detector.h"

counter state_counter;
analyser state_analyser;
tqdm state_tqdm;

extern int para_work_max;
extern int para_game_max;
extern int para_game_turn;
extern int para_mode;

void work_detector_init()
{
  temp_water=0;//init
  temp_work=0;//init
  temp_game=0;
  count_water=0;
  count_work=0;
  count_game=0;
}

void detector_init()
{
	state_counter.work_counter = work_counter;
	state_counter.book_counter = book_counter;
	state_counter.game_counter = game_counter;
	state_counter.compu_counter = compu_counter;
	state_counter.mouse_counter = mouse_counter;
	state_counter.water_counter = water_counter;
	
	state_analyser.drink_count_analyser = drink_count_analyser;
	state_analyser.game_count_analyser = game_count_analyser;
	state_analyser.work_count_analyser = work_count_analyser;
	state_analyser.stop_analyser = stop_analyser;
	
	state_tqdm.increase_game_game = increase_game_game;
	state_tqdm.increase_game_work = increase_game_work;
	state_tqdm.increase_work_game = increase_work_game;
	state_tqdm.increase_work_work = increase_work_work;
	state_tqdm.work_to_lvgl_bar = work_to_lvgl_bar;
	state_tqdm.game_to_lvgl_bar = game_to_lvgl_bar;
	printf("detector_init\n");
}

void work_set(int a, int b, int c, float d)
{
	you_work_max = a;
	you_game_max = b;
	you_game_turn = c;
	you_mode = d;
	printf("work_set:%d\n",you_work_max);
}
int get_work_max()
{
	return you_work_max;
}
int get_game_max()
{
	return you_game_max;
}
int get_game_turn()
{
	return you_game_turn;
}
float get_mode()
{
	return you_mode;
}

int drink_count_analyser(uint8_t *work_index_list) 
{
	uint8_t cup = work_index_list[6];
	int count = 0;
	
	
	
	if(cup=='1')
	{
		if(temp_water<=0)
			count =1;
		
		temp_water = WATER_TIME;
		//printf("drinking_up\n");
	}
	
	if(cup=='0')
	{
		temp_water--;
		//count = 1;
		//printf("delay_drinking\n");
	}
	//printf("drinking\n");
	if(temp_water>0 && count == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
  //return count;
}

int work_count_analyser(uint8_t *work_index_list)
{
	uint8_t work;
	work = work_index_list[5]+work_index_list[2]+work_index_list[1]+work_index_list[4]-48*3;//all working count
	float count = 0;
	
	if(work=='1')
	{
		temp_work = WORK_TIME;
		count=1;
	}
	
	if(work=='0' && temp_work==0)
	{
		count = -1;//?????
	}
	
	if(temp_work>0 && work=='0')
	{
		temp_work--;
		count = 1;
		if(temp_work==0)
		{
			count=2*(1-WORK_TIME);
		}
	}

  return count;
}

int game_count_analyser(uint8_t *work_index_list) 
{
	uint8_t game = work_index_list[3];
	int count = 0;
	
	if(game=='1')
	{
		temp_game = GAME_TIME;
		count = 1;
	}
	
	if(game=='0' && temp_game==0)
	{
		count = -1;//??????
	}
	
	if(temp_game>0 && game=='0')
	{
		temp_game--;
		count = 1;
		if(temp_game==0)
		{
			count=2*(1-GAME_TIME);
		}
	}

  return count;
}

//【1】专有分析计数：work——1
int work_counter(uint8_t *work_index_list)
{
	uint8_t work = work_index_list[1];
	int count = 0;

	if(work=='1')
	{
		temp_work_1 = WORK_1_TIME;
		return 1;
	}
	if(work=='0')
	{
		temp_work_1--;
		if(temp_work_1==0)
			return 1-WORK_1_TIME;
		else if(temp_work_1>0)
			return 1;
		else
			return 0;
	}
	
	return 0;
}
//【2】专有分析计数：book——2
int book_counter(uint8_t *work_index_list)
{
	uint8_t book = work_index_list[2];
	int count = 0;

	if(book=='1')
	{
		temp_book_2 = BOOK_2_TIME;
		return 1;
	}
	if(book=='0')
	{
		temp_book_2--;
		if(temp_book_2==0)
			return 1-BOOK_2_TIME;
		else if(temp_book_2>0)
			return 1;
		else
			return 0;
	}
	
	return 0;
}
//【3】专有分析计数：game——3
int game_counter(uint8_t *work_index_list)
{
	uint8_t game = work_index_list[3];
	int count = 0;

	if(game=='1')
	{
		temp_game_3 = GAME_3_TIME;
		return 1;
	}
	if(game=='0')
	{
		temp_game_3--;
		if(temp_game_3==0)
			return 1-GAME_3_TIME;
		else if(temp_game_3>0)
			return 1;
		else
			return 0;
	}
	
	return 0;
}
//【4】专有分析计数：compu——4
int compu_counter(uint8_t *work_index_list)
{
	uint8_t compu = work_index_list[4];
	int count = 0;

	if(compu=='1')
	{
		temp_compu_4 = COMPU_4_TIME;
		return 1;
	}
	if(compu=='0')
	{
		temp_compu_4--;
		if(temp_compu_4==0)
			return 1-COMPU_4_TIME;
		else if(temp_compu_4>0)
			return 1;
		else
			return 0;
	}
	
	return 0;
}
//【5】专有分析计数：mouse——5
int mouse_counter(uint8_t *work_index_list)
{
	uint8_t mouse = work_index_list[5];
	int count = 0;

	if(mouse=='1')
	{
		temp_mouse_5 = MOUSE_5_TIME;
		return 1;
	}
	if(mouse=='0')
	{
		temp_mouse_5--;
		if(temp_mouse_5==0)
			return 1-MOUSE_5_TIME;
		else if(temp_mouse_5>0)
			return 1;
		else
			return 0;
	}
	
	return 0;
}
//【6】专有分析计数：water——6
int water_counter(uint8_t *work_index_list)
{
	uint8_t water = work_index_list[6];
	int count = 0;

	if(water=='1')
	{
		if(temp_water_6<=0)
			count = 1;
		temp_water_6 = WATER_6_TIME;
	}
	
	if(water=='0')
	{
		temp_water_6--;
	}
	
	return count;
}


float increase_work_work(int sum_work)
{
	if(sum_work>=WORK_MAX-1)
		sum_work = WORK_MAX-1;
	
	return -(50/sqrt(WORK_MAX))/pow(WORK_MAX-sum_work,0.5);
}

float increase_game_work(int sum_game)//ok?
{
	if(sum_game>=you_game_turn*2)
		sum_game = you_game_turn*2;
	
	return (-1.0/( 1.0/(1+pow(2.7183,GAME_WORK_A*(you_game_turn))) - 0.5 )) * ( 1.0/(1+pow(2.7183,GAME_WORK_A*(you_game_turn-sum_game))) - 0.5 );
}

float increase_game_game(int sum_game)//to be continue...
{
	if(sum_game>=GAME_MAX)
	{
		sum_game = GAME_MAX;
	}
	
	return (200.0/(float)(GAME_MAX*GAME_MAX))*sum_game;
}	

float increase_work_game(int sum_work)//
{
	if(sum_work>=WORK_FISH)
		sum_work = WORK_FISH;
	
	return -(200.0/(float)(WORK_FISH*WORK_FISH))*sum_work;
}

float work_to_lvgl_bar(float work)
{
	if(work>=you_work_max)
		work = you_work_max;
	
	return (100/pow(you_work_max,0.5))*pow(you_work_max-work,0.5);
}

float game_to_lvgl_bar(float game)
{
	if(game>=you_game_max)
		game = you_game_max;
	
	return (100.0/(you_game_max*you_game_max))*game*game;
}
	
void stop_analyser(int *sum_work, int *sum_game, int *delay)
{
	if(*sum_work >= RECOVER_FROM_WORK && *delay >= RECOVER_FROM_WORK)
	{
		*sum_game = 0;
	}
	if(*sum_game >= RECOVER_FROM_GAME && *delay >= RECOVER_FROM_GAME)
	{
		*sum_work = 0;
	}
}


