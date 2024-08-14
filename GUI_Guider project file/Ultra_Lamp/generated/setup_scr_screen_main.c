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



int screen_main_digital_clock_min_value = 9;
int screen_main_digital_clock_hour_value = 19;
int screen_main_digital_clock_sec_value = 41;
void setup_scr_screen_main(lv_ui *ui)
{
	//Write codes screen_main
	ui->screen_main = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_main, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_main, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_cont_main
	ui->screen_main_cont_main = lv_obj_create(ui->screen_main);
	lv_obj_set_pos(ui->screen_main_cont_main, 0, 0);
	lv_obj_set_size(ui->screen_main_cont_main, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_main_cont_main, LV_SCROLLBAR_MODE_AUTO);

	//Write style for screen_main_cont_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_main_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_cont_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_cont_main, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_cont_main, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_main_cont_main, lv_color_hex(0x00FFFC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_main_cont_main, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_main_cont_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_cont_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_btn_guard_mode
	ui->screen_main_btn_guard_mode = lv_btn_create(ui->screen_main_cont_main);
	ui->screen_main_btn_guard_mode_label = lv_label_create(ui->screen_main_btn_guard_mode);
	lv_label_set_text(ui->screen_main_btn_guard_mode_label, "守护模式");
	lv_label_set_long_mode(ui->screen_main_btn_guard_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_main_btn_guard_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_main_btn_guard_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_main_btn_guard_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_main_btn_guard_mode, 86, 93);
	lv_obj_set_size(ui->screen_main_btn_guard_mode, 82, 37);

	//Write style for screen_main_btn_guard_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main_btn_guard_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_main_btn_guard_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_btn_guard_mode, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_btn_guard_mode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_main_btn_guard_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_main_btn_guard_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_main_btn_guard_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_main_btn_guard_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_main_btn_guard_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_btn_guard_mode, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_btn_guard_mode, &lv_font_MI_LanTing_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_btn_guard_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_btn_guard_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_btn_desk_mode
	ui->screen_main_btn_desk_mode = lv_btn_create(ui->screen_main_cont_main);
	ui->screen_main_btn_desk_mode_label = lv_label_create(ui->screen_main_btn_desk_mode);
	lv_label_set_text(ui->screen_main_btn_desk_mode_label, "桌面模式");
	lv_label_set_long_mode(ui->screen_main_btn_desk_mode_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_main_btn_desk_mode_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_main_btn_desk_mode, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_main_btn_desk_mode_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_main_btn_desk_mode, 182, 93);
	lv_obj_set_size(ui->screen_main_btn_desk_mode, 75, 35);

	//Write style for screen_main_btn_desk_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main_btn_desk_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_main_btn_desk_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_btn_desk_mode, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_btn_desk_mode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_main_btn_desk_mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_main_btn_desk_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_main_btn_desk_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_main_btn_desk_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_main_btn_desk_mode, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_btn_desk_mode, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_btn_desk_mode, &lv_font_MI_LanTing_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_btn_desk_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_btn_desk_mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_slider_led_Light
	ui->screen_main_slider_led_Light = lv_slider_create(ui->screen_main_cont_main);
	lv_slider_set_range(ui->screen_main_slider_led_Light, 0, 100);
	lv_slider_set_mode(ui->screen_main_slider_led_Light, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->screen_main_slider_led_Light, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_main_slider_led_Light, 15, 60);
	lv_obj_set_size(ui->screen_main_slider_led_Light, 20, 165);

	//Write style for screen_main_slider_led_Light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main_slider_led_Light, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_slider_led_Light, lv_color_hex(0x34ffa4), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_slider_led_Light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_slider_led_Light, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->screen_main_slider_led_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_slider_led_Light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_main_slider_led_Light, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main_slider_led_Light, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_slider_led_Light, lv_color_hex(0x34ff98), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_slider_led_Light, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_slider_led_Light, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for screen_main_slider_led_Light, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main_slider_led_Light, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_slider_led_Light, lv_color_hex(0x00ed5c), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_slider_led_Light, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_slider_led_Light, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes screen_main_label_led_light
	ui->screen_main_label_led_light = lv_label_create(ui->screen_main_cont_main);
	lv_label_set_text(ui->screen_main_label_led_light, "台灯亮度");
	lv_label_set_long_mode(ui->screen_main_label_led_light, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_main_label_led_light, 10, 20);
	lv_obj_set_size(ui->screen_main_label_led_light, 30, 30);

	//Write style for screen_main_label_led_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_main_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_label_led_light, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_label_led_light, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_label_led_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_main_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_main_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_label_led_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_label_led_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_label_led_light, lv_color_hex(0x34ffa4), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_label_led_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_label_led_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_label_temp_Pre_1
	ui->screen_main_label_temp_Pre_1 = lv_label_create(ui->screen_main_cont_main);
	lv_label_set_text(ui->screen_main_label_temp_Pre_1, "温度预测");
	lv_label_set_long_mode(ui->screen_main_label_temp_Pre_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_main_label_temp_Pre_1, 66, 194);
	lv_obj_set_size(ui->screen_main_label_temp_Pre_1, 30, 30);

	//Write style for screen_main_label_temp_Pre_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_main_label_temp_Pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_label_temp_Pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_label_temp_Pre_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_label_temp_Pre_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_label_temp_Pre_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_main_label_temp_Pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_main_label_temp_Pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_label_temp_Pre_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_label_temp_Pre_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_label_temp_Pre_1, lv_color_hex(0x00ff93), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_label_temp_Pre_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_label_temp_Pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_label_temp_Pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_label_temp_Pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_label_temp_Pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_label_temp_Pre_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_label_envscore_1
	ui->screen_main_label_envscore_1 = lv_label_create(ui->screen_main_cont_main);
	lv_label_set_text(ui->screen_main_label_envscore_1, "环境评分");
	lv_label_set_long_mode(ui->screen_main_label_envscore_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_main_label_envscore_1, 177, 195);
	lv_obj_set_size(ui->screen_main_label_envscore_1, 30, 30);

	//Write style for screen_main_label_envscore_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_main_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_label_envscore_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_label_envscore_1, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_label_envscore_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_main_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_main_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_label_envscore_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_label_envscore_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_label_envscore_1, lv_color_hex(0x00ff93), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_label_envscore_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_label_envscore_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_label_envscore
	ui->screen_main_label_envscore = lv_label_create(ui->screen_main_cont_main);
	lv_label_set_text(ui->screen_main_label_envscore, "---");
	lv_label_set_long_mode(ui->screen_main_label_envscore, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_main_label_envscore, 217, 195);
	lv_obj_set_size(ui->screen_main_label_envscore, 55, 30);

	//Write style for screen_main_label_envscore, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_main_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_label_envscore, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_label_envscore, &lv_font_MI_LanTing_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_label_envscore, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_main_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_main_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_label_envscore, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_label_envscore, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_label_envscore, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_main_label_envscore, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_main_label_envscore, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_main_label_envscore, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_main_label_envscore, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_main_label_envscore, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_label_temp_pre
	ui->screen_main_label_temp_pre = lv_label_create(ui->screen_main_cont_main);
	lv_label_set_text(ui->screen_main_label_temp_pre, "--");
	lv_label_set_long_mode(ui->screen_main_label_temp_pre, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_main_label_temp_pre, 106, 194);
	lv_obj_set_size(ui->screen_main_label_temp_pre, 36, 30);

	//Write style for screen_main_label_temp_pre, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_main_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_label_temp_pre, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_label_temp_pre, &lv_font_MI_LanTing_Regular_30, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_label_temp_pre, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_main_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_main_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_label_temp_pre, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_label_temp_pre, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_label_temp_pre, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_main_label_temp_pre, lv_color_hex(0x2195F6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_main_label_temp_pre, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_main_label_temp_pre, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_main_label_temp_pre, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_main_label_temp_pre, 3, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_cont_light_mode
	ui->screen_main_cont_light_mode = lv_obj_create(ui->screen_main_cont_main);
	lv_obj_set_pos(ui->screen_main_cont_light_mode, 82, 18);
	lv_obj_set_size(ui->screen_main_cont_light_mode, 180, 60);
	lv_obj_set_scrollbar_mode(ui->screen_main_cont_light_mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_main_cont_light_mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_main_cont_light_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_cont_light_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_cont_light_mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_cont_light_mode, lv_color_hex(0xe5f6fe), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_cont_light_mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_cont_light_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_cont_light_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_cont_light_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_cont_light_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_cont_light_mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_btn_handset_light
	ui->screen_main_btn_handset_light = lv_btn_create(ui->screen_main_cont_light_mode);
	ui->screen_main_btn_handset_light_label = lv_label_create(ui->screen_main_btn_handset_light);
	lv_label_set_text(ui->screen_main_btn_handset_light_label, "手动亮度");
	lv_label_set_long_mode(ui->screen_main_btn_handset_light_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_main_btn_handset_light_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_main_btn_handset_light, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_main_btn_handset_light_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_main_btn_handset_light, 10, 10);
	lv_obj_set_size(ui->screen_main_btn_handset_light, 75, 40);

	//Write style for screen_main_btn_handset_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main_btn_handset_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_btn_handset_light, lv_color_hex(0x00ffe0), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_btn_handset_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_main_btn_handset_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_btn_handset_light, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_btn_handset_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_btn_handset_light, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_btn_handset_light, &lv_font_MI_LanTing_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_btn_handset_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_btn_handset_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_btn_auto_light
	ui->screen_main_btn_auto_light = lv_btn_create(ui->screen_main_cont_light_mode);
	ui->screen_main_btn_auto_light_label = lv_label_create(ui->screen_main_btn_auto_light);
	lv_label_set_text(ui->screen_main_btn_auto_light_label, "自动亮度");
	lv_label_set_long_mode(ui->screen_main_btn_auto_light_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_main_btn_auto_light_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_main_btn_auto_light, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_main_btn_auto_light_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_main_btn_auto_light, 95, 10);
	lv_obj_set_size(ui->screen_main_btn_auto_light, 75, 40);

	//Write style for screen_main_btn_auto_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main_btn_auto_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_btn_auto_light, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_btn_auto_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_main_btn_auto_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_btn_auto_light, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_btn_auto_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_btn_auto_light, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_btn_auto_light, &lv_font_MI_LanTing_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_btn_auto_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_btn_auto_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_btn_chat
	ui->screen_main_btn_chat = lv_btn_create(ui->screen_main_cont_main);
	ui->screen_main_btn_chat_label = lv_label_create(ui->screen_main_btn_chat);
	lv_label_set_text(ui->screen_main_btn_chat_label, "开始说话");
	lv_label_set_long_mode(ui->screen_main_btn_chat_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_main_btn_chat_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_main_btn_chat, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_main_btn_chat_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_main_btn_chat, 132, 143);
	lv_obj_set_size(ui->screen_main_btn_chat, 82, 37);

	//Write style for screen_main_btn_chat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_main_btn_chat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_btn_chat, lv_color_hex(0x009ea9), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_btn_chat, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_main_btn_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_btn_chat, 25, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_btn_chat, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->screen_main_btn_chat, lv_color_hex(0x0d4b3b), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->screen_main_btn_chat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->screen_main_btn_chat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->screen_main_btn_chat, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->screen_main_btn_chat, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_btn_chat, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_btn_chat, &lv_font_MI_LanTing_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_btn_chat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_btn_chat, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_cont_top
	ui->screen_main_cont_top = lv_obj_create(ui->screen_main);
	lv_obj_set_pos(ui->screen_main_cont_top, 0, 0);
	lv_obj_set_size(ui->screen_main_cont_top, 320, 15);
	lv_obj_set_scrollbar_mode(ui->screen_main_cont_top, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_main_cont_top, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_main_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_cont_top, 78, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_main_cont_top, lv_color_hex(0x808080), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_main_cont_top, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_cont_top, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_label_wifi
	ui->screen_main_label_wifi = lv_label_create(ui->screen_main_cont_top);
	lv_label_set_text(ui->screen_main_label_wifi, "" LV_SYMBOL_HOME " " LV_SYMBOL_WIFI "");
	lv_label_set_long_mode(ui->screen_main_label_wifi, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->screen_main_label_wifi, 280, 0);
	lv_obj_set_size(ui->screen_main_label_wifi, 40, 15);

	//Write style for screen_main_label_wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_label_wifi, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_label_wifi, &lv_font_MI_LanTing_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_label_wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_label_wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_label_wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_main_digital_clock
	static bool screen_main_digital_clock_timer_enabled = false;
	ui->screen_main_digital_clock = lv_dclock_create(ui->screen_main_cont_top, "19:09:41");
	if (!screen_main_digital_clock_timer_enabled) {
		lv_timer_create(screen_main_digital_clock_timer, 1000, NULL);
		screen_main_digital_clock_timer_enabled = true;
	}
	lv_obj_set_pos(ui->screen_main_digital_clock, 0, 0);
	lv_obj_set_size(ui->screen_main_digital_clock, 65, 15);

	//Write style for screen_main_digital_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_radius(ui->screen_main_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_main_digital_clock, lv_color_hex(0x191717), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_main_digital_clock, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_main_digital_clock, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_main_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_main_digital_clock, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_main_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_main_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_main_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_main_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_main_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_main_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_main.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_main);

	//Init events for screen.
	events_init_screen_main(ui);
}
