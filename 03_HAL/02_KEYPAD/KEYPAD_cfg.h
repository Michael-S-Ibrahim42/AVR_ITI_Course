/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	KEYPAD
**       Description :	Keypad module
** **************************************************************************************/
#ifndef _KEYPAD_CFG_H
#define _KEYPAD_CFG_H
  /* *********************************************************************************** */
  /* ********************************* HW MACROS          ****************************** */
  /* HW Connection Pins */
  #define KEYPAD_u8R0                    DIO_u8PIN24
  #define KEYPAD_u8R1                    DIO_u8PIN25
  #define KEYPAD_u8R2                    DIO_u8PIN26
  #define KEYPAD_u8R3                    DIO_u8PIN27
  #define KEYPAD_u8C0                    DIO_u8PIN28
  #define KEYPAD_u8C1                    DIO_u8PIN29
  #define KEYPAD_u8C2                    DIO_u8PIN30
  #define KEYPAD_u8C3                    DIO_u8PIN31
  /* Keypad Pattern */
  #define KEYPAD_u8R0C0                  '7'                      //    7 8 9 *                                   
  #define KEYPAD_u8R0C1                  '8'                      //    4 5 6 /                  
  #define KEYPAD_u8R0C2                  '9'                      //    1 2 3 +                  
  #define KEYPAD_u8R0C3                  '*'                      //    = 0 . -
  #define KEYPAD_u8R1C0                  '4'
  #define KEYPAD_u8R1C1                  '5'
  #define KEYPAD_u8R1C2                  '6'
  #define KEYPAD_u8R1C3                  '/'
  #define KEYPAD_u8R2C0                  '1'
  #define KEYPAD_u8R2C1                  '2'
  #define KEYPAD_u8R2C2                  '3'
  #define KEYPAD_u8R2C3                  '+'
  #define KEYPAD_u8R3C0                  '='
  #define KEYPAD_u8R3C1                  '0'
  #define KEYPAD_u8R3C2                  '.'
  #define KEYPAD_u8R3C3                  '-'
  /* *********************************************************************************** */
  /* *********************************************************************************** */
        
#endif
