/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : HAL            *********************/
/**********************      SWC     : Stepper Motor  *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 03/01/2024     *********************/
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/
/******************************          **********************************/
/******************************File Guard**********************************/
/******************************          **********************************/
/**************************************************************************/
#ifndef _STEPPER_CONFIG_H
#define _STEPPER_CONFIG_H
/**************************************************************************/
/******************************              ******************************/
/******************************Configurations******************************/
/******************************              ******************************/
/**************************************************************************/

#define Stepper_PORT	   					DIO_u8PORTA
#define BLUE_WIRE_CTRL	   					DIO_u8PIN0
#define PINK_WIRE_CTRL	   					DIO_u8PIN1
#define YELLOW_WIRE_CTRL   					DIO_u8PIN2
#define ORANGE_WIRE_CTRL					DIO_u8PIN3
#define CLOCK_WISE_DIRECTION				0
#define COUNTER_CLOCK_WISE_DIRECTION		1

#endif
