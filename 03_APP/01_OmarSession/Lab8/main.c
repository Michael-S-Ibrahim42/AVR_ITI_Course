/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 15, 2022
**       Version     :	V0
**       SWC         :	main
**       Description :	
** **************************************************************************************/
/* STD headers */
#include <avr/io.h>
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Port.h"
#include "Dio.h"

/* main */
int main(void)
{
  Port_vidInit();
  Dio_enuWriteChannel(DIO_u8PIN0, DIO_u8PIN_HIGH);

  while(1)
  {
    
  }
  return(0);
}