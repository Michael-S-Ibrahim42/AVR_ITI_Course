/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 11, 2022
**       Version     :	V01
**       SWC         :	LCD
**       Description :	LCD module files
** **************************************************************************************/

/* ************************************************************************ */
/* **************************** Headers Inclusion ************************* */
#include <util/delay.h>
#include "Std_types.h"
#include "Dio.h"
#include "LCD.h"
#include "LCD_prv.h"
#include "LCD_cfg.h"


/* ************************************************************************ */
/* **************************** Fns Implementations *********************** */

void LCD_vidInit(void)
{
  /* Basic Initializing steps */
  _delay_ms(LCD_u8INIT_CMD1_DELAY);
  LCD_vidSendCommand(LCD_u8FN_DL8_N1_F8);
  _delay_ms(LCD_u8INIT_CMD2_DELAY);
  LCD_vidSendCommand(LCD_u8FN_DL8_N1_F8);
  _delay_us(LCD_u8INIT_CMD3_DELAY);
  LCD_vidSendCommand(LCD_u8FN_DL8_N1_F8);
  /* Fn Set; Data lines number of bits(4 or 8) - Number of lines(1 or 2) - Font size(5*8 or 5*11) */
  LCD_vidSendCommand(LCD_u8FN_DL8_N2_F8);
  /* Display off */
  LCD_vidSendCommand(LCD_u8SET_DIS0_CUR0_BLINK0);
  /* Display clear */
  LCD_vidSendCommand(LCD_u8CLEAR);
  /* Entry Mode Set */
  LCD_vidSendCommand(LCD_u8MODE_INC_NO_SHFT);
  /* Turn on Display */
  LCD_vidSendCommand(LCD_u8SET_DIS1_CUR0_BLINK0);
}/* LCD_vidInit */
void LCD_vidSendCommand(u8 Copy_u8Command)
{
  Dio_enuWriteChannel(LCD_u8RS, DIO_u8PIN_LOW);
  Dio_enuWriteChannel(LCD_u8RW, DIO_u8PIN_LOW);
  Dio_enuWriteChannel(LCD_u8E, DIO_u8PIN_HIGH);
  Dio_enuWriteChannel(LCD_u8DB0, (Copy_u8Command>>LCD_u8BIT0) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB1, (Copy_u8Command>>LCD_u8BIT1) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB2, (Copy_u8Command>>LCD_u8BIT2) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB3, (Copy_u8Command>>LCD_u8BIT3) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB4, (Copy_u8Command>>LCD_u8BIT4) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB5, (Copy_u8Command>>LCD_u8BIT5) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB6, (Copy_u8Command>>LCD_u8BIT6) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB7, (Copy_u8Command>>LCD_u8BIT7) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8E, DIO_u8PIN_LOW);
  if((Copy_u8Command == LCD_u8RET_HOME) || (Copy_u8Command == LCD_u8CLEAR))
  {
    _delay_ms(LCD_u8DEFAULT_BIG_CMD_DELAY);
  }/* if */
  else
  {
    _delay_us(LCD_u8DEFAULT_SMALL_CMD_DELAY);
  }
}/* LCD_vidSendCommand */
void LCD_vidDisplayCharacter(u8 Copy_u8Character)
{
  Dio_enuWriteChannel(LCD_u8RS, DIO_u8PIN_HIGH);
  Dio_enuWriteChannel(LCD_u8RW, DIO_u8PIN_LOW);
  Dio_enuWriteChannel(LCD_u8E, DIO_u8PIN_HIGH);
  Dio_enuWriteChannel(LCD_u8DB0, (Copy_u8Character>>LCD_u8BIT0) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB1, (Copy_u8Character>>LCD_u8BIT1) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB2, (Copy_u8Character>>LCD_u8BIT2) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB3, (Copy_u8Character>>LCD_u8BIT3) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB4, (Copy_u8Character>>LCD_u8BIT4) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB5, (Copy_u8Character>>LCD_u8BIT5) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB6, (Copy_u8Character>>LCD_u8BIT6) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8DB7, (Copy_u8Character>>LCD_u8BIT7) & LCD_u8CMD_SPLIT);
  Dio_enuWriteChannel(LCD_u8E, DIO_u8PIN_LOW); 
  _delay_us(LCD_u8DEFAULT_SMALL_CMD_DELAY); 
}/* LCD_vidDisplayCharacter */

void LCD_vidDisplayNumber(u16 Copy_u16Number)
{
	u16 Loc_u16Temp = 0;
	u8 Loc_u8Zeros = 0;
  u16 Loc_u16Display = (u16)LCD_u8LCD_NUM_INIT;
  while(Copy_u16Number)
  {
    Loc_u16Display = Copy_u16Number % LCD_u8NUM_DIV;
    Loc_u16Temp = Loc_u16Display + Loc_u16Temp*10;
    if(Loc_u16Temp == 0)
    {
    	Loc_u8Zeros++;
    }
    Copy_u16Number /= LCD_u8NUM_DIV;
  }/* while */
  while(Loc_u16Temp)
  {
    Loc_u16Display = Loc_u16Temp % LCD_u8NUM_DIV;
    LCD_vidDisplayCharacter(Loc_u16Display+LCD_u8LCD_ASCII_SHIFT);
    Loc_u16Temp /= LCD_u8NUM_DIV;
  }/* while */
  while(Loc_u8Zeros)
  {
	  LCD_vidDisplayCharacter('0');
	  Loc_u8Zeros--;
  }
}/* LCD_vidDisplayNumber */
void LCD_vidDisplayFloatNum(f64 Copy_f64Number)
{
  u16 Loc_u16Number = (u16)Copy_f64Number;
  f32 Loc_f32Fraction = Copy_f64Number - Loc_u16Number;
	u16 Loc_u16Temp = 0;
	u8 Loc_u8Zeros = 0;
  u16 Loc_u16Display = (u16)LCD_u8LCD_NUM_INIT;
  while(Loc_u16Number)
  {
    Loc_u16Display = Loc_u16Number % LCD_u8NUM_DIV;
    Loc_u16Temp = Loc_u16Display + Loc_u16Temp*10;
    if(Loc_u16Temp == 0)
    {
    	Loc_u8Zeros++;
    }
    Loc_u16Number /= LCD_u8NUM_DIV;
  }/* while */
  while(Loc_u16Temp)
  {
    Loc_u16Display = Loc_u16Temp % LCD_u8NUM_DIV;
    LCD_vidDisplayCharacter(Loc_u16Display+LCD_u8LCD_ASCII_SHIFT);
    Loc_u16Temp /= LCD_u8NUM_DIV;
  }/* while */
  while(Loc_u8Zeros)
  {
	  LCD_vidDisplayCharacter('0');
	  Loc_u8Zeros--;
  }
  LCD_vidDisplayCharacter('.');
	
  Loc_u16Number = (u16)(Loc_f32Fraction * 100);
  Loc_u16Temp = 0;
  Loc_u8Zeros = 0;
  Loc_u16Display = (u16)LCD_u8LCD_NUM_INIT;
  while(Loc_u16Number)
  {
    Loc_u16Display = Loc_u16Number % LCD_u8NUM_DIV;
    Loc_u16Temp = Loc_u16Display + Loc_u16Temp*10;
    if(Loc_u16Temp == 0)
    {
    	Loc_u8Zeros++;
    }
    Loc_u16Number /= LCD_u8NUM_DIV;
  }/* while */
  while(Loc_u16Temp)
  {
    Loc_u16Display = Loc_u16Temp % LCD_u8NUM_DIV;
    LCD_vidDisplayCharacter(Loc_u16Display+LCD_u8LCD_ASCII_SHIFT);
    Loc_u16Temp /= LCD_u8NUM_DIV;
  }/* while */
  while(Loc_u8Zeros)
  {
	  LCD_vidDisplayCharacter('0');
	  Loc_u8Zeros--;
  }  
}/* LCD_vidDisplayFloatNum */

/* 
    Fn: Send custom characters to the LCD
    Return: Void
    Parameter1: Custom Character Creation Address, Available Options are in LCD.h under the section 'Custom Characters Creation Addresses'
    Parameter2: pointer to int array of size '8', which hold the custom character needed to be printed
*/
void LCD_vidCreateCustomCharacter(u8 Copy_u8CustomCharAdd, pu8 Copy_pu8CustomCharacter)
{
  u8 Loc_u8Counter;
  LCD_vidSendCommand(Copy_u8CustomCharAdd|LCD_u8CGRAM_ADD_SET);
  for(Loc_u8Counter = LCD_u8CUSTOM_COUNTER_INIT; Loc_u8Counter < LCD_u8CUSTOM_COUNTER_MAX; Loc_u8Counter++)
  {
    LCD_vidDisplayCharacter(*Copy_pu8CustomCharacter);
    Copy_pu8CustomCharacter++;
  }/* for */
  LCD_vidSendCommand(LCD_u8DDRAM_ADD_SET);
}/* LCD_vidCreateCustomCharacter */
void LCD_vidGoTo(u8 Copy_u8Row, u8 Copy_u8Column)
{
  LCD_vidSendCommand((LCD_u8DDRAM_ADD_SET|(Copy_u8Row+Copy_u8Column)));  
}/* LCD_vidGoTo */
/* 
    Fn: Display String on the LCD
    Return: Void
    Parameter1: the pointer to the string
*/
void LCD_vidDisplayString(pu8 Copy_pu8String)
{
  while(*Copy_pu8String != LCD_u8NULL_CHAR)
  {
    LCD_vidDisplayCharacter(*Copy_pu8String);
    Copy_pu8String++;
  }
}/* LCD_vidDisplayString */
/* ************************************************************************ */
/* ************************************************************************ */
