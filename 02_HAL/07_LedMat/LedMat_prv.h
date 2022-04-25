/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	April 25, 2022
**       Version     :	V01
**       SWC         :	LedMat
**       Description :	Led Matrix component files
** **************************************************************************************/
#ifndef _LEDMAT_PRV_H
#define _LEDMAT_PRV_H
  /* /////////////////////////// Private Fns Prototypes //////////////////////////////////// */
  /* 
    Description         :       Display Char  
    Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
    Return              :       void
  */
  static void LedMat_vidDisp(u8 Copy_u8MatID);
  /* 
    Description         :       Stop Displaying  
    Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
    Return              :       void
  */
  static void LedMat_vidStop(u8 Copy_u8MatID);
  /* //////////////////////////////////////////////////////////////////////////////////////// */

#endif
