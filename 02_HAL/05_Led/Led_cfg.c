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
#include "Led.h"
#include "Led_cfg.h"
/* ******************** Configurations Variables *********************************** */
Led_strCfg_t Led_astrLeds[] = {
  [LED_u8BLUE] = {
    .Pin          = DIO_u8PIN0,       
    .ActiveState  = LED_u8ACTIVE_HIGH_STATE,     
    .Request      = Led_enuReq_Idle,
    .State        = ZERO_INIT,
    .LedCounter   = ZERO_INIT
  },
};
/* ********************************************************************************* */
