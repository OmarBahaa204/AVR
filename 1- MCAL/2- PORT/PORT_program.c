/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : MCAl           *********************/
/**********************      SWC     : PORT            *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 29/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/

#include "..\..\4- LIB\STD_TYPES.h"
#include "PORT_Config.h"
#include "PORT_private.h"
#include "PORT_register.h"
#include "PORT_interface.h"

void MPORT_voidInit(void)
{
      /*Directions*/
      DDRA = PORTA_DIR ;
      DDRB = PORTB_DIR ;
      DDRC = PORTC_DIR ;
      DDRD = PORTD_DIR ;
      /*Initial Values*/
      PORTA = PORTA_INITIAL_VALUE;
      PORTB = PORTB_INITIAL_VALUE;
      PORTC = PORTC_INITIAL_VALUE;
      PORTD = PORTD_INITIAL_VALUE;
}
