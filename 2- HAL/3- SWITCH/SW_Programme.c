/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : HAL            *********************/
/**********************      SWC     : SWITCH         *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 21/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/
#include "../../4- LIB/STD_Types.h"
#include "../../4- LIB/STD_ERRORS.h"
#include "../../4- LIB/BIT_MATH.h"
#include "../../1- MCAL/1-DIO/DIO_interface.h"
#include "SW_Interface.h"
#include "util/delay.h"

u8 HSW_u8GetState(u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8PullType, u8 *Copy_pu8Status)
{
	u8 Local_u8ErrorState = RT_OK;
	u8 Local_u8SwStatus = SW_u8NOT_PRESSED ;

	if(Copy_pu8Status!=NULL)
	{
		if(Copy_u8PullType==SW_u8PULL_UP)
			//if the switch is pressed so the pin will be connected to ground = 0
		{
			DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);//Activating Pull_up_Resistor
			DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Local_u8SwStatus);
			_delay_ms(200);
			if(Local_u8SwStatus==SW_u8NOT_PRESSED)
			{
				*Copy_pu8Status = SW_u8NOT_PRESSED;
			}
			else if (Local_u8SwStatus==SW_u8PRESSED)
			{
				*Copy_pu8Status = SW_u8PRESSED;
			}
			else
			{
				Local_u8ErrorState = RT_NOK;
			}
		}
		else if(Copy_u8PullType == SW_u8PULL_DOWN)
			//if the switch is pressed so the pin will be connected to VCC = 1
		{
			DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);//deactivate Pull_up_Resistor
			DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Local_u8SwStatus);
			_delay_ms(200);
			//using pull down resistor >> pressed == 1 , NotPressed == 0
			if(Local_u8SwStatus == 0)
			{
				*Copy_pu8Status = SW_u8NOT_PRESSED;
			}
			else if (Local_u8SwStatus==1)
			{
				*Copy_pu8Status = SW_u8PRESSED;
			}
			else
			{
				Local_u8ErrorState = RT_NOK;
			}
		}
		else
		{
			Local_u8ErrorState=RT_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = RT_NOK;
	}
	return Local_u8ErrorState;
}
