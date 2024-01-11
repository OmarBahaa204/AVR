/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : MCAl           *********************/
/**********************      SWC     : EXTI           *********************/
/**********************      Version : 2.00           *********************/
/**********************      Date    : 07/01/2024     *********************/
/**************************************************************************/
/**************************************************************************/


/**************************************************************************/
/******************************          **********************************/
/******************************File Guard**********************************/
/******************************          **********************************/
/**************************************************************************/
#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_
/**************************************************************************/
/******************************           *********************************/
/******************************definitions*********************************/
/******************************           *********************************/
/**************************************************************************/
/*Sense Control*/
#define LOW_LEVEL		0
#define ON_CHANGE		1
#define FALLING_EDGE	2
#define RISING_EDGE		3
/*Interrupts*/
#define INT0			0
#define INT1			1
#define INT2			2
/**************************************************************************/
/****************************                   ***************************/
/****************************Function Proto_Type***************************/
/****************************                   ***************************/
/**************************************************************************/
/* Functions to Initialize External Interrupts (Sense,PIE) using pre-build configurations*/
void MEXTI_voidInt0Init(void);
void MEXTI_voidInt1Init(void);
void MEXTI_voidInt2Init(void);
/* Functions to set required Sense Control using post build configurations*/
/*Inputs : Copy_u8Sense , Options :
 	 	 	 	 	 	 	 	 	1- LOW_LEVEL
									2- ON_CHANGE
									3- FALLING_EDGE
									4- RISING_EDGE		 	*/
u8 MEXTI_u8INT0SetSenseControl(u8 Copy_u8Sense);
/*Inputs : Copy_u8Sense , Options :
 	 	 	 	 	 	 	 	 	1- LOW_LEVEL
									2- ON_CHANGE
									3- FALLING_EDGE
									4- RISING_EDGE		 	*/
u8 MEXTI_u8INT1SetSenseControl(u8 Copy_u8Sense);
/*Inputs : Copy_u8Sense , Options :
									1- FALLING_EDGE
									2- RISING_EDGE		 	*/
u8 MEXTI_u8INT2SetSenseControl(u8 Copy_u8Sense);

/* Functions to Enable External Interrupt using post build configurations*/
/*Inputs : Copy_u8IntNo , Options :
 	 	 	 	 	 	 	 	 	1- INT0
									2- INT1
									3- INT2		 	*/
u8 MEXTI_u8Enable(u8 Copy_u8IntNo);
u8 MEXTI_u8Disable(u8 Copy_u8IntNo);
/***********************Send Address of ISR Function***********************/
u8 MEXTI_u8Int0SetCallBack(void (*Copy_pvINT0_ISR)(void));
u8 MEXTI_u8Int1SetCallBack(void (*Copy_pvINT1_ISR)(void));
u8 MEXTI_u8Int2SetCallBack(void (*Copy_pvINT2_ISR)(void));
/**************************************************************************/


#endif
