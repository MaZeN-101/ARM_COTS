/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : S2PCOM               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef HS2PCOM_INTERFACE_H_
#define HS2PCOM_INTERFACE_H_


/* Description : A function to Send A Byte of Data From Serial To Parallel
 * Input :
 * Copy_u8Data			, options : Write Data Want to be Set
 * 
 * Output : Void
 * */
void HS2PCOM_voidByteSend(u8 Copy_u8Data);


/* Description : A function to Send A 2 Bytes of Data From Serial To Parallel
 * Input :
 * Copy_u8Data			, options : Write Data Want to be Set
 *
 * Output : Void
 * */
void HS2PCOM_void2ByteSend(u16 Copy_u16Data);

#endif











