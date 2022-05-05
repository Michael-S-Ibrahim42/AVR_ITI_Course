
/* STD headers */
/* LIB headers */
#include "Std_types.h"
/* OS headers */
#include "Sched.h"
/* MCAL headers */
#include "Port.h"
#include "Dio.h"
/* HAL headers */
#include "Switch.h"

void Runnable_Test(void);

int main(void)
{
  Sched_tstrTask Loc_strRunnables[] = 
  {
    [0] = 
    {
      .CallbackFn  = Switch_vidUpdateState_R,
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
      .Periodicity = 5,
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

  Switch_tenuState Loc_enuSwitchState;
  Switch_enuGetState(SWITCH_u8COL0, &Loc_enuSwitchState);
  if(Loc_enuSwitchState == Switch_enuPrePressed)
  {
	Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_HIGH);
    Dio_enuWriteChannel(DIO_u8PIN9, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN10, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN11, DIO_u8PIN_LOW);
  }/* if */
  else if(Loc_enuSwitchState == Switch_enuPressed)
  {
    Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN9, DIO_u8PIN_HIGH);
    Dio_enuWriteChannel(DIO_u8PIN10, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN11, DIO_u8PIN_LOW);
  }/* else if */
  else if(Loc_enuSwitchState == Switch_enuPreReleased)
  {
    Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN9, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN10, DIO_u8PIN_HIGH);
    Dio_enuWriteChannel(DIO_u8PIN11, DIO_u8PIN_LOW);
  }/* else if */
  else if(Loc_enuSwitchState == Switch_enuReleased)
  {
    Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN9, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN10, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN11, DIO_u8PIN_HIGH);
  }/* else if */
  else
  {

  }/* else */
}/* Runnable_Test */
