/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : SSD                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/





#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "HSSD_interface.h"
#include "HSSD_private.h"
#include "HSSD_config.h"



/* Seven Segment Array Numbers */
u8 sevenSegArr[10] = {HSSD_NUMBER_0,HSSD_NUMBER_1,HSSD_NUMBER_2,HSSD_NUMBER_3,HSSD_NUMBER_4,
					  HSSD_NUMBER_5,HSSD_NUMBER_6,HSSD_NUMBER_7,HSSD_NUMBER_8,HSSD_NUMBER_9};
					  
					  
					  
					  
/* DISPLAY NUMBER ON HSSD */
u8 HSSD_u8SetNumber(u8 Copy_u8Number , HSSD_t *Copy_pu8HSSD)
{
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check if the Pointer Not equal NULL */
	if (Copy_pu8HSSD != NULL)
	{
		switch(Copy_pu8HSSD->Local_u8CommonType)
		{
			/* Common Anode 7 segment */
			case HSSD_COMMON_ANODE	:	MGPIO_u8SetPortValue(Copy_pu8HSSD->Local_u8Port , ~sevenSegArr[Copy_u8Number]);break;
			/* Common Cathode 7 segment */
			case HSSD_COMMON_CATHODE:	MGPIO_u8SetPortValue(Copy_pu8HSSD->Local_u8Port , sevenSegArr[Copy_u8Number]);break;
			default					: 	Local_u8ErrorState = NOK;	break;
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





/* ENABLE OR DISABLE HSSD */
u8 HSSD_u8EnableDisableHSSD(u8 Copy_u8SsdStatus , HSSD_t *Copy_pu8HSSD)
{
	
	/* Error state OK */
	u8 Local_u8ErrorState = OK;
	
	/* Check if the Pointer Not equal NULL */
	if (Copy_pu8HSSD != NULL)
	{
		switch(Copy_u8SsdStatus)
		{
			/* Check if the 7 segment is Enabled */
			case HSSD_Enable	:
				switch(Copy_pu8HSSD->Local_u8CommonType)
				{
					/* Common Anode 7 segment */
					case HSSD_COMMON_ANODE	:	MGPIO_u8SetPinValue(Copy_pu8HSSD->Local_u8EnablePort , Copy_pu8HSSD->Local_u8EnablePin , MGPIO_u8PIN_HIGH);break;
					/* Common Cathode 7 segment */
					case HSSD_COMMON_CATHODE:	MGPIO_u8SetPinValue(Copy_pu8HSSD->Local_u8EnablePort , Copy_pu8HSSD->Local_u8EnablePin , MGPIO_u8PIN_LOW);break;
					default					:	Local_u8ErrorState = NOK;	break;
				}
			break;

			/* Check if the 7 segment is Disabled */
			case HSSD_Disable	:
				switch(Copy_pu8HSSD->Local_u8CommonType)
				{
					/* Common Anode 7 segment */
					case HSSD_COMMON_ANODE	:	MGPIO_u8SetPinValue(Copy_pu8HSSD->Local_u8EnablePort , Copy_pu8HSSD->Local_u8EnablePin , MGPIO_u8PIN_LOW);break;
					/* Common Cathode 7 segment */
					case HSSD_COMMON_CATHODE:	MGPIO_u8SetPinValue(Copy_pu8HSSD->Local_u8EnablePort , Copy_pu8HSSD->Local_u8EnablePin , MGPIO_u8PIN_HIGH);break;
					default					:	Local_u8ErrorState = NOK;	break;
				}
			break;
				
			default			 	:Local_u8ErrorState = NOK;	break;
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





