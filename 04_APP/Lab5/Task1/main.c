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
/* MCAL headers */
#include "M_ADC.h"
#include "Port.h"
/* ************************************************************************************** */
/* ****************************** Fns prototypes **************************************** */
void Task1_vidVolumeReading(void);
/* ************************************************************************************** */
/* ****************************** Global ************************************************ */
static u16 Task1_u16Volume;
static u8 Flag;
/* ************************************************************************************** */
/* ****************************** Fns *************************************************** */
int main(int args, char** argv)
{
  /* Volume characters */
  u8 Loc_u8CustomChar0[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111 };  /* LVL 0 */
  u8 Loc_u8CustomChar1[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111 };  /* LVL 1 */
  u8 Loc_u8CustomChar2[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111 };  /* LVL 2 */
  u8 Loc_u8CustomChar3[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111 };  /* LVL 3 */
  u8 Loc_u8CustomChar4[8] = { 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111 };  /* LVL 4 */
  u8 Loc_u8CustomChar5[8] = { 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111 };  /* LVL 5 */
  u8 Loc_u8CustomChar6[8] = { 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111 };  /* LVL 6 */
  u8 Loc_u8CustomChar7[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000 };  /* LVL 7 */
  /* Init modules */
  Port_vidInit();
  LCD_vidInit();
  M_ADC_enuInit();
  asm("sei");
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH0, Loc_u8CustomChar0); /* LVL 0 */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH1, Loc_u8CustomChar1); /* LVL 1 */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH2, Loc_u8CustomChar2); /* LVL 2 */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH3, Loc_u8CustomChar3); /* LVL 3 */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH4, Loc_u8CustomChar4); /* LVL 4 */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH5, Loc_u8CustomChar5); /* LVL 5 */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH6, Loc_u8CustomChar6); /* LVL 6 */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH7, Loc_u8CustomChar7); /* LVL 7 */
  M_ADC_enuSelectChannel(M_ADC_u8SEL_ADC0);
  M_ADC_enuRegCallbackFn(Task1_vidVolumeReading); 
  M_ADC_enuStart();
  LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0);
  LCD_vidDisplayString("Volume");
  while(1)
  {
	  if(Flag)
	  {
		  Periodic();
	  }
//    LCD_vidSendCommand(LCD_u8CLEAR);
    if(Task1_u16Volume >= 6000)
    {
        LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE5);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
    }/* if */
    else if(Task1_u16Volume >= 5000)
    {
        LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE5);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
    }/* if */
    else if(Task1_u16Volume >= 4000)
    {
        LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
    }/* if */
    else if(Task1_u16Volume >= 3000)
    {
        LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
    }/* if */
    else if(Task1_u16Volume >= 2000)
    {
        LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
    }/* if */              
    else if(Task1_u16Volume >= 1000)
    {
        LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
    }/* if */  
    else if(Task1_u16Volume >= 0)
    {
        LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
        LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE7);
    }/* if */
  }/* while */
  return(0);/* indicate normal main termination */
}/* main */
void Task1_vidVolumeReading(void)
{
  Flag = 1;
}/* Task1_vidVolumeReading */
void Periodic(void)
{
	  u16 Loc_u16Result;
	  M_ADC_enuReadResult(&Loc_u16Result);
	  Task1_u16Volume = ((u32)8000 * Loc_u16Result) / 1023;
	  Flag = 0;
}
/* ************************************************************************************** */
