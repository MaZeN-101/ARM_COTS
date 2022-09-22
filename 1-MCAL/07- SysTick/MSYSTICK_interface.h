/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : SYSTICK              ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MSYSTICK_INTERFACE_H_
#define MSYSTICK_INTERFACE_H_



/* Description : A function to Initialize SysTick Peripheral
 * Input  :	void
 * 
 * Output : void
 * */
void MSYSTICK_voidInit(void);


/* Description : A function to Set time in Ticks (Polling) (Synchronous)
 * Input :
 * Copy_u32Ticks			, options : pass number of Ticks
 *
 * Output : Return Error Status
 * */
void MSYSTICK_voidSetBusyWait(u32 Copy_u32Ticks);


/* Description : A function to Set time in Ticks in a single Interval (Asynchronous)
 * Input :
 * Copy_u32Ticks			, options : pass number of Ticks
 * Copy_Ptr2Fun				, options : pass ISR
 *
 * Output : Return Error Status
 * */
u8 MSYSTICK_u8SetIntervalSingle(u32 Copy_u32Ticks , void(*Copy_Ptr2Fun)(void));


/* Description : A function to Set time in Ticks in a periodic Interval (Asynchronous)
 * Input :
 * Copy_u32Ticks			, options : pass number of Ticks
 * Copy_Ptr2Fun				, options : pass ISR
 * 
 * Output : Return Error Status
 * */
u8 MSYSTICK_u8SetIntervalPeriodic(u32 Copy_u32Ticks , void(*Copy_Ptr2Fun)(void));


/* Description : A function to Stop Timer if Interval was Single or Periodic
 * Input : void
 *
 * Output : void
 * */
void MSYSTICK_voidStopTimer(void);


/* Description : A function to Get Elapsed time in Ticks
 * Input : void
 *
 * Output : Return Elapsed Time
 * */
u32 MSYSTICK_u32GetElapsedTime(void);


/* Description : A function to Get Remaining time in Ticks
 * Input : void
 *
 * Output : Return Remaining Time
 * */
u32 MSYSTICK_u32GetRemainingTime(void);



#endif













