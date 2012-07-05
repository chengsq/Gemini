

MEMORY
{
  DRAM        org=0xC0000000 len=0x01000000 /* DDR RAM */
  DRAM_PROG   org=0xc3000000 len=0x04000000 /* DDR for program */
  AEMIF       org=0x62000000 len=0x01000000 /* AEMIF CS2 region */
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
   .aemif_mem :
  {
  } > AEMIF 
 .switch :> DRAM_PROG
 .far    :> DRAM_PROG
 .ddrram	 :
  {
  } > DRAM, RUN_START(DDRStart)
}