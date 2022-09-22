/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : S2PCOM               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"

#include "HS2PCOM_interface.h"
#include "HS2PCOM_private.h"
#include "HS2PCOM_config.h"



void HS2PCOM_voidByteSend(u8 Copy_u8Data)
{
	/* Initialize Iterator on the data */
	u8 Local_u8Iterator = 0;

	/* Initialize variable to Hold every Data Bit */
	u8 Local_u8DataBit = 0;

	/* Disable Clock on the Shift Register */
	MGPIO_u8SetPinValue(HS2PCOM_BIT_LATCH_PORT , HS2PCOM_BIT_LATCH_PIN , MGPIO_u8PIN_LOW);

	/* Disable Clock on the Storage Register */
	MGPIO_u8SetPinValue(HS2PCOM_BYTE_LATCH_PORT , HS2PCOM_BYTE_LATCH_PIN , MGPIO_u8PIN_LOW);

	for(Local_u8Iterator = 8 ; Local_u8Iterator > 0 ; Local_u8Iterator--)
	{
		/* Hold Data Bit of the Data Send */
		Local_u8DataBit = GET_BIT(Copy_u8Data , (Local_u8Iterator - 1));

		/* Set Data Bit on the Serial Data Pin */
		MGPIO_u8SetPinValue(HS2PCOM_DATA_PORT , HS2PCOM_DATA_PIN , Local_u8DataBit);

		/* Enable Clock on the Shift Register */
		MGPIO_u8SetPinValue(HS2PCOM_BIT_LATCH_PORT , HS2PCOM_BIT_LATCH_PIN , MGPIO_u8PIN_HIGH);

		/* Delay For (1 us) */
		MSYSTICK_voidSetBusyWait(1);

		/* Disable Clock on the Shift Register */
		MGPIO_u8SetPinValue(HS2PCOM_BIT_LATCH_PORT , HS2PCOM_BIT_LATCH_PIN , MGPIO_u8PIN_LOW);
	}

	/* Enable Clock on the Storage Register */
	MGPIO_u8SetPinValue(HS2PCOM_BYTE_LATCH_PORT , HS2PCOM_BYTE_LATCH_PIN , MGPIO_u8PIN_HIGH);

	/* Delay For (1 us) */
	MSYSTICK_voidSetBusyWait(1);

	/* Disable Clock on the Storage Register */
	MGPIO_u8SetPinValue(HS2PCOM_BYTE_LATCH_PORT , HS2PCOM_BYTE_LATCH_PIN , MGPIO_u8PIN_LOW);
}




void HS2PCOM_void2ByteSend(u16 Copy_u16Data)
{
	/* Initialize Iterator on the data */
	u8 Local_u8Iterator = 0;

	/* Initialize variable to Hold every Data Bit */
	u8 Local_u8DataBit = 0;

	/* Disable Clock on the Shift Register */
	MGPIO_u8SetPinValue(HS2PCOM_BIT_LATCH_PORT , HS2PCOM_BIT_LATCH_PIN , MGPIO_u8PIN_LOW);

	/* Disable Clock on the Storage Register */
	MGPIO_u8SetPinValue(HS2PCOM_BYTE_LATCH_PORT , HS2PCOM_BYTE_LATCH_PIN , MGPIO_u8PIN_LOW);

	for(Local_u8Iterator = 16 ; Local_u8Iterator > 0 ; Local_u8Iterator--)
	{
		/* Hold Data Bit of the Data Send */
		Local_u8DataBit = GET_BIT(Copy_u16Data , (Local_u8Iterator - 1));

		/* Set Data Bit on the Serial Data Pin */
		MGPIO_u8SetPinValue(HS2PCOM_DATA_PORT , HS2PCOM_DATA_PIN , Local_u8DataBit);

		/* Enable Clock on the Shift Register */
		MGPIO_u8SetPinValue(HS2PCOM_BIT_LATCH_PORT , HS2PCOM_BIT_LATCH_PIN , MGPIO_u8PIN_HIGH);

		/* Delay For (1 us) */
		MSYSTICK_voidSetBusyWait(1);

		/* Disable Clock on the Shift Register */
		MGPIO_u8SetPinValue(HS2PCOM_BIT_LATCH_PORT , HS2PCOM_BIT_LATCH_PIN , MGPIO_u8PIN_LOW);
	}

	/* Enable Clock on the Storage Register */
	MGPIO_u8SetPinValue(HS2PCOM_BYTE_LATCH_PORT , HS2PCOM_BYTE_LATCH_PIN , MGPIO_u8PIN_HIGH);

	/* Delay For (1 us) */
	MSYSTICK_voidSetBusyWait(1);

	/* Disable Clock on the Storage Register */
	MGPIO_u8SetPinValue(HS2PCOM_BYTE_LATCH_PORT , HS2PCOM_BYTE_LATCH_PIN , MGPIO_u8PIN_LOW);
}
