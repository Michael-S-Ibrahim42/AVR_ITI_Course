/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 01, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Lab3 Task3
** **************************************************************************************/
/* STD Headers */
#include "Std_types.h"
#include "Dio.h"
#include "Port.h"
#include <avr/delay.h>
#define F_CPU            16000000UL
#define T3_LOOP_LIMIT    60
#define T3_LOOP_INIT     0  
#define T3_DELAY_1SEC    1000
#define T3_TRUE          1
#define T3_RED_LED       PORT_u8PIN0
#define T3_YELLOW_LED    PORT_u8PIN1
#define T3_GREEN_LED     PORT_u8PIN2
#define T3_PORT_LOW      0x00
/* main Fn */
int main(int args, char** argv)
{
  u8 Loc_u8Counter;
  Port_vidInit();
  /* set the port direction as output */
  Port_enuSetPinDirection(T3_RED_LED, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(T3_YELLOW_LED, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(T3_GREEN_LED, PORT_u8DIR_OUT);

  //Dio_enuWritePort(T3_RED_LED, T3_PORT_LOW);
  while(T3_TRUE)
  {
    /* Light the red led */
    for(Loc_u8Counter = T3_LOOP_INIT; Loc_u8Counter <  T3_LOOP_LIMIT; Loc_u8Counter++)
    {
      Dio_enuWriteChannel(T3_RED_LED   , DIO_u8PIN_HIGH);
      Dio_enuWriteChannel(T3_YELLOW_LED, DIO_u8PIN_LOW);
      Dio_enuWriteChannel(T3_GREEN_LED , DIO_u8PIN_LOW);

      _delay_ms(T3_DELAY_1SEC);
    }/* for */
    /* Light the yellow led */
    for(Loc_u8Counter = T3_LOOP_INIT; Loc_u8Counter <  T3_LOOP_LIMIT; Loc_u8Counter++)
    {
      Dio_enuWriteChannel(T3_RED_LED   , DIO_u8PIN_LOW);
      Dio_enuWriteChannel(T3_YELLOW_LED, DIO_u8PIN_HIGH);
      Dio_enuWriteChannel(T3_GREEN_LED , DIO_u8PIN_LOW);

      _delay_ms(T3_DELAY_1SEC);
    }/* for */
    /* Light the green led */
    for(Loc_u8Counter = T3_LOOP_INIT; Loc_u8Counter <  T3_LOOP_LIMIT; Loc_u8Counter++)
    {
      Dio_enuWriteChannel(T3_RED_LED   , DIO_u8PIN_LOW);
      Dio_enuWriteChannel(T3_YELLOW_LED, DIO_u8PIN_LOW);
      Dio_enuWriteChannel(T3_GREEN_LED , DIO_u8PIN_HIGH);

      _delay_ms(T3_DELAY_1SEC);
    }/* for */    
  }/* while */
  
  return(0);/* indicate normal main termination */
}/* main */
