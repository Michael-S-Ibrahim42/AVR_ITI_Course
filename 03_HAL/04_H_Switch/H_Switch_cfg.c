/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 24, 2022
**       Version     :	V01
**       SWC         :	H_Switch
**       Description :	Switch module files
** **************************************************************************************/
/* *************************** Headers inclusion **************************************** */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "H_Switch.h"
#include "H_Switch_cfg.h"
/* *************************** Global Variables ***************************************** */
H_Switch_tstrSwConfig H_Switch_astrSysSwitches[] = {
  [H_SWITCH_u8VOLT_SELECT] = {
    .Pin      = DIO_u8PIN0,
    .State    = H_SWITCH_u8LVL_HIGH
  }
};
/* ************************************************************************************** */
