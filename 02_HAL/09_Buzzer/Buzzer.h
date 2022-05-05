/* **************************************************************************************
**       Author      :	Michael & Yomna
**       Date        :	May 05, 2022
**       Version     :	V01
**       SWC         :	Buzzer
**       Description :	Buzzer component Module
** **************************************************************************************/
#ifndef _BUZZER_H
#define _BUZZER_H
  /* ********************************* Inclusion Part ************************************* */
  #include "Buzzer_Lcfg.h"
  /* ********************************************************************************* */
  /* **************************** MACROS ********************************************* */
  /* Buzzer connection active state */                 
  #define BUZZER_u8ACTIVE_HIGH_STATE                     1
  #define BUZZER_u8ACTIVE_LOW_STATE                      0
  /* ********************************************************************************* */
  /* **************************** Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    Buzzer_enuStatus_Ok,
    Buzzer_enuStatus_Nok
  }Buzzer_enuStatus_t;
  /* Request options */
  typedef enum
  {
    Buzzer_enuReq_On,
    Buzzer_enuReq_Off,
    Buzzer_enuReq_Idle,
    Buzzer_enuReq_MultiTone /* Call the tone setter fn first */
  }Buzzer_enuReq_t;
  /* Status options */
  typedef enum
  {
    Buzzer_enuStatus_Ready, 
    Buzzer_enuStatus_Busy
  }Buzzer_enuStatus_t;
  /* Buzzer Configurations */   
  typedef struct
  {
    u8                 Pin;                  /* Options are in "Dio.h" under "Pins numbers" */
    u8                 PwmChannel;           /* Options are in "Pwm.h" under "Available Channels" */
    u8                 ActiveState;          /* Options are in "Buzzer.h" under "Buzzer connection active state"    */
    Buzzer_enuReq_t    Request;              /* Options are in "Buzzer.h" under "Request options", you should make it "Buzzer_enuReq_Idle" in your config array*/
    Buzzer_enuStatus_t Status;               /* Options are in "Buzzer.h" under "Status options" */  
    // u16                BuzzerPeriodicity;    /* You shouldn't configure it, It's just hold the Buzzer Periodicity */  
    u16                BuzzerCounter;        /* You should initialize it by "ZERO_INIT" */  
  }Buzzer_strCfg_t;  
  /* Tone Buffering type */
  typedef struct
  {
    u16*   Buffer;  /* Pointer the Tones buffer */
    u16    Size;    
    u16    Index;
    u16*   Duration; 
  }Buzzer_strToneBuff_t;
  /* ********************************************************************************* */

  /* ****************************** Interface Fns Prototypes ************************* */
  /* 
    Fn         :   Set the request of specific Buzzer number
    Parameter1 :   Number of the specific Buzzer to control, Write Buzzers number to pass in "Buzzer_cfg.h" under "Connected Buzzers"
    Parameter2 :   Request of the Buzzer, options are in "Buzzer.h" under "Request options"
    Return     :   Error status of the fn, Error type is in "Buzzer.h" under "Error Type"
  */
  extern Buzzer_enuStatus_t Buzzer_enuSetReq(u8 Copy_u8BuzzerNum, Buzzer_enuReq_t Copy_enuReq);
  /* 
    Description:   Set the periodicity of Buzzer blinking w.r.t blinking request
    Parameter1 :   Number of the specific Buzzer to control, Write Buzzers number to pass in "Buzzer_cfg.h" under "Connected Buzzers"
    Parameter2 :   Pointer to the tones buffer
    Return     :   Error status of the fn, Error type is in "Buzzer.h" under "Error Type"
  */
  extern Buzzer_enuStatus_t Buzzer_enuSetTones(u8 Copy_u8BuzzerNum, Buzzer_strToneBuff_t* Copy_pstrToneBuff);
  /* ///////////////////////////////////////////////////////////////////////////////// */

  /* /////////////////////////////// Runnable //////////////////////////////////////// */
  /* 
    Description   :   Task to master the Buzzer
    Parameter(s)  :   void
    Return        :   void
  */
  extern void Buzzer_vidMasterBuzzer_R(void);
  /* ///////////////////////////////////////////////////////////////////////////////// */
#endif