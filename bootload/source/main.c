#include"stdio.h"
#include "C6747.h"
#include "uart.h"
#include "nand.h"

#if 1
int main() 
{
	C6747_init();	
	uart_open();
	nand_init();	
	do_boot();
    return 0;

}
#endif




