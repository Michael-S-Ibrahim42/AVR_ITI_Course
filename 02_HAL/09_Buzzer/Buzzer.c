/* **************************************************************************************
**       Author      :	Michael & Yomna
**       Date        :	May 05, 2022
**       Version     :	V01
**       SWC         :	Buzzer
**       Description :	Buzzer component Module
** **************************************************************************************/
/* ****************************** Headers inclusion ******************************** */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
#include "Pwm.h"
/* Own headers */
#include "Buzzer.h"
#include "Buzzer_cfg.h"
#include "Buzzer_Lcfg.h"
#include "Buzzer_prv.h"
/* ///////////////////////////////////////////////////////////////////////////////// */

/* ****************************** Headers inclusion ******************************** */
static Buzzer_strToneBuff_t* Buzzer_astrToneBuff[BUZZER_u8NUM_OF_BUZZERS];
static u8 Buzzer_u8TaskPeriodicity = ZERO_INIT;
/* ///////////////////////////////////////////////////////////////////////////////// */

/* *************************** Interface Fns *************************************** */
/* 
  Fn         :   Set the request of specific Buzzer number
  Parameter1 :   Number of the specific Buzzer to control, Write Buzzers number to pass in "Buzzer_cfg.h" under "Connected Buzzers"
  Parameter2 :   Request of the Buzzer, options are in "Buzzer.h" under "Request options"
  Return     :   Error status of the fn, Error type is in "Buzzer.h" under "Error Type"
*/
Buzzer_enuStatus_t Buzzer_enuSetReq(u8 Copy_u8BuzzerNum, Buzzer_enuReq_t Copy_enuReq)
{
  Buzzer_enuStatus_t Loc_enuError = Buzzer_enuStatus_Ok;
  Buzzer_astrBuzzers[Copy_u8BuzzerNum].Request = Copy_enuReq;
   
  return(Loc_enuError);/* Returning the error status */
}/* Buzzer_enuSet */
/* 
  Description:   Set the periodicity of Buzzer blinking w.r.t blinking request
  Parameter1 :   Number of the specific Buzzer to control, Write Buzzers number to pass in "Buzzer_cfg.h" under "Connected Buzzers"
  Parameter2 :   Pointer to the tones buffer
  Parameter3 :   Buzzer Task Periodicity
  Return     :   Error status of the fn, Error type is in "Buzzer.h" under "Error Type"
*/
Buzzer_enuStatus_t Buzzer_enuSetTones(u8 Copy_u8BuzzerNum, Buzzer_strToneBuff_t* Copy_pstrToneBuff, u8 Copy_u8Periodicity)
{
  Buzzer_enuStatus_t Loc_enuError = Buzzer_enuStatus_Ok;
  if(Copy_pstrToneBuff != NULL)
  {
    Buzzer_u8TaskPeriodicity = Copy_u8Periodicity;
    Buzzer_astrToneBuff[Copy_u8BuzzerNum] = Copy_pstrToneBuff;
  }/* if */
  else 
  {
    Loc_enuError = Buzzer_enuStatus_Nok;
  }/* else */
  
  return(Loc_enuError);/* Returning the error status */
}/* Buzzer_enuSetBuzzerPeriodicity */

/* ********************************************************************************* */

/* /////////////////////////////// Runnable //////////////////////////////////////// */
/* 
  Description   :   Task to master the Buzzer
  Parameter(s)  :   void
  Return        :   void
*/
void Buzzer_vidMasterBuzzer_R(void)
{
  u8 Loc_u8Counter = ZERO_INIT;
  for(;Loc_u8Counter < BUZZER_u8NUM_OF_BUZZERS; Loc_u8Counter++)
  {
    switch(Buzzer_astrBuzzers[Loc_u8Counter].Request)
    {
    case(Buzzer_enuReq_Off):
      Buzzer_astrBuzzers[Loc_u8Counter].State = Buzzer_astrBuzzers[Loc_u8Counter].ActiveState ^ Buzzer_astrBuzzers[Loc_u8Counter].Request;
      Dio_enuWriteChannel(Buzzer_astrBuzzers[Loc_u8Counter].Pin, Buzzer_astrBuzzers[Loc_u8Counter].State);
      Buzzer_astrBuzzers[Loc_u8Counter].Request = Buzzer_enuReq_Idle;
      break;
    case(Buzzer_enuReq_On):
      Buzzer_astrBuzzers[Loc_u8Counter].State = Buzzer_astrBuzzers[Loc_u8Counter].ActiveState ^ Buzzer_astrBuzzers[Loc_u8Counter].Request;
      Dio_enuWriteChannel(Buzzer_astrBuzzers[Loc_u8Counter].Pin, Buzzer_astrBuzzers[Loc_u8Counter].State);
      Buzzer_astrBuzzers[Loc_u8Counter].Request = Buzzer_enuReq_Idle;
      break;
    case(Buzzer_enuReq_MultiTone):
      Buzzer_vidPlayTone(Loc_u8Counter);
      break;
    default:
      /* MISRA */
      break;
    }/* switch */
  }/* for */
}/* Buzzer_vidMasterBuzzer_R */
static void Buzzer_vidPlayTone(u8 Copy_u8BuzzerNum)
{
  if(Buzzer_astrBuzzers[Copy_u8BuzzerNum].BuzzerCounter == ZERO_INIT)
  {
    if(Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Frequency[Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Index] != ZERO_INIT)
    {
      Pwm_SetPeriodAndDuty(Buzzer_astrBuzzers[Copy_u8BuzzerNum].PwmChannel,  50, 1000/(Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Frequency[Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Index]));
    }/* if */
    else
    {
    	Pwm_SetOutputToIdle(Buzzer_astrBuzzers[Copy_u8BuzzerNum].PwmChannel);
    }
  }/* if */
  Buzzer_astrBuzzers[Copy_u8BuzzerNum].BuzzerCounter++;
  if(Buzzer_astrBuzzers[Copy_u8BuzzerNum].BuzzerCounter == (Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Duration[Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Index]/Buzzer_u8TaskPeriodicity))
  {
    Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Index++;
    Buzzer_astrBuzzers[Copy_u8BuzzerNum].BuzzerCounter = ZERO_INIT;
  }/* if */
  if(Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Index == Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Size)
  {
	  Buzzer_astrToneBuff[Copy_u8BuzzerNum]->Index = ZERO_INIT;
	  Buzzer_astrBuzzers[Copy_u8BuzzerNum].Request = Buzzer_enuReq_Idle;
    Pwm_SetOutputToIdle(Buzzer_astrBuzzers[Copy_u8BuzzerNum].PwmChannel);
  }/* if */
    
}/*  Buzzer_vidPlayTone_P */
/* ///////////////////////////////////////////////////////////////////////////////// */
