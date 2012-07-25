/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: update.h
* DESCRIPTION: head file of update  include basic update  function declerations
* type defination
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    9/July/2012				Create
*
*********************************************************************************/


#ifndef     __UPDATE_H__
#define     __UPDATE_H__
#include "C6747.h"
typedef    void (*Func_ptr)(void);


/* struct function_info - the indirect reference function table type defination
 * @id:			Identify the updateble  function
 * @version:    the version of the update function	
 * @entry:	    the entry point of the update function  
 * @reserved     for future extend use
 */
struct  update_func_info
{
  Uint32  func_id;
  Uint32  func_version;
  Func_ptr  func_entry;
  Uint32  reserved;
};


struct  segment_info
{
  Uint32  nand_addr;
  Uint32  mem_addr;
  Uint32  mem_size;
};

struct   patch_header
{
 Uint32   patch_header_ident;
 Uint32   patch_mem_addr;
 Uint32   patch_mem_size;
 Uint32   patch_func_index;
 Uint32   patch_segment_index;
 Uint32   patch_reserved;
 Uint32   patch_reserved1;
 Uint32   patch_reserved2;
};

  
#define  UPDATE_FUNC_COUNT      10  
#define  SEGMENT_COUNT 			30

/**
define the status of upade function
*/

#define  UPDATE_SUCCESS   1
#define  UPDATE_ERROR     0

#define  UPDATE_FUNCTION_TABLE_ADDR   (0)        /*the first block used to storage the  update function table*/
#define  SEGMENT_TABLE_STORAGE_ADDR   (1*64)   /*the second block of nandflash used to storage the update segment table index infomation */
#define  SEGMENT_DATA_BASE_ADDR       (4*64)
#define  BLOCK_SIZE     (1024*2*64)


#define PATCH_DATA_OFFSET  (32)

struct  segment_info * get_segment_table(void);
Uint16 update_patch();
Uint32 get_update_buffer_handle(void);
Uint32 get_update_func_table_handle();
#endif
