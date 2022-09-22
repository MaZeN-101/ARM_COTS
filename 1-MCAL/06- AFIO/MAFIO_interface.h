/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : AFIO                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MAFIO_INTERFACE_H_
#define MAFIO_INTERFACE_H_

/* define EXTI Lines */
#define MAFIO_LINE0  			0
#define MAFIO_LINE1  			1
#define MAFIO_LINE2  			2
#define MAFIO_LINE3  			3

#define MAFIO_LINE4  			4
#define MAFIO_LINE5  			5
#define MAFIO_LINE6  			6
#define MAFIO_LINE7  			7

#define MAFIO_LINE8  			8
#define MAFIO_LINE9  			9
#define MAFIO_LINE10 			10
#define MAFIO_LINE11 			11

#define MAFIO_LINE12 			12
#define MAFIO_LINE13 			13
#define MAFIO_LINE14 			14
#define MAFIO_LINE15 			15


/* define EXTI Ports */
#define MAFIO_PORTA   			0
#define MAFIO_PORTB  			1
#define MAFIO_PORTC		      	2




/* Description : A function to Set EXTI Configuration on Specific Line
 * Input :
 * Copy_u8EXTILine			, options : Choose one of the EXTI Lines
 * Copy_u8PortMap	  		, options : Choose one of the EXTI Ports
 * 
 * Output : Return Error Status
 * */
u8 MAFIO_u8SetEXTIConfig(u8 Copy_u8EXTILine , u8 Copy_u8PortMap);


#endif









