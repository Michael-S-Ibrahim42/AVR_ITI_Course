/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	KEYPAD
**       Description :	Keypad module
** **************************************************************************************/
#ifndef _KEYPAD_PRV_H
#define _KEYPAD_PRV_H
  /* ////////////////////////////// Defined types ///////////////////////////////////// */
  typedef enum {
    Keypad_enuWriting,
    Keypad_enuReading
  }Keypad_tenuState;
  /* ////////////////////////////////////////////////////////////////////////////////// */
  
  /* ///////////////////////////// MACROS ///////////////////////////////////////////// */
  #define KEYPAD_u8FIRST_BIT_SLICER                   0x01
  /* ////////////////////////////////////////////////////////////////////////////////// */
#endif
