/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : NVIC                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MNVIC_config.h"
#include "MNVIC_private.h"
#include "MNVIC_register.h"
#include "MNVIC_interface.h"


/* A function to Enable or Disable Interrupt on Peripheral */
u8 MNVIC_u8EnableDisableInterrupt(u8 Copy_u8InterruptId , u8 Copy_u8InterruptStatus)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check the Interrupt Peripheral number is less than or equal 31 */
	if 		(Copy_u8InterruptId <= MNVIC_I2C1_EV)
	{
		/* Check Interrupt status */
		switch (Copy_u8InterruptStatus)
		{
			case MNVIC_ENABLE_INTERRUPT  	:	MNVIC_ISER0 = (1 << Copy_u8InterruptId);	break;	 
			case MNVIC_DISABLE_INTERRUPT	:	MNVIC_ICER0 = (1 << Copy_u8InterruptId);	break;	 
			default							:	Local_u8ErrorState = NOK;	break;	 
		}
	}
	/* Check the Interrupt Peripheral number is less than or equal 59 */
	else if (Copy_u8InterruptId <= MNVIC_DMA2_CHANNEL4_5)
	{
		/* Adjust Interrupt number to start from 0 */
		Copy_u8InterruptId -= 31;
		
		/* Check Interrupt status */
		switch (Copy_u8InterruptStatus)
		{
			case MNVIC_ENABLE_INTERRUPT  	:	MNVIC_ISER1 = (1 << Copy_u8InterruptId);	break;	 
			case MNVIC_DISABLE_INTERRUPT	:	MNVIC_ICER1 = (1 << Copy_u8InterruptId);	break;	 
			default							:	Local_u8ErrorState = NOK;	break;	 
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


/* A function to Set or Clear Pending Flag of Peripheral */
u8 MNVIC_u8SetClearPendingFlag(u8 Copy_u8InterruptId , u8 Copy_u8FlagStatus)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check the Interrupt Peripheral number is less than or equal 31 */
	if 		(Copy_u8InterruptId <= MNVIC_I2C1_EV)
	{
		/* Check Interrupt status */
		switch (Copy_u8FlagStatus)
		{
			case MNVIC_SET_PENDING_FLAG  	:	MNVIC_ISPR0 = (1 << Copy_u8InterruptId);	break;
			case MNVIC_CLR_PENDING_FLAG		:	MNVIC_ICPR0 = (1 << Copy_u8InterruptId);	break;
			default							:	Local_u8ErrorState = NOK;	break;
		}
	}
	/* Check the Interrupt Peripheral number is less than or equal 59 */
	else if (Copy_u8InterruptId <= MNVIC_DMA2_CHANNEL4_5)
	{
		/* Adjust Interrupt number to start from 0 */
		Copy_u8InterruptId -= 31;
		
		/* Check Interrupt status */
		switch (Copy_u8FlagStatus)
		{
			case MNVIC_SET_PENDING_FLAG  	:	MNVIC_ISPR1 = (1 << Copy_u8InterruptId);	break;
			case MNVIC_CLR_PENDING_FLAG		:	MNVIC_ICPR1 = (1 << Copy_u8InterruptId);	break;
			default							:	Local_u8ErrorState = NOK;	break;
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


/* A function to Get Active Flag Reading of Peripheral */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptId , u8* Copy_u8FlagReading)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check the Interrupt Peripheral number is less than or equal 31 */
	if 		(Copy_u8InterruptId <= MNVIC_I2C1_EV)
	{
		/* Get Peripheral Active Flag Reading */
		*Copy_u8FlagReading = GET_BIT(MNVIC_IABR0 , Copy_u8InterruptId);
	}
	/* Check the Interrupt Peripheral number is less than or equal 59 */
	else if (Copy_u8InterruptId <= MNVIC_DMA2_CHANNEL4_5)
	{
		/* Adjust Interrupt number to start from 0 */
		Copy_u8InterruptId -= 31;
		
		/* Get Peripheral Active Flag Reading */
		*Copy_u8FlagReading = GET_BIT(MNVIC_IABR0 , Copy_u8InterruptId);
	}
	else 
	{
		/* Error State NOT OK */
		Local_u8ErrorState = NOK;
	}
	
	/* Return Error State */
	return Local_u8ErrorState;
}


u8 MNVIC_u8SetPriority(s8 Copy_s8InterruptId , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;

	/* Check the Group and Sub Group is suitable */
	#if MSCB_PRIORITY == MSCB_16GROUP_0SUB					//4 bits Group & 0 bits Sub Group
		if (Copy_u8GroupPriority > 15 || Copy_u8SubPriority != 0)	Local_u8ErrorState = NOK;
	#elif MSCB_PRIORITY == MSCB_8GROUP_2SUB					//3 bits Group & 1 bits Sub Group
		if (Copy_u8GroupPriority > 7 || Copy_u8SubPriority > 1)		Local_u8ErrorState = NOK;
	#elif MSCB_PRIORITY == MSCB_4GROUP_4SUB					//2 bits Group & 2 bits Sub Group
		if (Copy_u8GroupPriority > 3 || Copy_u8SubPriority > 3)		Local_u8ErrorState = NOK;
	#elif MSCB_PRIORITY == MSCB_2GROUP_8SUB					//1 bits Group & 3 bits Sub Group
		if (Copy_u8GroupPriority > 1 || Copy_u8SubPriority > 7)		Local_u8ErrorState = NOK;
	#elif MSCB_PRIORITY == MSCB_0GROUP_16SUB				//0 bits Group & 4 bits Sub Group
		if (Copy_u8GroupPriority != 0 || Copy_u8SubPriority > 15)	Local_u8ErrorState = NOK;
	#else
		#error "Choose a suitable number of Group and Sub Group "

	#endif

	/* Initialize Priority */
	u8 Local_u8Priority = Copy_u8SubPriority | (Copy_u8GroupPriority << (MSCB_PRIORITY - MSCB_16GROUP_0SUB)/0x100);

	/* Core Peripherals */
	if( Copy_s8InterruptId < 0 )
	{
		if( Copy_s8InterruptId == MNVIC_MEMORY_MANAGE || Copy_s8InterruptId == MNVIC_BUS_FAULT || Copy_s8InterruptId == MNVIC_USAGE_FAULT ){

			/* Adjust Offset to be In Right Place (0 -> 2) */
			Copy_s8InterruptId += 3;

			/* Set Internal Peripheral Group and Sub Group Priority */
			MSCB_SHPR1 = (Local_u8Priority) << ((8*Copy_s8InterruptId) + 4);
		}
		else if ( Copy_s8InterruptId == MNVIC_SV_CALL ){

			/* Adjust Offset to be In Right Place (3) */
			Copy_s8InterruptId += 7;

			/* Set Internal Peripheral Group and Sub Group Priority */
			MSCB_SHPR2 = (Local_u8Priority) << ((8*Copy_s8InterruptId) + 4);
		}
		else if( Copy_s8InterruptId == MNVIC_PEND_SV || Copy_s8InterruptId == MNVIC_SYSTICK ){

			/* Adjust Offset to be In Right Place (2 -> 3) */
			Copy_s8InterruptId += 8;

			/* Set Internal Peripheral Group and Sub Group Priority */
			MSCB_SHPR3 = (Local_u8Priority) << ((8*Copy_s8InterruptId) + 4);
		}
		else
		{
			/* Error State NOT OK */
			Local_u8ErrorState = NOK;
		}
	}
	/* External Peripherals */
	else if (Copy_s8InterruptId >= MNVIC_WWDG)
	{
		/* Set External Peripheral Group and Sub Group Priority */
		MNVIC_IPR[Copy_s8InterruptId] = Local_u8Priority << 4;
	}
	else
	{
		/* Error State NOT OK */
		Local_u8ErrorState = NOK;
	}

	/* Return Error State */
	return Local_u8ErrorState;
}


void MNVIC_voidInit(void)
{
	/* APPLICATION INTERRUPT & RESET CONTROL REGISTER (SYSTEM CONTROL BLOCK) */
	#define MSCB_AIRCR			*((volatile u32*)0xE000ED0C)

	MSCB_AIRCR = MSCB_PRIORITY;
}










