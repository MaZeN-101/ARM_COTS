/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : IRCOM                ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef HIRCOM_INTERFACE_H_
#define HIRCOM_INTERFACE_H_


/***************************************************************************************/

 /*
	 ________ IR REMOTE CTRL ________                         
	|                              	 |
	| ON/OFF		MODE		MUTE |
	|  	                             |
	| PLY/PAUSE		FWD			BWD  |
	|                                |
	| 	EQ        	VOL-      	VOL+ |
	|                                |
	| 	0       	RPT      	U/SD |
	|                                |
	| 	1       	 2      	 3	 |
	|                                |
	| 	4      		 5	      	 6	 |
	|                                |
	| 	7       	 8	      	 9	 |
	|________________________________|


*/
/***************************************************************************************/


/* define IR Remote Control Buttons */
#define HIRCOM_POWER_BUTTON             		0
#define HIRCOM_MODE_BUTTON              		1
#define HIRCOM_MUTE_BUTTON              		2
#define HIRCOM_PLAY_PAUSE_BUTTON                3
#define HIRCOM_BWD_BUTTON             			4
#define HIRCOM_FWD_BUTTON		             	5
#define HIRCOM_EQ_BUTTON                		6
#define HIRCOM_VOL_DOWN_BUTTON          		7
#define HIRCOM_VOL_UP_BUTTON            		8
#define HIRCOM_0_BUTTON              			9
#define HIRCOM_RPT_BUTTON               		10
#define HIRCOM_U_SD_BUTTON               		11
#define HIRCOM_1_BUTTON               			12
#define HIRCOM_2_BUTTON               			13
#define HIRCOM_3_BUTTON             			14
#define HIRCOM_4_BUTTON              			15
#define HIRCOM_5_BUTTON              			16
#define HIRCOM_6_BUTTON               			17
#define HIRCOM_7_BUTTON             			18
#define HIRCOM_8_BUTTON             			19
#define HIRCOM_9_BUTTON              			20



/* Description : A function to Initialize IR Pin
 * Input : Void
 * 
 * Output : Void
 * */
void HIRCOM_voidInit(void);


/* Description : A function to Set Button Function
 * Input :
 * Copy_u8PressedButton			, options : Choose one of the IR Remote Control Buttons
 * Copy_Pv2func			  		, options : Pass the function which want to be performed when a button is pressed
 * 
 * Output : Return Error Status
 * */
u8 HIRCOM_u8SetButtonFunction(u8 Copy_u8PressedButton , void(*Copy_Pv2func)(void));

#endif











