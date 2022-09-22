/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : S2PCOM               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef HS2PCOM_CONFIG_H_
#define HS2PCOM_CONFIG_H_


/********************************************************************************************/
/*                              SELECT PIN NUMBER :     			                    	*/
/*                     		0-MGPIO_u8PIN(0 || 1 || .... || 15)				         		*/
/*                     		1-MGPIO_u8PIN(0 || 1 || .... || 15)						    	*/
/*                     		2-MGPIO_u8PIN(13 || 14 || 15)				               		*/
/*																							*/
/*                              SELECT PORT NUMBER :     			                    	*/
/*                     		0-MGPIO_u8PORT(A || B || C)						         		*/
/********************************************************************************************/


/* define Data Serial port and pin */
#define HS2PCOM_DATA_PORT   	 				MGPIO_u8PORTA
#define HS2PCOM_DATA_PIN    	 				MGPIO_u8PIN0

/* define Shift Register Clock Port and Pin */
#define HS2PCOM_BIT_LATCH_PORT   				MGPIO_u8PORTA
#define HS2PCOM_BIT_LATCH_PIN    				MGPIO_u8PIN1

/* define Storage Register Clock Port and Pin */
#define HS2PCOM_BYTE_LATCH_PORT  				MGPIO_u8PORTA
#define HS2PCOM_BYTE_LATCH_PIN   				MGPIO_u8PIN2



#endif






