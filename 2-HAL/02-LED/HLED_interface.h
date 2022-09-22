/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : LED                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/







#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_


/* LED CONNECTION TYPE */
#define HLED_SINK_CONNECTION						0
#define HLED_SOURCE_CONNECTION						1


/* 7 Segment Status */
#define HLED_Enable									0
#define HLED_Disable								1



/* HAL LED DATA TYPE */
typedef struct
{
	u8 Local_u8ConnectionType;			//LED CONNECTION Type
	u8 Local_u8Port;                    //LED CONNECTION Port
	u8 Local_u8Pin;                     //LED CONNECTION Pin
}HLED_t;




//ENABLE DISABLE HLED TO BE ON//
u8 HLED_u8TurnOnOff(u8 Copy_u8ledStatus , HLED_t *Copy_pu8HLED);





#endif






