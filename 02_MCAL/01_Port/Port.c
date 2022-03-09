/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Port
**       Description :	Port module of the MCU "ATMEGA32A"
** **************************************************************************************/
#include "Std_types.h"
#include <avr/io.h>
#include "Port.h"
#include "Port_prv.h"
#include "Port_cfg.h"

/* Fns Implementations */
Port_tenuStatus Port_enuSetPinDirection (u8 Copy_u8PinNumber, u8 Copy_u8PinDirection )
{
  Port_tenuStatus Loc_enuReturnStatus = Port_Ok;
  u8 Loc_u8Port;
  u8 Loc_u8Pin;
  if(Copy_u8PinNumber > PORT_u8MAN_PIN_NO)
  {
    Loc_enuReturnStatus = Port_PinNoError;
    PORT_vidReportError();
  }/* if */
  else if(Copy_u8PinDirection > PORT_u8DIR_OUT)
  {
    Loc_enuReturnStatus = Port_DirError;    
    PORT_vidReportError();
  }/* else if */
  else 
  {
    Loc_u8Port = Copy_u8PinNumber / 8;
    Loc_u8Pin  = Copy_u8PinNumber % 8;
    switch(Loc_u8Port)
    {
      case(PORT_u8A):
        if(Copy_u8PinDirection == PORT_u8DIR_IN)
        {
          PORT_CLR_BIT(DDRA, Loc_u8Pin);
        }/* if */
        else
        {
          PORT_SET_BIT(DDRA, Loc_u8Pin);
        }/* else */
        break;
      case(PORT_u8B):
        if(Copy_u8PinDirection == PORT_u8DIR_IN)
        {
          PORT_CLR_BIT(DDRB, Loc_u8Pin);
        }/* if */
        else
        {
          PORT_SET_BIT(DDRB, Loc_u8Pin);
        }/* else */
        break;
      case(PORT_u8C):
        if(Copy_u8PinDirection == PORT_u8DIR_IN)
        {
          PORT_CLR_BIT(DDRC, Loc_u8Pin);
        }/* if */
        else
        {
          PORT_SET_BIT(DDRC, Loc_u8Pin);
        }/* else */
        break; 
      case(PORT_u8D):
        if(Copy_u8PinDirection == PORT_u8DIR_IN)
        {
          PORT_CLR_BIT(DDRD, Loc_u8Pin);
        }/* if */
        else
        {
          PORT_SET_BIT(DDRD, Loc_u8Pin);
        }/* else */
        break;
      default:
        break;
    }/* switch */
  }/* else */
  return(Loc_enuReturnStatus);
}/* Port_enuSetPinDirection */
Port_tenuStatus Port_enuSetPinMode(u8 Copy_u8PinNumber, u8 Copy_u8PinMode)
{
  Port_tenuStatus Loc_enuReturnStatus = Port_Ok;
  u8 Loc_u8Port;
  u8 Loc_u8Pin;
  if(Copy_u8PinNumber > PORT_u8MAN_PIN_NO)
  {
    Loc_enuReturnStatus = Port_PinNoError;
    PORT_vidReportError();
  }/* if */
  else if(Copy_u8PinMode > PORT_u8OUTPUT)
  {
    Loc_enuReturnStatus = Port_ModeError;    
    PORT_vidReportError();
  }/* else if */
  else 
  {
    Loc_u8Port = Copy_u8PinNumber / 8;
    Loc_u8Pin  = Copy_u8PinNumber % 8;
    switch(Loc_u8Port)
    {
      case(PORT_u8A):
        if(Copy_u8PinMode == PORT_u8INPUT_HIGH_IMP)
        {
          PORT_CLR_BIT(DDRA, Loc_u8Pin);
          PORT_CLR_BIT(PORTA, Loc_u8Pin);
        }/* if */
        else if(Copy_u8PinMode == PORT_u8INPUT_PULL_UP)
        {
          PORT_CLR_BIT(DDRA, Loc_u8Pin);
          PORT_SET_BIT(PORTA, Loc_u8Pin);
        }/* else if */
        else /* The case of output pin */
        {
          PORT_SET_BIT(DDRA, Loc_u8Pin);
        }/* else */
        break;
      case(PORT_u8B):
        if(Copy_u8PinMode == PORT_u8INPUT_HIGH_IMP)
        {
          PORT_CLR_BIT(DDRB, Loc_u8Pin);
          PORT_CLR_BIT(PORTB, Loc_u8Pin);
        }/* if */
        else if(Copy_u8PinMode == PORT_u8INPUT_PULL_UP)
        {
          PORT_CLR_BIT(DDRB, Loc_u8Pin);
          PORT_SET_BIT(PORTB, Loc_u8Pin);
        }/* else if */
        else /* The case of output pin */
        {
          PORT_SET_BIT(DDRB, Loc_u8Pin);
        }/* else */
        break;
      case(PORT_u8C):
        if(Copy_u8PinMode == PORT_u8INPUT_HIGH_IMP)
        {
          PORT_CLR_BIT(DDRC, Loc_u8Pin);
          PORT_CLR_BIT(PORTC, Loc_u8Pin);
        }/* if */
        else if(Copy_u8PinMode == PORT_u8INPUT_PULL_UP)
        {
          PORT_CLR_BIT(DDRC, Loc_u8Pin);
          PORT_SET_BIT(PORTC, Loc_u8Pin);
        }/* else if */
        else /* The case of output pin */
        {
          PORT_SET_BIT(DDRC, Loc_u8Pin);
        }/* else */
        break; 
      case(PORT_u8D):
        if(Copy_u8PinMode == PORT_u8INPUT_HIGH_IMP)
        {
          PORT_CLR_BIT(DDRD, Loc_u8Pin);
          PORT_CLR_BIT(PORTD, Loc_u8Pin);
        }/* if */
        else if(Copy_u8PinMode == PORT_u8INPUT_PULL_UP)
        {
          PORT_CLR_BIT(DDRD, Loc_u8Pin);
          PORT_SET_BIT(PORTD, Loc_u8Pin);
        }/* else if */
        else /* The case of output pin */
        {
          PORT_SET_BIT(DDRD, Loc_u8Pin);
        }/* else */
        break;
      default:
        break;
    }/* switch */
  }/* else */
  return(Loc_enuReturnStatus);  
}/* Port_enuSetPinMode */
void Port_vidInit(void)
{
  u32 PORT_u32Dir = PORT_u32DIR;
  u32 PORT_u32Mode = PORT_u32VAL;
  DDRA  = (u8) (PORT_u32Dir     );
  DDRB  = (u8) (PORT_u32Dir >>8 );
  DDRC  = (u8) (PORT_u32Dir >>16);
  DDRD  = (u8) (PORT_u32Dir >>24);
  PORTA = (u8) (PORT_u32Mode    );
  PORTB = (u8) (PORT_u32Mode>>8 );
  PORTC = (u8) (PORT_u32Mode>>16);
  PORTD = (u8) (PORT_u32Mode>>24);
}/* Port_vidInit */

u8 PORT_u8DET(void)
{
  return(0);
}/* PORT_u8DET */
