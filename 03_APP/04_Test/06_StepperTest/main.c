/* **************************************************************************************
**       Author      :	Michael & Yomna
**       Date        :	May 07, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Stepper testing code
** **************************************************************************************/
/* /////////////////////////// Headers inclusion //////////////////////////////////////// */
/* LIB layer */
#include "Std_types.h"
/* MCAL layer */
#include "Port.h"
/* OS stack */
#include "Sched.h"
/* HAL layer */
#include "Stepper.h"
//#include "Led.h"
/* ////////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////////// Fns Prototypes ////////////////////////////////// */
void Runnable_Test(void);
/* ////////////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////////////// Interface Fns ////////////////////////////////// */

int main(void)
{
	Sched_tstrTask Loc_strRunnables[] =
	{
			[0] =
			{
					.CallbackFn  = Stepper_vidMasterStepper_R,
					.Priority    = 0,
					.FirstDelay  = 0,
					.Periodicity = 2,
					.State       = Sched_enuReady
			},
			[1] =
			{
					.CallbackFn  = Runnable_Test,
					.Priority    = 1,
					.FirstDelay  = 0,
					.Periodicity = 2000,
					.State       = Sched_enuReady
			}
	};
	Port_vidInit();
	Sched_vidInit();
	Sched_enuRegisterRunnable(&Loc_strRunnables[0]);
	Sched_enuRegisterRunnable(&Loc_strRunnables[1]);
	Sched_vidStart();

	return(0);
}/* main */

void Runnable_Test(void)
{
  static Stepper_enuDirection_t Loc_enuDir = Stepper_enuDirection_Clockwise;
  Stepper_enuState_t Loc_enuState;

  Loc_enuState = Stepper_vidGetState(STEPPER_u8STEPPER0);
  if(Loc_enuState != Stepper_enuState_Busy)
  {
    Stepper_vidSetDirection(STEPPER_u8STEPPER0, Loc_enuDir);
    Stepper_vidMoveAngle(STEPPER_u8STEPPER0, 90);
    Loc_enuDir ^= 1;
  }/* if */
  
}/* Runnable_Test */
