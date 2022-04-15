/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 15, 2022
**       Version     :	V01
**       SWC         :	Lab5
**       Description :	
** **************************************************************************************/
#include <avr/io.h>

#include "Std_types.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Lab5.h"

int main(void)
{
  const Gpt_ConfigType Loc_strConfig = 
  {
    .u8Mode           = GPT_u8MODE_NORMAL,
    .u8CompareOutput  = GPT_u8OC0_NORMAL,
    .u8Prescalar      = GPT_u8PRES_1024
  };
  Port_vidInit();
  Gpt_Init(&Loc_strConfig);
  Gpt_Notification_CH0(&Test);
  Gpt_EnableNotification(GPT_u8CH0);
  SREG |= (1<<7);
  Gpt_StartTimer(GPT_u8CH0, 225);

  Dio_enuWriteChannel(DIO_u8PIN0, DIO_u8PIN_LOW);
  while(1)
  {

  }
  return(0);
}
void Test(void)
{
	static u8 state = DIO_u8PIN_HIGH;
//
	state ^= 0x01;
	Dio_enuWriteChannel(DIO_u8PIN0, state);
}
