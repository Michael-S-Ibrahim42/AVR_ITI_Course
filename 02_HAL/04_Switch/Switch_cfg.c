/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 11, 2022
**       Version     :	V01
**       SWC         :	Switch
**       Description :	Switch module files
** **************************************************************************************/
/* *************************** Headers inclusion **************************************** */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "Switch.h"
#include "Switch_cfg.h"
/* ************************************************************************************** */

/* *************************** Global Variables ***************************************** */
Switch_tstrConfig Switch_astrSwitch[] = {
  [SWITCH_u8COL0] = {
    .Pin      = DIO_u8PIN0,
    .PullRes  = Switch_enuPullUp,
    .State    = Switch_enuReleased
  },
  [SWITCH_u8COL1] = {
    .Pin      = DIO_u8PIN1,
    .PullRes  = Switch_enuPullUp,
    .State    = Switch_enuReleased
  },
  [SWITCH_u8COL2] = {
    .Pin      = DIO_u8PIN2,
    .PullRes  = Switch_enuPullUp,
    .State    = Switch_enuReleased
  },
  [SWITCH_u8COL3] = {
    .Pin      = DIO_u8PIN3,
    .PullRes  = Switch_enuPullUp,
    .State    = Switch_enuReleased
  }
};
/* ************************************************************************************** */