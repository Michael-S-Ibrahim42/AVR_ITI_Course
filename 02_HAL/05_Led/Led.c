/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 24, 2022
**       Version     :	V01
**       SWC         :	H_LED
**       Description :	Led module files
** **************************************************************************************/
/* ****************************** Headers inclusion ******************************** */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "Led.h"
#include "Led_cfg.h"
#include "Led_prv.h"
/* ///////////////////////////////////////////////////////////////////////////////// */

/* *************************** Interface Fns *************************************** */
/* 
  Fn         :   Set the lvl of specific led number
  Parameter1 :   Number of the specific led to control, Write leds number to pass in "Led_cfg.h" under "Connected Leds"
  Parameter2 :   Request of the Led, options are in "Led.h" under "Request options"
  Return     :   Error status of the fn, Error type is in "Led.h" under "Error Type"
*/
Led_enuStatus_t Led_enuSetReq(u8 Copy_u8LedNum, Led_enuReq_t Copy_enuReq)
{
  Led_enuStatus_t Loc_enuError = Led_enuStatus_Ok;
  Led_astrLeds[Copy_u8LedNum].Request = Copy_enuReq;
  
  return(Loc_enuError);/* Returning the error status */
}/* Led_enuSet */
/* 
  Description:   Set the periodicity of led blinking w.r.t blinking request
  Parameter1 :   Number of the specific led to control, Write leds number to pass in "Led_cfg.h" under "Connected Leds"
  Parameter2 :   the time in milliseconds to blink the led
  Parameter3 :   the periodicity of the led runnable
  Return     :   Error status of the fn, Error type is in "Led.h" under "Error Type"
*/
Led_enuStatus_t Led_enuSetLedPeriodicity(u8 Copy_u8LedNum, u16 Copy_u16LedPeriodicity, u16 Copy_u16TaskPeriodicity)
{
  Led_enuStatus_t Loc_enuError = Led_enuStatus_Ok;
  Led_astrLeds[Copy_u8LedNum].LedPeriodicity = Copy_u16LedPeriodicity/Copy_u16TaskPeriodicity;
  
  return(Loc_enuError);/* Returning the error status */
}/* Led_enuSetLedPeriodicity */

/* ********************************************************************************* */

/* /////////////////////////////// Runnable //////////////////////////////////////// */
/* 
  Description   :   Task to master the Led
  Parameter(s)  :   void
  Return        :   void
  **Caution**   :   The leds must be initialized
*/
void Led_vidMasterLed_R(void)
{
  u8 Loc_u8Counter = ZERO_INIT;
  for(;Loc_u8Counter < LED_u8NUM_OF_LEDS; Loc_u8Counter++)
  {
    switch(Led_astrLeds[Loc_u8Counter].Request)
    {
    case(Led_enuReq_Off):
      Led_astrLeds[Loc_u8Counter].State = Led_astrLeds[Loc_u8Counter].ActiveState ^ Led_astrLeds[Loc_u8Counter].Request;
      Dio_enuWriteChannel(Led_astrLeds[Loc_u8Counter].Pin, Led_astrLeds[Loc_u8Counter].State);
      Led_astrLeds[Loc_u8Counter].Request = Led_enuReq_Idle;
      break;
    case(Led_enuReq_On):
      Led_astrLeds[Loc_u8Counter].State = Led_astrLeds[Loc_u8Counter].ActiveState ^ Led_astrLeds[Loc_u8Counter].Request;
      Dio_enuWriteChannel(Led_astrLeds[Loc_u8Counter].Pin, Led_astrLeds[Loc_u8Counter].State);
      Led_astrLeds[Loc_u8Counter].Request = Led_enuReq_Idle;
      break;
    case(Led_enuReq_Toggle):
      Led_astrLeds[Loc_u8Counter].State ^= 1;
      Dio_enuWriteChannel(Led_astrLeds[Loc_u8Counter].Pin, Led_astrLeds[Loc_u8Counter].State);
      Led_astrLeds[Loc_u8Counter].Request = Led_enuReq_Idle;
      break;
    case(Led_enuReq_Blink):
      Led_astrLeds[Loc_u8Counter].LedCounter++;
      if(Led_astrLeds[Loc_u8Counter].LedCounter == Led_astrLeds[Loc_u8Counter].LedPeriodicity)
      {
        Led_astrLeds[Loc_u8Counter].State ^= 1;
        Dio_enuWriteChannel(Led_astrLeds[Loc_u8Counter].Pin, Led_astrLeds[Loc_u8Counter].State);
        Led_astrLeds[Loc_u8Counter].LedCounter = ZERO_INIT;
      }/* if */
      else 
      {
        /* MISRA */
      }/* else */
      break;
    default:
      /* MISRA */
      break;
    }/* switch */
  }/* for */
}/* Led_vidMasterLed_R */
/* ///////////////////////////////////////////////////////////////////////////////// */
