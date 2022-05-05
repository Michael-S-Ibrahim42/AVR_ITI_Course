/* **************************************************************************************
**       Author      :	Michael & Yomna
**       Date        :	May 05, 2022
**       Version     :	V01
**       SWC         :	Buzzer
**       Description :	Buzzer component Module
** **************************************************************************************/
/* ***************************** Headers Inclusion ********************************* */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
#include "Pwm.h"
/* Own headers */
#include "Buzzer.h"
#include "Buzzer_cfg.h"
/* ******************** Configurations Variables *********************************** */
Buzzer_strCfg_t Buzzer_astrBuzzers[] = {
  [BUZZER_u8SONG] = {
    .Pin             = DIO_u8PIN0,     
    .PwmChannel      = PWM_u8CHANNEL1A,  
    .ActiveState     = Buzzer_u8ACTIVE_HIGH_STATE,     
    .Request         = Buzzer_enuReq_Idle,
    .Status          = Buzzer_enuStatus_Ready,
    .BuzzerCounter   = ZERO_INIT
  }
};
/* ********************************************************************************* */
