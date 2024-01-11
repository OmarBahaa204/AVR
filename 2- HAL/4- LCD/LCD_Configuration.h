/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : HAL            *********************/
/**********************      SWC     : LCD            *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 23/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/
#ifndef _LCD_CONFIGURATION_H
#define _LCD_CONFIGURATION_H
#include "../../1- MCAL/1-DIO/DIO_interface.h"
// Control Pins ( PORT & PINS )
#define LCD_u8CONTROL_PORT		DIO_u8PORTC
#define LCD_u8RS_PIN			DIO_u8PIN0
#define LCD_u8RW_PIN			DIO_u8PIN1
#define LCD_u8E_PIN				DIO_u8PIN2
// Data Pins
#define LCD_u8DATAPORT			DIO_u8PORTA


#endif
