/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 01, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	lab6 main file
** **************************************************************************************/
/* ********************************* Headers inclusion ********************************** */
/* STD headers */
#include "avr/interrupt.h"
/* LIB headers */
#include "Std_types.h"
/* HAL headers */
#include "H_Led.h"
/* MCAL headers */
#include "Port.h"
/* ************************************************************************************** */
/* ***************************** Entry Point ******************************************** */
int main(int args, char** argv)
{
  Port_vidInit();
  MCUCR &= ~(0x03);
  GICR |= (1<<6);
  while(1)
  {
    H_Led_enuSet(H_LED_u8BLUE, H_LED_u8OFF);
  }/* while */ 
  return(0);/* indicate normal program termination */
}/* main */

/* ************************************************************************************** */
/* ************************************************************************************** */

/* ************************************************************************************** */

