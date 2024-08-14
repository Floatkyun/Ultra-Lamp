/**
  ******************************************************************************
  * @file    room_state_fcn_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Jun  9 21:56:46 2024
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef ROOM_STATE_FCN_DATA_PARAMS_H
#define ROOM_STATE_FCN_DATA_PARAMS_H

#include "ai_platform.h"

/*
#define AI_ROOM_STATE_FCN_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_room_state_fcn_data_weights_params[1]))
*/

#define AI_ROOM_STATE_FCN_DATA_CONFIG               (NULL)


#define AI_ROOM_STATE_FCN_DATA_ACTIVATIONS_SIZES \
  { 384, }
#define AI_ROOM_STATE_FCN_DATA_ACTIVATIONS_SIZE     (384)
#define AI_ROOM_STATE_FCN_DATA_ACTIVATIONS_COUNT    (1)
#define AI_ROOM_STATE_FCN_DATA_ACTIVATION_1_SIZE    (384)



#define AI_ROOM_STATE_FCN_DATA_WEIGHTS_SIZES \
  { 13384, }
#define AI_ROOM_STATE_FCN_DATA_WEIGHTS_SIZE         (13384)
#define AI_ROOM_STATE_FCN_DATA_WEIGHTS_COUNT        (1)
#define AI_ROOM_STATE_FCN_DATA_WEIGHT_1_SIZE        (13384)



#define AI_ROOM_STATE_FCN_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_room_state_fcn_activations_table[1])

extern ai_handle g_room_state_fcn_activations_table[1 + 2];



#define AI_ROOM_STATE_FCN_DATA_WEIGHTS_TABLE_GET() \
  (&g_room_state_fcn_weights_table[1])

extern ai_handle g_room_state_fcn_weights_table[1 + 2];


#endif    /* ROOM_STATE_FCN_DATA_PARAMS_H */
