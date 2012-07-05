/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: C6747_init.c
* DESCRIPTION:  C6747  init  functions
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    4/July/2012			Create
*
*********************************************************************************/


#include "C6747.h"






/*Enable Function for PSC0*/
void PSC0_lPSC_enable(Uint8 PD, Uint8 LPSC_num)
 {

  *(Uint32*) (PSC0_MDCTL+4*LPSC_num) = (*(Uint32*) (PSC0_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0003;
  PSC0_PTCMD = 0x1<<PD;
  while( (PSC0_PTSTAT & (0x1<<PD) ) !=0) ; /*Wait for power state transition to finish*/
  while( (*(Uint32*)(PSC0_MDSTAT+4 * LPSC_num) & 0x1F) !=0x3);
}

/*Enable Function for PSC1*/
void PSC1_lPSC_enable(Uint8 PD, Uint8 LPSC_num)
 {

  *(Uint32*) (PSC1_MDCTL+4*LPSC_num) = (*(Uint32*) (PSC1_MDCTL+4*LPSC_num) & 0xFFFFFFE0) | 0x0003;
  PSC1_PTCMD = 0x1<<PD;
  while( (PSC1_PTSTAT & (0x1<<PD) ) !=0) ; /*Wait for power state transition to finish*/
  while( (*(Uint32*)(PSC1_MDSTAT+4 * LPSC_num) & 0x1F) !=0x3);
}

void initpsc( void)
{
    
    

    // PSC0
    PSC0_lPSC_enable(0, 0);
    PSC0_lPSC_enable(0, 1);
    PSC0_lPSC_enable(0, 2);
    PSC0_lPSC_enable(0, 3);  // EMIFA
    PSC0_lPSC_enable(0, 4);
    PSC0_lPSC_enable(0, 5);
    PSC0_lPSC_enable(0, 6);
    PSC0_lPSC_enable(0, 8);
    PSC0_lPSC_enable(0, 9);
    PSC0_lPSC_enable(0, 10);
    PSC0_lPSC_enable(0, 11);
    PSC0_lPSC_enable(0, 12);
    PSC0_lPSC_enable(0, 13);

	// PSC1
    PSC1_lPSC_enable(0, 1);
    PSC1_lPSC_enable(0, 2);
    PSC1_lPSC_enable(0, 3);
	PSC1_lPSC_enable(0, 4);
    PSC1_lPSC_enable(0, 5);
    PSC1_lPSC_enable(0, 6);  // EMIFB
    PSC1_lPSC_enable(0, 7);
    PSC1_lPSC_enable(0, 8);
    PSC1_lPSC_enable(0, 9);
    PSC1_lPSC_enable(0, 10);
    PSC1_lPSC_enable(0, 11);
    PSC1_lPSC_enable(0, 12);
    PSC1_lPSC_enable(0, 13);
    PSC1_lPSC_enable(0, 16);
    PSC1_lPSC_enable(0, 17);
    PSC1_lPSC_enable(0, 20);
    PSC1_lPSC_enable(0, 21);
    PSC1_lPSC_enable(0, 24);
    PSC1_lPSC_enable(0, 25);
    PSC1_lPSC_enable(0, 26);
    PSC1_lPSC_enable(0, 31);

    
}

void  SystemConfig(void)

{

  
    KICK0R = 0x83e70b13;  // Kick0 register + data (unlock)
    KICK1R = 0x95a4f1e0;  // Kick1 register + data (unlock)
    PINMUX0  = 0x11111188;  // EMIFB, Check EMU0/RTCK
    PINMUX1  = 0x11111111;  // EMIFB
    PINMUX2  = 0x11111111;  // EMIFB
    PINMUX3  = 0x11111111;  // EMIFB
    PINMUX4  = 0x11111111;  // EMIFB
    PINMUX5  = 0x11111111;  // EMIFB
    PINMUX6  = 0x11111111;  // EMIFB
    PINMUX7  = 0x11111111;  // EMIFB, SPI0,GP5[3]
    PINMUX8  = 0x11111111;  // UART2, McASP1, I2C0, I2C1
    PINMUX9  = 0x00000000;  // RMII CLK, McASP0, USB_DRVVBUS, UART2
    PINMUX10 = 0x00000008;  // RMII/ McASP0
    PINMUX11 = 0x08888888;  // McASP1, UART1, McASP0, MDIO (last 2 digits 0x22 for MDIO instead of GPIO)
    PINMUX12 = 0x00000000;  // McASP0 / McASP1
    PINMUX13 = 0x11000000;
	PINMUX14 = 0x11111111;
	PINMUX15 = 0x11111111;
	PINMUX16 = 0x11111111;
	PINMUX17 = 0x21111111;
	PINMUX18 = 0x11111112;
    PINMUX19 = 0x00000001;  // EMIFA

	KICK0R = 0;  // Kick0 register + data (lock)
    KICK1R = 0;  // Kick1 register + data (lock)






   
}

void InitPLL(void)
{
    int i = 0;

    /* Configure ARM, DSP at 300MHz, EMIFs at 133MHz */
    //Uint8 DIV45_EN = 1;
    Uint8 CLKMODE = 0;
    Uint8 PLLM = 24;
    Uint8 POSTDIV = 1;
    Uint8 PLLDIV3 = 2;
    Uint8 PLLDIV5 = 5;
    Uint8 PLLDIV7 = 7;
    Uint8 PREDIV = 0;

	// Moved step 2c and 2d to step 0
   /*Set PLLEN=0 and PLLRST=0, Reset the PLL*/
    PLL0_PLLCTL &=  0xFFFFFFFE; 	/*PLL BYPASS MODE*/
   
   /*wait for 4 cycles to allow PLLEN mux switches properly to bypass clock*/
   for(i=0; i<PLLEN_MUX_SWITCH; i++) {;}   /*Make PLLEN_MUX_SWITCH as bootpacket*/

   /*Select the Clock Mode bit 8 as External Clock or On Chip Oscilator*/
	PLL0_PLLCTL &= 0xFFFFFEFF;  
    PLL0_PLLCTL |= (CLKMODE<<8);  /* Make CLKSRC as BootPacket to pass the value*/

   /*Set PLLENSRC '0',bit 5, PLL Enable(PLLEN) selection is controlled through MMR*/
    PLL0_PLLCTL &=  0xFFFFFFDF; 
   
   /*PLLCTL.EXTCLKSRC bit 9 should be left at 0 for Primus*/
    PLL0_PLLCTL &=  0xFFFFFDFF;

   /* Clear PLLRST bit to 0 -Reset the PLL */
   PLL0_PLLCTL &= 0xFFFFFFF7; 	
  
   /*Disable the PLL output*/ 
   PLL0_PLLCTL |= 0x10; 		
   
   /*PLL initialization sequence*/
   
   /*Power up the PLL- PWRDN bit set to 0 to bring the PLL out of power down bit*/
   PLL0_PLLCTL &= 0xFFFFFFFD;
   
   /*Enable the PLL from Disable Mode PLLDIS bit to 0 - This is step is not required for Primus*/
   PLL0_PLLCTL &= 0xFFFFFFEF;
   
   /*PLL stabilisation time- take out this step , not required here when PLL in bypassmode*/
  // for(i=0; i<PLL_STABILIZATION_TIME; i++) {;}  /* Make PLL_STABILIZATION_TIME as bootpacket*/
   PLL0_PREDIV = 0x8000 | PREDIV;   
   /*Program the required multiplier value in PLLM*/
   PLL0_PLLM    = PLLM; /* Make PLLMULTIPLEIR as bootpacket*/

   /*If desired to scale all the SYSCLK frequencies of a given PLLC, program the POSTDIV ratio*/
 
   PLL0_POSTDIV = 0x8000 | POSTDIV; /* Make POSTDIV as bootpacket*/

   /*If Necessary program the PLLDIVx*/
   /*Check for the GOSTAT bit in PLLSTAT to clear to 0 to indicate that no GO operation is currently in progress*/
   while(PLL0_PLLSTAT & 0x1==1){}

   /*Program the RATIO field in PLLDIVx with the desired divide factors. In addition, make sure in this step you leave the PLLDIVx.DxEN bits set so clocks are still enabled (default).*/
    PLL0_PLLDIV3 = 0x8000 | PLLDIV3; /* Make PLLDIV3 as bootpacket, do it for other PLLDIVx to if required*/
    PLL0_PLLDIV5 = 0x8000 | PLLDIV5; /* Make PLLDIV5 as bootpacket, do it for other PLLDIVx to if required*/
    PLL0_PLLDIV7 = 0x8000 | PLLDIV7; /* Make PLLDIV7 as bootpacket, do it for other PLLDIVx to if required*/

    /*Set the GOSET bit in PLLCMD to 1 to initiate a new divider transition.*/
    PLL0_PLLCMD |= 0x1;

	/*Wait for the GOSTAT bit in PLLSTAT to clear to 0 (completion of phase alignment).*/
    while(PLL0_PLLSTAT & 0x1==1) { } 
   
 
   /*Wait for PLL to reset properly. See PLL spec for PLL reset time - This step is not required here -step11*/
  // for(i=0; i<PLL_RESET_TIME_CNT; i++) {;}   /*128 MXI Cycles*/ /*Make PLL_RESET_TIME_CNT as boot packet*/
      
   /*Set the PLLRST bit in PLLCTL to 1 to bring the PLL out of reset*/
   PLL0_PLLCTL |= 0x8;
   
   /*Wait for PLL to lock. See PLL spec for PLL lock time*/
   for(i=0; i<PLL_LOCK_TIME_CNT; i++) {;} /*Make PLL_LOCK_TIME_CNT as boot Packet*/ 
   
   /*Set the PLLEN bit in PLLCTL to 1 to remove the PLL from bypass mode*/
   PLL0_PLLCTL |=  0x1;

   KICK0R = 0x83e70b13;  // Kick0 register + data (unlock)
   KICK1R = 0x95a4f1e0;  // Kick1 register + data (unlock)
//   CFGCHIP1 |=0x44;     //ÉèÖÃGPIO3ÖÐ¶Ï
   CFGCHIP3 |= 0x4;       // Enable 4.5 divider PLL
   CFGCHIP3 |= 0x1;       // Select 4.5 divider for EMIFB clock source only (not EMIFA)
}


void emifconfig(void)
{
    // ISSI IS42S16160B-6BL SDRAM, 2 x 16M x 16 (32-bit data path), 133MHz
    EMIFB_SDCFG = 0         // SDRAM Bank Config Register
        |( 1 << 15)         // Unlock timing registers
        |( 3 << 9 )         // CAS latency is 2
        |( 2 << 4 )         // 4 bank SDRAM devices
        |( 1 << 0 );        // 512-word pages requiring 9 column address bits

    EMIFB_SDREF = 0         // SDRAM Refresh Control Register
        |( 0 << 31)         // Low power mode disabled
        |( 0 << 30)         // MCLK stoping disabled
        |( 0 << 23)         // Selects self refresh instead of power down
        |( 8192 <<0);       // Refresh rate = 7812.5ns / 7.5ns

    EMIFB_SDTIM1 = 0        // SDRAM Timing Register 1
        |( 8 << 25)        // (67.5ns / 7.55ns) - 1 = TRFC  @ 133MHz
        |( 2 << 22 )        // (20ns / 7.5ns) - 1 =TRP
        |( 2 << 19 )        // (20ns / 7.5ns) - 1 = TRCD
        |( 1 << 16 )        // (14ns / 7.5ns) - 1 = TWR
        |( 5 << 11 )        // (45ns / 7.5ns) - 1 = TRAS
        |( 8 <<  6 )        // (67.5ns / 7.5ns) - 1 = TRC
        |( 1 <<  3 );       // *(((4 * 14ns) + (2 * 7.5ns)) / (4 * 7.5ns)) -1. = TRRD
                            // but it says to use this formula if 8 banks but only 4 are used here.
                            // and SDCFG1 register only suports upto 4 banks.

    EMIFB_SDTIM2 = 0        // SDRAM Timing Register 2
        |( 16<< 27)         // not sure how they got this number. the datasheet says value should be
                            // "Maximum number of refresh_rate intervals from Activate to Precharge command"
                            // but has no equation. TRASMAX is 120k.
        |( 9 << 16)         // ( 70 / 7.5) - 1
        |( 5 << 0 );        // ( 45 / 7.5 ) - 1

    EMIFB_SDCFG = 0         // SDRAM Bank Config Register
	    |( 1 << 16)
        |( 0 << 15)         // Unlock timing registers
        |( 3 << 9 )         // CAS latency is 2
        |( 2 << 4 )         // 4 bank SDRAM devices
        |( 1 << 0 );        // 512-word pages requiring 9 column address bits

}

void CEint()
{
  	AEMIF_A2CR = 0				//CE3
    	| ( 0 << 31 )           // selectStrobe
       	| ( 0 << 30 )           // extWait
      	| ( 1 << 26 )           // writeSetup  //1    //   0 ns
      	| ( 8 << 20 )           // writeStrobe //4    //  40 ns
      	| ( 2 << 17 )           // writeHold   //1    //   0 ns
      	| ( 1 << 13 )           // readSetup   //1    //   0 ns
      	| ( 6 << 7 )            // readStrobe //8     //  80 ns
      	| ( 2 << 4 )            // readHold   // 1    //  10 ns
       	| ( 3 << 2 )            // turnAround    //3  //  10 ns
       	| ( 0 << 0 );           // asyncSize       // 8-bit bus          // asyncSize       //  8-bit bus*/

	AEMIF_A3CR = 0				//CE4
    	| ( 0 << 31 )           // selectStrobe
       	| ( 0 << 30 )           // extWait
      	| ( 2 << 26 )           // writeSetup  //1    //   0 ns
      	| ( 24 << 20 )           // writeStrobe //4    //  50 ns
      	| ( 2 << 17 )           // writeHold   //1    //   0 ns
      	| ( 2 << 13 )           // readSetup   //1    //   0 ns
      	| ( 24 << 7 )            // readStrobe //20     //  200 ns
      	| ( 2 << 4 )            // readHold   // 1    //  10 ns
       	| ( 3 << 2 )            // turnAround    //3  //  10 ns
       	| ( 1 << 0 );           // asyncSize       // 16-bit bus     

  	AEMIF_A4CR = 0				//CE5
    	| ( 0x0 << 31 )           // selectStrobe //0
       	| ( 0x0 << 30 )           // extWait     //0
      	| ( 0x1 << 26 )           // writeSetup  //1    //   0 ns
      	| ( 0x3 << 20 )           // writeStrobe //4    //  40 ns
      	| ( 0x1 << 17 )           // writeHold   //1    //   0 ns
      	| ( 0x1 << 13 )           // readSetup   //1    //   0 ns
      	| ( 0x3 << 7 )            // readStrobe //8     //  80 ns
      	| ( 0x1 << 4 )            // readHold   // 1    //  10 ns
       	| ( 0x1 << 2 )            // turnAround    //3  //  10 ns
       	| ( 0x1 << 0 );           // asyncSize  //1     // 16-bit bus          

}



void sysinit(void)
{



initpsc();



SystemConfig();



InitPLL();


emifconfig();


CEint();

}
