/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SYSTICK              ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MSYSTICK_REGISTER_H_
#define MSYSTICK_REGISTER_H_

typedef struct
{
	volatile u32 CTRL;				//SysTick Control and Status Register
	volatile u32 LOAD;              //SysTick Reload Value Register
	volatile u32 VAL;             	//SysTick Current Value Register
	volatile u32 CALIB;				//SysTick Calibration Value Register
	
}SYSTICK_t;


#define SYSTICK					((volatile	SYSTICK_t*)0xE000E010)

#endif
