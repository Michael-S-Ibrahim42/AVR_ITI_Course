/*
	auther	: yssh
	date	: 3/2/2022
*/
#ifndef BIT_UTILS_H_
#define BIT_UTILS_H_
#include "Std_types.h"
/*
	bit macros
*/
#define SET_BIT(Reg, Bit) 					(Reg |= (1<<Bit))
#define CLR_BIT(Reg, Bit) 					(Reg &= ~(1<<Bit))
#define GET_BIT(Reg, Bit) 					((Reg>>Bit) & 1)
#define TGL_BIT(Reg, Bit) 					(Reg ^= (1<<Bit))

/*
	reg macros
*/
#define RSHFT_REG(Reg, No) 					(Reg = ((u64)Reg) >> No)
#define LSHFT_REG(Reg, No)					(Reg <<= No)
#define CRSHFT_REG(Reg, No)					(Reg = ((u64)Reg >> No) | (Reg << ((sizeof(Reg)*8) -No) ))
#define CLSHFT_REG(Reg, No)					(Reg = (Reg << No) | ((u64)Reg >> ((sizeof(Reg)*8) -No) ))
#define ASSIGN_REG(Reg, Val)				(Reg = Val)
#define SET_REG(Reg)						(Reg = ~0x00)
#define CLR_REG(Reg)						(Reg = 0)
#define TGL_REG(Reg)						(Reg = ~Reg)



/*
	nibble macros
*/
#define SET_H_NIB(Reg)						(Reg |= 0xF0)
#define SET_L_NIB(Reg)						(Reg |= 0x0F)
#define CLR_H_NIB(Reg)						(Reg &= 0x0F)
#define CLR_L_NIB(Reg)						(Reg &= 0xF0)
#define GET_H_NIB(Reg)						((Reg & 0xF0)>>4)
#define GET_L_NIB(Reg)						(Reg & 0x0F)
#define ASSIGN_H_NIB(Reg, Val)				(Reg = ((Reg & 0x0F) | (Val<<4)) )
#define ASSIGN_L_NIB(Reg, Val)				(Reg = ((Reg & 0xF0) | Val))
#define TGL_H_NIB(Reg)						(Reg ^= 0xF0)
#define TGL_L_NIB(Reg)						(Reg ^= 0x0F)
#define SWAP_NIB(Reg)						(Reg = (Reg << 4) | (Reg >> 4))


#endif