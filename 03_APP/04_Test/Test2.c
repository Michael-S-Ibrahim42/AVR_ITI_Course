/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 18, 2022
**       Version     :	V01
**       SWC         :	Test2
**       Description :	Testing the keypad
** **************************************************************************************/
/* ////////////////////////// Headers inclusion /////////////////////////////////// */
/* LIB headers */
#include "Std_types.h"
/* OS headers */
#include "Sched.h"
/* HAL headers */
#include "Switch.h"
#include "Keypad.h"
/* MCAL headers */
#include "Port.h"
#include "Dio.h"
/* //////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////// Prototypes /////////////////////////////////////// */
void Test2_vidControl_R(void);
/* ///////////////////////////// main ///////////////////////////////////////////// */
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
      .CallbackFn  = Keypad_vidUpdateCurrentKey_R,
      .Priority    = 1,
      .FirstDelay  = 1,
      .Periodicity = 25,
      .State       = Sched_enuReady 
    },
    [2] = 
    {
      .CallbackFn  = Test2_vidControl_R,
      .Priority    = 2,
      .FirstDelay  = 25,
      .Periodicity = 5,
      .State       = Sched_enuReady 
    }
  };
  Port_vidInit();
  Sched_vidInit();
  Sched_enuRegisterRunnable(&Loc_strRunnables[0]);
  Sched_enuRegisterRunnable(&Loc_strRunnables[1]);
  Sched_enuRegisterRunnable(&Loc_strRunnables[2]);
  Sched_vidStart();

  return(0);
}/* main */
/* //////////////////////////////////////////////////////////////////////////////// */

/* ///////////////////////////// Runnable ///////////////////////////////////////// */
void Test2_vidControl_R(void)
{  
  u8 Loc_u8Key;
  Keypad_enuGetKey(&Loc_u8Key);
  if(Loc_u8Key == '7')
  {
	  Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_HIGH);
    Dio_enuWriteChannel(DIO_u8PIN9, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN10, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN11, DIO_u8PIN_LOW);
  }/* if */
  else if(Loc_u8Key == '8')
  {
    Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN9, DIO_u8PIN_HIGH);
    Dio_enuWriteChannel(DIO_u8PIN10, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN11, DIO_u8PIN_LOW);
  }/* else if */
  else if(Loc_u8Key == '5')
  {
    Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN9, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN10, DIO_u8PIN_HIGH);
    Dio_enuWriteChannel(DIO_u8PIN11, DIO_u8PIN_LOW);
  }/* else if */
  else if(Loc_u8Key == '1')
  {
    Dio_enuWriteChannel(DIO_u8PIN8, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN9, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN10, DIO_u8PIN_LOW);
    Dio_enuWriteChannel(DIO_u8PIN11, DIO_u8PIN_HIGH);
  }/* else if */
  else
  {

  }/* else */

}/* Test2_vidControl_R */
/* //////////////////////////////////////////////////////////////////////////////// */
