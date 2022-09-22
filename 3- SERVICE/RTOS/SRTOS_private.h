/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : SERVICE              ************************/
/********************      		SWC     : RTOS                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef SRTOS_PRIVATE_H_
#define SRTOS_PRIVATE_H_

typedef struct{

	u8 	 TaskID						;
	u8   State                     	;
	u8 	 Priority					;
	u16  Periodicity               	;
	u16  FirstDelay                	;
	void (*TaskHandler)(void)  		;

}TASK_TCB ;


/* define Task State */
#define SRTOS_TASK_READY      	 	0
#define SRTOS_TASK_SUSPEND     		1


/* RTOS Scheduler Algorithm */
static void SRTOS_voidScheduler(void);


/* RTOS Sorting Tasks Algorithm */
static void SRTOS_voidSortTasks(void);

#endif





