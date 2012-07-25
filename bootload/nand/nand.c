/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: nand.c
* DESCRIPTION: basic operation functions  of  nandflash 
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	   4/July/2012			Create
*
*********************************************************************************/
#include "C6747.h"
#include "nand.h"




Uint32  nand_timeout  =  0x00100000 ;



void FLASHGPIO_init()
{
	PINMUX13 = 0x11111111;
	PINMUX14 = 0x88111111;
	PINMUX15 = 0x11888888;
    PINMUX16 = 0x11111111;
    PINMUX18 = 0x11111110;

}

/* **************************************************************************
 *                                                                          *
 *  _NAND_readECC( )                                                        *
 *                                                                          *
 *      Read ECC calcualtions                                               *
 *                                                                          *
 * ************************************************************************** */
#ifdef USE_ECC
    inline Uint32 _NAND_readECC( void )
    {
        return AEMIF_NANDECC2;
    }
#endif

/* ************************************************************************** *
 *                                                                          *
 *  _NAND_startECC( )                                                       *
 *                                                                          *
 *      Start ECC calcualtions                                              *
 *                                                                          *
 * **************************************************************************- */
#ifdef USE_ECC
    inline void _NAND_startECC( void )
    {
        _NAND_readECC( );
        AEMIF_NANDFCR |= 0x0100;
    }
#endif




/*************************************************************************** *
 *                                                                          *
 *  _NAND_busywait( timeout )                                               *
 *                                                                          *
 *      Poll the external RDY/BSY pin                                       *
 *                                                                          *
 ****************************************************************************/
Int16 _nand_busywait( Int32 timeout )
{
    /*
     *  Short delay to let the Ready/Busy signal go LOW
     */
    _wait( 200 );

    /*
     *  Wait while the device is busy
     */
    while(( ! NAND_READ_RB ) &&  ( timeout-- > 0 ) );

    if ( timeout == 0 )
        return NAND_ERR_TIMEOUT;
    else
        return 0;
}

/* **************************************************************************
 *                                                                          *
 *  _NANDFLASH_init( )                                                      *
 *      Initialize the NAND Flash                                           *
 *                                                                          *
 *  Note:                                                                   *
 *      The Write Protect on the NAND Flash is disabled.  This allows the   *
 *      erase & write NAND flash to work.                                   *
 *                                                                          *
 * ************************************************************************** */
Int16 nand_init( )
{   
	Uint32 acfg2;

    /********************************************************************
     *                                                                  *
     *  NAND Flash timing parameters                                    *
     *                                                                  *
     *      EMIF.CLK freq   = PLL1/6 = 594/6 = 99 MHz                   *
     *      EMIF.CLK period = 1/99 MHz = 10.1 ns                        *
     *                                                                  *
     *****************************************************************-*/
/*	acfg2=0x00a00504;*/
 acfg2 = 0
		| ( 0 << 31 )           // selectStrobe
       	| ( 0 << 30 )           // extWait
      	| ( 2 << 26 )           // writeSetup      //   0 ns//0
      	| ( 8 << 20 )           // writeStrobe     //  50 ns
      	| ( 2 << 17 )           // writeHold       //   0 ns
      	| ( 2 << 13 )           // readSetup       //   0 ns//0
      	| ( 6 << 7 )            // readStrobe      //  80 ns
      	| ( 2 << 4 )            // readHold        //  30 ns
       	| ( 3 << 2 )            // turnAround      //  10 ns//2
       	| ( 0 << 0 );           // asyncSize       // 8-bit bus
	_resetEMIF( EMIF_CS3 );
    _setupEMIF( EMIF_CS3, acfg2, EMIF_NAND_MODE );

    /* *****************************************************************
     *                                                                  *
     *  Note: If NANDFLASH_CE_DO_CARE is defined, then CE will be low   *
     *        during read/write/erase operations.                       *
     *                                                                  *
     *        Else if NANDFLASH_CE_DO_NOT_CARE is defined, then CE will *
     *        only be low during accesses to the NAND Flash device.     *
     *                                                                  *
     * **************************************************************** */


    NAND_CMD( CMD_RESET );              // Reset NAND Flash

    if ( _nand_busywait( nand_timeout ) )
        return NAND_ERR_TIMEOUT;

    return 0;
}


Int16 nand_info(struct nand_chip_info nandinfo )
{

    NAND_CMD( CMD_READID );        
 	NAND_ADDR_0( 0 );
	//TODO
    return NAND_STATUS_OK;
}


Int16 nand_erase_one_block(Uint32 addr)
{
    NAND_CMD(CMD_ERASE);                     /* Erase block*/
	NAND_ADDR_2( addr );
	NAND_CMD_CONFIRM( CMD_ERASE_CONFIRM );    /*Confirm Erase*/

    if ( _nand_busywait( nand_timeout ) )    
       {
            return NAND_ERR_TIMEOUT;         /*Timeout Error*/
       }
	
	NAND_CMD_CONFIRM( CMD_STATUS );          /*Check Status*/

	if ( NAND_DATA & CMD_STATUS_ERROR )
           return NAND_STATUS_ERROR;
	
   return NAND_STATUS_OK;
}

Int16 nand_erase_block(Uint32 addr,Uint32 block_count)
{
  Uint32 i = 0;
  for(i = 0;i < block_count;i++)
  	{
		addr = addr + (i * NAND_PAGES_PER_BLOCK);
    	nand_erase_one_block(addr);
	}
  return NAND_STATUS_OK;
}
Int16 nand_read_page( Uint32 src, Uint32 dst,Uint32 len)
{
	Uint32 j;
	volatile Uint8* dst8 = (volatile Uint8*) dst;
		
    NAND_CMD( CMD_READ );           /* Read page command */
    NAND_ADDR_4( src );
    NAND_CMD_CONFIRM( CMD_READ_CONFIRM );
		

    if ( _nand_busywait( nand_timeout ) )
      {
            return NAND_ERR_TIMEOUT;    /* Timeout Error*/
      }
	
	for ( j = 0 ; j < len ; j++ ) 	/* Read MAIN array*/
            *dst8++ = NAND_DATA;        
	/*	
     for ( j = 0 ; j < NAND_SPARESIZE ; j++ )  
			*dst8++ = NAND_DATA;
	*/
 return NAND_STATUS_OK;
}


Int16 nand_write_page( Uint32 src, Uint32 dst, Uint32 len)
{
	Uint32 j;
    volatile Uint8* src8 = (volatile Uint8*) src;
	   
      //NAND_ASSERT_CE( );             /* Assert CE ( for CE-care devices )*/

        NAND_CMD(CMD_PROGRAM);        /* Program page*/
        NAND_ADDR_4(dst);
	
		for ( j = 0 ; j < len ; j++ )   /* Write MAIN array    */           
			NAND_DATA = *src8++;			
		for ( j = 0 ; j < NAND_SPARESIZE ; j++ ) 
            NAND_DATA = 0xFF;
            		
        NAND_CMD_CONFIRM( CMD_PROGRAM_CONFIRM ); // Confirm Program*/

		if ( _nand_busywait( nand_timeout ) )
        { 
            return NAND_ERR_TIMEOUT;       /* Timeout Error*/
        }

        NAND_CMD( CMD_STATUS );           	/* Check Status    */ 
        
        if ( NAND_DATA & CMD_STATUS_ERROR )
            return NAND_STATUS_ERROR;
	
   return NAND_STATUS_OK;
}


Int16 nand_write( Uint32 srcaddr, Uint32 dstpage, Uint32 len)
{
    Uint32 PageCount = (len/NAND_PAGESIZE);
	Uint32 i;

	for(i = 0; i < PageCount; i++)
		{
		nand_write_page(srcaddr,dstpage,NAND_PAGESIZE);
		srcaddr = srcaddr + NAND_PAGESIZE;
		dstpage++;
		}
	
	len = len - PageCount*NAND_PAGESIZE;
	nand_write_page(srcaddr,dstpage,(len));

  return NAND_STATUS_OK;
}

Int16 nand_read( Uint32 srcpage, Uint32 dstaddr, Uint32 len)
{
	Uint32 PageCount = (len/NAND_PAGESIZE);
	Uint32 i;
	
	for(i = 0; i < PageCount; i++)
		{
		nand_read_page(srcpage,dstaddr,NAND_PAGESIZE);
		dstaddr = dstaddr + NAND_PAGESIZE;
		srcpage++;
		}
	len = len - PageCount*NAND_PAGESIZE;
	nand_read_page(srcpage,dstaddr,len);

  return NAND_STATUS_OK;	 
}



#if (DEBUG_NAND_ADDRESS==1)
void  NAND_ADDR_4( Uint32  addr ) 
{
	NAND_ALE_PTR = 0;
	NAND_ADDR_3( addr );
}
	
void NAND_ADDR_3(Uint32  addr ) 
{
	NAND_ALE_PTR = 0;
	NAND_ADDR_2( addr );
}
	
void NAND_ADDR_2( Uint32 addr ) 
{
	NAND_ALE_PTR = (addr) & 0xff;
	NAND_ADDR_1( addr );
}

void NAND_ADDR_1( Uint32 addr )
{ 
	NAND_ALE_PTR = (addr >> 8) & 0xff;
	NAND_ADDR_0( addr );
}
void NAND_ADDR_0( Uint32 addr )
{
	NAND_ALE_PTR = (addr >> 16) & 0xff; 
}

#endif

