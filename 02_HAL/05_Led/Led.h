/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 24, 2022
**       Version     :	V01
**       SWC         :	H_LED
**       Description :	Led module files
** **************************************************************************************/
#ifndef LED_H
#define LED_H
  /* ********************************* Inclusion Part ************************************* */
  #include "Led_cfg.h"
  /* ********************************************************************************* */
  /* **************************** MACROS ********************************************* */
  /* led connection active state */                 
  #define LED_u8ACTIVE_HIGH_STATE                     1
  #define LED_u8ACTIVE_LOW_STATE                      0
  /* ********************************************************************************* */
  /* **************************** Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    Led_enuStatus_Ok,
    Led_enuStatus_Nok
  }Led_enuStatus_t;
  /* Request options */
  typedef enum
  {
    Led_enuReq_On,
    Led_enuReq_Off,
    Led_enuReq_Idle,
    Led_enuReq_Blink,
    Led_enuReq_Toggle
  }Led_enuReq_t;
  /* Led Configurations */   
  typedef struct
  {
    u8  Pin;                 /* Options are in "Dio.h" under "Pins numbers"                     */
    u8  ActiveState;         /* Options are in "Led.h" under "led connection active state"    */
    Led_enuReq_t Request;    /* Options are in "Led.h" under "Request options", you should make it "Led_enuReq_Idle" in your config array*/
    u8 State;                /* You should initialize it by "ZERO_INIT" */  
    u16 LedPeriodicity;      /* You shouldn't configure it, It's just hold the led Periodicity */  
    u16 LedCounter;          /* You should initialize it by "ZERO_INIT" */  
  }Led_strCfg_t;  
  /* ********************************************************************************* */
  /* ****************************** Interface Fns Prototypes ************************* */
  /* 
    Fn         :   Set the lvl of specific led number
    Parameter1 :   Number of the specific led to control, Write leds number to pass in "Led_cfg.h" under "Connected Leds"
    Parameter2 :   Request of the Led, options are in "Led.h" under "Request options"
    Return     :   Error status of the fn, Error type is in "Led.h" under "Error Type"
  */
  extern Led_enuStatus_t Led_enuSetReq(u8 Copy_u8LedNum, Led_enuReq_t Copy_enuReq);
  /* 
    Description:   Set the periodicity of led blinking w.r.t blinking request
    Parameter1 :   Number of the specific led to control, Write leds number to pass in "Led_cfg.h" under "Connected Leds"
    Parameter2 :   the time in milliseconds to blink the led
    Parameter3 :   the periodicity of the led runnable
    Return     :   Error status of the fn, Error type is in "Led.h" under "Error Type"
  */
  extern Led_enuStatus_t Led_enuSetLedPeriodicity(u8 Copy_u8LedNum, u16 Copy_u16LedPeriodicity, u16 Copy_u16TaskPeriodicity);
  /* ///////////////////////////////////////////////////////////////////////////////// */

  /* /////////////////////////////// Runnable //////////////////////////////////////// */
  /* 
    Description   :   Task to master the Led
    Parameter(s)  :   void
    Return        :   void
    **Caution**   :   The leds must be initialized
  */
  extern void Led_vidMasterLed_R(void);
  /* ///////////////////////////////////////////////////////////////////////////////// */
#endif