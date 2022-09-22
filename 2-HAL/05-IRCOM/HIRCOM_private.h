/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : IRCOM                ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef HIRCOM_PRIVATE_H_
#define HIRCOM_PRIVATE_H_

/* define IR Remote Control Buttons Data Values */
#define HIRCOM_POWER_Data             		69
#define HIRCOM_MODE_Data              		70
#define HIRCOM_MUTE_Data             		71
#define HIRCOM_PLY_PAUSE_Data               68
#define HIRCOM_BWD_Data             		64
#define HIRCOM_FWD_Data		             	67
#define HIRCOM_EQ_Data              		7
#define HIRCOM_VOL_DOWN_Data          		21
#define HIRCOM_VOL_UP_Data           		9
#define HIRCOM_0_Data             			22
#define HIRCOM_RPT_Data             		25
#define HIRCOM_U_SD_Data               		13
#define HIRCOM_1_Data               		12
#define HIRCOM_2_Data               		24
#define HIRCOM_3_Data            			94
#define HIRCOM_4_Data              			8
#define HIRCOM_5_Data              			28
#define HIRCOM_6_Data               		90
#define HIRCOM_7_Data             			66
#define HIRCOM_8_Data             			82
#define HIRCOM_9_Data              			74


/* define Start Bit Time Limits */
#define HIRCOM_START_BIT_LOW_LIMIT				10000
#define HIRCOM_START_BIT_HIGH_LIMIT				14000


/* define Zero Bit Time Limits */
#define HIRCOM_ZERO_BIT_LOW_LIMIT				1000
#define HIRCOM_ZERO_BIT_HIGH_LIMIT				1250


/* define One Bit Time Limits */
#define HIRCOM_ONE_BIT_LOW_LIMIT				2000
#define HIRCOM_ONE_BIT_HIGH_LIMIT				2500


/* define Remote Control Address */
#define HIRCOM_REMOTE_ADDRESS					0


/* define Inversion Mask */
#define HIRCOM_INVERSION_MASK					(u8)0XFF



/* Get IR ToTal Frame */
static void HIRCOM_voidGetFrame(void);


/* Perform Pressed Button Function */
static void HIRCOM_voidTakeAction();


/* Check Start Bit */
static u8 HIRCOM_u8CheckStartBit(void);


/* Compare Address Frame With the Address of the Used Remote & Check Address Inversion */
static u8 HIRCOM_u8CheckAddress(void);


/* Check Data Frame Inversion */
static u8 HIRCOM_u8CheckData(u8 *Copy_pu8Data);

#endif





