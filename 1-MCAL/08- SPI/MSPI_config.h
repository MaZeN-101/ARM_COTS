/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SPI                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MSPI_CONFIG_H_
#define MSPI_CONFIG_H_

/********************************************************************************************/
/*                              SELECT PIN NUMBER :     			                    	*/
/*                     		0-MGPIO_u8PIN(0 || 1 || .... || 15)				         		*/
/*                     		1-MGPIO_u8PIN(0 || 1 || .... || 15)						    	*/
/*                     		2-MGPIO_u8PIN(13 || 14 || 15)				               		*/
/*																							*/
/*                              SELECT PORT NUMBER :     			                    	*/
/*                     		0-MGPIO_u8PORT(A || B || C)						         		*/
/********************************************************************************************/

/* define Slave port and pin */
#define MSPI_SLAVE_PIN				MGPIO_u8PIN0
#define MSPI_SLAVE_PORT				MGPIO_u8PORTA


/********************************************************************************************/
/*                              SELECT Master or Slave mode :     			                */
/*                     				0-MSPI_MASTER  			         						*/
/*                     				1-MSPI_Slave  					    					*/
/********************************************************************************************/

/* define Master or Slave node */
#define MSPI1_MASTER_SLAVE   		MSPI_MASTER


#if MSPI1_MASTER_SLAVE == MSPI_MASTER

/********************************************************************************************/
/*                              SELECT Master Clock prescaler :     			            */
/*                     				0-MSPI_FPCLK_DIV_BY_2  			         				*/
/*                     				1-MSPI_FPCLK_DIV_BY_4  					    			*/
/*                     				2-MSPI_FPCLK_DIV_BY_8  		               				*/
/*									3-MSPI_FPCLK_DIV_BY_16 									*/
/*                     				4-MSPI_FPCLK_DIV_BY_32 			         				*/
/*                     				5-MSPI_FPCLK_DIV_BY_64 					    			*/
/*                     				6-MSPI_FPCLK_DIV_BY_128		               				*/
/*									7-MSPI_FPCLK_DIV_BY_256									*/
/********************************************************************************************/

/* define Master Clock (only on master Mode) */
#define MSPI1_PRESCALLER     		MSPI_FPCLK_DIVIDED_BY_4

/********************************************************************************************/
/*                              SELECT SS Pin In Master Mode :     				            */
/*                     				0-MSPI_HW_MANAGE			         					*/
/*                     				1-MSPI_SW_MANAGE  					    				*/
/********************************************************************************************/

/* define SS Management (only on master Mode) */
#define MSPI1_SS_MANAGE      		MSPI_HW_MANAGE

#endif

/********************************************************************************************/
/*                              SELECT Data Order mode :     				                */
/*                     				0-MSPI_MSB_FIRST  			         					*/
/*                     				1-MSPI_LSB_FIRST  					    				*/
/********************************************************************************************/

/* define LSB or MSB Data Order */
#define MSPI1_DATA_ORDER     		MSPI_MSB_FIRST


/********************************************************************************************/
/*                              SELECT Data Sent Size :     				                */
/*                     				0-MSPI_8BIT_DATA  			         					*/
/*                     				1-MSPI_16BIT_DATA  					    				*/
/********************************************************************************************/

/* define Size of the Data Sent */
#define MSPI1_DATA_SIZE      		MSPI_8BIT_DATA


/********************************************************************************************/
/*                              SELECT Master or Slave Clock Mode :     			        */
/*                     				0-MSPI_LOW_IDLE_RD_WRT 			         				*/
/*                     				1-MSPI_LOW_IDLE_WRT_RD  					    		*/
/*                     				2-MSPI_HIGH_IDLE_RD_WRT  		               		 	*/
/*									3-MSPI_HIGH_IDLE_WRT_RD 							 	*/
/********************************************************************************************/

/* define Master or Slave Clock Mode */
#define MSPI1_CLOCK_MODE     		MSPI_HIGH_IDLE_WRT_RD


/********************************************************************************************/
/*                              SELECT Master or Slave Interrupt Mode :     			    */
/*                     				0-MSPI_INT_DISABLE	 			         				*/
/*                     				1-MSPI_TXE_INT_ENABLE  					    			*/
/*                     				2-MSPI_RXNE_INT_ENABLE  		               		 	*/
/********************************************************************************************/

/* define Interrupt Event */
#define MSPI1_INT_STATUS     		MSPI_INT_DISABLE

#endif


