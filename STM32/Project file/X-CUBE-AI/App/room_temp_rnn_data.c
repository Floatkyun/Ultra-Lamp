/**
  ******************************************************************************
  * @file    room_temp_rnn_data.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Sun Jun  9 21:56:41 2024
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */
#include "room_temp_rnn_data.h"
#include "ai_platform_interface.h"

AI_API_DECLARE_BEGIN
ai_buffer g_room_temp_rnn_data_map_activations[AI_ROOM_TEMP_RNN_DATA_ACTIVATIONS_COUNT] = {
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3144, 1, 1),
    3144, NULL, NULL),    /* heap_overlay_pool */
  };
ai_buffer g_room_temp_rnn_data_map_weights[AI_ROOM_TEMP_RNN_DATA_WEIGHTS_COUNT] = {
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 60488, 1, 1),
    60488, NULL, s_room_temp_rnn_weights_array_u64),   /* weights_array */
  };


/*!
 * @brief Get network activations buffer initialized struct.
 * @ingroup room_temp_rnn_data
 * @param[in] ptr a pointer to the activations array storage area
 * @return an ai_buffer initialized struct
 */
AI_DEPRECATED
AI_API_ENTRY
ai_buffer ai_room_temp_rnn_data_activations_buffer_get(const ai_handle ptr)
{
  ai_buffer buf = AI_BUFFER_INIT(
    AI_FLAG_NONE, AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, AI_ROOM_TEMP_RNN_DATA_ACTIVATIONS_SIZE, 1, AI_ROOM_TEMP_RNN_DATA_ACTIVATIONS_COUNT),
    AI_ROOM_TEMP_RNN_DATA_ACTIVATIONS_SIZE,
    NULL, ptr);
  return buf;
}

/*!
 * @brief Get network weights buffer initialized struct.
 * @ingroup room_temp_rnn_data
 * @param[in] ptr a pointer to the weights array storage area
 * @return an ai_buffer initialized struct
 */
AI_DEPRECATED
AI_API_ENTRY
ai_buffer ai_room_temp_rnn_data_weights_buffer_get(const ai_handle ptr)
{
  ai_buffer buf = AI_BUFFER_INIT(
    AI_FLAG_NONE, AI_BUFFER_FORMAT_U8|AI_BUFFER_FMT_FLAG_CONST,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, AI_ROOM_TEMP_RNN_DATA_WEIGHTS_SIZE, 1, AI_ROOM_TEMP_RNN_DATA_WEIGHTS_COUNT),
    AI_ROOM_TEMP_RNN_DATA_WEIGHTS_SIZE,
    NULL, ptr);
  return buf;
}


/*!
 * @brief Get network weights array pointer as a handle ptr.
 * @ingroup room_temp_rnn_data
 * @return a ai_handle pointer to the weights array
 */
AI_DEPRECATED
AI_API_ENTRY
ai_handle ai_room_temp_rnn_data_weights_get(void)
{
  return AI_HANDLE_PTR(g_room_temp_rnn_weights_table);

}


/*!
 * @brief Get network params configuration data structure.
 * @ingroup room_temp_rnn_data
 * @return true if a valid configuration is present, false otherwise
 */
AI_API_ENTRY
ai_bool ai_room_temp_rnn_data_params_get(ai_network_params* params)
{
  if (!params) return false;
  
  const ai_buffer_array map_activations = 
    AI_BUFFER_ARRAY_OBJ_INIT(AI_FLAG_NONE, AI_ROOM_TEMP_RNN_DATA_ACTIVATIONS_COUNT, g_room_temp_rnn_data_map_activations);
  
  const ai_buffer_array map_weights = 
    AI_BUFFER_ARRAY_OBJ_INIT(AI_FLAG_NONE, AI_ROOM_TEMP_RNN_DATA_WEIGHTS_COUNT, g_room_temp_rnn_data_map_weights);

  return ai_platform_bind_network_params(params, &map_weights, &map_activations);
}


AI_API_DECLARE_END
