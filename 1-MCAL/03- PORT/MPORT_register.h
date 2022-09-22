/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : PORT                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MPORT_REGISTER_H_
#define MPORT_REGISTER_H_

/* GPIOA */
#define MGPIOA_CRL			*((volatile u32*)0x40010800)		//PORT CONFIGURATION REGISTER LOW
#define MGPIOA_CRH			*((volatile u32*)0x40010804)		//PORT CONFIGURATION REGISTER HIGH
#define MGPIOA_ODR			*((volatile u32*)0x4001080C)		//PORT OUTPUT DATA REGISTER


/* GPIOB */
#define MGPIOB_CRL			*((volatile u32*)0x40010C00)		//PORT CONFIGURATION REGISTER LOW
#define MGPIOB_CRH			*((volatile u32*)0x40010C04)     	//PORT CONFIGURATION REGISTER HIGH
#define MGPIOB_ODR			*((volatile u32*)0x40010C0C)     	//PORT OUTPUT DATA REGISTER


/* GPIOC */
#define MGPIOC_CRL			*((volatile u32*)0x40011000)		//PORT CONFIGURATION REGISTER LOW
#define MGPIOC_CRH			*((volatile u32*)0x40011004)     	//PORT CONFIGURATION REGISTER HIGH
#define MGPIOC_ODR			*((volatile u32*)0x4001100C)     	//PORT OUTPUT DATA REGISTER


#endif
