/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: update.c
* DESCRIPTION: implementation of update function 
* 
* REV         AUTHOR      			DATE             DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    9/July/2012				Create
*
*********************************************************************************/

#include "update.h"
#include "C6747.h"

#pragma DATA_SECTION(update_func_table, ".data_func_table")
static struct  update_func_info  update_func_table[UPDATE_FUNC_COUNT+1];

struct  segment_info      update_segment_table[SEGMENT_COUNT+1];

char    update_buffer[BLOCK_SIZE];
static  Uint32   update_segment_ref = 0;
static  Uint32   update_func_count = 0;

/*
internal  function  declaration 
*/


Uint32 get_nand_addr(Uint32 base_addr,Uint32 index);
Uint16 function_table_update(Uint32 func_index,Uint32 func_entry);
Uint16 segment_table_update(struct segment_info seg, Uint32 index );
Uint16 update_segment_to_memory(char data[],struct segment_info seg);
Uint16 save_updated_func_table_to_nand(void);
Uint16 read_updated_func_table_from_nand(void);
Uint16 save_updated_segment_table_to_nand(void);
Uint16 read_updated_segment_table_from_nand(void);
Uint16 segment_save_to_flash(char update_data[],Uint32 nand_addr,Uint32 data_len);
Uint16 update_process(char *data_ptr,Uint32 mem_addr,Uint32 data_len,Uint32 func_index,Uint32 seg_index);
Uint32 get_update_buffer_handle(void);

/*   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *   */

Uint16 update_patch()
{ 
   struct   patch_header  *patch;
   char *buf_ptr  = update_buffer;
   char *data_ptr = update_buffer + PATCH_DATA_OFFSET;
   patch = (struct  patch_header  *)update_buffer;
   update_process(data_ptr,patch->patch_mem_addr,patch->patch_mem_size,patch->patch_func_index,patch->patch_segment_index);

   return   UPDATE_SUCCESS;
}


Uint32 get_update_buffer_handle(void)
{
  return (Uint32)update_buffer;
}

Uint32  get_update_func_table_handle(void)
{
  return (Uint32)update_func_table;
}
Uint16 init_update()
{
       Uint32  data_len = sizeof(struct update_func_info)*UPDATE_FUNC_COUNT;
	   char *ptr = (char *)update_func_table;
	   int i =0;

	   for(i = 0;i < data_len;i++)
	   	ptr[i]=0x0;
	   
	  data_len = sizeof(struct segment_info)*SEGMENT_COUNT;
	  ptr = (char *)update_segment_table;
	  
	  for(i = 0;i < data_len;i++)
	   	ptr[i]=0x0;	 
	
	 
return   UPDATE_SUCCESS;
}

Uint16 update_process(char *data_ptr,Uint32 mem_addr,Uint32 data_len,Uint32 func_index,Uint32 seg_index)
{
	 struct segment_info seg;
	 init_update();
	 seg.nand_addr = get_nand_addr(SEGMENT_DATA_BASE_ADDR,seg_index);
	 seg.mem_addr = mem_addr;
	 seg.mem_size = data_len;
	 
	 update_segment_to_memory(data_ptr,seg);
	 segment_table_update(seg,seg_index);
	 function_table_update(func_index,mem_addr);

	 save_updated_func_table_to_nand();
	 save_updated_segment_table_to_nand();
	 segment_save_to_flash(data_ptr,seg.nand_addr,data_len);

}


Uint16 function_table_update(Uint32 func_index,Uint32 func_entry)
{

	if(func_index > UPDATE_FUNC_COUNT)
		{
		return  UPDATE_ERROR;	
		}
	else
		{
		update_func_table[func_index].func_entry =(Func_ptr)func_entry;
		update_func_table[func_index].func_version++;
		}
	
return   UPDATE_SUCCESS;	
}



Uint16 segment_save_to_flash(char update_data[],Uint32 nand_addr,Uint32 data_len)
{
		 Uint32 src_addr =(Uint32)update_data;
		 nand_erase_one_block(nand_addr);  
		 nand_write(src_addr,nand_addr,data_len);
		 
return   UPDATE_SUCCESS;	
}



Uint16 segment_table_update(struct segment_info seg, Uint32 index )
{
  	update_segment_table[index].nand_addr = seg.nand_addr;
	update_segment_table[index].mem_addr = seg.mem_addr;
	update_segment_table[index].mem_size = seg.mem_size;
return   UPDATE_SUCCESS;
}



Uint16 update_segment_to_memory(char data[],struct segment_info seg)
{
  Uint32 data_addr = (Uint32)data;
  move_memory(data_addr, seg.mem_addr, seg.mem_size);

return   UPDATE_SUCCESS;
}




Uint32 get_nand_addr(Uint32 base_addr,Uint32 index)
{
   return  (base_addr + index *64); 
}



struct  segment_info * get_segment_table(void)
{
   return update_segment_table;
}


Uint16 save_updated_func_table_to_nand(void)
{
		Uint32  data_len = sizeof(struct update_func_info)*UPDATE_FUNC_COUNT;
		nand_erase_one_block(UPDATE_FUNCTION_TABLE_ADDR);
		nand_write(update_func_table,UPDATE_FUNCTION_TABLE_ADDR,data_len);
return   UPDATE_SUCCESS;
}

Uint16 read_updated_func_table_from_nand(void)
{
    Uint32  data_len = sizeof(struct update_func_info)*UPDATE_FUNC_COUNT;
	nand_read(UPDATE_FUNCTION_TABLE_ADDR,update_func_table,data_len);
	return   UPDATE_SUCCESS;
}

Uint16 save_updated_segment_table_to_nand(void)
{
       	Uint32  data_len = sizeof(struct segment_info)*SEGMENT_COUNT;
		nand_erase_one_block(SEGMENT_TABLE_STORAGE_ADDR);
		nand_write(update_segment_table,SEGMENT_TABLE_STORAGE_ADDR,data_len);	
return   UPDATE_SUCCESS;
}

Uint16 read_updated_segment_table_from_nand(void)
{
	Uint32  data_len = sizeof(struct segment_info)*SEGMENT_COUNT;
	nand_read(SEGMENT_TABLE_STORAGE_ADDR,update_segment_table,data_len);
	return   UPDATE_SUCCESS;
}


Uint16 load_updatable_segment()
{
  int i = 0;
  while(update_segment_table[i].mem_size !=0)
  {
  nand_read(update_segment_table[i].nand_addr, update_buffer, update_segment_table[i].mem_size);
  update_segment_to_memory(update_buffer,update_segment_table[i]);
  i++;
  }
  return   UPDATE_SUCCESS;
}

Uint16 load_updatable_partion()
{
 read_updated_func_table_from_nand();
 read_updated_segment_table_from_nand();
 load_updatable_segment();
 return   UPDATE_SUCCESS;
}






