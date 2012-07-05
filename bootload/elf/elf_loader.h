
/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: ELFLoader.h
* DESCRIPTION: elf loader header file 
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	  4/July/2012			Create
*
*********************************************************************************/

#ifndef __ELFLOADER_H__
#define __ELFLOADER_H__

#include "elf.h"
#include "C6747.h"

struct elf_parser{
	void *src_addr;
	void *dst_addr;
};


struct prog_loader
{
	struct elf32_phdr	 *prog_header;
	Elf32_Half			  index;
};


#define PROGSEG_COUNT 10

#define  TRANS_DATA(buf,base)   ((((int)(buf[base+3])&0xff)<<24)|(((int)(buf[base+2])&0xff)<<16)|(((int)(buf[base+1])&0xff)<<8)|(((int)(buf[base])&0xff)))

Uint16 Move_memory(char *src, char *dst,unsigned int Size);
Uint16 load_to_memory(struct prog_loader seg,Uint32 base);
Uint16 component_load(struct elf_parser *parse_info); 
Uint32 get_prog_entry(struct elf_parser *parser_info);
Uint16  elf_prog_segment_loader(struct elf_parser *parser_info, struct prog_loader Segment[],int progseg_count);
#endif




