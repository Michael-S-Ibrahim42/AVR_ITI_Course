/* **************************************************************************************
 **       Author      :	Michael S. Ibrahim
 **       Date        :	March 16, 2022
 **       Version     :	V01
 **       SWC         :	Lab3_Task5
 **       Description :	Task5 main file
 ** **************************************************************************************/
#include <util/delay.h>
#define F_CPU 			16000000UL
#include "Std_types.h"
#include "Port.h"
#include "LCD.h"

int main(void) {
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
  while (1)
	{
		LCD_vidSendCommand(LCD_u8CLEAR);
		Task3_vidDisFrame1();
		LCD_vidSendCommand(LCD_u8CLEAR);
		Task3_vidDisFrame2();
		LCD_vidSendCommand(LCD_u8CLEAR);
		Task3_vidDisFrame3();
		LCD_vidSendCommand(LCD_u8CLEAR);
		Task3_vidDisFrame4();
		LCD_vidSendCommand(LCD_u8CLEAR);
		Task3_vidDisFrame5();
		LCD_vidSendCommand(LCD_u8CLEAR);
	}/* while */

	return (0);
}/* main */
void Task3_vidDisFrame0(void)
{
	u8 Loc_u8CustomCharF1_UR[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00100, 0b01100, 0b10100}; /* The Upper Right */
	u8 Loc_u8CustomCharF1_UL[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00100, 0b00110, 0b00101}; /* The Upper Left */
	u8 Loc_u8CustomCharF1_LL[8] = {0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b00000, 0b00000, 0b00000}; /* The Lower Left */
	u8 Loc_u8CustomCharF1_LR[8] = {0b00100, 0b00100, 0b00100, 0b00100, 0b00100, 0b00000, 0b00000, 0b00000}; /* The Lower Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH0, Loc_u8CustomCharF1_UL);/* The Character Upper Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH1, Loc_u8CustomCharF1_UR);/* The Character Upper Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH2, Loc_u8CustomCharF1_LL);/* The Character Lower Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH3, Loc_u8CustomCharF1_LR);/* The Character Lower Right */
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL7);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL7);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
	_delay_ms(500);
}
void Task3_vidDisFrame1(void)
{
	u8 Loc_u8CustomCharF1_UR[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00110, 0b01010, 0b10010}; /* The Upper Right */
	u8 Loc_u8CustomCharF1_UL[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b01100, 0b01010, 0b01001}; /* The Upper Left */
	u8 Loc_u8CustomCharF1_LL[8] = {0b01000, 0b01000, 0b01000, 0b01000, 0b01000, 0b01000, 0b00000, 0b00000}; /* The Lower Left */
	u8 Loc_u8CustomCharF1_LR[8] = {0b00010, 0b00010, 0b00010, 0b00010, 0b00010, 0b00010, 0b00000, 0b00000}; /* The Lower Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH0, Loc_u8CustomCharF1_UL);/* The Character Upper Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH1, Loc_u8CustomCharF1_UR);/* The Character Upper Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH2, Loc_u8CustomCharF1_LL);/* The Character Lower Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH3, Loc_u8CustomCharF1_LR);/* The Character Lower Right */
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL7);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL7);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
	_delay_ms(500);
}
void Task3_vidDisFrame2(void)
{
	u8 Loc_u8CustomCharF1_UR[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00111, 0b01001, 0b10001}; /* The Upper Right */
	u8 Loc_u8CustomCharF1_UL[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11100, 0b10010, 0b10001}; /* The Upper Left */
	u8 Loc_u8CustomCharF1_LL[8] = {0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000}; /* The Lower Left */
	u8 Loc_u8CustomCharF1_LR[8] = {0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001, 0b00001}; /* The Lower Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH0, Loc_u8CustomCharF1_UL);/* The Character Upper Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH1, Loc_u8CustomCharF1_UR);/* The Character Upper Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH2, Loc_u8CustomCharF1_LL);/* The Character Lower Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH3, Loc_u8CustomCharF1_LR);/* The Character Lower Right */
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL7);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL7);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
	_delay_ms(500);
}
void Task3_vidDisFrame3(void)
{
	u8 Loc_u8CustomCharF1_UR0[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b00011, 0b00111, 0b01100, 0b11000}; /* The Upper Right */
	u8 Loc_u8CustomCharF1_UR1[8] = {0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b00011, 0b00011, 0b00011}; /* The Upper Right */
	u8 Loc_u8CustomCharF1_UL0[8] = {0b00000, 0b00000, 0b00000, 0b00000, 0b11000, 0b11100, 0b00110, 0b00011}; /* The Upper Left */
	u8 Loc_u8CustomCharF1_UL1[8] = {0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11000, 0b11000, 0b11000}; /* The Upper Left */
	u8 Loc_u8CustomCharF1_LL[8]  = {0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000}; /* The Lower Left */
	u8 Loc_u8CustomCharF1_LR[8]  = {0b00011, 0b00011, 0b00011, 0b00011, 0b00011, 0b00011, 0b00011, 0b00011}; /* The Lower Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH0, Loc_u8CustomCharF1_UR0);/* The Character Upper Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH1, Loc_u8CustomCharF1_UR1);/* The Character Upper Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH2, Loc_u8CustomCharF1_UL0);/* The Character Lower Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH3, Loc_u8CustomCharF1_UL1);/* The Character Lower Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH4, Loc_u8CustomCharF1_LL);/* The Character Lower Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH5, Loc_u8CustomCharF1_LR);/* The Character Lower Right */
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL6);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL7);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL9);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL6);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL9);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE5);
	_delay_ms(500);
}
void Task3_vidDisFrame4(void)
{
	u8 Loc_u8CustomCharF1_UR0[8] = {0b00001,0b00011,0b00110,0b01100,0b11000,0b10000,0b00000,0b00000}; /* The Upper Right */
	u8 Loc_u8CustomCharF1_UR1[8] = {0b11111,0b11111,0b00111,0b00111,0b00111,0b00111,0b00111,0b00111}; /* The Upper Right */
	u8 Loc_u8CustomCharF1_UL0[8] = {0b10000,0b11000,0b01100,0b00110,0b00011,0b00001,0b00000,0b00000}; /* The Upper Left */
	u8 Loc_u8CustomCharF1_UL1[8] = {0b11111,0b11111,0b11100,0b11100,0b11100,0b11100,0b11100,0b11100}; /* The Upper Left */
	u8 Loc_u8CustomCharF1_LL[8]  = {0b11100,0b11100,0b11100,0b11100,0b11100,0b11100,0b11100,0b11100}; /* The Lower Left */
	u8 Loc_u8CustomCharF1_LR[8]  = {0b00111,0b00111,0b00111,0b00111,0b00111,0b00111,0b00111,0b00111}; /* The Lower Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH0, Loc_u8CustomCharF1_UR0);/* The Character Upper Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH1, Loc_u8CustomCharF1_UR1);/* The Character Upper Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH2, Loc_u8CustomCharF1_UL0);/* The Character Lower Left */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH3, Loc_u8CustomCharF1_UL1);/* The Character Lower Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH4, Loc_u8CustomCharF1_LL);/* The Character Lower Right */
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH5, Loc_u8CustomCharF1_LR);/* The Character Lower Right */
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL6);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL7);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE2);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL8);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE0);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL9);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL6);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL9);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE5);
	_delay_ms(500);
}
void Task3_vidDisFrame5(void)
{
	u8 Loc_u8CustomCharF1_UR1[8] = {0b00011,0b00011,0b00011,0b00011,0b00011,0b00011,0b00011,0b00011};
	u8 Loc_u8CustomCharF1_UL1[8] = {0b11000,0b11000,0b11000,0b11000,0b11000,0b11000,0b11000,0b11000};
	u8 Loc_u8CustomCharF1_LL[8]  = {0b11000,0b11000,0b11000,0b11000,0b11000,0b11000,0b11000,0b11000};
	u8 Loc_u8CustomCharF1_LR[8]  = {0b00011,0b00011,0b00011,0b00011,0b00011,0b00011,0b00011,0b00011};
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH1, Loc_u8CustomCharF1_UR1);
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH3, Loc_u8CustomCharF1_UL1);
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH4, Loc_u8CustomCharF1_LL);
	LCD_vidCreateCustomCharacter(LCD_u8CGRAM_CH5, Loc_u8CustomCharF1_LR);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL6);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE3);
	LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL9);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE1);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL6);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE4);
	LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL9);
	LCD_vidDisplayCharacter(LCD_u8CGRAM_CODE5);
	_delay_ms(500);
}
