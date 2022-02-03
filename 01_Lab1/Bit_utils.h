/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	February 03, 2022
**       Version     :	V01
**       SWC         :	Bit_utils
**       Description :	Bit Manipulation MACROS
** **************************************************************************************/
#ifndef _BIT_UTILS_H
#define _BIT_UTILS_H
  #define REG_SIZE                      8
  #define SET_BIT(REG, BIT)             REG |=  (1 << BIT)
  #define CLR_BIT(REG, BIT)             REG &= ~(1 << BIT)
  #define GIT_BIT(REG, BIT)             (REG >> BIT) & 1
  #define RSHFT_REG(REG, NO)            REG >>= NO
  #define LSHFT_REG(REG, NO)            REG <<= NO
  #define CRSHFT_REG(REG, NO)           REG = (REG >> NO) | (REG << (REG_SIZE - NO))
  #define CLSHFT_REG(REG, NO)           REG = (REG << NO) | (REG >> (REG_SIZE - NO))
  #define ASSIGN_REG(REG, VALUE)        REG = VALUE
  #define SET_REG(REG)                  REG |= ~(0x00)  
  #define CLR_REG(REG)                  REG &= (0x00)
  #define TGL_BIT(REG, BIT)             REG ^= (1<<BIT)
  #define TGL_REG(REG)                  REG ^= ~(0x00)
  #define SET_H_NIB(REG)                REG |= 0x00 | (~(0x00) << (REG_SIZE / 2))
  #define SET_L_NIB(REG)                REG |= 0x00 | (~(0x00) >> (REG_SIZE / 2))
  #define CLR_H_NIB(REG)                REG &= ~(~(0x00)<<(REG_SIZE / 2))
  #define CLR_L_NIB(REG)                REG &= ~(~(0x00)>>(REG_SIZE / 2))
  #define GET_H_NIB(REG)                (REG >> (REG_SIZE / 2)) & (~(0x00) >> (REG_SIZE / 2))
  #define GET_L_NIB(REG)                (REG) & (~(0x00) >> (REG_SIZE / 2))
  #define ASSIGN_H_NIB(REG, VALUE)      REG = (REG & ~(~(0x00)<<(REG_SIZE / 2))) | (VALUE << (REG_SIZE / 2))
  #define ASSIGN_L_NIB(REG, VALUE)      REG = (REG & ~(~(0x00)>>(REG_SIZE / 2))) | (VALUE)
  #define TGL_H_NIB(REG)                REG ^= ~(0x00)<<(REG_SIZE / 2)
  #define TGL_L_NIB(REG)                REG ^= ~(0x00)>>(REG_SIZE / 2)
  #define SWAP_NIB(REG)                 REG = (REG >> (REG_SIZE / 2)) | (REG << (REG_SIZE / 2))

#endif