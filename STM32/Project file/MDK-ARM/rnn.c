#include "rnn.h"

ai_handle rnn=AI_HANDLE_NULL;
static float rnnInData[AI_ROOM_TEMP_RNN_IN_1_SIZE]={17.0,16.0,15.0,17.0,19.0,26.0};
static float rnnOutData[AI_ROOM_TEMP_RNN_OUT_1_SIZE];
static ai_u8 rnn_activations[AI_ROOM_TEMP_RNN_DATA_ACTIVATIONS_SIZE];

ai_buffer * rnn_input;
ai_buffer * rnn_output;

void AI_Init_rnn(void)
{
  ai_error err;
  const ai_handle rnn_act_addr[] = { rnn_activations };
  err = ai_room_temp_rnn_create_and_init(&rnn, rnn_act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    printf("ai_rnn_create error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	else 
	{
		printf("RNN AI init success!\r\n");
	}
  rnn_input = ai_room_temp_rnn_inputs_get(rnn, NULL);
  rnn_output = ai_room_temp_rnn_outputs_get(rnn, NULL);
}


void AI_Run_rnn(float *pIn, float *pOut)
{
	char logStr[100];
	int count = 0;
	float max = 0;
  ai_i32 batch;
  ai_error err;

  rnn_input[0].data = AI_HANDLE_PTR(pIn);
  rnn_output[0].data = AI_HANDLE_PTR(pOut);

  batch = ai_room_temp_rnn_run(rnn, rnn_input, rnn_output);
  if (batch != 1) {
    err = ai_room_temp_rnn_get_error(rnn);
    printf("AI ai_rnn_run error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	//printf("rnn_result=%8.6f\n",rnnOutData[0]);
}

float* rnn_to_main(void)
{
	return rnnOutData;
}