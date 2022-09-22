/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : GPIO                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MGPIO_REGISTER_H_
#define MGPIO_REGISTER_H_

/* PORTA REGISTERS ADDRESSES */
#define MGPIOA_CRL			*((volatile u32*)0x40010800)			//PORT CONFIGURATION REGISTER LOW
#define MGPIOA_CRH			*((volatile u32*)0x40010804)         	//PORT CONFIGURATION REGISTER HIGH
#define MGPIOA_IDR			*((volatile u32*)0x40010808)			//PORT INPUT DATA REGISTER
#define MGPIOA_ODR			*((volatile u32*)0x4001080C)			//PORT OUTPUT DATA REGISTER
#define MGPIOA_BSRR			*((volatile u32*)0x40010810)			//PORT BIT SET/RESET REGISTER
#define MGPIOA_BRR			*((volatile u32*)0x40010814)			//PORT BIT RESET REGISTER
#define MGPIOA_LCKR			*((volatile u32*)0x40010818)			//PORT CONFIGURATION LOCK REGISTER

/* PORTB REGISTERS ADDRESSES */
#define MGPIOB_CRL			*((volatile u32*)0x40010C00)			//PORT CONFIGURATION REGISTER LOW
#define MGPIOB_CRH			*((volatile u32*)0x40010C04)         	//PORT CONFIGURATION REGISTER HIGH
#define MGPIOB_IDR			*((volatile u32*)0x40010C08)         	//PORT INPUT DATA REGISTER
#define MGPIOB_ODR			*((volatile u32*)0x40010C0C)        	//PORT OUTPUT DATA REGISTER
#define MGPIOB_BSRR			*((volatile u32*)0x40010C10)        	//PORT BIT SET/RESET REGISTER
#define MGPIOB_BRR			*((volatile u32*)0x40010C14)         	//PORT BIT RESET REGISTER
#define MGPIOB_LCKR			*((volatile u32*)0x40010C18)         	//PORT CONFIGURATION LOCK REGISTER

/* PORTC REGISTERS ADDRESSES */
#define MGPIOC_CRL			*((volatile u32*)0x40011000)         	//PORT CONFIGURATION REGISTER LOW
#define MGPIOC_CRH			*((volatile u32*)0x40011004)        	//PORT CONFIGURATION REGISTER HIGH
#define MGPIOC_IDR			*((volatile u32*)0x40011008)        	//PORT INPUT DATA REGISTER
#define MGPIOC_ODR			*((volatile u32*)0x4001100C)        	//PORT OUTPUT DATA REGISTER
#define MGPIOC_BSRR			*((volatile u32*)0x40011010)         	//PORT BIT SET/RESET REGISTER
#define MGPIOC_BRR			*((volatile u32*)0x40011014)         	//PORT BIT RESET REGISTER
#define MGPIOC_LCKR			*((volatile u32*)0x40011018)        	//PORT CONFIGURATION LOCK REGISTER

#endif
