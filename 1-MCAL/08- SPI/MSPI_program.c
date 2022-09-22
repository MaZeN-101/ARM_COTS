/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SPI                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSPI_config.h"
#include "MSPI_private.h"
#include "MSPI_register.h"
#include "MSPI_interface.h"


/* Global pointer to function to hold SPI ISR address */
void(*SPI_CallBack)(u16) = NULL;


/* A function to Initialize SPI Peripheral */
void MSPI1_voidInit(void)
{
	/* Set Clock Mode */
	#if		MSPI1_CLOCK_MODE == MSPI_LOW_IDLE_RD_WRT

		CLR_BIT(SPI1 -> CR1 , 0);	CLR_BIT(SPI1 -> CR1 , 1);

	#elif	MSPI1_CLOCK_MODE == MSPI_LOW_IDLE_WRT_RD

		SET_BIT(SPI1 -> CR1 , 0); 	CLR_BIT(SPI1 -> CR1 , 1);

	#elif	MSPI1_CLOCK_MODE == MSPI_HIGH_IDLE_RD_WRT

		CLR_BIT(SPI1 -> CR1 , 0); 	SET_BIT(SPI1 -> CR1 , 1);

	#elif	MSPI1_CLOCK_MODE == MSPI_HIGH_IDLE_WRT_RD

		SET_BIT(SPI1 -> CR1 , 0); 	SET_BIT(SPI1 -> CR1 , 1);

	#endif

	/* Set Master or Slave Mode */
	#if    MSPI1_MASTER_SLAVE == MSPI_MASTER

		SET_BIT(SPI1 -> CR1 , 2);

	#elif  MSPI1_MASTER_SLAVE == MSPI_SLAVE

		CLR_BIT(SPI1 -> CR1 , 2);

	#endif
	
	/* Set Data Order Mode */
	#if   MSPI1_DATA_ORDER == MSPI_MSB_FIRST

		CLR_BIT(SPI1 -> CR1 , 7);

	#elif MSPI1_DATA_ORDER == MSPI_LSB_FIRST

		SET_BIT(SPI1 -> CR1 , 7);

	#endif

	/* Set SS Master Management Config */
	#if   MSPI1_SS_MANAGE == MSPI_HW_MANAGE

		CLR_BIT(SPI1 -> CR1 , 9);

	#elif MSPI1_SS_MANAGE == MSPI_SW_MANAGE

		SET_BIT(SPI1 -> CR1 , 9);

	#endif

	/* Set Size of the Data Sent */
	#if   MSPI1_DATA_SIZE == MSPI_8BIT_DATA

		CLR_BIT(SPI1 -> CR1 , 11);

	#elif MSPI1_DATA_SIZE == MSPI_16BIT_DATA

		SET_BIT(SPI1 -> CR1 , 11);

	#endif

	/* Set Interrupt Event */
	#if   MSPI1_INT_STATUS == MSPI_INT_DISABLE

		SPI1 -> CR2 = 0;

	#elif MSPI1_INT_STATUS == MSPI_TXE_INT_ENABLE

		SET_BIT(SPI1 -> CR2 , 7);

	#elif MSPI1_INT_STATUS == MSPI_RXNE_INT_ENABLE

		SET_BIT(SPI1 -> CR2 , 6);

	#endif

	/* Set Mask Prescaler */
	SPI1 -> CR1 &= MSPI_PRESCALER_MASK;
	
	/* Set Prescaler */
	SPI1 -> CR1 |= (MSPI1_PRESCALLER << 3);

	/* Enable SPI Peripheral */
	SET_BIT( SPI1 -> CR1 , 6 );
}



/* A function to Send data across SPI Peripheral (Polling) (Synchronous) */
void MSPI1_voidSendDataSynch(u16 Copy_u16Data , u16 *Copy_u16ReceivedData)
{
	/* Disable Slave Pin to Set data */
	MGPIO_u8SetPinValue(MSPI_SLAVE_PORT , MSPI_SLAVE_PIN , MGPIO_u8PIN_HIGH);
	
	/* Set data in data Register */
	SPI1 -> DR = Copy_u16Data;

	/* Polling (BUSY WAITING) until SPI Sending is Finished */
	while(GET_BIT(SPI -> SR , MSPI_BSY_FLAG));
	
	/* Receive data from the slave */
	*Copy_u16ReceivedData = SPI1 -> DR;
	
	/* Enable Slave Pin to Send data */
	MGPIO_u8SetPinValue(MSPI_SLAVE_PORT , MSPI_SLAVE_PIN , MGPIO_u8PIN_LOW);
}



/* A function to Send data across SPI Peripheral (Asynchronous) */
void MSPI1_voidSendDataAsynch(u32 Copy_u16Data , void(*Copy_Ptr2Fun)(u16))
{		
	/* Disable Slave Pin to Set data */
	MGPIO_u8SetPinValue(MSPI_SLAVE_PORT , MSPI_SLAVE_PIN , MGPIO_u8PIN_HIGH);
	
	/* Set data in data Register */
	SPI1 -> DR = Copy_u16Data;
	
	/* Enable Slave Pin to Send data */
	MGPIO_u8SetPinValue(MSPI_SLAVE_PORT , MSPI_SLAVE_PIN , MGPIO_u8PIN_LOW);
	
	
	SPI_CallBack = Copy_Ptr2Fun;
}


/* SPI Timer ISR Function */
void SPI_IQRHandler(void)
{
	if (SPI_CallBack != NULL)
	{
		/* Pass User ISR To Global Pointer */
		SPI_CallBack(SPI1 -> DR);
	}
	else
	{
		/*Do Nothing */
	}
}



