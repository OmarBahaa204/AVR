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
/****************************** Includes **********************************/
/******************************          **********************************/
/**************************************************************************/
#include "..\..\4- LIB\STD_TYPES.h"
#include "..\..\4- LIB\STD_ERRORS.h"
#include "..\..\4- LIB\BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_Config.h"
#include "ADC_private.h"
#include "ADC_register.h"


#define ADC_PRESCALER_MASK			0b11111000
#define ADC_CHANNEL_MASK			0b11100000
#define ADC_SFIOR_MASK				0b00011111
#define HIGH						1
#define LOW							0
#define NUMBER_OF_SHEFTED_BITS		5
/**************************************************************************/
/**************************                       *************************/
/**************************    Global Variables   *************************/
/**************************                       *************************/
/**************************************************************************/

/*used static as we wont use it out of this file*/
static u16 *ADC_pu16Reading = NULL;
static void (*ADC_pvCallBackNotificationFunc)(void) = NULL;
static u8 ADC_u8BusyState = IDLE ;
/**************************************************************************/
/**************************                       *************************/
/************************** Function declarations *************************/
/**************************                       *************************/
/**************************************************************************/
void MADC_voidInit(void)
{
	/*Select REFS1:0 to Reference Voltage*/
#if VOLTAGE_REFERANCE == AVCC
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#elif VOLTAGE_REFERANCE == AREF_PIN
	CLR_BIT(ADMUX,ADMUX_REFS1);
	CLR_BIT(ADMUX,ADMUX_REFS0);
#elif VOLTAGE_REFERANCE == INTERNAL_VOLTAGE_REFERANCE
	SET_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#else
#error "Wrong VOLTAGE_REFERANCE From Configuration of ADC"
#endif

	/*Select ADLAR : ADC Left Adjustment result*/
#if DATA_ADJUSTMENT	== LEFT_ADJUST
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif DATA_ADJUSTMENT == RIGHT_ADJUST
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "Wrong DATA_ADJUSTMENT From Configuration of ADC"
#endif

	/*Select ADPS2:0 : ADC Prescaler Select Bits*/
	ADCSRA &= ADC_PRESCALER_MASK;
	ADCSRA |= PRESCALER;

#if AUTO_TRIGGER == ENABLE
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	SFIOR &= ADC_SFIOR_MASK;
	SFIOR |= (AUTO_TRIGGER_SOURCE<<NUMBER_OF_SHEFTED_BITS);
	SET_BIT(ADCSRA,ADCSRA_ADIE);
#elif AUTO_TRIGGER == DISABLE
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#else
#error "Wrong AUTO_TRIGGER From Configuration of ADC"
#endif

	/*SelectADEN : ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
/**************************************************************************/
u8 MADC_u8StartConversionSynch(u8 Copy_u8Channel , u16* Copy_pu16Reading)
{
	u32 Local_u32Counter = 0 ;
	u8 	Local_u8ErrorStatus = RT_OK;
	if (ADC_u8BusyState == IDLE)
	{
		ADC_u8BusyState = Busy;
		/*Time out counter*/
		/*Clear the MUX bits in the register*/
		ADMUX &= ADC_CHANNEL_MASK;
		/*Set Required Channel at MUX bits*/
		ADMUX |= Copy_u8Channel;
		/*Select ADSC : ADC Start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		/*polling until the flag is set ( conversation is complete ) or counter reach timeout*/
		while( ( GET_BIT(ADCSRA,ADCSRA_ADIF) == LOW ) && (Local_u32Counter != ADC_u32TIMEOUT   ))
		{
			Local_u32Counter ++;
		}
		if(Local_u32Counter == ADC_u32TIMEOUT)
		{
			/*Loop is broken as time out is reached*/
			Local_u8ErrorStatus = RT_NOK;
		}
		else
		{
			/*Loop is broken as flag is raised*/
			/*clearing the flag Manually*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);
			/*return digital bits 10_bit or 8_bit*/
			*Copy_pu16Reading = ADC_DATA;
		}

		ADC_u8BusyState = IDLE ;
	}

	else
	{
		Local_u8ErrorStatus = BUSY_FUNCTION;
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/
u8 MADC_u8StartConversionAsynch(u8 Copy_u8Channel , u16* Copy_pu16Reading , void (*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorStatus = RT_OK;
	if (ADC_u8BusyState == IDLE)
	{
		if ( Copy_pu16Reading == NULL || Copy_pvNotificationFunc == NULL)
		{
			Local_u8ErrorStatus = RT_NOK;
		}
		else
		{
			ADC_u8BusyState = Busy ;
			/*Initialize Global reading  variable & Notification Function*/
			ADC_pu16Reading = Copy_pu16Reading ;
			ADC_pvCallBackNotificationFunc = Copy_pvNotificationFunc;

			/*Clear the MUX bits in the register*/
			ADMUX &= ADC_CHANNEL_MASK;
			/*Set Required Channel at MUX bits*/
			ADMUX |= Copy_u8Channel;
			/*Select ADSC : ADC Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*ADC interrupt Enable*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
			ADC_u8BusyState = IDLE;
		}
	}
	else
	{
		Local_u8ErrorStatus = BUSY_FUNCTION ;
	}
	return Local_u8ErrorStatus;
}

/*****************ISR Function When Conversion Complete*********************/
void __vector_16 (void)  __attribute__((signal));
void __vector_16 (void)
{
	/*After Conversion is finished*/
	*ADC_pu16Reading = ADC_DATA;
	/*Invoke Callback notification Function*/
	ADC_pvCallBackNotificationFunc();
	/*Disable ADC IE*/
	CLR_BIT(ADCSRA,ADCSRA_ADIE);
}
/**************************************************************************/
u8 MADC_u8SellectPrescaller(u8 Copy_u8Prescaler)
{
	u8 Local_u8ErrorStatus = RT_OK;
	if(Copy_u8Prescaler <= DIVISION_BY_128 )
	{
		/*Select ADPS2:0 : ADC Prescaler Select Bits*/
		ADCSRA &= ADC_PRESCALER_MASK;
		ADCSRA |= Copy_u8Prescaler;
	}
	else
	{
		Local_u8ErrorStatus = RT_NOK;
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/
u8 MADC_u8SellectReferenceVolt(u8 Copy_u8Refference)
{
	u8 Local_u8ErrorStatus = RT_OK;
	/*Select REFS1:0 to Reference Voltage*/
	if(Copy_u8Refference == AVCC)
	{
		CLR_BIT(ADMUX,ADMUX_REFS1);
		SET_BIT(ADMUX,ADMUX_REFS0);
	}
	else if (Copy_u8Refference == AREF_PIN)
	{
		CLR_BIT(ADMUX,ADMUX_REFS1);
		CLR_BIT(ADMUX,ADMUX_REFS0);
	}
	else if (Copy_u8Refference == INTERNAL_VOLTAGE_REFERANCE)
	{
		SET_BIT(ADMUX,ADMUX_REFS1);
		SET_BIT(ADMUX,ADMUX_REFS0);
	}
	else
	{
		Local_u8ErrorStatus = RT_NOK;
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/
void MADC_voidEnable(void)
{
	/*SelectADEN : ADC Enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
/**************************************************************************/
void MADC_voidDisable(void)
{
	/*SelectADEN : ADC Enable*/
	CLR_BIT(ADCSRA,ADCSRA_ADEN);
}
/**************************************************************************/
void MADC_voidStartConverssion(void)
{
	/*Select ADSC : ADC Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
}
/**************************************************************************/
