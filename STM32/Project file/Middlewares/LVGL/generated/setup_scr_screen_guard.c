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

void setup_scr_screen_guard(lv_ui *ui)
{
	//Write codes screen_guard
	ui->screen_guard = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen_guard, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_guard, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_guard, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_guard, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_guard_cont_1
	ui->screen_guard_cont_1 = lv_obj_create(ui->screen_guard);
	lv_obj_set_pos(ui->screen_guard_cont_1, 0, 0);
	lv_obj_set_size(ui->screen_guard_cont_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen_guard_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen_guard_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->screen_guard_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_guard_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_guard_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_guard_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_guard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_guard_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_guard_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_guard_cont_1, LV_GRAD_DIR_HOR, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->screen_guard_cont_1, lv_color_hex(0x00FFFC), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_main_stop(ui->screen_guard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_stop(ui->screen_guard_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_guard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_guard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_guard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_guard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_guard_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_guard_spinner_1
	ui->screen_guard_spinner_1 = lv_spinner_create(ui->screen_guard_cont_1, 1000, 60);
	lv_obj_set_pos(ui->screen_guard_spinner_1, 89, 21);
	lv_obj_set_size(ui->screen_guard_spinner_1, 142, 139);

	//Write style for screen_guard_spinner_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_pad_top(ui->screen_guard_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->screen_guard_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_guard_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_guard_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_guard_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->screen_guard_spinner_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_guard_spinner_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_guard_spinner_1, lv_color_hex(0x727272), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_guard_spinner_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_guard_spinner_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_arc_width(ui->screen_guard_spinner_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_opa(ui->screen_guard_spinner_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->screen_guard_spinner_1, lv_color_hex(0xffffff), LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_guard_btn_1
	ui->screen_guard_btn_1 = lv_btn_create(ui->screen_guard_cont_1);
	ui->screen_guard_btn_1_label = lv_label_create(ui->screen_guard_btn_1);
	lv_label_set_text(ui->screen_guard_btn_1_label, "退出守护模式");
	lv_label_set_long_mode(ui->screen_guard_btn_1_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->screen_guard_btn_1_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->screen_guard_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->screen_guard_btn_1_label, LV_PCT(100));
	lv_obj_set_pos(ui->screen_guard_btn_1, 80, 170);
	lv_obj_set_size(ui->screen_guard_btn_1, 160, 40);

	//Write style for screen_guard_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_guard_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_guard_btn_1, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_guard_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_guard_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_guard_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_guard_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->screen_guard_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_guard_btn_1, &lv_font_MI_LanTing_Regular_24, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_guard_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_guard_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_guard_img_1
	ui->screen_guard_img_1 = lv_img_create(ui->screen_guard_cont_1);
	lv_obj_add_flag(ui->screen_guard_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_guard_img_1, &_img_alpha_90x100);
	lv_img_set_pivot(ui->screen_guard_img_1, 50,50);
	lv_img_set_angle(ui->screen_guard_img_1, 0);
	lv_obj_set_pos(ui->screen_guard_img_1, 115, 43);
	lv_obj_set_size(ui->screen_guard_img_1, 90, 100);

	//Write style for screen_guard_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_guard_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of screen_guard.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen_guard);

	//Init events for screen.
	events_init_screen_guard(ui);
}
