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


/****************************************       SPI1        **********************************************/


/* Description : A function to Initialize SPI1 Peripheral
 * Input  :	void
 * 
 * Output : void
 * */
void MSPI1_voidInit(void);


/* Description : A function to Send data across SPI1 Peripheral (Polling) (Synchronous)
 * Input :
 * Copy_u16Data				, options : pass Data want to be sent
 * Copy_u16ReceivedData		, options : pass variable to store the received data after completion 
 *
 * Output : void
 * */
void MSPI1_voidSendDataSynch(u8 Copy_u8Data , u8 *Copy_u8ReceivedData);


/* Description : A function to Send data across SPI1 Peripheral (Asynchronous)
 * Input :
 * Copy_u16Data				, options : pass Data want to be sent
 * Copy_Ptr2Fun				, options : pass ISR to receive the data after completion 
 *
 * Output : void
 * */
void MSPI1_voidSendDataAsynch(u8 Copy_u8Data , void(*Copy_Ptr2Fun)(u16));



/****************************************       SPI2        **********************************************/


/* Description : A function to Initialize SPI2 Peripheral
 * Input  :	void
 *
 * Output : void
 * */
void MSPI2_voidInit(void);


/* Description : A function to Send data across SPI2 Peripheral (Polling) (Synchronous)
 * Input :
 * Copy_u16Data				, options : pass Data want to be sent
 * Copy_u16ReceivedData		, options : pass variable to store the received data after completion
 *
 * Output : void
 * */
void MSPI2_voidSendDataSynch(u8 Copy_u8Data , u8 *Copy_u8ReceivedData);


/* Description : A function to Send data across SPI2 Peripheral (Asynchronous)
 * Input :
 * Copy_u16Data				, options : pass Data want to be sent
 * Copy_Ptr2Fun				, options : pass ISR to receive the data after completion
 *
 * Output : void
 * */
void MSPI2_voidSendDataAsynch(u8 Copy_u8Data , void(*Copy_Ptr2Fun)(u16));

#endif













