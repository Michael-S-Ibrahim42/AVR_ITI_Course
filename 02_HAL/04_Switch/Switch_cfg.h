/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 11, 2022
**       Version     :	V01
**       SWC         :	Switch
**       Description :	Switch module files
** **************************************************************************************/
#ifndef _SWITCH_CFG_H
#define _SWITCH_CFG_H
  /* **************************** Configurations MACROS *********************************** */
  /* Connected Switches Names */
  /* Add MACRO for each connected switch and assign a value starting from 0 to 255, the following are examples */
  #define SWITCH_u8COL0                                      0
  #define SWITCH_u8COL1                                      1
  #define SWITCH_u8COL2                                      2
  #define SWITCH_u8COL3                                      3
  /* Adjust the value only by the number of connected switches, max = 256 */
  #define SWITCH_u8BTN_NUM                                   4
  /* ************************************************************************************** */
#endif