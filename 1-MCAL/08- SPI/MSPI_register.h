/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SPI              	   ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MSPI_REGISTER_H_
#define MSPI_REGISTER_H_

typedef struct
{
	volatile u32 CR1	;				//SPI Control Register 1
	volatile u32 CR2	;              	//SPI Control Register 2
	volatile u32 SR		;             	//SPI Status Register
	volatile u32 DR		;				//SPI Data Register
	volatile u32 CRCPR	;				//SPI CRC Polynomial Register
	volatile u32 RXCRCR	;				//SPI RX CRC Register
	volatile u32 TXCRCR	;				//SPI TX CRC Register
	volatile u32 I2SCFGR;				//SPI I2S Configuration Register
	volatile u32 I2SPR	;				//SPI I2S Prescaler Register
	
}SPI_t;


#define SPI1					((volatile	SPI_t*)0X40013000)

#define SPI2					((volatile	SPI_t*)0X40003800)

#endif
