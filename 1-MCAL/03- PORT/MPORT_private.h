/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : PORT                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/


#ifndef MPORT_PRIVATE_H_
#define MPORT_PRIVATE_H_


/* MODE CONCATINATE FUNCTION */
#define CONC_MODE(b7,b6,b5,b4,b3,b2,b1,b0)				CONC_MODE_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)

#define CONC_MODE_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0

/* INITAL VALUE CONCATINATE FUNCTION */
#define CONC_INITAL_VALUE(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)			CONC_INITAL_VALUE_HELPER(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)

#define CONC_INITAL_VALUE_HELPER(b15,b14,b13,b12,b11,b10,b9,b8,b7,b6,b5,b4,b3,b2,b1,b0)		0b##b15##b14##b13##b12##b11##b10##b9##b8##b7##b6##b5##b4##b3##b2##b1##b0


/* SET MPORT A,B,C MODES */
#define MPORTA_MODE_LOW	CONC_MODE(MPORTA_PIN7_MODE,MPORTA_PIN6_MODE,MPORTA_PIN5_MODE,MPORTA_PIN4_MODE,MPORTA_PIN3_MODE,MPORTA_PIN2_MODE,MPORTA_PIN1_MODE,MPORTA_PIN0_MODE)
#define MPORTB_MODE_LOW	CONC_MODE(MPORTB_PIN7_MODE,MPORTB_PIN6_MODE,MPORTB_PIN5_MODE,MPORTB_PIN4_MODE,MPORTB_PIN3_MODE,MPORTB_PIN2_MODE,MPORTB_PIN1_MODE,MPORTB_PIN0_MODE)
#define MPORTC_MODE_LOW	CONC_MODE(MPORTC_PIN7_MODE,MPORTC_PIN6_MODE,MPORTC_PIN5_MODE,MPORTC_PIN4_MODE,MPORTC_PIN3_MODE,MPORTC_PIN2_MODE,MPORTC_PIN1_MODE,MPORTC_PIN0_MODE)

#define MPORTA_MODE_HIGH	 CONC_MODE(MPORTA_PIN15_MODE,MPORTA_PIN14_MODE,MPORTA_PIN13_MODE,MPORTA_PIN12_MODE,MPORTA_PIN11_MODE,MPORTA_PIN10_MODE,MPORTA_PIN9_MODE,MPORTA_PIN8_MODE)
#define MPORTB_MODE_HIGH	 CONC_MODE(MPORTB_PIN15_MODE,MPORTB_PIN14_MODE,MPORTB_PIN13_MODE,MPORTB_PIN12_MODE,MPORTB_PIN11_MODE,MPORTB_PIN10_MODE,MPORTB_PIN9_MODE,MPORTB_PIN8_MODE)
#define MPORTC_MODE_HIGH	 CONC_MODE(MPORTC_PIN15_MODE,MPORTC_PIN14_MODE,MPORTC_PIN13_MODE,MPORTC_PIN12_MODE,MPORTC_PIN11_MODE,MPORTC_PIN10_MODE,MPORTC_PIN9_MODE,MPORTC_PIN8_MODE)


/* SET MPORT A,B,C INITIAL VALUES */
#define MPORTA_INITAL_VALUE	CONC_INITAL_VALUE(MPORTA_PIN15_INITIAL_VALUE,MPORTA_PIN14_INITIAL_VALUE,MPORTA_PIN13_INITIAL_VALUE,MPORTA_PIN12_INITIAL_VALUE,MPORTA_PIN11_INITIAL_VALUE,MPORTA_PIN10_INITIAL_VALUE,MPORTA_PIN9_INITIAL_VALUE,MPORTA_PIN8_INITIAL_VALUE,MPORTA_PIN7_INITIAL_VALUE,MPORTA_PIN6_INITIAL_VALUE,MPORTA_PIN5_INITIAL_VALUE,MPORTA_PIN4_INITIAL_VALUE,MPORTA_PIN3_INITIAL_VALUE,MPORTA_PIN2_INITIAL_VALUE,MPORTA_PIN1_INITIAL_VALUE,MPORTA_PIN0_INITIAL_VALUE)

#define MPORTB_INITAL_VALUE	CONC_INITAL_VALUE(MPORTB_PIN15_INITIAL_VALUE,MPORTB_PIN14_INITIAL_VALUE,MPORTB_PIN13_INITIAL_VALUE,MPORTB_PIN12_INITIAL_VALUE,MPORTB_PIN11_INITIAL_VALUE,MPORTB_PIN10_INITIAL_VALUE,MPORTB_PIN9_INITIAL_VALUE,MPORTB_PIN8_INITIAL_VALUE,MPORTB_PIN7_INITIAL_VALUE,MPORTB_PIN6_INITIAL_VALUE,MPORTB_PIN5_INITIAL_VALUE,MPORTB_PIN4_INITIAL_VALUE,MPORTB_PIN3_INITIAL_VALUE,MPORTB_PIN2_INITIAL_VALUE,MPORTB_PIN1_INITIAL_VALUE,MPORTB_PIN0_INITIAL_VALUE)

#define MPORTC_INITAL_VALUE	CONC_INITAL_VALUE(MPORTC_PIN15_INITIAL_VALUE,MPORTC_PIN14_INITIAL_VALUE,MPORTC_PIN13_INITIAL_VALUE,MPORTC_PIN12_INITIAL_VALUE,MPORTC_PIN11_INITIAL_VALUE,MPORTC_PIN10_INITIAL_VALUE,MPORTC_PIN9_INITIAL_VALUE,MPORTC_PIN8_INITIAL_VALUE,MPORTC_PIN7_INITIAL_VALUE,MPORTC_PIN6_INITIAL_VALUE,MPORTC_PIN5_INITIAL_VALUE,MPORTC_PIN4_INITIAL_VALUE,MPORTC_PIN3_INITIAL_VALUE,MPORTC_PIN2_INITIAL_VALUE,MPORTC_PIN1_INITIAL_VALUE,MPORTC_PIN0_INITIAL_VALUE)





/* define pin Configuration */

#define INPUT_ANALOG							0000       //INPUT 10MHZ SPEED PUSH PULL
#define INPUT_FLOATING							0100       //INPUT 10MHZ SPEED OPEN DRAIN
#define INPUT_PULLED_UP_DOWN					1000       //INPUT 10MHZ SPEED ALTERNATIVE FUNCTION PUSH PULL
	
#define OUTPUT_10MHZ_PP							0001	   //OUTPUT 10MHZ SPEED PUSH PULL
#define OUTPUT_10MHZ_OD							0101       //OUTPUT 10MHZ SPEED OPEN DRAIN
#define OUTPUT_10MHZ_AFPP						1001       //OUTPUT 10MHZ SPEED ALTERNATIVE FUNCTION PUSH PULL
#define OUTPUT_10MHZ_AFOD						1101       //OUTPUT 10MHZ SPEED ALTERNATIVE FUNCTION OPEN DRAIN
	
#define OUTPUT_2MHZ_PP							0010	   //OUTPUT 2MHZ SPEED PUSH PULL
#define OUTPUT_2MHZ_OD							0110       //OUTPUT 2MHZ SPEED OPEN DRAIN
#define OUTPUT_2MHZ_AFPP						1010       //OUTPUT 2MHZ SPEED ALTERNATIVE FUNCTION PUSH PULL
#define OUTPUT_2MHZ_AFOD						1110       //OUTPUT 2MHZ SPEED ALTERNATIVE FUNCTION OPEN DRAIN
	
#define OUTPUT_50MHZ_PP							0011       //OUTPUT 50MHZ SPEED PUSH PULL
#define OUTPUT_50MHZ_OD							0111       //OUTPUT 50MHZ SPEED OPEN DRAIN
#define OUTPUT_50MHZ_AFPP						1011       //OUTPUT 50MHZ SPEED ALTERNATIVE FUNCTION PUSH PULL
#define OUTPUT_50MHZ_AFOD						1111       //OUTPUT 50MHZ SPEED ALTERNATIVE FUNCTION OPEN DRAIN


//define MODE OF ALL PINS IN MPORTC THAT NOT USED
#define MPORTC_PIN0_MODE					    0000
#define MPORTC_PIN1_MODE					    0000
#define MPORTC_PIN2_MODE					    0000
#define MPORTC_PIN3_MODE					    0000
#define MPORTC_PIN4_MODE					    0000
#define MPORTC_PIN5_MODE					    0000
#define MPORTC_PIN6_MODE					    0000
#define MPORTC_PIN7_MODE					    0000
#define MPORTC_PIN8_MODE					    0000
#define MPORTC_PIN9_MODE					    0000
#define MPORTC_PIN10_MODE						0000
#define MPORTC_PIN11_MODE						0000
#define MPORTC_PIN12_MODE						0000


//define INITIAL VALUE OF ALL PINS IN MPORTC THAT NOT USED
#define MPORTC_PIN0_INITIAL_VALUE				0
#define MPORTC_PIN1_INITIAL_VALUE				0
#define MPORTC_PIN2_INITIAL_VALUE				0
#define MPORTC_PIN3_INITIAL_VALUE				0
#define MPORTC_PIN4_INITIAL_VALUE				0
#define MPORTC_PIN5_INITIAL_VALUE				0
#define MPORTC_PIN6_INITIAL_VALUE				0
#define MPORTC_PIN7_INITIAL_VALUE				0
#define MPORTC_PIN8_INITIAL_VALUE				0
#define MPORTC_PIN9_INITIAL_VALUE				0
#define MPORTC_PIN10_INITIAL_VALUE				0
#define MPORTC_PIN11_INITIAL_VALUE				0
#define MPORTC_PIN12_INITIAL_VALUE				0


/* define Output Status */
#define OUTPUT_LOW	                            0
#define OUTPUT_HIGH                             1

/* define Input Status */
#define INPUT_PULLED_DOWN	                    0
#define INPUT_PULLED_UP                       	1

#endif
















