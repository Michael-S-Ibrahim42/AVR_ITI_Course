/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 29, 2022
**       Version     :	V01
**       SWC         :	M_ADC
**       Description :	ADC module files
** **************************************************************************************/
#ifndef _M_ADC_PRV_H
#define _M_ADC_PRV_H
  /* ************************** MACROS **************************************************** */
  /* Reference Voltage Selection */
  #define M_ADC_u8EXT_VREF                            0b00000000
  #define M_ADC_u8INT_AVCC                            0b01000000  
  #define M_ADC_u8INT_2_56                            0b11000000
  /* Data adjustment */
  #define M_ADC_u8LEFT_ADJ                            0b00100000
  /* Enable ADC */
  #define M_ADC_u8ENABLE                              0b10000000
  /* Starting Conversion */ 
  #define M_ADC_u8START_CONV                          0b01000000
  /* Auto triggering selection */
  #define M_ADC_u8ENABLE_AUTO_TRIG                    0b00100000
  /* Interrupt Flag Mask */
  #define M_ADC_u8INT_FLAG                            0b00010000
  /* Enable Interrupt */
  #define M_ADC_u8ENABLE_INT                          0b00001000
  /* Prescalar selection */
  #define M_ADC_u8PRE_2                               0b00000001
  #define M_ADC_u8PRE_4                               0b00000010
  #define M_ADC_u8PRE_8                               0b00000011
  #define M_ADC_u8PRE_16                              0b00000100
  #define M_ADC_u8PRE_32                              0b00000101
  #define M_ADC_u8PRE_64                              0b00000110
  #define M_ADC_u8PRE_128                             0b00000111
  /* Tigger source */
  #define M_ADC_u8FREE_RUN                            0b00000000
  /* SET Masks */
  #define M_ADC_u8CHANNEL                             0b00000111
  /* ************************************************************************************** */
#endif