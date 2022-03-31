/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 30, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	lab1 main source file
** **************************************************************************************/
/* ***************************** headers inclusion ************************************** */
/* STD headers */
#include "avr/delay.h"
#define F_CPU           16000000UL
#include "avr/interrupt.h"
/* LIB headers */
#include "Std_types.h"
/* HAL headers */
#include "LCD.h"
#include "H_Switch.h"
#include "H_Led.h"
/* MCAL headers */
#include "M_ADC.h"
#include "Port.h"

#define TASK2_LOW					0
#define TASK2_HIGH					1
/* ************************************************************************************** */
/* ****************************** Fns prototypes **************************************** */
void Task2_vidVoltageReading(void);
void Task2_vidUpdateVoltage(void);
/* ************************************************************************************** */
/* ****************************** Global ************************************************ */
static f32 Task2_f32Voltage;
static u8 Task2_u8Flag;
/* ************************************************************************************** */
/* ****************************** Fns *************************************************** */
int main(int args, char** argv)
{
	u8 Loc_u8SelectorValue = 0;
	/* Init modules */
  Port_vidInit();
  LCD_vidInit();
  M_ADC_enuInit();
  asm("sei");
  M_ADC_enuSelectChannel(M_ADC_u8SEL_ADC0);
  M_ADC_enuRegCallbackFn(Task2_vidVoltageReading);
  M_ADC_enuStart();
  LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0);
  LCD_vidDisplayString("Volt = ");
  while(1)
  {
	  LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL7);
	  if(Task2_u8Flag)
	  {
		  Task2_vidUpdateVoltage();
	  }
	  if(Loc_u8SelectorValue)//Millivolt option
	  {
		  LCD_vidDisplayFloatNum(Task2_f32Voltage);
	  }
	  else // volt option
	  {
		  Task2_f32Voltage /= (u16)1000;
		  LCD_vidDisplayFloatNum(Task2_f32Voltage);
	  }
	  LCD_vidDisplayString("    ");
	  H_Switch_enuReadSwitch(H_SWITCH_u8VOLT_SELECT, &Loc_u8SelectorValue);
  }/* while */
  return(0);/* indicate normal main termination */
}/* main */
void Task2_vidVoltageReading(void)
{
	Task2_u8Flag = TASK2_HIGH;
}/* Task2_vidVolumeReading */
void Task2_vidUpdateVoltage(void)
{
	  u16 Loc_u16Result;
	  M_ADC_enuReadResult(&Loc_u16Result);
	  Task2_f32Voltage = ((u32)5000 * Loc_u16Result) / 1023;
	  Task2_u8Flag = TASK2_LOW;
}
/* ************************************************************************************** */
