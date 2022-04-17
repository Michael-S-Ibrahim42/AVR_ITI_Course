/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	KEYPAD
**       Description :	Keypad module
** **************************************************************************************/
/* ///////////////////////// Headers inclusion /////////////////////////////////// */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "Keypad.h"
#include "Keypad_cfg.h"
#include "Keypad_prv.h"
/* /////////////////////////////////////////////////////////////////////////////// */

/* ////////////////////////// Global Variables /////////////////////////////////// */
const Keypad_tstrConfig Keypad_strConfig = 
{
  .Rows[KEYPAD_u8NO_ROWS] = 
  {
    DIO_u8PIN4,
    DIO_u8PIN5,
    DIO_u8PIN6,
    DIO_u8PIN7
  },
  .Cols[KEYPAD_u8NO_COLS] = 
  {
    SWITCH_u8COL0,
    SWITCH_u8COL1,
    SWITCH_u8COL2,
    SWITCH_u8COL3
  },
  .Keys[KEYPAD_u8NO_ROWS][KEYPAD_u8NO_COLS] =
  {
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'.','0','=','+'} 
  }
};
/* /////////////////////////////////////////////////////////////////////////////// */