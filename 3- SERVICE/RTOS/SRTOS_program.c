/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : SERVICE              ************************/
/********************      		SWC     : RTOS                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSYSTICK_interface.h"

#include "SRTOS_interface.h"
#include "SRTOS_private.h"
#include "SRTOS_config.h"


/* Set System Tasks in Array */
static TASK_TCB SYS_TASKS[SRTOS_TASK_NUMBERS] = {{NULL}};
static u8 Global_u8SysTasksCounter = 0;



/* A function to Start Scheduling Tasks */
void SRTOS_voidStartOS(void)
{
	/* Sort System Tasks */
	SRTOS_voidSortTasks();

	/* Initialize SysTick */
	MSYSTICK_voidInit();

	/* Set CallBack Function and Time Interval */
	MSYSTICK_u8SetIntervalPeriodic(SRTOS_TICK_TIME , SRTOS_voidScheduler);
}


/* A function to Create a Task with certain Specifications */
void SRTOS_voidCreateTask(u8 Copy_u8TaskID , u8 Copy_u8Priority , u16 Copy_u16Periodicity , void (*Copy_pvTask)(void) , u16 Copy_u16FirstDelay)
{
	/* Check if the Task is not Created Yet  */
	if((SYS_TASKS[Global_u8SysTasksCounter].TaskHandler == NULL) && (Global_u8SysTasksCounter < SRTOS_TASK_NUMBERS))
	{
		/* Set Task Specifications */
		SYS_TASKS[Global_u8SysTasksCounter].TaskID		= Copy_u8TaskID	      ;
		SYS_TASKS[Global_u8SysTasksCounter].Priority	= Copy_u8Priority	  ;
		SYS_TASKS[Global_u8SysTasksCounter].Periodicity = Copy_u16Periodicity ;
		SYS_TASKS[Global_u8SysTasksCounter].TaskHandler = Copy_pvTask         ;
		SYS_TASKS[Global_u8SysTasksCounter].FirstDelay  = Copy_u16FirstDelay  ;
		SYS_TASKS[Global_u8SysTasksCounter].State       = SRTOS_TASK_READY    ;

		/* Increase number of System Tasks */
		Global_u8SysTasksCounter ++;
	}
	else
	{
		/* DO NOTHING */
	}
}


/* A function to Suspend a Task */
void SRTOS_voidSuspendTask(u8 Copy_u8TaskID)
{
	/* Set Task State to be Suspended */
	SYS_TASKS[Copy_u8TaskID].State = SRTOS_TASK_SUSPEND;
}


/* A function to Resume a Task */
void SRTOS_voidResumeTask(u8 Copy_u8TaskID)
{
	/* Set Task State to be Ready */
	SYS_TASKS[Copy_u8TaskID].State = SRTOS_TASK_READY;
}


/* A function to Delete a Task */
void SRTOS_voidDeleteTask(u8 Copy_u8TaskID)
{
	/* Swap the deleted Task with the last one */
	SYS_TASKS[Copy_u8TaskID] = SYS_TASKS[Global_u8SysTasksCounter - 1];

	/* delete the last task */
	SYS_TASKS[Global_u8SysTasksCounter - 1].TaskHandler = NULL;

	/* Decrease number of System Tasks */
	Global_u8SysTasksCounter --;

	/* Sort System Tasks */
	SRTOS_voidSortTasks();
}


/* RTOS Scheduler Algorithm */
static void SRTOS_voidScheduler(void)
{
	/* define Counter to loop on the System Tasks */
	u8 Local_u8TaskCounter;

	for(Local_u8TaskCounter = 0 ; Local_u8TaskCounter < Global_u8SysTasksCounter ; Local_u8TaskCounter++)
	{
		/* Check if the Task is Ready */
		if((SYS_TASKS[Local_u8TaskCounter].TaskHandler != NULL) && (SYS_TASKS[Local_u8TaskCounter].State == SRTOS_TASK_READY))
		{
			/* Check First delay of the Task */
			if(SYS_TASKS[Local_u8TaskCounter].FirstDelay == 0)
			{
				SYS_TASKS[Local_u8TaskCounter].FirstDelay = SYS_TASKS[Local_u8TaskCounter].Periodicity - 1;

				/* Perform Task Handler */
				SYS_TASKS[Local_u8TaskCounter].TaskHandler();
			}
			else
			{
				/* Decrease First Delay to start */
				SYS_TASKS[Local_u8TaskCounter].FirstDelay--;
			}
		}
		else
		{
			/* DO NOTHING */
		}
	}
}


/* RTOS Sorting Tasks Algorithm */
static void SRTOS_voidSortTasks(void)
{
	/* Initialize Temporary Task TCB */
	TASK_TCB Local_Task_TCB_Temp;

	for(u8 Counteri = 0 ; Counteri < Global_u8SysTasksCounter - 1; Counteri++)
	{
		for(u8 Counterj = 0 ; Counterj < Global_u8SysTasksCounter - Counteri - 1 ; Counterj++)
		{
			/* Sort Tasks According to Priority of each task */
			if(SYS_TASKS[Counterj].Priority > SYS_TASKS[Counterj+1].Priority)
			{
				/* Swap 2 tasks according to Priority */
				Local_Task_TCB_Temp   = SYS_TASKS[Counterj];
				SYS_TASKS[Counterj]   = SYS_TASKS[Counterj+1];
				SYS_TASKS[Counterj+1] = Local_Task_TCB_Temp;
			}
			else if(SYS_TASKS[Counterj].Priority == SYS_TASKS[Counterj+1].Priority)
			{
				if(SYS_TASKS[Counterj].TaskID > SYS_TASKS[Counterj+1].TaskID)
				{
					/* Swap 2 tasks according to Task ID */
					Local_Task_TCB_Temp   = SYS_TASKS[Counterj];
					SYS_TASKS[Counterj]   = SYS_TASKS[Counterj+1];
					SYS_TASKS[Counterj+1] = Local_Task_TCB_Temp;
				}
			}
		}
	}
}
