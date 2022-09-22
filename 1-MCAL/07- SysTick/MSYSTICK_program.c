/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SYSTICK              ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSYSTICK_config.h"
#include "MSYSTICK_private.h"
#include "MSYSTICK_register.h"
#include "MSYSTICK_interface.h"



/* Global pointer to function to hold SysTick ISR address */
void (*SYSTICK_CallBack) (void) = NULL;

/* Initialize variable to differentiate between single & periodic Intervals */
u8 Global_u8STKInterval = 0;


/* Description : A function to Initialize SysTick Peripheral */
void MSYSTICK_voidInit(void)
{
	/*  Select SysTick Clock Source Value  */
	#if MSYSTICK_CLK_SOURCE == MSYSTICK_AHB_DIV_BY_8
		CLR_BIT(SYSTICK -> CTRL , MSYSTICK_CLK_SRC);
	#elif MSYSTICK_CLK_SOURCE == MSYSTICK_AHB
		SET_BIT(SYSTICK -> CTRL , MSYSTICK_CLK_SRC);
	#else 
		#error "Select a Suitable Clock Source"
	#endif
	
	/*  Disable SysTick Interrupt */
	CLR_BIT(SYSTICK -> CTRL , MSYSTICK_INTERRUPT);

	/* Disable SysTick */
	CLR_BIT(SYSTICK -> CTRL , MSYSTICK_ENABLE);
}


/* A function to Set time in Ticks (Polling) (Synchronous) */
void MSYSTICK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Load Value to the Timer in us */
	SYSTICK -> LOAD = Copy_u32Ticks;

	/* Enable SysTick to Start Counting */
	SET_BIT(SYSTICK -> CTRL , MSYSTICK_ENABLE);

	/* Polling (BUSY WAITING) until Timer is Finished */
	while(!GET_BIT(SYSTICK -> CTRL , MSYSTICK_COUNT_FLAG));

	/* Reset Load Register */
	SYSTICK -> LOAD = MSYSTICK_RESET;

	/* Reset Value Register */
	SYSTICK -> VAL = MSYSTICK_RESET;
}

 /* A function to Set time in Ticks in a single Interval (Asynchronous) */
u8 MSYSTICK_u8SetIntervalSingle(u32 Copy_u32Ticks , void(*Copy_Ptr2Fun)(void))
{
	/* Initialize Error Status OK */
	u8 Local_ErrStatus = OK;

	/* Disable Interrupt */
	CLR_BIT(SYSTICK -> CTRL , MSYSTICK_ENABLE);

	/* Reset Value Register */
	SYSTICK -> VAL = 0;

	/* Load Value to the Timer in us */
	SYSTICK -> LOAD = Copy_u32Ticks;

	if (Copy_Ptr2Fun != NULL)
	{
		/* Pass User ISR To Global Pointer */
		SYSTICK_CallBack = Copy_Ptr2Fun;

		/* Enable SYSTICK Interrupt */
		SET_BIT(SYSTICK -> CTRL , MSYSTICK_INTERRUPT);

		/* Enable SYSTICK to Start Counting */
		SET_BIT(SYSTICK -> CTRL , MSYSTICK_ENABLE);

		/* Set SysTick Interval to Single */
		Global_u8STKInterval = MSYSTIC_SINGLE_INTERVAL;
	}
	else
	{
		/* Set Error Status Null Pointer */
		Local_ErrStatus = NULL_POINTER;
	}

	/* Return Error Status */
	return Local_ErrStatus;
}


/* A function to Set time in Ticks in a periodic Interval (Asynchronous) */
u8 MSYSTICK_u8SetIntervalPeriodic(u32 Copy_u32Ticks , void(*Copy_Ptr2Fun)(void))
{
	/* Initialize Error Status OK */
	u8 Local_ErrStatus = OK;

	/* Load Value to the Timer in us */
	SYSTICK -> LOAD = Copy_u32Ticks;

	if (Copy_Ptr2Fun != NULL)
	{
		/* Pass User ISR To Global Pointer */
		SYSTICK_CallBack = Copy_Ptr2Fun;

		/* Enable SYSTICK Interrupt */
		SET_BIT(SYSTICK -> CTRL , MSYSTICK_INTERRUPT);

		/* Enable SYSTICK to Start Counting */
		SET_BIT(SYSTICK -> CTRL , MSYSTICK_ENABLE);

		/* Set SysTick Interval to Periodic */
		Global_u8STKInterval = MSYSTIC_PERIODIC_INTERVAL;
	}
	else
	{
		/* Set Error Status Null Pointer */
		Local_ErrStatus = NULL_POINTER;
	}

	/* Return Error Status */
	return Local_ErrStatus;
}


/* A function to Stop Timer if Interval was Single or Periodic */
void MSYSTICK_voidStopTimer(void)
{
	/* Reset Load Register */
	SYSTICK -> LOAD = MSYSTICK_RESET;

	/* Reset Value Register */
	SYSTICK -> VAL = MSYSTICK_RESET;

	/* Disable SYSTICK Interrupt */
	CLR_BIT(SYSTICK -> CTRL , MSYSTICK_INTERRUPT);
}


/* A function to Get Elapsed time in Ticks */
u32 MSYSTICK_u32GetElapsedTime(void)
{
	return (SYSTICK -> LOAD) - (SYSTICK -> VAL);
}


/* A function to Get Remaining time in Ticks */
u32 MSYSTICK_u32GetRemainingTime(void)
{
	return SYSTICK -> VAL;
}


/* SysTick Timer ISR Function */
void SysTick_Handler(void)
{
	if (SYSTICK_CallBack != NULL)
	{
		/* Read the Count Flag For Clearing */
		GET_BIT(SYSTICK -> CTRL , MSYSTICK_COUNT_FLAG);

		/* Pass User ISR To Global Pointer */
		SYSTICK_CallBack();

		if (Global_u8STKInterval == MSYSTIC_SINGLE_INTERVAL)
		{
			/* Reset Load Register */
			SYSTICK -> LOAD = MSYSTICK_RESET;

			/* Reset Value Register */
			SYSTICK -> VAL = MSYSTICK_RESET;
		}
		else if (Global_u8STKInterval == MSYSTIC_PERIODIC_INTERVAL)
		{
			/*Do Nothing */
		}

		/* Reset SisTick Interval */
		Global_u8STKInterval = 0;
	}
	else
	{
		/*Do Nothing */
	}
}



