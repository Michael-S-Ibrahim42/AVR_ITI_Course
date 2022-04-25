/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	April 25, 2022
**       Version     :	V01
**       SWC         :	LedMat
**       Description :	Led Matrix component files
** **************************************************************************************/
#ifndef _LEDMAT_H
#define _LEDMAT_H 
  /* /////////////////////////////////// Headers inclusion //////////////////////////////// */
  /* Own headers */
  #include "LedMat_cfg.h"
  /* ////////////////////////////////////////////////////////////////////////////////////// */
  
  /* /////////////////////////////////// Defined types //////////////////////////////////// */  
  typedef enum
  {
    LedMat_enuIdle,
    LedMat_enuDisplayChar,
    LedMat_enuAnimString
  }LedMat_tenuReq;
  typedef struct 
  {
    u8              u8Rows[LEDMAT_u8ROWS];
    u8              u8Cols[LEDMAT_u8COLS];
    LedMat_tenuReq  enuRequest; 
  }LedMat_tstrConn;
  /* ////////////////////////////////////////////////////////////////////////////////////// */

  /* //////////////////////////////// Interface Fns Prototypes //////////////////////////// */
  /* 
    Description         :       Stop displaying on the matrix  
    Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
    Return              :       void
  */
  void LedMat_vidStopDisp(u8 Copy_u8MatID);
  /* 
    Description         :       Display char request  
    Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
    Parameter2          :       The character to display
    Return              :       void
  */
  void LedMat_vidDispChar(u8 Copy_u8MatID, u8 Copy_u8Char);  
  /* 
    Description         :       Animate string request  
    Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
    Parameter2          :       Address of the string to display
    Return              :       void
  */
  void LedMat_vidAnimString(u8 Copy_u8MatID, pu8 Copy_pu8String);
  /* ////////////////////////////////////////////////////////////////////////////////////// */
  
  /* //////////////////////////////// Runnables Prototypes //////////////////////////// */
  /* 
    Description         :       Runnable to master the Led Matrix  
    Parameter(s)        :       void
    Return              :       void
  */
  void LedMat_vidMasterMat_R(void);
  /* ////////////////////////////////////////////////////////////////////////////////////// */













#endif