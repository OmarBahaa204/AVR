/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : HAL            *********************/
/**********************      SWC     : KEYPAD         *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 30/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/
/******************************          **********************************/
/****************************** Includes **********************************/
/******************************          **********************************/
/**************************************************************************/
#include "../../4- LIB/BIT_MATH.h"
#include "../../4- LIB/STD_ERRORS.h"
#include "../../4- LIB/STD_TYPES.h"
#include "../../1- MCAL/1-DIO/DIO_interface.h"
#include "HKeyPad_interface.h"
#include "HKeyPad_configuration.h"
#include "HKeyPad_private.h"
/**************************************************************************/
/**************************                       *************************/
/************************** Function declarations *************************/
/**************************                       *************************/
/**************************************************************************/
u8 HKPD_u8GetPressedKey(void)
{
	/*Very High memory usage  so we will use "STATIC"*/
	static u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	static u8 Local_u8PinStatus;
	static u8 Local_u8ColumnIdx , Local_u8RowIdx;
	static u8 Local_u8KPDArr[ROW_NUMBER][COLUMN_NUMBER] = KPD_ARR_VAL ;
	static u8 Local_u8KPDColArr[COLUMN_NUMBER]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
	static u8 Local_u8KPDRowArr[ROW_NUMBER]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	for(Local_u8ColumnIdx = 0 ; Local_u8ColumnIdx < COLUMN_NUMBER ; Local_u8ColumnIdx ++)
	{
		/*Activate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColArr[Local_u8ColumnIdx],DIO_u8PIN_LOW);
		for (Local_u8RowIdx = 0 ; Local_u8RowIdx <ROW_NUMBER ;Local_u8RowIdx++)
		{
			/*Read Current Row*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIdx],&Local_u8PinStatus);
			/*Check if switch is pressed */
			if(Local_u8PinStatus == SW_PRESSED )
			{
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];
				/*Polling(busy waiting) until the key is released*/
				while(Local_u8PinStatus == SW_PRESSED)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIdx],&Local_u8PinStatus);
				}
				/*if we found it is pressed so return , finish the function & do not complete the loop we have found the one which is pressed*/
				return Local_u8PressedKey;
			}
		}
		/*Deactivate current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColArr[Local_u8ColumnIdx],DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;
}
