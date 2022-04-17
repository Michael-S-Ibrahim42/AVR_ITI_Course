/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 16, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler software component
** **************************************************************************************/
#ifndef SCHED_PRV_H_
#define SCHED_PRV_H_
  /* //////////////////////////// MACROS  ////////////////////////////// */
  #define SCHED_u8MAX_TIME_MS		                    ((u8)0xFF)
  /* Ticks to achieve 1ms */
  #define SCHED_u8TICKS_NUM                         250
  /* time to launch the task */
  #define SCHED_u8LAUNCH_TIME                       0
  /* Global interrupt mask */
  #define SCHED_u8GLOBAL_INT                        0b10000000
  /* /////////////////////////////////////////////////////////////////// */
  
  /* //////////////////////////// Private Fns ////////////////////////// */
  /* 
		Description					:				Select and run the tasks
		Parameter(s)				:				void
		Return							:				void	
	*/
  static void Sched_vidSched(void);
  /* 
		Description					:				raise the scheduler flag
		Parameter(s)				:				void
		Return							:				void	
	*/
  static void Sched_vidRaiseFlag(void);  
  /* /////////////////////////////////////////////////////////////////// */

#endif
