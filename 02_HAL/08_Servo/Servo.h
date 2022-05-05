/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	May 05, 2022
**       Version     :	V01
**       SWC         :	Servo
**       Description :	Servo component files
** **************************************************************************************/
#ifndef _SERVO_H
#define _SERVO_H
  /* //////////////////////////// Headers inclusion ////////////////////////////////// */
  #include "Servo_cfg.h"
  /* ///////////////////////////////////////////////////////////////////////////////// */

  /* //////////////////////////// Defined types ////////////////////////////////////// */
  typedef struct
  {
    u8  u8ChannelID;         /* set the channel ID, Options are in "Pwm.h" under "Available Channels" */
  }Servo_strConfig_t;
  /* ///////////////////////////////////////////////////////////////////////////////// */
  /* ///////////////////////////// Interface Fns ///////////////////////////////////// */
  /* 
    Description       :       Set the Servo angle
    Parameter1        :       The Servo Id
    Parameter2        :       The angle, range is from 0 to 180
    return            :       void
    *********** Synchronous ***********
  */  
  void Servo_vidSetServoAngle(u8 Copy_u8ServoId, u8 Copy_u8Angle);
  /* ///////////////////////////////////////////////////////////////////////////////// */
#endif