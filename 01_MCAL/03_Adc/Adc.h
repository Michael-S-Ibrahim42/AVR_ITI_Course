/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 29, 2022
**       Version     :	V01
**       SWC         :	M_ADC
**       Description :	ADC module files
** **************************************************************************************/
#ifndef _ADC_H
#define _ADC_H

  /* ****************************** MACROS *********************************************** */
  /* Channel Selection */
  #define ADC_u8CHANNEL_0                                                    (u8)(0b00000000)
  #define ADC_u8CHANNEL_1                                                    (u8)(0b00000001)
  #define ADC_u8CHANNEL_2                                                    (u8)(0b00000010)
  #define ADC_u8CHANNEL_3                                                    (u8)(0b00000011)
  #define ADC_u8CHANNEL_4                                                    (u8)(0b00000100)
  #define ADC_u8CHANNEL_5                                                    (u8)(0b00000101)
  #define ADC_u8CHANNEL_6                                                    (u8)(0b00000110)
  #define ADC_u8CHANNEL_7                                                    (u8)(0b00000111)
  /* ************************************************************************************** */
  
  /* **************************** Defined Types ******************************************* */
  /* Error type */
  typedef enum
  {
    Adc_enuStatus_Ok,
    Adc_enuStatus_Nok
  }Adc_enuStatus_t;
  /* ADC Buffer type */
  typedef struct
  {
    pu16 Buffer;
    u16 Index;
    u16 Size;
  }Adc_strBuffer_t;
  /* ************************************************************************************** */
  
  /* **************************** Interface Fns ******************************************* */
  /* 
    Fn          :       Initialize the ADC module
    Parameter   :       void
    return      :       Return error status, options are in "M_ADC.h" under "Error type"
  */
  Adc_enuStatus_t Adc_enuInit(void);
  /* 
    Fn          :       Start the ADC conversion
    Parameter1  :       Pointer to the buffer
    return      :       Return error status, options are in "M_ADC.h" under "Error type"
  */
  Adc_enuStatus_t Adc_enuStart(u8 Copy_u8Channel, Adc_strBuffer_t* Copy_pstrBuffer);
  /* 
    Fn          :       Register the callback Fn
    Parameter1  :       The channel number, options are in "Adc.h"
    Parameter2  :       Pointer to the callback fn
    return      :       Return error status, options are in "Adc.h" under "Error type"
  */
  Adc_enuStatus_t Adc_enuRegisterCallback(u8 Copy_u8Channel, tpfCallbackFn Copy_pfCallback);
  /* ************************************************************************************** */

#endif
