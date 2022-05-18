/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 29, 2022
**       Version     :	V01
**       SWC         :	M_ADC
**       Description :	ADC module files
** **************************************************************************************/
#ifndef _M_ADC_CFG_H
#define _M_ADC_CFG_H
  /* ************************************************************************************** */
  /* Select Voltage Reference */  
  /* Options are "ADC_u8AREF" or "ADC_u8AVCC" or "ADC_u8INTERNAL_2_56" */
  #define ADC_u8VOLT_REF                    ADC_u8AVCC
  /* Select prescalar value */
  /* options are ADC_u8PRE_x where x is 2,4,8,16,32,64,128 */
  #define ADC_u8PRESCALAR                   ADC_u8PRE_2
  /* ************************************************************************************** */
#endif