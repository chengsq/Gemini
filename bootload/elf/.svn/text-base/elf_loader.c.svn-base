
/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: ELFLoader.c
* DESCRIPTION: basic operations of parsing the elf file
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	   4/July/2012			Create
*
*********************************************************************************/

#include "elf.h"
#include "nand.h"
#include "elf_loader.h"
#include "C6747.h"

static struct prog_loader Segment[PROGSEG_COUNT];
static Uint32 nand_page_index = 0;
static Uint32 seg_count = 0;

Uint16  move_memory(Uint32 src_addr, Uint32 dst_addr, Uint32 size)
{
	Uint8* dst = (Uint8*)dst_addr;
	Uint8* src = (Uint8*)src_addr;
 	while(size)
	{
		size--;
	    *dst = *src;
		src++;
		dst++;
	}

	return 0;
}

Uint16 component_load(struct elf_parser *parse_info)
{
   return  elf_prog_segment_loader(parse_info,Segment,PROGSEG_COUNT);
}


Uint16  elf_prog_segment_loader(struct elf_parser*parser_info, struct prog_loader Segment[],int progseg_count)
{
	struct elf32_hdr	*elf_header = 0;	
	struct elf32_phdr   *segment_base = 0;
	struct elf32_phdr    *segment_entry = 0;
	
	Uint32 elf_src_addr = 0;
	Int32  segment_count = 0;
	Int32  i = 0;
	
	/*initialize the proseg for ccs4 don't initialize automaticly*/
	for(i=0;i<progseg_count;i++)
	{
		Segment[i].prog_header = 0 ;
		Segment[i].index = i;
	}


	elf_src_addr = (Uint32)parser_info->src_addr;  	//ELF文件在内存中的地址
	
	elf_header = (struct elf_hdr*)elf_src_addr; //ELF文件头
	segment_base =(struct elf32_phdr*)(elf_src_addr + elf_header->e_phoff);  //program header的起始地址

	segment_count = elf_header->e_phnum;   //program segment  count
	seg_count  = segment_count;       //save segment  count
	for(i = 0 ;i < segment_count;i++ )
	{
		segment_entry = segment_base + i;
		Segment[i].prog_header = segment_entry;
		Segment[i].index = i;
		load_to_memory(Segment[i],elf_src_addr);
	}
	
return 0;
}

Uint16 load_to_memory(struct prog_loader seg,Uint32 base)
{
	Uint32  src,dst,size;
	char *buf = (char *)seg.prog_header;
	
	size = TRANS_DATA(buf,16);
	src = base + TRANS_DATA(buf,4);
	dst  = TRANS_DATA(buf,12);
	//src = (int)base + seg.ProgHeader->p_offset;  //since align ,this line is not always work well on all platform,so we use the above line instead 
	//dst =  (int)seg.ProgHeader->p_paddr;		
	move_memory(src,dst,size);
	return 0;
}


Elf32_Addr get_prog_entry(struct elf_parser *parser_info)
{
  struct elf32_hdr	*elf_header = 0;
  Uint32 elf_src_addr = 0;
  
  elf_src_addr = (Uint32)parser_info->src_addr;
  elf_header = (struct elf_hdr*)elf_src_addr;
  
  return elf_header->e_entry; 
}




/*
Uint16 segment_save_to_flash(struct prog_loader Seg,Uint32 base )
{
  struct  segment_info *segment = get_segment_table();
  struct  segment_info temp_info;
  Uint32  src,size;
  char *buf = 0;
  Uint32  i = 0; 	  

	buf = (char *)Seg.prog_header;
	size = TRANS_DATA(buf,16);
	src = base + TRANS_DATA(buf,4);
    nand_write(src,nand_page_index,size);

	temp_info.nand_addr = nand_page_index;
	temp_info.mem_addr = TRANS_DATA(buf,12);
	temp_info.mem_size = size;
	
	segment_table_update(temp_info,Seg.index);
	
	nand_page_index = nand_page_index + size/NAND_PAGESIZE + 1;
  
  	
}

*/




