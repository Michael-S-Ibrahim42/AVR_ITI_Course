/* **************************************************************************************
 **       Author      :	Michael S. Ibrahim
 **       Date        :	March 16, 2022
 **       Version     :	V01
 **       SWC         :	Lab3_Task1
 **       Description :	Task1 main file
 ** **************************************************************************************/
#include <util/delay.h>
#define F_CPU 			16000000UL
#include "Std_types.h"
#include "Port.h"
#include "LCD.h"

int main(void) {
	u8 Loc_u8Counter;
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
		for (Loc_u8Counter = LCD_u8COL0; Loc_u8Counter <= LCD_u8COL15; Loc_u8Counter++) {
			LCD_vidSendCommand(LCD_u8CLEAR);
			LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayCharacter('X');
			_delay_ms(500);
		}/* for */
		for (Loc_u8Counter = LCD_u8COL0; Loc_u8Counter <= LCD_u8COL15; Loc_u8Counter++) {
			LCD_vidSendCommand(LCD_u8CLEAR);
			LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL0+Loc_u8Counter);
			LCD_vidDisplayCharacter('X');
			_delay_ms(500);
		}/* for */
	}
	return (0);
}
