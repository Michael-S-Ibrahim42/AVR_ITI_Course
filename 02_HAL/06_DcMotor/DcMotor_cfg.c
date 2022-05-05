/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 16, 2022
**       Version     :	V01
**       SWC         :	DcMotor
**       Description :	DcMotor software component
** **************************************************************************************/
/* ////////////////////////////////////// Headers inclusion ///////////////////////////////// */
#include "Std_types.h"
#include "Dio.h"
#include "Pwm.h"
#include "DcMotor.h"
#include "DcMotor_cfg.h"
#include "DcMotor_prv.h"
/* ////////////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////////// Configuration array //////////////////////////////// */
DcMotor_tstrConfig DcMotor_astrMotorConfig[] = 
{
  [DCMOTOR_u8MOTOR_ONE] =
  {
    .u8PinLeft  = DIO_u8PIN0,
    .u8PinRight = DIO_u8PIN1,
    .u8SpeedPin = PWM_u8CHANNEL1A
  }
};
/* ////////////////////////////////////////////////////////////////////////////////////////// */
