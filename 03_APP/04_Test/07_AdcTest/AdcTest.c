/* **************************************************************************************
**       Author      :	Michael & Yomna
**       Date        :	May 18, 2022
**       Version     :	V01
**       SWC         :	AdcTest
**       Description :	Adc Test application
** **************************************************************************************/
/* LIB headers */
#include "Std_types.h"
#include "ATMEGA32A.h"
/* MCAL headers */
#include "Port.h"
#include "Dio.h"
#include "Adc.h"
/* Own header */
#include "AdcTest.h"

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
{
	Port_vidInit();
	Adc_enuInit();
	Adc_enuRegisterCallback(ADC_u8CHANNEL_0, AdcTest_vidControlPin);
	Adc_enuStart(ADC_u8CHANNEL_0, &AdcTest);
	SREG |= (1<<7);/* Enable Global Interrupt */
	while(1)
	{

	}/* while */
	return(0);
}

void AdcTest_vidControlPin(void)
{
	if(AdcTest.Buffer[AdcTest.Index-1] > 500)
	{
		Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_HIGH);
	}/* if */
	else
	{
		Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_LOW);
	}/* else */
}/* AdcTest_vidControlPin */
