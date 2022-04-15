/* **************************************************************************************
**       Author      :	Michael S. Ibrahim
**       Date        :	April 01, 2022
**       Version     :	V01
**       SWC         :	main2
**       Description :	lab6 main2 file
** **************************************************************************************/
/* UART implementation */
void UART_vidInit(void)
{
  /* Enable Tx, Rx */
  /* configure character size ::::: 8 bits, with no parity, with one stop bit, with baud rate '9600'  */
  u8 Temp_UCSRC = 0x80; /* The MSB = 1 to access "UCSRC" */

  UCSRC = Temp_UCSRC;
  UBRRH = 0; /* The MSB = 0 to access "UBRRH" */
  UBRRL = 103;/* The baud rate least byte value */
}
void UART_vidSendByte(u8 Byte)
{
  while((UCSRA>>5)&0x01) == 0);
  UDR = Byte;
}
u8 UART_u8ReceiveByte(void)
{
  while((UCSRA>>7)&0x01) == 0);
  return(UDR);
}