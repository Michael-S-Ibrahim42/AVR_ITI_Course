/**************************************************************************************
**       Author      :	Youmna 
**       Date        :	February 04, 2022
**       Version     :	V01
**       SWC         :	Bit_utils
**       Description :	Bit Manipulation MACROS Test 
** **************************************************************************************/

#include <stdio.h>
#include "Bit_utils.h"
#include "Std_types.h"

int main(int args, char ** argv)
{
	unsigned char x;

	x = 0x0A;	printf("%x\n", SET_BIT(x, 2) == 0x0E);		// 0E
	x = 0x0A;	printf("%x\n", CLR_BIT(x, 3) == 0x02);		// 02
	x = 0x0A;	printf("%x\n", GET_BIT(x, 2) == 0x00 );		// 0
	x = 0x0A;	printf("%x\n", TGL_BIT(x, 3) == 0x02);		// 02

	x = 0x0A;	printf("%x\n", RSHFT_REG(x, 2) == 0x02);	// 02
	x = 0x0A;	printf("%x\n", LSHFT_REG(x, 2) == 0x28);	// 28
	x = 0x0A;	printf("%x\n", CRSHFT_REG(x, 2) == 0x82);	// 82
	x = 0x0A;	printf("%x\n", CLSHFT_REG(x, 2) == 0x28);	// 28
	x = 0x0A;	printf("%x\n", ASSIGN_REG(x, 2) == 0x02);	// 02
	x = 0x0A;	printf("%x\n", SET_REG(x) == 0xFF);			// FF
	x = 0x0A;	printf("%x\n", CLR_REG(x) == 0x00);			// 00
	x = 0x0A;	printf("%x\n", TGL_REG(x) == 0xF5);			// F5

	x = 0x0A;	printf("%x\n", SET_H_NIB(x) == 0xFA);			// FA
	x = 0x0A;	printf("%x\n", SET_L_NIB(x) == 0x0F);			// 0F
	x = 0x0A;	printf("%x\n", CLR_H_NIB(x) == 0x0A);			// 0A
	x = 0x0A;	printf("%x\n", CLR_L_NIB(x) == 0x00);			// 00
	x = 0x0A;	printf("%x\n", GET_H_NIB(x) == 0x00);			// 00
	x = 0x0A;	printf("%x\n", GET_L_NIB(x) == 0x0A);			// 0A
	x = 0x0A;	printf("%x\n", ASSIGN_H_NIB(x, 0x0F) == 0xFA);	// FA
	x = 0x0A;	printf("%x\n", ASSIGN_L_NIB(x, 0x0F) == 0x0F);	// 0F
	x = 0x0A;	printf("%x\n", TGL_H_NIB(x) == 0xFA);			// FA
	x = 0x0A;	printf("%x\n", TGL_L_NIB(x) == 0x05);			// 05
	x = 0x0A;	printf("%x\n", SWAP_NIB(x) == 0xA0);			// A0
  
  printf("The size of u8 :  %lld\n", sizeof(u8 ));
  printf("The size of s8 :  %lld\n", sizeof(s8 ));
  printf("The size of u16: %lld\n", sizeof(u16));
  printf("The size of s16: %lld\n", sizeof(s16));
  printf("The size of u32: %lld\n", sizeof(u32));
  printf("The size of s32: %lld\n", sizeof(s32));
  printf("The size of u64: %lld\n", sizeof(u64));
  printf("The size of s64: %lld\n", sizeof(s64));
  printf("The size of f32: %lld\n", sizeof(f32));
  printf("The size of f64: %lld\n", sizeof(f64));

	return (0);
}/* main */
