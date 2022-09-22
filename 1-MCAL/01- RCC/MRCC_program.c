/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : RCC                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#include "STD_TYPES.h"
#include "MRCC_interface.h"
#include "MRCC_register.h"

#include "BIT_MATH.h"
#include "MRCC_config.h"
#include "MRCC_interface.h"
#include "MRCC_private.h"



/* Description : A function to Enable or Disable Clock on Peripheral */
void MRCC_voidEnableDisableClock(u8 Copy_u8BusId , u8 Copy_u8peripheralId , u8 Copy_u8BusStatus)
{
	/* Check Peripheral number don't exceed 31 */
	if(Copy_u8peripheralId <= REGISTER_LIMIT)
	{
		/* Enable Bus */
		if(Copy_u8BusStatus == MRCC_BusEnable)
		{
			switch (Copy_u8BusId)
			{
				case MRCC_AHB	:	SET_BIT(MRCC_AHBENR  , Copy_u8peripheralId);	break;
				case MRCC_APB1	:   SET_BIT(MRCC_APB1ENR , Copy_u8peripheralId);	break;
				case MRCC_APB2	:   SET_BIT(MRCC_APB2ENR , Copy_u8peripheralId);	break;
			}
		}
		/* Disable Bus */
		else if (Copy_u8BusStatus == MRCC_BusDisable)
		{
			switch (Copy_u8BusId)
			{
				case MRCC_AHB	:	CLR_BIT(MRCC_AHBENR  , Copy_u8peripheralId);	break;
				case MRCC_APB1	:   CLR_BIT(MRCC_APB1ENR , Copy_u8peripheralId);	break;
				case MRCC_APB2	:   CLR_BIT(MRCC_APB2ENR , Copy_u8peripheralId);	break;
			}
		}
		else 
		{
			/* Return Err */
		}
	}
	else 
	{
		/* Return Err */
	}
}


/* Description : A function to Determine Clock Type used for Processor */
void MRCC_voidIntiSysClock(void)
{
	#if INITIAL_SYS_CLK == MRCC_HSI
	
		/* Disable HSION BIT to Set Configuration */
		CLR_BIT(MRCC_CR , MRCC_CR_HSION);
		
		/* Set Trimming Value to 0 */
		SET_BIT(MRCC_CR , MRCC_CR_HSITRIM4);
		
		/* Choose HSI as a System CLK */
		CLR_BIT(MRCC_CFGR , MRCC_CFGR_SW0);
		CLR_BIT(MRCC_CFGR , MRCC_CFGR_SW1);
		
		/* Enable HSION BIT */
		SET_BIT(MRCC_CR , MRCC_CR_HSION);

		/* Polling (busy Waiting) until HSI is Ready */
		while (!GET_BIT(MRCC_CR , MRCC_CR_HSIRDY));

		/* Polling (busy Waiting) until HSI is chosen as System CLK */
		while (GET_BIT(MRCC_CFGR , MRCC_CFGR_SWS0));
		while (GET_BIT(MRCC_CFGR , MRCC_CFGR_SWS1));
	
	
	
	#elif INITIAL_SYS_CLK == MRCC_HSE_CRYSTAL
		
		/* Disable HSEON BIT to Set Configuration */
		CLR_BIT(MRCC_CR , MRCC_CR_HSEON);

		/* Disable HSE BYPASS BIT */
		CLR_BIT(MRCC_CR , MRCC_CR_HSEBYP);
	
		/* Choose HSE as a System CLK */
		SET_BIT(MRCC_CFGR , MRCC_CFGR_SW0);
		CLR_BIT(MRCC_CFGR , MRCC_CFGR_SW1);
		
		/* Enable HSEON BIT */
		SET_BIT(MRCC_CR , MRCC_CR_HSEON);

		/* Polling (busy Waiting) until HSE is Ready */
		while (!GET_BIT(MRCC_CR , MRCC_CR_HSERDY));

		/* Polling (busy Waiting) until HSE is chosen as System CLK */
		while (!GET_BIT(MRCC_CFGR , MRCC_CFGR_SWS0));
		while ( GET_BIT(MRCC_CFGR , MRCC_CFGR_SWS1));


	#elif INITIAL_SYS_CLK == MRCC_HSE_RC
	
		/* Disable HSEON BIT to Set Configuration */
		CLR_BIT(MRCC_CR , MRCC_CR_HSEON);
		
		/* Enable HSE BYPASS BIT */
		SET_BIT(MRCC_CR , MRCC_CR_HSEBYP);
		
		/* Choose HSE as a System CLK */
		SET_BIT(MRCC_CFGR , MRCC_CFGR_SW0);
		CLR_BIT(MRCC_CFGR , MRCC_CFGR_SW1);
		
		/* Enable HSEON BIT */
		SET_BIT(MRCC_CR , MRCC_CR_HSEON);

		/* Polling (busy Waiting) until HSE is Ready */
		while (!GET_BIT(MRCC_CR , MRCC_CR_HSERDY));

		/* Polling (busy Waiting) until HSE is chosen as System CLK */
		while (!GET_BIT(MRCC_CFGR , MRCC_CFGR_SWS0));
		while ( GET_BIT(MRCC_CFGR , MRCC_CFGR_SWS1));
		
		
		
	#elif INITIAL_SYS_CLK == MRCC_PLL
	
		/* Disable PLLON BIT */
		CLR_BIT(MRCC_CR , MRCC_CR_PLLON);

		/* Choose PLL as a System CLK */
		CLR_BIT(MRCC_CFGR , MRCC_CFGR_SW0);
		SET_BIT(MRCC_CFGR , MRCC_CFGR_SW1);

		/* Select PLL Multiplication Factor */
		MRCC_CFGR &= PLL_MUL_MASK;
		MRCC_CFGR |= PLL_MUL_FACTOR;

	
		#if 	PLL_INPUT_SRC == MRCC_PLL_IN_HSE
		
			/* Enable HSEON BIT */
			SET_BIT(MRCC_CR , MRCC_CR_HSEON);

			/* Polling (busy Waiting) until HSE is Ready */
			while (!GET_BIT(MRCC_CR , MRCC_CR_HSERDY));

			/* Select HSE as PLL Input CLK */
			SET_BIT(MRCC_CFGR , MRCC_CFGR_PLLSRC);
			
			/* HES not divided */
			CLR_BIT(MRCC_CFGR , MRCC_CFGR_PLLXTPRE);
		
		#elif	PLL_INPUT_SRC == MRCC_PLL_IN_HSE_DIV2
			
			/* Enable HSEON BIT */
			SET_BIT(MRCC_CR , MRCC_CR_HSEON);

			/* Polling (busy Waiting) until HSE is Ready */
			while (!GET_BIT(MRCC_CR , MRCC_CR_HSERDY));

			/* Select HSE as PLL Input CLK */
			SET_BIT(MRCC_CFGR , MRCC_CFGR_PLLSRC);
			
			/* HES divided by 2 */
			SET_BIT(MRCC_CFGR , MRCC_CFGR_PLLXTPRE);
			
		#elif	PLL_INPUT_SRC == MRCC_PLL_IN_HSI_DIV2
			
			/* Enable HSION BIT */
			SET_BIT(MRCC_CR , MRCC_CR_HSION);

			/* Polling (busy Waiting) until HSI is Ready */
			while (!GET_BIT(MRCC_CR , MRCC_CR_HSIRDY));

			/* Select HSI divided by 2 as PLL Input CLK */
			CLR_BIT(MRCC_CFGR , MRCC_CFGR_PLLSRC);
			
		#else
			#error "YOU CHOOSE WRONG PLL INPUT SOURCE"
		#endif
		
		/* Enable PLLON BIT */
		SET_BIT(MRCC_CR , MRCC_CR_PLLON);
		
		/* Polling (busy Waiting) until PLL is Ready */
		while (!GET_BIT(MRCC_CR , MRCC_CR_PLLRDY));
		
		/* Polling (busy Waiting) until PLL is chosen as System CLK */
		while ( GET_BIT(MRCC_CFGR , MRCC_CFGR_SWS0));
		while (!GET_BIT(MRCC_CFGR , MRCC_CFGR_SWS1));
	
	#else
		#error "YOU CHOOSE WRONG CLOCK TYPE"
	#endif
	
	/* Configure Clock Security System */
	#if CLK_SECURITY_SYS == ENABLE_CLK_SECURITY_SYS

		/* Enable Clock Security System */
		SET_BIT(MRCC_CR , MRCC_CR_CSSON);

	#elif CLK_SECURITY_SYS == DISABLE_CLK_SECURITY_SYS

		/* Enable Clock Security System */
		CLR_BIT(MRCC_CR , MRCC_CR_CSSON);

	#else
		#warning " Wrong Clock Security System Configuration Choice "
	#endif


	/* Set  Microcontroller clock output */
	MRCC_CFGR &= MCO_MASK;
	MRCC_CFGR |= MC_CLK_OUTPUT;
	
}

















