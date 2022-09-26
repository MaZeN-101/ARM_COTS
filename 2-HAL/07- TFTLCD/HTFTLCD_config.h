/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : TFTLCD               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef HTFTLCD_CONFIG_H_
#define HTFTLCD_CONFIG_H_

/********************************************************************************************/
/*                           SELECT TFT LCD CONNECTION TO SPI1 OR SPI2 :     			    */
/*                     				0-HTFTLCD_SPI1					         				*/
/*                     				1-HTFTLCD_SPI2											*/
/********************************************************************************************/


/* define TFT LCD SPI */
#define HTFTLCD_SPI		   	 					HTFTLCD_SPI2


/********************************************************************************************/
/*                              SELECT PIN NUMBER :     			                    	*/
/*                     		0-MGPIO_u8PIN(0 || 1 || .... || 15)				         		*/
/*                     		1-MGPIO_u8PIN(0 || 1 || .... || 15)						    	*/
/*                     		2-MGPIO_u8PIN(13 || 14 || 15)				               		*/
/*																							*/
/*                              SELECT PORT NUMBER :     			                    	*/
/*                     		0-MGPIO_u8PORT(A || B || C)						         		*/
/********************************************************************************************/


/* define A0 port and pin (Send Command OR Data) */
#define HTFTLCD_A0_PORT		   	 				MGPIO_u8PORTA
#define HTFTLCD_A0_PIN	    	 				MGPIO_u8PIN1

/* define RESET Port and Pin */
#define HTFTLCD_RESET_PORT   					MGPIO_u8PORTA
#define HTFTLCD_RESET_PIN    					MGPIO_u8PIN0


/********************************************************************************************/
/*                              SELECT TFT Color Code :     			                   	*/
/*                     				0-HTFTLCD_RGB444				         				*/
/*                     				1-HTFTLCD_RGB565										*/
/*                     				2-HTFTLCD_RGB666							            */
/********************************************************************************************/

/* define Storage Register Clock Port and Pin */
#define HTFTLCD_COLOR_CODE			  			HTFTLCD_RGB565


/********************************************************************************************/
/*                             	 SELECT Your TFT LCD Resolution :     			            */
/*                     				0-HTFTLCD_RES_128_128				         			*/
/*                     				1-HTFTLCD_RES_128_160									*/
/*                     				2-HTFTLCD_RES_176_220							        */
/*                     				3-HTFTLCD_RES_240_240							        */
/********************************************************************************************/

/* define Resolution of TFT LCD */
#define HTFTLCD_FULL_RES						HTFTLCD_RES_128_160


/********************************************************************************************/
/*                           SELECT TFT Column & Row Address Set :     			      		*/
/*                     				0-HTFTLCD_FULL					         				*/
/*                     				1-HTFTLCD_CONFIG										*/
/********************************************************************************************/

/* define Column & Row Address Set */
#define HTFTLCD_COL_ROW_ADD_SET					HTFTLCD_FULL


/* define Column & Row Address END */
#if HTFTLCD_COL_ROW_ADD_SET == HTFTLCD_CONFIG

	#define HTFTLCD_COL_ADD_SET					100
	#define HTFTLCD_ROW_ADD_SET					50
	
#endif 

#endif






