/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 01, 2022
**       Version     :	V01
**       SWC         :	mian
**       Description :	Lab1 Task3
** **************************************************************************************/
/* STD Headers */
#include <avr/io.h>
#include <avr/delay.h>
#define F_CPU         16000000UL

/* main Fn */
int main(int args, char** argv)
{
  int Iterator;
  /* Set direction */
  DDRA = 0xFF;
  /* Initialize */
  PORTA = 0;
  while(1)
  {
    for(Iterator = 0; Iterator <  60; Iterator++)
    {
      PORTA = 0x01;
      _delay_ms(1000);
    }/* for */
    for(Iterator = 0; Iterator <  60; Iterator++)
    {
      PORTA = 0x02;
      _delay_ms(1000);
    }/* for */
    for(Iterator = 0; Iterator <  60; Iterator++)
    {
      PORTA = 0x04;
      _delay_ms(1000);
    }/* for */    
  }/* while */
  
  return(0);/* indicate normal main termination */
}/* main */
