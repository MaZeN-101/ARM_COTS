/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : PORT                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MPORT_CONFIG_H_
#define MPORT_CONFIG_H_

/********************************************************************************************/
/*                              SELECT PIN MODE :     			                            */
/*                              0-INPUT_ANALOG                                           	*/
/*                              1-INPUT_FLOATING		                                   	*/
/*                              2-INPUT_PULLED_UP_DOWN                                   	*/
/*                              3-OUTPUT_10MHZ_PP		                                  	*/
/*                              4-OUTPUT_10MHZ_OD		                                  	*/
/*                              5-OUTPUT_10MHZ_AFPP                                  		*/
/*                              6-OUTPUT_10MHZ_AFOD                                  		*/
/*                              7-OUTPUT_2MHZ_PP	                                 		*/
/*                              8-OUTPUT_2MHZ_OD	                                  		*/
/*                              9-OUTPUT_2MHZ_AFPP                                 			*/
/*                              10-OUTPUT_2MHZ_AFOD                                 		*/
/*                              11-OUTPUT_50MHZ_PP		                                	*/
/*                              12-OUTPUT_50MHZ_OD		                                	*/
/*                              13-OUTPUT_50MHZ_AFPP                               			*/
/*                              14-OUTPUT_50MHZ_AFOD                                		*/
/********************************************************************************************/

/* define MODE of all pins in PORTA */
#define MPORTA_PIN0_MODE					    INPUT_FLOATING
#define MPORTA_PIN1_MODE					    OUTPUT_2MHZ_PP
#define MPORTA_PIN2_MODE					    OUTPUT_2MHZ_PP
#define MPORTA_PIN3_MODE					    OUTPUT_2MHZ_PP
#define MPORTA_PIN4_MODE					    INPUT_ANALOG
#define MPORTA_PIN5_MODE					    INPUT_ANALOG
#define MPORTA_PIN6_MODE					    INPUT_ANALOG
#define MPORTA_PIN7_MODE					    INPUT_ANALOG
#define MPORTA_PIN8_MODE					    INPUT_ANALOG
#define MPORTA_PIN9_MODE					    INPUT_ANALOG
#define MPORTA_PIN10_MODE						INPUT_ANALOG
#define MPORTA_PIN11_MODE						INPUT_ANALOG
#define MPORTA_PIN12_MODE						INPUT_ANALOG
#define MPORTA_PIN13_MODE						INPUT_ANALOG
#define MPORTA_PIN14_MODE						INPUT_ANALOG
#define MPORTA_PIN15_MODE						INPUT_ANALOG
	
/* define MODE of all pins in PORTB */
#define MPORTB_PIN0_MODE					    INPUT_ANALOG
#define MPORTB_PIN1_MODE					    INPUT_ANALOG
#define MPORTB_PIN2_MODE					    INPUT_ANALOG
#define MPORTB_PIN3_MODE					    INPUT_ANALOG
#define MPORTB_PIN4_MODE					    INPUT_ANALOG
#define MPORTB_PIN5_MODE					    INPUT_ANALOG
#define MPORTB_PIN6_MODE					    INPUT_ANALOG
#define MPORTB_PIN7_MODE					    INPUT_ANALOG
#define MPORTB_PIN8_MODE					    INPUT_ANALOG
#define MPORTB_PIN9_MODE					    INPUT_ANALOG
#define MPORTB_PIN10_MODE						INPUT_ANALOG
#define MPORTB_PIN11_MODE						INPUT_ANALOG
#define MPORTB_PIN12_MODE						INPUT_ANALOG
#define MPORTB_PIN13_MODE						INPUT_ANALOG
#define MPORTB_PIN14_MODE						INPUT_ANALOG
#define MPORTB_PIN15_MODE						INPUT_ANALOG

/* define MODE of all pins in PORTC */
#define MPORTC_PIN13_MODE						INPUT_ANALOG
#define MPORTC_PIN14_MODE						INPUT_ANALOG
#define MPORTC_PIN15_MODE						INPUT_ANALOG


/********************************************************************************************/
/*                              SELECT PIN INITIAL VALUE :     			                    */
/*                              0-OUTPUT_LOW	                                         	*/
/*                              1-OUTPUT_HIGH		                                   		*/
/*                              2-INPUT_PULLED_UP                                   		*/
/*                              3-INPUT_PULLED_DOWN		                                  	*/
/********************************************************************************************/
		 

/* define Initial value of all pins in PORTA */
#define MPORTA_PIN0_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN1_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN2_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN3_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN4_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN5_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN6_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN7_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN8_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN9_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN10_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN11_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN12_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN13_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN14_INITIAL_VALUE						OUTPUT_LOW
#define MPORTA_PIN15_INITIAL_VALUE						OUTPUT_LOW

/* define Initial value of all pins in PORTB */
#define MPORTB_PIN0_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN1_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN2_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN3_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN4_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN5_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN6_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN7_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN8_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN9_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN10_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN11_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN12_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN13_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN14_INITIAL_VALUE						OUTPUT_LOW
#define MPORTB_PIN15_INITIAL_VALUE						OUTPUT_LOW

/* define Initial value of all pins in PORTC */
#define MPORTC_PIN13_INITIAL_VALUE						OUTPUT_LOW
#define MPORTC_PIN14_INITIAL_VALUE						OUTPUT_LOW
#define MPORTC_PIN15_INITIAL_VALUE						OUTPUT_LOW


#endif


