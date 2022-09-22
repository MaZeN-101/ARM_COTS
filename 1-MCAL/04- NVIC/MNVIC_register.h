/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : NVIC                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MNVIC_REGISTER_H_
#define MNVIC_REGISTER_H_



/* INTERRUPT SET ENABLE REGISTER */
#define MNVIC_ISER0			*((volatile u32*)0xE000E100)
#define MNVIC_ISER1			*((volatile u32*)0xE000E104)

/* INTERRUPT CLEAR ENABLE REGISTER */
#define MNVIC_ICER0			*((volatile u32*)0xE000E180)
#define MNVIC_ICER1			*((volatile u32*)0xE000E184)

/* INTERRUPT SET PENDING REGISTER */
#define MNVIC_ISPR0			*((volatile u32*)0xE000E200)
#define MNVIC_ISPR1			*((volatile u32*)0xE000E204)

/* INTERRUPT CLEAR PENDING REGISTER */
#define MNVIC_ICPR0			*((volatile u32*)0xE000E280)
#define MNVIC_ICPR1			*((volatile u32*)0xE000E284)

/* INTERRUPT ACTIVE BIT REGISTER */
#define MNVIC_IABR0			*((volatile u32*)0xE000E300)
#define MNVIC_IABR1			*((volatile u32*)0xE000E304)

/* INTERRUPT PRIORITY REGISTER (BYTE ACCESSABLE) */
#define MNVIC_IPR			 ((volatile u8*)0xE000E400)

/* SYSTEM HANDLER PRIORITY REGISTER */
#define MSCB_SHPR1			*((volatile u32*)0xE000ED18)
#define MSCB_SHPR2			*((volatile u32*)0xE000ED1C)
#define MSCB_SHPR3			*((volatile u32*)0xE000ED20)


#endif
