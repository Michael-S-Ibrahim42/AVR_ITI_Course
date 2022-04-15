/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 01, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Lab1 Task1
** **************************************************************************************/
/* STD Headers */
#include "Std_types.h"
#include "Dio.h"
#include "Port.h"
#include <util/delay.h>
#define F_CPU         16000000UL

/* main Fn */
int main(int args, char** argv)
{
  u8 Loc_u8SwitchValue = 0;
  u8 Loc_u8PortValue = 0x01;
  /* Initialize */
  Port_vidInit();
  /* set Pin24 Input PullUp */
  Port_enuSetPinMode(PORT_u8PIN24, PORT_u8INPUT_PULL_UP);

  /* set PORTA output */
  Port_enuSetPinDirection(PORT_u8PIN0, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN1, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN2, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN3, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN4, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN5, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN6, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN7, PORT_u8DIR_OUT);

  while(1)
  { 
    /* checking Pin24 input value */
    Dio_enuReadChannel(DIO_u8PIN24, &Loc_u8SwitchValue);
    if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
    {
      Loc_u8PortValue = (Loc_u8PortValue >> 1) | (Loc_u8PortValue << 7);
      Dio_enuWritePort(DIO_u8PORT0, Loc_u8PortValue);
    }/* if */
    else
    {
      Loc_u8PortValue = (Loc_u8PortValue << 1) | (Loc_u8PortValue >> 7);
      Dio_enuWritePort(DIO_u8PORT0, Loc_u8PortValue);
    }/* else */
    _delay_ms(500);
  }/* while */
  
  return(0);/* indicate normal main termination */
}/* main */
