/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 29, 2022
**       Version     :	V01
**       SWC         :	M_ADC
**       Description :	ADC module files
** **************************************************************************************/
/* ******************************* Inclusion ******************************************** */
/* LIB headers */
#include "Std_types.h"
#include "ATMEGA32A.h"
/* Own headers */
#include "Adc.h"
#include "Adc_cfg.h"
#include "Adc_prv.h"
/* ************************************************************************************** */

/* ***************************** Global ************************************************* */
/* Pointer to the buffer to store the adc values */
static Adc_strBuffer_t* Adc_pstrBuffer[ADC_u8NO_CHANNEL] = {NULL};
/* The current selected channel */
static u8 Adc_u8CurrentChannel = ZERO_INIT;
/* The Callback fn(called on half buffer completion) pointer */
static tpfCallbackFn Adc_pfCallback[ADC_u8NO_CHANNEL] = {NULL};
/* ************************************************************************************** */
/* ****************************** Interface Fns ***************************************** */
/* 
  Fn          :       Initialize the ADC module
  Parameter   :       void
  return      :       Return error status, options are in "M_ADC.h" under "Error type"
*/
Adc_enuStatus_t Adc_enuInit(void)
{
  Adc_enuStatus_t Loc_enuStatus = Adc_enuStatus_Ok;
  ADMUX  = (ADC_u8VOLT_REF);
  ADCSRA = (ADC_u8ENABLE) | (ADC_u8ENABLE_AUTO_TRIG) | (ADC_u8PRESCALAR) | (ADC_u8ENABLE_INT);
  SFIOR  = (ADC_u8FREE_RUN);

  return(Loc_enuStatus);/* return the error status */
}/* Adc_enuInit */
/* 
  Fn          :       Start the ADC conversion
  Parameter1  :       Pointer to the buffer
  return      :       Return error status, options are in "M_ADC.h" under "Error type"
*/
Adc_enuStatus_t Adc_enuStart(u8 Copy_u8Channel, Adc_strBuffer_t* Copy_pstrBuffer)
{
  Adc_enuStatus_t Loc_enuStatus = Adc_enuStatus_Ok;
  if(Copy_pstrBuffer != NULL)
  { 
    Adc_u8CurrentChannel = Copy_u8Channel;
    Adc_enuSelectChannel(Copy_u8Channel);
    Adc_pstrBuffer[Copy_u8Channel] = Copy_pstrBuffer;
    ADCSRA |= ADC_u8START_CONV;
  }/* if */
  else
  {
    Loc_enuStatus = Adc_enuStatus_Nok;
  }/* else */

  return(Loc_enuStatus);/* return the error status */
}/* Adc_enuStart */ 
/* 
  Fn          :       Register the callback Fn
  Parameter1  :       The channel number, options are in "Adc.h"
  Parameter2  :       Pointer to the callback fn
  return      :       Return error status, options are in "Adc.h" under "Error type"
*/
Adc_enuStatus_t Adc_enuRegisterCallback(u8 Copy_u8Channel, tpfCallbackFn Copy_pfCallback)
{
  Adc_enuStatus_t Loc_enuStatus = Adc_enuStatus_Ok;
  if(Copy_pfCallback != NULL)
  { 
    Adc_pfCallback[Copy_u8Channel] = Copy_pfCallback;
  }/* if */
  else
  {
    Loc_enuStatus = Adc_enuStatus_Nok;
  }/* else */

  return(Loc_enuStatus);/* return the error status */
}/* Adc_enuRegisterCallback */ 
/* 
  Fn          :       Select the channel
  Parameter   :       The channel to select, options are in "M_ADC.h" under "Channel Selection"
  return      :       Return error status, options are in "M_ADC.h" under "Error type"
*/
static Adc_enuStatus_t Adc_enuSelectChannel(u8 Copy_u8Channel)
{
  Adc_enuStatus_t Loc_enuStatus = Adc_enuStatus_Ok;
  if(Copy_u8Channel <= ADC_u8CHANNEL_7)
  {
    ADMUX &= ~ADC_u8CHANNEL_MASK;
    ADMUX |= Copy_u8Channel;
  }/* if */
  else
  {
    Loc_enuStatus = Adc_enuStatus_Nok;
  }
  return(Loc_enuStatus);/* return the error status */
}/* Adc_enuSelectChannel */
/* ************************************************************************************** */

/* ************************************************************************************** */
void __vector_16(void)
{   
  Adc_pstrBuffer[Adc_u8CurrentChannel]->Buffer[Adc_pstrBuffer[Adc_u8CurrentChannel]->Index] = ((u16)ADCL | ((u16)ADCH<<8));
  Adc_pstrBuffer[Adc_u8CurrentChannel]->Index++;
  if(Adc_pstrBuffer[Adc_u8CurrentChannel]->Index == (Adc_pstrBuffer[Adc_u8CurrentChannel]->Size / 2))
  {
    if(Adc_pfCallback[Adc_u8CurrentChannel])
    {
      Adc_pfCallback[Adc_u8CurrentChannel]();
    }/* if */
  }/* if */
  else if(Adc_pstrBuffer[Adc_u8CurrentChannel]->Index == Adc_pstrBuffer[Adc_u8CurrentChannel]->Size)
  {
    if(Adc_pfCallback[Adc_u8CurrentChannel])
    {
      Adc_pfCallback[Adc_u8CurrentChannel]();
    }/* if */
    Adc_pstrBuffer[Adc_u8CurrentChannel]->Index = ZERO_INIT;
  }/* if */  
  else
  {
    /* MISRA */
  }/* else */

}/* ADC ISR */
/* ************************************************************************************** */
