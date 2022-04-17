/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 16, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler software component
** **************************************************************************************/
#ifndef SCHED_H_
#define SCHED_H_
  /* //////////////////////////// Defined Types  /////////////////////// */
	/* Error types */
	typedef enum{
		Sched_enuOk,
		Sched_enuNullPtr,
		Sched_enuPriorityError,
		Sched_enuPriorityExist
	}Sched_tenuError;  
	/* Tasks states */
	typedef enum
	{
		Sched_enuReady,
		Sched_enuRunning,
		Sched_enuWaiting
	}Sched_tenuTaskState;
	/* Task structure */
	typedef struct {
		tpfCallbackFn 					CallbackFn; /* the task body */
		u16 										Priority;   /* the task priority, options are from 0 to number of tasks-1, duplication is forbidden */
		u16 										FirstDelay;	/* The task first delay time, unit of entry is in "millisecond" */
		u16 										Periodicity;	/* the task periodicity time, unit of entry is in "millisecond" */
		Sched_tenuTaskState 		State;				/* the state options are in "Sched.h" under "Tasks states" */
	}Sched_tstrTask;
	/* /////////////////////////////////////////////////////////////////// */

  /* //////////////////////////// Interface fns  /////////////////////// */
	/* 
		Description					:				Init the scheduler
		Parameter(s)				:				void
		Return							:				void	
	*/
	void Sched_vidInit(void);
	/* 
		Description					:				start the scheduler
		Parameter(s)				:				void
		Return							:				void	
	*/
	void Sched_vidStart(void);
	/* 
		Description					:				Register runnables
		Parameter(s)				:				The runnable of type "Task structure" in "Sched.h"
		Return							:				Error status of type "Error types" in "Sched.h"	
	*/
	Sched_tenuError Sched_enuRegisterRunnable(Sched_tstrTask* Copy_pstrTask);
	/* /////////////////////////////////////////////////////////////////// */
#endif
