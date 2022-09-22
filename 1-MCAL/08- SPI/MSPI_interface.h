/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SPI                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_



/* Description : A function to Initialize SPI Peripheral
 * Input  :	void
 * 
 * Output : void
 * */
void MSPI1_voidInit(void);


/* Description : A function to Send data across SPI Peripheral (Polling) (Synchronous)
 * Input :
 * Copy_u16Data				, options : pass Data want to be sent
 * Copy_u16ReceivedData		, options : pass variable to store the received data after completion 
 *
 * Output : void
 * */
void MSPI1_voidSendDataSynch(u16 Copy_u16Data , u16 *Copy_u16ReceivedData);


/* Description : A function to Send data across SPI Peripheral (Asynchronous)
 * Input :
 * Copy_u16Data				, options : pass Data want to be sent
 * Copy_Ptr2Fun				, options : pass ISR to receive the data after completion 
 *
 * Output : void
 * */
void MSPI1_voidSendDataAsynch(u32 Copy_u16Data , void(*Copy_Ptr2Fun)(u16));



#endif













