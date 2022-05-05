/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	May 05, 2022
**       Version     :	V01
**       SWC         :	Servo
**       Description :	Servo component files
** **************************************************************************************/
/* /////////////////////////// Headers inclusion ////////////////////////////////////// */
/* STD headers */
#include "Std_types.h"
/* MCAL headers */
#include "Pwm.h"
/* Own headers */
#include "Servo.h"
#include "Servo_cfg.h"
/* //////////////////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////// Global Section ///////////////////////////////////////////// */
const Servo_strConfig_t Servo_astrServos[] = 
{
  [SERVO_u8SERVO0] =
  {
    .u8ChannelID = PWM_u8CHANNEL1A
  }
};
/* //////////////////////////////////////////////////////////////////////////////////////// */
