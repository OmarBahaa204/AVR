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

#define ADMUX           *((volatile u8*)0x27)               //ADC Multiplexer Selection Register
#define ADMUX_REFS1     7                                   //Reference Selection Bit1
#define ADMUX_REFS0     6                                   //Reference Selection Bit0
#define ADMUX_ADLAR     5                                   //ADC Left Adjustment result
#define ADMUX_MUX4      4                                   //Analog channel & gain Selection Bit4
#define ADMUX_MUX3      3                                   //Analog channel & gain Selection Bit3
#define ADMUX_MUX2      2                                   //Analog channel & gain Selection Bit2
#define ADMUX_MUX1      1                                   //Analog channel & gain Selection Bit1
#define ADMUX_MUX0      0                                   //Analog channel & gain Selection Bit0

#define ADCSRA          *((volatile u8*)0x26)               //ADC Control & Status register A
#define ADCSRA_ADEN     7                                   //ADC Enable
#define ADCSRA_ADSC      6                                   //ADC Start Conversion
#define ADCSRA_ADATE     5                                   //ADC Auto Trigger Enable
#define ADCSRA_ADIF      4                                   //ADC Interrupt flag
#define ADCSRA_ADIE      3                                   //ADC Interrupt Enable
#define ADCSRA_ADPS2     2                                   //ADC Prescaler Selection Bit2
#define ADCSRA_ADPS1     1                                   //ADC Prescaler Selection Bit1
#define ADCSRA_ADPS0     0                                   //ADC Prescaler Selection Bit0


#define ADCH            *((volatile u8*)0x25)               //ADC Data Register High Byte
#define ADCL            *((volatile u8*)0x24)               //ADC Data Register Low Byte

#define SFIOR           *((volatile u8*)0x50)               //ADC Special Function IO Register      
#define SFIOR_ADTS2     7                                   //ADC Auto Trigger source bit2
#define SFIOR_ADTS1     6                                   //ADC Auto Trigger source bit1      
#define SFIOR_ADTS0     5                                   //ADC Auto Trigger Source bit0

#endif
