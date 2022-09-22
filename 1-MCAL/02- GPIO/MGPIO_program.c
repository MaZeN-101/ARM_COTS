/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : GPIO                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#include "STD_TYPES.h"
#include "MGPIO_interface.h"

#include "BIT_MATH.h"
#include "MGPIO_config.h"
#include "MGPIO_interface.h"
#include "MGPIO_private.h"
#include "MGPIO_register.h"


/* SET VALUE OF A PIN TO BE HIGH OR LOW */
u8 MGPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check the Pin is less than or equal 15 */
	if (Copy_u8Pin <= MGPIO_u8PIN15)
	{
		/* Check if the Pin is LOW */
		if (Copy_u8Value == MGPIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
				case MGPIO_u8PORTA : MGPIOA_BRR = (1 << Copy_u8Pin); break;		//PORT A
				case MGPIO_u8PORTB : MGPIOB_BRR = (1 << Copy_u8Pin); break;		//PORT B
				case MGPIO_u8PORTC : MGPIOC_BRR = (1 << Copy_u8Pin); break;		//PORT C
				default 		   : Local_u8ErrorState = NOK;			        //Error State NOT OK

			}
		}
		/* Check if the Pin is HIGH */
		else if (Copy_u8Value == MGPIO_u8PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
				case MGPIO_u8PORTA : MGPIOA_BSRR = (1 << Copy_u8Pin); break;	//PORT A
				case MGPIO_u8PORTB : MGPIOB_BSRR = (1 << Copy_u8Pin); break;	//PORT B
				case MGPIO_u8PORTC : MGPIOC_BSRR = (1 << Copy_u8Pin); break;	//PORT C
				default 		   : Local_u8ErrorState = NOK;					//Error State NOT OK

			}
		}
		else 
		{
			/* Error State NOT OK */
			Local_u8ErrorState = NOK;
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


/* SET VALUE OF A PORT TO BE HIGH OR LOW */
u8 MGPIO_u8SetPortValue(u8 Copy_u8Port , u16 Copy_u16Value)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	switch(Copy_u8Port)
	{
		case MGPIO_u8PORTA : MGPIOA_ODR = Copy_u16Value; break;				//PORT A
		case MGPIO_u8PORTB : MGPIOB_ODR = Copy_u16Value; break;				//PORT B
		case MGPIO_u8PORTC : MGPIOC_ODR = Copy_u16Value; break;				//PORT C
		default 	       : Local_u8ErrorState = NOK;                    	//Error State NOT OK

	}
	
	/* Return Error State */
	return Local_u8ErrorState;
}


/* SET LOCK OF A PIN TO BE MODE LOCKED OR UNLOCKED */
u8 MGPIO_u8SetPinLock(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8LockStatus)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;

	/* Check the Pin is less than or equal 15 */
	if (Copy_u8Pin <= MGPIO_u8PIN15)
	{
		/* Check if the Pin is LOW */
		if (Copy_u8LockStatus == MGPIO_u8PIN_UNLOCK)
		{
			switch(Copy_u8Port)
			{
				case MGPIO_u8PORTA : CLR_BIT(MGPIOA_LCKR , Copy_u8Pin); break;			//PORT A
				case MGPIO_u8PORTB : CLR_BIT(MGPIOB_LCKR , Copy_u8Pin); break;			//PORT B
				case MGPIO_u8PORTC : CLR_BIT(MGPIOC_LCKR , Copy_u8Pin); break;			//PORT C
				default 		   : Local_u8ErrorState = NOK;                   		//Error State NOT OK

			}
		}
		/* Check if the Pin is HIGH */
		else if (Copy_u8LockStatus == MGPIO_u8PIN_LOCK)
		{
			switch(Copy_u8Port)
			{
				case MGPIO_u8PORTA : SET_BIT(MGPIOA_LCKR , Copy_u8Pin); break;			//PORT A
				case MGPIO_u8PORTB : SET_BIT(MGPIOB_LCKR , Copy_u8Pin); break;			//PORT B
				case MGPIO_u8PORTC : SET_BIT(MGPIOC_LCKR , Copy_u8Pin); break;			//PORT C
				default 		   : Local_u8ErrorState = NOK;							//Error State NOT OK

			}
		}
		else
		{
			/* Error State NOT OK */
			Local_u8ErrorState = NOK;
		}
	}
	else
	{
		/* Error State NOT OK */
		Local_u8ErrorState = NOK;
	}

	/* Check Error Status */
	if (Local_u8ErrorState == OK)
	{
		/* Writing Sequence */
		SET_BIT(MGPIOA_LCKR , 16);
		CLR_BIT(MGPIOA_LCKR , 16);
		SET_BIT(MGPIOA_LCKR , 16);

		/* Polling (BUSY WAITING) */
		while ( GET_BIT(MGPIOA_LCKR , 16));
		while (!GET_BIT(MGPIOA_LCKR , 16));
	}

	/* Return Error State */
	return Local_u8ErrorState;
}


/* SET LOCK OF A PORT TO BE MODE LOCKED OR UNLOCKED */
u8 MGPIO_u8SetPortLock(u8 Copy_u8Port , u16 Copy_u16LockStatus)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Port)
	{
		case MGPIO_u8PORTA : MGPIOA_LCKR = Copy_u16LockStatus; break;				//PORT A
		case MGPIO_u8PORTB : MGPIOB_LCKR = Copy_u16LockStatus; break;				//PORT B
		case MGPIO_u8PORTC : MGPIOC_LCKR = Copy_u16LockStatus; break;				//PORT C
		default 	       : Local_u8ErrorState = NOK;                    			//Error State NOT OK

	}

	/* Check Error Status */
	if (Local_u8ErrorState == OK)
	{
		/* Writing Sequence */
		SET_BIT(MGPIOA_LCKR , 16);
		CLR_BIT(MGPIOA_LCKR , 16);
		SET_BIT(MGPIOA_LCKR , 16);

		/* Polling (BUSY WAITING) */
		while ( GET_BIT(MGPIOA_LCKR , 16));
		while (!GET_BIT(MGPIOA_LCKR , 16));
	}

	/* Return Error State */
	return Local_u8ErrorState;
}


/* GET VALUE OF A PIN TO BE HIGH OR LOW AND RETURN IT IN POINTER (Copy_Pu8Value) */
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_Pu8Value)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check the Pin is less than or equal 15 & Pointer Not NULL */
	if ((Copy_Pu8Value != NULL)&&(Copy_u8Pin <= MGPIO_u8PIN15))
	{
		switch(Copy_u8Port)
		{
			case MGPIO_u8PORTA : *Copy_Pu8Value = GET_BIT(MGPIOA_IDR , Copy_u8Pin); break;			//PORT A
			case MGPIO_u8PORTB : *Copy_Pu8Value = GET_BIT(MGPIOB_IDR , Copy_u8Pin); break;			//PORT B
			case MGPIO_u8PORTC : *Copy_Pu8Value = GET_BIT(MGPIOC_IDR , Copy_u8Pin); break;			//PORT C
			default 	       : Local_u8ErrorState = NOK;                                    		//Error State NOT OK

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
