/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 11, 2022
**       Version     :	V01
**       SWC         :	Switch
**       Description :	Switch module files
** **************************************************************************************/
#ifndef _SWITCH_H
#define _SWITCH_H
  /* ********************************* Inclusion Part ************************************* */
  #include "Switch_cfg.h"
  /* ************************************************************************************** */
  /* ********************************* Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    Switch_enuOk,
    Switch_enuNok,
    Switch_enuNullPtr
  }Switch_tenuError;
  /* Pull resistor */
  typedef enum
  {
    Switch_enuPullDown,
    Switch_enuPullUp
  }Switch_tenuPullRes;
  /* Switch state */
  typedef enum
  {
    Switch_enuPrePressed,
    Switch_enuPressed,
    Switch_enuPreReleased,
    Switch_enuReleased
  }Switch_tenuState;
  /* Switch Config */
  typedef struct
  {
    u16                Pin;        /*  Options in "Dio.h", under "Pins numbers" section             */
    u8                 PullRes;    /*  Options in "Switch.h", under "Switch_tenuPullRes" section   */
    Switch_tenuState   State;     /*  Options in "Switch.h", under "Switch State" section          */
    u8                 Counter;    /*  hold the value from 0 to 5 */
  }Switch_tstrConfig;
  /* ************************************************************************************** */
  /* **************************** Interface Fns ******************************************* */
  /* 
    Fn          : Init the switch which is defined in "Switch_cfg.c"
    Return      : The error status of type "Switch_tenuError", exist in "Switch.h" under "Error Type"
    **Caution** : The configuration files must be updated
  */
  extern Switch_tenuError Switch_enuInit(void);
  /* 
    Description : Get the switch last updated state
    Parameter1  : the switch, options are in "Switch_cfg.h" under the section "Connected Switches Names"
    Parameter2  : the switch State, options are in "Switch.h" under the section "Switch State"
    Return      : The error status of type "Switch_tenuError", exist in "Switch.h" under "Error Type"
  */
  extern Switch_tenuError Switch_enuGetState(u8 Copy_u8Switch, Switch_tenuState* Copy_penuState);
  /* ************************************************************************************** */
 
  /* ****************************** Runnables ********************************************* */
  /* 
    Runnable   :   Update State of the switches
    Parameters :   void
    Return     :   void
    **Caution**:   The switches must be initialized using "Switch_enuInit" before calling "Sched_vidStart"
  */  
  extern void Switch_vidUpdateState_R(void);
  /* ************************************************************************************** */
#endif