/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	SEV_SEG
**       Description :	Seven Segment module files
** **************************************************************************************/
/* ************************************************************************************** */
/* ********************************* Inclusion Part ************************************* */
/* STD Headers */
#include "Std_types.h"
/* MCAL Headers */
#include "Dio.h"
/* Own Headers */
#include "SEVSEG.h"
#include "SEVSEG_cfg.h"
#include "SEVSEG_prv.h"

/* ************************************************************************************** */
/* ************************************ Interface Fns *********************************** */
/* 
    Fn         : Display number on the seven segment(s)
    Parameter1 : The number to be displayed, accepted arguments are from 0.0 to 900.0
    Return     : The error status of type "SevSeg_tenuStatus", options are in SEVSEG.h under the section "Defined Types"
    **Caution**: The Pins Directiont must be configured
*/
SevSeg_tenuStatus SevSeg_enuDispNum(f64 Copy_f64Number)
{
  u64 Loc_u64Number;
  SevSeg_tenuStatus Loc_enuError = SevSeg_enuOk;

  if(Copy_f64Number > SEVSEG_NUM_MAX)
  {
    Loc_enuError = SevSeg_enuNok;
  }/* if */
  else
  {
    if((Copy_f64Number - (u64)Copy_f64Number) == SEVSEG_NO_FRACTION)/* Float part = 0 */
    {
      Loc_u64Number = (u64)Copy_f64Number;
      SevSeg_enuDispDigit((u8)(Loc_u64Number%SEVSEG_FIRST_DIG) , SEVSEG_DOT_ON, SEVSEG0);
      Loc_u64Number /= SEVSEG_FIRST_DIG;
      SevSeg_enuDispDigit((u8)(Loc_u64Number%SEVSEG_FIRST_DIG) , SEVSEG_DOT_OFF, SEVSEG1);
      Loc_u64Number /= SEVSEG_FIRST_DIG;
      SevSeg_enuDispDigit((u8)(Loc_u64Number%SEVSEG_FIRST_DIG) , SEVSEG_DOT_OFF, SEVSEG2);
      Loc_u64Number /= SEVSEG_FIRST_DIG;
      SevSeg_enuDispDigit((u8)(Loc_u64Number%SEVSEG_FIRST_DIG) , SEVSEG_DOT_OFF, SEVSEG3);
    }/* if */
    else/* Float part > 0 */
    {
      Copy_f64Number *= SEVSEG_FRAC_POINT_SHIFT;
      Loc_u64Number = (u64)Copy_f64Number;
      SevSeg_enuDispDigit((u8)(Loc_u64Number%SEVSEG_FIRST_DIG) , SEVSEG_DOT_OFF, SEVSEG0);
      Loc_u64Number /= SEVSEG_FIRST_DIG;
      SevSeg_enuDispDigit((u8)(Loc_u64Number%SEVSEG_FIRST_DIG) , SEVSEG_DOT_ON, SEVSEG1);
      Loc_u64Number /= SEVSEG_FIRST_DIG;
      SevSeg_enuDispDigit((u8)(Loc_u64Number%SEVSEG_FIRST_DIG) , SEVSEG_DOT_OFF, SEVSEG2);
      Loc_u64Number /= SEVSEG_FIRST_DIG;
      SevSeg_enuDispDigit((u8)(Loc_u64Number%SEVSEG_FIRST_DIG) , SEVSEG_DOT_OFF, SEVSEG3);
    }/* else */
  }/* else */

  return(Loc_enuError);
}/* SevSeg_enuDispNum */
/* ************************************************************************************** */
/* ******************************** Static Fns ****************************************** */
/* 
  Fn        : (Static Fn)Display Digit on the seven segment
  Parameter1: The Digit to be displayed, Options are from 0 to 9
  Parameter2: The Dot status, Options are in "SEVSEG_prv.h" under the section "Dot status"
  Parameter3: The Segment to be displayed on, Options are in "SEVSEG_prv.h" under the section "Segments Numbers"
  Return    : The error status of type "SevSeg_tenuStatus", options are in SEVSEG.h under the section "Error type"
*/
static SevSeg_tenuStatus SevSeg_enuDispDigit(u8 Copy_u8Digit, u8 Copy_u8DotStatus, u8 Copy_u8SegNumber)
{
  SevSeg_tenuStatus Loc_enuError = SevSeg_enuOk;
  u8 Loc_au8Numbers[10] = {SEVSEG_NUM0, SEVSEG_NUM1, SEVSEG_NUM2, SEVSEG_NUM3, SEVSEG_NUM4, SEVSEG_NUM5, SEVSEG_NUM6 ,SEVSEG_NUM7, SEVSEG_NUM8, SEVSEG_NUM9};
  if((Copy_u8Digit > SEVSEG_DIG_MAX) || (Copy_u8DotStatus > SEVSEG_DOT_ON))
  {
    Loc_enuError = SevSeg_enuNok;
  }/* if */
  else
  { 
    if(Copy_u8SegNumber == SEVSEG0)
    {
      Dio_enuWriteChannel(SEVSEG0_A,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_A_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG0_B,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_B_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG0_C,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_C_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG0_D,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_D_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG0_E,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_E_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG0_F,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_F_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG0_G,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_G_BIT)&SEVSEG_BIT0_MASK);
      if(Copy_u8DotStatus == SEVSEG_DOT_OFF)
      {
        Dio_enuWriteChannel(SEVSEG0_DOT,   (~SEVSEG_DOT)&SEVSEG_BIT0_MASK);
      }/* if */
      else
      {
        Dio_enuWriteChannel(SEVSEG0_DOT,   SEVSEG_DOT);
      }/* else */
    }/* if */
    else if(Copy_u8SegNumber == SEVSEG1)
    {
      Dio_enuWriteChannel(SEVSEG1_A,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_A_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG1_B,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_B_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG1_C,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_C_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG1_D,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_D_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG1_E,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_E_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG1_F,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_F_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG1_G,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_G_BIT)&SEVSEG_BIT0_MASK);
      if(Copy_u8DotStatus == SEVSEG_DOT_OFF)
      {
        Dio_enuWriteChannel(SEVSEG1_DOT,   (~SEVSEG_DOT)&SEVSEG_BIT0_MASK);
      }/* if */
      else
      {
        Dio_enuWriteChannel(SEVSEG1_DOT,   SEVSEG_DOT);
      }/* else */
    }/* else if */
    else if(Copy_u8SegNumber == SEVSEG2)
    {
      Dio_enuWriteChannel(SEVSEG2_A,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_A_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG2_B,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_B_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG2_C,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_C_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG2_D,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_D_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG2_E,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_E_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG2_F,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_F_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG2_G,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_G_BIT)&SEVSEG_BIT0_MASK);
      if(Copy_u8DotStatus == SEVSEG_DOT_OFF)
      {
        Dio_enuWriteChannel(SEVSEG2_DOT,   (~SEVSEG_DOT)&SEVSEG_BIT0_MASK);
      }/* if */
      else
      {
        Dio_enuWriteChannel(SEVSEG2_DOT,   SEVSEG_DOT);
      }/* else */
    }/* else if */
    else if(Copy_u8SegNumber == SEVSEG3)
    {
      Dio_enuWriteChannel(SEVSEG3_A,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_A_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG3_B,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_B_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG3_C,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_C_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG3_D,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_D_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG3_E,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_E_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG3_F,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_F_BIT)&SEVSEG_BIT0_MASK);
      Dio_enuWriteChannel(SEVSEG3_G,   (Loc_au8Numbers[Copy_u8Digit]>>SEVSEG_G_BIT)&SEVSEG_BIT0_MASK);
      if(Copy_u8DotStatus == SEVSEG_DOT_OFF)
      {
        Dio_enuWriteChannel(SEVSEG3_DOT,   (~SEVSEG_DOT)&SEVSEG_BIT0_MASK);
      }/* if */
      else
      {
        Dio_enuWriteChannel(SEVSEG3_DOT,   SEVSEG_DOT);
      }/* else */
    }/* else if */
    else
    {
      Loc_enuError = SevSeg_enuNok;
    }/* else */        
  }/* else */

  return(Loc_enuError);
}/* SevSeg_enuDispNum */
/* ************************************************************************************** */
/* ************************************************************************************** */
