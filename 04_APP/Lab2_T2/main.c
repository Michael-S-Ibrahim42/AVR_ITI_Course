/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 01, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Lab1 Task2
** **************************************************************************************/
/* STD Headers */
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU         16000000UL
#define SET_BIT(REG, BIT)       REG |=  (1<<BIT)
#define CLR_BIT(REG, BIT)       REG &= ~(1<<BIT)
#define GET_BIT(REG, BIT)       ((REG>>BIT)&1)

/* main Fn */
int main(int args, char** argv)
{
  int RunStatus = 1;/* Indicate the running status of the leds */
  unsigned char PORTA_Prev = 0;  /* hold the previous state of portA */
  /* Set direction */
  DDRA = 0xFF;
  CLR_BIT(DDRD, 0);
  /* Initialize */
  SET_BIT(PORTD, 0);
  PORTA = 0x01;
  while(1)
  {
    if(GET_BIT(PIND, 0) == 0)
    {
      _delay_ms(10);
      if(GET_BIT(PIND, 0) == 0);
        if(RunStatus == 1)
        {
          RunStatus = 0;
          PORTA_Prev = PORTA;
          PORTA = 0;
        }/* if */
        else
        {
          RunStatus = 1;
          PORTA = PORTA_Prev;
          PORTA = (PORTA >> 1) | (PORTA << 7);
        }/* else */
        while(GET_BIT(PIND, 0) == 0);
    }/* if */
    else
    {
      if(RunStatus == 1)
      {
        PORTA = (PORTA >> 1) | (PORTA << 7);
      }/* if */
    }/* else */
    _delay_ms(500);
  }/* while */
  
  return(0);/* indicate normal main termination */
}/* main */
