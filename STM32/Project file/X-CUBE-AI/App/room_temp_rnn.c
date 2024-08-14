/**
  ******************************************************************************
  * @file    room_temp_rnn.c
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


#include "room_temp_rnn.h"
#include "room_temp_rnn_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_room_temp_rnn
 
#undef AI_ROOM_TEMP_RNN_MODEL_SIGNATURE
#define AI_ROOM_TEMP_RNN_MODEL_SIGNATURE     "0x9eaed36d91fc18ad9387a660c1d21d58"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Sun Jun  9 21:56:41 2024"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_ROOM_TEMP_RNN_N_BATCHES
#define AI_ROOM_TEMP_RNN_N_BATCHES         (1)

static ai_ptr g_room_temp_rnn_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_room_temp_rnn_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_x0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 6, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  lstm_0_output0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 360, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  slice_1_gather_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 60, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  slice_1_gather_0_placeholder_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  lstm_0_kernel_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  lstm_0_recurrent_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14400, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  lstm_0_peephole_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 180, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  lstm_0_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 240, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 60, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  gemm_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  lstm_0_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 420, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_weights, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 60, 1, 1, 1), AI_STRIDE_INIT(4, 4, 240, 240, 240),
  1, &gemm_2_weights_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_bias, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &gemm_2_bias_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_x0_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 6), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &serving_default_x0_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  lstm_0_output0, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 60, 1, 6), AI_STRIDE_INIT(4, 4, 4, 240, 240),
  1, &lstm_0_output0_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  lstm_0_scratch0, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 420, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1680, 1680),
  1, &lstm_0_scratch0_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  slice_1_gather_0_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 60, 1, 1), AI_STRIDE_INIT(4, 4, 4, 240, 240),
  1, &slice_1_gather_0_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  gemm_2_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &gemm_2_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  slice_1_gather_0_placeholder, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &slice_1_gather_0_placeholder_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  lstm_0_kernel, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 240, 1, 1), AI_STRIDE_INIT(4, 4, 4, 960, 960),
  1, &lstm_0_kernel_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  lstm_0_recurrent, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 60, 240, 1, 1), AI_STRIDE_INIT(4, 4, 240, 57600, 57600),
  1, &lstm_0_recurrent_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  lstm_0_peephole, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 180, 1, 1), AI_STRIDE_INIT(4, 4, 4, 720, 720),
  1, &lstm_0_peephole_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  lstm_0_bias, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 240, 1, 1), AI_STRIDE_INIT(4, 4, 4, 960, 960),
  1, &lstm_0_bias_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_1_gather_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_2_weights, &gemm_2_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  gemm_2_layer, 2,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &gemm_2_chain,
  NULL, &gemm_2_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_1_gather_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &lstm_0_output0, &slice_1_gather_0_placeholder),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_1_gather_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_1_gather_0_layer, 1,
  GATHER_TYPE, 0x0, NULL,
  gather, forward_gather,
  &slice_1_gather_0_chain,
  NULL, &gemm_2_layer, AI_STATIC, 
  .axis = AI_SHAPE_HEIGHT, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  lstm_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_x0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &lstm_0_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 9, &lstm_0_kernel, &lstm_0_recurrent, &lstm_0_peephole, &lstm_0_bias, NULL, NULL, NULL, NULL, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &lstm_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  lstm_0_layer, 0,
  LSTM_TYPE, 0x0, NULL,
  lstm, forward_lstm,
  &lstm_0_chain,
  NULL, &slice_1_gather_0_layer, AI_STATIC, 
  .n_units = 60, 
  .activation_nl = nl_func_tanh_array_f32, 
  .go_backwards = false, 
  .reverse_seq = false, 
  .return_state = false, 
  .out_nl = nl_func_tanh_array_f32, 
  .recurrent_nl = nl_func_sigmoid_array_f32, 
  .cell_clip = 10.0, 
  .state = AI_HANDLE_PTR(NULL), 
  .init = AI_LAYER_FUNC(NULL), 
  .destroy = AI_LAYER_FUNC(NULL), 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 60488, 1, 1),
    60488, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3144, 1, 1),
    3144, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_ROOM_TEMP_RNN_IN_NUM, &serving_default_x0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_ROOM_TEMP_RNN_OUT_NUM, &gemm_2_output),
  &lstm_0_layer, 0x5c1482b8, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 60488, 1, 1),
      60488, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 3144, 1, 1),
      3144, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_ROOM_TEMP_RNN_IN_NUM, &serving_default_x0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_ROOM_TEMP_RNN_OUT_NUM, &gemm_2_output),
  &lstm_0_layer, 0x5c1482b8, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool room_temp_rnn_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_room_temp_rnn_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_x0_output_array.data = AI_PTR(g_room_temp_rnn_activations_map[0] + 0);
    serving_default_x0_output_array.data_start = AI_PTR(g_room_temp_rnn_activations_map[0] + 0);
    lstm_0_scratch0_array.data = AI_PTR(g_room_temp_rnn_activations_map[0] + 24);
    lstm_0_scratch0_array.data_start = AI_PTR(g_room_temp_rnn_activations_map[0] + 24);
    lstm_0_output0_array.data = AI_PTR(g_room_temp_rnn_activations_map[0] + 1704);
    lstm_0_output0_array.data_start = AI_PTR(g_room_temp_rnn_activations_map[0] + 1704);
    slice_1_gather_0_output_array.data = AI_PTR(g_room_temp_rnn_activations_map[0] + 0);
    slice_1_gather_0_output_array.data_start = AI_PTR(g_room_temp_rnn_activations_map[0] + 0);
    gemm_2_output_array.data = AI_PTR(g_room_temp_rnn_activations_map[0] + 240);
    gemm_2_output_array.data_start = AI_PTR(g_room_temp_rnn_activations_map[0] + 240);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool room_temp_rnn_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_room_temp_rnn_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    slice_1_gather_0_placeholder_array.format |= AI_FMT_FLAG_CONST;
    slice_1_gather_0_placeholder_array.data = AI_PTR(g_room_temp_rnn_weights_map[0] + 0);
    slice_1_gather_0_placeholder_array.data_start = AI_PTR(g_room_temp_rnn_weights_map[0] + 0);
    lstm_0_kernel_array.format |= AI_FMT_FLAG_CONST;
    lstm_0_kernel_array.data = AI_PTR(g_room_temp_rnn_weights_map[0] + 4);
    lstm_0_kernel_array.data_start = AI_PTR(g_room_temp_rnn_weights_map[0] + 4);
    lstm_0_recurrent_array.format |= AI_FMT_FLAG_CONST;
    lstm_0_recurrent_array.data = AI_PTR(g_room_temp_rnn_weights_map[0] + 964);
    lstm_0_recurrent_array.data_start = AI_PTR(g_room_temp_rnn_weights_map[0] + 964);
    lstm_0_peephole_array.format |= AI_FMT_FLAG_CONST;
    lstm_0_peephole_array.data = AI_PTR(g_room_temp_rnn_weights_map[0] + 58564);
    lstm_0_peephole_array.data_start = AI_PTR(g_room_temp_rnn_weights_map[0] + 58564);
    lstm_0_bias_array.format |= AI_FMT_FLAG_CONST;
    lstm_0_bias_array.data = AI_PTR(g_room_temp_rnn_weights_map[0] + 59284);
    lstm_0_bias_array.data_start = AI_PTR(g_room_temp_rnn_weights_map[0] + 59284);
    gemm_2_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_2_weights_array.data = AI_PTR(g_room_temp_rnn_weights_map[0] + 60244);
    gemm_2_weights_array.data_start = AI_PTR(g_room_temp_rnn_weights_map[0] + 60244);
    gemm_2_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_2_bias_array.data = AI_PTR(g_room_temp_rnn_weights_map[0] + 60484);
    gemm_2_bias_array.data_start = AI_PTR(g_room_temp_rnn_weights_map[0] + 60484);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_room_temp_rnn_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_ROOM_TEMP_RNN_MODEL_NAME,
      .model_signature   = AI_ROOM_TEMP_RNN_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 89701,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x5c1482b8,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_room_temp_rnn_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_ROOM_TEMP_RNN_MODEL_NAME,
      .model_signature   = AI_ROOM_TEMP_RNN_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 89701,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x5c1482b8,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_room_temp_rnn_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_room_temp_rnn_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_room_temp_rnn_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_room_temp_rnn_create(network, AI_ROOM_TEMP_RNN_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_room_temp_rnn_data_params_get(&params) != true) {
    err = ai_room_temp_rnn_get_error(*network);
    return err;
  }
#if defined(AI_ROOM_TEMP_RNN_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_ROOM_TEMP_RNN_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_room_temp_rnn_init(*network, &params) != true) {
    err = ai_room_temp_rnn_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_room_temp_rnn_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_room_temp_rnn_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_room_temp_rnn_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_room_temp_rnn_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= room_temp_rnn_configure_weights(net_ctx, params);
  ok &= room_temp_rnn_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_room_temp_rnn_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_room_temp_rnn_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_ROOM_TEMP_RNN_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

