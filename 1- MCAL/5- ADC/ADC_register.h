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
#ifndef _ADC_REGISTER_H_
#define _ADC_REGISTER_H_
/**************************************************************************/
/******************************           *********************************/
/****************************** Registers *********************************/
/******************************           *********************************/
/**************************************************************************/

#define ADMUX           *((volatile u8*)0x27)               //ADC Multiplixer Sellection Regisrer
#define ADMUX_REFS1     7                                   //Refrence Seleection Bit1
#define ADMUX_REFS0     6                                   //Refrence Seleection Bit0
#define ADMUX_ADLAR     5                                   //ADC Left Adgusment result
#define ADMUX_MUX4      4                                   //Analog channel & gain sellection Bit4
#define ADMUX_MUX3      3                                   //Analog channel & gain sellection Bit3
#define ADMUX_MUX2      2                                   //Analog channel & gain sellection Bit2
#define ADMUX_MUX1      1                                   //Analog channel & gain sellection Bit1
#define ADMUX_MUX0      0                                   //Analog channel & gain sellection Bit0

#define ADCSRA          *((volatile u8*)0x26)               //ADC Control & Status register A
#define ADCSRA_ADEN     7                                   //ADC Enable
#define ADCSR_ADSC      6                                   //ADC Start Conversion
#define ADCSR_ADATE     5                                   //ADC Auto Trigger Enable
#define ADCSR_ADIF      4                                   //ADC Interrupt flag
#define ADCSR_ADIE      3                                   //ADC Interrupt Enable
#define ADCSR_ADPS2     2                                   //ADC Prescaller Sellection Bit2
#define ADCSR_ADPS1     1                                   //ADC Prescaller Sellection Bit1
#define ADCSR_ADPS0     0                                   //ADC Prescaller Sellection Bit0


#define ADCH            *((volatile u8*)0x25)               //ADC Data Register High Byte
#define ADCL            *((volatile u8*)0x24)               //ADC Data Register Low Byte

#define SFIOR           *((volatile u8*)0x50)               //ADC Special Function IO Register      
#define SFIOR_ADTS2     7                                   //ADC Auto Trigger source bit2
#define SFIOR_ADTS1     6                                   //ADC Auto Trigger source bit1      
#define SFIOR_ADTS0     5                                   //ADC Auto Trigger Source bit0

#endif
