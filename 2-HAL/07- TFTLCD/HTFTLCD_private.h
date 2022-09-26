/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : TFTLCD               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef HTFTLCD_PRIVATE_H_
#define HTFTLCD_PRIVATE_H_

/* define TFT Commands */
#define HTFTLCD_SLPOUT							0X11	// SLEEP OUT
#define HTFTLCD_COLMOD							0X3A    // COLOR MODE
#define HTFTLCD_DISPON							0X29    // DISPLAY ON
#define HTFTLCD_CASET							0X2C    // COLUMN ADDRESS SET
#define HTFTLCD_RASET							0X2C    // ROW ADDRESS SET
#define HTFTLCD_RAMWR							0X2C    // RAM WRITE



/* define Color Codes that is supported for TFT LCD */
#define HTFTLCD_RGB444			  				0X03
#define HTFTLCD_RGB565   						0X05
#define HTFTLCD_RGB666   						0X06



/* define TFT LCD Resolutions */
#define HTFTLCD_RES_128_128						128*128
#define HTFTLCD_RES_128_160						128*160
#define HTFTLCD_RES_176_220						176*220
#define HTFTLCD_RES_240_240						240*240


/*define COLUMN & ROW Address Set*/
#define HTFTLCD_FULL							1
#define HTFTLCD_CONFIG							2


/* define TFT LCD SPI */
#define HTFTLCD_SPI1							1
#define HTFTLCD_SPI2							2


/* Description : A function to Send Command to TFT LCD
 * Input :
 * Copy_u8Command			, options : Send Command From (TFT LCD) Data Sheet 
 *
 * Output : Void
 * */
static void HTFTLCD_voidWriteCommand(u8 Copy_u8Command);



/* Description : A function to Send Data to TFT LCD
 * Input :
 * Copy_u8Data				, options : Send Data From (TFT LCD) Data Sheet or Send Image Data 
 *
 * Output : Void
 * */
static void HTFTLCD_voidWriteData(u8 Copy_u8Data);

#endif





