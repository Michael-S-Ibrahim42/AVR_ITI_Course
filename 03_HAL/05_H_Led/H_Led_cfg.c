/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 24, 2022
**       Version     :	V01
**       SWC         :	H_LED
**       Description :	Led module files
** **************************************************************************************/
/* ***************************** Headers Inclusion ********************************* */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "H_Led.h"
#include "H_Led_cfg.h"
/* ******************** Configurations Variables *********************************** */
const H_Led_tstrCfg H_Led_astrLeds[] = {
  [H_LED_u8BLUE] = {
    .Pin          = DIO_u8PIN0,       
    .ActiveState  = H_LED_u8HIGH_ACTIVE_STATE,     
  },
};
/* ********************************************************************************* */
