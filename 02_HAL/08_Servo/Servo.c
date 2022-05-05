/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	May 05, 2022
**       Version     :	V01
**       SWC         :	Servo
**       Description :	Servo component files
** **************************************************************************************/
/* ////////////////////////////// Headers inclusion /////////////////////////////////////// */
/* LIB headers */
#include "Std_types.h"
#include "ATMEGA32A.h"
/* MCAL headers */
#include "Pwm.h"
/* Own headers */
#include "Servo.h"
#include "Servo_cfg.h"
#include "Servo_Lcfg.h"
#include "Servo_prv.h"
/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////////// Interface Fns ////////////////////////////////////// */
/* 
  Description       :       Set the Servo angle
  Parameter1        :       The Servo Id
  Parameter2        :       The angle, range is from 0 to 180
  return            :       void
  *********** Synchronous ***********
*/ 
void Servo_vidSetServoAngle(u8 Copy_u8ServoId, u8 Copy_u8Angle)
{
  f32 Loc_f32Duty = ((((Copy_u8Angle*2) / 180.0) + 0.5) * 100.0) / 20.0;
  Pwm_SetPeriodAndDuty(Servo_astrServos[Copy_u8ServoId].u8ChannelID, Loc_f32Duty, 20);
}/* Servo_vidSetServoAngle */
/* ////////////////////////////////////////////////////////////////////////////////////////// */
