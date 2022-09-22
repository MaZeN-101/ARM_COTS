/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : EXTI                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MEXTI_REGISTER_H_
#define MEXTI_REGISTER_H_


typedef struct
{
	volatile u32 IMR;			//Interrupt Mask Register
	volatile u32 EMR;			//Event Mask Register
	volatile u32 RTSR;          //Rising Trigger Selection Register
	volatile u32 FTSR;          //Falling Trigger Selection Register
	volatile u32 SWIER;         //SoftWare Interrupt Event Register
	volatile u32 PR;            //Pending Register
	
}EXTI_t;


#define EXTI			((volatile EXTI_t*)0x40010400)



#endif
