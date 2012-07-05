
/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: uart.c
* DESCRIPTION: user friendly  Uart API based on C6747_uart.c
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    4/July/2012			Create
*
*********************************************************************************/

#include "C6747_uart.h"
#include "uart.h"
#include "C6747.h"


void uart_open(void )
{
  UART_Handle uart;
  PINMUX11 = 0x00001100;
  uart = C6747_UART_open( 1, 19200);
}


void uart_print_char(char ch)
{
	UART_Handle uart_handle = (UART_Handle) &UART_MODULE_1;
	
	while(!(uart_handle->regs->LSR & 0x60));/*wait until the Tx buffer is empty*/
	
	uart_handle->regs->THR = ch;  /*put the data into the Transmit hold register*/
}


void uart_print_string(char *str)
{
	while(*str != '\0'){
		uart_print_char(*str++);
	}
	
}

void uart_print_int(int digit)
{
   unsigned char  out[10];
    int i,  j, len; 

    for (i = 0; i < 9; i++)
    {
        out[i] = 0;
    }

    i = 0;
    len = 0;

    if (digit == 0)
    {
        uart_print_char('0');

        return ;
    }

    while (digit > 0)
    {

        j = digit % 10;
        digit = digit / 10;
        out[i++] = j;
        len++;
    }

    while ((--len) >= 0)
    {
        uart_print_char((char)('0' + out[len]));
    }
    uart_print_string("\r\n");	
}







