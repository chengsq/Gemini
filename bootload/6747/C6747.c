/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: C6747.c
* DESCRIPTION: C6747 basic operation and init
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    4/July/2012			Create
*
*********************************************************************************/

/*
 *  Board Setup
 *
 */

#include "C6747.h"
#include "C6747_i2c.h"

/* ************************************************************************ *
 *                                                                          *
 *  C6747_wait( delay )                                                     *                                                                        *
 *      Wait in a software loop for 'x' delay                               *
 *                                                                          *
 * ************************************************************************ */
void C6747_wait( Uint32 delay )
{
    volatile Uint32 i;
    for ( i = 0 ; i < delay ; i++ ){ };
}

/************************************************************************** *
 *                                                                          *
 *  C6747_waitusec( usec )                                                  *                                                                          *
 *      Wait in a software loop for 'x' microseconds                        *
 *                                                                          *
 * ************************************************************************ */
void C6747_waitusec( Uint32 usec )
{
    C6747_wait( usec * 3 );
}

void _wait( Uint32 delay )
{
    volatile Uint32 i;
    for ( i = 0 ; i < delay ; i++ ){ };
}




/* ************************************************************************ *
 *                                                                          *
 *  C6747_init( )                                                          **                                                                          *
 *      Setup I2C, MSP430, & I2C GPIO Expander                              *
 *                                                                          *
 * ***********************************************************************  */
Int16 C6747_init( )
{

   sysinit();
   TIMER0_TRC=0x0;
    return 0;
}

/****************************************************************************
 *                                                                          *
 *  _resetEMIF( )                                                           *
 *                                                                          *
 *      Reset EMIF timings to have MAX timeout                              *
 *                                                                          *
 *      @ 594 MHz, AEMIF clock is set to ( 99 MHz or 10.1 ns )              *
 *                                                                          *
 *      chip_select     <- Chip Select [2-5]                                *
 *                                                                          *
 ************************************************************************** */
Int16 _resetEMIF( Uint16 chip_select )
{
     Uint32 emif_max_timeout = 0
        | ( 0  << 31 )      // Select Strobe    [ Normal ]
        | ( 0  << 30 )      // Extended Wait    [ Disabled ]
        | ( 15 << 26 )      // Write Setup      [ 151.5 ns ]
        | ( 31 << 20 )      // Write Strobe     [ 313.1 ns ]
        | ( 7  << 17 )      // Write Hold       [  70.7 ns ]
        | ( 15 << 13 )      // Read Setup       [ 151.5 ns ]
        | ( 31 << 7 )       // Read Strobe      [ 313.1 ns ]
        | ( 7  << 4 )       // Read Hold        [  70.7 ns ]
        | ( 3  << 2 )       // Turn Around      [  30.3 ns ]
        | ( 0  << 0 );      // Bus Size         [ 8-bit Bus ]


    switch ( chip_select )
    {
       case 3://2
            AEMIF_A1CR = emif_max_timeout;

            AEMIF_NANDFCR &= ~( 1 << 0 );       // NAND Flash [ OFF ]
            AEMIF_A2CR = emif_max_timeout;

            AEMIF_NANDFCR &= ~( 1 << 1 );       // NAND Flash [ OFF ]
            AEMIF_A3CR = emif_max_timeout;

            AEMIF_NANDFCR &= ~( 1 << 2 );       // NAND Flash [ OFF ]
            AEMIF_A4CR = emif_max_timeout;

            AEMIF_NANDFCR &= ~( 1 << 3 );       // NAND Flash [ OFF ]
                          
            
            
            break;
       case 2://3
            AEMIF_A2CR = emif_max_timeout;

            AEMIF_NANDFCR &= ~( 1 << 1 );       // NAND Flash [ OFF ]
            break;
        case 4:
            AEMIF_A3CR = emif_max_timeout;
            AEMIF_NANDFCR &= ~( 1 << 0 );       // NAND Flash [ Off ]
            break;
        case 5:
            AEMIF_A4CR = emif_max_timeout;
            AEMIF_NANDFCR  &= ~( 1 << 0 );       // NAND Flash [ Off ]
            break;
        default:
            return -1;
    }
    return 0;
}


Int16 _setupEMIF( Uint16 chip_select, Uint32 emif_timing, Uint16 emif_mode )
{

	AEMIF_A1CR = emif_timing;

	AEMIF_A2CR = emif_timing;
	AEMIF_A3CR = emif_timing;
	AEMIF_A4CR = emif_timing;
   	AEMIF_NANDFCR |= 0x02;

    return 0;
}
