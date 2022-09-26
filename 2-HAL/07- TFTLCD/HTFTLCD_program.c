/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : TFTLCD               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "MSPI_interface.h"

#include "HTFTLCD_private.h"
#include "HTFTLCD_interface.h"
#include "HTFTLCD_config.h"


/* A function to TFT LCD (Initialization Sequence) */
void HTFTLCD_voidInit(void)
{
	/* Reset Pulse Sequence */
	
	/* Reset PIN HIGH For 100 us */
	MGPIO_u8SetPinValue(HTFTLCD_RESET_PORT , HTFTLCD_RESET_PIN , MGPIO_u8PIN_HIGH);
	MSYSTICK_voidSetBusyWait(100);
	
	/* Reset PIN LOW For 1 us */
	MGPIO_u8SetPinValue(HTFTLCD_RESET_PORT , HTFTLCD_RESET_PIN , MGPIO_u8PIN_LOW);
	MSYSTICK_voidSetBusyWait(1);
	
	/* Reset PIN HIGH For 100 us */
	MGPIO_u8SetPinValue(HTFTLCD_RESET_PORT , HTFTLCD_RESET_PIN , MGPIO_u8PIN_HIGH);
	MSYSTICK_voidSetBusyWait(100);
	
	/* Reset PIN LOW For 100 us */
	MGPIO_u8SetPinValue(HTFTLCD_RESET_PORT , HTFTLCD_RESET_PIN , MGPIO_u8PIN_LOW);
	MSYSTICK_voidSetBusyWait(100);
	
	/* Reset PIN HIGH For 120 ms */
	MGPIO_u8SetPinValue(HTFTLCD_RESET_PORT , HTFTLCD_RESET_PIN , MGPIO_u8PIN_HIGH);
	MSYSTICK_voidSetBusyWait(120000);
	
	/* SLEEP OUT Command */
	HTFTLCD_voidWriteCommand(HTFTLCD_SLPOUT);
	
	/* COLOR Mode Command */
	HTFTLCD_voidWriteCommand(HTFTLCD_COLMOD);
	
	/* Set Color Code */
	#if HTFTLCD_COLOR_CODE == HTFTLCD_RGB444
		
		HTFTLCD_voidWriteData(HTFTLCD_RGB444);
	
	#elif HTFTLCD_COLOR_CODE == HTFTLCD_RGB565
		
		HTFTLCD_voidWriteData(HTFTLCD_RGB565);
		
	#elif HTFTLCD_COLOR_CODE == HTFTLCD_RGB666
		
		HTFTLCD_voidWriteData(HTFTLCD_RGB666);
		
	#else
		#warning "ERROR COLOR CODE"
	#endif
	
	/* Display ON Mode */
	HTFTLCD_voidWriteCommand(HTFTLCD_DISPON);
}



/* A function to Display An Image on TFT LCD */
void HTFTLCD_voidDisplayImage(const u16* Copy_u16Image)
{
	/* Initialize Column Length & Row Length Variables */
	u8 Local_u8ColLength = 0;
	u8 Local_u8RowLength = 0;
	
	/* Initialize Image Counter */
	u16 Local_u16Counter = 0;
	
	/* Set Color Code */
	#if HTFTLCD_FULL_RES == HTFTLCD_RES_128_128
		
		/* Set Column & Row Length */
		Local_u8ColLength = 128;
	    Local_u8RowLength = 128;
		
	#elif HTFTLCD_FULL_RES == HTFTLCD_RES_128_160
		
		/* Set Column & Row Length */
		Local_u8ColLength = 128;
	    Local_u8RowLength = 160;
		
	#elif HTFTLCD_FULL_RES == HTFTLCD_RES_176_220
		
		/* Set Column & Row Length */
		Local_u8ColLength = 176;
	    Local_u8RowLength = 220;
		
	#elif HTFTLCD_FULL_RES == HTFTLCD_RES_240_240
		
		/* Set Column & Row Length */
		Local_u8ColLength = 240;
	    Local_u8RowLength = 240;
		
	#else
		#error "ERROR TFT LCD RESOLUTION"
	#endif
	

	/* Initialize TFT LCD to Set Column Length */
	HTFTLCD_voidWriteCommand(HTFTLCD_CASET);
	HTFTLCD_voidWriteData(0);
	HTFTLCD_voidWriteData(0);
	HTFTLCD_voidWriteData(0);
	HTFTLCD_voidWriteData(Local_u8ColLength - 1);

	/* Initialize TFT LCD to Set Row Length */
	HTFTLCD_voidWriteCommand(HTFTLCD_RASET);
	HTFTLCD_voidWriteData(0);
	HTFTLCD_voidWriteData(0);
	HTFTLCD_voidWriteData(0);
	HTFTLCD_voidWriteData(Local_u8RowLength - 1);

	/* RAM Write */
	HTFTLCD_voidWriteCommand(HTFTLCD_RAMWR);


	/* Set Column & Row Length Limits */
	#if HTFTLCD_COL_ROW_ADD_SET == HTFTLCD_FULL
		
		for(Local_u16Counter = 0 ; Local_u16Counter < HTFTLCD_FULL_RES ; Local_u16Counter++)
		{
			/* Write the High Byte */
			HTFTLCD_voidWriteData(Copy_u16Image[Local_u16Counter] >> 8);

			/* Write the Low Byte */
			HTFTLCD_voidWriteData(Copy_u16Image[Local_u16Counter] & 0X00FF);
		}
			
	#elif HTFTLCD_COL_ROW_ADD_SET == HTFTLCD_CONFIG
		
		if((HTFTLCD_COL_ADD_SET < Local_u8ColLength) && (HTFTLCD_ROW_ADD_SET < Local_u8RowLength))
		{
			for(Local_u16Counter = 0 ; Local_u16Counter < (HTFTLCD_COL_ADD_SET * HTFTLCD_ROW_ADD_SET) ; Local_u16Counter++)
			{
				/* Write the High Byte */
				HTFTLCD_voidWriteData(Copy_u16Image[Local_u16Counter] >> 8);

				/* Write the Low Byte */
				HTFTLCD_voidWriteData(Copy_u16Image[Local_u16Counter] & 0X00FF);
			}
			/* Set the rest of pixels as a black pixels */
			for( ; Local_u16Counter < HTFTLCD_FULL_RES ; Local_u16Counter++)
			{
				/* Write the High Byte */
				HTFTLCD_voidWriteData(0X00);

				/* Write the Low Byte */
				HTFTLCD_voidWriteData(0X00);
			}
		}
		else
		{
			/* Set all pixels as a black pixels */
			for(Local_u16Counter = 0 ; Local_u16Counter < HTFTLCD_FULL_RES ; Local_u16Counter++)
			{
				/* Write the High Byte */
				HTFTLCD_voidWriteData(0X00);

				/* Write the Low Byte */
				HTFTLCD_voidWriteData(0X00);
			}
			#warning "ERROR COLUMN OR ROW LENGTH LIMITS"
		}

	#else
		#error "ERROR COLUMN OR ROW ADDRESS SET"
	#endif
}



/* A function to Send Command to TFT LCD */
static void HTFTLCD_voidWriteCommand(u8 Copy_u8Command)
{
	/* Initialize Temporary Variable */
	u8 Local_u8dTemp = 0;
	
	/* Configure A0 PIN To Send Command (LOW) */
	MGPIO_u8SetPinValue(HTFTLCD_A0_PORT , HTFTLCD_A0_PIN , MGPIO_u8PIN_LOW);
	
	/* Send Command Over SPI*/
	#if HTFTLCD_SPI == HTFTLCD_SPI1

		MSPI1_voidSendDataSynch(Copy_u8Command , &Local_u8dTemp);

	#elif HTFTLCD_SPI == HTFTLCD_SPI2

		MSPI2_voidSendDataSynch(Copy_u8Command , &Local_u8dTemp);

	#else
		#error "ERROR SPI NUMBER"
	#endif
}


/* A function to Send Data to TFT LCD */
static void HTFTLCD_voidWriteData(u8 Copy_u8Data)
{
	/* Initialize Temporary Variable */
	u8 Local_u8dTemp = 0;
	
	/* Configure A0 PIN To Send Data (HIGH) */
	MGPIO_u8SetPinValue(HTFTLCD_A0_PORT , HTFTLCD_A0_PIN , MGPIO_u8PIN_HIGH);
	
	/* Send Data Over SPI*/
	#if HTFTLCD_SPI == HTFTLCD_SPI1

		MSPI1_voidSendDataSynch(Copy_u8Data , &Local_u8dTemp);

	#elif HTFTLCD_SPI == HTFTLCD_SPI2

		MSPI2_voidSendDataSynch(Copy_u8Data , &Local_u8dTemp);

	#else
		#error "ERROR SPI NUMBER"
	#endif
}





