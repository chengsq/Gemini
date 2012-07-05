/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: nand.h
* DESCRIPTION: nandflash header file 
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	   4/July/2012				Create
*
*********************************************************************************/

/*
 *  nandflash header file
 *
 */

#include "C6747.h"


#ifndef __NAND_H__
#define __NAND_H__


#define USE_ECC   1
#define DEBUG_NAND_ADDRESS  0 

/********************************************************************************** 
 *                
 * Flash Device - SAMSUNG NAND Flash Memory K9F5608U0B      
 *
 * *******************************************************************************/
#define MFG_SAMSUNG                 0xEC
#define K9K2G08U0M                  0xDA
#define K9K2G08U0M_PAGE_COUNT       64 * 2048            

#define DEV_K9F5608U0B              0x75
#define DEV_K9F5608U0B_PAGE_COUNT   32 * 2048 // 32 pages * 2048 blocks

#define DEV_K9F5608Q0B              0x35
#define DEV_K9F5608Q0B_PAGE_COUNT   32 * 2048 // 32 pages * 2048 blocks

#define DEV_K9F2808U0C              0x73
#define DEV_K9F2808U0C_PAGE_COUNT   32 * 1024 // 32 pages * 1024 blocks

#define DEV_K9K1208Q0C              0x36
#define DEV_K9K1208Q0C_PAGE_COUNT   32 * 4096 // 32 pages * 4096 blocks

#define DEV_SMCARD_128              0x79
#define DEV_SMCARD_128_PAGE_COUNT   32 * 8192 // 32 pages * 8192 blocks


#define MFG_STI                     0x20

#define DEV_NAND512W3A              0x76
#define DEV_NAND512W3A_PAGE_COUNT   32 * 4096

/* ------------------------------------------------------------------------ *
 *  Flash Memory Property Definitions                                       *
 * ------------------------------------------------------------------------ */
#define NAND_BASE                  0x62000000  // SNAND.CS0 BASE

#define NAND_PAGESIZE              2 * 1024
#define NAND_PAGESIZE_POW2         9
#define NAND_SPARESIZE             64
#define NAND_SPARESIZE_POW2        4
#define NAND_PAGES_PER_BLOCK       64
#define NAND_PAGES_PER_BLOCK_POW2  5

#define NAND_BLOCKSIZE             \
        NAND_PAGESIZE * NAND_PAGES_PER_BLOCK

#define NAND_BLOCKSIZE_POW2        \
        NAND_PAGESIZE_POW2 + NAND_PAGES_PER_BLOCK_POW2

/* ------------------------------------------------------------------------ *
 *  NAND Flash Command Codes                                                *
 * ------------------------------------------------------------------------ */
#define CMD_READ                    0x00
#define CMD_READ_CONFIRM            0x30
#define CMD_READ_HALF               0x01
#define CMD_READ_SPARE              0x50
#define CMD_READID                  0x90
#define CMD_RESET                   0xFF
#define CMD_POINTER_MAIN            0x00
#define CMD_POINTER_MAIN_HALF       0x01
#define CMD_POINTER_SPARE           0x50
#define CMD_PROGRAM                 0x80
#define CMD_PROGRAM_CONFIRM         0x10
#define CMD_COPYBACK                0x00
#define CMD_COPYBACK_CONFIRM        0x35
#define CMD_ERASE                   0x60
#define CMD_ERASE_CONFIRM           0xD0
#define CMD_STATUS                  0x70
#define CMD_CHIP1_STATUS            0xF1
#define CMD_CHIP2_STATUS            0xF2

/* ------------------------------------------------------------------------ *
 *  NAND Flash Status Register Definitions                                  *
 * ------------------------------------------------------------------------ */
#define CMD_STATUS_SUCCESS          0xFFFE
#define CMD_STATUS_ERROR            0x0001
#define CMD_STATUS_BUSY             0xFFBF
#define CMD_STATUS_READY            0x0040
#define CMD_STATUS_WPROTECT         0xFF7F
#define CMD_STATUS_NOWPROTECT       0x0080

/* ------------------------------------------------------------------------ *
 *  NAND Flash Memory Data Pointer                                          *
 * ------------------------------------------------------------------------ */
#define NAND_BASE_PTR       *( volatile Uint8* )( NAND_BASE + 0x00 )
#define NAND_CLE_PTR        *( volatile Uint8* )( NAND_BASE + 0x10 )
#define NAND_ALE_PTR        *( volatile Uint8* )( NAND_BASE + 0x08 )

#define NAND_ASSERT_CE( )   ;
#define NAND_DEASSERT_CE( ) ;

#define NAND_READ_RB        ( ( *( volatile Uint32* )( 0x68000064 ) ) & 0x01 )
//#define NAND_READ_RB        ( ( *( volatile Uint8* )( NAND_BASE + 0x64 ) ) & 1 )
/* ------------------------------------------------------------------------ *
 *  NAND Flash R/B functions                                                *
 * ------------------------------------------------------------------------ */
#define NAND_ERR_NOERROR            ( 0 )
#define NAND_ERR_TIMEOUT            ( -1 )





#define NAND_DATA           NAND_BASE_PTR

#define NAND_CMD( cmd )      NAND_CLE_PTR = cmd
#define NAND_CMD_CONFIRM(cmd)  	NAND_CLE_PTR = cmd



/****************************************************************************
**
*nand funtion return status macro
*
*****************************************************************************/

#define  NAND_STATUS_OK     0
#define  NAND_STATUS_ERROR  1



/****************************************************************************
**
*nand info struct define 
*
*****************************************************************************/

/***********************************************************************
 * struct nand_flash_dev - NAND Flash Device ID Structure
 * @name:	Identify the device type
 * @id:		device ID code
 * @pagesize:	Pagesize in bytes. Either 256 or 512 or 0
 *		If the pagesize is 0, then the real pagesize
 *		and the eraseize are determined from the
 *		extended id bytes in the chip
 * @erasesize:	Size of an erase block in the flash device.
 * @chipsize:	Total chipsize in Mega Bytes
 * @options:	Bitfield to store chip relevant options
 **********************************************************************/
 
struct nand_flash_dev {
	char *name;
	int id;
	unsigned long pagesize;
	unsigned long chipsize;
	unsigned long erasesize;
	unsigned long options;
};


/******************************************************************************
 * struct nand_manufacturers - NAND Flash Manufacturer ID Structure
 * @name:	Manufacturer name
 * @id:		manufacturer ID code of device.
******************************************************************************/
struct nand_manufacturers {
	int id;
	char * name;
};

struct nand_chip_info{
		struct nand_flash_dev dev_info;
		struct nand_manufacturers  manufacturer;
};

/****************************************************************************
*
*   nandflash address  write function and macro 
*
*****************************************************************************/

#if (DEBUG_NAND_ADDRESS==1)
void  NAND_ADDR_4( Uint32  addr ) ;
void  NAND_ADDR_3( Uint32  addr ) ;
void  NAND_ADDR_2( Uint32  addr ) ;
void  NAND_ADDR_1( Uint32  addr ) ;
void  NAND_ADDR_0( Uint32  addr ) ;
#else
#define  NAND_ADDR_4(addr)  NAND_ALE_PTR = 0;				NAND_ADDR_3(addr);
#define  NAND_ADDR_3(addr)  NAND_ALE_PTR = 0;				NAND_ADDR_2(addr);
#define  NAND_ADDR_2(addr)  NAND_ALE_PTR = (addr)&0xff;		NAND_ADDR_1(addr);
#define  NAND_ADDR_1(addr)  NAND_ALE_PTR = (addr>>8)&0xff;	NAND_ADDR_0(addr);
#define  NAND_ADDR_0(addr)  NAND_ALE_PTR = (addr>>16)&0xff;
#endif



/****************************************************************************
**
*nandflash operation function declaration 
*
*****************************************************************************/

Int16 nand_init(void);
Int16 nand_info(struct nand_chip_info nandinfo);
Int16 nand_read( Uint32 src, Uint32 dst, Uint32 len);
Int16 nand_write( Uint32 src, Uint32 dst, Uint32 len);
Int16 nand_write_page( Uint32 src, Uint32 dst, Uint32 len);
Int16 nand_read_page( Uint32 src, Uint32 dst,Uint32 len);
Int16 nand_erase_block(Uint32 addr,Uint32 block_count);
#endif

























