/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 29, 2022
**       Version     :	V01
**       SWC         :	M_ADC
**       Description :	ADC module files
** **************************************************************************************/
#ifndef _M_ADC_H
#define _M_ADC_H

  /* ****************************** MACROS *********************************************** */
  /* Channel Selection */
  #define M_ADC_u8SEL_ADC0                            0b00000000
  #define M_ADC_u8SEL_ADC1                            0b00000001
  #define M_ADC_u8SEL_ADC2                            0b00000010
  #define M_ADC_u8SEL_ADC3                            0b00000011
  #define M_ADC_u8SEL_ADC4                            0b00000100
  #define M_ADC_u8SEL_ADC5                            0b00000101
  #define M_ADC_u8SEL_ADC6                            0b00000110
  #define M_ADC_u8SEL_ADC7                            0b00000111
  /* ************************************************************************************** */
  /* **************************** Defined Types ******************************************* */
  /* pointer to fn type */
  typedef void (*M_ADC_tpfCallback)(void);
  /* Error type */
  typedef enum
  {
    M_ADC_enuOk,
    M_ADC_enuNok
  }M_ADC_tenuError;
  /* ************************************************************************************** */
  /* **************************** Interface Fns ******************************************* */
  /* 
    Fn          :       Initialize the ADC module
    Parameter   :       void
    return      :       Return error status, options are in "M_ADC.h" under "Error type"
  */
  M_ADC_tenuError M_ADC_enuInit(void);
  /* 
    Fn          :       Select the channel
    Parameter   :       The channel to select, options are in "M_ADC.h" under "Channel Selection"
    return      :       Return error status, options are in "M_ADC.h" under "Error type"
  */
  M_ADC_tenuError M_ADC_enuSelectChannel(u8 Copy_u8Channel);
  /* 
    Fn          :       Start the ADC conversion
    Parameter   :       void
    return      :       Return error status, options are in "M_ADC.h" under "Error type"
  */
  M_ADC_tenuError M_ADC_enuStart(void); 
  /* 
    Fn          :       Blocking fn to read the ADC conversion result
    Parameter   :       Pointer to u16 to receive the result in it
    return      :       Return error status, options are in "M_ADC.h" under "Error type"
  */
  M_ADC_tenuError M_ADC_enuReadResult(pu16 Copy_pu16Result); 
  /* 
    Fn          :       Registering the callback fn
    Parameter   :       pointer to fn, to send the callback fn address
    return      :       Return error status, options are in "M_ADC.h" under "Error type"
  */
  M_ADC_tenuError M_ADC_enuRegCallbackFn(M_ADC_tpfCallback Copy_pfCallback); 
  /* ************************************************************************************** */
#endif