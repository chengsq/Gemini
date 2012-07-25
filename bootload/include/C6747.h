/*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: C6747.h
* DESCRIPTION: C6747 register and basic data type defination
* REV         AUTHOR      			DATE       DESCRIPTION OF CHANGE
* 1.0     	Shiqing.Cheng    	    4/July/2012			Create
*
*********************************************************************************/
/*
 *  Definitions & Register
 *
 */

#ifndef __C6747_H__
#define __C6747_H__

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Variable types                                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */


    typedef unsigned int                 Uint32;
    typedef unsigned short               Uint16;
    typedef unsigned char                Uint8;

    /* Signed integer definitions (32bit, 16bit, 8bit) follow... */
    typedef int                          Int32;
    typedef short                        Int16;
    typedef char                         Int8;

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Software Breakpoint code                                                *
 *      Uses inline assembly command                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */



/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  AEMIF Controller                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define AEMIF_BASE              0x68000000
#define AEMIF_AWCCR             *( volatile Uint32* )( AEMIF_BASE + 0x04 )
#define AEMIF_A1CR              *( volatile Uint32* )( AEMIF_BASE + 0x10 )
#define AEMIF_A2CR              *( volatile Uint32* )( AEMIF_BASE + 0x14 )
#define AEMIF_A3CR              *( volatile Uint32* )( AEMIF_BASE + 0x18 )
#define AEMIF_A4CR              *( volatile Uint32* )( AEMIF_BASE + 0x1C )
#define AEMIF_EIRR              *( volatile Uint32* )( AEMIF_BASE + 0x40 )
#define AEMIF_EIMR              *( volatile Uint32* )( AEMIF_BASE + 0x44 )
#define AEMIF_EIMSR             *( volatile Uint32* )( AEMIF_BASE + 0x48 )
#define AEMIF_EIMCR             *( volatile Uint32* )( AEMIF_BASE + 0x4C )
#define AEMIF_NANDFCR           *( volatile Uint32* )( AEMIF_BASE + 0x60 )
#define AEMIF_NANDFSR           *( volatile Uint32* )( AEMIF_BASE + 0x64 )
#define AEMIF_NANDECC2          *( volatile Uint32* )( AEMIF_BASE + 0x70 )
#define AEMIF_NANDECC3          *( volatile Uint32* )( AEMIF_BASE + 0x74 )
#define AEMIF_NANDECC4          *( volatile Uint32* )( AEMIF_BASE + 0x78 )
#define AEMIF_NANDECC5          *( volatile Uint32* )( AEMIF_BASE + 0x7C )

#define AEMIF_MAX_TIMEOUT_8BIT  0x3FFFFFFC
#define AEMIF_MAX_TIMEOUT_16BIT 0x3FFFFFFD

#define EMIF_CS2                2
#define EMIF_CS3                3
#define EMIF_CS4                4
#define EMIF_CS5                5

#define EMIF_CS0_BASE           0x02000000
#define EMIF_CS1_BASE           0x04000000

#define EMIF_NAND_MODE          1
#define EMIF_NORMAL_MODE        0


#define EMIFB_BASE              0xB0000000
#define EMIFB_SDSTAT            *(unsigned int*)(EMIFB_BASE + 0x04)    //SDRAM Status Register  
#define EMIFB_SDCFG             *(unsigned int*)(EMIFB_BASE + 0x08)    //SDRAM Bank Config Register
#define EMIFB_SDREF             *(unsigned int*)(EMIFB_BASE + 0x0C)    //SDRAM Refresh Control Register
#define EMIFB_SDTIM1            *(unsigned int*)(EMIFB_BASE + 0x10)    //SDRAM Timing Register
#define EMIFB_SDTIM2            *(unsigned int*)(EMIFB_BASE + 0x14)    //SDRAM Timing Register

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Device System Controller                                                *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define SYS_BASE            0x01C14000
#define REVID               *(unsigned int*)(SYS_BASE + 0x000)  
#define DIEIDR0             *(unsigned int*)(SYS_BASE + 0x008)
#define DIEIDR1             *(unsigned int*)(SYS_BASE + 0x00C)
#define DIEIDR2             *(unsigned int*)(SYS_BASE + 0x010)
#define DIEIDR3             *(unsigned int*)(SYS_BASE + 0x014)
#define DEVIDR0             *(unsigned int*)(SYS_BASE + 0x018)
#define DEVIDR1             *(unsigned int*)(SYS_BASE + 0x01C)
#define BOOTCFG             *(unsigned int*)(SYS_BASE + 0x020)
#define CHIPREVIDR          *(unsigned int*)(SYS_BASE + 0x024)
#define KICK0R              *(unsigned int*)(SYS_BASE + 0x038)  
#define KICK1R              *(unsigned int*)(SYS_BASE + 0x03c)  
#define HOST0CFG            *(unsigned int*)(SYS_BASE + 0x040)
#define HOST1CFG            *(unsigned int*)(SYS_BASE + 0x044)
#define IRAWSTAT            *(unsigned int*)(SYS_BASE + 0x0E0)  
#define IENSTAT             *(unsigned int*)(SYS_BASE + 0x0E4)  
#define IENSET              *(unsigned int*)(SYS_BASE + 0x0E8)  
#define IENCLR              *(unsigned int*)(SYS_BASE + 0x0EC)  
#define EOI                 *(unsigned int*)(SYS_BASE + 0x0F0)  
#define FLTADDRR            *(unsigned int*)(SYS_BASE + 0x0F4)  
#define FLTSTAT             *(unsigned int*)(SYS_BASE + 0x0F8)  
#define MSTPRI0             *(unsigned int*)(SYS_BASE + 0x110)  
#define MSTPRI1             *(unsigned int*)(SYS_BASE + 0x114)  
#define MSTPRI2             *(unsigned int*)(SYS_BASE + 0x118) 
#define PINMUX0				*(unsigned int*)(SYS_BASE + 0x120)
#define PINMUX1				*(unsigned int*)(SYS_BASE + 0x124)
#define PINMUX2				*(unsigned int*)(SYS_BASE + 0x128)
#define PINMUX3				*(unsigned int*)(SYS_BASE + 0x12C)
#define PINMUX4				*(unsigned int*)(SYS_BASE + 0x130)
#define PINMUX5				*(unsigned int*)(SYS_BASE + 0x134)
#define PINMUX6				*(unsigned int*)(SYS_BASE + 0x138)
#define PINMUX7				*(unsigned int*)(SYS_BASE + 0x13C)
#define PINMUX8				*(unsigned int*)(SYS_BASE + 0x140)
#define PINMUX9				*(unsigned int*)(SYS_BASE + 0x144)
#define PINMUX10			*(unsigned int*)(SYS_BASE + 0x148)
#define PINMUX11			*(unsigned int*)(SYS_BASE + 0x14C)
#define PINMUX12			*(unsigned int*)(SYS_BASE + 0x150)
#define PINMUX13			*(unsigned int*)(SYS_BASE + 0x154)
#define PINMUX14			*(unsigned int*)(SYS_BASE + 0x158)
#define PINMUX15			*(unsigned int*)(SYS_BASE + 0x15C)
#define PINMUX16			*(unsigned int*)(SYS_BASE + 0x160)
#define PINMUX17			*(unsigned int*)(SYS_BASE + 0x164)
#define PINMUX18			*(unsigned int*)(SYS_BASE + 0x168)
#define PINMUX19			*(unsigned int*)(SYS_BASE + 0x16C)
#define SUSPSRC		 	    *(unsigned int*)(SYS_BASE + 0x170) 
#define CHIPSIG	            *(unsigned int*)(SYS_BASE + 0x174) 
#define CHIPSIG_CLR         *(unsigned int*)(SYS_BASE + 0x178) 
#define CFGCHIP0            *(unsigned int*)(SYS_BASE + 0x17C) 
#define CFGCHIP1            *(unsigned int*)(SYS_BASE + 0x180) 
#define CFGCHIP2            *(unsigned int*)(SYS_BASE + 0x184) 
#define CFGCHIP3           	*(unsigned int*)(SYS_BASE + 0x188) 
#define CFGCHIP4		 	*(unsigned int*)(SYS_BASE + 0x18C)


/*PSC Module Related Registers*/              
#define PSC0_BASE  	    0x01C10000
#define PSC1_BASE  	    0x01E27000

#define PSC0_MDCTL 		(PSC0_BASE+0xA00)
#define PSC0_MDSTAT 	(PSC0_BASE+0x800)
#define PSC0_PTCMD  	*(unsigned int*) (PSC0_BASE + 0x120)
#define PSC0_PTSTAT 	*(unsigned int*) (PSC0_BASE + 0x128)

#define PSC1_MDCTL 		(PSC1_BASE+0xA00)
#define PSC1_MDSTAT 	(PSC1_BASE+0x800)
#define PSC1_PTCMD  	*(unsigned int*) (PSC1_BASE + 0x120)
#define PSC1_PTSTAT 	*(unsigned int*) (PSC1_BASE + 0x128)
 


/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  GPIO Control                                                            *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define GPIO_BASE               0x01E26000

#define GPIO_PCR                *( volatile Uint32* )( GPIO_BASE + 0x04 )
#define GPIO_BINTEN             *( volatile Uint32* )( GPIO_BASE + 0x08 )

// For GPIO[0:31]
#define GPIO_DIR_BASE           ( 0x10 )   // Direction Cntl
#define GPIO_OUT_DATA_BASE      ( 0x14 )   // Output data
#define GPIO_SET_DATA_BASE      ( 0x18 )   // Set data
#define GPIO_CLR_DATA_BASE      ( 0x1C )   // Clear data
#define GPIO_IN_DATA_BASE       ( 0x20 )   // Input data
#define GPIO_SET_RIS_TRIG_BASE  ( 0x24 )   // Set rising edge intr
#define GPIO_CLR_RIS_TRIG_BASE  ( 0x28 )   // Clear rising edge intr
#define GPIO_SET_FAL_TRIG_BASE  ( 0x2C )   // Set falling edge intr
#define GPIO_CLR_FAL_TRIG_BASE  ( 0x30 )   // Clear falling edge intr
#define GPIO_INSTAT_BASE        ( 0x34 )   // Intr status
#define GPIO_BASE_OFFSET        0x28

#define GPIO_01_BASE            ( GPIO_BASE + 0x10 )
#define GPIO_23_BASE            ( GPIO_01_BASE + GPIO_BASE_OFFSET )
#define GPIO_45_BASE            ( GPIO_23_BASE + GPIO_BASE_OFFSET )
#define GPIO_6_BASE             ( GPIO_45_BASE + GPIO_BASE_OFFSET )

// For GPIO[0:31]
#define GPIO_DIR01              *( volatile Uint32* )( GPIO_BASE + 0x10 )
#define GPIO_OUT_DATA01         *( volatile Uint32* )( GPIO_BASE + 0x14 )
#define GPIO_SET_DATA01         *( volatile Uint32* )( GPIO_BASE + 0x18 )
#define GPIO_CLR_DATA01         *( volatile Uint32* )( GPIO_BASE + 0x1C )
#define GPIO_IN_DATA01          *( volatile Uint32* )( GPIO_BASE + 0x20 )
#define GPIO_SET_RIS_TRIG01     *( volatile Uint32* )( GPIO_BASE + 0x24 )
#define GPIO_CLR_RIS_TRIG01     *( volatile Uint32* )( GPIO_BASE + 0x28 )
#define GPIO_SET_FAL_TRIG01     *( volatile Uint32* )( GPIO_BASE + 0x2C )
#define GPIO_CLR_FAL_TRIG01     *( volatile Uint32* )( GPIO_BASE + 0x30 )
#define GPIO_INSTAT01           *( volatile Uint32* )( GPIO_BASE + 0x34 )

// For GPIO[32:63]
#define GPIO_DIR23              *( volatile Uint32* )( GPIO_BASE + 0x38 )
#define GPIO_OUT_DATA23         *( volatile Uint32* )( GPIO_BASE + 0x3C )
#define GPIO_SET_DATA23         *( volatile Uint32* )( GPIO_BASE + 0x40 )
#define GPIO_CLR_DATA23         *( volatile Uint32* )( GPIO_BASE + 0x44 )
#define GPIO_IN_DATA23          *( volatile Uint32* )( GPIO_BASE + 0x48 )
#define GPIO_SET_RIS_TRIG23     *( volatile Uint32* )( GPIO_BASE + 0x4C )
#define GPIO_CLR_RIS_TRIG23     *( volatile Uint32* )( GPIO_BASE + 0x50 )
#define GPIO_SET_FAL_TRIG23     *( volatile Uint32* )( GPIO_BASE + 0x54 )
#define GPIO_CLR_FAL_TRIG23     *( volatile Uint32* )( GPIO_BASE + 0x58 )
#define GPIO_INSTAT23           *( volatile Uint32* )( GPIO_BASE + 0x5C )

// For GPIO[64:70]
#define GPIO_DIR45              *( volatile Uint32* )( GPIO_BASE + 0x60 )
#define GPIO_OUT_DATA45         *( volatile Uint32* )( GPIO_BASE + 0x64 )
#define GPIO_SET_DATA45         *( volatile Uint32* )( GPIO_BASE + 0x68 )
#define GPIO_CLR_DATA45         *( volatile Uint32* )( GPIO_BASE + 0x6C )
#define GPIO_IN_DATA45          *( volatile Uint32* )( GPIO_BASE + 0x70 )
#define GPIO_SET_RIS_TRIG45     *( volatile Uint32* )( GPIO_BASE + 0x74 )
#define GPIO_CLR_RIS_TRIG45     *( volatile Uint32* )( GPIO_BASE + 0x78 )
#define GPIO_SET_FAL_TRIG45     *( volatile Uint32* )( GPIO_BASE + 0x7C )
#define GPIO_CLR_FAL_TRIG45     *( volatile Uint32* )( GPIO_BASE + 0x80 )
#define GPIO_INSTAT45           *( volatile Uint32* )( GPIO_BASE + 0x84 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  I2C Controller                                                          *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define I2C_BASE                0x01C22000
#define I2C_OAR                 *( volatile Uint32* )( I2C_BASE + 0x00 )
#define I2C_ICIMR               *( volatile Uint32* )( I2C_BASE + 0x04 )
#define I2C_ICSTR               *( volatile Uint32* )( I2C_BASE + 0x08 )
#define I2C_ICCLKL              *( volatile Uint32* )( I2C_BASE + 0x0C )
#define I2C_ICCLKH              *( volatile Uint32* )( I2C_BASE + 0x10 )
#define I2C_ICCNT               *( volatile Uint32* )( I2C_BASE + 0x14 )
#define I2C_ICDRR               *( volatile Uint32* )( I2C_BASE + 0x18 )
#define I2C_ICSAR               *( volatile Uint32* )( I2C_BASE + 0x1C )
#define I2C_ICDXR               *( volatile Uint32* )( I2C_BASE + 0x20 )
#define I2C_ICMDR               *( volatile Uint32* )( I2C_BASE + 0x24 )
#define I2C_ICIVR               *( volatile Uint32* )( I2C_BASE + 0x28 )
#define I2C_ICEMDR              *( volatile Uint32* )( I2C_BASE + 0x2C )
#define I2C_ICPSC               *( volatile Uint32* )( I2C_BASE + 0x30 )
#define I2C_ICPID1              *( volatile Uint32* )( I2C_BASE + 0x34 )
#define I2C_ICPID2              *( volatile Uint32* )( I2C_BASE + 0x38 )

/* I2C Field Definitions */
#define ICOAR_MASK_7                    0x007F
#define ICOAR_MASK_10                   0x03FF
#define ICSAR_MASK_7                    0x007F
#define ICSAR_MASK_10                   0x03FF
#define ICOAR_OADDR                     0x007f
#define ICSAR_SADDR                     0x0050

#define ICSTR_SDIR                      0x4000
#define ICSTR_NACKINT                   0x2000
#define ICSTR_BB                        0x1000
#define ICSTR_RSFULL                    0x0800
#define ICSTR_XSMT                      0x0400
#define ICSTR_AAS                       0x0200
#define ICSTR_AD0                       0x0100
#define ICSTR_SCD                       0x0020
#define ICSTR_ICXRDY                    0x0010
#define ICSTR_ICRRDY                    0x0008
#define ICSTR_ARDY                      0x0004
#define ICSTR_NACK                      0x0002
#define ICSTR_AL                        0x0001

#define ICMDR_NACKMOD                   0x8000
#define ICMDR_FREE                      0x4000
#define ICMDR_STT                       0x2000
#define ICMDR_IDLEEN                    0x1000
#define ICMDR_STP                       0x0800
#define ICMDR_MST                       0x0400
#define ICMDR_TRX                       0x0200
#define ICMDR_XA                        0x0100
#define ICMDR_RM                        0x0080
#define ICMDR_DLB                       0x0040
#define ICMDR_IRS                       0x0020
#define ICMDR_STB                       0x0010
#define ICMDR_FDF                       0x0008
#define ICMDR_BC_MASK                   0x0007

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  INTC controller                                                         *
 *      Controls the Interrupts                                             *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define INTC_BASE               0xFFFE0000
#define INTC_FIQ0               *( volatile Uint32* )( INTC_BASE + 0x00 )
#define INTC_FIQ1               *( volatile Uint32* )( INTC_BASE + 0x04 )
#define INTC_IRQ0               *( volatile Uint32* )( INTC_BASE + 0x08 )
#define INTC_IRQ1               *( volatile Uint32* )( INTC_BASE + 0x0C )
#define INTC_FIQENTRY           *( volatile Uint32* )( INTC_BASE + 0x10 )
#define INTC_IRQENTRY           *( volatile Uint32* )( INTC_BASE + 0x14 )
#define INTC_EINT0              *( volatile Uint32* )( INTC_BASE + 0x18 )
#define INTC_EINT1              *( volatile Uint32* )( INTC_BASE + 0x1C )
#define INTC_INTCTL             *( volatile Uint32* )( INTC_BASE + 0x20 )
#define INTC_EABASE             *( volatile Uint32* )( INTC_BASE + 0x24 )
#define INTC_INTPRI0            *( volatile Uint32* )( INTC_BASE + 0x30 )
#define INTC_INTPRI1            *( volatile Uint32* )( INTC_BASE + 0x34 )
#define INTC_INTPRI2            *( volatile Uint32* )( INTC_BASE + 0x38 )
#define INTC_INTPRI3            *( volatile Uint32* )( INTC_BASE + 0x3C )
#define INTC_INTPRI4            *( volatile Uint32* )( INTC_BASE + 0x40 )
#define INTC_INTPRI5            *( volatile Uint32* )( INTC_BASE + 0x44 )
#define INTC_INTPRI6            *( volatile Uint32* )( INTC_BASE + 0x48 )
#define INTC_INTPRI7            *( volatile Uint32* )( INTC_BASE + 0x4C )


/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  PLL0 Controller                                                         *
 *      Generates DSP, ARM clocks                                           *
 *                                                                          *
 * ------------------------------------------------------------------------ */


#define PLL0_BASE   	0x01C11000   							/*SYSTEM PLL BASE ADDRESS*/

#define PLL0_PID      	*(unsigned int*) (PLL0_BASE + 0x00)		/*PID*/
#define PLL0_FUSERR   	*(unsigned int*) (PLL0_BASE + 0xE0)		/*x*FuseFarm Error Reg*/
#define PLL0_RSTYPE	    *(unsigned int*) (PLL0_BASE + 0xE4)		/*Reset Type status Reg*/
#define PLL0_PLLCTL     *(unsigned int*) (PLL0_BASE + 0x100) 	/*PLL Control Register*/
#define PLL0_OCSEL      *(unsigned int*) (PLL0_BASE + 0x104)	/*OBSCLK Select Register*/
#define PLL0_SECCTL     *(unsigned int*) (PLL0_BASE + 0x108)	/*PLL Secondary Control Register*/
#define PLL0_PLLM       *(unsigned int*) (PLL0_BASE + 0x110)    /*PLL Multiplier*/	
#define PLL0_PREDIV     *(unsigned int*) (PLL0_BASE + 0x114)    /*Pre divider*/	
#define PLL0_PLLDIV1    *(unsigned int*) (PLL0_BASE + 0x118)    /*Diveder-1*/	
#define PLL0_PLLDIV2    *(unsigned int*) (PLL0_BASE + 0x11C)    /*Diveder-2*/	
#define PLL0_PLLDIV3    *(unsigned int*) (PLL0_BASE + 0x120)    /*Diveder-3*/	
#define PLL0_OSCDIV1    *(unsigned int*) (PLL0_BASE + 0x124)    /*Oscilator Divider*/	
#define PLL0_POSTDIV    *(unsigned int*) (PLL0_BASE + 0x128)    /*Post Divider*/	
#define PLL0_BPDIV      *(unsigned int*) (PLL0_BASE + 0x12C)	/*Bypass Divider*/
#define PLL0_WAKEUP     *(unsigned int*) (PLL0_BASE + 0x130)	/*Wakeup Reg*/
#define PLL0_PLLCMD     *(unsigned int*) (PLL0_BASE + 0x138)	/*Command Reg*/
#define PLL0_PLLSTAT    *(unsigned int*) (PLL0_BASE + 0x13C)	/*Status Reg*/
#define PLL0_ALNCTL     *(unsigned int*) (PLL0_BASE + 0x140)	/*Clock Align Control Reg*/
#define PLL0_DCHANGE    *(unsigned int*) (PLL0_BASE + 0x144)	/*PLLDIV Ratio Chnage status*/
#define PLL0_CKEN       *(unsigned int*) (PLL0_BASE + 0x148)	/*Clock Enable Reg*/
#define PLL0_CKSTAT     *(unsigned int*) (PLL0_BASE + 0x14C)	/*Clock Status Reg*/
#define PLL0_SYSTAT     *(unsigned int*) (PLL0_BASE + 0x150)	/*Sysclk status reg*/
#define PLL0_PLLDIV4    *(unsigned int*) (PLL0_BASE + 0x160)	/*Divider 4*/
#define PLL0_PLLDIV5    *(unsigned int*) (PLL0_BASE + 0x164)	/*Divider 5*/
#define PLL0_PLLDIV6    *(unsigned int*) (PLL0_BASE + 0x168)	/*Divider 6*/
#define PLL0_PLLDIV7    *(unsigned int*) (PLL0_BASE + 0x16C)	/*Divider 7*/
#define PLL0_PLLDIV8    *(unsigned int*) (PLL0_BASE + 0x170)	/*Divider 8*/
#define PLL0_PLLDIV9    *(unsigned int*) (PLL0_BASE + 0x174)	/*Divider 9*/
#define PLL0_PLLDIV10   *(unsigned int*) (PLL0_BASE + 0x178)	/*Divider 10*/
#define PLL0_PLLDIV11   *(unsigned int*) (PLL0_BASE + 0x17C)	/*Divider 11*/
#define PLL0_PLLDIV12   *(unsigned int*) (PLL0_BASE + 0x180)	/*Divider 12*/
#define PLL0_PLLDIV13   *(unsigned int*) (PLL0_BASE + 0x184)	/*Divider 13*/
#define PLL0_PLLDIV14   *(unsigned int*) (PLL0_BASE + 0x188)	/*Divider 14*/
#define PLL0_PLLDIV15   *(unsigned int*) (PLL0_BASE + 0x18C)	/*Divider 15*/
#define PLL0_PLLDIV16   *(unsigned int*) (PLL0_BASE + 0x190)	/*Divider 16*/
#define PLLEN_MUX_SWITCH  4 
#define PLL_LOCK_TIME_CNT 2400


/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  Timer Controller                                                        *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define TIMER0_BASE         0x01C20000
#define TIMER0_EMUMGT       *( volatile Uint32* )( TIMER0_BASE + 0x04 )
#define TIMER0_TIM12        *( volatile Uint32* )( TIMER0_BASE + 0x10 )
#define TIMER0_TIM34        *( volatile Uint32* )( TIMER0_BASE + 0x14 )
#define TIMER0_PRD12        *( volatile Uint32* )( TIMER0_BASE + 0x18 )
#define TIMER0_PRD34        *( volatile Uint32* )( TIMER0_BASE + 0x1C )
#define TIMER0_TRC          *( volatile Uint32* )( TIMER0_BASE + 0x20 )
#define TIMER0_TGCR         *( volatile Uint32* )( TIMER0_BASE + 0x24 )

#define TIMER1_BASE         0x01C21000
#define TIMER1_EMUMGT       *( volatile Uint32* )( TIMER1_BASE + 0x04 )
#define TIMER1_TIM12        *( volatile Uint32* )( TIMER1_BASE + 0x10 )
#define TIMER1_TIM34        *( volatile Uint32* )( TIMER1_BASE + 0x14 )
#define TIMER1_PRD12        *( volatile Uint32* )( TIMER1_BASE + 0x18 )
#define TIMER1_PRD34        *( volatile Uint32* )( TIMER1_BASE + 0x1C )
#define TIMER1_TRC          *( volatile Uint32* )( TIMER1_BASE + 0x20 )
#define TIMER1_TGCR         *( volatile Uint32* )( TIMER1_BASE + 0x24 )

#define TIMER_EMUMGT            ( 0x04 )
#define TIMER_TIM12             ( 0x10 )
#define TIMER_TIM34             ( 0x14 )
#define TIMER_PRD12             ( 0x18 )
#define TIMER_PRD34             ( 0x1C )
#define TIMER_TRC               ( 0x20 )
#define TIMER_TGCR              ( 0x24 )

/* ------------------------------------------------------------------------ *
 *                                                                          *
 *  UART Controller                                                         *
 *                                                                          *
 * ------------------------------------------------------------------------ */
#define UART0_BASE          0x01C42000
#define UART0_RBR           *( volatile Uint32* )( UART0_BASE + 0x00 )
#define UART0_THR           *( volatile Uint32* )( UART0_BASE + 0x00 )
#define UART0_IER           *( volatile Uint32* )( UART0_BASE + 0x04 )
#define UART0_IIR           *( volatile Uint32* )( UART0_BASE + 0x08 )
#define UART0_FCR           *( volatile Uint32* )( UART0_BASE + 0x08 )
#define UART0_LCR           *( volatile Uint32* )( UART0_BASE + 0x0C )
#define UART0_MCR           *( volatile Uint32* )( UART0_BASE + 0x10 )
#define UART0_LSR           *( volatile Uint32* )( UART0_BASE + 0x14 )
#define UART0_DLL           *( volatile Uint32* )( UART0_BASE + 0x20 )
#define UART0_DLH           *( volatile Uint32* )( UART0_BASE + 0x24 )
#define UART0_PID1          *( volatile Uint32* )( UART0_BASE + 0x28 )
#define UART0_PID2          *( volatile Uint32* )( UART0_BASE + 0x2C )
#define UART0_PWREMU_MGMT   *( volatile Uint32* )( UART0_BASE + 0x30 )

#define UART1_BASE          0x01D0C000
#define UART1_RBR           *( volatile Uint32* )( UART1_BASE + 0x00 )
#define UART1_THR           *( volatile Uint32* )( UART1_BASE + 0x00 )
#define UART1_IER           *( volatile Uint32* )( UART1_BASE + 0x04 )
#define UART1_IIR           *( volatile Uint32* )( UART1_BASE + 0x08 )
#define UART1_FCR           *( volatile Uint32* )( UART1_BASE + 0x08 )
#define UART1_LCR           *( volatile Uint32* )( UART1_BASE + 0x0C )
#define UART1_MCR           *( volatile Uint32* )( UART1_BASE + 0x10 )
#define UART1_LSR           *( volatile Uint32* )( UART1_BASE + 0x14 )
#define UART1_DLL           *( volatile Uint32* )( UART1_BASE + 0x20 )
#define UART1_DLH           *( volatile Uint32* )( UART1_BASE + 0x24 )
#define UART1_PID1          *( volatile Uint32* )( UART1_BASE + 0x28 )
#define UART1_PID2          *( volatile Uint32* )( UART1_BASE + 0x2C )
#define UART1_PWREMU_MGMT   *( volatile Uint32* )( UART1_BASE + 0x30 )

#define UART2_BASE          0x01D0D000
#define UART2_RBR           *( volatile Uint32* )( UART2_BASE + 0x00 )
#define UART2_THR           *( volatile Uint32* )( UART2_BASE + 0x00 )
#define UART2_IER           *( volatile Uint32* )( UART2_BASE + 0x04 )
#define UART2_IIR           *( volatile Uint32* )( UART2_BASE + 0x08 )
#define UART2_FCR           *( volatile Uint32* )( UART2_BASE + 0x08 )
#define UART2_LCR           *( volatile Uint32* )( UART2_BASE + 0x0C )
#define UART2_MCR           *( volatile Uint32* )( UART2_BASE + 0x10 )
#define UART2_LSR           *( volatile Uint32* )( UART2_BASE + 0x14 )
#define UART2_DLL           *( volatile Uint32* )( UART2_BASE + 0x20 )
#define UART2_DLH           *( volatile Uint32* )( UART2_BASE + 0x24 )
#define UART2_PID1          *( volatile Uint32* )( UART2_BASE + 0x28 )
#define UART2_PID2          *( volatile Uint32* )( UART2_BASE + 0x2C )
#define UART2_PWREMU_MGMT   *( volatile Uint32* )( UART2_BASE + 0x30 )

#define UART_RBR                ( 0x00 )
#define UART_THR                ( 0x00 )
#define UART_IER                ( 0x04 )
#define UART_IIR                ( 0x08 )
#define UART_FCR                ( 0x08 )
#define UART_LCR                ( 0x0C )
#define UART_MCR                ( 0x10 )
#define UART_LSR                ( 0x14 )
#define UART_DLL                ( 0x20 )
#define UART_DLH                ( 0x24 )
#define UART_PID1               ( 0x28 )
#define UART_PID2               ( 0x2C )
#define UART_PWREMU_MGMT        ( 0x30 )




#define SPI0_BASE          0x01C41000

#define SPIGCR0           *( volatile Uint32* )( SPI0_BASE + 0x00 )
#define SPIGCR1           *( volatile Uint32* )( SPI0_BASE + 0x04 )
#define SPIINT0           *( volatile Uint32* )( SPI0_BASE + 0x08 )
#define SPILVL            *( volatile Uint32* )( SPI0_BASE + 0x0C )
#define SPIFLG            *( volatile Uint32* )( SPI0_BASE + 0x10 )
#define SPIPC0            *( volatile Uint32* )( SPI0_BASE + 0x14 )
#define SPIPC1            *( volatile Uint32* )( SPI0_BASE + 0x18 )
#define SPIPC2            *( volatile Uint32* )( SPI0_BASE + 0x1C )
#define SPIPC3            *( volatile Uint32* )( SPI0_BASE + 0x20 )
#define SPIPC4            *( volatile Uint32* )( SPI0_BASE + 0x24 )
#define SPIPC5            *( volatile Uint32* )( SPI0_BASE + 0x28 )
#define SPIDAT0           *( volatile Uint32* )( SPI0_BASE + 0x38 )
#define SPIDAT1           *( volatile Uint32* )( SPI0_BASE + 0x3C )
#define SPIBUF            *( volatile Uint32* )( SPI0_BASE + 0x40 )
#define SPIEMU            *( volatile Uint32* )( SPI0_BASE + 0x44 )
#define SPIDELAY          *( volatile Uint32* )( SPI0_BASE + 0x48 )
#define SPIDEF            *( volatile Uint32* )( SPI0_BASE + 0x4C )
#define SPIFMT0           *( volatile Uint32* )( SPI0_BASE + 0x50 )
#define SPIFMT1           *( volatile Uint32* )( SPI0_BASE + 0x54 )
#define SPIFMT2           *( volatile Uint32* )( SPI0_BASE + 0x58 )
#define SPIFMT3           *( volatile Uint32* )( SPI0_BASE + 0x5C )
#define INTVEC0           *( volatile Uint32* )( SPI0_BASE + 0x60 )
#define INTVEC1           *( volatile Uint32* )( SPI0_BASE + 0x64 )



/* ------------------------------------------------------------------------ *
 *  SPI Controller                                                          *
 * ------------------------------------------------------------------------ */
#define SPI_BASE                0x01C41000
#define SPI_SPIGCR0             *( volatile Uint32* )( SPI_BASE + 0x0 )
#define SPI_SPIGCR1             *( volatile Uint32* )( SPI_BASE + 0x4 )
#define SPI_SPIINT              *( volatile Uint32* )( SPI_BASE + 0x8 )
#define SPI_SPILVL              *( volatile Uint32* )( SPI_BASE + 0xc )
#define SPI_SPIFLG              *( volatile Uint32* )( SPI_BASE + 0x10 )
#define SPI_SPIPC0              *( volatile Uint32* )( SPI_BASE + 0x14 )
#define SPI_SPIPC2              *( volatile Uint32* )( SPI_BASE + 0x1c )
#define SPI_SPIDAT1_TOP         *( volatile Uint16* )( SPI_BASE + 0x3c )
#define SPI_SPIDAT1             *( volatile Uint32* )( SPI_BASE + 0x3c )
#define SPI_SPIDAT1_PTR16       *( volatile Uint16* )( SPI_BASE + 0x3e )
#define SPI_SPIDAT1_PTR8        *( volatile Uint8* ) ( SPI_BASE + 0x3f )
#define SPI_SPIBUF              *( volatile Uint32* )( SPI_BASE + 0x40 )
#define SPI_SPIBUF_PTR16        *( volatile Uint16* )( SPI_BASE + 0x42 )
#define SPI_SPIBUF_PTR8         *( volatile Uint8* ) ( SPI_BASE + 0x43 )
#define SPI_SPIEMU              *( volatile Uint32* )( SPI_BASE + 0x44 )
#define SPI_SPIDELAY            *( volatile Uint32* )( SPI_BASE + 0x48 )
#define SPI_SPIDEF              *( volatile Uint32* )( SPI_BASE + 0x4c )
#define SPI_SPIFMT0             *( volatile Uint32* )( SPI_BASE + 0x50 )
#define SPI_SPIFMT1             *( volatile Uint32* )( SPI_BASE + 0x54 )
#define SPI_SPIFMT2             *( volatile Uint32* )( SPI_BASE + 0x58 )
#define SPI_SPIFMT3             *( volatile Uint32* )( SPI_BASE + 0x5c )
#define SPI_INTVEC0             *( volatile Uint32* )( SPI_BASE + 0x60 )
#define SPI_INTVEC1             *( volatile Uint32* )( SPI_BASE + 0x64 )



/* ------------------------------------------------------------------------ *
 *  EDMA Controller                                                          *
 * ------------------------------------------------------------------------ */


#define SPIREV_PARAM_BASE               0x01C041C0
#define SPIREV_OPT             *( volatile Uint32* )( SPIREV_PARAM_BASE + 0x00 )         
#define SPIREV_SRC             *( volatile Uint32* )( SPIREV_PARAM_BASE + 0x04 )
#define SPIREV_A_B_CNT         *( volatile Uint32* )( SPIREV_PARAM_BASE + 0x08 )       
#define SPIREV_DST             *( volatile Uint32* )( SPIREV_PARAM_BASE + 0x0C )
#define SPIREV_SRC_DST_BIDX    *( volatile Uint32* )( SPIREV_PARAM_BASE + 0x10 )
#define SPIREV_LINK_BCNTRLD    *( volatile Uint32* )( SPIREV_PARAM_BASE + 0x14 )         
#define SPIREV_SRC_DST_CIDX    *( volatile Uint32* )( SPIREV_PARAM_BASE + 0x18 )
#define SPIREV_CCNT            *( volatile Uint32* )( SPIREV_PARAM_BASE + 0x1C )

#define SPIREV_PARAM_BASE1               0x01C04FE0
#define SPIREV_OPT1             *( volatile Uint32* )( SPIREV_PARAM_BASE1 + 0x00 )         
#define SPIREV_SRC1             *( volatile Uint32* )( SPIREV_PARAM_BASE1 + 0x04 )
#define SPIREV_A_B_CNT1         *( volatile Uint32* )( SPIREV_PARAM_BASE1 + 0x08 )       
#define SPIREV_DST1             *( volatile Uint32* )( SPIREV_PARAM_BASE1 + 0x0C )
#define SPIREV_SRC_DST_BIDX1    *( volatile Uint32* )( SPIREV_PARAM_BASE1 + 0x10 )
#define SPIREV_LINK_BCNTRLD1    *( volatile Uint32* )( SPIREV_PARAM_BASE1 + 0x14 )         
#define SPIREV_SRC_DST_CIDX1    *( volatile Uint32* )( SPIREV_PARAM_BASE1 + 0x18 )
#define SPIREV_CCNT1            *( volatile Uint32* )( SPIREV_PARAM_BASE1 + 0x1C )





#define SPITRA_PARAM_BASE               0x01C041E0
#define SPITRA_OPT             *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x00 )         
#define SPITRA_SRC             *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x04 )
#define SPITRA_A_B_CNT         *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x08 )       
#define SPITRA_DST             *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x0C )
#define SPITRA_SRC_DST_BIDX    *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x10 )
#define SPITRA_LINK_BCNTRLD    *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x14 )         
#define SPITRA_SRC_DST_CIDX    *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x18 )
#define SPITRA_CCNT            *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x1C )


#define SPITRA_PARAM_BASE1               0x01C04FC0
#define SPITRA_OPT1             *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x00 )         
#define SPITRA_SRC1             *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x04 )
#define SPITRA_A_B_CNT1         *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x08 )       
#define SPITRA_DST1             *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x0C )
#define SPITRA_SRC_DST_BIDX1    *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x10 )
#define SPITRA_LINK_BCNTRLD1    *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x14 )         
#define SPITRA_SRC_DST_CIDX1    *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x18 )
#define SPITRA_CCNT1            *( volatile Uint32* )( SPITRA_PARAM_BASE + 0x1C )


#define GPIO4_PARAM_BASE               0x01C04380
#define GPIO4_OPT             *( volatile Uint32* )( GPIO4_PARAM_BASE + 0x00 )         
#define GPIO4_SRC             *( volatile Uint32* )( GPIO4_PARAM_BASE + 0x04 )
#define GPIO4_A_B_CNT         *( volatile Uint32* )( GPIO4_PARAM_BASE + 0x08 )       
#define GPIO4_DST             *( volatile Uint32* )( GPIO4_PARAM_BASE + 0x0C )
#define GPIO4_SRC_DST_BIDX    *( volatile Uint32* )( GPIO4_PARAM_BASE + 0x10 )
#define GPIO4_LINK_BCNTRLD    *( volatile Uint32* )( GPIO4_PARAM_BASE + 0x14 )         
#define GPIO4_SRC_DST_CIDX    *( volatile Uint32* )( GPIO4_PARAM_BASE + 0x18 )
#define GPIO4_CCNT            *( volatile Uint32* )( GPIO4_PARAM_BASE + 0x1C ) 


#define GPIO4_PARAM_BASE1               0x01C04EA0
#define GPIO4_OPT1             *( volatile Uint32* )( GPIO4_PARAM_BASE1 + 0x00 )         
#define GPIO4_SRC1             *( volatile Uint32* )( GPIO4_PARAM_BASE1 + 0x04 )
#define GPIO4_A_B_CNT1         *( volatile Uint32* )( GPIO4_PARAM_BASE1 + 0x08 )       
#define GPIO4_DST1             *( volatile Uint32* )( GPIO4_PARAM_BASE1 + 0x0C )
#define GPIO4_SRC_DST_BIDX1    *( volatile Uint32* )( GPIO4_PARAM_BASE1 + 0x10 )
#define GPIO4_LINK_BCNTRLD1    *( volatile Uint32* )( GPIO4_PARAM_BASE1 + 0x14 )         
#define GPIO4_SRC_DST_CIDX1    *( volatile Uint32* )( GPIO4_PARAM_BASE1 + 0x18 )
#define GPIO4_CCNT1            *( volatile Uint32* )( GPIO4_PARAM_BASE1 + 0x1C )        



#define EESR            *( volatile Uint32* )(0x01C01030)
#define EECR        	*( volatile Uint32* )(0x01C01028)

#define SECR        	*( volatile Uint32* )(0x01C01040)

#define IPR             *( volatile Uint32* )( 0x01C01068 )         
#define ICR             *( volatile Uint32* )( 0x01C01070 )


#define LCD_BASE                         0x01E13000
#define LCD_REVID                *( volatile Uint32* )( LCD_BASE + 0x00 )         
#define LCD_CTRL                 *( volatile Uint32* )( LCD_BASE + 0x04 )
#define LCD_STAT                 *( volatile Uint32* )( LCD_BASE + 0x08 )       
#define LIDD_CTRL                *( volatile Uint32* )( LCD_BASE + 0x0C )
#define LIDD_CS0_CONF            *( volatile Uint32* )( LCD_BASE + 0x10 )
#define LIDD_CS0_ADDR            *( volatile Uint32* )( LCD_BASE + 0x14 )         
#define LIDD_CS0_DATA            *( volatile Uint32* )( LCD_BASE + 0x18 )
#define LIDD_CS1_CONF            *( volatile Uint32* )( LCD_BASE + 0x1C )
#define LIDD_CS1_ADDR            *( volatile Uint32* )( LCD_BASE + 0x20 )         
#define LIDD_CS1_DATA            *( volatile Uint32* )( LCD_BASE + 0x24 )
#define RASTER_CTRL              *( volatile Uint32* )( LCD_BASE + 0x28 )       
#define RASTER_TIMING_0          *( volatile Uint32* )( LCD_BASE + 0x2C )
#define RASTER_TIMING_1          *( volatile Uint32* )( LCD_BASE + 0x30 )
#define RASTER_TIMING_2          *( volatile Uint32* )( LCD_BASE + 0x34 )         
#define RASTER_SUBPANEL          *( volatile Uint32* )( LCD_BASE + 0x38 )
#define LCDDMA_CTRL              *( volatile Uint32* )( LCD_BASE + 0x40 )
#define LCDDMA_FB0_BASE          *( volatile Uint32* )( LCD_BASE + 0x44 )
#define LCDDMA_FB0_CEILING       *( volatile Uint32* )( LCD_BASE + 0x48 )       
#define LCDDMA_FB1_BASE          *( volatile Uint32* )( LCD_BASE + 0x4C )
#define LCDDMA_FB1_CEILING       *( volatile Uint32* )( LCD_BASE + 0x50 )



/* ------------------------------------------------------------------------ *
 *  Prototypes                                                              *
 * ------------------------------------------------------------------------ */
/* Board Initialization */
Int16 C6747_init( );

/* Wait Functions */




void C6747_wait( Uint32 delay );
void C6747_waitusec( Uint32 usec );


void PSC0_lPSC_enable(Uint8 PD, Uint8 LPSC_num);
void PSC_enable(unsigned int PD, unsigned int LPSC_num);
void initpsc( void);
void SystemConfig(void);
void InitPLL(void);
void emifconfig(void);
void sysinit(void);



#endif
