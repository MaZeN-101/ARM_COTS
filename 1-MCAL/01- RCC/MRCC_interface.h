/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : RCC                  ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

/* Define BUS STATE */
#define MRCC_BusEnable               0
#define MRCC_BusDisable              1


/* define BUS Type */
#define MRCC_AHB					1
#define MRCC_APB1					2
#define MRCC_APB2					3


/* define AHB Peripherals */
#define AHB_DMA1_EN					0
#define AHB_DMA2_EN					1
#define AHB_SRAM_EN					2
#define AHB_FLITF_EN				4
#define AHB_CRC_EN					6
#define AHB_FSMC_EN					8
#define AHB_SDIO_EN					10


/* define APB2 Peripherals */
#define APB2_AFIO_EN				0
#define APB2_IOPA_EN				2
#define APB2_IOPB_EN				3
#define APB2_IOPC_EN				4
#define APB2_IOPD_EN				5
#define APB2_IOPE_EN				6
#define APB2_IOPF_EN				7
#define APB2_IOPG_EN				8
#define APB2_ADC1_EN				9
#define APB2_ADC2_EN				10
#define APB2_TIM1_EN				11
#define APB2_SPI1_EN				12
#define APB2_TIM8_EN				13
#define APB2_USART1_EN				14
#define APB2_ADC3_EN				15
#define APB2_TIM9_EN				19
#define APB2_TIM10_EN				20
#define APB2_TIM11_EN				21


/* define APB1 Peripherals */
#define APB1_TIM2_EN				0
#define APB1_TIM3_EN				1
#define APB1_TIM4_EN				2
#define APB1_TIM5_EN				3
#define APB1_TIM6_EN				4
#define APB1_TIM7_EN				5
#define APB1_TIM12_EN				6
#define APB1_TIM13_EN				7
#define APB1_TIM14_EN				8
#define APB1_WWDG_EN				11
#define APB1_SPI2_EN				14
#define APB1_SPI3_EN				15
#define APB1_USART2_EN				17
#define APB1_USART3_EN				18
#define APB1_USART4_EN				19
#define APB1_USART5_EN				20
#define APB1_I2C1_EN				21
#define APB1_I2C2_EN				22
#define APB1_USB_EN					23
#define APB1_CAN_EN					25
#define APB1_BKP_EN					27
#define APB1_PWR_EN					28
#define APB1_DAC_EN					29


/* Description : A function to Enable or Disable Clock on Peripheral
 * Input :
 * Copy_u8BusId      	, options :	MRCC_AHB || MRCC_APB1 || MRCC_APB2
 * Copy_u8BusStatus		, options : MRCC_BusEnable || MRCC_BusDisable
 * Copy_u8peripheralId  ,
 * 
 * options :
 * NOTE : Select these Peripherals if (RCC_AHB) is chosen
 * AHB_DMA1_EN || AHB_DMA2_EN || AHB_SRAM_EN || AHB_FLITF_EN || AHB_CRC_EN || AHB_FSMC_EN || AHB_FSMC_EN || AHB_SDIO_EN
 *
 * NOTE : Select these Peripherals if (RCC_APB2) is chosen
 * APB2_AFIO_EN  || APB2_IOPA_EN || APB2_IOPB_EN || APB2_IOPC_EN || APB2_IOPD_EN || APB2_IOPE_EN   || APB2_IOPF_EN || APB2_IOPG_EN
 * APB2_ADC1_EN  || APB2_ADC2_EN || APB2_TIM1_EN || APB2_SPI1_EN || APB2_TIM8_EN || APB2_USART1_EN || APB2_ADC3_EN || APB2_TIM9_EN
 * APB2_TIM10_EN || APB2_TIM11_EN
 *
 * NOTE : Select these Peripherals if (RCC_APB1) is chosen
 * APB1_TIM2_EN  || APB1_TIM3_EN || APB1_TIM4_EN || APB1_TIM5_EN || APB1_TIM6_EN   || APB1_TIM7_EN   || APB1_TIM12_EN  || APB1_TIM13_EN
 * APB1_TIM14_EN || APB1_WWDG_EN || APB1_SPI2_EN || APB1_SPI3_EN || APB1_USART2_EN || APB1_USART3_EN || APB1_USART4_EN || APB1_USART5_EN
 * APB1_I2C1_EN  || APB1_I2C2_EN || APB1_USB_EN  || APB1_CAN_EN  || APB1_BKP_EN    || APB1_PWR_EN    || APB1_DAC_EN
 *
 * Output : 
 * */
void MRCC_voidEnableDisableClock(u8 Copy_u8BusId , u8 Copy_u8peripheralId , u8 Copy_u8BusStatus);



/* Description : A function to Determine Clock Type used for Processor
 * Input : void
 * Output : void
 * */
void MRCC_voidIntiSysClock(void);





#endif
