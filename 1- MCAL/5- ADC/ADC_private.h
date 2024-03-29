/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : MCAl           *********************/
/**********************      SWC     : ADC            *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 09/01/2024     *********************/
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/
/******************************          **********************************/
/******************************File Guard**********************************/
/******************************          **********************************/
/**************************************************************************/
#ifndef _ADC_PRIVATE_H
#define _ADC_PRIVATE_H

/***********************Options of Data Adjustment*************************/
#define LEFT_ADJUST							0
#define RIGHT_ADJUST						1
/**************************************************************************/
#define ENABLE								0
#define DISABLE								1
/*********************Options of auto Trigger source***********************/
#define FREE_RUNNING             			0
#define ANALOG_COMPARATOR        			1
#define EXTI_INT0                			2
#define TIMER0_COMPARE_MATCH     			3
#define TIMER0_OVERFLOW          			4
#define TIMER0_COMPARE_MATCH_B   			5
#define TIMER1_OVERFLOW          			6
#define TIMER1_CAPTURE_EVENT				7
/**************************Options of Resolution***************************/
#if DATA_ADJUSTMENT == RIGHT_ADJUST
#define RESOLUTION_8_BIT					ADCL
#elif DATA_ADJUSTMENT == LEFT_ADJUST
#define RESOLUTION_8_BIT					ADCH
#endif
#define RESOLUTION_10_BIT					ADCL
/**************************************************************************/
#define IDLE			0
#define Busy			1
/**************************************************************************/
#endif
