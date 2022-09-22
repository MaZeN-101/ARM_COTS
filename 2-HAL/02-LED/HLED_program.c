/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : LED                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/




#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "HLED_interface.h"
#include "HLED_private.h"
#include "HLED_config.h"



//ENABLE DISABLE HLED TO BE ON//
u8 HLED_u8TurnOnOff(u8 Copy_u8ledStatus , HLED_t *Copy_pu8HLED)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	
	/* Check if the Pointer Not equal NULL */
	if (Copy_pu8HLED != NULL)
	{
		switch(Copy_u8ledStatus)
		{
			case HLED_Enable  :
				switch(Copy_pu8HLED->Local_u8ConnectionType)
				{
					case HLED_SINK_CONNECTION 	:MGPIO_u8SetPinValue(Copy_pu8HLED->Local_u8Port , Copy_pu8HLED->Local_u8Pin , MGPIO_u8PIN_LOW);break;
					case HLED_SOURCE_CONNECTION :MGPIO_u8SetPinValue(Copy_pu8HLED->Local_u8Port , Copy_pu8HLED->Local_u8Pin , MGPIO_u8PIN_HIGH);break;
					default						:Local_u8ErrorState = NOK;	break;
				}
			break;
			case HLED_Disable :
				switch(Copy_pu8HLED->Local_u8ConnectionType)
				{
					case HLED_SINK_CONNECTION 	:MGPIO_u8SetPinValue(Copy_pu8HLED->Local_u8Port , Copy_pu8HLED->Local_u8Pin , MGPIO_u8PIN_HIGH);break;
					case HLED_SOURCE_CONNECTION :MGPIO_u8SetPinValue(Copy_pu8HLED->Local_u8Port , Copy_pu8HLED->Local_u8Pin , MGPIO_u8PIN_LOW);break;
					default						:Local_u8ErrorState = NOK;	break;
				}
			break;
			default			  :Local_u8ErrorState = NOK;			
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






