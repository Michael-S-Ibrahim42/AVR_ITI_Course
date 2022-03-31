#include "Std_types.h"
#include "avr/io.h"
#include "Port.h"
#include "Dio.h"

#define SET_BIT(REG, BIT)               REG |= (1<<BIT)
#define GET_BIT(REG, BIT)               ((REG>>BIT) & 0x01)

int main(void)
{
  u16 Loc_u16Result, Loc_u16Analog, Loc_u16OldResult;
  Port_vidInit();
  ADMUX=0b01000000;
  ADCSRA=0b10000000;
  while(1)
  {
    SET_BIT(ADCSRA, 6);/* For starting conversion */
    while(GET_BIT(ADCSRA, 4) == 0);
    Loc_u16Result = ((u16)ADCL) | (((u16)ADCH)<<8);
    SET_BIT(ADCSRA, 4);
    if((Loc_u16Result >= 510) && (Loc_u16Result>Loc_u16OldResult))
    {
      Loc_u16OldResult = Loc_u16Result;
      Dio_enuWriteChannel(DIO_u8PIN24, DIO_u8PIN_HIGH);
      Dio_enuWriteChannel(DIO_u8PIN25, DIO_u8PIN_LOW);
    }/* if */
    else if((Loc_u16Result <= 490) && (Loc_u16Result<Loc_u16OldResult))
    {
      Loc_u16OldResult = Loc_u16Result;
      Dio_enuWriteChannel(DIO_u8PIN24, DIO_u8PIN_LOW);
      Dio_enuWriteChannel(DIO_u8PIN25, DIO_u8PIN_HIGH);
    }/* else if */
    else
    {
      Loc_u16OldResult = Loc_u16Result;
    }/* else */
//    Loc_u16Analog = Loc_u16Result * (5000/1023);
  }/* while */
}/* main */
