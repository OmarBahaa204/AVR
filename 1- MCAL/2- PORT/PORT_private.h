/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : MCAl           *********************/
/**********************      SWC     : PORT            *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 29/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/

#ifndef _PORT_PRIVATE_H
#define _PORT_PRIVATE_H

#define INPUT     0
#define OUTPUT    1
#define HIGH      1
#define LOW       0

#define CONC(p7,p6,p5,p4,p3,p2,p1,p0)           CONC_HELPER(p7,p6,p5,p4,p3,p2,p1,p0)
#define CONC_HELPER(p7,p6,p5,p4,p3,p2,p1,p0)    (0b##p7##p6##p5##p4##p3##p2##p1##p0)
/*Direction*/
#define PORTA_DIR                               CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR                               CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR                               CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR                               CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)
/*Initial Value*/
#define PORTA_INITIAL_VALUE                     CONC(PORTA_PIN7_INITIAL_VALUE,PORTA_PIN6_INITIAL_VALUE,PORTA_PIN5_INITIAL_VALUE,PORTA_PIN4_INITIAL_VALUE,PORTA_PIN3_INITIAL_VALUE,PORTA_PIN2_INITIAL_VALUE,PORTA_PIN1_INITIAL_VALUE,PORTA_PIN0_INITIAL_VALUE)
#define PORTB_INITIAL_VALUE                     CONC(PORTB_PIN7_INITIAL_VALUE,PORTB_PIN6_INITIAL_VALUE,PORTB_PIN5_INITIAL_VALUE,PORTB_PIN4_INITIAL_VALUE,PORTB_PIN3_INITIAL_VALUE,PORTB_PIN2_INITIAL_VALUE,PORTB_PIN1_INITIAL_VALUE,PORTB_PIN0_INITIAL_VALUE)
#define PORTC_INITIAL_VALUE                     CONC(PORTC_PIN7_INITIAL_VALUE,PORTC_PIN6_INITIAL_VALUE,PORTC_PIN5_INITIAL_VALUE,PORTC_PIN4_INITIAL_VALUE,PORTC_PIN3_INITIAL_VALUE,PORTC_PIN2_INITIAL_VALUE,PORTC_PIN1_INITIAL_VALUE,PORTC_PIN0_INITIAL_VALUE)
#define PORTD_INITIAL_VALUE                     CONC(PORTD_PIN7_INITIAL_VALUE,PORTD_PIN6_INITIAL_VALUE,PORTD_PIN5_INITIAL_VALUE,PORTD_PIN4_INITIAL_VALUE,PORTD_PIN3_INITIAL_VALUE,PORTD_PIN2_INITIAL_VALUE,PORTD_PIN1_INITIAL_VALUE,PORTD_PIN0_INITIAL_VALUE)

#endif