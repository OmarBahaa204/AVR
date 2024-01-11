/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : HAL            *********************/
/**********************      SWC     : LCD            *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 23/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/
#include "../../4- LIB/BIT_MATH.h"
#include "../../4- LIB/STD_ERRORS.h"
#include "../../4- LIB/STD_TYPES.h"
#include "LCD_Configuration.h"
#include "LCD_Interface.h"
#include "../../1- MCAL/1-DIO/DIO_interface.h"
#include <util/delay.h>




/**************************************************************************/
/***************************                      *************************/
/*******************        Functions Declarations        *****************/
/***************************                      *************************/
/**************************************************************************/
void HLCD_voidSendCommand(u8 Copy_u8Command)
{
	//DIO_u8SetPinDirection(LCD_u8CONTROL_PORT,LCD_u8RS_PIN,DIO_u8PIN_OUTPUT);
	//DIO_u8SetPinDirection(LCD_u8CONTROL_PORT,LCD_u8RW_PIN,DIO_u8PIN_OUTPUT);
	//DIO_u8SetPortDirection(LCD_u8DATAPORT,DIO_u8PIN_OUTPUT);
	//DIO_u8SetPinDirection(LCD_u8CONTROL_PORT,LCD_u8E_PIN,DIO_u8PIN_OUTPUT);

	/* Control RS & RW pins */
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8RS_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8RW_PIN,DIO_u8PIN_LOW);

	/* Write command on data Pins */
	DIO_u8SetPortValue(LCD_u8DATAPORT,Copy_u8Command);

	/*Pulse on Enable Pin*/
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8E_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);
}
/**************************************************************************/
void HLCD_voidSendData(u8 Copy_u8Data)
{
	//DIO_u8SetPinDirection(LCD_u8CONTROL_PORT,LCD_u8RS_PIN,DIO_u8PIN_OUTPUT);
	//DIO_u8SetPinDirection(LCD_u8CONTROL_PORT,LCD_u8RW_PIN,DIO_u8PIN_OUTPUT);
	//DIO_u8SetPortDirection(LCD_u8DATAPORT,DIO_u8PIN_OUTPUT);
	//DIO_u8SetPinDirection(LCD_u8CONTROL_PORT,LCD_u8E_PIN,DIO_u8PIN_OUTPUT);

	/* Control RS & RW pins */
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8RS_PIN,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8RW_PIN,DIO_u8PIN_LOW);

	/* Write command on data Pins */
	DIO_u8SetPortValue(LCD_u8DATAPORT,Copy_u8Data);

	/*Pulse on Enable Pin*/
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_u8CONTROL_PORT,LCD_u8E_PIN,DIO_u8PIN_LOW);
	_delay_ms(2);
}
/**************************************************************************/
void HLCD_voidInit(void)
{
	/*Wait for more than 30ms*/
	_delay_ms(40);
	HLCD_voidSendCommand(FUNCTION_SET);
	HLCD_voidSendCommand(DISPLAY_CONTROL);
	HLCD_voidSendCommand(CLEAR_FUNCTION);
	HLCD_voidSendCommand(ENTRY_MODE_SET);
}
/**************************************************************************/
void HLCD_voidSendString(const char *Copy_pcString)
{
	u8 Local_u8Counter=0;
	while(Copy_pcString[Local_u8Counter] != '\0')
	{
		HLCD_voidSendData(Copy_pcString[Local_u8Counter]);
		Local_u8Counter++;
	}
}
/**************************************************************************/
void HLCD_voidClear(void)
{
	HLCD_voidSendCommand(CLEAR_FUNCTION);
}
/**************************************************************************/
void HLCD_voidReturnHome(void)
{
	HLCD_voidSendCommand(RETURN_HOME_FUNCTION);
}
/**************************************************************************/
u8 HLCD_u8GoToXY(u8 Copy_u8Xposition , u8 Copy_u8Yposition)
{
	u8 Local_u8Errorstatus = RT_OK;
	u8 Local_u8Address;
	if ( (Copy_u8Xposition <= LCD_u8SECOND_ROW ) && (Copy_u8Yposition <= LCD_u8LastColumn))
	{
		if(Copy_u8Xposition == LCD_u8FIRIST_ROW)
		{
			Local_u8Address= LCD_u8FIRIST_ROW_START + Copy_u8Yposition;
		}
		else if( Copy_u8Xposition == LCD_u8SECOND_ROW)
		{
			Local_u8Address= LCD_u8SECOND_COLUMN_START + Copy_u8Yposition;
		}
		/*Function Set DDRAM Address send this 8 Bits >> (1 AC6 AC5 AC4 AC3 AC2 AC1 AC0 ) AC for (Address Counter) */
		SET_BIT(Local_u8Address,7);
		HLCD_voidSendCommand(Local_u8Address);
	}
	else
	{
		Local_u8Errorstatus = RT_NOK;
	}
	return Local_u8Errorstatus;
}
/**************************************************************************/
u8 HLCD_u8WriteOnCGRAM(u8 Copy_u8PatternIndex , u8 *Copy_pu8PatternValue)
{
	u8 Local_u8ErrorStatus = RT_OK;
	u8 Local_u8Counter;
	u8 Local_u8CGRAM_Address;
	if(Copy_u8PatternIndex < LCD_CGRAM_NUMBER_OF_LOCATIONS)
	{
		/*Setting AC to CGRAM*/
		//pattern Index from 0 to 7 , CGRAM address from 0 to 67 each Pattern has 8 addresses
		Local_u8CGRAM_Address = Copy_u8PatternIndex * LCD_CGRAM_NUMBER_OF_LOCATIONS ;
		SET_BIT(Local_u8CGRAM_Address,6);
		HLCD_voidSendCommand(Local_u8CGRAM_Address);
		/*Now we are writing 8 Patterns on CGRAM*/
		for(Local_u8Counter=0; Local_u8Counter < LCD_CGRAM_EACH_PTTERN_LOCATIONS; Local_u8Counter++)
		{
			HLCD_voidSendData(Copy_pu8PatternValue[Local_u8Counter]);
		}
	}
	else
	{
		Local_u8ErrorStatus = RT_NOK;
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/
void HLCD_voidWriteNumber(u32 Copy_u32Number)
{
	u8 local_u8Digits[10];
	s8 Local_u8Length=0, Local_u8Iterator=0;
	if(Copy_u32Number == 0 )
	{
		HLCD_voidSendData('0');
	}
	else
	{
		while(Copy_u32Number != 0 )
		{
			local_u8Digits[Local_u8Length] = Copy_u32Number % 10 ;
			Copy_u32Number = Copy_u32Number / 10 ;
			Local_u8Length++;
		}
		for(Local_u8Iterator = (Local_u8Length-1) ; Local_u8Iterator >= 0 ;Local_u8Iterator--)
		{
			HLCD_voidSendData((local_u8Digits[Local_u8Iterator] + '0'));
		}
	}
}
/**************************************************************************/
void HLCD_voidBlinkCursor(void)
{
	HLCD_voidSendCommand(BLINK_CURSOR);
}
/**************************************************************************/
void HLCD_voidTurnOnCursor(void)
{
	HLCD_voidSendCommand(On_CURSOR);
}
/**************************************************************************/
void HLCD_voidShiftCursorLeft(void)
{
	HLCD_voidSendCommand(SHIFT_LEFT_CURSOR);
}
/**************************************************************************/
void HLCD_voidShiftCursorRight(void)
{
	HLCD_voidSendCommand(SHIFT_RIGHT_CURSOR);
}
/**************************************************************************/
void HLCD_voidShiftDisplayLeft(void)
{
	HLCD_voidSendCommand(SHIFT_DISPLAY_LEFT);
}
/**************************************************************************/
void HLCD_voidShiftDisplayRight(void)
{
	HLCD_voidSendCommand(SHIFT_DISPLAY_RIGHT);
}
/**************************************************************************/
