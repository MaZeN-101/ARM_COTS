/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : HAL                  ************************/
/********************      		SWC     : LEDMAX               ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef HLEDMAX_CONFIG_H_
#define HLEDMAX_CONFIG_H_


/********************************************************************************************/
/*                              SELECT PORT & PIN NUMBER :     			                    */
/*                     0-MGPIO_u8PORTA , MGPIO_u8PIN(0 || 1 || .... || 15)         			*/
/*                     1-MGPIO_u8PORTB , MGPIO_u8PIN(0 || 1 || .... || 15)		    		*/
/*                     2-MGPIO_u8PORTC , MGPIO_u8PIN(13 || 14 || 15)               			*/
/********************************************************************************************/


/* define columns port and pin */
#define HLEDMAX_COL0_PIN				MGPIO_u8PORTA,MGPIO_u8PIN0
#define HLEDMAX_COL1_PIN				MGPIO_u8PORTA,MGPIO_u8PIN1
#define HLEDMAX_COL2_PIN				MGPIO_u8PORTA,MGPIO_u8PIN2
#define HLEDMAX_COL3_PIN				MGPIO_u8PORTA,MGPIO_u8PIN3
#define HLEDMAX_COL4_PIN				MGPIO_u8PORTA,MGPIO_u8PIN4
#define HLEDMAX_COL5_PIN				MGPIO_u8PORTA,MGPIO_u8PIN5
#define HLEDMAX_COL6_PIN				MGPIO_u8PORTA,MGPIO_u8PIN6
#define HLEDMAX_COL7_PIN				MGPIO_u8PORTA,MGPIO_u8PIN7

/* define rows port and pin */
#define HLEDMAX_ROW0_PIN				MGPIO_u8PORTB,MGPIO_u8PIN0
#define HLEDMAX_ROW1_PIN				MGPIO_u8PORTB,MGPIO_u8PIN1
#define HLEDMAX_ROW2_PIN				MGPIO_u8PORTB,MGPIO_u8PIN5
#define HLEDMAX_ROW3_PIN				MGPIO_u8PORTB,MGPIO_u8PIN6
#define HLEDMAX_ROW4_PIN				MGPIO_u8PORTB,MGPIO_u8PIN7
#define HLEDMAX_ROW5_PIN				MGPIO_u8PORTB,MGPIO_u8PIN8
#define HLEDMAX_ROW6_PIN				MGPIO_u8PORTB,MGPIO_u8PIN9
#define HLEDMAX_ROW7_PIN				MGPIO_u8PORTB,MGPIO_u8PIN10


#endif






