
/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: boot.c
* DESCRIPTION: boot 
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	   17/July/2012			Create
*
*********************************************************************************/
#include "elf_loader.h"

#define SEGMENT_TABLE_LENGTH  	   (30*3*4)
#define UPDATE_FUNC_TABLE_LENGTH   (10*4*4)
#define UPDATE_FUNC_TABLE_ADDR     (0xC1040000)
#define UPDATE_SEGMENT_TABLE_ADDR  (0xC1060000)

#define  BLOCK_BASE (10*64)  
#define  UPDATE_FUNCTION_TABLE_ADDR   (BLOCK_BASE+0)        /*the first block used to storage the  update function table*/
#define  SEGMENT_TABLE_STORAGE_ADDR   (BLOCK_BASE+(1*64))    /*the second block of nandflash used to storage the update segment table index infomation */
#define  SEGMENT_DATA_BASE_ADDR       (BLOCK_BASE+(4*64))
#define  NAND_ELF_READ_SIZE           (2048*64*2)
#define  NAND_ELF_ADDR                (BLOCK_BASE+(2*64))

#define  NAND_AIS_ADDR 				  (1*64)
#define  NAND_AIS_READ_SIZE           (2048*64)

#define  DEBUG_PRINT  uart_print_string 

static unsigned char *update_func_table_ptr = (unsigned char *) UPDATE_FUNC_TABLE_ADDR;
static unsigned char *update_segment_table_ptr = (unsigned char *) UPDATE_SEGMENT_TABLE_ADDR;

static  unsigned char nand_read_buf[NAND_ELF_READ_SIZE];
static  unsigned char *recv_buff = nand_read_buf;

Uint32 bootentry;
extern unsigned char data[];
/************************************************
declearation of  fucntion 
************************************************/

Int16  read_elf_from_nand();
Uint16 read_updated_func_table_from_nand(void);
Uint16 save_updated_func_table_to_nand(void);
Uint16 save_updated_segment_table_to_nand(void);
Uint16 read_updated_segment_table_from_nand(void);
void   jump_to_elf_entry( struct elf_parser info);
Int16  save_elf_to_nand();
Uint16 pre_boot();
Int16  write_ais_to_nand();
Int16  read_ais_from_nand();
Uint32 test_nand_write(unsigned char *src,unsigned char *dst, Uint32 size);

Uint16 do_boot()
{
 struct elf_parser info;
 Uint16 update_flag = 0;
 DEBUG_PRINT("do_boot------------\r\n");

 update_flag = pre_boot();
 if(update_flag == 1)
	{
	 info.src_addr = recv_buff; 
	 DEBUG_PRINT("recieve   and save  sucess\r");
	} 
 else
	{
	  read_elf_from_nand();
	  DEBUG_PRINT("read elf from_nand\r  ");
	  info.src_addr = nand_read_buf;
	 }
	
	info.dst_addr = 0;
   
	component_load(&info);
	DEBUG_PRINT("load  elf success \r");
	
	if(update_flag == 0)
	{
		read_updated_func_table_from_nand();
		read_updated_segment_table_from_nand();
		DEBUG_PRINT("read_updated_func_table_from_nand\n\r   ");
	}
	else
		{
		save_elf_to_nand();
	 	save_updated_func_table_to_nand();
	 	save_updated_segment_table_to_nand();
		}
	
	DEBUG_PRINT("jump to elf entry  \r   ");
	jump_to_elf_entry(info);
	return 0;
}


Uint16  save_updated_func_table_to_nand(void)
{
    //Uint32  data_len = sizeof(struct update_func_info)*UPDATE_FUNC_COUNT;
    Uint32  data_len = UPDATE_FUNC_TABLE_LENGTH;
	nand_erase_one_block(UPDATE_FUNCTION_TABLE_ADDR);
	nand_write((Uint32)update_func_table_ptr,UPDATE_FUNCTION_TABLE_ADDR, data_len);
	return   0;
} 
	


Uint16 read_updated_func_table_from_nand(void)
{
    //Uint32  data_len = sizeof(struct update_func_info)*UPDATE_FUNC_COUNT;
    Uint32  data_len = UPDATE_FUNC_TABLE_LENGTH;
	nand_read(UPDATE_FUNCTION_TABLE_ADDR,update_func_table_ptr,data_len);
	return   0;
}

Uint16  save_updated_segment_table_to_nand(void)
{
    //Uint32  data_len = sizeof(struct update_func_info)*UPDATE_FUNC_COUNT;
    Uint32  data_len = UPDATE_FUNC_TABLE_LENGTH;
	nand_erase_one_block(SEGMENT_TABLE_STORAGE_ADDR);
	nand_write((Uint32)update_segment_table_ptr,SEGMENT_TABLE_STORAGE_ADDR, data_len);
	return   0;
} 
	


Uint16 read_updated_segment_table_from_nand(void)
{
	//Uint32  data_len = sizeof(struct segment_info)*SEGMENT_COUNT;
	Uint32  data_len = SEGMENT_TABLE_LENGTH;

	nand_read(SEGMENT_TABLE_STORAGE_ADDR,update_segment_table_ptr,data_len);
	return   0;
}


Uint16 pre_boot()
{
 Uint32 sec_count = 0;
 Uint32 min_count = 0;
 Uint16  update_flag = 0;  
 unsigned char *elf_buf_ptr = recv_buff;
 unsigned char  buf; 

 
for(min_count = 0;min_count < 5; min_count++)
 {
 for(sec_count = 0;sec_count < 0x50000; sec_count++)	
	{ if(uart_recv_data(&buf))
		{
         update_flag = 1;
		 break;
		}
    }
 
 if(update_flag == 1)
 	break;
}


if(update_flag == 1)
{
 uart_print_string("please input the elf file \r\n");
 while(1)
	{
    if(uart_recv_data(elf_buf_ptr))  
		{
		if(*elf_buf_ptr ==0xEF&& *(elf_buf_ptr-1) == 0xFD)
			{
				break;
			}
		elf_buf_ptr++;
    	}
	
    }
}
return update_flag;
}

void  jump_to_elf_entry( struct elf_parser info)
{
  bootentry = get_prog_entry(&info);
  asm(" MVKL _bootentry, B1");
  asm(" MVKH _bootentry, B1");
  asm(" LDW *B1, B1");
  asm(" NOP 4");
  asm(" B  B1");
  asm(" NOP 5");
}


Int16  read_elf_from_nand()
{
  nand_read(NAND_ELF_ADDR,(Uint32)nand_read_buf,NAND_ELF_READ_SIZE);
  return 0;
}


Int16  save_elf_to_nand()
{
	nand_erase_one_block(NAND_ELF_ADDR);
	nand_erase_one_block((NAND_ELF_ADDR+64));
	nand_write((Uint32)recv_buff, NAND_ELF_ADDR,NAND_ELF_READ_SIZE);
	return 0;
}

Int16  read_ais_from_nand()
{
  nand_read(NAND_AIS_ADDR,(Uint32)nand_read_buf,NAND_AIS_READ_SIZE);
  return 0;
}


Int16  write_ais_to_nand()
{
  Uint32 i = 0;
 nand_erase_one_block(NAND_AIS_ADDR);
 nand_write((Uint32)data, NAND_AIS_ADDR,13644);
 return 0;
}


Uint32 test_nand_write(unsigned char *src,unsigned char *dst, Uint32 size)
{
 Uint32 i = 0;
 for(i = 0;i < size;i++)
 	{
	if(src[i] != dst[i])
		return i;
 	}

  return 0;
}




