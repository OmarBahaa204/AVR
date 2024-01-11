/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : MCAl           *********************/
/**********************      SWC     : DIO            *********************/
/**********************      Version : 2.00           *********************/
/**********************      Date    : 30/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/
//Library
#include "../../4- LIB/STD_Types.h"
#include "../../4- LIB/STD_ERRORS.h"
#include "../../4- LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_register.h"
/**************************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin ,u8 Copy_u8Value)
{
	u8 Local_u8Errorstatus = RT_OK;
	if(Copy_u8Pin <= DIO_u8PIN7 )
	{
		if(Copy_u8Value==DIO_u8PIN_HIGH)
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : SET_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB : SET_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC : SET_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD : SET_BIT(PORTD,Copy_u8Pin);break;
			default : Local_u8Errorstatus = RT_NOK;
			}
		else if (Copy_u8Value==DIO_u8PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_u8PORTA : CLR_BIT(PORTA,Copy_u8Pin);break;
			case DIO_u8PORTB : CLR_BIT(PORTB,Copy_u8Pin);break;
			case DIO_u8PORTC : CLR_BIT(PORTC,Copy_u8Pin);break;
			case DIO_u8PORTD : CLR_BIT(PORTD,Copy_u8Pin);break;
			default : Local_u8Errorstatus = RT_NOK;
			}
		}
		else
		{
			Local_u8Errorstatus = RT_NOK;
		}
	}
	else
	{
		Local_u8Errorstatus=RT_NOK;
	}

	return Local_u8Errorstatus;
}
/**************************************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8Port ,u8 Copy_u8Value)
{
	u8 Local_u8Errorstatus = RT_OK;
	switch(Copy_u8Port)
	{
	case DIO_u8PORTA : PORTA=Copy_u8Value;break;
	case DIO_u8PORTB : PORTB=Copy_u8Value;break;
	case DIO_u8PORTC : PORTC=Copy_u8Value;break;
	case DIO_u8PORTD : PORTD=Copy_u8Value;break;
	default : Local_u8Errorstatus = RT_NOK;
	}
	return Local_u8Errorstatus;
}
/**************************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin , u8* Copy_pu8Value)
{
	u8 Local_u8Errorstatus = RT_OK;
	if((Copy_u8Pin<=DIO_u8PIN7) && (Copy_pu8Value != NULL))
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : *Copy_pu8Value = GET_BIT(PINA,Copy_u8Pin);break;
		case DIO_u8PORTB : *Copy_pu8Value = GET_BIT(PINB,Copy_u8Pin);break;
		case DIO_u8PORTC : *Copy_pu8Value = GET_BIT(PINC,Copy_u8Pin);break;
		case DIO_u8PORTD : *Copy_pu8Value = GET_BIT(PIND,Copy_u8Pin);break;
		default : Local_u8Errorstatus = RT_NOK;
		}
	}
	else
	{
		Local_u8Errorstatus=RT_NOK;
	}
	return Local_u8Errorstatus;
}
/**************************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8* Copy_pu8Value)
{
	u8 Local_u8Errorstatus = RT_OK;
	if(Copy_pu8Value != NULL)
	{
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA : *Copy_pu8Value =PINA ;break;
		case DIO_u8PORTB : *Copy_pu8Value =PINB ;break;
		case DIO_u8PORTC : *Copy_pu8Value =PINC ;break;
		case DIO_u8PORTD : *Copy_pu8Value =PIND ;break;
		default : Local_u8Errorstatus = RT_NOK;
		}
	}
	else
	{
		Local_u8Errorstatus=RT_NOK;
	}

	return Local_u8Errorstatus;
}
/**************************************************************************/
