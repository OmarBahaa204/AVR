/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : HAL            *********************/
/**********************      SWC     : LCD            *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 23/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/
/******************************          **********************************/
/******************************File Guard**********************************/
/******************************          **********************************/
/**************************************************************************/
#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

/**************************************************************************/
/******************************           *********************************/
/******************************definitions*********************************/
/******************************           *********************************/
/**************************************************************************/
#define LCD_u8FIRIST_ROW								0
#define LCD_u8SECOND_ROW								1
#define LCD_u8LastColumn								15			//LCD 16*2
#define LCD_u8FIRIST_ROW_START							0x00
#define LCD_u8SECOND_COLUMN_START						0x40
#define LCD_CGRAM_NUMBER_OF_LOCATIONS					8
#define LCD_CGRAM_EACH_PTTERN_LOCATIONS					8
/**************************************************************************/
/******************************                 ***************************/
/******************************My_name for CGRAM***************************/
/******************************                 ***************************/
/**************************************************************************/
//u8 G_u8Custom1[]={0x03, 0x02, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00};
//u8 G_u8Custom2[]={0x00, 0x00, 0x1F, 0x0A, 0x0E, 0x00, 0x00, 0x00};
//u8 G_u8Custom3[]={0x00, 0x00, 0x07, 0x04, 0x04, 0x1C, 0x00, 0x00};
/**************************************************************************/
/******************************                 ***************************/
/******************************Function Commands***************************/
/******************************                 ***************************/
/**************************************************************************/
/*Function Set Command D7:D0 ( 0011NFXX ) N for Number of Lines(0 >> 1line & 1 >> 2Lines) .. F (0 >> for 5*8 pixels | 1 >> 5*11 pixels) X is do not care 1 or 0 */
#define FUNCTION_SET 			0b00111000
/*function Display on off control   D7:D0 (00001DCB) D for Display Screen Enable (0 >> off | 1>>on) & C for Cursor Enable (0>>off | 1>>on) & B for Blinking Cursor(0>>no blink | 1 >> Blinking) */
#define DISPLAY_CONTROL			0b00001100
/*Function turn on Cursor without blinking*/
#define On_CURSOR				0b00001110
/*Function Blink Cursor*/
#define BLINK_CURSOR			0b00001111
/*Function Display Clear  (00000001)*/
#define CLEAR_FUNCTION			0b00000001
/*Function Return Home  (0b00000010)*/
#define RETURN_HOME_FUNCTION	0b00000010
/*Function shifts cursor position to left*/
#define SHIFT_LEFT_CURSOR		0b00010000
/*Function shifts cursor position to right*/
#define SHIFT_RIGHT_CURSOR		0b00010100
/*Function shifts Display position to left*/
#define SHIFT_DISPLAY_LEFT		0b00011000
/*Function shifts Display position to right*/
#define SHIFT_DISPLAY_RIGHT		0b00011100
/*Function Entry Mode Set (0b000001(I/D)(SH)) (I/D)>>(increase 1 decrease 0) (SH) (0 no shift ) ( 1 >> if ID 1 Shift to right else ID 0 sheft to the left)*/
#define ENTRY_MODE_SET    	  	0b00000110
/**************************************************************************/
/****************************                   ***************************/
/****************************Function Proto_Type***************************/
/****************************                   ***************************/
/**************************************************************************/
void HLCD_voidSendCommand(u8 Copy_u8Command);
void HLCD_voidSendData(u8 Copy_u8Data);
void HLCD_voidInit(void);
void HLCD_voidSendString(const char *Copy_pcString); //Type For ASCI Value only char  and we used CONST to make sure we wont change it
void HLCD_voidClear(void);
void HLCD_voidReturnHome(void);
u8 HLCD_u8GoToXY(u8 Copy_u8Xposition , u8 Copy_u8Yposition);
u8 HLCD_u8WriteOnCGRAM(u8 Copy_u8PatternIndex , u8 *Copy_pu8PatternValue);
void HLCD_voidWriteNumber(u32 Copy_u32Number);
void HLCD_voidBlinkCursor(void);
void HLCD_voidTurnOnCursor(void);
void HLCD_voidShiftCursorLeft(void);
void HLCD_voidShiftCursorRight(void);
void HLCD_voidShiftDisplayLeft(void);
void HLCD_voidShiftDisplayRight(void);
/**************************************************************************/
#endif
