/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : RCC                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

/* define REGISTER LIMIT */
#define REGISTER_LIMIT				31


/* define INITIAL_SYS_CLK for Processor */
#define MRCC_HSI						1
#define MRCC_HSE_CRYSTAL 				2
#define MRCC_HSE_RC		 				3
#define MRCC_PLL						4

/* define PLL_INPUT_SRC */
#define MRCC_PLL_IN_HSE 				1
#define MRCC_PLL_IN_HSE_DIV2			2
#define MRCC_PLL_IN_HSI_DIV2			3


/* define PLL MULTIPLICATION MASK */
#define PLL_MUL_MASK				0xFFC3FFFF


/* define PLL INPUT CLK */
#define PLL_INPUT_CLK_X2			0x00000000
#define PLL_INPUT_CLK_X3			0x00040000
#define PLL_INPUT_CLK_X4			0x00080000
#define PLL_INPUT_CLK_X5			0x000C0000
#define PLL_INPUT_CLK_X6			0x00100000
#define PLL_INPUT_CLK_X7			0x00140000
#define PLL_INPUT_CLK_X8			0x00180000
#define PLL_INPUT_CLK_X9			0x001C0000
#define PLL_INPUT_CLK_X10			0x00200000
#define PLL_INPUT_CLK_X11			0x00240000
#define PLL_INPUT_CLK_X12			0x00280000
#define PLL_INPUT_CLK_X13			0x002C0000
#define PLL_INPUT_CLK_X14			0x00300000
#define PLL_INPUT_CLK_X15			0x00340000
#define PLL_INPUT_CLK_X16			0x00380000


/* define PLL MULTIPLICATION MASK */
#define MCO_MASK					0xF8FFFFFF
	

/* define Microcontroller clock output */
#define NO_CLK 						0x00000000		
#define SYS_CLK						0x04000000
#define HSI_CLK						0x05000000
#define HSE_CLK			          	0x06000000
#define PLL_CLK_DIV2            	0x07000000


/* define CLOCK SECURITY SYSTEM */
#define ENABLE_CLK_SECURITY_SYS     	1
#define DISABLE_CLK_SECURITY_SYS    	2

#endif

