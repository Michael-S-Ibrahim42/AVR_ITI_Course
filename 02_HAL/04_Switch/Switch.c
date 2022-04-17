/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 11, 2022
**       Version     :	V01
**       SWC         :	Switch
**       Description :	Switch module files
** **************************************************************************************/
/* ****************************** Headers Inclusion ************************************* */
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Dio.h"
/* Own headers */
#include "Switch.h"
#include "Switch_cfg.h"
#include "Switch_prv.h"
/* ************************************************************************************** */

/* ************************** Interface Fns ********************************************* */
/* 
  Fn          : Init the switch which is defined in "Switch_cfg.c"
  Return      : The error status of type "Switch_tenuError", exist in "Switch.h" under "Error Type"
  **Caution** : The configuration files must be updated
*/
Switch_tenuError Switch_enuInit(void)
{
  Switch_tenuError Loc_enuError = Switch_enuOk; 

  return(Loc_enuError);/* returning the error status */
}/* Switch_enuInit */
/* 
  Description : Get the switch last updated state
  Parameter1  : the switch, options are in "Switch_cfg.h" under the section "Connected Switches Names"
  Parameter2  : the switch State, options are in "Switch.h" under the section "Switch State"
  Return      : The error status of type "Switch_tenuError", exist in "Switch.h" under "Error Type"
*/
Switch_tenuError Switch_enuGetState(u8 Copy_u8Switch, Switch_tenuState* Copy_penuState)
{
  Switch_tenuError Loc_enuError = Switch_enuOk; 

  if(Copy_penuState == NULL)/* The pointer is initialized by null */
  {
    Loc_enuError = Switch_enuNullPtr;
  }/* if */ 
  else if(Copy_u8Switch >= SWITCH_u8BTN_NUM)/* the number of switch is not valid */
  {
    Loc_enuError = Switch_enuNok;
  }
  else
  {
    *Copy_penuState = Switch_astrSwitch[Copy_u8Switch].State;
  }/* else */
  
  return(Loc_enuError);/* returning the error status */  
}/* Switch_enuGetStatus */
/* ************************************************************************************** */

/* ****************************** Runnables ********************************************* */
/* 
  Runnable   :   Update State of the switches
  Parameters :   void
  Return     :   void
  **Caution**:   The switches must be initialized using "Switch_enuInit" before calling "Sched_vidStart"
*/  
void Switch_vidUpdateState_R(void)
{
  u8  Loc_u8Reading = SWITCH_u8READING_INIT;/* Variable to receive the immediate reading */
  u8  Loc_u8Iterator = SWITCH_u8COUNTER_INIT;/* Variable to loop over the connected switches */

  for(Loc_u8Iterator = SWITCH_u8COUNTER_INIT; Loc_u8Iterator < SWITCH_u8BTN_NUM; Loc_u8Iterator++)
  {
    Dio_enuReadChannel(Switch_astrSwitch[Loc_u8Iterator].Pin, &Loc_u8Reading);
    /* CHECK on the switch state and take the suitable action */
    switch(Switch_astrSwitch[Loc_u8Iterator].State)
    {
    case(Switch_enuReleased):
      /* If pullUp && read = 0 || pulldown && read=1 --->> Counter++ then if(counter==3)--->State=prepressed
          else ---> Counter = 0 */    
      if(((Switch_astrSwitch[Loc_u8Iterator].PullRes == Switch_enuPullUp  ) &&  (Loc_u8Reading == DIO_u8PIN_LOW  )) ||
	     ((Switch_astrSwitch[Loc_u8Iterator].PullRes == Switch_enuPullDown) &&  (Loc_u8Reading == DIO_u8PIN_HIGH )))
	 {
        Switch_astrSwitch[Loc_u8Iterator].Counter++;
        if(Switch_astrSwitch[Loc_u8Iterator].Counter == SWITCH_u8PREPRESSED_ENTRY)
        {
          Switch_astrSwitch[Loc_u8Iterator].State = Switch_enuPrePressed;
        }/* if */
      }/* if */
      else
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
      }/* else */
      break;
    case(Switch_enuPrePressed):
      /* If pullUp && read = 0 || pulldown && read=1 --->> Counter++ then if(counter==25)--->State=pressed &  counter=0
      else -->counter=0 & State=Released */
      if(((Switch_astrSwitch[Loc_u8Iterator].PullRes == Switch_enuPullUp  ) && (Loc_u8Reading == DIO_u8PIN_LOW )) ||
         ((Switch_astrSwitch[Loc_u8Iterator].PullRes == Switch_enuPullDown) && (Loc_u8Reading == DIO_u8PIN_HIGH)))
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter++;
        if(Switch_astrSwitch[Loc_u8Iterator].Counter == SWITCH_u8PRESSED_ENTRY)
        {
          Switch_astrSwitch[Loc_u8Iterator].State = Switch_enuPressed;
          Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
        }/* if */
      }/* if */
      else
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
        Switch_astrSwitch[Loc_u8Iterator].State = Switch_enuReleased;
      }/* else */
      break;
    case(Switch_enuPressed):
      /* If pullUp && read = 1 || pulldown && read=0 --->> Counter++ then if(counter==20)--->State=PreReleased
      else -->counter=0  */
      if(((Switch_astrSwitch[Loc_u8Iterator].PullRes == Switch_enuPullUp  ) && (Loc_u8Reading == DIO_u8PIN_HIGH)) ||
         ((Switch_astrSwitch[Loc_u8Iterator].PullRes == Switch_enuPullDown) && (Loc_u8Reading == DIO_u8PIN_LOW)))
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter++;
        if(Switch_astrSwitch[Loc_u8Iterator].Counter == SWITCH_u8PRERELEASED_ENTRY)
        {
          Switch_astrSwitch[Loc_u8Iterator].State = Switch_enuPreReleased;
        }/* if */
      }/* if */
      else
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
      }/* else */      
      break;
    case(Switch_enuPreReleased):
      /* If pullUp && read = 1 || pulldown && read=0 --->> Counter++ then if(counter==25)--->State=released &  counter=0
      else -->counter=0 & State=Pressed */
      if(((Switch_astrSwitch[Loc_u8Iterator].PullRes == Switch_enuPullUp) &&    (Loc_u8Reading == DIO_u8PIN_HIGH)) ||
         ((Switch_astrSwitch[Loc_u8Iterator].PullRes == Switch_enuPullDown) &&  (Loc_u8Reading == DIO_u8PIN_LOW)))
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter++;
        if(Switch_astrSwitch[Loc_u8Iterator].Counter == SWITCH_u8RELEASED_ENTRY)
        {
          Switch_astrSwitch[Loc_u8Iterator].State = Switch_enuReleased;
          Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
        }/* if */
      }/* if */
      else
      {
        Switch_astrSwitch[Loc_u8Iterator].Counter = SWITCH_u8COUNTER_INIT;
        Switch_astrSwitch[Loc_u8Iterator].State = Switch_enuPressed;
      }/* else */      
      break;
    default:
      /* MISRA */
      break;
    }/* switch */
  }/* for */
}/* Switch_vidUpdateStatus_R */
/* ************************************************************************************** */
