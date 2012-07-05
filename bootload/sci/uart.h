/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: uart.h
* DESCRIPTION: head file of uart.c include basic uart function declerations
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    4/July/2012				Create
*
*********************************************************************************/

#ifndef  __UART_H__
#define  __UART_H__

void uart_open(void);
void uart_print_char(char ch);
void uart_print_string(char *str);
void uart_print_int(int digit);

#endif