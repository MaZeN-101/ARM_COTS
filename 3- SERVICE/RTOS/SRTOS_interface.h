/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : SERVICE              ************************/
/********************      		SWC     : RTOS                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef SRTOS_INTERFACE_H_
#define SRTOS_INTERFACE_H_

/* Description : A function to Start Scheduling Tasks
 * Input : void
 * 
 * Output : void
 * */
void SRTOS_voidStartOS(void);


/* Description : A function to Create a Task with certain Specifications
 * Input :
 * Copy_u8TaskID 		: Set the Task ID
 * Copy_u8Priority 		: Set Task Priority
 * Copy_u16Periodicity  : Set Task Periodicity
 * Copy_pvTask 			: Set Task Function
 * Copy_u16FirstDelay	: Set First delay to start after it
 *
 * Output : void
 * */
void SRTOS_voidCreateTask(u8 Copy_u8TaskID , u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)(void) , u16 Copy_u16FirstDelay);


/* Description : A function to Suspend a Task
 * Input :
 * Copy_u8TaskID : pass the Task ID which want to be Suspended
 * 
 * Output : void
 * */
void SRTOS_voidSuspendTask(u8 Copy_u8TaskID);


/* Description : A function to Suspend a Task
 * Input :
 * Copy_u8TaskID : pass the Task ID which want to be Resumed
 * 
 * Output : void
 * */
void SRTOS_voidResumeTask(u8 Copy_u8TaskID);


/* Description : A function to Suspend a Task
 * Input :
 * Copy_u8TaskID : pass the Task ID which want to be Deleted
 * 
 * Output : void
 * */
void SRTOS_voidDeleteTask(u8 Copy_u8TaskID);


#endif











