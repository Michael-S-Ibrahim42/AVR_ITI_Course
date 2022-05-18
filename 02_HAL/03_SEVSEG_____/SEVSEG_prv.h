/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 18, 2022
**       Version     :	V01
**       SWC         :	SEV_SEG
**       Description :	Seven Segment module files
** **************************************************************************************/
#ifndef _SEVSEG_PRV_H
#define _SEVSEG_PRV_H
  /* ************************************************************************************** */
  /* ****************************** MACROS ************************************************ */
  /* Number of seven segments */
  #define SEVSEG_SEG_ONE                  0
  #define SEVSEG_SEG_TWO                  1
  #define SEVSEG_SEG_THREE                2
  #define SEVSEG_SEG_FOUR                 3
  /* Seven Segment Types */
  #define SEVSEG_COM_CATHODE              0   
  #define SEVSEG_COM_ANODE                1
  /* Segments Numbers */
  #define SEVSEG0                         0
  #define SEVSEG1                         1
  #define SEVSEG2                         2
  #define SEVSEG3                         3
  /* Dot status */
  #define SEVSEG_DOT_OFF                  0
  #define SEVSEG_DOT_ON                   1
  /* Seven Segment Numbers */
  #if(SEVSEG_TYPE == SEVSEG_COM_ANODE)
    #define SEVSEG_NUM0                (u8)(~0x3F)      
    #define SEVSEG_NUM1                (u8)(~0x06)
    #define SEVSEG_NUM2                (u8)(~0x5B)
    #define SEVSEG_NUM3                (u8)(~0x4F)
    #define SEVSEG_NUM4                (u8)(~0x66)
    #define SEVSEG_NUM5                (u8)(~0x6D)
    #define SEVSEG_NUM6                (u8)(~0x7D)
    #define SEVSEG_NUM7                (u8)(~0x07)
    #define SEVSEG_NUM8                (u8)(~0x7F)
    #define SEVSEG_NUM9                (u8)(~0x67)
    #define SEVSEG_DOT                 (u8)(0x00)
  #elif(SEVSEG_TYPE == SEVSEG_COM_CATHODE)
    #define SEVSEG_NUM0                (u8)(0x3F)
    #define SEVSEG_NUM1                (u8)(0x06)
    #define SEVSEG_NUM2                (u8)(0x5B)
    #define SEVSEG_NUM3                (u8)(0x4F)
    #define SEVSEG_NUM4                (u8)(0x66)
    #define SEVSEG_NUM5                (u8)(0x6D)
    #define SEVSEG_NUM6                (u8)(0x7D)
    #define SEVSEG_NUM7                (u8)(0x07)
    #define SEVSEG_NUM8                (u8)(0x7F)
    #define SEVSEG_NUM9                (u8)(0x67)
    #define SEVSEG_DOT                 (u8)(0x01)
  #endif
  /* Bit Masks for shifting */
  #define SEVSEG_A_BIT                 0
  #define SEVSEG_B_BIT                 1
  #define SEVSEG_C_BIT                 2
  #define SEVSEG_D_BIT                 3
  #define SEVSEG_E_BIT                 4
  #define SEVSEG_F_BIT                 5
  #define SEVSEG_G_BIT                 6
  /* Bit Masks for set&clear */
  #define SEVSEG_BIT0_MASK             0x01
  /* Max Digit MACRO */
  #define SEVSEG_DIG_MAX               9
  /* Max Num MACRO */
  #define SEVSEG_NUM_MAX               900
  /* General MACROS */
  #define SEVSEG_NO_FRACTION           0
  #define SEVSEG_FIRST_DIG             10
  #define SEVSEG_SECOND_DIG            100
  #define SEVSEG_THIRD_DIG             1000
  #define SEVSEG_FOURTH_DIG            10000
  #define SEVSEG_FRAC_POINT_SHIFT      10
  /* ************************************************************************************** */
  /* ***************************** Private Fns Prototypes ********************************* */
  /* 
    Fn        : (Static Fn)Display Digit on the seven segment
    Parameter1: The Digit to be displayed, Options are from 0 to 9
    Parameter2: The Dot status, Options are in "SEVSEG_prv.h" under the section "Dot status"
    Parameter3: The Segment to be displayed on, Options are in "SEVSEG_prv.h" under the section "Segments Numbers"
    Return    : The error status of type "SevSeg_tenuStatus", options are in SEVSEG.h under the section "Error type"
  */
  static SevSeg_tenuStatus SevSeg_enuDispDigit(u8 Copy_u8Digit, u8 Copy_u8DotStatus, u8 Copy_u8SegNumber);
  /* ************************************************************************************** */
  /* ************************************************************************************** */


#endif
