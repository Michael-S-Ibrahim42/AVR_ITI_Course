/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	KEYPAD
**       Description :	Keypad module
** **************************************************************************************/
#ifndef _KEYPAD_PRV_H
#define _KEYPAD_PRV_H

  /* *********************************************************************************** */
  /* ******************************* General MACROS ************************************ */
  #define F_CPU				16000000
  #define KEYPAD_u8INIT_READ_VAR                0x00
  /* Number of keypad rows */
  #define KEYPAD_u8ROWS_NUM                     4
  /* Output value on rows */
  #define KEYPAD_u8ROWS_CHECK_VAL               0b0001
  /* Flag values */
  #define KEYPAD_u8FLAG_LOW                     0
  #define KEYPAD_u8FLAG_HIGH                    1
  /* Counter Value */
  #define KEYPAD_u8INIT_COUNT                   0x00
  /* Shift values */
  #define KEYPAD_u8ZERO_BIT_SHIFT               0 
  #define KEYPAD_u8ONE_BIT_SHIFT                1
  #define KEYPAD_u8TWO_BIT_SHIFT                2
  #define KEYPAD_u8THREE_BIT_SHIFT              3
  #define KEYPAD_u8FOUR_BIT_SHIFT               4
  /* Bit masks */
  #define KEYPAD_u8BIT0_MASK                    0x01
  #define KEYPAD_u8BIT1_MASK                    0x02
  #define KEYPAD_u8BIT2_MASK                    0x04
  #define KEYPAD_u8BIT3_MASK                    0x08
  /* Switch case values */
  #define KEYPAD_u8CASE_R0C0                    0x0E
  #define KEYPAD_u8CASE_R0C1                    0x0D
  #define KEYPAD_u8CASE_R0C2                    0x0B
  #define KEYPAD_u8CASE_R0C3                    0x07
  #define KEYPAD_u8CASE_R1C0                    0x1E
  #define KEYPAD_u8CASE_R1C1                    0x1D
  #define KEYPAD_u8CASE_R1C2                    0x1B
  #define KEYPAD_u8CASE_R1C3                    0x17
  #define KEYPAD_u8CASE_R2C0                    0x2E
  #define KEYPAD_u8CASE_R2C1                    0x2D
  #define KEYPAD_u8CASE_R2C2                    0x2B
  #define KEYPAD_u8CASE_R2C3                    0x27
  #define KEYPAD_u8CASE_R3C0                    0x3E
  #define KEYPAD_u8CASE_R3C1                    0x3D
  #define KEYPAD_u8CASE_R3C2                    0x3B
  #define KEYPAD_u8CASE_R3C3                    0x37
  /* *********************************************************************************** */
  /* *********************************************************************************** */

#endif
