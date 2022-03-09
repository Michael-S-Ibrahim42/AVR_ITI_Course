/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	March 05, 2022
**       Version     :	V01
**       SWC         :	Port
**       Description :	Port module of the MCU "ATMEGA32A"
** **************************************************************************************/
#ifndef _PORT_CFG_H
#define _PORT_CFG_H

  /* Write Down Pins Initial Directions */
  /* You have 32 Pins from pin0 to pin31 ... To configure Directions  :Write 0 to make the pin input and 1 to make the pin output */
  #define PORT_u32DIR           0b00000000000000000000000000000000
  /* You have 32 Pins from pin0 to pin31 ... To configure input modes :Write 0 to make the pin high impendance and 1 to make the pin pull up */
  #define PORT_u32VAL           0b00000000000000000000000000000000



#endif