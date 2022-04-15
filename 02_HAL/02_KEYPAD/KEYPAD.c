/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	KEYPAD
**       Description :	Keypad module
** **************************************************************************************/
/* *********************************************************************************** */
/* **************************** Headers Inclusion ************************************ */
#include "util/delay.h"
/* STD Headers */
#include "Std_types.h"
/* MCAL Headers */
#include "Dio.h"
/* Own Headers */
#include "KEYPAD.h"
#include "KEYPAD_prv.h"
#include "KEYPAD_cfg.h"

/* *********************************************************************************** */
/* 
  Description: Return the pressed key as character; one of the entered configurations
  Return     : Error Status, options available in KEYPAD.h under the "Error status" Section
  Parameter  : address of u8 variable to receive the passed keys value 
  ****Caution****: You have first to configure the rows pins as output and cols and input pull up
*/
Keypad_tenuStatus Keypad_enuGetKey(pu8 Add_pu8PressedKey)
{

  Keypad_tenuStatus Loc_enuStatus = Keypad_enuNok;/* Error status variable */
  u8 Loc_u8DebouncingCounter = 0, DebouncingFlag=0;
  u8 Loc_u8TempReading = KEYPAD_u8INIT_READ_VAR, Loc_u8Reading = KEYPAD_u8INIT_READ_VAR;
  u8 Loc_u8Counter = KEYPAD_u8INIT_COUNT;
  u8 Loc_u8CheckValue = KEYPAD_u8ROWS_CHECK_VAL; 
  if(Add_pu8PressedKey == NULL)
  {
    Loc_enuStatus = Keypad_enuNullPtr;
  }/* if */
  else
  {
    while((Loc_enuStatus == Keypad_enuNok) && (Loc_u8Counter < KEYPAD_u8ROWS_NUM))
    {
      Loc_enuStatus = Keypad_enuOk;
      Loc_u8Reading = KEYPAD_u8INIT_READ_VAR;
      Dio_enuWriteChannel(KEYPAD_u8R0, ((~(Loc_u8CheckValue<<Loc_u8Counter))&KEYPAD_u8BIT0_MASK)>>KEYPAD_u8ZERO_BIT_SHIFT);
      Dio_enuWriteChannel(KEYPAD_u8R1, ((~(Loc_u8CheckValue<<Loc_u8Counter))&KEYPAD_u8BIT1_MASK)>>KEYPAD_u8ONE_BIT_SHIFT);
      Dio_enuWriteChannel(KEYPAD_u8R2, ((~(Loc_u8CheckValue<<Loc_u8Counter))&KEYPAD_u8BIT2_MASK)>>KEYPAD_u8TWO_BIT_SHIFT);
      Dio_enuWriteChannel(KEYPAD_u8R3, ((~(Loc_u8CheckValue<<Loc_u8Counter))&KEYPAD_u8BIT3_MASK)>>KEYPAD_u8THREE_BIT_SHIFT);
      DebouncingFlag =0;
      Loc_u8DebouncingCounter = 0;
      while(!DebouncingFlag)
      {
        Dio_enuReadChannel(KEYPAD_u8C0, &Loc_u8TempReading);
        if((Loc_u8TempReading == 0x01) && (Loc_u8DebouncingCounter > 0))
        {
          Loc_u8DebouncingCounter--;
        }/* if */
        else if(Loc_u8TempReading != 0x01)
        {
          Loc_u8DebouncingCounter++;
        }/* else if */
        if((Loc_u8DebouncingCounter == 0) || (Loc_u8DebouncingCounter >= 25))
        {
          DebouncingFlag = 1;
        }
        _delay_ms(1);
      }/* while */
      Loc_u8Reading |= (Loc_u8TempReading<<KEYPAD_u8ZERO_BIT_SHIFT);
      DebouncingFlag =0;
      Loc_u8DebouncingCounter = 10;
      while(!DebouncingFlag)
      {
        Dio_enuReadChannel(KEYPAD_u8C0, &Loc_u8TempReading);
        if((Loc_u8TempReading == 0x01) && (Loc_u8DebouncingCounter > 0))
        {
          Loc_u8DebouncingCounter--;
        }/* if */
        else if(Loc_u8TempReading != 0x01)
        {
          Loc_u8DebouncingCounter++;
        }/* else if */
        if(Loc_u8DebouncingCounter == 0)
        {
          DebouncingFlag = 1;
        }
		if(Loc_u8DebouncingCounter >= 25)
		{
			Loc_u8DebouncingCounter = 10;
		}
        _delay_ms(1);
      }/* while */
      DebouncingFlag =0;
      Loc_u8DebouncingCounter = 0;
      while(!DebouncingFlag)
      {
        Dio_enuReadChannel(KEYPAD_u8C1, &Loc_u8TempReading);
        if((Loc_u8TempReading == 0x01) && (Loc_u8DebouncingCounter > 0))
        {
          Loc_u8DebouncingCounter--;
        }/* if */
        else if(Loc_u8TempReading != 0x01)
        {
          Loc_u8DebouncingCounter++;
        }/* else if */
        if((Loc_u8DebouncingCounter == 0) || (Loc_u8DebouncingCounter >= 25))
        {
          DebouncingFlag = 1;
        }
        _delay_ms(1);
      }/* while */
      Loc_u8Reading |= (Loc_u8TempReading<<KEYPAD_u8ONE_BIT_SHIFT);
      DebouncingFlag =0;
      Loc_u8DebouncingCounter = 10;
      while(!DebouncingFlag)
      {
        Dio_enuReadChannel(KEYPAD_u8C0, &Loc_u8TempReading);
        if((Loc_u8TempReading == 0x01) && (Loc_u8DebouncingCounter > 0))
        {
          Loc_u8DebouncingCounter--;
        }/* if */
        else if(Loc_u8TempReading != 0x01)
        {
          Loc_u8DebouncingCounter++;
        }/* else if */
        if(Loc_u8DebouncingCounter == 0)
        {
          DebouncingFlag = 1;
        }
		if(Loc_u8DebouncingCounter >= 25)
		{
			Loc_u8DebouncingCounter = 10;
		}
        _delay_ms(1);
      }/* while */
      DebouncingFlag =0;
      Loc_u8DebouncingCounter = 0;
      while(!DebouncingFlag)
      {
        Dio_enuReadChannel(KEYPAD_u8C2, &Loc_u8TempReading);
        if((Loc_u8TempReading == 0x01) && (Loc_u8DebouncingCounter > 0))
        {
          Loc_u8DebouncingCounter--;
        }/* if */
        else if(Loc_u8TempReading != 0x01)
        {
          Loc_u8DebouncingCounter++;
        }/* else if */
        if((Loc_u8DebouncingCounter == 0) || (Loc_u8DebouncingCounter >= 25))
        {
          DebouncingFlag = 1;
        }
        _delay_ms(1);
      }/* while */
      Loc_u8Reading |= (Loc_u8TempReading<<KEYPAD_u8TWO_BIT_SHIFT);
      DebouncingFlag =0;
      Loc_u8DebouncingCounter = 10;
      while(!DebouncingFlag)
      {
        Dio_enuReadChannel(KEYPAD_u8C0, &Loc_u8TempReading);
        if((Loc_u8TempReading == 0x01) && (Loc_u8DebouncingCounter > 0))
        {
          Loc_u8DebouncingCounter--;
        }/* if */
        else if(Loc_u8TempReading != 0x01)
        {
          Loc_u8DebouncingCounter++;
        }/* else if */
        if(Loc_u8DebouncingCounter == 0)
        {
          DebouncingFlag = 1;
        }
		if(Loc_u8DebouncingCounter >= 25)
		{
			Loc_u8DebouncingCounter = 10;
		}
        _delay_ms(1);
      }/* while */
      DebouncingFlag =0;
      Loc_u8DebouncingCounter = 0;
      while(!DebouncingFlag)
      {
        Dio_enuReadChannel(KEYPAD_u8C3, &Loc_u8TempReading);
        if((Loc_u8TempReading == 0x01) && (Loc_u8DebouncingCounter > 0))
        {
          Loc_u8DebouncingCounter--;
        }/* if */
        else if(Loc_u8TempReading != 0x01)
        {
          Loc_u8DebouncingCounter++;
        }/* else if */
        if((Loc_u8DebouncingCounter == 0) || (Loc_u8DebouncingCounter >= 25))
        {
          DebouncingFlag = 1;
        }
        _delay_ms(1);
      }/* while */
  
      Loc_u8Reading |= (Loc_u8TempReading<<KEYPAD_u8THREE_BIT_SHIFT);
      DebouncingFlag =0;
      Loc_u8DebouncingCounter = 10;
      while(!DebouncingFlag)
      {
        Dio_enuReadChannel(KEYPAD_u8C0, &Loc_u8TempReading);
        if((Loc_u8TempReading == 0x01) && (Loc_u8DebouncingCounter > 0))
        {
          Loc_u8DebouncingCounter--;
        }/* if */
        else if(Loc_u8TempReading != 0x01)
        {
          Loc_u8DebouncingCounter++;
        }/* else if */
        if(Loc_u8DebouncingCounter == 0)
        {
          DebouncingFlag = 1;
        }
		if(Loc_u8DebouncingCounter >= 25)
		{
			Loc_u8DebouncingCounter = 10;
		}
        _delay_ms(1);
      }/* while */
      Loc_u8Reading |= (Loc_u8Counter<<KEYPAD_u8FOUR_BIT_SHIFT);
      switch(Loc_u8Reading)
      {
      case(KEYPAD_u8CASE_R0C0): 
        *Add_pu8PressedKey = KEYPAD_u8R0C0;
        break;
      case(KEYPAD_u8CASE_R0C1): 
        *Add_pu8PressedKey = KEYPAD_u8R0C1;
        break;
      case(KEYPAD_u8CASE_R0C2): 
        *Add_pu8PressedKey = KEYPAD_u8R0C2;
        break;
      case(KEYPAD_u8CASE_R0C3): 
        *Add_pu8PressedKey = KEYPAD_u8R0C3;
        break;        
      case(KEYPAD_u8CASE_R1C0): 
        *Add_pu8PressedKey = KEYPAD_u8R1C0;
        break;
      case(KEYPAD_u8CASE_R1C1):
        *Add_pu8PressedKey = KEYPAD_u8R1C1;
        break;
      case(KEYPAD_u8CASE_R1C2):
        *Add_pu8PressedKey = KEYPAD_u8R1C2;
        break;
      case(KEYPAD_u8CASE_R1C3):
        *Add_pu8PressedKey = KEYPAD_u8R1C3;
        break;        
      case(KEYPAD_u8CASE_R2C0): 
        *Add_pu8PressedKey = KEYPAD_u8R2C0;
        break;
      case(KEYPAD_u8CASE_R2C1):
        *Add_pu8PressedKey = KEYPAD_u8R2C1;
        break;
      case(KEYPAD_u8CASE_R2C2):
        *Add_pu8PressedKey = KEYPAD_u8R2C2;
        break;
      case(KEYPAD_u8CASE_R2C3):
        *Add_pu8PressedKey = KEYPAD_u8R2C3;
        break;        
      case(KEYPAD_u8CASE_R3C0): 
        *Add_pu8PressedKey = KEYPAD_u8R3C0;
        break;
      case(KEYPAD_u8CASE_R3C1):
        *Add_pu8PressedKey = KEYPAD_u8R3C1;
        break;
      case(KEYPAD_u8CASE_R3C2):
        *Add_pu8PressedKey = KEYPAD_u8R3C2;
        break;
      case(KEYPAD_u8CASE_R3C3):
        *Add_pu8PressedKey = KEYPAD_u8R3C3;
        break;     
      default:
        Loc_enuStatus = Keypad_enuNok;
      }/* switch */

      Loc_u8Counter++;
    }/* while */
  }/* else */

  return(Loc_enuStatus);
}/* Keypad_enuGetKey */
/* *********************************************************************************** */
/* *********************************************************************************** */
