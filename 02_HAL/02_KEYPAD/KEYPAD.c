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
#include "Bit_utils.h"
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
  Description    :  Runnable to update the pressed key every 5*NO_OF_Switch_Runnable
  Parameter(s)   :  void
  Return         :  void
 **Caution**     :  You have first to configure the rows pins as output and cols as input pull up
 */
void Keypad_vidUpdateCurrentKey_R(void)
{
	static u8 Loc_u8CurrentRow = ZERO_INIT;
	static Keypad_tenuState Loc_enuState = Keypad_enuWriting;
	u8 Loc_u8Mask, Loc_u8RowCounter, Loc_u8ColCounter, Loc_u8PressedState;
	Switch_tenuState Loc_enuSwitchState;

	switch(Loc_enuState){  
	case Keypad_enuWriting:
		Loc_u8Mask = ((u8)1<<Loc_u8CurrentRow);
		for(Loc_u8RowCounter = ZERO_INIT; Loc_u8RowCounter < KEYPAD_u8NO_ROWS; Loc_u8RowCounter++){
			Dio_enuWriteChannel(Keypad_strConfig.Rows[Loc_u8RowCounter], ((Loc_u8Mask>>Loc_u8RowCounter)&KEYPAD_u8FIRST_BIT_SLICER) ^ KEYPAD_u8ACTIVE_STATE);
		}
		Loc_enuState = Keypad_enuReading;
		break;
	case Keypad_enuReading:
		Loc_u8PressedState = FLAG_LOW;
		for(Loc_u8ColCounter = ZERO_INIT; Loc_u8ColCounter < KEYPAD_u8NO_COLS; Loc_u8ColCounter++){
			Switch_enuGetState(Keypad_strConfig.Cols[Loc_u8ColCounter], &Loc_enuSwitchState);
			if(Loc_enuSwitchState == Switch_enuPressed){
				Keypad_u8PressedKey = Keypad_strConfig.Keys[Loc_u8CurrentRow][Loc_u8ColCounter];
				Loc_u8PressedState  = FLAG_HIGH;
				Loc_u8CurrentRow = KEYPAD_u8NO_ROWS -1 ;
			}/* if */
		}/* for */
		Loc_u8CurrentRow++;
		if(Loc_u8CurrentRow == KEYPAD_u8NO_ROWS){
			if(Loc_u8PressedState != FLAG_HIGH){
				Keypad_u8PressedKey = KEYPAD_u8NO_PRESS;
			}
			Loc_u8CurrentRow = ZERO_INIT;
		}
		Loc_enuState = Keypad_enuWriting;
		break;
	default:
		/*	Misra	*/
		break;
	}
}/* Keypad_vidUpdateCurrentKey_R */
/* /////////////////////////////////////////////////////////////////////////////////// */
