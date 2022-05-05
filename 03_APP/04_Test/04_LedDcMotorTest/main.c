/* **************************************************************************************
**       Author      :	Michael & Yomna
**       Date        :	May 05, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	Test of Led and DcMotor Modules
** **************************************************************************************/
/* /////////////////////////// Headers inclusion //////////////////////////////////////// */
/* LIB layer */
#include "Std_types.h"
/* OS stack */
#include "Sched.h"
/* MCAL layer */
#include "Port.h"
/* HAL layer */
#include "Led.h"
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
      .CallbackFn  = Led_vidMasterLed_R,
      .Priority    = 0,
      .FirstDelay  = 0,
      .Periodicity = 5,
      .State       = Sched_enuReady 
    },
    [1] = 
    {
      .CallbackFn  = Runnable_Test,
      .Priority    = 1,
      .FirstDelay  = 1,
      .Periodicity = 1000,
      .State       = Sched_enuReady 
    }
  };
  Port_vidInit();
  Led_enuSetLedPeriodicity(LED_u8BLUE, 100, 5);
  Sched_vidInit();
  Sched_enuRegisterRunnable(&Loc_strRunnables[0]);
  Sched_enuRegisterRunnable(&Loc_strRunnables[1]);
  Sched_vidStart();

  return(0);
}/* main */

void Runnable_Test(void)
{
	 static u8 Turn = 0;
	 if(Turn == 0)
	 {
	 	Led_enuSetReq(LED_u8BLUE, Led_enuReq_Blink);
	 	Turn = 1;
	 }/* if */
	// else
	// {
	// 	Led_enuSetReq(LED_u8BLUE, Led_enuReq_Off);
	// 	Turn = 0;
	// }/* else */

}/* Runnable_Test */
