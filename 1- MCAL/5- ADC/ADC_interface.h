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
#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_
/**************************************************************************/
/******************************           *********************************/
/******************************definitions*********************************/
/******************************           *********************************/
/**************************************************************************/
#define ADC_CHANNEL_0 	                	0
#define ADC_CHANNEL_1 	                	1
#define ADC_CHANNEL_2 	                	2
#define ADC_CHANNEL_3 	                	3
#define ADC_CHANNEL_4 	                	4
#define ADC_CHANNEL_5 	                	5
#define ADC_CHANNEL_6 	                	6
#define ADC_CHANNEL_7 	                	7

#define DIVISION_BY_2						0
#define DIVISION_BY_4						2
#define DIVISION_BY_8						3
#define DIVISION_BY_16						4
#define DIVISION_BY_32						5
#define DIVISION_BY_64						6
#define DIVISION_BY_128						7

#define AREF_PIN							0
#define AVCC								1
#define INTERNAL_VOLTAGE_REFERANCE			3
/**************************************************************************/
/****************************                   ***************************/
/****************************Function Proto_Type***************************/
/****************************                   ***************************/
/**************************************************************************/
/*Function with Prebuild Configuration of :
											1- Reference voltage selection
											2- Data Adjustment direction
											3- Prescaler Bits
											4- Auto trigger Enable/Disable
											 4a-Select Auto trigger Source
											5- Interrupt Enable/disable
											6- Enable ADC peripheral			*/
void MADC_voidInit(void);
/**************************************************************************/
/*Options :
            1-ADC_CHANNEL_0
            2-ADC_CHANNEL_1
            3-ADC_CHANNEL_2
            4-ADC_CHANNEL_3
            5-ADC_CHANNEL_4
            6-ADC_CHANNEL_5
            7-ADC_CHANNEL_6
            8-ADC_CHANNEL_7
            */
u8 MADC_u8StartConversionSynch(u8 Copy_u8Channel , u16* Copy_pu16Reading);
/**************************************************************************/
/*Options : before calling this function first we must Enable GIE
            1-ADC_CHANNEL_0
            2-ADC_CHANNEL_1
            3-ADC_CHANNEL_2
            4-ADC_CHANNEL_3
            5-ADC_CHANNEL_4
            6-ADC_CHANNEL_5
            7-ADC_CHANNEL_6
            8-ADC_CHANNEL_7
            */
u8 MADC_u8StartConversionAsynch(u8 Copy_u8Channel , u16* Copy_pu16Reading , void (*Copy_pvNotificationFunc)(void));
/**************************************************************************/
/*Options :
 	 	 	1- DIVISION_BY_2
 	 	 	2- DIVISION_BY_4
 	 	 	3- DIVISION_BY_8
 	 	 	4- DIVISION_BY_16
 	 	 	5- DIVISION_BY_32
 	 	 	6- DIVISION_BY_64
 	 	 	7- DIVISION_BY_128			*/
//Function with Post Configuration of Prescaller
u8 MADC_u8SellectPrescaller(u8 Copy_u8Prescaler);
/**************************************************************************/

/*Options :
 	 	 	1- AREF_PIN
 	 	 	2- AVCC
 	 	 	3- INTERNAL_VOLTAGE_REFERANCE	*/
u8 MADC_u8SellectReferenceVolt(u8 Copy_u8Refference);
/**************************************************************************/
void MADC_voidEnable(void);
void MADC_voidDisable(void);
/**************************************************************************/
void MADC_voidStartConverssion(void);
/**************************************************************************/
#endif


