/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : IRCOM                ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MSYSTICK_interface.h"
#include "MNVIC_interface.h"
#include "MEXTI_interface.h"
#include "MAFIO_interface.h"

#include "HIRCOM_interface.h"
#include "HIRCOM_private.h"
#include "HIRCOM_config.h"



volatile u32 Global_u32IRFrame[33] = {0};		//Global Array to store the frame
volatile u8  Global_u8StartBitFlag = 0;			//Global Flag to differ between start bit and any other bit
volatile u8  Global_u8Counter = 0;				//Global Counter to Access Frame


/* Global pointer to function to hold INT0 ISR address */
void (*HIRCOM_CallBack[21]) (void) = {NULL};



void HIRCOM_voidInit(void)
{
	/* Enable Configuration */
	MAFIO_u8SetEXTIConfig(HIRCOM_SENSOR_PIN , HIRCOM_SENSOR_PORT);

	/* Set Call Back */
	MEXTI_u8SetCallBack(HIRCOM_voidGetFrame , HIRCOM_SENSOR_PIN);

	/* Initialize EXTI(0,.....,15) */
	MEXTI_u8Init(HIRCOM_SENSOR_PIN , MEXTI_FALLING_EDGE);

	/* Enable EXTI(0,.....,15) */
	MEXTI_u8EXTIEnableLine(HIRCOM_SENSOR_PIN);

	/* Initialize NVIC */
	MNVIC_voidInit();

	/* Enable NVIC */
	MNVIC_u8EnableDisableInterrupt(HIRCOM_SENSOR_PIN + 6 , MNVIC_ENABLE_INTERRUPT);

	/* Initialize SysTick */
	MSYSTICK_voidInit();
}


/* Set Button Function */
u8 HIRCOM_u8SetButtonFunction(u8 Copy_u8PressedButton , void(*Copy_Pv2func)(void))
{
	/* Error state OK */
	u8 Local_ErrStatus = OK;

	/* Check if the pointer is NULL or NOT */
	if (Copy_Pv2func != NULL)
	{
		HIRCOM_CallBack[Copy_u8PressedButton] = Copy_Pv2func;
	}
	else
	{
		/* Error State NOT OK */
		Local_ErrStatus = NULL_POINTER;
	}

	/* Return Error State */
	return Local_ErrStatus;
}


/* Get IR ToTal Frame */
static void HIRCOM_voidGetFrame(void)
{
	if (Global_u8StartBitFlag == 0)
	{
		MSYSTICK_u8SetIntervalSingle(500000 , HIRCOM_voidTakeAction);
		Global_u8StartBitFlag = 1;
	}
	else if (Global_u8Counter <= 32)
	{
		Global_u32IRFrame[Global_u8Counter] = MSYSTICK_u32GetElapsedTime();
		MSYSTICK_u8SetIntervalSingle(500000 , HIRCOM_voidTakeAction);
		Global_u8Counter ++;
	}
	else
	{
		/* DO NOTHING */
	}
}


/* Perform Pressed Button Function */
static void HIRCOM_voidTakeAction()
{
	/* Get Pressed Button Value */
	u8 Local_u8PressedButtonData = 0;
	
	if ((HIRCOM_u8CheckStartBit() == OK) && (HIRCOM_u8CheckAddress() == OK) && (HIRCOM_u8CheckData(&Local_u8PressedButtonData) == OK))
	{
		/* Perform Pressed Button Function */
		switch (Local_u8PressedButtonData)
		{
			case HIRCOM_POWER_Data 		:	if(HIRCOM_CallBack[0] != NULL)	HIRCOM_CallBack[0]();	break;
			case HIRCOM_MODE_Data 		:	if(HIRCOM_CallBack[1] != NULL)	HIRCOM_CallBack[1]();	break;
			case HIRCOM_MUTE_Data 		:	if(HIRCOM_CallBack[2] != NULL)	HIRCOM_CallBack[2]();	break;
			case HIRCOM_PLY_PAUSE_Data 	:	if(HIRCOM_CallBack[3] != NULL)	HIRCOM_CallBack[3]();	break;
			case HIRCOM_BWD_Data 		:	if(HIRCOM_CallBack[4] != NULL)	HIRCOM_CallBack[4]();	break;
			case HIRCOM_FWD_Data 		:	if(HIRCOM_CallBack[5] != NULL)	HIRCOM_CallBack[5]();	break;
			case HIRCOM_EQ_Data 		:	if(HIRCOM_CallBack[6] != NULL)	HIRCOM_CallBack[6]();	break;
			case HIRCOM_VOL_DOWN_Data 	:	if(HIRCOM_CallBack[7] != NULL)	HIRCOM_CallBack[7]();	break;
			case HIRCOM_VOL_UP_Data 	:	if(HIRCOM_CallBack[8] != NULL)	HIRCOM_CallBack[8]();	break;
			case HIRCOM_0_Data 			:	if(HIRCOM_CallBack[9] != NULL)	HIRCOM_CallBack[9]();	break;
			case HIRCOM_RPT_Data 		:	if(HIRCOM_CallBack[10] != NULL)	HIRCOM_CallBack[10]();	break;
			case HIRCOM_U_SD_Data 		:	if(HIRCOM_CallBack[11] != NULL)	HIRCOM_CallBack[11]();	break;
			case HIRCOM_1_Data 			:	if(HIRCOM_CallBack[12] != NULL)	HIRCOM_CallBack[12]();	break;
			case HIRCOM_2_Data 			:	if(HIRCOM_CallBack[13] != NULL)	HIRCOM_CallBack[13]();	break;
			case HIRCOM_3_Data 			:	if(HIRCOM_CallBack[14] != NULL)	HIRCOM_CallBack[14]();	break;
			case HIRCOM_4_Data 			:	if(HIRCOM_CallBack[15] != NULL)	HIRCOM_CallBack[15]();	break;
			case HIRCOM_5_Data 			:	if(HIRCOM_CallBack[16] != NULL)	HIRCOM_CallBack[16]();	break;
			case HIRCOM_6_Data 			:	if(HIRCOM_CallBack[17] != NULL)	HIRCOM_CallBack[17]();	break;
			case HIRCOM_7_Data 			:	if(HIRCOM_CallBack[18] != NULL)	HIRCOM_CallBack[18]();	break;
			case HIRCOM_8_Data 			:	if(HIRCOM_CallBack[19] != NULL)	HIRCOM_CallBack[19]();	break;
			case HIRCOM_9_Data 			:	if(HIRCOM_CallBack[20] != NULL)	HIRCOM_CallBack[20]();	break;
			default : /* DO NOTHING */					break;
		}

		/* Reset to receive new frame */
		Global_u32IRFrame[0] = 0;
		Global_u8StartBitFlag = 0;	
		Global_u8Counter = 0;		
	}
	else
	{
		/* DO NOTHING */
	}
}


/* Check Start Bit */
static u8 HIRCOM_u8CheckStartBit(void)
{
	/* Initialize Error Status to OK */
	u8 Local_u8ErrStatus = OK;
	
	/* Check Start Bit Came or Not */
	if ((Global_u32IRFrame[0] >= HIRCOM_START_BIT_LOW_LIMIT)	&&	(Global_u32IRFrame[0] <= HIRCOM_START_BIT_HIGH_LIMIT))
	{
		/* DO NOTHING */
	}
	else
	{
		/* Error Status is NOK */
		Local_u8ErrStatus = NOK;
	}
	
	/* Return Error Status */
	return Local_u8ErrStatus;
}


/* Compare Address Frame With the Address of the Used Remote & Check Address Inversion */
static u8 HIRCOM_u8CheckAddress(void)
{
	/* Initialize Error Status to OK */
	u8 Local_u8ErrStatus = OK;
	
	/* define Address of the Coming Frame From IR Remote */
	u8 Local_u8RemoteAddress = 0;
	
	/* define the Inverted Address of the Coming Frame From IR Remote */
	u8 Local_u8RemoteAddressInverted = 0;
	
	/* Check the coming Bit is 0 or 1 */
	for (u8 Iter = 1 ; Iter < 17 ; Iter ++)
	{
		if ((Global_u32IRFrame[Iter] >= HIRCOM_ZERO_BIT_LOW_LIMIT) &&	(Global_u32IRFrame[Iter] <= HIRCOM_ZERO_BIT_HIGH_LIMIT))
		{
			/* the Bit is zero */
			if (Iter <= 8)	CLR_BIT(Local_u8RemoteAddress , (Iter - 1));
			else 			CLR_BIT(Local_u8RemoteAddressInverted , (Iter - 9));
		}
		else if ((Global_u32IRFrame[Iter] >= HIRCOM_ONE_BIT_LOW_LIMIT) &&	(Global_u32IRFrame[Iter] <= HIRCOM_ONE_BIT_HIGH_LIMIT))
		{
			/* the Bit is one */
			if (Iter <= 8)	SET_BIT(Local_u8RemoteAddress , (Iter - 1));
			else			SET_BIT(Local_u8RemoteAddressInverted , (Iter - 9));
		}
		else
		{
			/* Error Status is NOK */
			Local_u8ErrStatus = NOK;
		}
	}

	/* Check the Inverted Byte Address equals to Address Byte */
	if ((Local_u8RemoteAddressInverted ^ HIRCOM_INVERSION_MASK) != Local_u8RemoteAddress)
	{
		/* Error Status is NOK */
		Local_u8ErrStatus = NOK;
	}
	
	/* Check the Coming Frame from the Required Remote */
	if (Local_u8RemoteAddress != HIRCOM_REMOTE_ADDRESS)
	{
		/* Error Status is NOK */
		Local_u8ErrStatus = NOK;
	}
	
	/* Return Error Status */
	return Local_u8ErrStatus;
}


/* Check Data Frame Inversion */
static u8 HIRCOM_u8CheckData(u8 *Copy_pu8Data)
{
	/* Initialize Error Status to OK */
	u8 Local_u8ErrStatus = OK;
	
	/* define Data of the Coming Frame From IR Remote */
	u8 Local_u8RemoteData = 0;
	
	/* define the Inverted Data of the Coming Frame From IR Remote */
	u8 Local_u8RemoteDataInverted = 0;
	
	/* Check the coming Bit is 0 or 1 */
	for (u8 Iter = 17 ; Iter < 33 ; Iter ++)
	{
		if ((Global_u32IRFrame[Iter] >= HIRCOM_ZERO_BIT_LOW_LIMIT) &&	(Global_u32IRFrame[Iter] <= HIRCOM_ZERO_BIT_HIGH_LIMIT))
		{
			/* the Bit is zero */
			if (Iter <= 24)	CLR_BIT(Local_u8RemoteData , (Iter - 17));
			else 			CLR_BIT(Local_u8RemoteDataInverted , (Iter - 25));
		}
		else if ((Global_u32IRFrame[Iter] >= HIRCOM_ONE_BIT_LOW_LIMIT) &&	(Global_u32IRFrame[Iter] <= HIRCOM_ONE_BIT_HIGH_LIMIT))
		{
			/* the Bit is one */
			if (Iter <= 24)	SET_BIT(Local_u8RemoteData , (Iter - 17));
			else			SET_BIT(Local_u8RemoteDataInverted , (Iter - 25));
		}
		else
		{
			/* Error Status is NOK */
			Local_u8ErrStatus = NOK;
		}
	}
	/* Data Byte of the pressed Button */
	*Copy_pu8Data = Local_u8RemoteData;
	
	/* Check the Inverted Byte Address equals to Address Byte */
	if ((Local_u8RemoteDataInverted ^ HIRCOM_INVERSION_MASK) != Local_u8RemoteData)
	{
		/* Error Status is NOK */
		Local_u8ErrStatus = NOK;
	}
	
	
	/* Return Error Status */
	return Local_u8ErrStatus;
}


