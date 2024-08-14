/**
  ******************************************************************************
  * @file    lite_dense_if32.h
  * @author  AIS
  * @date    29-Nov-2022
  * @brief   Definitions of runtime-lite dense core kernels (with float f32 input)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#ifndef LITE_DENSE_IF32_H
#define LITE_DENSE_IF32_H

#include "ai_lite_interface.h"

/*!
 * @brief C struct for a dense layer with signed float input, signed float output, and float weights.
 * @ingroup lite_dense_if32
 * @param output The pointer to output buffer.
 * @param input The pointer to input buffer.
 * @param weights The pointer to weights.
 * @param bias The pointer to bias (NULL if not available).
 * @param n_channel_in The number of channels of the input.
 * @param n_channel_out The number of channels of the output, i.e., the number of dense hidden neurons.
 */
typedef struct {
  ai_float*           output;
  const ai_float*     input;
  const ai_float*     weights;
  const ai_float*     bias;
  const ai_size       n_channel_in;
  const ai_size       n_channel_out;
  const ai_size       n_elements;
} forward_lite_dense_if32of32wf32_args;


/*!
 * @brief Forward function for a dense layer with signed float input,
 * signed float output, and float weights.
 * @ingroup lite_dense_if32
 * @param args pointer to @ref forward_lite_dense_if32of32wf32_args structure
 */
LITE_API_ENTRY
void forward_lite_dense_if32of32wf32(
  forward_lite_dense_if32of32wf32_args* args);


#endif    /* LITE_DENSE_IF32_H */
