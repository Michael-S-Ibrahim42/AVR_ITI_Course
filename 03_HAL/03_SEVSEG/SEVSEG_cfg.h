/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	SEV_SEG
**       Description :	Seven Segment module files
** **************************************************************************************/
#ifndef _SEVSEG_CFG_H
#define _SEVSEG_CFG_H

  /* ************************************************************************************** */
  /* *************************** configuration MACROS ************************************* */
  /* Seven segment types */
  /* Options are: SEVSEG_COM_ANODE - SEVSEG_COM_CATHODE */
  #define SEVSEG_TYPE           SEVSEG_COM_CATHODE
  /* Options are: SEVSEG_SEG_ONE - SEVSEG_SEG_TWO - SEVSEG_SEG_THREE - SEVSEG_SEG_FOUR */
  #define SEVSEG_CONN_SEGS      SEVSEG_SEG_ONE
  /* Connection pins */
  #if(SEVSEG_CONN_SEGS >= SEVSEV_SEG_ONE)
    #define SEVSEG0_A           DIO_u8PIN0
    #define SEVSEG0_B           DIO_u8PIN1
    #define SEVSEG0_C           DIO_u8PIN2
    #define SEVSEG0_D           DIO_u8PIN3
    #define SEVSEG0_E           DIO_u8PIN4
    #define SEVSEG0_F           DIO_u8PIN5
    #define SEVSEG0_G           DIO_u8PIN6
    #define SEVSEG0_DOT         DIO_u8PIN7
  #endif
  #if(SEVSEG_CONN_SEGS >= SEVSEV_SEG_TWO)
    #define SEVSEG1_A           DIO_u8PIN8
    #define SEVSEG1_B           DIO_u8PIN9
    #define SEVSEG1_C           DIO_u8PIN10
    #define SEVSEG1_D           DIO_u8PIN11
    #define SEVSEG1_E           DIO_u8PIN12
    #define SEVSEG1_F           DIO_u8PIN13
    #define SEVSEG1_G           DIO_u8PIN14
    #define SEVSEG1_DOT         DIO_u8PIN15
  #endif
  #if(SEVSEG_CONN_SEGS >= SEVSEV_SEG_THREE)
    #define SEVSEG2_A           DIO_u8PIN16
    #define SEVSEG2_B           DIO_u8PIN17
    #define SEVSEG2_C           DIO_u8PIN18
    #define SEVSEG2_D           DIO_u8PIN19
    #define SEVSEG2_E           DIO_u8PIN20
    #define SEVSEG2_F           DIO_u8PIN21
    #define SEVSEG2_G           DIO_u8PIN22
    #define SEVSEG2_DOT         DIO_u8PIN23
  #endif
  #if(SEVSEG_CONN_SEGS >= SEVSEV_SEG_FOUR)
    #define SEVSEG3_A           DIO_u8PIN24
    #define SEVSEG3_B           DIO_u8PIN25
    #define SEVSEG3_C           DIO_u8PIN26
    #define SEVSEG3_D           DIO_u8PIN27
    #define SEVSEG3_E           DIO_u8PIN28
    #define SEVSEG3_F           DIO_u8PIN29
    #define SEVSEG3_G           DIO_u8PIN30
    #define SEVSEG3_DOT         DIO_u8PIN31
  #endif
  /* ************************************************************************************** */
  /* ************************************************************************************** */

#endif
