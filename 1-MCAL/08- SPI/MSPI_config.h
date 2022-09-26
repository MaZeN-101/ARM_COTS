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
/*                              SELECT Master or Slave mode :     			                */
/*                     				0-MSPI_MASTER  			         						*/
/*                     				1-MSPI_SLAVE  					    					*/
/********************************************************************************************/

/* define Master or Slave node */
#define MSPI1_MASTER_SLAVE   		MSPI_MASTER
#define MSPI2_MASTER_SLAVE   		MSPI_MASTER


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
#define MSPI1_PRESCALLER     		MSPI_FPCLK_DIV_BY_2
#define MSPI2_PRESCALLER     		MSPI_FPCLK_DIV_BY_2

#endif


/********************************************************************************************/
/*                         SELECT SSM Bit In Master & Slave Mode :     				        */
/*                     				0-MSPI_HW_MANAGE			         					*/
/*                     				1-MSPI_SW_MANAGE  					    				*/
/********************************************************************************************/

/* define SSM Management
 * Master Mode 	: MSPI_SW_MANAGE
 * Slave Mode 	: MSPI_HW_MANAGE
 **/
#define MSPI1_SSM_MANAGE      		MSPI_SW_MANAGE
#define MSPI2_SSM_MANAGE      		MSPI_SW_MANAGE


/********************************************************************************************/
/*                         SELECT SSI Bit In Master & Slave Mode :     				        */
/*                     				0-MSPI_SSI_SLAVE			         					*/
/*                     				1-MSPI_SSI_MASTER  					    				*/
/********************************************************************************************/

/* define SSI Management
 * Master Mode 	: MSPI_SSI_MASTER
 * Slave Mode 	: MSPI_SSI_SLAVE
 **/
#define MSPI1_SSI_MANAGE      		MSPI_SSI_MASTER
#define MSPI2_SSI_MANAGE      		MSPI_SSI_MASTER


/********************************************************************************************/
/*                              SELECT Data Order mode :     				                */
/*                     				0-MSPI_MSB_FIRST  			         					*/
/*                     				1-MSPI_LSB_FIRST  					    				*/
/********************************************************************************************/

/* define LSB or MSB Data Order */
#define MSPI1_DATA_ORDER     		MSPI_MSB_FIRST
#define MSPI2_DATA_ORDER     		MSPI_MSB_FIRST


/********************************************************************************************/
/*                              SELECT Data Sent Size :     				                */
/*                     				0-MSPI_8BIT_DATA  			         					*/
/*                     				1-MSPI_16BIT_DATA  					    				*/
/********************************************************************************************/

/* define Size of the Data Sent */
#define MSPI1_DATA_SIZE      		MSPI_8BIT_DATA
#define MSPI2_DATA_SIZE      		MSPI_8BIT_DATA


/********************************************************************************************/
/*                              SELECT Master or Slave Clock Mode :     			        */
/*                     				0-MSPI_LOW_IDLE_RD_WRT 			         				*/
/*                     				1-MSPI_LOW_IDLE_WRT_RD  					    		*/
/*                     				2-MSPI_HIGH_IDLE_RD_WRT  		               		 	*/
/*									3-MSPI_HIGH_IDLE_WRT_RD 							 	*/
/********************************************************************************************/

/* define Master or Slave Clock Mode */
#define MSPI1_CLOCK_MODE     		MSPI_HIGH_IDLE_WRT_RD
#define MSPI2_CLOCK_MODE     		MSPI_HIGH_IDLE_WRT_RD


/********************************************************************************************/
/*                              SELECT Master or Slave Interrupt Mode :     			    */
/*                     				0-MSPI_INT_DISABLE	 			         				*/
/*                     				1-MSPI_TXE_INT_ENABLE  					    			*/
/*                     				2-MSPI_RXNE_INT_ENABLE  		               		 	*/
/********************************************************************************************/

/* define Interrupt Event */
#define MSPI1_INT_STATUS     		MSPI_INT_DISABLE
#define MSPI2_INT_STATUS     		MSPI_INT_DISABLE

#endif


