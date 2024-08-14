#include "ws2812.h"
#include "tim.h"
#include "math.h" 

/*Some Static Colors------------------------------*/
const RGB_Color_TypeDef RED      = {255,0,0};   //显示红色RGB数据
const RGB_Color_TypeDef ORANGE   = {127,106,0};
const RGB_Color_TypeDef YELLOW   = {127,216,0};
const RGB_Color_TypeDef GREEN    = {0,255,0};
const RGB_Color_TypeDef CYAN	 = {0,255,255};
const RGB_Color_TypeDef BLUE     = {0,0,255};
const RGB_Color_TypeDef PURPLE	 = {238,130,238};
const RGB_Color_TypeDef BLACK    = {0,0,0};
const RGB_Color_TypeDef WHITE    = {255,255,255};
const RGB_Color_TypeDef MAGENTA  = {255,0,220};

RGB_Color_TypeDef load[16];
 
/*二维数组存放最终PWM输出数组，每一行24个
数据代表一个LED，最后一行24个0代表RESET码*/
uint32_t Pixel_Buf[Pixel_NUM+1][24];       
 

// 创建 Gamma 修正查找表
uint8_t gamma_correction_table[256];
// 初始化 Gamma 修正查找表
void init_gamma_correction_table() {
    for (int i = 0; i < 256; i++) {
        gamma_correction_table[i] = (uint8_t)(pow(i / 255.0, GAMMA) * 255.0);
    }
}
// Gamma 修正函数（使用查找表）
uint8_t gamma_correction(uint8_t color) {
    return gamma_correction_table[color];
}


/*
功能：设定单个RGB LED的颜色，把结构体中RGB的24BIT转换为0码和1码
参数：LedId为LED序号，Color：定义的颜色结构体
*/
void RGB_SetColor(uint8_t LedId,RGB_Color_TypeDef Color)
{
	uint8_t i; 
	if(LedId > Pixel_NUM)return; //avoid overflow 防止写入ID大于LED总数
	if(1)//gamma修正
	{
		Color.G = gamma_correction(Color.G);
		Color.B = gamma_correction(Color.B);
		Color.R = gamma_correction(Color.R);
	}
	for(i=0;i<8;i++) Pixel_Buf[LedId][i]   = ( (Color.G & (1 << (7 -i)))? (CODE_1):CODE_0 );//数组某一行0~7转化存放G
	for(i=8;i<16;i++) Pixel_Buf[LedId][i]  = ( (Color.R & (1 << (15-i)))? (CODE_1):CODE_0 );//数组某一行8~15转化存放R
	for(i=16;i<24;i++) Pixel_Buf[LedId][i] = ( (Color.B & (1 << (23-i)))? (CODE_1):CODE_0 );//数组某一行16~23转化存放B
}
 
/*
功能：最后一行装在24个0，输出24个周期占空比为0的PWM波，作为最后reset延时，这里总时长为24*1.2=30us > 24us(要求大于24us)
*/
void Reset_Load(void)
{
	uint8_t i;
	for(i=0;i<24;i++)
	{
		Pixel_Buf[Pixel_NUM][i] = 0;
	}
}
 
/*
功能：发送数组
参数：(&htim1)定时器1，(TIM_CHANNEL_2)通道2，((uint32_t *)Pixel_Buf)待发送数组，
			(Pixel_NUM+1)*24)发送个数，数组行列相乘
*/
void RGB_SendArray(void)
{
	HAL_TIM_PWM_Start_DMA(&htim4, TIM_CHANNEL_1, (uint16_t *)Pixel_Buf,(Pixel_NUM+1)*24);
}
 


void single_led(uint8_t pos, RGB_Color_TypeDef rgb)
{
	RGB_SetColor(pos,rgb);
	Reset_Load();
	RGB_SendArray();
}
/*
功能：显示红色
参数：Pixel_Len为显示LED个数
*/
void RGB_RED(uint16_t Pixel_Len)
{
	uint16_t i;
	for(i=0;i<Pixel_Len;i++)//给对应个数LED写入红色
	{
		RGB_SetColor(i,RED);
	}
	Reset_Load();
	RGB_SendArray();
}
 
/*
功能：显示绿色
参数：Pixel_Len为显示LED个数
*/
void RGB_GREEN(uint16_t Pixel_Len)
{
	uint16_t i;
	for(i=0;i<Pixel_Len;i++)//给对应个数LED写入绿色
	{
		RGB_SetColor(i,GREEN);
	}
	Reset_Load();
	RGB_SendArray();
}
 
/*
功能：显示蓝色
参数：Pixel_Len为显示LED个数
*/
void RGB_BLUE(uint16_t Pixel_Len)
{
	uint16_t i;
	for(i=0;i<Pixel_Len;i++)//给对应个数LED写入蓝色
	{
		RGB_SetColor(i,BLUE);
	}
	Reset_Load();
	RGB_SendArray();
}
 
/*
功能：显示白色
参数：Pixel_Len为显示LED个数
*/
void RGB_WHITE(uint16_t Pixel_Len)
{
	uint16_t i;
	for(i=0;i<Pixel_Len;i++)//给对应个数LED写入白色
	{
		RGB_SetColor(i,WHITE);
	}
	Reset_Load();
	RGB_SendArray();
}

void RGB_WHITE_Change(uint16_t Pixel_Len, uint8_t bright)
{
	uint16_t i;
	RGB_Color_TypeDef white;
	white.B = bright;
	white.G = bright;
	white.R = bright;	
	for(i=0;i<Pixel_Len;i++)//给对应个数LED写入自定义亮度白色
	{
		RGB_SetColor(i,white);
	}
	Reset_Load();
	RGB_SendArray();
}
 
/*
功能：显示black
参数：Pixel_Len为显示LED个数
*/
void RGB_BLACK(uint16_t Pixel_Len)
{
	uint16_t i;
	for(i=0;i<Pixel_Len;i++)//给对应个数LED写入白色
	{
		RGB_SetColor(i,BLACK);
	}
	Reset_Load();
	RGB_SendArray();
}

void RGB_loading(uint16_t Pixel_Len)
{
	uint16_t i;
	for(i=0;i<=15;i++)//给对应个数LED写入
	{
		RGB_SetColor(i,load[i]);
	}
	Reset_Load();
	RGB_SendArray();
}

void RGB_start(void)
{
	for(int i=0;i<=15;i++)
	{
		if(load[i].R>=16)
			load[i].R-=16;
		else
			load[i].R=255;
		
		if(load[i].G>=16)
			load[i].G-=16;
		else
			load[i].G=255;
		
		if(load[i].B>=16)
			load[i].B-=16;
		else
			load[i].B=255;		
	}
	RGB_loading(Pixel_NUM);
}

//也可以继续添加其他颜色，和颜色变化函数等
 
/*******************************************************************************/
/*									添加部分									   */
 
//显示指定颜色
static void rgb_show(uint32_t Pixel_Len, RGB_Color_TypeDef rgb)
{
	uint16_t i;
	for(i=0;i<Pixel_Len;i++)
	{
		RGB_SetColor(i,rgb);
	}
	Reset_Load();
	RGB_SendArray();
}
 
//颜色循环转换
static RGB_Color_TypeDef Wheel(uint8_t WheelPos)
{
	RGB_Color_TypeDef rgb;
	WheelPos = 255 - WheelPos;
	if (WheelPos < 85)
	{
		rgb.R = 255 - WheelPos * 3;
		rgb.G = 0;
		rgb.B = WheelPos * 3;
		return rgb;
	}
	if (WheelPos < 170)
	{
		WheelPos -= 85;
		rgb.R = 0;
		rgb.G = WheelPos * 3;
		rgb.B = 255 - WheelPos * 3;
		return rgb;
	}
	WheelPos -= 170;
	rgb.R = WheelPos * 3;
	rgb.G = 255 - WheelPos * 3;
	rgb.B = 0;
	return rgb;
}
 
//彩虹呼吸灯
static void rainbow(uint8_t wait)
{
	uint32_t timestamp = HAL_GetTick();
	uint16_t i;
	static uint8_t j;
	static uint32_t next_time = 0;
 
	uint32_t flag = 0;
	if (next_time < wait)
	{
		if ((uint64_t)timestamp + wait - next_time > 0)
			flag = 1;
	}
	else if (timestamp > next_time)
	{
		flag = 1;
	}
	if (flag)    // && (timestamp - next_time < wait*5))
	{
		j++;
		next_time = timestamp + wait;
		for (i = 0; i < Pixel_NUM; i++)
		{
			RGB_SetColor(i, Wheel((i + j) & 255));
		}
	}
	RGB_SendArray();
}
 
//彩虹灯旋转
static void rainbowCycle(uint8_t wait)
{
	uint32_t timestamp = HAL_GetTick();
	uint16_t i;
	static uint8_t j;
	static uint32_t next_time = 0;
 
	static uint8_t loop = 0;
	if (loop == 0)
		next_time = timestamp;
	loop = 1;    //首次调用初始化
 
	if ((timestamp > next_time))    // && (timestamp - next_time < wait*5))
	{
		j++;
		next_time = timestamp + wait;
		for (i = 0; i < Pixel_NUM; i++)
		{
			RGB_SetColor(i, Wheel(((i * 256 / (Pixel_NUM)) + j) & 255));
		}
	}
	RGB_SendArray();
}
 
 
static uint8_t rainbow_change_flag = 0;
void led_loop(void)
{
	int i;
	rgb_show(16, BLACK);		HAL_Delay(300);
	for(i = 1; i <= 16 ;i++) {	//红
		rgb_show(i, RED);		
		HAL_Delay(50);		
	}
	for(i = 1; i <= 16 ;i++) {	//橙
		rgb_show(i, ORANGE);		
		HAL_Delay(50);		
	}
	for(i = 1; i <= 16 ;i++) {	//黄
		rgb_show(i, YELLOW);		
		HAL_Delay(50);		
	}
	for(i = 1; i <= 16 ;i++) {	//绿
		rgb_show(i, GREEN);		
		HAL_Delay(50);		
	}
	for(i = 1; i <= 16 ;i++) {	//青
		rgb_show(i, CYAN);		
		HAL_Delay(50);		
	}
	for(i = 1; i <= 16 ;i++) {	//蓝
		rgb_show(i, BLUE);		
		HAL_Delay(50);		
	}
	for(i = 1; i <= 16 ;i++) {	//紫
		rgb_show(i, PURPLE);		
		HAL_Delay(50);		
	}
	/*
	HAL_TIM_Base_Start_IT(&htim3);	//使能定时器中断->时间：1ms
	while(1) {
		if(!rainbow_change_flag)
			rainbow(5);
		else 
			rainbowCycle(2);
	}
	*/
}

void loading_init(void)
{
	int i=0;
	init_gamma_correction_table();
	for(int i=0;i<=15;i++)
	{
		load[i].R = i*16+15;
		load[i].G = i*16+15;
		load[i].B = i*16*15;
	}
}

void led_loading(void)
{
	int i;
	rgb_show(16, BLACK);		HAL_Delay(300);
	loading_init();
	for(i = 0; i <= 15 ;i++) 
	{	
		rgb_show(1, load[(i+1)%16]);
    rgb_show(2, load[(i+2)%16]);
		rgb_show(3, load[(i+3)%16]);
    rgb_show(4, load[(i+4)%16]);	
		rgb_show(5, load[(i+5)%16]);
    rgb_show(6, load[(i+6)%16]);	
		rgb_show(7, load[(i+7)%16]);
    rgb_show(8, load[(i+8)%16]);			
		rgb_show(9, load[(i+9)%16]);
    rgb_show(10, load[(i+10)%16]);
		rgb_show(11, load[(i+11)%16]);
    rgb_show(12, load[(i+12)%16]);	
		rgb_show(13, load[(i+13)%16]);
    rgb_show(14, load[(i+14)%16]);	
		rgb_show(15, load[(i+15)%16]);
    rgb_show(16, load[(i+16)%16]);
		if(i==15)i=0;
		HAL_Delay(300);		
	}
	
}

 
 
 