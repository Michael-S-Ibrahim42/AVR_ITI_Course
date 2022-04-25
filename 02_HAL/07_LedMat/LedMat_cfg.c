/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	April 25, 2022
**       Version     :	V01
**       SWC         :	LedMat
**       Description :	Led Matrix component files
** **************************************************************************************/
/* //////////////////////////// Headers inclusion //////////////////////////////////// */
/* LIB headers */
#include "Std_types.h"
/* MCAL Headers */
#include "Dio.h"
/* Own Headers */
#include "LedMat.h"
#include "LedMat_cfg.h"
/* /////////////////////////////////////////////////////////////////////////////////// */

/* //////////////////////////// Config Variable ////////////////////////////////////// */
LedMat_tstrConn LedMat_astrConn[] = 
{
  [LEDMAT_u8NAME_MAT] = 
  {
	  {
      DIO_u8PIN16,
      DIO_u8PIN17,
      DIO_u8PIN18,
      DIO_u8PIN19,
      DIO_u8PIN20,
      DIO_u8PIN21,
      DIO_u8PIN22,
      DIO_u8PIN23
    },
	  {
      DIO_u8PIN24,
      DIO_u8PIN25,
      DIO_u8PIN26,
      DIO_u8PIN27,
      DIO_u8PIN28,
      DIO_u8PIN29,
      DIO_u8PIN30,
      DIO_u8PIN31
    },
    .enuRequest = LedMat_enuIdle
  }
};
/* /////////////////////////////////////////////////////////////////////////////////// */
