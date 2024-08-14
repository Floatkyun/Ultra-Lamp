/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int screen_work_setting_digital_clock_min_value = 9;
int screen_work_setting_digital_clock_hour_value = 19;
int screen_work_setting_digital_clock_sec_value = 41;
void setup_scr_screen_work_setting(lv_ui *ui)
{
	//Write codes screen_work_setting
	ui->screen_work_setting = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_work_setting, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_work_setting, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_work_setting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_setting, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_cont_main
	ui->screen_work_setting_cont_main = lv_obj_create(ui->screen_work_setting);
	lv_obj_set_pos(ui->screen_work_setting_cont_main, 0, 0);
	lv_obj_set_size(ui->screen_work_setting_cont_main, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_work_setting_cont_main, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_work_setting_cont_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_setting_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_cont_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_cont_main, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_dither_mode(ui->screen_work_setting_cont_main, LV_DITHER_ORDERED, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_cont_main, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_work_setting_cont_main, lv_color_hex(0x00FFFC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_work_setting_cont_main, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_work_setting_cont_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_setting_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_btn_work_begin
	ui->screen_work_setting_btn_work_begin = lv_btn_create(ui->screen_work_setting_cont_main);
	lv_obj_add_flag(ui->screen_work_setting_btn_work_begin, LV_OBJ_FLAG_CHECKABLE);
	ui->screen_work_setting_btn_work_begin_label = lv_label_create(ui->screen_work_setting_btn_work_begin);
	lv_label_set_text(ui->screen_work_setting_btn_work_begin_label, "开始");
	lv_label_set_long_mode(ui->screen_work_setting_btn_work_begin_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_work_setting_btn_work_begin_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_work_setting_btn_work_begin, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_work_setting_btn_work_begin_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_work_setting_btn_work_begin, 180, 190);
	lv_obj_set_size(ui->screen_work_setting_btn_work_begin, 100, 40);

	//Write style for screen_work_setting_btn_work_begin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_setting_btn_work_begin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_btn_work_begin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_dither_mode(ui->screen_work_setting_btn_work_begin, LV_DITHER_ORDERED, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_btn_work_begin, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_work_setting_btn_work_begin, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_work_setting_btn_work_begin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_work_setting_btn_work_begin, 194, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_setting_btn_work_begin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_btn_work_begin, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_btn_work_begin, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_setting_btn_work_begin, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_setting_btn_work_begin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_setting_btn_work_begin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_setting_btn_work_begin, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_setting_btn_work_begin, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_setting_btn_work_begin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_btn_work_begin, &lv_font_MI_LanTing_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_btn_work_begin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_setting_btn_work_begin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_btn_work_cancel
	ui->screen_work_setting_btn_work_cancel = lv_btn_create(ui->screen_work_setting_cont_main);
	ui->screen_work_setting_btn_work_cancel_label = lv_label_create(ui->screen_work_setting_btn_work_cancel);
	lv_label_set_text(ui->screen_work_setting_btn_work_cancel_label, "取消");
	lv_label_set_long_mode(ui->screen_work_setting_btn_work_cancel_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_work_setting_btn_work_cancel_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_work_setting_btn_work_cancel, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_work_setting_btn_work_cancel_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_work_setting_btn_work_cancel, 40, 190);
	lv_obj_set_size(ui->screen_work_setting_btn_work_cancel, 100, 40);

	//Write style for screen_work_setting_btn_work_cancel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_setting_btn_work_cancel, 128, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_btn_work_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_dither_mode(ui->screen_work_setting_btn_work_cancel, LV_DITHER_ORDERED, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_btn_work_cancel, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_work_setting_btn_work_cancel, lv_color_hex(0x7f7f7f), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_work_setting_btn_work_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_work_setting_btn_work_cancel, 194, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_setting_btn_work_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_btn_work_cancel, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_btn_work_cancel, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_setting_btn_work_cancel, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_setting_btn_work_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_setting_btn_work_cancel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_setting_btn_work_cancel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_setting_btn_work_cancel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_setting_btn_work_cancel, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_btn_work_cancel, &lv_font_MI_LanTing_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_btn_work_cancel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_setting_btn_work_cancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_cont_top
	ui->screen_work_setting_cont_top = lv_obj_create(ui->screen_work_setting_cont_main);
	lv_obj_set_pos(ui->screen_work_setting_cont_top, 0, 0);
	lv_obj_set_size(ui->screen_work_setting_cont_top, 320, 15);
	lv_obj_set_scrollbar_mode(ui->screen_work_setting_cont_top, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_work_setting_cont_top, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_cont_top, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_cont_top, lv_color_hex(0x808080), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_cont_top, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_label_wifi
	ui->screen_work_setting_label_wifi = lv_label_create(ui->screen_work_setting_cont_top);
	lv_label_set_text(ui->screen_work_setting_label_wifi, "" LV_SYMBOL_EDIT " " LV_SYMBOL_WIFI "");
	lv_label_set_long_mode(ui->screen_work_setting_label_wifi, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_setting_label_wifi, 280, 0);
	lv_obj_set_size(ui->screen_work_setting_label_wifi, 40, 15);

	//Write style for screen_work_setting_label_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_setting_label_wifi, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_label_wifi, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_label_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_setting_label_wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_digital_clock
	static bool screen_work_setting_digital_clock_timer_enabled = false;
	ui->screen_work_setting_digital_clock = lv_dclock_create(ui->screen_work_setting_cont_top, "19:09:41");
	if (!screen_work_setting_digital_clock_timer_enabled) {
		lv_timer_create(screen_work_setting_digital_clock_timer, 1000, NULL);
		screen_work_setting_digital_clock_timer_enabled = true;
	}
	lv_obj_set_pos(ui->screen_work_setting_digital_clock, 0, 0);
	lv_obj_set_size(ui->screen_work_setting_digital_clock, 65, 15);

	//Write style for screen_work_setting_digital_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_work_setting_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_setting_digital_clock, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_digital_clock, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_digital_clock, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_setting_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_setting_digital_clock, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_setting_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_label_work_time_choose_1
	ui->screen_work_setting_label_work_time_choose_1 = lv_label_create(ui->screen_work_setting_cont_main);
	lv_label_set_text(ui->screen_work_setting_label_work_time_choose_1, "工作时间:(分钟)");
	lv_label_set_long_mode(ui->screen_work_setting_label_work_time_choose_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_setting_label_work_time_choose_1, 25, 20);
	lv_obj_set_size(ui->screen_work_setting_label_work_time_choose_1, 110, 17);

	//Write style for screen_work_setting_label_work_time_choose_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_setting_label_work_time_choose_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_work_setting_label_work_time_choose_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_work_setting_label_work_time_choose_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_work_setting_label_work_time_choose_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_label_work_time_choose_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_setting_label_work_time_choose_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_label_work_time_choose_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_label_work_time_choose_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_setting_label_work_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_setting_label_work_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_setting_label_work_time_choose_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_label_work_time_choose_1, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_label_work_time_choose_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_label_work_time_choose_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_label_work_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_label_work_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_setting_label_work_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_label_work_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_label_work_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_label_game_time_choose_1
	ui->screen_work_setting_label_game_time_choose_1 = lv_label_create(ui->screen_work_setting_cont_main);
	lv_label_set_text(ui->screen_work_setting_label_game_time_choose_1, "休息时间:(分钟)");
	lv_label_set_long_mode(ui->screen_work_setting_label_game_time_choose_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_setting_label_game_time_choose_1, 175, 20);
	lv_obj_set_size(ui->screen_work_setting_label_game_time_choose_1, 110, 17);

	//Write style for screen_work_setting_label_game_time_choose_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_setting_label_game_time_choose_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_work_setting_label_game_time_choose_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_work_setting_label_game_time_choose_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_work_setting_label_game_time_choose_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_label_game_time_choose_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_setting_label_game_time_choose_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_label_game_time_choose_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_label_game_time_choose_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_setting_label_game_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_setting_label_game_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_setting_label_game_time_choose_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_label_game_time_choose_1, 80, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_label_game_time_choose_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_label_game_time_choose_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_label_game_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_label_game_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_setting_label_game_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_label_game_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_label_game_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_label_turn_time_choose_1
	ui->screen_work_setting_label_turn_time_choose_1 = lv_label_create(ui->screen_work_setting_cont_main);
	lv_label_set_text(ui->screen_work_setting_label_turn_time_choose_1, "最长手机时间:(分钟)");
	lv_label_set_long_mode(ui->screen_work_setting_label_turn_time_choose_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_setting_label_turn_time_choose_1, 20, 100);
	lv_obj_set_size(ui->screen_work_setting_label_turn_time_choose_1, 140, 17);

	//Write style for screen_work_setting_label_turn_time_choose_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_setting_label_turn_time_choose_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_work_setting_label_turn_time_choose_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_work_setting_label_turn_time_choose_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_work_setting_label_turn_time_choose_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_label_turn_time_choose_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_setting_label_turn_time_choose_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_label_turn_time_choose_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_label_turn_time_choose_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_setting_label_turn_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_setting_label_turn_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_setting_label_turn_time_choose_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_label_turn_time_choose_1, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_label_turn_time_choose_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_label_turn_time_choose_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_label_turn_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_label_turn_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_setting_label_turn_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_label_turn_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_label_turn_time_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_label_work_mode_choose_1
	ui->screen_work_setting_label_work_mode_choose_1 = lv_label_create(ui->screen_work_setting_cont_main);
	lv_label_set_text(ui->screen_work_setting_label_work_mode_choose_1, "工作模式:");
	lv_label_set_long_mode(ui->screen_work_setting_label_work_mode_choose_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_setting_label_work_mode_choose_1, 175, 100);
	lv_obj_set_size(ui->screen_work_setting_label_work_mode_choose_1, 70, 17);

	//Write style for screen_work_setting_label_work_mode_choose_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_setting_label_work_mode_choose_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_work_setting_label_work_mode_choose_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_work_setting_label_work_mode_choose_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_work_setting_label_work_mode_choose_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_label_work_mode_choose_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_setting_label_work_mode_choose_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_label_work_mode_choose_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_label_work_mode_choose_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_setting_label_work_mode_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_setting_label_work_mode_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_setting_label_work_mode_choose_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_label_work_mode_choose_1, 77, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_label_work_mode_choose_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_label_work_mode_choose_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_label_work_mode_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_label_work_mode_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_setting_label_work_mode_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_label_work_mode_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_label_work_mode_choose_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_ddlist_work_mode
	ui->screen_work_setting_ddlist_work_mode = lv_dropdown_create(ui->screen_work_setting_cont_main);
	lv_dropdown_set_options(ui->screen_work_setting_ddlist_work_mode, "Demo mode\nActual mode");
	lv_obj_set_pos(ui->screen_work_setting_ddlist_work_mode, 175, 129);
	lv_obj_set_size(ui->screen_work_setting_ddlist_work_mode, 130, 35);

	//Write style for screen_work_setting_ddlist_work_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_work_mode, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_work_mode, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_work_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_work_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_work_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_work_mode, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_work_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_work_mode, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_work_mode, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_work_mode, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_work_mode, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_work_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_work_mode, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_work_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_work_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_work_setting_ddlist_work_mode, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_work_mode, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_work_mode, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_work_mode, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_work_mode, 1, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_work_mode, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_work_mode, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_work_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_work_mode, 8, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_work_mode, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_work_mode, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_work_mode, 3, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_work_mode, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_work_mode, lv_color_hex(0x3bae90), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_work_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_work_mode, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_work_setting_ddlist_work_mode, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_work_mode, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_work_mode, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_work_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_work_mode, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_work_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_work_mode, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_work_mode, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_work_mode, 8, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_work_mode, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_work_mode, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_work_mode, 3, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_work_mode, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_work_mode, lv_color_hex(0x3bcba6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_work_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_work_mode, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style state: LV_STATE_CHECKED for &style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked
	static lv_style_t style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked;
	ui_init_style(&style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_work_mode), &style_screen_work_setting_ddlist_work_mode_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_setting_ddlist_work_mode_extra_list_main_default
	static lv_style_t style_screen_work_setting_ddlist_work_mode_extra_list_main_default;
	ui_init_style(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, &lv_font_montserratMedium_14);
	lv_style_set_text_opa(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, 255);
	lv_style_set_border_width(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, lv_color_hex(0x53a1d9));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_work_mode_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_work_mode), &style_screen_work_setting_ddlist_work_mode_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_setting_ddlist_work_mode_extra_list_scrollbar_default
	static lv_style_t style_screen_work_setting_ddlist_work_mode_extra_list_scrollbar_default;
	ui_init_style(&style_screen_work_setting_ddlist_work_mode_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_work_setting_ddlist_work_mode_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_work_mode_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_work_mode_extra_list_scrollbar_default, lv_color_hex(0x62b062));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_work_mode_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_work_mode), &style_screen_work_setting_ddlist_work_mode_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_ddlist_turn_time
	ui->screen_work_setting_ddlist_turn_time = lv_dropdown_create(ui->screen_work_setting_cont_main);
	lv_dropdown_set_options(ui->screen_work_setting_ddlist_turn_time, "2\n4\n6\n8\n10\n12\n14\n16\n18\n20\n22\n24\n26\n28\n30");
	lv_obj_set_pos(ui->screen_work_setting_ddlist_turn_time, 20, 130);
	lv_obj_set_size(ui->screen_work_setting_ddlist_turn_time, 130, 35);

	//Write style for screen_work_setting_ddlist_turn_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_turn_time, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_turn_time, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_turn_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_turn_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_turn_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_turn_time, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_turn_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_turn_time, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_turn_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_turn_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_turn_time, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_turn_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_turn_time, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_turn_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_turn_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_work_setting_ddlist_turn_time, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_turn_time, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_turn_time, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_turn_time, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_turn_time, 1, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_turn_time, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_turn_time, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_turn_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_turn_time, 8, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_turn_time, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_turn_time, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_turn_time, 3, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_turn_time, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_turn_time, lv_color_hex(0x3bae90), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_turn_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_turn_time, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_work_setting_ddlist_turn_time, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_turn_time, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_turn_time, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_turn_time, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_turn_time, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_turn_time, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_turn_time, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_turn_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_turn_time, 8, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_turn_time, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_turn_time, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_turn_time, 3, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_turn_time, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_turn_time, lv_color_hex(0x3bcba6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_turn_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_turn_time, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style state: LV_STATE_CHECKED for &style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked
	static lv_style_t style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked;
	ui_init_style(&style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_turn_time), &style_screen_work_setting_ddlist_turn_time_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_setting_ddlist_turn_time_extra_list_main_default
	static lv_style_t style_screen_work_setting_ddlist_turn_time_extra_list_main_default;
	ui_init_style(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, &lv_font_montserratMedium_14);
	lv_style_set_text_opa(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, 255);
	lv_style_set_border_width(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, lv_color_hex(0x53a1d9));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_turn_time_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_turn_time), &style_screen_work_setting_ddlist_turn_time_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_setting_ddlist_turn_time_extra_list_scrollbar_default
	static lv_style_t style_screen_work_setting_ddlist_turn_time_extra_list_scrollbar_default;
	ui_init_style(&style_screen_work_setting_ddlist_turn_time_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_work_setting_ddlist_turn_time_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_turn_time_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_turn_time_extra_list_scrollbar_default, lv_color_hex(0x62b062));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_turn_time_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_turn_time), &style_screen_work_setting_ddlist_turn_time_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_ddlist_work_time
	ui->screen_work_setting_ddlist_work_time = lv_dropdown_create(ui->screen_work_setting_cont_main);
	lv_dropdown_set_options(ui->screen_work_setting_ddlist_work_time, "5\n10\n15\n20\n25\n30\n35\n40\n45\n50\n55\n60");
	lv_obj_set_pos(ui->screen_work_setting_ddlist_work_time, 20, 50);
	lv_obj_set_size(ui->screen_work_setting_ddlist_work_time, 130, 35);

	//Write style for screen_work_setting_ddlist_work_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_work_time, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_work_time, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_work_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_work_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_work_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_work_time, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_work_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_work_time, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_work_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_work_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_work_time, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_work_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_work_time, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_work_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_work_setting_ddlist_work_time, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_work_time, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_work_time, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_work_time, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_work_time, 1, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_work_time, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_work_time, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_work_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_work_time, 8, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_work_time, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_work_time, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_work_time, 3, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_work_time, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_work_time, lv_color_hex(0x3bae90), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_work_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_work_time, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_work_setting_ddlist_work_time, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_work_time, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_work_time, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_work_time, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_work_time, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_work_time, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_work_time, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_work_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_work_time, 8, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_work_time, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_work_time, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_work_time, 3, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_work_time, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_work_time, lv_color_hex(0x3bcba6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_work_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_work_time, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style state: LV_STATE_CHECKED for &style_screen_work_setting_ddlist_work_time_extra_list_selected_checked
	static lv_style_t style_screen_work_setting_ddlist_work_time_extra_list_selected_checked;
	ui_init_style(&style_screen_work_setting_ddlist_work_time_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_screen_work_setting_ddlist_work_time_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_work_setting_ddlist_work_time_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_work_setting_ddlist_work_time_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_work_setting_ddlist_work_time_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_work_setting_ddlist_work_time_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_work_time_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_work_time_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_work_time_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_work_time), &style_screen_work_setting_ddlist_work_time_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_setting_ddlist_work_time_extra_list_main_default
	static lv_style_t style_screen_work_setting_ddlist_work_time_extra_list_main_default;
	ui_init_style(&style_screen_work_setting_ddlist_work_time_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, &lv_font_montserratMedium_14);
	lv_style_set_text_opa(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, 255);
	lv_style_set_border_width(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, lv_color_hex(0x53a1d9));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_work_time_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_work_time), &style_screen_work_setting_ddlist_work_time_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_setting_ddlist_work_time_extra_list_scrollbar_default
	static lv_style_t style_screen_work_setting_ddlist_work_time_extra_list_scrollbar_default;
	ui_init_style(&style_screen_work_setting_ddlist_work_time_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_work_setting_ddlist_work_time_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_work_time_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_work_time_extra_list_scrollbar_default, lv_color_hex(0x62b062));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_work_time_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_work_time), &style_screen_work_setting_ddlist_work_time_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_work_setting_ddlist_game_time
	ui->screen_work_setting_ddlist_game_time = lv_dropdown_create(ui->screen_work_setting_cont_main);
	lv_dropdown_set_options(ui->screen_work_setting_ddlist_game_time, "5\n10\n15\n20\n25\n30\n35\n40\n45\n50\n55\n60");
	lv_obj_set_pos(ui->screen_work_setting_ddlist_game_time, 174, 49);
	lv_obj_set_size(ui->screen_work_setting_ddlist_game_time, 130, 35);

	//Write style for screen_work_setting_ddlist_game_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_game_time, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_game_time, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_game_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_game_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_game_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_game_time, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_game_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_game_time, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_game_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_game_time, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_game_time, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_game_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_game_time, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_game_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_game_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_work_setting_ddlist_game_time, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_game_time, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_game_time, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_game_time, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_game_time, 1, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_game_time, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_game_time, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_game_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_game_time, 8, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_game_time, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_game_time, 6, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_game_time, 3, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_game_time, 255, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_game_time, lv_color_hex(0x3bae90), LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_game_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_game_time, 0, LV_PART_MAIN|LV_STATE_CHECKED);

	//Write style for screen_work_setting_ddlist_game_time, Part: LV_PART_MAIN, State: LV_STATE_FOCUSED.
	lv_obj_set_style_text_color(ui->screen_work_setting_ddlist_game_time, lv_color_hex(0x0D3055), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_font(ui->screen_work_setting_ddlist_game_time, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_text_opa(ui->screen_work_setting_ddlist_game_time, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_width(ui->screen_work_setting_ddlist_game_time, 1, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_opa(ui->screen_work_setting_ddlist_game_time, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_color(ui->screen_work_setting_ddlist_game_time, lv_color_hex(0xe1e6ee), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_border_side(ui->screen_work_setting_ddlist_game_time, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_top(ui->screen_work_setting_ddlist_game_time, 8, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_left(ui->screen_work_setting_ddlist_game_time, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_pad_right(ui->screen_work_setting_ddlist_game_time, 6, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_radius(ui->screen_work_setting_ddlist_game_time, 3, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_opa(ui->screen_work_setting_ddlist_game_time, 255, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_color(ui->screen_work_setting_ddlist_game_time, lv_color_hex(0x3bcba6), LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_setting_ddlist_game_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_FOCUSED);
	lv_obj_set_style_shadow_width(ui->screen_work_setting_ddlist_game_time, 0, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style state: LV_STATE_CHECKED for &style_screen_work_setting_ddlist_game_time_extra_list_selected_checked
	static lv_style_t style_screen_work_setting_ddlist_game_time_extra_list_selected_checked;
	ui_init_style(&style_screen_work_setting_ddlist_game_time_extra_list_selected_checked);
	
	lv_style_set_border_width(&style_screen_work_setting_ddlist_game_time_extra_list_selected_checked, 1);
	lv_style_set_border_opa(&style_screen_work_setting_ddlist_game_time_extra_list_selected_checked, 255);
	lv_style_set_border_color(&style_screen_work_setting_ddlist_game_time_extra_list_selected_checked, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_work_setting_ddlist_game_time_extra_list_selected_checked, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_work_setting_ddlist_game_time_extra_list_selected_checked, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_game_time_extra_list_selected_checked, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_game_time_extra_list_selected_checked, lv_color_hex(0x00a1b5));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_game_time_extra_list_selected_checked, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_game_time), &style_screen_work_setting_ddlist_game_time_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_setting_ddlist_game_time_extra_list_main_default
	static lv_style_t style_screen_work_setting_ddlist_game_time_extra_list_main_default;
	ui_init_style(&style_screen_work_setting_ddlist_game_time_extra_list_main_default);
	
	lv_style_set_max_height(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, 90);
	lv_style_set_text_color(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, lv_color_hex(0x0D3055));
	lv_style_set_text_font(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, &lv_font_montserratMedium_14);
	lv_style_set_text_opa(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, 255);
	lv_style_set_border_width(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, 1);
	lv_style_set_border_opa(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, 255);
	lv_style_set_border_color(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, lv_color_hex(0xe1e6ee));
	lv_style_set_border_side(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, LV_BORDER_SIDE_FULL);
	lv_style_set_radius(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, lv_color_hex(0x53a1d9));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_game_time_extra_list_main_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_game_time), &style_screen_work_setting_ddlist_game_time_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_setting_ddlist_game_time_extra_list_scrollbar_default
	static lv_style_t style_screen_work_setting_ddlist_game_time_extra_list_scrollbar_default;
	ui_init_style(&style_screen_work_setting_ddlist_game_time_extra_list_scrollbar_default);
	
	lv_style_set_radius(&style_screen_work_setting_ddlist_game_time_extra_list_scrollbar_default, 3);
	lv_style_set_bg_opa(&style_screen_work_setting_ddlist_game_time_extra_list_scrollbar_default, 255);
	lv_style_set_bg_color(&style_screen_work_setting_ddlist_game_time_extra_list_scrollbar_default, lv_color_hex(0x62b062));
	lv_style_set_bg_grad_dir(&style_screen_work_setting_ddlist_game_time_extra_list_scrollbar_default, LV_GRAD_DIR_NONE);
	lv_obj_add_style(lv_dropdown_get_list(ui->screen_work_setting_ddlist_game_time), &style_screen_work_setting_ddlist_game_time_extra_list_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//The custom code of screen_work_setting.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_work_setting);

	//Init events for screen.
	events_init_screen_work_setting(ui);
}
