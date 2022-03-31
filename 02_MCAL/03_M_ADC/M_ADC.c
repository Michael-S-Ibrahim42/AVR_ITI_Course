/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 29, 2022
**       Version     :	V01
**       SWC         :	M_ADC
**       Description :	ADC module files
** **************************************************************************************/
/* ******************************* Inclusion ******************************************** */
/* STD headers */
#include "avr/io.h"
#include "avr/interrupt.h"
/* LIB headers */
#include "Std_types.h"
/* Own headers */
#include "M_ADC.h"
#include "M_ADC_cfg.h"
#include "M_ADC_prv.h"
/* ************************************************************************************** */
/* ***************************** Global ************************************************* */
/* Global pointer to fn to point to the callback fn */
M_ADC_tpfCallback M_ADC_pfCallback;
/* ************************************************************************************** */
/* ****************************** Interface Fns ***************************************** */
/* 
  Fn          :       Initialize the ADC module
  Parameter   :       void
  return      :       Return error status, options are in "M_ADC.h" under "Error type"
*/
M_ADC_tenuError M_ADC_enuInit(void)
{
  M_ADC_tenuError Loc_enuError = M_ADC_enuOk;
  ADMUX = (M_ADC_u8INT_AVCC);
  ADCSRA = (M_ADC_u8ENABLE) | (M_ADC_u8ENABLE_AUTO_TRIG) | (M_ADC_u8ENABLE_INT) | (M_ADC_u8PRE_2);
  SFIOR = M_ADC_u8FREE_RUN;

  return(Loc_enuError);/* return the error status */
}/* M_ADC_enuInit */
/* 
  Fn          :       Select the channel
  Parameter   :       The channel to select, options are in "M_ADC.h" under "Channel Selection"
  return      :       Return error status, options are in "M_ADC.h" under "Error type"
*/
M_ADC_tenuError M_ADC_enuSelectChannel(u8 Copy_u8Channel)
{
  M_ADC_tenuError Loc_enuError = M_ADC_enuOk;
  if(Copy_u8Channel <= M_ADC_u8SEL_ADC7)
  {
    ADMUX &= ~M_ADC_u8CHANNEL;
    ADMUX |= Copy_u8Channel;
  }/* if */
  else
  {
    Loc_enuError = M_ADC_enuNok;
  }
  return(Loc_enuError);/* return the error status */
}/* M_ADC_enuReadResult */
/* 
  Fn          :       Start the ADC conversion
  Parameter   :       void
  return      :       Return error status, options are in "M_ADC.h" under "Error type"
*/
M_ADC_tenuError M_ADC_enuStart(void)
{
  M_ADC_tenuError Loc_enuError = M_ADC_enuOk;
  ADCSRA |= M_ADC_u8START_CONV;

  return(Loc_enuError);/* return the error status */
}/* M_ADC_enuStart */ 
/* 
  Fn          :       Blocking fn to read the ADC conversion result
  Parameter   :       Pointer to u16 to receive the result in it
  return      :       Return error status, options are in "M_ADC.h" under "Error type"
*/
M_ADC_tenuError M_ADC_enuReadResult(pu16 Copy_pu16Result)
{
  M_ADC_tenuError Loc_enuError = M_ADC_enuOk;
  while(ADCSRA&16 == 0);
  *Copy_pu16Result = (u16)ADCL | ((u16)ADCH<<8);
  ADCSRA |= 16;
  
  return(Loc_enuError);/* return the error status */
}/* M_ADC_enuStart */ 
/* 
  Fn          :       Registering the callback fn
  Parameter   :       pointer to fn, to send the callback fn address
  return      :       Return error status, options are in "M_ADC.h" under "Error type"
*/
M_ADC_tenuError M_ADC_enuRegCallbackFn(M_ADC_tpfCallback Copy_pfCallback)
{
  M_ADC_tenuError Loc_enuError = M_ADC_enuOk;
  if(Copy_pfCallback)
  {
    M_ADC_pfCallback = Copy_pfCallback;
  }/* if */ 
  else
  { 
    Loc_enuError = M_ADC_enuNok;
  }/* else */
  return(Loc_enuError);/* return the error status */
}/* M_ADC_enuRegCallbackFn */
/* ************************************************************************************** */
/* ************************************************************************************** */
ISR(ADC_vect)
{
  if(M_ADC_pfCallback)
  {
    M_ADC_pfCallback();
  }
}/* ISR ADC_vect */
/* ************************************************************************************** */