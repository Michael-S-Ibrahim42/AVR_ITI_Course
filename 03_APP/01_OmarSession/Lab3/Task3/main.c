/* **************************************************************************************
 **       Author      :	Michael S. Ibrahim
 **       Date        :	March 16, 2022
 **       Version     :	V01
 **       SWC         :	Lab3_Task3
 **       Description :	Task3 main file
 ** **************************************************************************************/
#include <util/delay.h>
#define F_CPU 			16000000UL
#include "Std_types.h"
#include "Port.h"
#include "LCD.h"

void Task3_vidDisFrame1(void);
void Task3_vidDisFrame2(void);
void Task3_vidDisFrame3(void);
void Task3_vidDisFrame4(void);

int main(void) {
  u8 Loc_u8CustomChar0[8] = { 0b01110, 0b01110, 0b00101, 0b11110, 0b00100, 0b01010, 0b10001, 0b11111 }; /* The Runner */
  u8 Loc_u8CustomChar1[8] = { 0b00000, 0b00000, 0b00000, 0b00001, 0b00011, 0b00111, 0b01111, 0b11111 }; /* The Stair  */
  u8 Loc_u8CustomChar2[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000 }; /* The Hole   */
  u8 Loc_u8CustomChar3[8] = { 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b11111 }; /* The Wall   */
  u8 Loc_u8CustomChar4[8] = { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111 }; /* The Ground */
  u8 Loc_u8CustomChar5[8] = { 0b00000, 0b00000, 0b00000, 0b00101, 0b00111, 0b01111, 0b01111, 0b11111 }; /* On Stairs */
  u8 Loc_u8CustomChar6[8] = { 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00101, 0b01111, 0b11111 }; /* The Crash   */
	/* Setting the LCD pins directions */
	Port_enuSetPinDirection(PORT_u8PIN0, PORT_u8DIR_OUT );
	Port_enuSetPinDirection(PORT_u8PIN1, PORT_u8DIR_OUT );
	Port_enuSetPinDirection(PORT_u8PIN2, PORT_u8DIR_OUT );
	Port_enuSetPinDirection(PORT_u8PIN24, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN25, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN26, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN27, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN28, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN29, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN30, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN31, PORT_u8DIR_OUT);
	/* Init the LCD */
	LCD_vidInit();
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH0, Loc_u8CustomChar0);/* The Runner */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH1, Loc_u8CustomChar1);/* The Stairs */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH2, Loc_u8CustomChar2);/* The Hole */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH3, Loc_u8CustomChar3);/* The Wall */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH4, Loc_u8CustomChar4);/* The Ground */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH5, Loc_u8CustomChar5);/* On Stairs */
  LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH6, Loc_u8CustomChar6);/* On Stairs */
  while (1)
	{
		LCD_vidSendCommand(LCD_u8CLEAR);
		Task3_vidDisFrame1();
		Task3_vidDisFrame2();
		Task3_vidDisFrame3();
		Task3_vidDisFrame4();
		LCD_vidSendCommand(LCD_u8CLEAR);
		LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL4);
		LCD_vidDisplayString("The END");
		_delay_ms(1000);
	}/* while */

	return (0);
}/* main */
void Task3_vidDisFrame1(void)
{
		u8 Loc_u8Counter;
		for(Loc_u8Counter = LCD_u8COL0; Loc_u8Counter <= LCD_u8COL15; Loc_u8Counter++)
		{
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
		}/* for */
		for (Loc_u8Counter = LCD_u8COL0; Loc_u8Counter <= LCD_u8COL15; Loc_u8Counter++)
		{
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter-1);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);/* The runner */
			_delay_ms(500);
		}/* for */
		LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL15);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
}
void Task3_vidDisFrame2(void)
{
		u8 Loc_u8Counter;
		LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL8);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);/* The Hole */

		for (Loc_u8Counter = LCD_u8COL0; Loc_u8Counter < LCD_u8COL8; Loc_u8Counter++)
		{
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);/* The runner */
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter-1);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
			_delay_ms(500);
		}/* for */
		LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter-1);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
		for (Loc_u8Counter = LCD_u8COL8; Loc_u8Counter <= LCD_u8COL15; Loc_u8Counter++)
		{
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);/* The runner */
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0+Loc_u8Counter-1);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
			_delay_ms(500);
		}/* for */
		LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL15);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
}
void Task3_vidDisFrame3(void)
{
		u8 Loc_u8Counter;
		LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);/* The Stairs */

		for (Loc_u8Counter = LCD_u8COL0; Loc_u8Counter < LCD_u8COL8; Loc_u8Counter++)
		{
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);/* The runner */
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0+Loc_u8Counter-1);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
			_delay_ms(500);
		}/* for */
		LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL7);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
		LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE5);/* On Stairs */
		_delay_ms(500);
		LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);/* The Stairs */
		for (Loc_u8Counter = LCD_u8COL9; Loc_u8Counter <= LCD_u8COL15; Loc_u8Counter++)
		{
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);/* The runner */
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter-1);
			if((LCD_u8COL0+Loc_u8Counter-1) != LCD_u8COL8)
			{
				LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
			}/* if */
			_delay_ms(500);
		}/* for */
		LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL15);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
}
void Task3_vidDisFrame4(void)
{
	u8 Loc_u8Counter;
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL15);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);/* The Wall */	
	for (Loc_u8Counter = LCD_u8COL0; Loc_u8Counter <= LCD_u8COL15; Loc_u8Counter++)
	{
		LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter-1);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);/* The ground */
		LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter);
		LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);/* The runner */
		_delay_ms(500);
	}/* for */
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL15);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE6);/* The Crash */
	_delay_ms(500);
}