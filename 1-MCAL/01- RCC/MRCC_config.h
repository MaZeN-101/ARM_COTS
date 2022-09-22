/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : RCC                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MRCC_CONFIG_H_
#define MRCC_CONFIG_H_

/* define INITIAL_SYS_CLK for Processor
 * options:
 * 		1- MRCC_HSI
 * 		2- MRCC_HSE_CRYSTAL
 *		3- MRCC_HSE_RC
 * 		4- MRCC_PLL
 * */

#define INITIAL_SYS_CLK			MRCC_HSE_CRYSTAL



/* define PLL_INPUT_SRC
 * options:
 * 		1- MRCC_PLL_IN_HSE
 * 		2- MRCC_PLL_IN_HSE_DIV2
 *		3- MRCC_PLL_IN_HSI_DIV2
 * 
 * NOTE : Select value only if you have PLL value as INITIAL_SYS_CLK */
#if INITIAL_SYS_CLK == MRCC_PLL

#define PLL_INPUT_SRC			MRCC_PLL_IN_HSE

#endif

/* define PLL_MUL_FACTOR for clock
 * options:
 * 		01- PLL_INPUT_CLK_X2
 * 		02- PLL_INPUT_CLK_X3
 * 		03- PLL_INPUT_CLK_X4
 *		04- PLL_INPUT_CLK_X5
 * 		05- PLL_INPUT_CLK_X6
 * 		06- PLL_INPUT_CLK_X7
 *		07- PLL_INPUT_CLK_X8
 * 		08- PLL_INPUT_CLK_X9
 * 		09- PLL_INPUT_CLK_X10
 *		10- PLL_INPUT_CLK_X11
 * 		11- PLL_INPUT_CLK_X12
 * 		12- PLL_INPUT_CLK_X13
 *		13- PLL_INPUT_CLK_X14
 * 		14- PLL_INPUT_CLK_X15
 * 		15- PLL_INPUT_CLK_X16
 * 
 * NOTE : Select value only if you have PLL value as INITIAL_SYS_CLK 
 * Caution: The PLL output frequency must not exceed 72 MHz
 * */
#if INITIAL_SYS_CLK == MRCC_PLL

#define PLL_MUL_FACTOR			PLL_INPUT_CLK_X2

#endif


/* define MC_CLOCK_OUTPUT
 * options:
 * 		1- NO_CLK 
 * 		2- SYS_CLK
 *		3- HSI_CLK
 * 		4- HSE_CLK
 *		5- PLL_CLK_DIV2
 * */

#define MC_CLK_OUTPUT			NO_CLK


/* define CLOCK_SECURITY_SYSTEM
 * options:
 * 		1- ENABLE_CLK_SECURITY_SYS
 * 		2- DISABLE_CLK_SECURITY_SYS
 * */

#define CLK_SECURITY_SYS		DISABLE_CLK_SECURITY_SYS


#endif
