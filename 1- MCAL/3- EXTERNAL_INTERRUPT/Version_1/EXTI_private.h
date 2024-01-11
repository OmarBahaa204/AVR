/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : MCAl           *********************/
/**********************      SWC     : EXTI           *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 06/01/2024     *********************/
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/
/******************************          **********************************/
/******************************File Guard**********************************/
/******************************          **********************************/
/**************************************************************************/
#ifndef _EXTI_PRIVATE_H
#define _EXTI_PRIVATE_H

/* Sense Control Variations for INT1 | INT0 */
//Low Level
#define SENSE_CTRL0_LOW_LEVEL				0
#define SENSE_CTRL1_LOW_LEVEL				0
//On change
#define SENSE_CTRL0_ON_CHANGE				1
#define SENSE_CTRL1_ON_CHANGE				0
//falling Edge
#define SENSE_CTRL0_FALLING_EDGE			0
#define SENSE_CTRL1_FALLING_EDGE			1
//Rising Edge
#define SENSE_CTRL0_RISING_EDGE				1
#define SENSE_CTRL1_RISING_EDGE				1

/* Sense Control Variations for INT2 */
//falling Edge
#define INT2_SENSE_CTRL_FALLING_EDGE		0
//Rising Edge
#define INT2_SENSE_CTRL_RISING_EDGE			1

#endif
