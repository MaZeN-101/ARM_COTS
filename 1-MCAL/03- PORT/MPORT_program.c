/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : PORT                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#include "STD_TYPES.h"

#include "MPORT_config.h"
#include "MPORT_interface.h"
#include "MPORT_private.h"
#include "MPORT_register.h"




//INITIALIZE ALL PORTS MODE AND INITIAL VALUE//
void MPORT_voidInit(void)
{
	//SET MODE OF LOW PINS OF PORTS A,B,C
	MGPIOA_CRL = MPORTA_MODE_LOW;
	MGPIOB_CRL = MPORTB_MODE_LOW;
	MGPIOC_CRL = MPORTC_MODE_LOW;

	//SET MODE OF HIGH PINS OF PORTS A,B,C
	MGPIOA_CRH = MPORTA_MODE_HIGH;
	MGPIOB_CRH = MPORTB_MODE_HIGH;
	MGPIOC_CRH = MPORTC_MODE_HIGH;
	
	//SET INITIAL VALUE OF PORTS A,B,C
	MGPIOA_ODR = MPORTA_INITAL_VALUE;
	MGPIOB_ODR = MPORTB_INITAL_VALUE;
	MGPIOC_ODR = MPORTC_INITAL_VALUE;
	
}




