/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : RCC                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MRCC_REGISTER_H_
#define MRCC_REGISTER_H_



/* RCC Clock Control Register */
#define MRCC_CR							*((volatile u32*)0x40021000)
#define MRCC_CR_HSION					0			//HSI ENABLE
#define MRCC_CR_HSIRDY					1           //HSI READY
#define MRCC_CR_HSITRIM0			    3           //HSI TRIM BIT 0
#define MRCC_CR_HSITRIM1			    4           //HSI TRIM BIT 1
#define MRCC_CR_HSITRIM2			    5           //HSI TRIM BIT 2
#define MRCC_CR_HSITRIM3			    6           //HSI TRIM BIT 3
#define MRCC_CR_HSITRIM4			    7           //HSI TRIM BIT 4
#define MRCC_CR_HSEON					16          //HSE ENABLE
#define MRCC_CR_HSERDY					17          //HSI READY
#define MRCC_CR_HSEBYP					18          //HSI BYPASS
#define MRCC_CR_CSSON					19          //CSS ENABLE
#define MRCC_CR_PLLON					24          //PLL ENABLE
#define MRCC_CR_PLLRDY					25          //PLL READY


/* RCC Clock configuration Register */
#define MRCC_CFGR						*((volatile u32*)0x40021004)
#define MRCC_CFGR_SW0					0			//SYS CLK SWITCH BIT0
#define MRCC_CFGR_SW1					1			//SYS CLK SWITCH BIT1
#define MRCC_CFGR_SWS0					2           //SYS CLK SWITCH STATUS BIT0
#define MRCC_CFGR_SWS1					3           //SYS CLK SWITCH STATUS BIT1
#define MRCC_CFGR_PLLSRC				16          //PLL SRC
#define MRCC_CFGR_PLLXTPRE				17          //HSE DIVIDER FOR PLL


/* RCC Clock Interrupt Register */
#define MRCC_CIR						*((volatile u32*)0x40021008)

/* RCC APB2 Peripheral Reset Register */
#define MRCC_APB2RSTR					*((volatile u32*)0x4002100C)

/* RCC APB1 Peripheral Reset Register */
#define MCC_APB1RSTS					*((volatile u32*)0x40021010)

/* RCC AHB peripheral Clock Enable Register */
#define MRCC_AHBENR						*((volatile u32*)0x40021014)

/* RCC APB2 peripheral Clock Enable Register */
#define MRCC_APB2ENR					*((volatile u32*)0x40021018)

/* RCC APB1 peripheral Clock Enable Register */
#define MRCC_APB1ENR					*((volatile u32*)0x4002101C)

/* RCC Backup Domain Control Register */
#define MRCC_BDCR						*((volatile u32*)0x40021020)

/* RCC Control Status Register */
#define MRCC_CSR						*((volatile u32*)0x40021024)



#endif
