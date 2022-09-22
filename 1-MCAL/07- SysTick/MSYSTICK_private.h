/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SYSTICK              ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#ifndef MSYSTICK_PRIVATE_H_
#define MSYSTICK_PRIVATE_H_


/* define SysTick Clock Source */
#define MSYSTICK_AHB					1
#define MSYSTICK_AHB_DIV_BY_8			2	


/* define SysTick Clock Source */
#define MSYSTICK_ENABLE					0
#define MSYSTICK_INTERRUPT				1
#define MSYSTICK_CLK_SRC				2
#define MSYSTICK_COUNT_FLAG				16

/* define Reset Value */
#define MSYSTICK_RESET					0x00000000

/* define SysTick Interval */
#define MSYSTIC_SINGLE_INTERVAL			1
#define MSYSTIC_PERIODIC_INTERVAL		2


#endif
















