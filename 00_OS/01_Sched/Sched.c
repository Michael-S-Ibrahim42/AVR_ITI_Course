/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 16, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler software component
** **************************************************************************************/
/* //////////////////////////// Headers inclusion  /////////////////////// */
/* STD types */
#include <avr/io.h>
/* LIB headers */
#include "Std_types.h"
/* MCAL headers */
#include "Port.h"
#include "Dio.h"
/* Own headers */
#include "Sched.h"
#include "Sched_cfg.h"
#include "Sched_prv.h"
/* /////////////////////////////////////////////////////////////////// */

/* //////////////////////////// Global Variables  //////////////////// */
Sched_tstrTask* Sched_apstrTasks[SCHED_u8MAX_TASKS];
u8 Sched_u8SchedulerFlag = FLAG_LOW;
/* /////////////////////////////////////////////////////////////////// */

/* //////////////////////////// Interface fns  /////////////////////// */
/* 
	Description					:				Init the scheduler
	Parameter(s)				:				void
	Return							:				void	
*/
void Sched_vidInit(void)
{
	const Gpt_ConfigType Loc_strConfig = 
  {
    .u8Mode           = GPT_u8MODE_NORMAL,
    .u8CompareOutput  = GPT_u8OC0_NORMAL,
    .u8Prescalar      = GPT_u8PRES_64
  };
  Gpt_Init(&Loc_strConfig);
  Gpt_Notification_CH0(Sched_vidRaiseFlag);
  Gpt_EnableNotification(GPT_u8CH0);
  SREG |= SCHED_u8GLOBAL_INT; /* Enable Global Interrupt using masking */
}/* Sched_vidInit */
/* 
	Description					:				start the scheduler
	Parameter(s)				:				void
	Return							:				void	
*/
void Sched_vidStart(void)
{
	/* start the timer */
	Gpt_StartTimer(GPT_u8CH0, SCHED_u8TICKS_NUM);
	while(1)
	{
		if(Sched_u8SchedulerFlag)/* Check on Scheduler flag */
		{
			Sched_u8SchedulerFlag = FLAG_LOW;/* Lowering the Scheduler flag */
			Sched_vidSched();/* Calling the scheduler */
		}/* if */
	}/* while */
}
/* 
	Description					:				Register runnables
	Parameter(s)				:				The runnable of type "Task structure" in "Sched.h"
	Return							:				Error status of type "Error types" in "Sched.h"	
*/
Sched_tenuError Sched_enuRegisterRunnable(Sched_tstrTask* Copy_pstrTask)
{
	Sched_tenuError Loc_enuStatus = Sched_enuOk;

	if(Copy_pstrTask != NULL)
	{
		if(Copy_pstrTask->Priority < SCHED_u8MAX_TASKS)
		{
			if(Sched_apstrTasks[Copy_pstrTask->Priority] == NULL)
			{
				Sched_apstrTasks[Copy_pstrTask->Priority] = Copy_pstrTask;
			}/* if */
			else
			{
				Loc_enuStatus = Sched_enuPriorityExist;
			}/* else */
		}/* if */
		else
		{
			Loc_enuStatus = Sched_enuPriorityError;

		}/* else */
	}/* if */
	else
	{
		Loc_enuStatus = Sched_enuNullPtr; /* Passed null pointer */
	}/* else */

	return(Loc_enuStatus);
}/* Sched_registerRunnable */
/* /////////////////////////////////////////////////////////////////// */

/* //////////////////////////// Private Fns ////////////////////////// */
/* 
	Description					:				Select and run the tasks
	Parameter(s)				:				void
	Return							:				void	
*/
static void Sched_vidSched(void)
{
	u8 Loc_u8Counter = ZERO_INIT;
	for(Loc_u8Counter = ZERO_INIT; Loc_u8Counter < SCHED_u8MAX_TASKS; Loc_u8Counter++)
	{
		if(Sched_astrTasks[Loc_u8Counter] != NULL)
		{
			if(Sched_astrTasks[Loc_u8Counter]->State == Sched_enuReady)
			{
				if(Sched_astrTasks[Loc_u8Counter]->FirstDelay == SCHED_u8LAUNCH_TIME)
				{
					Sched_astrTasks[Loc_u8Counter]->State == Sched_enuRunning;
					(Sched_astrTasks[Loc_u8Counter]->CallbackFn)();/* calling the task */
					Sched_astrTasks[Loc_u8Counter]->State = Sched_enuReady;
					Sched_astrTasks[Loc_u8Counter]->FirstDelay = Sched_astrTasks[Loc_u8Counter]->Periodicity;
				}/* if */
				Sched_astrTasks[Loc_u8Counter]->FirstDelay--;
			}/* if */
		}/* if */
	}/* for */
}/* Sched_vidSched */
/* 
	Description					:				raise the scheduler flag
	Parameter(s)				:				void
	Return							:				void	
*/
static void Sched_vidRaiseFlag(void)
{
	Sched_u8SchedulerFlag = FLAG_HIGH;
}/* Sched_vidRaiseFlag */
/* /////////////////////////////////////////////////////////////////// */
