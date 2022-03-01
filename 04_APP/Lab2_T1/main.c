/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 01, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Lab1 Task1
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
      PORTA = (PORTA >> 1) | (PORTA << 7);
    }/* if */
    else
    {
      PORTA = (PORTA << 1) | (PORTA >> 7);
    }/* else */
    _delay_ms(500);
  }/* while */
  
  return(0);/* indicate normal main termination */
}/* main */
