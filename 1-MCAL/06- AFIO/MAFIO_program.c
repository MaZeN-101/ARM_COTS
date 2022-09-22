/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : AFIO                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MAFIO_config.h"
#include "MAFIO_private.h"
#include "MAFIO_register.h"
#include "MAFIO_interface.h"




/* Set EXTI Configuration */
u8 MAFIO_u8SetEXTIConfig(u8 Copy_u8EXTILine , u8 Copy_u8PortMap)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;

	/* Initialize Register Index */
	u8 Local_u8RegIndex = 0;

	/* Check the Port Map is less than or equal 2 */
	if (Copy_u8PortMap <= MAFIO_PORTC)
	{
		/* Check if EXTI Line (0 -> 3) */
		if( Copy_u8EXTILine <= 3 ){
			
			Local_u8RegIndex = 0 ;		//EXTICR1
		}
		/* Check if EXTI Line (4 -> 7) */
		else if( Copy_u8EXTILine <= 7 ){
			
			Local_u8RegIndex = 1 ;		//EXTICR2
			Copy_u8EXTILine -= 4 ;		//Adjust EXTI Line Number (Starting from 0)
		}
		/* Check if EXTI Line (8 -> 11) */
		else if( Copy_u8EXTILine <= 11 ){
			
			Local_u8RegIndex = 2 ;		//EXTICR3
			Copy_u8EXTILine -= 8 ;		//Adjust EXTI Line Number (Starting from 0)
		}
		/* Check if EXTI Line (12 -> 15) */
		else if( Copy_u8EXTILine <= 15 ){
			
			Local_u8RegIndex = 3 ;		//EXTICR4
			Copy_u8EXTILine -= 12 ;		//Adjust EXTI Line Number (Starting from 0)
		}
		
		/* Clear EXTI Line (Initialized to zeros) */
		AFIO->EXTICRx[Local_u8RegIndex] &= 	~((MAFIO_EXTICRx_MASK)  << (Copy_u8EXTILine * 4));
		
		/* Set Port number in the Right EXTI Line */
		AFIO->EXTICRx[Local_u8RegIndex] |= 	  (Copy_u8PortMap) 		<< (Copy_u8EXTILine * 4);
	}
	else
	{
		/* Error State NOT OK */
		Local_u8ErrorState = NOK;
	}
	
	/* Return Error State */
	return Local_u8ErrorState;
}











