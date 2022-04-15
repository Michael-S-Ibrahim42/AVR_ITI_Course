/* **************************************************************************************
 **       Author      :	Michael S. Ibrahim
 **       Date        :	March 16, 2022
 **       Version     :	V01
 **       SWC         :	Lab3_Task2
 **       Description :	Task2 main file
 ** **************************************************************************************/
#include <util/delay.h>
#define F_CPU 			16000000UL
#include "Std_types.h"
#include "Port.h"
#include "LCD.h"
#define TASK2_NAME_ROWS				2
#define TASK2_NAME_COLS				8
#define TASK2_DELAY						1000
#define TASK2_ARR_ELE0				0
#define TASK2_ARR_ELE1				1
int main(void) {
	u8 Loc_u8Counter;
	u8 Loc_u8Array[TASK2_NAME_ROWS][TASK2_NAME_COLS] = {"M C A L", " I H E "};
	/* Setting the LCD pins directions */
	Port_enuSetPinDirection(PORT_u8PIN0, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN1, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN2, PORT_u8DIR_OUT);
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
	while (1) {
		for (Loc_u8Counter = LCD_u8COL0; Loc_u8Counter < LCD_u8COL9; Loc_u8Counter += 2) {
			LCD_vidSendCommand(LCD_u8CLEAR);
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayString(Loc_u8Array[TASK2_ARR_ELE0]);
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayString(Loc_u8Array[TASK2_ARR_ELE1]);
			_delay_ms(TASK2_DELAY);
			LCD_vidSendCommand(LCD_u8CLEAR);
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter+1);
			LCD_vidDisplayString(Loc_u8Array[TASK2_ARR_ELE1]);
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0+Loc_u8Counter+1);
			LCD_vidDisplayString(Loc_u8Array[TASK2_ARR_ELE0]);
			_delay_ms(TASK2_DELAY);
		}/* for */
		for (Loc_u8Counter = LCD_u8COL0; Loc_u8Counter < LCD_u8COL9; Loc_u8Counter += 2) {
			LCD_vidSendCommand(LCD_u8CLEAR);
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL9-Loc_u8Counter);
			LCD_vidDisplayString(Loc_u8Array[TASK2_ARR_ELE0]);
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL9-Loc_u8Counter);
			LCD_vidDisplayString(Loc_u8Array[TASK2_ARR_ELE1]);
			_delay_ms(TASK2_DELAY);
			LCD_vidSendCommand(LCD_u8CLEAR);
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL9-Loc_u8Counter-1);
			LCD_vidDisplayString(Loc_u8Array[TASK2_ARR_ELE1]);
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL9-Loc_u8Counter-1);
			LCD_vidDisplayString(Loc_u8Array[TASK2_ARR_ELE0]);
			_delay_ms(TASK2_DELAY);
		}/* for */
	}
	return (0);
}
