/* **************************************************************************************
 **       Author      :	Michael Ibrahim & Yomna Al-Shaboury
 **       Date        :	April 25, 2022
 **       Version     :	V01
 **       SWC         :	LedMat
 **       Description :	Led Matrix component files
 ** **************************************************************************************/
/* /////////////////////////////////// Headers inclusion //////////////////////////////// */
/* LIB headers */
#include "Std_types.h"
#include "Bit_utils.h"
/* MCAL headers */
#include "Dio.h"
/* Own Headers */
#include "LedMat.h"
#include "LedMat_cfg.h"
#include "LedMat_prv.h"
/* ////////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////// Global Var ///////////////////////////////////////////// */
extern LedMat_tstrConn LedMat_astrConn[LEDMAT_u8CONN_MAT];
static pu8 String[LEDMAT_u8CONN_MAT];
static u8  Character[LEDMAT_u8CONN_MAT][LEDMAT_u8ROWS];
static u8  EnglishCharUC[26][8] = {
		{0b00000000,0b00111100,0b01100110,0b01100110,0b01111110,0b01100110,0b01100110,0b01100110},
		{0b01111000,0b01001000,0b01001000,0b01110000,0b01001000,0b01000100,0b01000100,0b01111100},
		{0b00000000,0b00011110,0b00100000,0b01000000,0b01000000,0b01000000,0b00100000,0b00011110},
		{0b00000000,0b00111000,0b00100100,0b00100010,0b00100010,0b00100100,0b00111000,0b00000000},
		{0b00000000,0b00111100,0b00100000,0b00111000,0b00100000,0b00100000,0b00111100,0b00000000},
		{0b00000000,0b00111100,0b00100000,0b00111000,0b00100000,0b00100000,0b00100000,0b00000000},
		{0b00000000,0b00111110,0b00100000,0b00100000,0b00101110,0b00100010,0b00111110,0b00000000},
		{0b00000000,0b00100100,0b00100100,0b00111100,0b00100100,0b00100100,0b00100100,0b00000000},
		{0b00000000,0b00111000,0b00010000,0b00010000,0b00010000,0b00010000,0b00111000,0b00000000},
		{0b00000000,0b00011100,0b00001000,0b00001000,0b00001000,0b00101000,0b00111000,0b00000000},
		{0b00000000,0b00100100,0b00101000,0b00110000,0b00101000,0b00100100,0b00100100,0b00000000},
		{0b00000000,0b00100000,0b00100000,0b00100000,0b00100000,0b00100000,0b00111100,0b00000000},
		{0b10000001,0b11000011,0b10100101,0b10011001,0b10000001,0b10000001,0b10000001,0b10000001},
		{0b00000000,0b00100010,0b00110010,0b00101010,0b00100110,0b00100010,0b00000000,0b00000000},
		{0b00000000,0b00111100,0b01000010,0b01000010,0b01000010,0b01000010,0b00111100,0b00000000},
		{0b00000000,0b00111000,0b00100100,0b00100100,0b00111000,0b00100000,0b00100000,0b00000000},
		{0b00000000,0b00111100,0b01000010,0b01000010,0b01000010,0b01000110,0b00111110,0b00000001},
		{0b00000000,0b00111000,0b00100100,0b00100100,0b00111000,0b00100100,0b00100100,0b00000000},
		{0b00000000,0b00111100,0b00100000,0b00111100,0b00000100,0b00000100,0b00111100,0b00000000},
		{0b00000000,0b01111100,0b00010000,0b00010000,0b00010000,0b00010000,0b00010000,0b00000000},
		{0b00000000,0b01000010,0b01000010,0b01000010,0b01000010,0b00100100,0b00011000,0b00000000},
		{0b00000000,0b00100010,0b00100010,0b00100010,0b00010100,0b00010100,0b00001000,0b00000000},
		{0b00000000,0b10000010,0b10010010,0b01010100,0b01010100,0b00101000,0b00000000,0b00000000},
		{0b00000000,0b01000010,0b00100100,0b00011000,0b00011000,0b00100100,0b01000010,0b00000000},
		{0b00000000,0b01000100,0b00101000,0b00010000,0b00010000,0b00010000,0b00010000,0b00000000},
		{0b00000000,0b00111100,0b00000100,0b00001000,0b00010000,0b00100000,0b00111100,0b00000000}};
/* ////////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////// Interface Fns //////////////////////////////////////// */
/* 
  Description         :       Display char request  
  Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
  Parameter2          :       The character to display
  Return              :       void
 */
 void LedMat_vidDispChar(u8 Copy_u8MatID, u8 Copy_u8Char)
  {
	 u8 Loc_u8Counter = ZERO_INIT;
	  if((Copy_u8Char >= 'A') && (Copy_u8Char <= 'Z'))
	  {
		  LedMat_astrConn[Copy_u8MatID].enuRequest = LedMat_enuDisplayChar;
		  for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LEDMAT_u8ROWS; Loc_u8Counter++){
			  Character[Copy_u8MatID][Loc_u8Counter] = EnglishCharUC[Copy_u8Char - 'A'][Loc_u8Counter];
		  }
	  }/* if */
  }/* LedMat_vidDispChar */
  /*
  Description         :       Animate string request  
  Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
  Parameter2          :       Address of the string to display
  Return              :       void
   */
 void LedMat_vidAnimString(u8 Copy_u8MatID, pu8 Copy_pu8String)
 {
	 if((Copy_pu8String != NULL) && (Copy_pu8String != NULL))
	 {
		 LedMat_astrConn[Copy_u8MatID].enuRequest = LedMat_enuAnimString;
		 String[Copy_u8MatID] = Copy_pu8String;
	 }/* if */
 }/* LedMat_vidAnimString */
 /*
  Description         :       Stop displaying on the matrix  
  Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
  Return              :       void
  */
 void LedMat_vidStopDisp(u8 Copy_u8MatID)
 {
	 LedMat_astrConn[Copy_u8MatID].enuRequest = LedMat_enuIdle;
 }/* LedMat_vidDispChar */
 /* //////////////////////////////////////////////////////////////////////////////////// */

 /* ///////////////////////////// Runnables //////////////////////////////////////////// */
 /*
  Description         :       Runnable to master the Led Matrix  
  Parameter(s)        :       void
  Return              :       void
  */
 void LedMat_vidMasterMat_R(void)
 {
	 u8 Loc_u8Counter = ZERO_INIT;
	 u8 Loc_u8RowCounter = ZERO_INIT;
	 u8 Loc_u8NextChar;
	 static u8 Loc_u8Index = ZERO_INIT;
	 static u8 Loc_u8FrameCounter = ZERO_INIT;
	 static u8 Loc_u8Shifter = ZERO_INIT;

	 for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LEDMAT_u8CONN_MAT; Loc_u8Counter++)
	 {
		 switch(LedMat_astrConn[Loc_u8Counter].enuRequest)
		 {
		 case(LedMat_enuIdle):
    		  LedMat_vidStop(Loc_u8Counter);
		 break;
		 case(LedMat_enuDisplayChar):
    		  LedMat_vidDisp(Loc_u8Counter);
		 break;
		 case(LedMat_enuAnimString):
			 Loc_u8FrameCounter++;
			 if(Loc_u8FrameCounter == 200){
				 Loc_u8FrameCounter = ZERO_INIT;
				 for(Loc_u8RowCounter = ZERO_INIT; Loc_u8RowCounter < LEDMAT_u8ROWS; Loc_u8RowCounter++){
					 Loc_u8NextChar = Loc_u8Index + 1;
					 if(String[Loc_u8Counter][Loc_u8NextChar] == '\0'){
						 Loc_u8NextChar = ZERO_INIT;
					 }
					 if(String[Loc_u8Counter][Loc_u8Index] == '\0'){
						 Loc_u8Index = ZERO_INIT;
					 }
					  Character[Loc_u8Counter][Loc_u8RowCounter] =
							  EnglishCharUC[String[Loc_u8Counter][Loc_u8Index] - 'A'][Loc_u8RowCounter] <<	(Loc_u8Shifter)
							 | EnglishCharUC[String[Loc_u8Counter][Loc_u8NextChar] - 'A'][Loc_u8RowCounter] >> (LEDMAT_u8COLS - Loc_u8Shifter)	;
				  }
				 Loc_u8Shifter++;
				 if(Loc_u8Shifter == LEDMAT_u8COLS){
					 Loc_u8Shifter = ZERO_INIT;
					 Loc_u8Index++;
				 }
			 }
		 	 LedMat_vidDisp(Loc_u8Counter);
		 break;
		 default:
			 /* MISRA */
			 break;
		 }/* switch */
	 }/* for */
 }/* LedMat_vidMasterMat */
 /* //////////////////////////////////////////////////////////////////////////////////// */

 /* ///////////////////////////// Private Fns //////////////////////////////////////////// */
 /*
  Description         :       Stop Displaying  
  Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
  Return              :       void
  */
 static void LedMat_vidStop(u8 Copy_u8MatID)
 {
	 u8 Loc_u8Counter = ZERO_INIT;

	 for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < LEDMAT_u8ROWS; Loc_u8Counter++)
	 {
		 Dio_enuWriteChannel(LedMat_astrConn[Copy_u8MatID].u8Rows[Loc_u8Counter], DIO_u8PIN_HIGH);
	 }/* for */
 }/* LedMat_vidStop */
 /*
  Description         :       Display Char  
  Parameter1          :       Matrix ID, options are in "LedMat_cfg.h" under "Led Matrices IDs"
  Return              :       void
  */
 static void LedMat_vidDisp(u8 Copy_u8MatID)
 {
	 static u8 Loc_u8Counter[LEDMAT_u8CONN_MAT] = {ZERO_INIT};
	 u8 Loc_u8ColCounter = ZERO_INIT;

	 for(Loc_u8ColCounter = ZERO_INIT; Loc_u8ColCounter < LEDMAT_u8COLS; Loc_u8ColCounter++)
	 {
		 Dio_enuWriteChannel(LedMat_astrConn[Copy_u8MatID].u8Cols[Loc_u8ColCounter], DIO_u8PIN_LOW);
	 }/* for */

	 if(Loc_u8Counter[Copy_u8MatID] == ZERO_INIT)
	 {
		 Dio_enuWriteChannel(LedMat_astrConn[Copy_u8MatID].u8Rows[LEDMAT_u8ROWS-1], DIO_u8PIN_HIGH);
	 }/* if */
	 else
	 {
		 Dio_enuWriteChannel(LedMat_astrConn[Copy_u8MatID].u8Rows[Loc_u8Counter[Copy_u8MatID]-1], DIO_u8PIN_HIGH);
	 }/* else */
	 Dio_enuWriteChannel(LedMat_astrConn[Copy_u8MatID].u8Rows[Loc_u8Counter[Copy_u8MatID]], DIO_u8PIN_LOW);

	 for(Loc_u8ColCounter = ZERO_INIT; Loc_u8ColCounter < LEDMAT_u8COLS; Loc_u8ColCounter++)
	 {
		 Dio_enuWriteChannel(LedMat_astrConn[Copy_u8MatID].u8Cols[Loc_u8ColCounter], GET_BIT(Character[Copy_u8MatID][Loc_u8Counter[Copy_u8MatID]], Loc_u8ColCounter));
	 }/* for */

	 Loc_u8Counter[Copy_u8MatID]++;
	 if(Loc_u8Counter[Copy_u8MatID] >= LEDMAT_u8ROWS)
	 {
		 Loc_u8Counter[Copy_u8MatID] = ZERO_INIT;
	 }/* if */
 }/* LedMat_vidDisp */
 /* ////////////////////////////////////////////////////////////////////////////////////// */
