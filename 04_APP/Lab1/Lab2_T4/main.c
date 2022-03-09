/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 01, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Lab1 Task4
** **************************************************************************************/
/* STD Headers */
#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU         16000000UL
#define SET_BIT(REG, BIT)           REG |=  (1<<BIT)
#define CLR_BIT(REG, BIT)           REG &= ~(1<<BIT)
#define GET_BIT(REG, BIT)           ((REG>>BIT)&1)
#define ALARM_LED     3           
#define INC_BTN       2
#define DEC_BTN       1
#define FLASH_BTN     0

/* main Fn */
int main(int args, char** argv)
{
  unsigned char FlashStat = 0;
  unsigned char PortValue = 0x00;
  /* Set direction */
  DDRA = 0xFF;
  SET_BIT(DDRD, ALARM_LED);
  CLR_BIT(DDRD, INC_BTN);
  CLR_BIT(DDRD, DEC_BTN);
  CLR_BIT(DDRD, FLASH_BTN);
  /* Initialize */
  SET_BIT(PORTD, INC_BTN);
  SET_BIT(PORTD, DEC_BTN);
  SET_BIT(PORTD, FLASH_BTN);
  PORTA = 0x00;

  while(1)
  {
    /* checking the pressing of "Flashing Btn" */
    if(GET_BIT(PIND, FLASH_BTN) == 0)
    {
      _delay_ms(10);
      if(GET_BIT(PIND, FLASH_BTN) == 0)
      {
        FlashStat ^= 1;
      }/* if */
      while(GET_BIT(PIND, FLASH_BTN) == 0);
    }/* if */
    /* checking the flashing status */
    if(FlashStat == 0)
    {
      /* checking the pressing of "Inc Btn" */
      if(GET_BIT(PIND, INC_BTN) == 0)
      {
        _delay_ms(10);
        if(GET_BIT(PIND, INC_BTN) == 0)
        {
          if(PortValue == 0xFF)
          {
            SET_BIT(PORTD, 3);
            _delay_ms(500);
            CLR_BIT(PORTD, 3);            
          }/* if */
          else
          {
            PortValue = (PortValue>>1) | (0x80);
          }/* else */
        }/* if */
        while(GET_BIT(PIND, INC_BTN) == 0);
      }/* if */
      /* checking the pressing of "Dec Btn" */
      if(GET_BIT(PIND, DEC_BTN) == 0)
      {
        _delay_ms(10);
        if(GET_BIT(PIND, DEC_BTN) == 0)
        {
          if(PortValue == 0x00)
          {
            SET_BIT(PORTD, 3);
            _delay_ms(500);
            CLR_BIT(PORTD, 3);            
          }/* if */
          else
          {
            PortValue <<= 1;
          }/* else */
        }/* if */
        while(GET_BIT(PIND, DEC_BTN) == 0);
      }/* if */
      PORTA = PortValue;
      _delay_ms(500);
    }/* if */
    else if(FlashStat == 1)
    {
      PORTA ^= PortValue;
      _delay_ms(500);
      /* checking the pressing of "Inc Btn" */
      if(GET_BIT(PIND, INC_BTN) == 0)
      {
        _delay_ms(10);
        if(GET_BIT(PIND, INC_BTN) == 0)
        {
          SET_BIT(PORTD, 3);
          _delay_ms(500);
          CLR_BIT(PORTD, 3);
        }/* if */
        while(GET_BIT(PIND, INC_BTN) == 0);
      }/* if */
      /* checking the pressing of "Dec Btn" */
      if(GET_BIT(PIND, DEC_BTN) == 0)
      {
        _delay_ms(10);
        if(GET_BIT(PIND, DEC_BTN) == 0)
        {
          SET_BIT(PORTD, 3);
          _delay_ms(500);
          CLR_BIT(PORTD, 3);
        }/* if */
        while(GET_BIT(PIND, DEC_BTN) == 0);
      }/* if */
    }/* else if */
    else
    {
      /* Do nothing */
    }/* else */
  }/* while */
  
  return(0);/* indicate normal main termination */
}/* main */
