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

#include "nand.h"
#include "C6747.h"

extern unsigned char data[];
unsigned char buf[54651] = {0};
Uint32 len = 54651;

Int16  nand_test()
{
 
  Uint32 i = 0;

  nand_init();
	
  nand_erase_block(0,1);	
  
  nand_write((Uint32)data, 0 ,len);

  
  nand_read(0,(Uint32)buf,len);

  
  for(i = 0;i < len ;i++)
  	{
  	if(data[i] != buf[i])
		printf("error in postion  %d\n",i);
  	}

  
 return 0;
}
