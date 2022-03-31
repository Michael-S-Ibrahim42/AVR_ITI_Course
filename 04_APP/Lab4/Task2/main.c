/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 24, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	lab4 task2
** **************************************************************************************/
/* ************************************************************************************** */
/* *************************** Headers Inclusion **************************************** */
/* STD headers */
#include "util/delay.h"
#define F_CPU           16000000
/* LIB Headers */
#include "Std_types.h"
/* HAL headers */
#include "LCD.h"
#include "KEYPAD.h"
/* MCAL headers */
#include "Port.h"
/* ************************************************************************************** */
/* ***************************** Fns Implementation ************************************* */
int main(int args, char** argv)
{

  u8 Loc_u8Error, Loc_u8Keypad;
  u8 Loc_u8Num1, Loc_u8Op, Loc_u8Num2, Loc_u8Result;/* Numbers of the calculator task */
  /* LCD Pins initialization*/
	Port_enuSetPinDirection(PORT_u8PIN0, PORT_u8DIR_OUT );
	Port_enuSetPinDirection(PORT_u8PIN1, PORT_u8DIR_OUT );
	Port_enuSetPinDirection(PORT_u8PIN2, PORT_u8DIR_OUT );
	Port_enuSetPinDirection(PORT_u8PIN16, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN17, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN18, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN19, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN20, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN21, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN22, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN23, PORT_u8DIR_OUT);
	/* Keypad Pins initialization */
  /* Rows */
	Port_enuSetPinDirection(PORT_u8PIN24, PORT_u8DIR_OUT );
	Port_enuSetPinDirection(PORT_u8PIN25, PORT_u8DIR_OUT );
	Port_enuSetPinDirection(PORT_u8PIN26, PORT_u8DIR_OUT );
	Port_enuSetPinDirection(PORT_u8PIN27, PORT_u8DIR_OUT );
  /* Columns */
	Port_enuSetPinMode(PORT_u8PIN28, PORT_u8INPUT_PULL_UP);
	Port_enuSetPinMode(PORT_u8PIN29, PORT_u8INPUT_PULL_UP);
	Port_enuSetPinMode(PORT_u8PIN30, PORT_u8INPUT_PULL_UP);
	Port_enuSetPinMode(PORT_u8PIN31, PORT_u8INPUT_PULL_UP);
	/* Init the LCD */
  LCD_vidInit();
  while(1)
  {
    Loc_u8Num1 = Loc_u8Op = Loc_u8Num2 = Loc_u8Result = 0;
    LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0);
    /* Taking Num1 */
    Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
    while(!(Loc_u8Error == Keypad_enuOk && (Loc_u8Keypad <= '9' && Loc_u8Keypad >= '0')))
    {
      Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
    }/* while */
    Loc_u8Num1 = Loc_u8Keypad;
    LCD_vidDisplayCharacter(Loc_u8Num1);
    Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
    while(!(Loc_u8Error == Keypad_enuOk && ((Loc_u8Keypad <= '9' && Loc_u8Keypad >= '0') || (Loc_u8Keypad == '+') || (Loc_u8Keypad == '-') || (Loc_u8Keypad == '/') || (Loc_u8Keypad == '*'))))
    {
      Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
    }/* while */
    if((Loc_u8Keypad>='0') && (Loc_u8Keypad<='9'))
    {
      Loc_u8Num1 -= '0';
      Loc_u8Num1 = (Loc_u8Num1*10) + (Loc_u8Keypad-'0');
      LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL0);
      LCD_vidDisplayNumber(Loc_u8Num1);
      Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
      while(!(Loc_u8Error == Keypad_enuOk && ((Loc_u8Keypad == '+') || (Loc_u8Keypad == '-') || (Loc_u8Keypad == '/') || (Loc_u8Keypad == '*'))))
      {
        Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
      }/* while */
      Loc_u8Op = Loc_u8Keypad;
      LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL2);
      LCD_vidDisplayCharacter(Loc_u8Op);
    }/* if */
    else
    {
      Loc_u8Num1 -= '0';
      Loc_u8Op = Loc_u8Keypad;
      LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL2);
      LCD_vidDisplayCharacter(Loc_u8Op);
    }/* else */
    Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
    while(!(Loc_u8Error == Keypad_enuOk && (Loc_u8Keypad <= '9' && Loc_u8Keypad >= '0')))
    {
      Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
    }/* while */
    Loc_u8Num2 = Loc_u8Keypad;
    LCD_vidDisplayCharacter(Loc_u8Num2);
    Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
    while(!(Loc_u8Error == Keypad_enuOk && ((Loc_u8Keypad <= '9' && Loc_u8Keypad >= '0') || (Loc_u8Keypad == '='))))
    {
      Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
    }/* while */
    if(Loc_u8Keypad != '=')
    {
      Loc_u8Num2 -= '0';
      Loc_u8Num2 = (Loc_u8Num2*10) + (Loc_u8Keypad-'0');
      LCD_vidGoTo(LCD_u8ROW0, LCD_u8COL3);
      LCD_vidDisplayNumber(Loc_u8Num2);
      Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
      while(!(Loc_u8Error == Keypad_enuOk && (Loc_u8Keypad == '=')))
      {
        Loc_u8Error = Keypad_enuGetKey(&Loc_u8Keypad);
      }/* while */
    }/* if */
    else
    {
      Loc_u8Num2 -= '0';
    }/* else */
    switch(Loc_u8Op)
    {
    case '+':
      Loc_u8Result = Loc_u8Num1 + Loc_u8Num2;
      LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
      LCD_vidDisplayNumber(Loc_u8Result);
      break;
    case '-':
      Loc_u8Result = Loc_u8Num1 - Loc_u8Num2;
      LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
      LCD_vidDisplayNumber(Loc_u8Result);
      break;
    case '*':
      Loc_u8Result = Loc_u8Num1 * Loc_u8Num2;
      LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
      LCD_vidDisplayNumber(Loc_u8Result);
      break;
    case '/':
      Loc_u8Result = Loc_u8Num1 / Loc_u8Num2;
      if(Loc_u8Num2 == 0)
      {
  		LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
  		LCD_vidDisplayString("Invalid");
      }
      else
      {
		LCD_vidGoTo(LCD_u8ROW1, LCD_u8COL8);
		LCD_vidDisplayNumber(Loc_u8Result);
      }
      break;
    default:
      break;
    }/* switch */
    _delay_ms(1000);
    LCD_vidSendCommand(LCD_u8CLEAR);
  }/* while */
  return(0);
}/* main */

/* ************************************************************************************** */
/* ************************************************************************************** */
