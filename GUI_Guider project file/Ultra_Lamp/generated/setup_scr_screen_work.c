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



int screen_work_digital_clock_min_value = 9;
int screen_work_digital_clock_hour_value = 19;
int screen_work_digital_clock_sec_value = 41;
void setup_scr_screen_work(lv_ui *ui)
{
	//Write codes screen_work
	ui->screen_work = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_work, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_work, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_work, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_cont_main
	ui->screen_work_cont_main = lv_obj_create(ui->screen_work);
	lv_obj_set_pos(ui->screen_work_cont_main, 0, 0);
	lv_obj_set_size(ui->screen_work_cont_main, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_work_cont_main, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_work_cont_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_cont_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_cont_main, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_cont_main, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_work_cont_main, lv_color_hex(0x00fffc), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_work_cont_main, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_work_cont_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_drink_bar
	ui->screen_work_drink_bar = lv_bar_create(ui->screen_work_cont_main);
	lv_obj_set_style_anim_time(ui->screen_work_drink_bar, 500, 0);
	lv_bar_set_mode(ui->screen_work_drink_bar, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->screen_work_drink_bar, 0, 100);
	lv_bar_set_value(ui->screen_work_drink_bar, 100, LV_ANIM_ON);
	lv_obj_set_pos(ui->screen_work_drink_bar, 90, 180);
	lv_obj_set_size(ui->screen_work_drink_bar, 210, 15);

	//Write style for screen_work_drink_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_drink_bar, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_drink_bar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_drink_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_drink_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_drink_bar, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_drink_bar, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_drink_bar, 130, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_drink_bar, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_drink_bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_drink_bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_work_drink_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_drink_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_drink_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_drink_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_drink_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_work_game_bar
	ui->screen_work_game_bar = lv_bar_create(ui->screen_work_cont_main);
	lv_obj_set_style_anim_time(ui->screen_work_game_bar, 500, 0);
	lv_bar_set_mode(ui->screen_work_game_bar, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->screen_work_game_bar, 0, 100);
	lv_bar_set_value(ui->screen_work_game_bar, 1, LV_ANIM_ON);
	lv_obj_set_pos(ui->screen_work_game_bar, 90, 150);
	lv_obj_set_size(ui->screen_work_game_bar, 210, 15);

	//Write style for screen_work_game_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_game_bar, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_game_bar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_game_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_game_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_game_bar, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_game_bar, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_game_bar, 128, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_game_bar, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_game_bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_game_bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_work_game_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_game_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_game_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_game_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_game_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_work_work_bar
	ui->screen_work_work_bar = lv_bar_create(ui->screen_work_cont_main);
	lv_obj_set_style_anim_time(ui->screen_work_work_bar, 500, 0);
	lv_bar_set_mode(ui->screen_work_work_bar, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->screen_work_work_bar, 0, 100);
	lv_bar_set_value(ui->screen_work_work_bar, 50, LV_ANIM_ON);
	lv_obj_set_pos(ui->screen_work_work_bar, 90, 120);
	lv_obj_set_size(ui->screen_work_work_bar, 210, 15);

	//Write style for screen_work_work_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_work_bar, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_work_bar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_work_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_work_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_work_bar, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_work_bar, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_work_bar, 128, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_work_bar, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_work_bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_work_bar, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_work_work_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_work_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_work_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_work_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_work_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_work_label_work_bar_1
	ui->screen_work_label_work_bar_1 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_work_bar_1, "精力");
	lv_label_set_long_mode(ui->screen_work_label_work_bar_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_work_bar_1, 40, 120);
	lv_obj_set_size(ui->screen_work_label_work_bar_1, 40, 15);

	//Write style for screen_work_label_work_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_work_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_work_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_work_bar_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_work_bar_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_work_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_work_bar_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_work_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_work_bar_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_work_bar_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_label_work_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_label_work_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_work_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_work_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_work_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_work_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_work_bar_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_label_work_bar_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_label_work_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_label_work_bar_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_label_work_bar_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_label_work_bar_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_game_bar_1
	ui->screen_work_label_game_bar_1 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_game_bar_1, "放松");
	lv_label_set_long_mode(ui->screen_work_label_game_bar_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_game_bar_1, 40, 150);
	lv_obj_set_size(ui->screen_work_label_game_bar_1, 40, 15);

	//Write style for screen_work_label_game_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_game_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_game_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_game_bar_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_game_bar_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_game_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_game_bar_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_game_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_game_bar_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_game_bar_1, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_label_game_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_label_game_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_game_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_game_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_game_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_game_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_game_bar_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_label_game_bar_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_label_game_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_label_game_bar_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_label_game_bar_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_label_game_bar_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_drink_bar_1
	ui->screen_work_label_drink_bar_1 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_drink_bar_1, "口渴");
	lv_label_set_long_mode(ui->screen_work_label_drink_bar_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_drink_bar_1, 41, 180);
	lv_obj_set_size(ui->screen_work_label_drink_bar_1, 40, 15);

	//Write style for screen_work_label_drink_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_drink_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_drink_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_drink_bar_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_drink_bar_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_drink_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_drink_bar_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_drink_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_drink_bar_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_drink_bar_1, 61, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_label_drink_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_label_drink_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_drink_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_drink_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_drink_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_drink_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_drink_bar_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_label_drink_bar_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_label_drink_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_label_drink_bar_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_label_drink_bar_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_label_drink_bar_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_button_stop_work
	ui->screen_work_button_stop_work = lv_btn_create(ui->screen_work_cont_main);
	ui->screen_work_button_stop_work_label = lv_label_create(ui->screen_work_button_stop_work);
	lv_label_set_text(ui->screen_work_button_stop_work_label, "退出桌面模式");
	lv_label_set_long_mode(ui->screen_work_button_stop_work_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_work_button_stop_work_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_work_button_stop_work, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_work_button_stop_work_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_work_button_stop_work, 90, 205);
	lv_obj_set_size(ui->screen_work_button_stop_work, 140, 30);

	//Write style for screen_work_button_stop_work, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_button_stop_work, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_button_stop_work, lv_color_hex(0xff0000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_button_stop_work, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_button_stop_work, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_button_stop_work, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_button_stop_work, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_button_stop_work, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_button_stop_work, &lv_font_MI_LanTing_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_button_stop_work, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_button_stop_work, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_work_time_1
	ui->screen_work_label_work_time_1 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_work_time_1, "已经连续工作");
	lv_label_set_long_mode(ui->screen_work_label_work_time_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_work_time_1, 40, 50);
	lv_obj_set_size(ui->screen_work_label_work_time_1, 90, 15);

	//Write style for screen_work_label_work_time_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_work_time_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_work_time_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_work_time_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_work_time_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_work_time_1, 179, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_label_work_time_1, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_label_work_time_1, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_work_label_work_time_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_work_label_work_time_1, 223, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_work_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_game_time_1
	ui->screen_work_label_game_time_1 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_game_time_1, "已连续玩手机");
	lv_label_set_long_mode(ui->screen_work_label_game_time_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_game_time_1, 40, 70);
	lv_obj_set_size(ui->screen_work_label_game_time_1, 90, 15);

	//Write style for screen_work_label_game_time_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_game_time_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_game_time_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_game_time_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_game_time_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_game_time_1, 180, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_label_game_time_1, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_label_game_time_1, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_work_label_game_time_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_work_label_game_time_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_game_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_drink_time_1
	ui->screen_work_label_drink_time_1 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_drink_time_1, "目前已喝水 ");
	lv_label_set_long_mode(ui->screen_work_label_drink_time_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_drink_time_1, 47, 90);
	lv_obj_set_size(ui->screen_work_label_drink_time_1, 75, 15);

	//Write style for screen_work_label_drink_time_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_drink_time_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_drink_time_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_drink_time_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_drink_time_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_drink_time_1, 179, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_label_drink_time_1, lv_color_hex(0x00ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_label_drink_time_1, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_work_label_drink_time_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_work_label_drink_time_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_drink_time_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_work_time
	ui->screen_work_label_work_time = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_work_time, "---");
	lv_label_set_long_mode(ui->screen_work_label_work_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_work_time, 132, 50);
	lv_obj_set_size(ui->screen_work_label_work_time, 30, 15);

	//Write style for screen_work_label_work_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_work_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_work_time, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_work_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_work_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_work_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_work_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_work_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_label_work_time, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_label_work_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_label_work_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_label_work_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_label_work_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_paly_time
	ui->screen_work_label_paly_time = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_paly_time, "---");
	lv_label_set_long_mode(ui->screen_work_label_paly_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_paly_time, 132, 70);
	lv_obj_set_size(ui->screen_work_label_paly_time, 30, 15);

	//Write style for screen_work_label_paly_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_paly_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_paly_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_paly_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_paly_time, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_paly_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_paly_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_paly_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_paly_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_paly_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_paly_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_paly_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_paly_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_paly_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_paly_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_label_paly_time, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_label_paly_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_label_paly_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_label_paly_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_label_paly_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_drink_time
	ui->screen_work_label_drink_time = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_drink_time, "---");
	lv_label_set_long_mode(ui->screen_work_label_drink_time, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_drink_time, 132, 90);
	lv_obj_set_size(ui->screen_work_label_drink_time, 30, 15);

	//Write style for screen_work_label_drink_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_drink_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_drink_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_drink_time, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_drink_time, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_drink_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_drink_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_drink_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_drink_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_drink_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_drink_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_drink_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_drink_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_drink_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_drink_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_label_drink_time, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_label_drink_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_label_drink_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_label_drink_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_label_drink_time, 1, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_work_time_2
	ui->screen_work_label_work_time_2 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_work_time_2, "分钟");
	lv_label_set_long_mode(ui->screen_work_label_work_time_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_work_time_2, 165, 50);
	lv_obj_set_size(ui->screen_work_label_work_time_2, 30, 15);

	//Write style for screen_work_label_work_time_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_work_time_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_work_time_2, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_work_time_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_work_time_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_work_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_game_time_2
	ui->screen_work_label_game_time_2 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_game_time_2, "分钟");
	lv_label_set_long_mode(ui->screen_work_label_game_time_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_game_time_2, 165, 70);
	lv_obj_set_size(ui->screen_work_label_game_time_2, 30, 15);

	//Write style for screen_work_label_game_time_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_game_time_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_game_time_2, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_game_time_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_game_time_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_game_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_drink_time_2
	ui->screen_work_label_drink_time_2 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_drink_time_2, "次");
	lv_label_set_long_mode(ui->screen_work_label_drink_time_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_drink_time_2, 165, 90);
	lv_obj_set_size(ui->screen_work_label_drink_time_2, 15, 15);

	//Write style for screen_work_label_drink_time_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_drink_time_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_drink_time_2, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_drink_time_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_drink_time_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_drink_time_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_slider_led_light
	ui->screen_work_slider_led_light = lv_slider_create(ui->screen_work_cont_main);
	lv_slider_set_range(ui->screen_work_slider_led_light, 0, 100);
	lv_slider_set_mode(ui->screen_work_slider_led_light, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->screen_work_slider_led_light, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_work_slider_led_light, 12, 55);
	lv_obj_set_size(ui->screen_work_slider_led_light, 15, 170);

	//Write style for screen_work_slider_led_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_slider_led_light, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_slider_led_light, lv_color_hex(0x34ffa4), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_slider_led_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_slider_led_light, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->screen_work_slider_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_slider_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_work_slider_led_light, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_slider_led_light, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_slider_led_light, lv_color_hex(0x34ff98), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_slider_led_light, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_slider_led_light, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_work_slider_led_light, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_slider_led_light, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_slider_led_light, lv_color_hex(0x00ed5c), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_slider_led_light, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_slider_led_light, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_work_label_led_light
	ui->screen_work_label_led_light = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_led_light, "台灯亮度");
	lv_label_set_long_mode(ui->screen_work_label_led_light, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_led_light, 5, 15);
	lv_obj_set_size(ui->screen_work_label_led_light, 30, 30);

	//Write style for screen_work_label_led_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_led_light, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_led_light, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_led_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_led_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_led_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_label_led_light, lv_color_hex(0x34ffa4), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_label_led_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_temp_pre_1
	ui->screen_work_label_temp_pre_1 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_temp_pre_1, "温度预测");
	lv_label_set_long_mode(ui->screen_work_label_temp_pre_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_temp_pre_1, 210, 50);
	lv_obj_set_size(ui->screen_work_label_temp_pre_1, 30, 30);

	//Write style for screen_work_label_temp_pre_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_temp_pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_temp_pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_temp_pre_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_temp_pre_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_temp_pre_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_temp_pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_temp_pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_temp_pre_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_temp_pre_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_label_temp_pre_1, lv_color_hex(0x00ff93), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_label_temp_pre_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_temp_pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_temp_pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_temp_pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_temp_pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_temp_pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_temp_pre
	ui->screen_work_label_temp_pre = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_temp_pre, "--");
	lv_label_set_long_mode(ui->screen_work_label_temp_pre, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_temp_pre, 250, 50);
	lv_obj_set_size(ui->screen_work_label_temp_pre, 33, 28);

	//Write style for screen_work_label_temp_pre, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_temp_pre, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_temp_pre, &lv_font_MI_LanTing_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_temp_pre, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_temp_pre, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_temp_pre, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_label_temp_pre, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_label_temp_pre, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_label_temp_pre, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_label_temp_pre, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_label_temp_pre, 3, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_envscore_1
	ui->screen_work_label_envscore_1 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_envscore_1, "环境评分");
	lv_label_set_long_mode(ui->screen_work_label_envscore_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_envscore_1, 210, 85);
	lv_obj_set_size(ui->screen_work_label_envscore_1, 30, 30);

	//Write style for screen_work_label_envscore_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_envscore_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_envscore_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_envscore_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_envscore_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_envscore_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_label_envscore_1, lv_color_hex(0x00ff93), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_label_envscore_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_envscore
	ui->screen_work_label_envscore = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_envscore, "---");
	lv_label_set_long_mode(ui->screen_work_label_envscore, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_envscore, 250, 85);
	lv_obj_set_size(ui->screen_work_label_envscore, 49, 28);

	//Write style for screen_work_label_envscore, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_envscore, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_envscore, &lv_font_MI_LanTing_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_envscore, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_envscore, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_envscore, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_label_envscore, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_label_envscore, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_label_envscore, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_label_envscore, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_label_envscore, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_spinner
	ui->screen_work_spinner = lv_spinner_create(ui->screen_work_cont_main, 1000, 60);
	lv_obj_set_pos(ui->screen_work_spinner, 275, 15);
	lv_obj_set_size(ui->screen_work_spinner, 30, 30);

	//Write style for screen_work_spinner, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->screen_work_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_work_spinner, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_work_spinner, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_work_spinner, lv_color_hex(0x727272), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_spinner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_work_spinner, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_work_spinner, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_work_spinner, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_work_spinner, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_work_btn_handset_light
	ui->screen_work_btn_handset_light = lv_btn_create(ui->screen_work_cont_main);
	ui->screen_work_btn_handset_light_label = lv_label_create(ui->screen_work_btn_handset_light);
	lv_label_set_text(ui->screen_work_btn_handset_light_label, "手动亮度");
	lv_label_set_long_mode(ui->screen_work_btn_handset_light_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_work_btn_handset_light_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_work_btn_handset_light, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_work_btn_handset_light_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_work_btn_handset_light, 80, 15);
	lv_obj_set_size(ui->screen_work_btn_handset_light, 75, 30);

	//Write style for screen_work_btn_handset_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_btn_handset_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_btn_handset_light, lv_color_hex(0x00ffe0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_btn_handset_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_btn_handset_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_btn_handset_light, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_btn_handset_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_btn_handset_light, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_btn_handset_light, &lv_font_MI_LanTing_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_btn_handset_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_btn_handset_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_btn_auto_light
	ui->screen_work_btn_auto_light = lv_btn_create(ui->screen_work_cont_main);
	ui->screen_work_btn_auto_light_label = lv_label_create(ui->screen_work_btn_auto_light);
	lv_label_set_text(ui->screen_work_btn_auto_light_label, "自动亮度");
	lv_label_set_long_mode(ui->screen_work_btn_auto_light_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_work_btn_auto_light_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_work_btn_auto_light, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_work_btn_auto_light_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_work_btn_auto_light, 165, 15);
	lv_obj_set_size(ui->screen_work_btn_auto_light, 75, 30);

	//Write style for screen_work_btn_auto_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_btn_auto_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_btn_auto_light, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_btn_auto_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_btn_auto_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_btn_auto_light, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_btn_auto_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_btn_auto_light, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_btn_auto_light, &lv_font_MI_LanTing_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_btn_auto_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_btn_auto_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_work_bar
	ui->screen_work_label_work_bar = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_work_bar, "---");
	lv_label_set_long_mode(ui->screen_work_label_work_bar, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_work_bar, 90, 120);
	lv_obj_set_size(ui->screen_work_label_work_bar, 105, 15);

	//Write style for screen_work_label_work_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_work_bar, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_work_bar, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_work_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_work_bar, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_work_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_work_bar_3
	ui->screen_work_label_work_bar_3 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_work_bar_3, "%");
	lv_label_set_long_mode(ui->screen_work_label_work_bar_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_work_bar_3, 195, 120);
	lv_obj_set_size(ui->screen_work_label_work_bar_3, 105, 15);

	//Write style for screen_work_label_work_bar_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_work_bar_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_work_bar_3, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_work_bar_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_work_bar_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_work_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_drink_bar_3
	ui->screen_work_label_drink_bar_3 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_drink_bar_3, "%");
	lv_label_set_long_mode(ui->screen_work_label_drink_bar_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_drink_bar_3, 195, 180);
	lv_obj_set_size(ui->screen_work_label_drink_bar_3, 105, 15);

	//Write style for screen_work_label_drink_bar_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_drink_bar_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_drink_bar_3, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_drink_bar_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_drink_bar_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_drink_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_game_bar_3
	ui->screen_work_label_game_bar_3 = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_game_bar_3, "%");
	lv_label_set_long_mode(ui->screen_work_label_game_bar_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_game_bar_3, 195, 150);
	lv_obj_set_size(ui->screen_work_label_game_bar_3, 105, 15);

	//Write style for screen_work_label_game_bar_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_game_bar_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_game_bar_3, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_game_bar_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_game_bar_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_game_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_game_bar
	ui->screen_work_label_game_bar = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_game_bar, "---");
	lv_label_set_long_mode(ui->screen_work_label_game_bar, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_game_bar, 90, 150);
	lv_obj_set_size(ui->screen_work_label_game_bar, 105, 15);

	//Write style for screen_work_label_game_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_game_bar, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_game_bar, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_game_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_game_bar, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_game_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_drink_bar
	ui->screen_work_label_drink_bar = lv_label_create(ui->screen_work_cont_main);
	lv_label_set_text(ui->screen_work_label_drink_bar, "---");
	lv_label_set_long_mode(ui->screen_work_label_drink_bar, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_drink_bar, 90, 180);
	lv_obj_set_size(ui->screen_work_label_drink_bar, 105, 15);

	//Write style for screen_work_label_drink_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_drink_bar, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_drink_bar, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_drink_bar, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_drink_bar, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_drink_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_cont_top
	ui->screen_work_cont_top = lv_obj_create(ui->screen_work);
	lv_obj_set_pos(ui->screen_work_cont_top, 0, 0);
	lv_obj_set_size(ui->screen_work_cont_top, 320, 15);
	lv_obj_set_scrollbar_mode(ui->screen_work_cont_top, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_work_cont_top, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_cont_top, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_cont_top, lv_color_hex(0x808080), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_cont_top, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_label_wifi
	ui->screen_work_label_wifi = lv_label_create(ui->screen_work_cont_top);
	lv_label_set_text(ui->screen_work_label_wifi, "" LV_SYMBOL_EDIT " " LV_SYMBOL_WIFI "");
	lv_label_set_long_mode(ui->screen_work_label_wifi, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_work_label_wifi, 280, 0);
	lv_obj_set_size(ui->screen_work_label_wifi, 40, 15);

	//Write style for screen_work_label_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_label_wifi, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_label_wifi, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_label_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_label_wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_digital_clock
	static bool screen_work_digital_clock_timer_enabled = false;
	ui->screen_work_digital_clock = lv_dclock_create(ui->screen_work_cont_top, "19:09:41");
	if (!screen_work_digital_clock_timer_enabled) {
		lv_timer_create(screen_work_digital_clock_timer, 1000, NULL);
		screen_work_digital_clock_timer_enabled = true;
	}
	lv_obj_set_pos(ui->screen_work_digital_clock, 0, 0);
	lv_obj_set_size(ui->screen_work_digital_clock, 65, 15);

	//Write style for screen_work_digital_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_work_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_work_digital_clock, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_work_digital_clock, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_work_digital_clock, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_work_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_work_digital_clock, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_work_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_work_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_work_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_work_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_work_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_work_msgbox_1
	static const char * screen_work_msgbox_1_btns[] = {"是","否", ""};
	ui->screen_work_msgbox_1 = lv_msgbox_create(ui->screen_work, "是否退出桌面模式？", "退出后统计时长数据无法恢复", screen_work_msgbox_1_btns, false);
	lv_obj_set_size(lv_msgbox_get_btns(ui->screen_work_msgbox_1), 240, 35);
	lv_obj_set_pos(ui->screen_work_msgbox_1, 35, 65);
	lv_obj_set_size(ui->screen_work_msgbox_1, 250, 101);
	lv_obj_add_flag(ui->screen_work_msgbox_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_add_flag(ui->screen_work_msgbox_1, LV_OBJ_FLAG_HIDDEN);

	//Write style for screen_work_msgbox_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_work_msgbox_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_work_msgbox_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_work_msgbox_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_work_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_work_msgbox_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_work_msgbox_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_work_msgbox_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_work_msgbox_1, 105, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_work_msgbox_1, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_work_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_work_msgbox_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_msgbox_1_extra_title_main_default
	static lv_style_t style_screen_work_msgbox_1_extra_title_main_default;
	ui_init_style(&style_screen_work_msgbox_1_extra_title_main_default);
	
	lv_style_set_text_color(&style_screen_work_msgbox_1_extra_title_main_default, lv_color_hex(0x4e4e4e));
	lv_style_set_text_font(&style_screen_work_msgbox_1_extra_title_main_default, &lv_font_MI_LanTing_Regular_12);
	lv_style_set_text_opa(&style_screen_work_msgbox_1_extra_title_main_default, 255);
	lv_style_set_text_letter_space(&style_screen_work_msgbox_1_extra_title_main_default, 0);
	lv_style_set_text_line_space(&style_screen_work_msgbox_1_extra_title_main_default, 30);
	lv_obj_add_style(lv_msgbox_get_title(ui->screen_work_msgbox_1), &style_screen_work_msgbox_1_extra_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_msgbox_1_extra_content_main_default
	static lv_style_t style_screen_work_msgbox_1_extra_content_main_default;
	ui_init_style(&style_screen_work_msgbox_1_extra_content_main_default);
	
	lv_style_set_text_color(&style_screen_work_msgbox_1_extra_content_main_default, lv_color_hex(0x4e4e4e));
	lv_style_set_text_font(&style_screen_work_msgbox_1_extra_content_main_default, &lv_font_MI_LanTing_Regular_12);
	lv_style_set_text_opa(&style_screen_work_msgbox_1_extra_content_main_default, 255);
	lv_style_set_text_letter_space(&style_screen_work_msgbox_1_extra_content_main_default, 0);
	lv_style_set_text_line_space(&style_screen_work_msgbox_1_extra_content_main_default, 10);
	lv_obj_add_style(lv_msgbox_get_text(ui->screen_work_msgbox_1), &style_screen_work_msgbox_1_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for &style_screen_work_msgbox_1_extra_btns_items_default
	static lv_style_t style_screen_work_msgbox_1_extra_btns_items_default;
	ui_init_style(&style_screen_work_msgbox_1_extra_btns_items_default);
	
	lv_style_set_bg_opa(&style_screen_work_msgbox_1_extra_btns_items_default, 255);
	lv_style_set_bg_color(&style_screen_work_msgbox_1_extra_btns_items_default, lv_color_hex(0xe6e6e6));
	lv_style_set_bg_grad_dir(&style_screen_work_msgbox_1_extra_btns_items_default, LV_GRAD_DIR_NONE);
	lv_style_set_border_width(&style_screen_work_msgbox_1_extra_btns_items_default, 0);
	lv_style_set_radius(&style_screen_work_msgbox_1_extra_btns_items_default, 10);
	lv_style_set_text_color(&style_screen_work_msgbox_1_extra_btns_items_default, lv_color_hex(0x4e4e4e));
	lv_style_set_text_font(&style_screen_work_msgbox_1_extra_btns_items_default, &lv_font_MI_LanTing_Regular_12);
	lv_style_set_text_opa(&style_screen_work_msgbox_1_extra_btns_items_default, 255);
	lv_obj_add_style(lv_msgbox_get_btns(ui->screen_work_msgbox_1), &style_screen_work_msgbox_1_extra_btns_items_default, LV_PART_ITEMS|LV_STATE_DEFAULT);

	//The custom code of screen_work.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_work);

	//Init events for screen.
	events_init_screen_work(ui);
}
