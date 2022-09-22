/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SPI                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_


/* define SPI Busy Flag */
#define MSPI_BSY_FLAG					7

/* define Prescaler Mask */
#define MSPI_PRESCALER_MASK				0XFFC7


/* define Prescaler Values */
#define MSPI_FPCLK_DIV_BY_2      		0b000
#define MSPI_FPCLK_DIV_BY_4      		0b001
#define MSPI_FPCLK_DIV_BY_8      		0b010
#define MSPI_FPCLK_DIV_BY_16     		0b011
#define MSPI_FPCLK_DIV_BY_32     		0b100
#define MSPI_FPCLK_DIV_BY_64     		0b101
#define MSPI_FPCLK_DIV_BY_128    		0b110
#define MSPI_FPCLK_DIV_BY_256    		0b111


/* define Master & Slave Mode */
#define MSPI_MASTER                  	1
#define MSPI_SLAVE                   	2

	
/* define LSB or MSB Data Order */
#define MSPI_MSB_FIRST               	1
#define MSPI_LSB_FIRST 				 	2


/* define Size of the Data Sent */
#define MSPI_8BIT_DATA               	1
#define MSPI_16BIT_DATA              	2


/* define Clock Modes */
#define MSPI_LOW_IDLE_RD_WRT 			1
#define MSPI_LOW_IDLE_WRT_RD 			2
#define MSPI_HIGH_IDLE_RD_WRT			3
#define MSPI_HIGH_IDLE_WRT_RD			4
	
	
/* define SS Pin In Master Mode */	
#define MSPI_HW_SLAVE_MANAGE			1
#define MSPI_SW_SLAVE_MANAGE			2


/* define Interrupt Event */
#define MSPI_INT_DISABLE	 			1
#define MSPI_TXE_INT_ENABLE 			2
#define MSPI_RXNE_INT_ENABLE			3

#endif
















