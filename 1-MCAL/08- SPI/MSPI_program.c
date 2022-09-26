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

#include "MSPI_register.h"
#include "MSPI_private.h"
#include "MSPI_config.h"
#include "MSPI_interface.h"


/* Global pointer to function to hold SPI ISR address */
void(*SPI_CallBack[2]) (u16) = {{NULL}};


/****************************************       SPI1        **********************************************/

/* A function to Initialize SPI1 Peripheral */
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

	/* Set SSI Management Config */
	#if   MSPI1_SSI_MANAGE == MSPI_SSI_MASTER

		SET_BIT(SPI1 -> CR1 , 8);

	#elif MSPI1_SSI_MANAGE == MSPI_SSI_SLAVE

		CLR_BIT(SPI1 -> CR1 , 8);

	#endif

	/* Set SSM Management Config */
	#if   MSPI1_SSM_MANAGE == MSPI_HW_MANAGE

		CLR_BIT(SPI1 -> CR1 , 9);

	#elif MSPI1_SSM_MANAGE == MSPI_SW_MANAGE

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



/* A function to Send data across SPI1 Peripheral (Polling) (Synchronous) */
void MSPI1_voidSendDataSynch(u8 Copy_u8Data , u8 *Copy_u8ReceivedData)
{
	/* Set data in data Register */
	SPI1 -> DR = Copy_u8Data;

	/* Polling (BUSY WAITING) until SPI Sending is Finished */
	while(GET_BIT(SPI1 -> SR , MSPI_BSY_FLAG));
	
	/* Receive data from the slave */
	*Copy_u8ReceivedData = SPI1 -> DR;
}



/* A function to Send data across SPI1 Peripheral (Asynchronous) */
void MSPI1_voidSendDataAsynch(u8 Copy_u8Data , void(*Copy_Ptr2Fun)(u16))
{		
	/* Set data in data Register */
	SPI1 -> DR = Copy_u8Data;
	
	/* Pass User ISR To Global Pointer */
	SPI_CallBack[0] = Copy_Ptr2Fun;
}



/****************************************       SPI2        **********************************************/

/* A function to Initialize SPI2 Peripheral */
void MSPI2_voidInit(void)
{
	/* Set Clock Mode */
	#if		MSPI2_CLOCK_MODE == MSPI_LOW_IDLE_RD_WRT

		CLR_BIT(SPI2 -> CR1 , 0);	CLR_BIT(SPI2 -> CR1 , 1);

	#elif	MSPI2_CLOCK_MODE == MSPI_LOW_IDLE_WRT_RD

		SET_BIT(SPI2 -> CR1 , 0); 	CLR_BIT(SPI2 -> CR1 , 1);

	#elif	MSPI2_CLOCK_MODE == MSPI_HIGH_IDLE_RD_WRT

		CLR_BIT(SPI2 -> CR1 , 0); 	SET_BIT(SPI2 -> CR1 , 1);

	#elif	MSPI2_CLOCK_MODE == MSPI_HIGH_IDLE_WRT_RD

		SET_BIT(SPI2 -> CR1 , 0); 	SET_BIT(SPI2 -> CR1 , 1);

	#endif

	/* Set Master or Slave Mode */
	#if    MSPI2_MASTER_SLAVE == MSPI_MASTER

		SET_BIT(SPI2 -> CR1 , 2);

	#elif  MSPI2_MASTER_SLAVE == MSPI_SLAVE

		CLR_BIT(SPI2 -> CR1 , 2);

	#endif

	/* Set Data Order Mode */
	#if   MSPI2_DATA_ORDER == MSPI_MSB_FIRST

		CLR_BIT(SPI2 -> CR1 , 7);

	#elif MSPI2_DATA_ORDER == MSPI_LSB_FIRST

		SET_BIT(SPI2 -> CR1 , 7);

	#endif

	/* Set SSI Management Config */
	#if   MSPI2_SSI_MANAGE == MSPI_SSI_MASTER

		SET_BIT(SPI2 -> CR1 , 8);

	#elif MSPI2_SSI_MANAGE == MSPI_SSI_SLAVE

		CLR_BIT(SPI2 -> CR1 , 8);

	#endif

	/* Set SSM Management Config */
	#if   MSPI2_SSM_MANAGE == MSPI_HW_MANAGE

		CLR_BIT(SPI2 -> CR1 , 9);

	#elif MSPI2_SSM_MANAGE == MSPI_SW_MANAGE

		SET_BIT(SPI2 -> CR1 , 9);

	#endif

	/* Set Size of the Data Sent */
	#if   MSPI2_DATA_SIZE == MSPI_8BIT_DATA

		CLR_BIT(SPI2 -> CR1 , 11);

	#elif MSPI2_DATA_SIZE == MSPI_16BIT_DATA

		SET_BIT(SPI2 -> CR1 , 11);

	#endif

	/* Set Interrupt Event */
	#if   MSPI2_INT_STATUS == MSPI_INT_DISABLE

		SPI2 -> CR2 = 0;

	#elif MSPI2_INT_STATUS == MSPI_TXE_INT_ENABLE

		SET_BIT(SPI2 -> CR2 , 7);

	#elif MSPI2_INT_STATUS == MSPI_RXNE_INT_ENABLE

		SET_BIT(SPI2 -> CR2 , 6);

	#endif

	/* Set Mask Prescaler */
	SPI2 -> CR1 &= MSPI_PRESCALER_MASK;

	/* Set Prescaler */
	SPI2 -> CR1 |= (MSPI1_PRESCALLER << 3);

	/* Enable SPI Peripheral */
	SET_BIT( SPI2 -> CR1 , 6 );
}



/* A function to Send data across SPI2 Peripheral (Polling) (Synchronous) */
void MSPI2_voidSendDataSynch(u8 Copy_u8Data , u8 *Copy_u8ReceivedData)
{
	/* Set data in data Register */
	SPI2 -> DR = Copy_u8Data;

	/* Polling (BUSY WAITING) until SPI Sending is Finished */
	while(GET_BIT(SPI2 -> SR , MSPI_BSY_FLAG));

	/* Receive data from the slave */
	*Copy_u8ReceivedData = SPI2 -> DR;
}



/* A function to Send data across SPI2 Peripheral (Asynchronous) */
void MSPI2_voidSendDataAsynch(u8 Copy_u8Data , void(*Copy_Ptr2Fun)(u16))
{
	/* Set data in data Register */
	SPI2 -> DR = Copy_u8Data;

	/* Pass User ISR To Global Pointer */
	SPI_CallBack[1] = Copy_Ptr2Fun;
}


/* SPI2 ISR Function */
void SPI2_IRQHandler(void)
{
	if (SPI_CallBack[1] != NULL)
	{
		/* Execute User ISR & Pass Received data */
		SPI_CallBack[1](SPI1 -> DR);
	}
	else
	{
		/*Do Nothing*/
	}
}


/* SPI1 ISR Function */
void SPI1_IRQHandler(void)
{
	if (SPI_CallBack[0] != NULL)
	{
		/* Execute User ISR & Pass Received data */
		SPI_CallBack[0](SPI1 -> DR);
	}
	else
	{
		/*Do Nothing*/
	}
}



