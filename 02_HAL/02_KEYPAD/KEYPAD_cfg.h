/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	KEYPAD
**       Description :	Keypad module
** **************************************************************************************/
#ifndef _KEYPAD_CFG_H
#define _KEYPAD_CFG_H
  /* ////////////////////////////////// MACROS ///////////////////////////////////// */
  /* Number of rows and cols */
  /* Available options are from 1 and step is 1 */
  #define KEYPAD_u8NO_ROWS                  ((u8)4)
  #define KEYPAD_u8NO_COLS                  ((u8)4)
  /* the Connection Active state  */
  /* Available options are in "Keypad.h" under "Active states" */
  #define KEYPAD_u8ACTIVE_STATE             KEYPAD_u8ACTIVE_LOW
  /* *********************************************************************************** */        
#endif
