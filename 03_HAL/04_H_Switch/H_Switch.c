/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 24, 2022
**       Version     :	V01
**       SWC         :	H_Switch
**       Description :	Switch module files
** **************************************************************************************/
/* ****************************** Headers Inclusion ************************************* */
/* STD headers */
#include <avr/delay.h>
#define F_CPU           16000000UL
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "H_Switch.h"
#include "H_Switch_cfg.h"
#include "H_Switch_prv.h"

/* ************************** Interface Fns ********************************************* */
/* 
  Fn          : Read the switch value which is defined by the passed parameter. It also will handle the debouncing, it's synchronous fn
  Parameter1  : the switch, options are in "H_Switch_cfg.h" under the section "Connected Switches Names"
  Parameter2  : the switch lvl, options are in "H_Switch.h" under the section "Switch Levels"
  Return      : The error status of type "H_Switch_tenuStatus", exist in "H_Switch.h" under "Error Type"
*/
H_Switch_tenuStatus H_Switch_enuReadSwitch(u8 Copy_u8Switch, pu8 Copy_pu8SwitchLvl)
{
  H_Switch_tenuStatus Loc_enuError = H_Switch_enuOk; 
  u8 Loc_u8CurrentVal, Loc_u8DebFlag = H_SWITCH_u8FLAG_LOW, Loc_u8DelayCounter = 0;

  while(!Loc_u8DebFlag)/* Loop to over the debouncing */
  {
    Dio_enuReadChannel(H_Switch_astrSysSwitches[Copy_u8Switch].Pin, &Loc_u8CurrentVal);
    /* Delay for some time to check on debouncing */
    if((Loc_u8CurrentVal == H_Switch_astrSysSwitches[Copy_u8Switch].State) && (Loc_u8DelayCounter > H_SWITCH_u32COUNTER_START))
    {
      Loc_u8DelayCounter--;
    }/* if */
    else if(Loc_u8CurrentVal != H_Switch_astrSysSwitches[Copy_u8Switch].State)
    {
      Loc_u8DelayCounter++;
    }/* else if */
    if((Loc_u8DelayCounter >= H_SWITCH_u32COUNTER_END) || (Loc_u8DelayCounter == H_SWITCH_u32COUNTER_START))
    {
      H_Switch_astrSysSwitches[Copy_u8Switch].State = Loc_u8CurrentVal;
      Loc_u8DebFlag = H_SWITCH_u8FLAG_HIGH;
    }
    _delay_ms(5);
  }/* while */
  *Copy_pu8SwitchLvl = Loc_u8CurrentVal;

  return(Loc_enuError);/* returning the error status */  
}/* H_Switch_enuReadSwitch */
/* ************************************************************************************** */
