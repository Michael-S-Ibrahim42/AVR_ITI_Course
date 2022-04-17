/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	Keypad
**       Description :	Keypad module
** **************************************************************************************/
#ifndef _KEYPAD_H
#define _KEYPAD_H
  /* ///////////////////////////////// Headers inclusion /////////////////////////////// */
  /* Own headers */
  #include "Keypad_cfg.h"
  /* /////////////////////////////////////////////////////////////////////////////////// */

  /* ///////////////////////////////// Defined Types ///////////////////////////////// */
  /* Error type */
  typedef enum
  {
    Keypad_enuOk,    /* The Key pressed catched */
    Keypad_enuNok
  }Keypad_tenuStatus;
  /* Keypad Configuration */
  typedef struct
  {
    u8 Rows[KEYPAD_u8NO_ROWS]; /* options are in "Dio.h" under "Pins numbers" */
    u8 Cols[KEYPAD_u8NO_COLS]; /* options are in "Switch_cfg.h" under "Connected Switches Names" */
    u8 Keys[KEYPAD_u8NO_ROWS][KEYPAD_u8NO_COLS]; /* Map your keypad */
  }Keypad_tstrConfig;
  /* /////////////////////////////////////////////////////////////////////////////////// */

  /* //////////////////////////////// MACROS //////////////////////////////////////////// */
  /* Active states */
  #define KEYPAD_u8ACTIVE_HIGH                                              0
  #define KEYPAD_u8ACTIVE_LOW                                               1
  /* ////////////////////////////////////////////////////////////////////////////////// */

  /* ///////////////////////////////// Interface Fns ////////////////////////////////// */
  /* 
    Description    :  Return the pressed key as character; one of the entered configurations
    Parameter1     :  Address of u8 variable to receive the passed keys value 
    Return         :  Error Status, options available in "Keypad.h" under the "Error type"
  */
  extern Keypad_tenuStatus Keypad_enuGetKey(pu8 Copy_pu8PressedKey);
  /* /////////////////////////////////////////////////////////////////////////////////// */
  /* ////////////////////////////////// Runnable /////////////////////////////////////// */
  /* 
    Description    :  Runnable to update the pressed key every 500 milliseconds
    Parameter(s)   :  void
    Return         :  void
    **Caution**    :  You have first to configure the rows pins as output and cols as input pull up
  */  
  extern void Keypad_vidUpdateCurrentKey_R(void);
  /* /////////////////////////////////////////////////////////////////////////////////// */
#endif