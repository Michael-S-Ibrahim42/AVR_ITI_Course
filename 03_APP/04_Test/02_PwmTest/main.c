/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	May 04, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Testing of PWM
** **************************************************************************************/
/* ////////////////////// Headers inclusion /////////////////////////////// */
/* STD headers */
//#include <avr/io.h>
#include "util/delay.h"
#define F_CPU       16000000UL
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Port.h"
#include "Pwm.h"
/* //////////////////////////////////////////////////////////////////////// */

/* /////////////////////// Fns ////////////////////////////////// */
int main(void)
{
  Pwm_ConfigType Loc_strPWMConfig = {
	  .u32Prescalar  =  PWM_u32PRESCAL_8,
    .u8ChannelID   =  PWM_u8CHANNEL1A,
	  .u8Idle        =  PWM_u8LOW,
	  .u8ChannelType =  PWM_u8VARIABLE_CHANNEL
  };
  Port_vidInit();
  Pwm_Init(&Loc_strPWMConfig);

  while(1)
  {
    Pwm_SetPeriodAndDuty(PWM_u8CHANNEL1A,  2.5, 20);/* angle 0 at 0.5 ms*/
    _delay_ms(500);
    Pwm_SetPeriodAndDuty(PWM_u8CHANNEL1A,  7.5, 20);/* angle 90 at 1.5 ms*/
    _delay_ms(500);
    Pwm_SetPeriodAndDuty(PWM_u8CHANNEL1A,  12.5, 20);/* angle 180 at 2.5 ms*/
    _delay_ms(500);
    Pwm_SetOutputToIdle(PWM_u8CHANNEL1A);
    _delay_ms(3000);
  }/* while */

  return(0);
}
