/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 24, 2022
**       Version     :	V01
**       SWC         :	H_Switch
**       Description :	Switch module files
** **************************************************************************************/
#ifndef _H_SWITCH_H
#define _H_SWITCH_H
  /* ********************************* Inclusion Part ************************************* */
  #include "H_Switch_cfg.h"
  /* ************************************************************************************** */
  /* ********************************* Defined Types ************************************** */
  /* Error Type */
  typedef enum
  {
    H_Switch_enuOk,
    H_Switch_enuNok
  }H_Switch_tenuStatus;
  /* Switch Config */
  typedef struct
  {
    u8 Pin;         /* Options in "Dio.h", under "Pins numbers" section  */
    u8 State;    /*  Options in "H_Switch.h", under "Switch Levels" */
  }H_Switch_tstrSwConfig;
  /* ************************************************************************************** */
  /* ******************************** Arguments MACROs ************************************ */
  /* Switch Levels */
  #define H_SWITCH_u8LVL_LOW                               0
  #define H_SWITCH_u8LVL_HIGH                              1
  /* ************************************************************************************** */
  /* **************************** Interface Fns ******************************************* */
  /* 
    Fn          : Read the switch value which is defined by the passed parameter. It also will handle the debouncing, it's synchronous fn
    Parameter1  : the switch, options are in "H_Switch_cfg.h" under the section "Connected Switches Names"
    Parameter2  : the switch lvl, options are in "H_Switch.h" under the section "Switch Levels"
    Return      : The error status of type "H_Switch_tenuStatus", exist in "H_Switch.h" under "Error Type"
  */
  H_Switch_tenuStatus H_Switch_enuReadSwitch(u8 Copy_u8Switch, pu8 Copy_pu8SwitchLvl);

  /* ************************************************************************************** */


#endif