/* **************************************************************************************
**       Author      :	Michael Ibrahim & Yomna Al-Shaboury
**       Date        :	April 25, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	
** **************************************************************************************/
/* LIB headers */
#include "Std_types.h"
/* OS Headers */
#include "Sched.h"
/* HAL headers */
#include "LedMat.h"
/* MCAL Headers */
#include "Port.h"

void Test_vidOrder_R(void);

/* main fn */
int main(void)
{
  Sched_tstrTask Loc_strRunnables[] = 
  {
    [0] = 
    {
      .CallbackFn  = LedMat_vidMasterMat_R,
      .Priority    = 0,
      .FirstDelay  = 0,
      .Periodicity = 1,
      .State       = Sched_enuReady 
    },
    [1] = 
    {
      .CallbackFn  = Test_vidOrder_R,
      .Priority    = 1,
      .FirstDelay  = 0,
      .Periodicity = 25,
      .State       = Sched_enuReady 
    }
  };
	Port_vidInit();
	Sched_vidInit();
	Sched_enuRegisterRunnable(&Loc_strRunnables[0]);
	Sched_enuRegisterRunnable(&Loc_strRunnables[1]);
	Sched_vidStart();

	return(0);
}

void Test_vidOrder_R(void)
{
//	LedMat_vidDispChar(LEDMAT_u8NAME_MAT, 'N');
		LedMat_vidAnimString(LEDMAT_u8NAME_MAT, "MICHAEL");
//		LedMat_vidAnimString(LEDMAT_u8NAME_MAT, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

}/* Test_vidOrder_R */
