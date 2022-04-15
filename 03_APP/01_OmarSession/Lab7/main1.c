/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 08, 2022
**       Version     :	V01
**       SWC         :	main
**       Description :	lab7 main file
** **************************************************************************************/
/* ********************************* Headers inclusion ********************************** */
/* STD headers */
#include <avr/io.h>
#include <avr/interrupt.h>
/* LIB headers */
#include "Std_types.h"
/* HAL headers */

/* MCAL headers */
#include "Port.h"
#include "H_Led.h"
/* ************************************************************************************** */
/* ***************************** Entry Point ******************************************** */
int main(int args, char** argv)
{
  Port_vidInit();
  TCNT0 = 0;
  TIMSK = (1<<0);
  TCCR0 = (1<<0);
  SREG  |= (1<<7);
  while(1)
  {

  }/* while */ 
  return(0);/* indicate normal program termination */
}/* main */
ISR(TIMER0_OVF_vect)
{
  static u16 Loc_u16No_Of_OVF = 0;
  static u8 State = 0;
  Loc_u16No_Of_OVF++;
  if(Loc_u16No_Of_OVF == 62500)
  {
    State ^= 1;
    H_Led_enuSet(H_LED_u8BLUE, State);
  }
}
// void Delay_vidMS(u16 Copy_u16Time)
// {
//   u8 Loc_u8Counter = 0;
//   u8 Loc_u8Iterations;

//   Loc_u8Iterations = ;
//   for(Loc_u8Counter = 0; Loc_u8Counter < Loc_u8Iterations; Loc_u8Counter++)
//   {
//     asm("NOP");
//   }/* for */
// }/* for */

/* ////////////////////////////////////////////////////////////////////////////////// */
/* //////////////////////// After Break /////////////////////////////////// */
typedef struct
{
  u16 FirstDelay;
  u16 Periodicity;
  u8 State;
  void (*pCode)(void);
}Task_type;
Task_type* Arr_Task[2];
void fun(void);
int main(void)
{
  Task_type Led1_Task;
  Led1_Task.FirstDelay = 0;
  Led1_Task.Periodicity = 1000;
  Led1_Task.State = 1;
  Led1_Task.pCode = &fun;
  Task_type Led2_Task;
  Led2_Task.FirstDelay = 0;
  Led2_Task.Periodicity = 1000;
  Led2_Task.State = 1;
  Led2_Task.pCode = &fun;
  Arr_Task[0] = &Led1_Task;
  Arr_Task[1] = &Led2_Task;
}

void vid_Scheduler(void)
{
  u8 Index;
  for(Index=0; Index<2; Index++)
  {
    if(Arr_Task[Index] != NULL)
    {
      if(Arr_Task[Index]->State == 1)
      {
        if(Arr_Task[Index]->FirstDelay == 0)
        {
          (Arr_Task[Index]->pCode)();
          Arr_Task[Index]->FirstDelay = Arr_Task[Index]->Periodicity;
        }
        Arr_Task[Index]->FirstDelay--;
      }
    }
  }/* for */
}
