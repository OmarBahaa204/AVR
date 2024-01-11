/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : MCAl           *********************/
/**********************      SWC     : DIO            *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 19/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
/* port A registers */
#define  PORTA   *((volatile u8*)0x3b)
#define  DDRA    *((volatile u8*)0X3A)             // used in PORT driver
#define  PINA    *((volatile u8*)0X39)
/* port B registers */
#define  PORTB   *((volatile u8*)0X38)
#define  DDRB    *((volatile u8*)0X37)
#define  PINB    *((volatile u8*)0X36)
/* port C registers */
#define  PORTC   *((volatile u8*)0X35)
#define  DDRC    *((volatile u8*)0X34)
#define  PINC    *((volatile u8*)0X33)
/* port D registers */
#define  PORTD   *((volatile u8*)0X32)
#define  DDRD    *((volatile u8*)0X31)
#define  PIND    *((volatile u8*)0X30)

#endif