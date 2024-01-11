/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : MCAl           *********************/
/**********************      SWC     : EXTI           *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 06/01/2024     *********************/
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/
/******************************          **********************************/
/****************************** Includes **********************************/
/******************************          **********************************/
/**************************************************************************/
#include "..\..\4- LIB\STD_TYPES.h"
#include "..\..\4- LIB\STD_ERRORS.h"
#include "..\..\4- LIB\BIT_MATH.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"
#include "EXTI_Config.h"
#include "EXTI_private.h"
#include "../4- GIE/GIE_interface.h"
/**************************************************************************/
/**************************                       *************************/
/************************** Function declarations *************************/
/**************************                       *************************/
/**************************************************************************/
void MEXTI_voidInt0Init(void)
{
	/* Set sense control for INT0 falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC00);
	/* Peripheral interrupt Enable For INT0 */
	SET_BIT(GICR,GICR_INT0);
}
void MEXTI_voidInt1Init(void)
{
	/* Set sense control for INT1 falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
	/* Peripheral interrupt Enable For INT1 */
	SET_BIT(GICR,GICR_INT1);
}
void MEXTI_voidInt2Init(void)
{
	/* Set sense control for INT2 falling edge*/
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
	/* Peripheral interrupt Enable For INT2 */
	SET_BIT(GICR,GICR_INT2);
}

