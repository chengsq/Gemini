

MEMORY
{
  DRAM        org=0xC8000000 len=0x010000 /* DDR RAM */
  DRAM_PROG   org=0xc8100000 len=0x0800000 /* DDR for program  4M */ 
}

SECTIONS
{
  .text :
  {
  } > DRAM_PROG
  .const :
  {
  } > DRAM_PROG
  .bss :
  {
  } > DRAM_PROG
  .stack :
  {
  } > DRAM_PROG
  .data :
  {
  } > DRAM_PROG
   
  .cinit :
  {
  } > DRAM_PROG
  .sysmem :
  {
  } > DRAM_PROG
  .cio :
  {
  } > DRAM_PROG
 
 .switch :> DRAM_PROG
 .far    :> DRAM_PROG
 .ddrram	 :
  {
  } > DRAM, RUN_START(DDRStart)
}
