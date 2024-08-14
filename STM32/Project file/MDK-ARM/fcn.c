#include "fcn.h"

ai_handle fcn=AI_HANDLE_NULL;
static float fcnInData[AI_ROOM_STATE_FCN_IN_1_SIZE]={20,40,400,500};
static float fcnOutData[AI_ROOM_STATE_FCN_OUT_1_SIZE];
ai_u8 fcn_activations[AI_ROOM_STATE_FCN_DATA_ACTIVATIONS_SIZE];

ai_buffer * fcn_input;
ai_buffer * fcn_output;

void AI_Init_fcn(void)
{
  ai_error err;
  const ai_handle fcn_act_addr[] = { fcn_activations };
  err = ai_room_state_fcn_create_and_init(&fcn, fcn_act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    printf("ai_fcn_create error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	else 
	{
		printf("FCN AI init success!\r\n");
	}
  fcn_input = ai_room_state_fcn_inputs_get(fcn, NULL);
  fcn_output = ai_room_state_fcn_outputs_get(fcn, NULL);
}


void AI_Run_fcn(float *pIn, float *pOut)
{
	char logStr[100];
	int count = 0;
	float max = 0;
  ai_i32 batch;
  ai_error err;

  fcn_input[0].data = AI_HANDLE_PTR(pIn);
  fcn_output[0].data = AI_HANDLE_PTR(pOut);

  batch = ai_room_state_fcn_run(fcn, fcn_input, fcn_output);
  if (batch != 1) {
    err = ai_room_state_fcn_get_error(fcn);
    printf("AI ai_network_run error - type=%d code=%d\r\n", err.type, err.code);
    Error_Handler();
  }
	//printf("fcn_result=%8.6f,%8.6f",fcnOutData[0],fcnOutData[1]);
	
	if(fcnOutData[0]<fcnOutData[1])
	{
		//printf("fcn_result:环境条件好");
	}
	else	if(fcnOutData[0]>=fcnOutData[1])
	{
		//printf("fcn_result:环境条件不好");
	}
}

float* fcn_to_main(void)
{
	return fcnOutData;
}