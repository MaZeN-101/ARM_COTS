/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : TFTLCD               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef HTFTLCD_INTERFACE_H_
#define HTFTLCD_INTERFACE_H_


/* Description : A function to TFT LCD (Initialization Sequence)
 * Input :	void
 * 
 * Output : Void
 * */
void HTFTLCD_voidInit(void);


/* Description : A function to Display An Image on TFT LCD
 * Input :
 * Copy_u16Image			, options : Send Image In Array Format 
 *
 * Output : Void
 * */
void HTFTLCD_voidDisplayImage(const u16* Copy_u16Image);

#endif











