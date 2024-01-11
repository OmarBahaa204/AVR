/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : MCAl           *********************/
/**********************      SWC     : DIO            *********************/
/**********************      Version : 2.00           *********************/
/**********************      Date    : 29/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_
/* port A registers */
#define  PORTA   *((volatile u8*)0x3b)
#define  PINA    *((volatile u8*)0X39)
/* port B registers */
#define  PORTB   *((volatile u8*)0X38)
#define  PINB    *((volatile u8*)0X36)
/* port C registers */
#define  PORTC   *((volatile u8*)0X35)
#define  PINC    *((volatile u8*)0X33)
/* port D registers */
#define  PORTD   *((volatile u8*)0X32)
#define  PIND    *((volatile u8*)0X30)
#endif
