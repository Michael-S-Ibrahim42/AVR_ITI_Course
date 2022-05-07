/* **************************************************************************************
**       Author      :	Michael & Yomna
**       Date        :	May 07, 2022
**       Version     :	V01
**       SWC         :	Stepper
**       Description :	Stepper module files
** **************************************************************************************/
/* /////////////////////////// Headers inclusion ////////////////////////////////////// */
/* STD headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "Stepper.h"
#include "Stepper_cfg.h"
/* //////////////////////////////////////////////////////////////////////////////////////// */

/* /////////////////////////// Global Section ///////////////////////////////////////////// */
Stepper_strConfig_t Stepper_astrStepper[] =
{
  [STEPPER_u8STEPPER0] =
  {
    .Stepper_enuState     = Stepper_enuState_Available,
    .Stepper_enuDirection = Stepper_enuDirection_Clockwise,
    .u8PinA               = DIO_u8PIN0,
    .u8PinB               = DIO_u8PIN1, 
    .u8PinC               = DIO_u8PIN2, 
    .u8PinD               = DIO_u8PIN3, 
    .u16Steps             = ZERO_INIT,
    .u8Pattern            = STEPPER_u8START_PATTERN
  }
};
/* //////////////////////////////////////////////////////////////////////////////////////// */
