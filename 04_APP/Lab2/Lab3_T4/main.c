/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 01, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Lab1 Task4
** **************************************************************************************/
/* STD Headers */
#include "Std_types.h"
#include "Dio.h"
#include "Port.h"
#include <avr/delay.h>
#define F_CPU              16000000UL
#define T4_ALARM_LED       PORT_u8PIN27
#define T4_INC_BTN         PORT_u8PIN26
#define T4_DEC_BTN         PORT_u8PIN25
#define T4_FLASH_BTN       PORT_u8PIN24
#define T4_OFF_FLASH       0
#define T4_ON_FLASH        1
#define T4_PORT_INIT       0x00
#define T4_PORT_FULL       0xFF
#define T4_DEBOUNCE_DELAY  10
#define T4_WAIT_DELAY      500

/* main Fn */
int main(int args, char** argv)
{
  u8 Loc_u8FlashStat = T4_OFF_FLASH;
  u8 Loc_u8PortValue = T4_PORT_INIT;
  u8 Loc_u8PortPrevVal = T4_PORT_INIT;
  u8 Loc_u8SwitchValue;
  Port_vidInit();
  /* setting port0 dir as output */
  Port_enuSetPinDirection(PORT_u8PIN0, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN1, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN2, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN3, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN4, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN5, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN6, PORT_u8DIR_OUT);
  Port_enuSetPinDirection(PORT_u8PIN7, PORT_u8DIR_OUT);
  /* Setting the alarm led pin output */
  Port_enuSetPinDirection(T4_ALARM_LED, PORT_u8DIR_OUT);
  Dio_enuWriteChannel(T4_ALARM_LED, DIO_u8PIN_LOW);
  /* Set the buttons Modes */
  Port_enuSetPinMode     (T4_INC_BTN  , PORT_u8INPUT_PULL_UP);
  Port_enuSetPinMode     (T4_DEC_BTN  , PORT_u8INPUT_PULL_UP);
  Port_enuSetPinMode     (T4_FLASH_BTN, PORT_u8INPUT_PULL_UP);
  
  while(1)
  {
    /* checking the pressing of "Flashing Btn" */
    Dio_enuReadChannel(T4_FLASH_BTN, &Loc_u8SwitchValue);
    if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
    {
      _delay_ms(T4_DEBOUNCE_DELAY);
      Dio_enuReadChannel(T4_FLASH_BTN, &Loc_u8SwitchValue);
      if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
      {
        Loc_u8FlashStat ^= T4_ON_FLASH;
      }/* if */
      while(Loc_u8SwitchValue == DIO_u8PIN_LOW)
      {
        Dio_enuReadChannel(T4_FLASH_BTN, &Loc_u8SwitchValue);
      }/* while */
    }/* if */
    /* checking the flashing status */
    if(Loc_u8FlashStat == T4_OFF_FLASH)
    {
      Loc_u8PortValue = Loc_u8PortPrevVal;
      Dio_enuWritePort(DIO_u8PORT0, Loc_u8PortValue);
      /* checking the pressing of "Inc Btn" */
      Dio_enuReadChannel(T4_INC_BTN, &Loc_u8SwitchValue);
      if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
      {
        _delay_ms(T4_DEBOUNCE_DELAY);
        Dio_enuReadChannel(T4_INC_BTN, &Loc_u8SwitchValue);
        if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
        {
          if(Loc_u8PortValue == T4_PORT_FULL)
          {
            Dio_enuWriteChannel(T4_ALARM_LED, DIO_u8PIN_HIGH);
            _delay_ms(T4_WAIT_DELAY);
            Dio_enuWriteChannel(T4_ALARM_LED, DIO_u8PIN_LOW);
          }/* if */
          else
          {
            Loc_u8PortValue = (Loc_u8PortValue>>1) | (0x80);
            Loc_u8PortPrevVal = Loc_u8PortValue;
            Dio_enuWritePort(DIO_u8PORT0, Loc_u8PortValue);
          }/* else */
        }/* if */
        while(Loc_u8SwitchValue == DIO_u8PIN_LOW)
        {
          Dio_enuReadChannel(T4_INC_BTN, &Loc_u8SwitchValue);
        }
      }/* if */
      /* checking the pressing of "Dec Btn" */
      Dio_enuReadChannel(T4_DEC_BTN, &Loc_u8SwitchValue);
      if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
      {
        _delay_ms(T4_DEBOUNCE_DELAY);
        Dio_enuReadChannel(T4_DEC_BTN, &Loc_u8SwitchValue);
        if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
        {
          if(Loc_u8PortValue == T4_PORT_INIT)
          {
            Dio_enuWriteChannel(T4_ALARM_LED, DIO_u8PIN_HIGH);
            _delay_ms(T4_WAIT_DELAY);
            Dio_enuWriteChannel(T4_ALARM_LED, DIO_u8PIN_LOW);            
          }/* if */
          else
          {
            Loc_u8PortValue <<= 1;
            Loc_u8PortPrevVal = Loc_u8PortValue;
            Dio_enuWritePort(DIO_u8PORT0, Loc_u8PortValue);
          }/* else */
        }/* if */
        while(Loc_u8SwitchValue == DIO_u8PIN_LOW)
        {
          Dio_enuReadChannel(T4_DEC_BTN, &Loc_u8SwitchValue);
        }
      }/* if */
      _delay_ms(T4_WAIT_DELAY);
    }/* if */
    else if(Loc_u8FlashStat == T4_ON_FLASH)
    {
      Loc_u8PortValue ^= Loc_u8PortPrevVal;
      Dio_enuWritePort(DIO_u8PORT0, Loc_u8PortValue);
      _delay_ms(T4_WAIT_DELAY);
      /* checking the pressing of "Inc Btn" */
      Dio_enuReadChannel(T4_INC_BTN, &Loc_u8SwitchValue);
      if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
      {
        _delay_ms(T4_DEBOUNCE_DELAY);
        Dio_enuReadChannel(T4_INC_BTN, &Loc_u8SwitchValue);
        if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
        {
          Dio_enuWriteChannel(T4_ALARM_LED, DIO_u8PIN_HIGH);
          _delay_ms(T4_WAIT_DELAY);
          Dio_enuWriteChannel(T4_ALARM_LED, DIO_u8PIN_LOW);            
        }/* if */
        while(Loc_u8SwitchValue == DIO_u8PIN_LOW)
        {
          Dio_enuReadChannel(T4_INC_BTN, &Loc_u8SwitchValue);
        }
      }/* if */
      /* checking the pressing of "Dec Btn" */
      Dio_enuReadChannel(T4_DEC_BTN, &Loc_u8SwitchValue);
      if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
      {
        _delay_ms(T4_DEBOUNCE_DELAY);
        Dio_enuReadChannel(T4_DEC_BTN, &Loc_u8SwitchValue);
        if(Loc_u8SwitchValue == DIO_u8PIN_LOW)
        {
          Dio_enuWriteChannel(T4_ALARM_LED, DIO_u8PIN_HIGH);
          _delay_ms(T4_WAIT_DELAY);
          Dio_enuWriteChannel(T4_ALARM_LED, DIO_u8PIN_LOW);            
        }/* if */
        while(Loc_u8SwitchValue == DIO_u8PIN_LOW)
        {
          Dio_enuReadChannel(T4_DEC_BTN, &Loc_u8SwitchValue);
        }/* while */
      }/* if */
    }/* else if */
    else
    {
      /* Do nothing */
    }/* else */
  }/* while */
  
  return(0);/* indicate normal main termination */
}/* main */
