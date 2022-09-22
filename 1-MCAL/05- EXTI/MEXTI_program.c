/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : EXTI                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MEXTI_config.h"
#include "MEXTI_private.h"
#include "MEXTI_register.h"
#include "MEXTI_interface.h"


/* Global pointer to function to hold INT0 ISR address */
void (*EXTI_CallBack[16]) (void) = {NULL};


/* Initialize EXTI with Line and Pin Mode */
u8 MEXTI_u8Init(u8 Copy_u8EXTILine , u8 Copy_u8EXTIMode)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check the Line is less than or equal 15 */
	if (Copy_u8EXTILine <= MEXTI_LINE15)
	{
		switch(Copy_u8EXTIMode)
		{
			case MEXTI_FALLING_EDGE 	:	SET_BIT(EXTI->FTSR , Copy_u8EXTILine);	break;
			case MEXTI_RISING_EDGE 		:	SET_BIT(EXTI->RTSR , Copy_u8EXTILine);	break;
			case MEXTI_ON_CHANGE	 	:	SET_BIT(EXTI->FTSR , Copy_u8EXTILine);	SET_BIT(EXTI->RTSR , Copy_u8EXTILine);	break;
			default						:	Local_u8ErrorState = NOK;	break;
		}
	}
	else
	{
		/* Error State NOT OK */
		Local_u8ErrorState = NOK;
	}
	
	/* Return Error State */
	return Local_u8ErrorState;
}


/* Enable EXTI with Line Number */
u8 MEXTI_u8EXTIEnableLine(u8 Copy_u8EXTILine)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check the Line is less than or equal 15 */
	if (Copy_u8EXTILine <= MEXTI_LINE15)
	{
		SET_BIT(EXTI->IMR , Copy_u8EXTILine);
	}
	else
	{
		/* Error State NOT OK */
		Local_u8ErrorState = NOK;
	}
	
	/* Return Error State */
	return Local_u8ErrorState;
}


/* Disable EXTI with Line Number */
u8 MEXTI_u8EXTIDisableLine(u8 Copy_u8EXTILine)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check the Line is less than or equal 15 */
	if (Copy_u8EXTILine <= MEXTI_LINE15)
	{
		CLR_BIT(EXTI->IMR , Copy_u8EXTILine);
	}
	else
	{
		/* Error State NOT OK */
		Local_u8ErrorState = NOK;
	}
	
	/* Return Error State */
	return Local_u8ErrorState;
}


/* Enable SoftWare Trigger with Line Number */
u8 MEXTI_u8EXTISWTrigger(u8 Copy_u8EXTILine)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check the Line is less than or equal 15 */
	if (Copy_u8EXTILine <= MEXTI_LINE15)
	{
		SET_BIT(EXTI->SWIER , Copy_u8EXTILine);
	}
	else
	{
		/* Error State NOT OK */
		Local_u8ErrorState = NOK;
	}
	
	/* Return Error State */
	return Local_u8ErrorState;
}


/* Set Call Back For ISR in main */
u8 MEXTI_u8SetCallBack(void(*Copy_Pv2func)(void) , u8 Copy_u8EXTINum)
{
	/* Error state OK */
	u8 Local_ErrStatus = OK;

	/* Check if the pointer is NULL or NOT */
	if (Copy_Pv2func != NULL)
	{
		EXTI_CallBack[Copy_u8EXTINum] = Copy_Pv2func;
	}
	else
	{
		/* Error State NOT OK */
		Local_ErrStatus = NULL_POINTER;
	}

	/* Return Error State */
	return Local_ErrStatus;
}


/* EXTI0 ISR Interrupt Handler */
void EXTI0_IRQHandler(void)
{
	/* Check if the pointer is NULL or NOT */
	if (EXTI_CallBack[0] != NULL)
	{
		EXTI_CallBack[0]();

		SET_BIT(EXTI->PR , 0);
	}
	else
	{
		/* Do Nothing */
	}
}






