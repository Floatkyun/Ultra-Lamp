/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "usart.h"
#include "work_detector.h"
#include "tim.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

extern int screens;
extern int light_mode;
extern int light_bright;
extern int chat;

static void screen_main_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		lv_obj_set_style_radius(guider_ui.screen_main_label_led_light, 8, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_main_cont_light_mode, 5, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_main_label_temp_Pre_1, 8, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_main_label_temp_pre, 4, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_main_label_envscore, 4, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_main_label_envscore_1, 8, LV_PART_MAIN);
		break;
	}
	default:
		break;
	}
}
static void screen_main_btn_guard_mode_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+400-1);
		HAL_UART_Transmit(&huart2,"guard_start\n",sizeof("guard_start\n"),1000);
		light_bright = 0;
		
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_guard, guider_ui.screen_guard_del, &guider_ui.screen_main_del, setup_scr_screen_guard, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		screens = -1;
		break;
	}
	default:
		break;
	}
}
static void screen_main_btn_desk_mode_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_work_setting, guider_ui.screen_work_setting_del, &guider_ui.screen_main_del, setup_scr_screen_work_setting, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
		screens = 1;
		break;
	}
	default:
		break;
	}
}
static void screen_main_slider_led_Light_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_main_btn_auto_light, lv_color_hex(0x00ffe0), LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.screen_main_btn_handset_light, lv_color_hex(0xff6500), LV_PART_MAIN);
		light_mode=0;
		light_bright = lv_slider_get_value(guider_ui.screen_main_slider_led_Light);		
		break;
	}
	default:
		break;
	}
}
static void screen_main_btn_handset_light_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_main_btn_auto_light, lv_color_hex(0x00ffe0), LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.screen_main_btn_handset_light, lv_color_hex(0xff6500), LV_PART_MAIN);
		light_mode=0;
		break;
	}
	default:
		break;
	}
}
static void screen_main_btn_auto_light_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_main_btn_auto_light, lv_color_hex(0xff6500), LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.screen_main_btn_handset_light, lv_color_hex(0x00ffe0), LV_PART_MAIN);
		light_mode = 1;
		break;
	}
	default:
		break;
	}
}
static void screen_main_btn_chat_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		if(chat == 0)//start chat
		{
			lv_obj_set_style_bg_color(guider_ui.screen_main_btn_chat, lv_color_hex(0xff6500), LV_PART_MAIN);
			lv_obj_set_style_text_font(guider_ui.screen_main_btn_chat, &lv_font_MI_LanTing_Regular_18, 0);
			HAL_UART_Transmit(&huart2,"chat_start\n",sizeof("chat_start\n"),10000);
			lv_label_set_text(guider_ui.screen_main_btn_chat_label, "停止说话");
			chat = 1;
		}
		else if(chat == 1)//stop chat
		{
			lv_obj_set_style_bg_color(guider_ui.screen_main_btn_chat, lv_color_hex(0x009ea9), LV_PART_MAIN);
			lv_obj_set_style_text_font(guider_ui.screen_main_btn_chat, &lv_font_MI_LanTing_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
			HAL_UART_Transmit(&huart2,"chat_stop\n",sizeof("chat_stop\n"),10000);
			lv_label_set_text(guider_ui.screen_main_btn_chat_label, "开始说话");			
			chat = 0;
		}
		break;
	}
	default:
		break;
	}
}
void events_init_screen_main(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_main, screen_main_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_btn_guard_mode, screen_main_btn_guard_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_btn_desk_mode, screen_main_btn_desk_mode_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_slider_led_Light, screen_main_slider_led_Light_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_btn_handset_light, screen_main_btn_handset_light_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_btn_auto_light, screen_main_btn_auto_light_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_main_btn_chat, screen_main_btn_chat_event_handler, LV_EVENT_ALL, ui);
}
static void screen_work_setting_btn_work_begin_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		int aa = 5*(lv_dropdown_get_selected(guider_ui.screen_work_setting_ddlist_work_time)+1);
		int b = 5*(lv_dropdown_get_selected(guider_ui.screen_work_setting_ddlist_game_time)+1);
		int c = 2*(lv_dropdown_get_selected(guider_ui.screen_work_setting_ddlist_turn_time)+1);
		int d = (lv_dropdown_get_selected(guider_ui.screen_work_setting_ddlist_work_mode));
	  work_set(aa,b,c,d);
		printf("para_work_max: %d\n",aa);
		printf("para_game_max: %d\n",b);
		printf("para_game_turn: %d\n",c);
		printf("para_mode: %d\n",d);
		
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_work, guider_ui.screen_work_del, &guider_ui.screen_work_setting_del, setup_scr_screen_work, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);

		if(d == 0)
			HAL_UART_Transmit(&huart2,"work_detector_start\n",sizeof("demo_work_detector_start\n"),10000);//Demo
		else if(d == 1)
			HAL_UART_Transmit(&huart2,"work_detector_start\n",sizeof("actual_work_detector_start\n"),10000);//Actual	
		
		screens = 2;	
		
		lv_bar_set_value(guider_ui.screen_work_drink_bar,100,LV_ANIM_ON);
		lv_bar_set_value(guider_ui.screen_work_game_bar,0,LV_ANIM_ON);
		lv_bar_set_value(guider_ui.screen_work_work_bar,100,LV_ANIM_ON);
		lv_label_set_text(guider_ui.screen_work_label_work_bar, "100.00");
		lv_label_set_text(guider_ui.screen_work_label_game_bar, "0.00");
		lv_label_set_text(guider_ui.screen_work_label_drink_bar, "100.00");
		lv_label_set_text(guider_ui.screen_work_label_work_time, "0");
		lv_label_set_text(guider_ui.screen_work_label_paly_time, "0");
		lv_label_set_text(guider_ui.screen_work_label_drink_time, "0");				
		
		break;
	}
	default:
		break;
	}
}
static void screen_work_setting_btn_work_cancel_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_work_setting_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		screens = 0;
		break;
	}
	default:
		break;
	}
}
void events_init_screen_work_setting(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_work_setting_btn_work_begin, screen_work_setting_btn_work_begin_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_work_setting_btn_work_cancel, screen_work_setting_btn_work_cancel_event_handler, LV_EVENT_ALL, ui);
}
static void screen_work_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_SCREEN_LOADED:
	{
		lv_obj_set_style_radius(guider_ui.screen_work_label_game_bar_1, 15, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_work_bar_1, 15, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_drink_bar_1, 15, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_drink_time, 3, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_paly_time, 3, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_work_time, 3, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_temp_pre_1, 8, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_led_light, 8, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_envscore_1, 8, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_temp_pre, 4, LV_PART_MAIN);
		lv_obj_set_style_radius(guider_ui.screen_work_label_envscore, 4, LV_PART_MAIN);
		break;
	}
	default:
		break;
	}
}
static void screen_work_button_stop_work_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_clear_flag(guider_ui.screen_work_msgbox_1, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(guider_ui.screen_work_btn_auto_light, LV_OBJ_FLAG_CLICKABLE);
		lv_obj_clear_flag(guider_ui.screen_work_btn_handset_light, LV_OBJ_FLAG_CLICKABLE);
		lv_obj_clear_flag(guider_ui.screen_work_slider_led_light, LV_OBJ_FLAG_CLICKABLE);
		lv_obj_clear_flag(guider_ui.screen_work_button_stop_work, LV_OBJ_FLAG_CLICKABLE);
		break;
	}
	default:
		break;
	}
}
static void screen_work_slider_led_light_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_work_btn_auto_light, lv_color_hex(0x00ffe0), LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.screen_work_btn_handset_light, lv_color_hex(0xff6500), LV_PART_MAIN);
		light_mode = 0;
		light_bright = lv_slider_get_value(guider_ui.screen_work_slider_led_light);
		break;
	}
	default:
		break;
	}
}
static void screen_work_btn_handset_light_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_work_btn_auto_light, lv_color_hex(0x00ffe0), LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.screen_work_btn_handset_light, lv_color_hex(0xff6500), LV_PART_MAIN);
		light_mode = 0;		
		break;
	}
	default:
		break;
	}
}
static void screen_work_btn_auto_light_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_set_style_bg_color(guider_ui.screen_work_btn_auto_light, lv_color_hex(0xff6500), LV_PART_MAIN);
		lv_obj_set_style_bg_color(guider_ui.screen_work_btn_handset_light, lv_color_hex(0x00ffe0), LV_PART_MAIN);
		light_mode = 1;
		break;
	}
	default:
		break;
	}
}
static void screen_work_msgbox_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		lv_obj_t * obj = lv_event_get_current_target(e);
		uint16_t id = lv_msgbox_get_active_btn(obj);
		switch(id) {
		case 0:
		{
			lv_obj_add_flag(guider_ui.screen_work_msgbox_1, LV_OBJ_FLAG_HIDDEN);
			ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_work_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
			screens = 0;
			
			char a[] = "work_detector_stop\n";
			HAL_UART_Transmit(&huart2,(unsigned char*)a,sizeof(a),10000);			
			
			break;
		}
		case 1:
		{
			lv_obj_add_flag(guider_ui.screen_work_msgbox_1, LV_OBJ_FLAG_HIDDEN);
			lv_obj_add_flag(guider_ui.screen_work_btn_auto_light, LV_OBJ_FLAG_CLICKABLE);
			lv_obj_add_flag(guider_ui.screen_work_btn_handset_light, LV_OBJ_FLAG_CLICKABLE);
			lv_obj_add_flag(guider_ui.screen_work_button_stop_work, LV_OBJ_FLAG_CLICKABLE);
			lv_obj_add_flag(guider_ui.screen_work_slider_led_light, LV_OBJ_FLAG_CLICKABLE);
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}
void events_init_screen_work(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_work, screen_work_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_work_button_stop_work, screen_work_button_stop_work_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_work_slider_led_light, screen_work_slider_led_light_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_work_btn_handset_light, screen_work_btn_handset_light_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_work_btn_auto_light, screen_work_btn_auto_light_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->screen_work_msgbox_1, screen_work_msgbox_1_event_handler, LV_EVENT_ALL, ui);
}
static void screen_guard_btn_1_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		HAL_UART_Transmit(&huart2,"guard_stop\n",sizeof("guard_stop\n"),1000);
		
				__HAL_TIM_SetCompare(&htim11, TIM_CHANNEL_1, 250+400/2-60);
		light_bright = 20;
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_guard_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
		screens = 0;
		
		break;
	}
	default:
		break;
	}
}
void events_init_screen_guard(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->screen_guard_btn_1, screen_guard_btn_1_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
