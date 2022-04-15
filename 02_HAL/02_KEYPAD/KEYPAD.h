/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	KEYPAD
**       Description :	Keypad module
** **************************************************************************************/
#ifndef _KEYPAD_H
#define _KEYPAD_H
  /* *********************************************************************************** */
  /* ********************************* Defined Types *********************************** */
  /* Error Status */
  typedef enum
  {
    Keypad_enuOk,/* The Key pressed catched */
    Keypad_enuNok,/* There is no pressed key */
    Keypad_enuNullPtr/* The passed pointer value equal null */
  }Keypad_tenuStatus;

  /* *********************************************************************************** */
  /* *************************** Interface Fns   *************************************** */
  /* 
    Description: Return the pressed key as character; one of the entered configurations
    Return     : Error Status, options available in KEYPAD.h under the "Error status" Section
    Parameter  : address of u8 variable to receive the passed keys value 
    ****Caution****: You have first to configure the rows pins as output and cols and input pull up
  */
  Keypad_tenuStatus Keypad_enuGetKey(pu8 Add_pu8PressedKey);

  /* *********************************************************************************** */
  /* *********************************************************************************** */

#endif