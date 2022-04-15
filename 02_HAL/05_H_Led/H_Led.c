/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 24, 2022
**       Version     :	V01
**       SWC         :	H_LED
**       Description :	Led module files
** **************************************************************************************/
/* ****************************** Headers inclusion ******************************** */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "H_Led.h"
#include "H_Led_cfg.h"
#include "H_Led_prv.h"
/* *************************** Interface Fns *************************************** */
/* 
  Fn         :   Set the lvl of specific led number
  Parameter1 :   Number of the specific led to control, Write leds number to pass in "H_Led_cfg.h" under "Connected Leds"
  Parameter2 :   Level of the LED, options are in "H_Led.h" under "Led levels"
  Return     :   Error status of the fn, Error type is in "H_Led.h" under "Error Type"
  **Caution**:   The leds must be initialized
*/
H_Led_tenuStatus H_Led_enuSet(u8 Copy_u8LedNum, u8 Copy_u8LedLvl)
{
  H_Led_tenuStatus Loc_enuError = H_Led_enuOk;
  Dio_enuWriteChannel(H_Led_astrLeds[Copy_u8LedNum].Pin, (H_Led_astrLeds[Copy_u8LedNum].ActiveState ^ Copy_u8LedLvl));
  
  return(Loc_enuError);/* Returning the error status */
}/* H_Led_enuSet */
/* ********************************************************************************* */