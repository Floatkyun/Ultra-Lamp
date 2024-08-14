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

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


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
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_guard, guider_ui.screen_guard_del, &guider_ui.screen_main_del, setup_scr_screen_guard, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
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
		lv_obj_set_style_bg_color(guider_ui.screen_main_btn_chat, lv_color_hex(0xff6500), LV_PART_MAIN);
		lv_obj_set_style_text_font(guider_ui.screen_main_btn_chat, &lv_font_MI_LanTing_Regular_18, 0);
		lv_label_set_text(guider_ui.screen_main_btn_chat_label, "停止说话");
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
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_work, guider_ui.screen_work_del, &guider_ui.screen_work_setting_del, setup_scr_screen_work, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
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
		ui_load_scr_animation(&guider_ui, &guider_ui.screen_main, guider_ui.screen_main_del, &guider_ui.screen_guard_del, setup_scr_screen_main, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
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
