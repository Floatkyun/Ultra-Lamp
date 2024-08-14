#ifndef __WS2812_H__
#define __WS2812_H__
 
#include "main.h"

#define GAMMA 2.2 // Gamma У��ֵ
/*���������ļ�������CCR�ĺ궨��*/
#define CODE_1       (71)       //1�붨ʱ����������
#define CODE_0       (34)       //0�붨ʱ����������
 
/*����һ�����嵥��LED��ԭɫֵ��С�Ľṹ��*/
typedef struct
{
	uint8_t R;
	uint8_t G;
	uint8_t B;
	
}RGB_Color_TypeDef;
 
#define Pixel_NUM 16*2  //LED�����궨�壬������ʹ��һ��LED��������pixelΪ���ص���˼��

void init_gamma_correction_table();
void RGB_SetColor(uint8_t LedId,RGB_Color_TypeDef Color);//��һ��LEDװ��24����ɫ�����루0���1�룩
void Reset_Load(void); //�ú������ڽ��������24�����ݱ�Ϊ0������RESET_code
void RGB_SendArray(void);          //������������
void RGB_RED(uint16_t Pixel_Len);  //��ʾ���
void RGB_GREEN(uint16_t Pixel_Len);//��ʾ�̵�
void RGB_BLUE(uint16_t Pixel_Len); //��ʾ����
void RGB_WHITE(uint16_t Pixel_Len);//��ʾ�׵�
void RGB_BLACK(uint16_t Pixel_Len);//��ʾ�׵�
void RGB_WHITE_Change(uint16_t Pixel_Len, uint8_t bright);//�Զ������Ȱ�
void RGB_loading(uint16_t Pixel_Len);
void RGB_start(void);
void loading_init(void);
void led_loading(void);
void led_loop(void);
 
#endif
 
 
 
 
 