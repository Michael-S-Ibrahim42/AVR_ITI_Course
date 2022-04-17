/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	KEYPAD
**       Description :	Keypad module
** **************************************************************************************/
/* **************************** Headers inclusion ************************************ */
/* STD Headers */
#include "Std_types.h"
/* MCAL Headers */
#include "Dio.h"
#include "Switch.h"
/* Own Headers */
#include "Keypad.h"
#include "Keypad_prv.h"
#include "Keypad_cfg.h"
/* /////////////////////////////// Global  /////////////////////////////////////////// */
extern const Keypad_tstrConfig Keypad_strConfig;
static u8 Keypad_u8PressedKey;/* static variable to hold the pressed key */
/* /////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////// Interface Fns ////////////////////////////////// */
/* 
  Description    :  Return the pressed key as character; one of the entered configurations
  Parameter1     :  Address of u8 variable to receive the passed keys value 
  Return         :  Error Status, options available in "Keypad.h" under the "Error type"
*/
Keypad_tenuStatus Keypad_enuGetKey(pu8 Copy_pu8PressedKey)
{
  Keypad_tenuStatus Loc_enuError = Keypad_enuOk;
  if(Copy_pu8PressedKey != NULL)
  {
    *Copy_pu8PressedKey = Keypad_u8PressedKey;
  }/* if */
  else
  {
    Loc_enuError = Keypad_enuNok;
  }/* else */
  return(Loc_enuError);/* returning the error status */
}/* Keypad_enuGetKey */
/* /////////////////////////////////////////////////////////////////////////////////// */
/* ////////////////////////////////// Runnable /////////////////////////////////////// */
/* 
  Description    :  Runnable to update the pressed key every 500 milliseconds
  Parameter(s)   :  void
  Return         :  void
  **Caution**    :  You have first to configure the rows pins as output and cols as input pull up
*/  
void Keypad_vidUpdateCurrentKey_R(void)
{
  u8 Loc_u8RowCounter, Loc_u8ColCounter, Loc_u8TempRowCounter;
  u8 Loc_u8PressedRow, Loc_u8PressedCol, Loc_u8PressedState;
  Switch_tenuState Loc_enuSwitchState;

  Loc_u8PressedState = FLAG_LOW;
  // write high on all rows 
  for(Loc_u8RowCounter = ZERO_INIT; Loc_u8RowCounter < KEYPAD_u8NO_ROWS; Loc_u8RowCounter++){
    Dio_enuWriteChannel(Keypad_strConfig.Rows[Loc_u8RowCounter], DIO_u8PIN_HIGH ^ KEYPAD_u8ACTIVE_STATE);
  }/* for */
  // read which col is pressed
  for(Loc_u8ColCounter = ZERO_INIT; Loc_u8ColCounter < KEYPAD_u8NO_COLS; Loc_u8ColCounter++)
  {
    Switch_enuGetState(Keypad_strConfig.Cols[Loc_u8RowCounter], &Loc_enuSwitchState);
    if(Loc_enuSwitchState == Switch_enuPressed)
    {
      Loc_u8PressedState = FLAG_HIGH;
      Loc_u8PressedCol = Loc_u8ColCounter;
    }/* if */
  }/* if */
  // loop on rows and read which row is pressed
  if(Loc_u8PressedState)
  {
    for(Loc_u8RowCounter = ZERO_INIT; Loc_u8RowCounter < KEYPAD_u8NO_ROWS; Loc_u8RowCounter++)
    {
      for(Loc_u8TempRowCounter = ZERO_INIT; Loc_u8TempRowCounter < KEYPAD_u8NO_ROWS; Loc_u8TempRowCounter++)
      {
        Dio_enuWriteChannel(Keypad_strConfig.Rows[Loc_u8RowCounter], DIO_u8PIN_LOW ^ KEYPAD_u8ACTIVE_STATE);
      }/* for */
      Dio_enuWriteChannel(Keypad_strConfig.Rows[Loc_u8RowCounter], DIO_u8PIN_HIGH ^ KEYPAD_u8ACTIVE_STATE);
      Switch_enuGetState(Keypad_strConfig.Cols[Loc_u8RowCounter], &Loc_enuSwitchState);
      if(Loc_enuSwitchState == Switch_enuPressed)
      {
        Loc_u8PressedRow = Loc_u8RowCounter;
        Keypad_u8PressedKey = Keypad_strConfig.Keys[Loc_u8PressedRow][Loc_u8PressedCol];
      }/* if */
    }/* for */
  }/* if */
  else
  {
    Keypad_u8PressedKey = KEYPAD_u8NO_PRESS;
  }/* else */
}/* Keypad_vidUpdateCurrentKey_R */
/* /////////////////////////////////////////////////////////////////////////////////// */
