/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: nand_test.c
* DESCRIPTION: a test case for basic nandflash operation functions
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    4/July/2012				Create
*
*********************************************************************************/
#if 0
#include "nand.h"
#include "C6747.h"
#define  ELF_BUFFER_SIZE 2048*64
extern unsigned char data[];
unsigned char buf[ELF_BUFFER_SIZE] = {0};
Uint32 len = 185746 ;
#define  NAND_ELF_ADDR  (2*64)

Int16  nand_elf()
{
 
  Uint32 i = 0;

  nand_init();
	
 // nand_erase_one_block(NAND_ELF_ADDR);	
  
  
  nand_read(NAND_ELF_ADDR,(Uint32)buf,len);

  
  for(i = 0;i < len ;i++)
  	{
  	if(data[i] != buf[i])
		uart_print_string("error in postion  %d\n",i);
  	}

  
 return 0;
}
#endif
