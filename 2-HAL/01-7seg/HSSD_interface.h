/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : SSD                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef HSSD_INTERFACE_H_
#define HSSD_INTERFACE_H_

/* 7 Segment Type */
#define HSSD_COMMON_ANODE					0
#define HSSD_COMMON_CATHODE					1

/* 7 Segment Status */
#define HSSD_Enable							0
#define HSSD_Disable						1

/* define 9 Numbers in Seven Segment Display */
#define HSSD_NUMBER_ZERO				0			//NUMBER 0
#define HSSD_NUMBER_ONE					1			//NUMBER 1
#define HSSD_NUMBER_TWO 				2			//NUMBER 2
#define HSSD_NUMBER_THREE				3			//NUMBER 3
#define HSSD_NUMBER_FOUR				4			//NUMBER 4
#define HSSD_NUMBER_FIVE				5			//NUMBER 5
#define HSSD_NUMBER_SIX					6			//NUMBER 6
#define HSSD_NUMBER_SEVEN				7			//NUMBER 7
#define HSSD_NUMBER_EIGHT				8			//NUMBER 8
#define HSSD_NUMBER_NINE				9          	//NUMBER 9



/* HAL SEVEN SEGMENT DISPLAY DATA TYPE */
typedef struct
{
	u8 Local_u8CommonType;		//7 Segment Type
	u8 Local_u8Port;			//7 Segment Port
	u8 Local_u8EnablePort;		//7 Segment (Enable Pin) Port
	u8 Local_u8EnablePin;       //7 Segment Enable Pin
}HSSD_t;





/* DISPLAY NUMBER ON HSSD */
u8 HSSD_u8SetNumber(u8 Copy_u8Number , HSSD_t *Copy_pu8HSSD);


/* ENABLE OR DISABLE HSSD */
u8 HSSD_u8EnableDisableHSSD(u8 Copy_u8SsdStatus , HSSD_t *Copy_pu8HSSD);





#endif











