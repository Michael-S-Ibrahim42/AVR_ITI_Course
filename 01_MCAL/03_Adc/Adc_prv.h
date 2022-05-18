/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 29, 2022
**       Version     :	V01
**       SWC         :	M_ADC
**       Description :	ADC module files
** **************************************************************************************/
#ifndef _ADC_PRV_H
#define _ADC_PRV_H
  /* ************************** MACROS **************************************************** */
  /* Data adjustment */
  #define ADC_u8LEFT_ADJ                              (u8)(0b00100000)
  /* Enable ADC */
  #define ADC_u8ENABLE                                (u8)(0b10000000)
  /* Enable Interrupt */
  #define ADC_u8ENABLE_INT                            (u8)(0x08)
  /* Starting Conversion */ 
  #define ADC_u8START_CONV                            (u8)(0b01000000)
  /* Auto triggering selection */
  #define ADC_u8ENABLE_AUTO_TRIG                      (u8)(0b00100000)
  /* Tigger source */
  #define ADC_u8FREE_RUN                              (u8)(0b00000000)
  /* Masks */
  #define ADC_u8CHANNEL_MASK                          (u8)(0b00000111)
  /* Voltage reference options */
  #define ADC_u8AREF                                  (u8)(0b00000000)
  #define ADC_u8AVCC                                  (u8)(0b01000000)
  #define ADC_u8INTERNAL_2_56                         (u8)(0b11000000)       
  /* Prescalar values */
  #define ADC_u8PRE_2                                 (u8)(0x01)
  #define ADC_u8PRE_4                                 (u8)(0x02)
  #define ADC_u8PRE_8                                 (u8)(0x03)
  #define ADC_u8PRE_16                                (u8)(0x04)   
  #define ADC_u8PRE_32                                (u8)(0x05) 
  #define ADC_u8PRE_64                                (u8)(0x06) 
  #define ADC_u8PRE_128                               (u8)(0x07) 
  /* Number of channels */
  #define ADC_u8NO_CHANNEL                            (u8)(0x08)
  /* ************************************************************************************** */
  
  /* ////////////////////////////// Private Fns /////////////////////////////////////////// */
  /* 
    Fn          :       Select the channel
    Parameter   :       The channel to select, options are in "M_ADC.h" under "Channel Selection"
    return      :       Return error status, options are in "M_ADC.h" under "Error type"
  */
  static Adc_enuStatus_t Adc_enuSelectChannel(u8 Copy_u8Channel);
  /* ////////////////////////////////////////////////////////////////////////////////////// */

  /* ////////////////////////////// ISR /////////////////////////////////////////////////// */
  void __vector_16(void) __attribute__((signal,used));
  /* ////////////////////////////////////////////////////////////////////////////////////// */

#endif