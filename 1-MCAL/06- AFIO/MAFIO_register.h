/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : AFIO                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MAFIO_REGISTER_H_
#define MAFIO_REGISTER_H_


typedef struct
{
	volatile u32 EVCR;				//Event Control Register
	volatile u32 MAPR;              //AF remap and debug I/O configuration register
	volatile u32 EXTICRx[4];        //EXTI Configuration register (1 -> 4)
	volatile u32 MAPR2;             //AF remap and debug I/O configuration register2

}AFIO_t;


#define AFIO 				((volatile AFIO_t*)0x40010000)



#endif
