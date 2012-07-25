/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: C6747_uart.c
* DESCRIPTION: UART implementation
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    4/July/2012			Create
*
*********************************************************************************/


#include "C6747_uart.h"

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _UART_open( id, baudrate )                                              *
 *                                                                          *
 *      Open UART handle                                                    *
 *                                                                          *
 * ------------------------------------------------------------------------ */
UART_Handle C6747_UART_open( Uint16 id, Uint32 baudrate )
{
        UART_Handle uart_handle;
        Uint32 divisor;
		volatile Uint16 dummy;

        /*
         *  UART clk / baudrate
         *  = 150,000,000 / (900 * 16)
         */
        divisor = 150000000 / ( baudrate * 16);

        switch ( id )
        {
            case 0:
                uart_handle = ( UART_Handle )&UART_MODULE_0;
                break;
            case 1:
                uart_handle = ( UART_Handle )&UART_MODULE_1;
                break;
            case 2:
                uart_handle = ( UART_Handle )&UART_MODULE_2;
                break;
            default:
                return ( UART_Handle )-1;
        }

        uart_handle->regs->PWREMU_MGMT = 0;         // Reset UART TX & RX components

        C6747_wait( 100 );

        uart_handle->regs->DLL = (divisor & 0xff);  // Set baud rate
        uart_handle->regs->DLH = (divisor >> 8);
        
        uart_handle->regs->FCR = 0x0007;            // Clear UART TX & RX FIFOs
        uart_handle->regs->FCR = 0x0000;            // Non-FIFO mode
        uart_handle->regs->IER = 0x0007;            // Enable interrupts
        uart_handle->regs->LCR = 0x0003;            // 8-bit words,
                                                    // 1 STOP bit generated,
                                                    // No Parity, No Stick paritiy,
                                                    // No Break control
        uart_handle->regs->MCR = 0x0000;            // RTS & CTS disabled,
                                                    // Loopback mode disabled,
                                                    // Autoflow disabled

        uart_handle->regs->PWREMU_MGMT = 0xE001;    // Enable TX & RX componenets

		// Clear any pre-existing characters
        dummy = uart_handle->regs->THR;
	    return uart_handle;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _UART_close( uart_handle )                                              *
 *                                                                          *
 *      Close UART handle                                                   *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 C6747_UART_close( UART_Handle uart_handle  )
{
    return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _UART_xmtReady( uart_handle )                                           *
 *                                                                          *
 *      Check if Transmitter is ready to send                               *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 C6747_UART_xmtReady( UART_Handle uart_handle )
{
    Uint8 lsr_status;

	lsr_status = uart_handle->regs->LSR;
	if (lsr_status & 0x60)
	    return 0;  // Ready to transmit
	else
	    return 1;

}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _UART_putChar( uart_handle, data )                                      *
 *                                                                          *
 *      Send 1 byte of serial data                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 C6747_UART_putChar( UART_Handle uart_handle, Uint8 data )
{
    uart_handle->regs->THR = data;

    return 0;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _UART_rcvReady( uart_handle )                                           *
 *                                                                          *
 *      Check if Receiver is ready to read                                  *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 C6747_UART_rcvReady( UART_Handle uart_handle )
{
    Uint8 lsr_status;

	lsr_status = uart_handle->regs->LSR;
	if (lsr_status & 0x1)
	    return 0;  // Data ready
	else
	    return 1;
}

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  _UART_getChar( uart_handle, data )                                      *
 *                                                                          *
 *      Recv 1 byte of serial data                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
Int16 C6747_UART_getChar( UART_Handle uart_handle, Uint8* data )
{
    *data = uart_handle->regs->THR;

    return 0;
}
