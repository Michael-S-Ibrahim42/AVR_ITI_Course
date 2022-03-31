/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 11, 2022
**       Version     :	V01
**       SWC         :	LCD
**       Description :	LCD module files
** **************************************************************************************/
#ifndef _LCD_PRV_H
#define _LCD_PRV_H


    /* ************************************************************************ */
    /* **************************** Private Masks ********************************** */
    /* Initial Values */
    #define LCD_u8LCD_NUM_INIT                  0
    /* Bit masks */
    #define LCD_u8BIT0                          0
    #define LCD_u8BIT1                          1
    #define LCD_u8BIT2                          2
    #define LCD_u8BIT3                          3
    #define LCD_u8BIT4                          4
    #define LCD_u8BIT5                          5
    #define LCD_u8BIT6                          6
    #define LCD_u8BIT7                          7
    /* Bit slicer mask */
    #define LCD_u8CMD_SPLIT                     0x1
    /* Number Divider */
    #define LCD_u8NUM_DIV                       10
    /* ASCII Shifter */
    #define LCD_u8LCD_ASCII_SHIFT               48
    /* MCU clock */
    #define  F_CPU                              16000000
    /* Delays */
    #define LCD_u8INIT_CMD1_DELAY               15
    #define LCD_u8INIT_CMD2_DELAY               5
    #define LCD_u8INIT_CMD3_DELAY               100
    #define LCD_u8DEFAULT_BIG_CMD_DELAY         5  
    #define LCD_u8DEFAULT_SMALL_CMD_DELAY       50
    /* Counter */
    #define LCD_u8CUSTOM_COUNTER_INIT           0
    #define LCD_u8CUSTOM_COUNTER_MAX           8
    /* String Terminator */
    #define LCD_u8NULL_CHAR                     '\0'
    /* ************************************************************************ */
    /* ************************************************************************ */
    













#endif
