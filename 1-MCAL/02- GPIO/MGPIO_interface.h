/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : GPIO                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_


/* PIN VALUE STATUS */
#define MGPIO_u8PIN_HIGH			1
#define MGPIO_u8PIN_LOW				0
	
/* PORT VALUE STATUS */
#define MGPIO_u16PORT_HIGH			0XFFFF
#define MGPIO_u16PORT_LOW			0X0000

/* PIN LOCK STATUS */
#define MGPIO_u8PIN_LOCK			1
#define MGPIO_u8PIN_UNLOCK			0

/* PORT LOCK STATUS */
#define MGPIO_u16PORT_LOCK			0XFFFF
#define MGPIO_u16PORT_UNLOCK		0X0000

/* GPIO PORTS */
#define MGPIO_u8PORTA				0
#define MGPIO_u8PORTB				1
#define MGPIO_u8PORTC				2

/* GPIO PINS */
#define MGPIO_u8PIN0			    0
#define MGPIO_u8PIN1			    1
#define MGPIO_u8PIN2			    2
#define MGPIO_u8PIN3			    3
#define MGPIO_u8PIN4			    4
#define MGPIO_u8PIN5			    5
#define MGPIO_u8PIN6			    6
#define MGPIO_u8PIN7			    7
#define MGPIO_u8PIN8			    8
#define MGPIO_u8PIN9			    9
#define MGPIO_u8PIN10				10
#define MGPIO_u8PIN11				11
#define MGPIO_u8PIN12				12
#define MGPIO_u8PIN13				13
#define MGPIO_u8PIN14				14
#define MGPIO_u8PIN15				15




//SET VALUE OF A PIN TO BE HIGH OR LOW //
u8 MGPIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);


//SET VALUE OF A PORT TO BE HIGH OR LOW //
u8 MGPIO_u8SetPortValue(u8 Copy_u8Port , u16 Copy_u16Value);


//SET LOCK OF A PIN TO BE MODE LOCKED OR UNLOCKED //
u8 MGPIO_u8SetPinLock(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);


//SET LOCK OF A PORT TO BE MODE LOCKED OR UNLOCKED //
u8 MGPIO_u8SetPortLock(u8 Copy_u8Port , u16 Copy_u16Value);


//GET VALUE OF A PIN TO BE HIGH OR LOW AND RETURN IT IN POINTER (Copy_Pu8Value) //
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8* Copy_Pu8Value);


#endif
