/**
  ******************************************************************************
  * @file    stai_network_fan_ae.h
  * @author  AST Embedded Analytics Research Platform
  * @brief   Definitions of ST.AI platform public APIs types
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#ifndef STAI_NETWORK_FAN_AE_H
#define STAI_NETWORK_FAN_AE_H

#include "stai.h"
#include "stai_debug.h"

/*****************************************************************************/
/*****************************************************************************/
#define STAI_NETWORK_FAN_AE_MODEL_NAME          "network_fan_ae"
#define STAI_NETWORK_FAN_AE_ORIGIN_MODEL_NAME   "q2c_unit_tests_fan_ae"

/*****************************************************************************/
#define STAI_NETWORK_FAN_AE_CONTEXT_SIZE        ((stai_size)sizeof(_stai_network_fan_ae_context))
#define STAI_NETWORK_FAN_AE_CONTEXT_ALIGNMENT   (8)

#ifdef STAI_NETWORK_MINIMAL
#define STAI_NETWORK_FAN_AE_FLAGS               (STAI_FLAG_ACTIVATIONS|STAI_FLAG_INPUTS|STAI_FLAG_OUTPUTS|\
                                                 STAI_FLAG_WEIGHTS|STAI_FLAG_PREALLOCATED)
#define STAI_NETWORK_FAN_AE_IO_FLAGS            (STAI_FLAG_CHANNEL_LAST|STAI_FLAG_PREALLOCATED|STAI_FLAG_OVERRIDE)
#else
#define STAI_NETWORK_FAN_AE_FLAGS               (STAI_FLAG_WEIGHTS)
#define STAI_NETWORK_FAN_AE_IO_FLAGS            (STAI_FLAG_CHANNEL_LAST)
#endif


#define STAI_NETWORK_FAN_AE_IN_NUM              (2)
#define STAI_NETWORK_FAN_AE_IN_ALIGNMENTS \
  { 4, 4 }
#define STAI_NETWORK_FAN_AE_IN_NAMES \
  { NULL, NULL }
#define STAI_NETWORK_FAN_AE_IN_FORMATS \
  { FORMAT_FLOAT, FORMAT_FLOAT }
#define STAI_NETWORK_FAN_AE_IN_SIZES \
  { 32, 32 }
#define STAI_NETWORK_FAN_AE_IN_SIZES_BYTES \
  { 128, 128 }

#define STAI_NETWORK_FAN_AE_IN_1_ALIGNMENT   (4)
#define STAI_NETWORK_FAN_AE_IN_1_NAME        (NULL)
#define STAI_NETWORK_FAN_AE_IN_1_FLAGS       (STAI_NETWORK_FAN_AE_IO_FLAGS)
#define STAI_NETWORK_FAN_AE_IN_1_FORMAT      STAI_FORMAT_FLOAT32
#define STAI_NETWORK_FAN_AE_IN_1_CHANNEL     (32)
#define STAI_NETWORK_FAN_AE_IN_1_SIZE        (32)
#define STAI_NETWORK_FAN_AE_IN_1_SIZE_BYTES  (128)

#define STAI_NETWORK_FAN_AE_IN_2_ALIGNMENT   (4)
#define STAI_NETWORK_FAN_AE_IN_2_NAME        (NULL)
#define STAI_NETWORK_FAN_AE_IN_2_FLAGS       (STAI_NETWORK_FAN_AE_IO_FLAGS)
#define STAI_NETWORK_FAN_AE_IN_2_FORMAT      STAI_FORMAT_FLOAT32
#define STAI_NETWORK_FAN_AE_IN_2_CHANNEL     (32)
#define STAI_NETWORK_FAN_AE_IN_2_SIZE        (32)
#define STAI_NETWORK_FAN_AE_IN_2_SIZE_BYTES  (128)

/*****************************************************************************/
#define STAI_NETWORK_FAN_AE_OUT_NUM          (2)
#define STAI_NETWORK_FAN_AE_OUT_ALIGNMENTS \
  { 4, 4 }
#define STAI_NETWORK_FAN_AE_OUT_NAMES \
  { NULL, NULL }
#define STAI_NETWORK_FAN_AE_OUT_FORMATS \
  { STAI_FORMAT_FLOAT32, STAI_FORMAT_FLOAT32 }
#define STAI_NETWORK_FAN_AE_OUT_SIZES \
  { 32, 32 }
#define STAI_NETWORK_FAN_AE_OUT_SIZES_BYTES \
  { 128, 128 }

#define STAI_NETWORK_FAN_AE_OUT_1_ALIGNMENT   (4)
#define STAI_NETWORK_FAN_AE_OUT_1_NAME        (NULL)
#define STAI_NETWORK_FAN_AE_OUT_1_FLAGS       (STAI_NETWORK_FAN_AE_IO_FLAGS)
#define STAI_NETWORK_FAN_AE_OUT_1_FORMAT      STAI_FORMAT_FLOAT32
#define STAI_NETWORK_FAN_AE_OUT_1_CHANNEL     (32)
#define STAI_NETWORK_FAN_AE_OUT_1_SIZE        (32)
#define STAI_NETWORK_FAN_AE_OUT_1_SIZE_BYTES  (128)

#define STAI_NETWORK_FAN_AE_OUT_2_ALIGNMENT   (4)
#define STAI_NETWORK_FAN_AE_OUT_2_NAME        (NULL)
#define STAI_NETWORK_FAN_AE_OUT_2_FLAGS       (STAI_NETWORK_FAN_AE_IO_FLAGS)
#define STAI_NETWORK_FAN_AE_OUT_2_FORMAT      STAI_FORMAT_FLOAT32
#define STAI_NETWORK_FAN_AE_OUT_2_CHANNEL     (32)
#define STAI_NETWORK_FAN_AE_OUT_2_SIZE        (32)
#define STAI_NETWORK_FAN_AE_OUT_2_SIZE_BYTES  (128)


/*****************************************************************************/
#define STAI_NETWORK_FAN_AE_ACTIVATIONS_SIZE        (400)
#define STAI_NETWORK_FAN_AE_ACTIVATIONS_ALIGNMENTS \
  { 4 }
#define STAI_NETWORK_FAN_AE_ACTIVATIONS_SIZES \
  { 400 }
#define STAI_NETWORK_FAN_AE_ACTIVATIONS_NUM         (1)
#define STAI_NETWORK_FAN_AE_ACTIVATION_1_ALIGNMENT  (4)
#define STAI_NETWORK_FAN_AE_ACTIVATION_1_SIZE       (400)

#define STAI_NETWORK_FAN_AE_WEIGHTS_SIZE            (5888)
#define STAI_NETWORK_FAN_AE_WEIGHTS_ALIGNMENTS \
  { 4 }
#define STAI_NETWORK_FAN_AE_WEIGHTS_SIZES \
  { 5888 }
#define STAI_NETWORK_FAN_AE_WEIGHTS_NUM             (1)
#define STAI_NETWORK_FAN_AE_WEIGHT_1_ALIGNMENT      (4)
#define STAI_NETWORK_FAN_AE_WEIGHT_1_SIZE           (5888)

/*****************************************************************************/
#define STAI_NETWORK_FAN_AE_STATES_NUM              (0)
#define STAI_NETWORK_FAN_AE_STATES_SIZE             (0)

/*****************************************************************************/
STAI_API_DECLARE_BEGIN

/*****************************************************************************/
/** Private context: DO NOT EDIT NOR access directly                        **/
/*****************************************************************************/
typedef struct {
  uint32_t                     _magic;
  uint32_t                     _signature;
  stai_flags                   _flags;
  stai_return_code             _return_code;
  stai_inspect_cb              _callback;
  const void*                  _callback_cookie;

  stai_ptr                     _activations[STAI_NETWORK_FAN_AE_ACTIVATIONS_NUM];
  stai_ptr                     _weights[STAI_NETWORK_FAN_AE_WEIGHTS_NUM];
  stai_ptr                     _inputs[STAI_NETWORK_FAN_AE_IN_NUM];
  stai_ptr                     _outputs[STAI_NETWORK_FAN_AE_OUT_NUM];
} _stai_network_fan_ae_context;


/*****************************************************************************/
/*  Network management APIs  */
STAI_API_ENTRY
stai_return_code stai_network_fan_ae_init(
  stai_network* network);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_deinit(
  stai_network* network);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_run(
  stai_network* network,
  const stai_run_mode mode);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_train(
  stai_network* network,
  const stai_run_mode mode);


/*****************************************************************************/
/*  Getters APIs  */

// needed only for python bindings to query internal context byte size
STAI_API_ENTRY
stai_size stai_network_fan_ae_get_context_size(void);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_get_info(
  stai_network* network,
  stai_network_info* info);


/* Activations, weights, I/O buffers pointers are now passed by copy */
STAI_API_ENTRY
stai_return_code stai_network_fan_ae_get_activations(
  stai_network* network,
  stai_ptr* activations,
  stai_size* n_activations);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_get_weights(
  stai_network* network,
  stai_ptr* weights,
  stai_size* n_weights);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_get_inputs(
  stai_network* network,
  stai_ptr* inputs,
  stai_size* n_inputs);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_get_outputs(
  stai_network* network,
  stai_ptr* outputs,
  stai_size* n_outputs);

STAI_API_ENTRY
stai_return_code stai_network_fan_ae_get_states(
  stai_network* network,
  stai_ptr* states,
  stai_size* n_states);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_get_error(
  stai_network* network);


/*****************************************************************************/
/*  Setters APIS  */
STAI_API_ENTRY
stai_return_code stai_network_fan_ae_set_inputs(
  stai_network* network,
  const stai_ptr* inputs,
  const stai_size n_inputs);

STAI_API_ENTRY
stai_return_code stai_network_fan_ae_set_outputs(
  stai_network* network,
  const stai_ptr* outputs,
  const stai_size n_outputs);

STAI_API_ENTRY
stai_return_code stai_network_fan_ae_set_activations(
  stai_network* network,
  const stai_ptr* activations,
  const stai_size n_activations);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_set_weights(
  stai_network* network,
  const stai_ptr* weights,
  const stai_size n_weights);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_set_states(
  stai_network* network,
  const stai_ptr* states,
  const stai_size n_states);


STAI_API_ENTRY
stai_return_code stai_network_fan_ae_set_callback(
  stai_network* network,
  const stai_inspect_cb cb,
  const void* cb_cookie);


/***************************************************************************/
/**  Extended Target Specific APIs  **/


/*** Asynchronous Execution ***/
/**
 * @brief continue network execution of an asynchronously started/run network (i.e. network was started/run in `stai_run_mode::MODE_ASYNC` mode)
 * @details Running a network in asynchronous mode (see function `stai_network_fan_ae_run()` and its parameter `mode` being equal to `stai_run_mode::MODE_ASYNC`)
 *          means that `stai_network_fan_ae_run()` returns while the network is still in execution. In this case the user may not call 
 *          `stai_network_fan_ae_run()` again until the network's execution has actually finish.
 *          Therefore, we need to have two new API functions, one that provides the execution status of the currently running network (`get_nn_execution_status()`),
 *          and one which triggers the continuation of the network execution (`continue_nn_execution()`).
 * @details While the asynchronously started network is in execution the user may call any application specific code. 
 *          When she/he has finished to do so she/he should call `get_nn_execution_status()` and act as described for the different `execution_status` values
 *          returned ny the call of `get_nn_execution_status()`.
 * @param[in] network network opaque pointer
 * @return error or return code
 * 
 * @note the number of samples of asynchronous runs (parameter `stai_size n_samples` of function `stai_network_fan_ae_run()`) is restricted to `1`! 
 * @note enum `stai_return_code` might need to be extended to better represent errors of new API functions,
 *       in this case e.g. an enum value specifying that the provided network handle does not identify the currently running network,
 *       and one that informs about a still running network execution (for function `stai_network_fan_ae_run()`).
 */
STAI_API_ENTRY
stai_return_code stai_ext_network_fan_ae_run_continue(stai_network* network);

/**
 * @brief continue network execution of an asynchronously started/run network (i.e. network was started/run in `stai_run_mode::MODE_ASYNC` mode)
 * @details Running a network in asynchronous mode (see function `stai_network_fan_ae_run()` and its parameter `mode` being equal to `stai_run_mode::MODE_ASYNC`)
 *          means that `stai_network_fan_ae_run()` returns while the network is still in execution. In this case the user may not call 
 *          `stai_network_fan_ae_run()` again until the network's execution has actually finish.
 *          Therefore, we need to have two new API functions, one that provides the execution status of the currently running network (`get_nn_execution_status()`),
 *          and one which triggers the continuation of the network execution (`continue_nn_execution()`).
 * @details While the asynchronously started network is in execution the user may call any application specific code. 
 *          When she/he has finished to do so she/he should call `get_nn_execution_status()` and act as described for the different `execution_status` values
 *          returned ny the call of `get_nn_execution_status()`.
 * @param[in] network network handle
 * @return error code
 * 
 * @note the number of samples of asynchronous runs (parameter `stai_size n_samples` of function `stai_network_fan_ae_run()`) is restricted to `1`! 
 * @note enum `stai_return_code` might need to be extended to better represent errors of new API functions,
 *       in this case e.g. an enum value specifying that the provided network handle does not identify the currently running network,
 *       and one that informs about a still running network execution (for function `stai_network_fan_ae_run()`).
 */
STAI_API_ENTRY
stai_return_code stai_ext_network_fan_ae_get_nn_run_status(stai_network* network);


STAI_API_DECLARE_END

#endif    /* STAI_NETWORK_FAN_AE_H */
