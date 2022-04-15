/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 11, 2022
**       Version     :	V01
**       SWC         :	LCD
**       Description :	LCD module files
** **************************************************************************************/
#ifndef _LCD_H
#define _LCD_H


    /* ************************************************************************ */
    /* **************************** Interface MACROS ************************** */
    /* Commands */
    #define LCD_u8CLEAR                         0x01
    #define LCD_u8RET_HOME                      0x02
    #define LCD_u8MODE_INC_SHFT                 0x07
    #define LCD_u8MODE_INC_NO_SHFT              0x06
    #define LCD_u8MODE_DEC_SHFT                 0x05
    #define LCD_u8MODE_DEC_NO_SHFT              0x04
    #define LCD_u8SET_DIS0_CUR0_BLINK0          0x08    
    #define LCD_u8SET_DIS0_CUR0_BLINK1          0x09    
    #define LCD_u8SET_DIS0_CUR1_BLINK0          0x0A    
    #define LCD_u8SET_DIS0_CUR1_BLINK1          0x0B    
    #define LCD_u8SET_DIS1_CUR0_BLINK0          0x0C    
    #define LCD_u8SET_DIS1_CUR0_BLINK1          0x0D    
    #define LCD_u8SET_DIS1_CUR1_BLINK0          0x0E    
    #define LCD_u8SET_DIS1_CUR1_BLINK1          0x0F    
    #define LCD_u8SHFT_CUR_LEFT                 0x10  
    #define LCD_u8SHFT_CUR_RIGHT                0x14 
    #define LCD_u8SHFT_DISP_LEFT                0x18 
    #define LCD_u8SHFT_DISP_RIGHT               0x1C
    #define LCD_u8FN_DL4_N1_F8                  0x20
    #define LCD_u8FN_DL4_N1_F11                 0x24                 
    #define LCD_u8FN_DL4_N2_F8                  0x28
    #define LCD_u8FN_DL4_N2_F11                 0x2C
    #define LCD_u8FN_DL8_N1_F8                  0x30
    #define LCD_u8FN_DL8_N1_F11                 0x34
    #define LCD_u8FN_DL8_N2_F8                  0x38
    #define LCD_u8FN_DL8_N2_F11                 0x3C
    #define LCD_u8CGRAM_ADD_SET                 0x40
    #define LCD_u8DDRAM_ADD_SET                 0x80
    /* Custom Characters Creation Addresses */
    #define LCD_u8CGRAM_CH0                     0x00
    #define LCD_u8CGRAM_CH1                     0x08   
    #define LCD_u8CGRAM_CH2                     0x10
    #define LCD_u8CGRAM_CH3                     0x18          
    #define LCD_u8CGRAM_CH4                     0x20      
    #define LCD_u8CGRAM_CH5                     0x28          
    #define LCD_u8CGRAM_CH6                     0x30             
    #define LCD_u8CGRAM_CH7                     0x38
    /* Custom Characters Display Addresses */
    #define LCD_u8CGRAM_CODE0                   0x0
    #define LCD_u8CGRAM_CODE1                   0x1
    #define LCD_u8CGRAM_CODE2                   0x2
    #define LCD_u8CGRAM_CODE3                   0x3
    #define LCD_u8CGRAM_CODE4                   0x4
    #define LCD_u8CGRAM_CODE5                   0x5
    #define LCD_u8CGRAM_CODE6                   0x6
    #define LCD_u8CGRAM_CODE7                   0x7
    /* LCD Rows */
    #define LCD_u8ROW0                          0x00
    #define LCD_u8ROW1                          0x40
    /* LCD Columns */
    #define LCD_u8COL0                          0x0
    #define LCD_u8COL1                          0x1 
    #define LCD_u8COL2                          0x2 
    #define LCD_u8COL3                          0x3 
    #define LCD_u8COL4                          0x4 
    #define LCD_u8COL5                          0x5 
    #define LCD_u8COL6                          0x6 
    #define LCD_u8COL7                          0x7 
    #define LCD_u8COL8                          0x8 
    #define LCD_u8COL9                          0x9
    #define LCD_u8COL10                         0xA
    #define LCD_u8COL11                         0xB
    #define LCD_u8COL12                         0xC
    #define LCD_u8COL13                         0xD
    #define LCD_u8COL14                         0xE
    #define LCD_u8COL15                         0xF
    /* ************************************************************************ */
    /* **************************** Fns Prototypes **************************** */
    /* 
        Fn: Init the LCD Module
        Return: Void
        No Parameters
    */
    void LCD_vidInit(void);
    /* 
        Fn: Send Commands to the LCD
        Return: Void
        Parameter1: the command, available options are in LCD.h under the section 'Commands'
    */
    void LCD_vidSendCommand(u8 Copy_u8Command);
    /* 
        Fn: Display character on the LCD
        Return: Void
        Parameter1: the character, available options are the ASCII alphapeticalls or the 
        custom characters under the section 'Custom Characters Display Addresses' '
    */
    void LCD_vidDisplayCharacter(u8 Copy_u8Character);
    /* 
        Fn: Display Numbers on the LCD
        Return: Void
        Parameter1: the number
    */
    void LCD_vidDisplayNumber(u16 Copy_u16Number);
    /* 
        Fn: Display Float Numbers on the LCD
        Return: Void
        Parameter1: the number
    */
    void LCD_vidDisplayFloatNum(f64 Copy_f64Number);
    /* 
        Fn: Send custom characters to the LCD
        Return: Void
        Parameter1: Custom Character Creation Address, Available Options are in LCD.h under the section 'Custom Characters Creation Addresses'
        Parameter2: pointer to int array of size '8', which hold the custom character needed to be printed
    */
    void LCD_vidCreateCustomCharacter(u8 Copy_u8CustomCharAdd, pu8 Copy_pu8CustomCharacter);
    /* 
        Fn: change location on LCD display
        Return: Void
        Parameter1: the row   , available options are in LCD.h under the section 'LCD Rows'
        Parameter2: the column, available options are in LCD.h under the section 'LCD Columns'
    */
    void LCD_vidGoTo(u8 Copy_u8Row, u8 Copy_u8Column);
    /* 
        Fn: Display String on the LCD
        Return: Void
        Parameter1: the pointer to the string
    */
    void LCD_vidDisplayString(pu8 Copy_pu8String);
    /* ************************************************************************ */
    /* ************************************************************************ */

#endif