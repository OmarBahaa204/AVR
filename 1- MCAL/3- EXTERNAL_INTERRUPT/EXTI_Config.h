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
/******************************File Guard**********************************/
/******************************          **********************************/
/**************************************************************************/
#ifndef _EXTI_CONFIG_H
#define _EXTI_CONFIG_H
/*********************************INT0*************************************/
/*	Options:
 	 	 	1- LOW_LEVEL
 	 	 	2- ON_CHANGE
 	 	 	3- FALLING_EDGE
 	 	 	4- RISING_EDGE		*/
#define INT0_SENSE	FALLING_EDGE

/*	Options:
 	 	 	1- ENABLED
 	 	 	2- DISABLED		*/
#define INT0_INITIAL_STATE	ENABLED
/**************************************************************************/
/*********************************INT1*************************************/
/*	Options:
 	 	 	1- LOW_LEVEL
 	 	 	2- ON_CHANGE
 	 	 	3- FALLING_EDGE
 	 	 	4- RISING_EDGE		*/
#define INT1_SENSE	LOW_LEVEL

/*	Options:
 	 	 	1- ENABLED
 	 	 	2- DISABLED		*/
#define INT1_INITIAL_STATE	DISABLED
/**************************************************************************/
/*********************************INT2*************************************/
/*	Options:
 	 	 	1- FALLING_EDGE
 	 	 	2- RISING_EDGE		*/
#define INT2_SENSE	RISING_EDGE

/*	Options:
 	 	 	1- ENABLED
 	 	 	2- DISABLED		*/
#define INT2_INITIAL_STATE	DISABLED
/**************************************************************************/
#endif
