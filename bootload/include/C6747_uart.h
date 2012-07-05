/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: C6747_uart.h
* DESCRIPTION: UART Header file
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    4/July/2012			Create
*
*********************************************************************************/


#ifndef __C6747_UART_H__
#define __C6747_UART_H__

#include "C6747.h"

/* ------------------------------------------------------------------------ *
 *  UART regs                                                               *
 * ------------------------------------------------------------------------ */

    typedef struct {
        volatile Uint32 RBR;
        volatile Uint32 IER;
        volatile Uint32 IIR;
        volatile Uint32 LCR;
        volatile Uint32 MCR;
        volatile Uint32 LSR;
                 Uint32 rsvd_18;
                 Uint32 rsvd_1c;
        volatile Uint32 DLL;
        volatile Uint32 DLH;
        volatile Uint32 PID1;
        volatile Uint32 PID2;
        volatile Uint32 PWREMU_MGMT;
    } UART_REGS;

    #define THR     RBR    // THR & RBR occupy the same memory location
    #define FCR     IIR    // FCR & IIR occupy the same memory location

    typedef struct {
        UART_REGS* regs;
    } UART_OBJ;

    static UART_OBJ UART_MODULE_0 = { ( UART_REGS* )UART0_BASE };
    static UART_OBJ UART_MODULE_1 = { ( UART_REGS* )UART1_BASE };
    static UART_OBJ UART_MODULE_2 = { ( UART_REGS* )UART2_BASE };

    typedef UART_OBJ* UART_Handle;

/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */

UART_Handle C6747_UART_open( Uint16 id, Uint32 baudrate );
Int16       C6747_UART_close( UART_Handle UartHandle );

Int16 C6747_UART_xmtReady( UART_Handle UartHandle );
Int16 C6747_UART_rcvReady( UART_Handle UartHandle );

Int16 C6747_UART_putChar( UART_Handle UartHandle, Uint8 data );
Int16 C6747_UART_getChar( UART_Handle UartHandle, Uint8* data );

#endif
