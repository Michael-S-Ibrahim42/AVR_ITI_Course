/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 22, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Simple calculator using LCD and Keypad 4*4
** **************************************************************************************/
/* ************************************************************************************** */
/* ****************************** Headers inclusion ************************************* */
/* STD headers */
#include "util/delay.h"
#define F_CPU 				16000000UL
#include "Std_types.h"
#include "Port.h"
#include "SEVSEG.h"
#include "KEYPAD.h"

int main(int args, char** argv)
{
	u8 Key = 0;
	f64 Number = 0;
	Keypad_tenuStatus Error;
	/* output */
	Port_enuSetPinDirection(PORT_u8PIN0, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN1, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN2, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN3, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN4, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN5, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN6, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN7, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN24, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN25, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN26, PORT_u8DIR_OUT);
	Port_enuSetPinDirection(PORT_u8PIN27, PORT_u8DIR_OUT);
	/* Input */
	Port_enuSetPinMode(PORT_u8PIN28, PORT_u8INPUT_PULL_UP);
	Port_enuSetPinMode(PORT_u8PIN29, PORT_u8INPUT_PULL_UP);
	Port_enuSetPinMode(PORT_u8PIN30, PORT_u8INPUT_PULL_UP);
	Port_enuSetPinMode(PORT_u8PIN31, PORT_u8INPUT_PULL_UP);

  while(1)
  {
	  Error = Keypad_enuGetKey(&Key);
	  if(Error == Keypad_enuOk)
	  {
		  SevSeg_enuDispNum(Key-'0');
	  }
  }/* while */
  return(0);
}/* main */
/* ************************************************************************************** */
/* ************************************************************************************** */

/* ************************************************************************************** */
/* ************************************************************************************** */
