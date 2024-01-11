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
#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H

/**************************************************************************/
/*Options :
 	 	 	1- AREF_PIN
 	 	 	2- AVCC
 	 	 	3- INTERNAL_VOLTAGE_REFERANCE	*/
#define VOLTAGE_REFERANCE		AVCC
/**************************************************************************/
/*Options :
 	 	 	1- LEFT_ADJUST
 	 	 	2- RIGHT_ADJUST			*/
#define DATA_ADJUSTMENT			LEFT_ADJUST
/**************************************************************************/
/*Options :
 	 	 	1- DIVISION_BY_2
 	 	 	2- DIVISION_BY_4
 	 	 	3- DIVISION_BY_8
 	 	 	4- DIVISION_BY_16
 	 	 	5- DIVISION_BY_32
 	 	 	6- DIVISION_BY_64
 	 	 	7- DIVISION_BY_128			*/
#define PRESCALER 				DIVISION_BY_128
/**************************************************************************/
/*Options :
 	 	 	1- ENABLE
 	 	 	2- DISABLE		*/
#define AUTO_TRIGGER	DISABLE
/**************************************************************************/
/*Options :
 	 	 	1- FREE_RUNNING
 	 	 	2- ANALOG_COMPARATOR
 	 	 	3- EXTI_INT0
 	 	 	4- TIMER0_COMPARE_MATCH
 	 	 	5- TIMER0_OVERFLOW
 	 	 	6- TIMER0_COMPARE_MATCH_B
 	 	 	7- TIMER1_OVERFLOW
 	 	 	8- TIMER1_CAPTURE_EVENT			*/
#define AUTO_TRIGGER_SOURCE		FREE_RUNNING
#endif
