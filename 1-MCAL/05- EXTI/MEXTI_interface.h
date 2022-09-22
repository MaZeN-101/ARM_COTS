/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : EXTI                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

/* define EXTI Lines */
#define MEXTI_LINE0  			0
#define MEXTI_LINE1  			1
#define MEXTI_LINE2  			2
#define MEXTI_LINE3  			3
	
#define MEXTI_LINE4  			4
#define MEXTI_LINE5  			5
#define MEXTI_LINE6  			6
#define MEXTI_LINE7  			7

#define MEXTI_LINE8  			8
#define MEXTI_LINE9  			9
#define MEXTI_LINE10 			10
#define MEXTI_LINE11 			11

#define MEXTI_LINE12 			12
#define MEXTI_LINE13 			13
#define MEXTI_LINE14 			14
#define MEXTI_LINE15 			15


/* define EXTI Lines */
#define MEXTI0  			0
#define MEXTI1  			1
#define MEXTI2  			2
#define MEXTI3  			3

#define MEXTI4  			4
#define MEXTI5  			5
#define MEXTI6  			6
#define MEXTI7  			7

#define MEXTI8  			8
#define MEXTI9  			9
#define MEXTI10 			10
#define MEXTI11 			11

#define MEXTI12 			12
#define MEXTI13 			13
#define MEXTI14 			14
#define MEXTI15 			15


/* define EXTI Modes */
#define MEXTI_RISING_EDGE    	0
#define MEXTI_FALLING_EDGE   	1
#define MEXTI_ON_CHANGE      	2




/* Description : A function to Initialize EXTI on Specific Line
 * Input :
 * Copy_u8EXTILine			, options : Choose one of the EXTI Lines
 * Copy_u8EXTIMode  		, options : Choose one of the EXTI Modes
 * 
 * Output : Return Error Status
 * */
u8 MEXTI_u8Init(u8 Copy_u8EXTILine , u8 Copy_u8EXTIMode);


/* Description : A function to Enable EXTI on Specific Line
 * Input :
 * Copy_u8EXTILine			, options : Choose one of the EXTI Lines
 * 
 * Output : Return Error Status
 * */
u8 MEXTI_u8EXTIEnableLine(u8 Copy_u8EXTILine);


/* Description : A function to Disable EXTI on Specific Line
 * Input :
 * Copy_u8EXTILine			, options : Choose one of the EXTI Lines
 * 
 * Output : Return Error Status
 * */
u8 MEXTI_u8EXTIDisableLine(u8 Copy_u8EXTILine);


/* Description : A function to Enable SoftWare Trigger
 * Input :
 * Copy_u8EXTILine			, options : Choose one of the EXTI Lines
 * 
 * Output : Return Error Status
 * */
u8 MEXTI_u8EXTISWTrigger(u8 Copy_u8EXTILine);


/* Description : A function to Set Call Back For ISR in main
 * Input :
 * Copy_Pv2func 	: Pointer to EXTI0 ISR function
 * Copy_u8EXTINum	: Choose one of the EXTI(0,...,15)
 * 
 * Output : Return Error Status
 * */
u8 MEXTI_u8SetCallBack(void(*Copy_Pv2func)(void) , u8 Copy_u8EXTINum);


#endif









