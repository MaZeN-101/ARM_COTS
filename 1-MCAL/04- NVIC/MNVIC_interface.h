/**************************************************************************************/
/**************************************************************************************/
/********************      		Author  : Mazen gasser         ************************/
/********************     		Layer   : MCAL                 ************************/
/********************      		SWC     : NVIC                 ************************/
/********************      		Version : 1.00                 ************************/
/**************************************************************************************/
/**************************************************************************************/



#ifndef	MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_

/* define Interrupt Status */
#define MNVIC_ENABLE_INTERRUPT			0
#define MNVIC_DISABLE_INTERRUPT			1


/* define Pending Flag Status */
#define MNVIC_SET_PENDING_FLAG			0
#define MNVIC_CLR_PENDING_FLAG			1


/* define Internal Interrupts Positions */
#define MNVIC_USAGE_FAULT    			-1
#define MNVIC_BUS_FAULT      			-2
#define MNVIC_MEMORY_MANAGE  			-3
#define MNVIC_SV_CALL        			-4
#define MNVIC_SYSTICK        			-5
#define MNVIC_PEND_SV        			-6


/* define External Interrupts Positions */
#define MNVIC_WWDG                      0
#define MNVIC_PVD                       1
#define MNVIC_TAMPER                    2
#define MNVIC_RTC                       3
#define MNVIC_FLASH                     4
#define MNVIC_RCC                       5
#define MNVIC_EXTI0                     6 
#define MNVIC_EXTI1                     7
#define MNVIC_EXTI2                     8
#define MNVIC_EXTI3                     9
#define MNVIC_EXTI4                     10
#define MNVIC_DMA1_CHANNEL1             11
#define MNVIC_DMA1_CHANNEL2             12
#define MNVIC_DMA1_CHANNEL3             13
#define MNVIC_DMA1_CHANNEL4             14
#define MNVIC_DMA1_CHANNEL5             15
#define MNVIC_DMA1_CHANNEL6             16
#define MNVIC_DMA1_CHANNEL7             17
#define MNVIC_ADC1_2                    18
#define MNVIC_USB_HP_CAN_TX             19
#define MNVIC_USB_HP_CAN_RX0            20
#define MNVIC_CAN_RX1                   21
#define MNVIC_CAN_SCE                   22
#define MNVIC_EXTI9_5                   23
#define MNVIC_TIM1_BRK                  24
#define MNVIC_TIM1_UP                   25
#define MNVIC_TIM1_TRG_COM              26
#define MNVIC_TIM1_CC                   27
#define MNVIC_TIM2                      28
#define MNVIC_TIM3                      29
#define MNVIC_TIM4                      30
#define MNVIC_I2C1_EV                   31
#define MNVIC_I2C1_ER                   32
#define MNVIC_I2C2_EV                   33
#define MNVIC_I2C2_ER                   34
#define MNVIC_SPI1                      35
#define MNVIC_SPI2                      36
#define MNVIC_USART1                    37
#define MNVIC_USART2                    38
#define MNVIC_USART3                    39
#define MNVIC_EXTI15_10                 40
#define MNVIC_RTC_ALARM                 41
#define MNVIC_USB_WAKE_UP               42
#define MNVIC_TIM8_BRK                  43
#define MNVIC_TIM8_UP                   44
#define MNVIC_TIM8_TRG_COM              45
#define MNVIC_TIM8_CC                   46
#define MNVIC_ADC3                      47
#define MNVIC_FSMC                      48
#define MNVIC_SDIO                      49
#define MNVIC_TIM5                      50
#define MNVIC_SPI3                      51
#define MNVIC_USART4                    52
#define MNVIC_USART5                    53
#define MNVIC_TIM6                      54
#define MNVIC_TIM7                      55
#define MNVIC_DMA2_CHANNEL1             56
#define MNVIC_DMA2_CHANNEL2             57
#define MNVIC_DMA2_CHANNEL3             58
#define MNVIC_DMA2_CHANNEL4_5           59


/* Description : A function to Enable or Disable Interrupt on Peripheral
 * Input :
 * Copy_u8InterruptStatus	, options : MNVIC_ENABLE_INTERRUPT || MNVIC_DISABLE_INTERRUPT
 * Copy_u8InterruptId  		, options : Choose one of the External Interrupts
 * 
 * Output : Return Error Status
 * */
u8 MNVIC_u8EnableDisableInterrupt(u8 Copy_u8InterruptId , u8 Copy_u8InterruptStatus);


/* Description : A function to Set or Clear Pending Flag of Peripheral
 * Input :
 * Copy_u8FlagStatus		, options : MNVIC_SET_PENDING_FLAG || MNVIC_CLR_PENDING_FLAG
 * Copy_u8InterruptId  		, options : Choose one of the External Interrupts
 * 
 * Output : Return Error Status
 * */
u8 MNVIC_u8SetClearPendingFlag(u8 Copy_u8InterruptId , u8 Copy_u8FlagStatus);


/* Description : A function to Get Active Flag Reading of Peripheral
 * Input :
 * Copy_u8FlagReading		, options : Pass u8 variable to Get Active Flag Reading
 * Copy_u8InterruptId  		, options : Choose one of the External Interrupts
 * 
 * Output : Return Error Status
 * */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptId , u8* Copy_u8FlagReading);


/* Description : A function to Get Active Flag Reading of Peripheral
 * Input :
 * Copy_u8GroupPriority		, options :
 * Copy_u8SubPriority		, options :
 * Copy_u8InterruptId  		, options : Choose one of the Core or External Interrupts
 *
 * Output : Return Error Status
 * */
u8 MNVIC_u8SetPriority(s8 Copy_s8InterruptId , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority);


void MNVIC_voidInit(void);

#endif
