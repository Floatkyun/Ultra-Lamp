/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen_main;
	bool screen_main_del;
	lv_obj_t *screen_main_cont_main;
	lv_obj_t *screen_main_btn_guard_mode;
	lv_obj_t *screen_main_btn_guard_mode_label;
	lv_obj_t *screen_main_btn_desk_mode;
	lv_obj_t *screen_main_btn_desk_mode_label;
	lv_obj_t *screen_main_slider_led_Light;
	lv_obj_t *screen_main_label_led_light;
	lv_obj_t *screen_main_label_temp_Pre_1;
	lv_obj_t *screen_main_label_envscore_1;
	lv_obj_t *screen_main_label_envscore;
	lv_obj_t *screen_main_label_temp_pre;
	lv_obj_t *screen_main_cont_light_mode;
	lv_obj_t *screen_main_btn_handset_light;
	lv_obj_t *screen_main_btn_handset_light_label;
	lv_obj_t *screen_main_btn_auto_light;
	lv_obj_t *screen_main_btn_auto_light_label;
	lv_obj_t *screen_main_btn_chat;
	lv_obj_t *screen_main_btn_chat_label;
	lv_obj_t *screen_main_cont_top;
	lv_obj_t *screen_main_label_wifi;
	lv_obj_t *screen_main_digital_clock;
	lv_obj_t *screen_work_setting;
	bool screen_work_setting_del;
	lv_obj_t *screen_work_setting_cont_main;
	lv_obj_t *screen_work_setting_btn_work_begin;
	lv_obj_t *screen_work_setting_btn_work_begin_label;
	lv_obj_t *screen_work_setting_btn_work_cancel;
	lv_obj_t *screen_work_setting_btn_work_cancel_label;
	lv_obj_t *screen_work_setting_cont_top;
	lv_obj_t *screen_work_setting_label_wifi;
	lv_obj_t *screen_work_setting_digital_clock;
	lv_obj_t *screen_work_setting_label_work_time_choose_1;
	lv_obj_t *screen_work_setting_label_game_time_choose_1;
	lv_obj_t *screen_work_setting_label_turn_time_choose_1;
	lv_obj_t *screen_work_setting_label_work_mode_choose_1;
	lv_obj_t *screen_work_setting_ddlist_work_mode;
	lv_obj_t *screen_work_setting_ddlist_turn_time;
	lv_obj_t *screen_work_setting_ddlist_work_time;
	lv_obj_t *screen_work_setting_ddlist_game_time;
	lv_obj_t *screen_work;
	bool screen_work_del;
	lv_obj_t *screen_work_cont_main;
	lv_obj_t *screen_work_drink_bar;
	lv_obj_t *screen_work_game_bar;
	lv_obj_t *screen_work_work_bar;
	lv_obj_t *screen_work_label_work_bar_1;
	lv_obj_t *screen_work_label_game_bar_1;
	lv_obj_t *screen_work_label_drink_bar_1;
	lv_obj_t *screen_work_button_stop_work;
	lv_obj_t *screen_work_button_stop_work_label;
	lv_obj_t *screen_work_label_work_time_1;
	lv_obj_t *screen_work_label_game_time_1;
	lv_obj_t *screen_work_label_drink_time_1;
	lv_obj_t *screen_work_label_work_time;
	lv_obj_t *screen_work_label_paly_time;
	lv_obj_t *screen_work_label_drink_time;
	lv_obj_t *screen_work_label_work_time_2;
	lv_obj_t *screen_work_label_game_time_2;
	lv_obj_t *screen_work_label_drink_time_2;
	lv_obj_t *screen_work_slider_led_light;
	lv_obj_t *screen_work_label_led_light;
	lv_obj_t *screen_work_label_temp_pre_1;
	lv_obj_t *screen_work_label_temp_pre;
	lv_obj_t *screen_work_label_envscore_1;
	lv_obj_t *screen_work_label_envscore;
	lv_obj_t *screen_work_spinner;
	lv_obj_t *screen_work_btn_handset_light;
	lv_obj_t *screen_work_btn_handset_light_label;
	lv_obj_t *screen_work_btn_auto_light;
	lv_obj_t *screen_work_btn_auto_light_label;
	lv_obj_t *screen_work_label_work_bar;
	lv_obj_t *screen_work_label_work_bar_3;
	lv_obj_t *screen_work_label_drink_bar_3;
	lv_obj_t *screen_work_label_game_bar_3;
	lv_obj_t *screen_work_label_game_bar;
	lv_obj_t *screen_work_label_drink_bar;
	lv_obj_t *screen_work_cont_top;
	lv_obj_t *screen_work_label_wifi;
	lv_obj_t *screen_work_digital_clock;
	lv_obj_t *screen_work_msgbox_1;
	lv_obj_t *screen_guard;
	bool screen_guard_del;
	lv_obj_t *screen_guard_cont_1;
	lv_obj_t *screen_guard_spinner_1;
	lv_obj_t *screen_guard_btn_1;
	lv_obj_t *screen_guard_btn_1_label;
	lv_obj_t *screen_guard_img_1;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_screen_main(lv_ui *ui);
void setup_scr_screen_work_setting(lv_ui *ui);
void setup_scr_screen_work(lv_ui *ui);
void setup_scr_screen_guard(lv_ui *ui);
LV_IMG_DECLARE(_img_alpha_90x100);

LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_18)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_15)
LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_16)
LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_30)
LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_12)
LV_FONT_DECLARE(lv_font_montserratMedium_15)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_28)
LV_FONT_DECLARE(lv_font_MI_LanTing_Regular_24)


#ifdef __cplusplus
}
#endif
#endif
