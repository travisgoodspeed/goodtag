/* ============================================================================ */
/* Copyright (c) 2019, Texas Instruments Incorporated                           */
/*  All rights reserved.                                                        */
/*                                                                              */
/*  Redistribution and use in source and binary forms, with or without          */
/*  modification, are permitted provided that the following conditions          */
/*  are met:                                                                    */
/*                                                                              */
/*  *  Redistributions of source code must retain the above copyright           */
/*     notice, this list of conditions and the following disclaimer.            */
/*                                                                              */
/*  *  Redistributions in binary form must reproduce the above copyright        */
/*     notice, this list of conditions and the following disclaimer in the      */
/*     documentation and/or other materials provided with the distribution.     */
/*                                                                              */
/*  *  Neither the name of Texas Instruments Incorporated nor the names of      */
/*     its contributors may be used to endorse or promote products derived      */
/*     from this software without specific prior written permission.            */
/*                                                                              */
/*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" */
/*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,       */
/*  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR      */
/*  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR            */
/*  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,       */
/*  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,         */
/*  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; */
/*  OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    */
/*  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR     */
/*  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,              */
/*  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                          */
/* ============================================================================ */

/* This file supports RF430FRL152H devices. */
/* Version: 1.207 */

/************************************************************
* STANDARD BITS
************************************************************/
/************************************************************
* STATUS REGISTER BITS
************************************************************/
/************************************************************
* PERIPHERAL FILE MAP
************************************************************/
/************************************************************
* COMPACT CLOCK SYSTEM
************************************************************/
PROVIDE(CCSCTL0            = 0x0160);
PROVIDE(CCSCTL0_L          = 0x0160);
PROVIDE(CCSCTL0_H          = 0x0161);
PROVIDE(CCSCTL1            = 0x0162);
PROVIDE(CCSCTL1_L          = 0x0162);
PROVIDE(CCSCTL1_H          = 0x0163);
PROVIDE(CCSCTL2            = 0x0164);
PROVIDE(CCSCTL2_L          = 0x0164);
PROVIDE(CCSCTL2_H          = 0x0165);
PROVIDE(CCSCTL4            = 0x0168);
PROVIDE(CCSCTL4_L          = 0x0168);
PROVIDE(CCSCTL4_H          = 0x0169);
PROVIDE(CCSCTL5            = 0x016A);
PROVIDE(CCSCTL5_L          = 0x016A);
PROVIDE(CCSCTL5_H          = 0x016B);
PROVIDE(CCSCTL6            = 0x016C);
PROVIDE(CCSCTL6_L          = 0x016C);
PROVIDE(CCSCTL6_H          = 0x016D);
PROVIDE(CCSCTL7            = 0x016E);
PROVIDE(CCSCTL7_L          = 0x016E);
PROVIDE(CCSCTL7_H          = 0x016F);
PROVIDE(CCSCTL8            = 0x0170);
PROVIDE(CCSCTL8_L          = 0x0170);
PROVIDE(CCSCTL8_H          = 0x0171);
/*************************************************************
* CRC Module
*************************************************************/
PROVIDE(CRCDI              = 0x0150);
PROVIDE(CRCDI_L            = 0x0150);
PROVIDE(CRCDI_H            = 0x0151);
PROVIDE(CRCDIRB            = 0x0152);
PROVIDE(CRCDIRB_L          = 0x0152);
PROVIDE(CRCDIRB_H          = 0x0153);
PROVIDE(CRCINIRES          = 0x0154);
PROVIDE(CRCINIRES_L        = 0x0154);
PROVIDE(CRCINIRES_H        = 0x0155);
PROVIDE(CRCRESR            = 0x0156);
PROVIDE(CRCRESR_L          = 0x0156);
PROVIDE(CRCRESR_H          = 0x0157);
/************************************************************
* DIGITAL I/O Port1/2 Pull up / Pull down Resistors
************************************************************/
PROVIDE(PAIN               = 0x0200);
PROVIDE(PAIN_L             = 0x0200);
PROVIDE(PAIN_H             = 0x0201);
PROVIDE(PAOUT              = 0x0202);
PROVIDE(PAOUT_L            = 0x0202);
PROVIDE(PAOUT_H            = 0x0203);
PROVIDE(PADIR              = 0x0204);
PROVIDE(PADIR_L            = 0x0204);
PROVIDE(PADIR_H            = 0x0205);
PROVIDE(PAREN              = 0x0206);
PROVIDE(PAREN_L            = 0x0206);
PROVIDE(PAREN_H            = 0x0207);
PROVIDE(PADS               = 0x0208);
PROVIDE(PADS_L             = 0x0208);
PROVIDE(PADS_H             = 0x0209);
PROVIDE(PASEL0             = 0x020A);
PROVIDE(PASEL0_L           = 0x020A);
PROVIDE(PASEL0_H           = 0x020B);
PROVIDE(PASEL1             = 0x020C);
PROVIDE(PASEL1_L           = 0x020C);
PROVIDE(PASEL1_H           = 0x020D);
PROVIDE(PAIES              = 0x0218);
PROVIDE(PAIES_L            = 0x0218);
PROVIDE(PAIES_H            = 0x0219);
PROVIDE(PAIE               = 0x021A);
PROVIDE(PAIE_L             = 0x021A);
PROVIDE(PAIE_H             = 0x021B);
PROVIDE(PAIFG              = 0x021C);
PROVIDE(PAIFG_L            = 0x021C);
PROVIDE(PAIFG_H            = 0x021D);
PROVIDE(P1IV               = 0x020E);
PROVIDE(P2IV               = 0x021E);
/************************************************************
* RF13M (13MHz NFC communication module)
************************************************************/
PROVIDE(RF13MCTL           = 0x0800);
PROVIDE(RF13MCTL_L         = 0x0800);
PROVIDE(RF13MCTL_H         = 0x0801);
PROVIDE(RF13MINT           = 0x0802);
PROVIDE(RF13MINT_L         = 0x0802);
PROVIDE(RF13MINT_H         = 0x0803);
PROVIDE(RF13MIV            = 0x0804);
PROVIDE(RF13MIV_L          = 0x0804);
PROVIDE(RF13MIV_H          = 0x0805);
PROVIDE(RF13MRXF           = 0x0806);
PROVIDE(RF13MRXF_L         = 0x0806);
PROVIDE(RF13MRXF_H         = 0x0807);
PROVIDE(RF13MTXF           = 0x0808);
PROVIDE(RF13MTXF_L         = 0x0808);
PROVIDE(RF13MTXF_H         = 0x0809);
PROVIDE(RF13MCRC           = 0x080A);
PROVIDE(RF13MCRC_L         = 0x080A);
PROVIDE(RF13MCRC_H         = 0x080B);
PROVIDE(RF13MFIFOFL        = 0x080C);
PROVIDE(RF13MFIFOFL_L      = 0x080C);
PROVIDE(RF13MFIFOFL_H      = 0x080D);
PROVIDE(RF13MWMCFG         = 0x080E);
PROVIDE(RF13MWMCFG_L       = 0x080E);
PROVIDE(RF13MWMCFG_H       = 0x080F);
PROVIDE(RF13MRXBUF         = 0x0820);
PROVIDE(RF13MRXBUF_L       = 0x0820);
PROVIDE(RF13MRXBUF_H       = 0x0821);
PROVIDE(RF13MTXBUF         = 0x0840);
PROVIDE(RF13MTXBUF_L       = 0x0840);
PROVIDE(RF13MTXBUF_H       = 0x0841);
/************************************************************
* SD14 (14 Bit sigma delta ADC)
************************************************************/
PROVIDE(SD14CTL0           = 0x0700);
PROVIDE(SD14CTL0_L         = 0x0700);
PROVIDE(SD14CTL0_H         = 0x0701);
PROVIDE(SD14CTL1           = 0x0702);
PROVIDE(SD14CTL1_L         = 0x0702);
PROVIDE(SD14CTL1_H         = 0x0703);
PROVIDE(SD14MEM0           = 0x0704);
PROVIDE(SD14MEM0_L         = 0x0704);
PROVIDE(SD14MEM0_H         = 0x0705);
PROVIDE(SD14MEM1           = 0x0706);
PROVIDE(SD14MEM1_L         = 0x0706);
PROVIDE(SD14MEM1_H         = 0x0707);
PROVIDE(SD14MEM2           = 0x0708);
PROVIDE(SD14MEM2_L         = 0x0708);
PROVIDE(SD14MEM2_H         = 0x0709);
PROVIDE(SD14MEM3           = 0x070A);
PROVIDE(SD14MEM3_L         = 0x070A);
PROVIDE(SD14MEM3_H         = 0x070B);
PROVIDE(SD14IV             = 0x070C);
PROVIDE(SD14IV_L           = 0x070C);
PROVIDE(SD14IV_H           = 0x070D);
/************************************************************
* USCI B0
************************************************************/
PROVIDE(UCB0CTLW0          = 0x0640);
PROVIDE(UCB0CTLW0_L        = 0x0640);
PROVIDE(UCB0CTLW0_H        = 0x0641);
PROVIDE(UCB0CTLW1          = 0x0642);
PROVIDE(UCB0CTLW1_L        = 0x0642);
PROVIDE(UCB0CTLW1_H        = 0x0643);
PROVIDE(UCB0BRW            = 0x0646);
PROVIDE(UCB0BRW_L          = 0x0646);
PROVIDE(UCB0BRW_H          = 0x0647);
PROVIDE(UCB0STATW          = 0x0648);
PROVIDE(UCB0STATW_L        = 0x0648);
PROVIDE(UCB0STATW_H        = 0x0649);
PROVIDE(UCB0TBCNT          = 0x064A);
PROVIDE(UCB0TBCNT_L        = 0x064A);
PROVIDE(UCB0TBCNT_H        = 0x064B);
PROVIDE(UCB0RXBUF          = 0x064C);
PROVIDE(UCB0RXBUF_L        = 0x064C);
PROVIDE(UCB0RXBUF_H        = 0x064D);
PROVIDE(UCB0TXBUF          = 0x064E);
PROVIDE(UCB0TXBUF_L        = 0x064E);
PROVIDE(UCB0TXBUF_H        = 0x064F);
PROVIDE(UCB0I2COA0         = 0x0654);
PROVIDE(UCB0I2COA0_L       = 0x0654);
PROVIDE(UCB0I2COA0_H       = 0x0655);
PROVIDE(UCB0I2COA1         = 0x0656);
PROVIDE(UCB0I2COA1_L       = 0x0656);
PROVIDE(UCB0I2COA1_H       = 0x0657);
PROVIDE(UCB0I2COA2         = 0x0658);
PROVIDE(UCB0I2COA2_L       = 0x0658);
PROVIDE(UCB0I2COA2_H       = 0x0659);
PROVIDE(UCB0I2COA3         = 0x065A);
PROVIDE(UCB0I2COA3_L       = 0x065A);
PROVIDE(UCB0I2COA3_H       = 0x065B);
PROVIDE(UCB0ADDRX          = 0x065C);
PROVIDE(UCB0ADDRX_L        = 0x065C);
PROVIDE(UCB0ADDRX_H        = 0x065D);
PROVIDE(UCB0ADDMASK        = 0x065E);
PROVIDE(UCB0ADDMASK_L      = 0x065E);
PROVIDE(UCB0ADDMASK_H      = 0x065F);
PROVIDE(UCB0I2CSA          = 0x0660);
PROVIDE(UCB0I2CSA_L        = 0x0660);
PROVIDE(UCB0I2CSA_H        = 0x0661);
PROVIDE(UCB0IE             = 0x066A);
PROVIDE(UCB0IE_L           = 0x066A);
PROVIDE(UCB0IE_H           = 0x066B);
PROVIDE(UCB0IFG            = 0x066C);
PROVIDE(UCB0IFG_L          = 0x066C);
PROVIDE(UCB0IFG_H          = 0x066D);
PROVIDE(UCB0IV             = 0x066E);
/************************************************************
* SFR - Special Function Register Module
************************************************************/
PROVIDE(SFRIE1             = 0x0100);
PROVIDE(SFRIE1_L           = 0x0100);
PROVIDE(SFRIE1_H           = 0x0101);
PROVIDE(SFRIFG1            = 0x0102);
PROVIDE(SFRIFG1_L          = 0x0102);
PROVIDE(SFRIFG1_H          = 0x0103);
PROVIDE(SFRRPCR            = 0x0104);
PROVIDE(SFRRPCR_L          = 0x0104);
PROVIDE(SFRRPCR_H          = 0x0105);
/************************************************************
* COMPACT SYS - System Module
************************************************************/
PROVIDE(SYSCTL             = 0x0180);
PROVIDE(SYSCTL_L           = 0x0180);
PROVIDE(SYSCTL_H           = 0x0181);
PROVIDE(SYSJMBC            = 0x0186);
PROVIDE(SYSJMBC_L          = 0x0186);
PROVIDE(SYSJMBC_H          = 0x0187);
PROVIDE(SYSJMBI0           = 0x0188);
PROVIDE(SYSJMBI0_L         = 0x0188);
PROVIDE(SYSJMBI0_H         = 0x0189);
PROVIDE(SYSJMBI1           = 0x018A);
PROVIDE(SYSJMBI1_L         = 0x018A);
PROVIDE(SYSJMBI1_H         = 0x018B);
PROVIDE(SYSJMBO0           = 0x018C);
PROVIDE(SYSJMBO0_L         = 0x018C);
PROVIDE(SYSJMBO0_H         = 0x018D);
PROVIDE(SYSJMBO1           = 0x018E);
PROVIDE(SYSJMBO1_L         = 0x018E);
PROVIDE(SYSJMBO1_H         = 0x018F);
PROVIDE(SYSCNF             = 0x0190);
PROVIDE(SYSCNF_L           = 0x0190);
PROVIDE(SYSCNF_H           = 0x0191);
PROVIDE(SYSBERRIV          = 0x0198);
PROVIDE(SYSBERRIV_L        = 0x0198);
PROVIDE(SYSBERRIV_H        = 0x0199);
PROVIDE(SYSUNIV            = 0x019A);
PROVIDE(SYSUNIV_L          = 0x019A);
PROVIDE(SYSUNIV_H          = 0x019B);
PROVIDE(SYSSNIV            = 0x019C);
PROVIDE(SYSSNIV_L          = 0x019C);
PROVIDE(SYSSNIV_H          = 0x019D);
PROVIDE(SYSRSTIV           = 0x019E);
PROVIDE(SYSRSTIV_L         = 0x019E);
PROVIDE(SYSRSTIV_H         = 0x019F);
/************************************************************
* PMM_RF - Power Management System of RF
************************************************************/
PROVIDE(RFPMMCTL0          = 0x0120);
PROVIDE(RFPMMCTL0_L        = 0x0120);
PROVIDE(RFPMMCTL0_H        = 0x0121);
PROVIDE(RFPMMCTL1          = 0x0122);
PROVIDE(RFPMMCTL1_L        = 0x0122);
PROVIDE(RFPMMCTL1_H        = 0x0123);
PROVIDE(RFMMIE             = 0x0124);
PROVIDE(RFMMIE_L           = 0x0124);
PROVIDE(RFMMIE_H           = 0x0125);
PROVIDE(RFPMMIFG           = 0x0126);
PROVIDE(RFPMMIFG_L         = 0x0126);
PROVIDE(RFPMMIFG_H         = 0x0127);
PROVIDE(RFPMMIV            = 0x0128);
PROVIDE(RFPMMIV_L          = 0x0128);
PROVIDE(RFPMMIV_H          = 0x0129);
/************************************************************
* Timer0_A3
************************************************************/
PROVIDE(TA0CTL             = 0x0340);
PROVIDE(TA0CCTL0           = 0x0342);
PROVIDE(TA0CCTL1           = 0x0344);
PROVIDE(TA0CCTL2           = 0x0346);
PROVIDE(TA0R               = 0x0350);
PROVIDE(TA0CCR0            = 0x0352);
PROVIDE(TA0CCR1            = 0x0354);
PROVIDE(TA0CCR2            = 0x0356);
PROVIDE(TA0IV              = 0x036E);
PROVIDE(TA0EX0             = 0x0360);
/************************************************************
* WATCHDOG TIMER A
************************************************************/
PROVIDE(WDTCTL             = 0x015C);
PROVIDE(WDTCTL_L           = 0x015C);
PROVIDE(WDTCTL_H           = 0x015D);
/************************************************************
* Interrupt Vectors (offset from 0xFFFF - 0x20)
************************************************************/
/************************************************************
* End of Modules
************************************************************/
