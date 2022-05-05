/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	May 04, 2022
**       Version     :	V01
**       SWC         :	ATMEGA32A
**       Description :	Registers Header
** **************************************************************************************/
#ifndef _ATMEGA32A_H
#define _ATMEGA32A_H
  /* ////////////////////////////////////////// Timer1 ////////////////////////////////////////// */
  #define TCCR1A                          *((volatile u8* )(0x4F))
  #define TCCR1B                          *((volatile u8* )(0x4E))
  #define TCNT1                           *((volatile u16*)(0x4C))
  #define OCR1A                           *((volatile u16*)(0x4A))
  #define OCR1B                           *((volatile u16*)(0x48))
  #define ICR1                            *((volatile u16*)(0x46))
  /* //////////////////////////////////////////////////////////////////////////////////////////// */

  /* ////////////////////////////////////////// GPIO ////////////////////////////////////////// */
  #define PORTA                           *((volatile u8* )(0x3B))
  #define DDRA                            *((volatile u8* )(0x3A))
  #define PINA                            *((volatile u8* )(0x39))
  #define PORTB                           *((volatile u8* )(0x38))
  #define DDRB                            *((volatile u8* )(0x37))
  #define PINB                            *((volatile u8* )(0x36))
  #define PORTC                           *((volatile u8* )(0x35))
  #define DDRC                            *((volatile u8* )(0x34))
  #define PINC                            *((volatile u8* )(0x33))
  #define PORTD                           *((volatile u8* )(0x32))
  #define DDRD                            *((volatile u8* )(0x31))
  #define PIND                            *((volatile u8* )(0x30))
  /* //////////////////////////////////////////////////////////////////////////////////////////// */

#endif
