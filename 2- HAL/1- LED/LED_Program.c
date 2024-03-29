/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : HAL            *********************/
/**********************      SWC     : LED            *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 21/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/
#include "..\..\4- LIB\STD_TYPES.h"
#include "..\..\4- LIB\STD_ERRORS.h"
#include "..\..\4- LIB\BIT_MATH.h"
#include "..\..\1- MCAL\1-DIO\DIO_Interface.h"
#include "LED_Interface.h"
#include "../../1- MCAL/1-DIO/DIO_interface.h"




u8 HLed_u8TurnOn(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionType)
{
	u8 Local_u8ErrorStatus = RT_OK;
	//LED is Sink connection type
	if(Copy_u8ConnectionType == LED_u8LED_CONNECTION_SINK )
	{
		DIO_u8SetPinValue(Copy_u8Port ,Copy_u8Pin ,DIO_u8PIN_HIGH);
	}
	//LED is Source connection type
	else if (Copy_u8ConnectionType==LED_u8LED_CONNECTION_SOURCE)
	{
		DIO_u8SetPinValue(Copy_u8Port ,Copy_u8Pin ,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}

	return Local_u8ErrorStatus;
}
u8 HLed_u8TurnOff(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8ConnectionType)
{
	u8 Local_u8ErrorStatus = RT_OK;
	//LED is Source connection type
	if(Copy_u8ConnectionType == LED_u8LED_CONNECTION_SOURCE )
	{
		DIO_u8SetPinValue(Copy_u8Port ,Copy_u8Pin ,DIO_u8PIN_HIGH);
	}
	//LED is Sink connection type
	else if (Copy_u8ConnectionType == LED_u8LED_CONNECTION_SINK)
	{
		DIO_u8SetPinValue(Copy_u8Port ,Copy_u8Pin ,DIO_u8PIN_LOW);
	}
	else
	{
		Local_u8ErrorStatus=RT_NOK;
	}

	return Local_u8ErrorStatus;
}
