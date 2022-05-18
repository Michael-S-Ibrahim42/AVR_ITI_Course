/* **************************************************************************************
**       Author      :	Michael & Yomna 
**       Date        :	May 18, 2022
**       Version     :	V01
**       SWC         :	ServoControl
**       Description :	Servo Control task using potentiometer
** **************************************************************************************/
/* LIB headers */
#include "Std_types.h"
#include "ATMEGA32A.h"
/* MCAL headers */
#include "Port.h"
#include "Dio.h"
#include "Adc.h"
#include "Pwm.h"
/* HAL */
#include "Servo.h"
/* Own header */
#include "ServoControl.h"

#define BUFF_SIZE						50

u16 AdcTest_u16Buffer[BUFF_SIZE];

Adc_strBuffer_t AdcTest =
{
	.Buffer = AdcTest_u16Buffer,
	.Index  = ZERO_INIT,
	.Size   = BUFF_SIZE
};

/* main fn */
int main(void)
{	Pwm_ConfigType Loc_astrPwmConfig[] =
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
	Adc_enuInit();
	Adc_enuRegisterCallback(ADC_u8CHANNEL_0, AdcTest_vidControlServo);
	Adc_enuStart(ADC_u8CHANNEL_0, &AdcTest);
	SREG |= (1<<7);/* Enable Global Interrupt */
	while(1)
	{

	}/* while */
	return(0);
}

void AdcTest_vidControlServo(void)
{
	u8 Loc_u8Angle = ((u32)AdcTest.Buffer[AdcTest.Index-1] * 180) / 1024;
	Servo_vidSetServoAngle(SERVO_u8SERVO0, Loc_u8Angle);
}/* AdcTest_vidControlPin */
