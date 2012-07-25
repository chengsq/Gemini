/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: C6747_i2c.h
* DESCRIPTION:  I2C header file
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    4/July/2012			Create
*
*********************************************************************************/


#ifndef __C6747_I2C_H__
#define __C6747_I2C_H__

#include "C6747.h"


/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
Int16 C6747_I2C_init ( );
Int16 C6747_I2C_close( );
Int16 C6747_I2C_write( Uint16 i2c_addr, Uint8* data, Uint16 len );
Int16 C6747_I2C_read ( Uint16 i2c_addr, Uint8* data, Uint16 len );

#endif
