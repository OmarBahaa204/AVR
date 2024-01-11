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
/**************************    Global Variables   *************************/
/**************************                       *************************/
/**************************************************************************/
//Global pointer to function to hold Int0 ISR address
void (*EXTI_pvInt0Function)(void) = NULL;
//Global pointer to function to hold Int1 ISR address
void (*EXTI_pvInt1Function)(void) = NULL;
//Global pointer to function to hold Int2 ISR address
void (*EXTI_pvInt2Function)(void) = NULL;
/**************************************************************************/
/**************************                       *************************/
/************************** Function declarations *************************/
/**************************                       *************************/
/**************************************************************************/
void MEXTI_voidInt0Init(void)
{
	/*Check INT0 Sense Control*/
#if INT0_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC00);
	SET_BIT(MCUCR,MCUCR_ISC01);
#else
#error "Wrong INT0 Control Sense from Configuration Options"
#endif
	/*Check PIE initial State*/
#if INT0_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT0);
#else
#error "Wrong INT0 Initial State from Configuration Options"
#endif
}
/**************************************************************************/
void MEXTI_voidInt1Init(void)
{
	/*Check INT1 Sense Control*/
#if INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE == ON_CHANGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE == FALLING_EDGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Wrong INT1 Control Sense from Configuration Options"
#endif
	/*Check PIE initial State*/
#if INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT1);
#else
#error "Wrong INT1 Initial State from Configuration Options"
#endif
}
/**************************************************************************/
void MEXTI_voidInt2Init(void)
{
#if INT2_SENSE == FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
#elif INT2_SENSE == RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error "Wrong INT2 Control Sense from Configuration Options"
#endif
	/*Check PIE initial State*/
#if INT2_INITIAL_STATE == ENABLED
	SET_BIT(GICR,GICR_INT2);
#elif INT2_INITIAL_STATE == DISABLED
	CLR_BIT(GICR,GICR_INT2);
#else
#error "Wrong INT2 Initial State from Configuration Options"
#endif
}
/**************************************************************************/
u8 MEXTI_u8INT0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorStatus = RT_OK;
	if (Copy_u8Sense == LOW_LEVEL)
	{
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	}
	else if(Copy_u8Sense == ON_CHANGE)
	{
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	}
	else if (Copy_u8Sense == FALLING_EDGE)
	{
		CLR_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	}
	else if (Copy_u8Sense == RISING_EDGE)
	{
		SET_BIT(MCUCR,MCUCR_ISC00);
		SET_BIT(MCUCR,MCUCR_ISC01);
	}
	else
	{
		Local_u8ErrorStatus = RT_NOK;
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/
u8 MEXTI_u8INT1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorStatus = RT_OK;
	if (Copy_u8Sense == LOW_LEVEL)
	{
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	}
	else if(Copy_u8Sense == ON_CHANGE)
	{
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
	}
	else if (Copy_u8Sense == FALLING_EDGE)
	{
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	}
	else if (Copy_u8Sense == RISING_EDGE)
	{
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
	}
	else
	{
		Local_u8ErrorStatus = RT_NOK;
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/
u8 MEXTI_u8INT2SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorStatus = RT_OK;
	if(Copy_u8Sense == FALLING_EDGE)
	{
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
	}
	else if(Copy_u8Sense == RISING_EDGE)
	{
		SET_BIT(MCUCSR,MCUCSR_ISC2);
	}
	else
	{
		Local_u8ErrorStatus = RT_NOK;
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/
u8 MEXTI_u8Enable(u8 Copy_u8IntNo)
{
	u8 Local_u8ErrorStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT0 : SET_BIT(GICR,GICR_INT0);break;
	case INT1 : SET_BIT(GICR,GICR_INT1);break;
	case INT2 : SET_BIT(GICR,GICR_INT2);break;
	default : Local_u8ErrorStatus = RT_NOK;
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/
u8 MEXTI_u8Disable(u8 Copy_u8IntNo)
{
	u8 Local_u8ErrorStatus = RT_OK;
	switch(Copy_u8IntNo)
	{
	case INT0 : CLR_BIT(GICR,GICR_INT0);break;
	case INT1 : CLR_BIT(GICR,GICR_INT1);break;
	case INT2 : CLR_BIT(GICR,GICR_INT2);break;
	default : Local_u8ErrorStatus = RT_NOK;
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/

/**************************************************************************/
/**************************                       *************************/
/**************************     ISR Functions     *************************/
/**************************                       *************************/
/**************************************************************************/

/********************************ISR for INT0 *****************************/
void __vector_1 (void)   __attribute__((signal));
void __vector_1 (void)
{
		EXTI_pvInt0Function();
}
/********************************ISR for INT1 *****************************/
void __vector_2 (void)   __attribute__((signal));
void __vector_2 (void)
{
	EXTI_pvInt1Function();
}
/********************************ISR for INT2 *****************************/
void __vector_3 (void)   __attribute__((signal));
void __vector_3 (void)
{
	EXTI_pvInt2Function();
}
/**************************************************************************/

/***********************Send Address of ISR Function***********************/
u8 MEXTI_u8Int0SetCallBack(void (*Copy_pvINT0_ISR)(void))
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(Copy_pvINT0_ISR != NULL)
		EXTI_pvInt0Function = Copy_pvINT0_ISR ;
	else
		Local_u8ErrorStatus = RT_NOK;
	return Local_u8ErrorStatus;
}
u8 MEXTI_u8Int1SetCallBack(void (*Copy_pvINT1_ISR)(void))
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(Copy_pvINT1_ISR != NULL)
		EXTI_pvInt1Function = Copy_pvINT1_ISR ;
	else
		Local_u8ErrorStatus = RT_NOK;
	return Local_u8ErrorStatus;
}
u8 MEXTI_u8Int2SetCallBack(void (*Copy_pvINT2_ISR)(void))
{
	u8 Local_u8ErrorStatus=RT_OK;
	if(Copy_pvINT2_ISR != NULL)
		EXTI_pvInt2Function = Copy_pvINT2_ISR ;
	else
		Local_u8ErrorStatus = RT_NOK;
	return Local_u8ErrorStatus;}
/**************************************************************************/
