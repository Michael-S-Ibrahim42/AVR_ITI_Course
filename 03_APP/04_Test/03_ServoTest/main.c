/* **************************************************************************************
 **       Author      :	Michael & Yomna
 **       Date        :	May 05, 2022
 **       Version     :	V01
 **       SWC         :	main
 **       Description :	Servo Test
 ** **************************************************************************************/
/* ////////////////////////// Headers inclusion /////////////////////////////////////// */
/* STD headers */
#include <util/delay.h>
#define F_CPU         16000000UL
/* LIB headers */
#include "Std_types.h"
/* MCAL */
#include "Port.h"
#include "Pwm.h"
/* HAL */
#include "Servo.h"
/* ///////////////////////////////////////////////////////////////////////////////////// */

/* ////////////////////////// Fns Implementation /////////////////////////////////////// */
int main(void)
{
	Pwm_ConfigType Loc_astrPwmConfig[] =
	{
			{
					.u32Prescalar  =  PWM_u32PRESCAL_8,
					.u8ChannelID   =  PWM_u8CHANNEL1A,
					.u8Idle        =  PWM_u8LOW,
					.u8ChannelType =  PWM_u8VARIABLE_CHANNEL
			}
	};
	Port_vidInit();
	Pwm_Init(Loc_astrPwmConfig);
	while(1)
	{
		Servo_vidSetServoAngle(SERVO_u8SERVO0, 0);
		_delay_ms(500);
		Servo_vidSetServoAngle(SERVO_u8SERVO0, 90);
		_delay_ms(500);
		Servo_vidSetServoAngle(SERVO_u8SERVO0, 180);
		_delay_ms(500);

	}/* while */

	return(0);
}/* main */
/* ///////////////////////////////////////////////////////////////////////////////////// */
