/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	SEV_SEG
**       Description :	Seven Segment module files
** **************************************************************************************/
#ifndef _SEVSEG_H
#define _SEVSEG_H
  /* ************************************************************************************** */
  /* ********************************** Defined Types ************************************* */
  /* Error type */
  typedef enum
  {
    SevSeg_enuOk,
    SevSeg_enuNok
  }SevSeg_tenuStatus;
  /* ************************************************************************************** */
  /* ********************************** Interface Fns  ************************************ */
  /* 
    Fn         : Display number on the seven segment(s)
    Parameter1 : The number to be displayed, accepted arguments are from 0.0 to 900.0
    Return     : The error status of type "SevSeg_tenuStatus", options are in SEVSEG.h under the section "Defined Types"
    **Caution**: The Pins Directiont must be configured
  */
  SevSeg_tenuStatus SevSeg_enuDispNum(f64 Copy_f64Number);

  /* ************************************************************************************** */
  /* ************************************************************************************** */


#endif
