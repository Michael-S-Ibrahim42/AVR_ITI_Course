/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 24, 2022
**       Version     :	V01
**       SWC         :	H_LED
**       Description :	Led module files
** **************************************************************************************/
#ifndef _H_LED_H
#define _H_LED_H
  /* ********************************* Inclusion Part ************************************* */
  #include "H_Led_cfg.h"
  /* ********************************************************************************* */
  /* **************************** MACROS ********************************************* */
  /* Led levels */ 
  #define H_LED_u8ON                                    0
  #define H_LED_u8OFF                                   1
  /* led connection active state */                 
  #define H_LED_u8HIGH_ACTIVE_STATE                     1
  #define H_LED_u8LOW_ACTIVE_STATE                      0
  /* ********************************************************************************* */
  /* **************************** Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    H_Led_enuOk,
    H_Led_enuNok
  }H_Led_tenuStatus;
  /* Led Configurations */
  typedef struct
  {
    u8  Pin;                 /* Options are in "Dio.h" under "Pins numbers"                     */
    u8  ActiveState;         /* Options are in "H_Led.h" under "led connection active state"    */
  }H_Led_tstrCfg;  
  /* ********************************************************************************* */
  /* ****************************** Interface Fns Prototypes ************************* */
  /* 
    Fn         :   Set the lvl of specific led number
    Parameter1 :   Number of the specific led to control, Write leds number to pass in "H_Led_cfg.h" under "Connected Leds"
    Parameter2 :   Level of the LED, options are in "H_Led.h" under "Led levels"
    Return     :   Error status of the fn, Error type is in "H_Led.h" under "Error Type"
    **Caution**:   The leds must be initialized
  */
  extern H_Led_tenuStatus H_Led_enuSet(u8 Copy_u8LedNum, u8 Copy_u8LedLvl);
  /* ********************************************************************************* */
#endif