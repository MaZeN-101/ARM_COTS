/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : LEDMAX               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"

#include "HLEDMAX_private.h"
#include "HLEDMAX_config.h"
#include "HLEDMAX_interface.h"


/* LED MATRIX PORT CONFIG */
u8 HLEDMAX_COLS_PORT_PIN[16] = {HLEDMAX_COL0_PIN,HLEDMAX_COL1_PIN,HLEDMAX_COL2_PIN,HLEDMAX_COL3_PIN,
								HLEDMAX_COL4_PIN,HLEDMAX_COL5_PIN,HLEDMAX_COL6_PIN,HLEDMAX_COL7_PIN};
					  
					  
u8 HLEDMAX_ROWS_PORT_PIN[16] = {HLEDMAX_ROW0_PIN,HLEDMAX_ROW1_PIN,HLEDMAX_ROW2_PIN,HLEDMAX_ROW3_PIN,
								HLEDMAX_ROW4_PIN,HLEDMAX_ROW5_PIN,HLEDMAX_ROW6_PIN,HLEDMAX_ROW7_PIN};					  
								

/* A function to Display a Static Data on LED Matrix */
void HLEDMAX_u8Display(u8 *Copy_u8Data)
{
	while (1)
	{
		for (int i=0 ; i<8 ; i++)
		{
			/* Set Rows Value */
			HLEDMAX_u8SetRowValues(Copy_u8Data[i]);

			/* Enable Column i */
			MGPIO_u8SetPinValue(HLEDMAX_COLS_PORT_PIN[2*i] , HLEDMAX_COLS_PORT_PIN[(2*i)+1] , MGPIO_u8PIN_LOW);

			/* Delay 2.5 ms */
			MSYSTICK_voidSetBusyWait(2500);

			/* Disable Column i */
			MGPIO_u8SetPinValue(HLEDMAX_COLS_PORT_PIN[2*i] , HLEDMAX_COLS_PORT_PIN[(2*i)+1] , MGPIO_u8PIN_HIGH);
		}
	}
}



/* A function to Move String in LED Matrix */
void HLEDMAX_u8MoveString(u8 *Copy_u8Data , u8 Copy_u8DataSize , u8 Copy_u8SpeedMotion , u8 Copy_u8IterNum)
{
	u8 Local_u8DataSelect = 0 , Local_u8NumColsLimit = 1;

	/* determine Number of elements in the array */
	u8 Local_u8DataSize = Copy_u8DataSize * 8;

	for(u8 x = 0 ; x <= Local_u8DataSize * Copy_u8IterNum ; x++)
	{
		for (u8 Local_u8Delay = 0 ; Local_u8Delay < Copy_u8SpeedMotion ; Local_u8Delay++)
		{
			for (u8 Local_u8ColSelect = 0 ; Local_u8ColSelect < Local_u8NumColsLimit ; Local_u8ColSelect++)
			{
				/* Set Rows Value */
				HLEDMAX_u8SetRowValues(Copy_u8Data[(Local_u8DataSelect - Local_u8ColSelect) % Local_u8DataSize]);

				/* Enable Column i */
				MGPIO_u8SetPinValue(HLEDMAX_COLS_PORT_PIN[2*(7-Local_u8ColSelect)] , HLEDMAX_COLS_PORT_PIN[2*(7-Local_u8ColSelect)+1] , MGPIO_u8PIN_LOW);

				/* Delay 2.5 ms */
				MSYSTICK_voidSetBusyWait(2500);

				/* Disable Column i */
				MGPIO_u8SetPinValue(HLEDMAX_COLS_PORT_PIN[2*(7-Local_u8ColSelect)] , HLEDMAX_COLS_PORT_PIN[2*(7-Local_u8ColSelect)+1] , MGPIO_u8PIN_HIGH);
			}
		}
		/* access next data element */
		Local_u8DataSelect += 1;
		if (Local_u8NumColsLimit != 8) Local_u8NumColsLimit += 1;
	}
}


/* A function to Set Row Values */
static void HLEDMAX_u8SetRowValues(u8 Copy_u8RowValue)
{
	for (int i=0 ; i<8 ; i++)
	{
		MGPIO_u8SetPinValue(HLEDMAX_ROWS_PORT_PIN[2*i] , HLEDMAX_ROWS_PORT_PIN[2*i+1] , GET_BIT(Copy_u8RowValue,i));
	}
}

