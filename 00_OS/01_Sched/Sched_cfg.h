/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 16, 2022
**       Version     :	V01
**       SWC         :	Sched
**       Description :	Scheduler software component
** **************************************************************************************/
#ifndef SCHED_CFG_H_
#define SCHED_CFG_H_
  /* //////////////////////////// Headers inclusion //////////////////// */
  #include "Gpt.h"
  /* //////////////////////////// MACROS  ////////////////////////////// */
  #define SCHED_u8TICK_MS				        1
  /* Define your system max number of concurrent tasks */
  #define SCHED_u8MAX_TASKS			        5
  /* Define your timer */
  #define SCHED_u8TIMER_CHANNEL         GPT_u8CH0
  /* /////////////////////////////////////////////////////////////////// */
#endif 
