#include"stdio.h"
#include "elf.h"
#include "C6747.h"
#include "elf_loader.h"
#include "uart.h"
#define BUF_SIZE  100*1024

char dst[BUF_SIZE];

struct elf_parser info;
Elf32_Addr entry;
extern unsigned char data[];

void  do_bootm(void)
{
  entry = get_prog_entry(&info);
  asm(" MVKL _entry, B1");
  asm(" MVKH _entry, B1");
  asm(" LDW *B1, B1");
  asm(" NOP 4");
  asm(" B B1");
  asm(" NOP 5");
}


int main() 
{

	C6747_init();
	info.src_addr = data;
	info.dst_addr= dst;
	
	uart_open();
	
	nand_test();
	
   	uart_print_string("\n***starting***\n");
	
   	#if 1
	component_load(&info);
	do_bootm();
	#endif

return 0;

}

