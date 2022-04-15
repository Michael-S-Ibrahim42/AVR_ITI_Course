/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 01, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Lab1 Task2
** **************************************************************************************/
/* STD Headers */
#include "Std_types.h"
#include "Port.h"
#include "Dio.h"
#include <util/delay.h>
#define F_CPU         16000000UL
#define T2_RUN           1
#define T2_STOP          0

/* main Fn */
int main(int args, char** argv)
{
  u8 Loc_u8RunStatus = T2_RUN;/* Indicate the running status of the leds */
  u8 Loc_u8PortPrevVal = 0;  /* hold the previous state of port */
  u8 Loc_u8PortCurrVal = 128;  /* hold the current state of port */
  u8 Loc_u8SwitchValue = 0;
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
    Dio_enuReadChannel(DIO_u8PIN24, &Loc_u8SwitchValue);
    if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
    {
      _delay_ms(10);
      Dio_enuReadChannel(DIO_u8PIN24, &Loc_u8SwitchValue);
      if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
      {
    	if(Loc_u8RunStatus == T2_RUN)
        {
          Loc_u8RunStatus = T2_STOP;
          Loc_u8PortPrevVal = Loc_u8PortCurrVal;
          Loc_u8PortCurrVal = 0;
          Dio_enuWritePort(DIO_u8PORT0, Loc_u8PortCurrVal);
        }/* if */
        else
        {
          Loc_u8RunStatus = T2_RUN;
          Loc_u8PortCurrVal = Loc_u8PortPrevVal;
          Loc_u8PortCurrVal = (Loc_u8PortCurrVal >> 1) | (Loc_u8PortCurrVal << 7);
          Dio_enuWritePort(DIO_u8PORT0, Loc_u8PortCurrVal);           
        }/* else */
        while(Loc_u8SwitchValue == DIO_u8PIN_LOW)
        {
          Dio_enuReadChannel(DIO_u8PIN24, &Loc_u8SwitchValue);  
        }/* while */
      }/* if */
    }/* if */
    else
    {
      if(Loc_u8RunStatus == T2_RUN)
      {
        Loc_u8PortCurrVal = (Loc_u8PortCurrVal >> 1) | (Loc_u8PortCurrVal << 7);
        Dio_enuWritePort(DIO_u8PORT0, Loc_u8PortCurrVal);         
      }/* if */
    }/* else */
    _delay_ms(500);
  }/* while */
  
  return(0);/* indicate normal main termination */
}/* main */
