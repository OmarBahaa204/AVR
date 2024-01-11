/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : HAL            *********************/
/**********************      SWC     : Stepper Motor  *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 03/01/2024     *********************/
/**************************************************************************/
/**************************************************************************/
/**************************************************************************/


/**************************************************************************/
/******************************          **********************************/
/****************************** Includes **********************************/
/******************************          **********************************/
/**************************************************************************/
#include "../../4- LIB/BIT_MATH.h"
#include "../../4- LIB/STD_ERRORS.h"
#include "../../4- LIB/STD_TYPES.h"
#include "HStepperMotor_interface.h"
#include "HStepperMotor_configuration.h"
#include "HStepperMotor_private.h"
#include "../../1- MCAL/1-DIO/DIO_interface.h"
#include "util/delay.h"

/**************************************************************************/
/**************************                       *************************/
/************************** Function declarations *************************/
/**************************                       *************************/
/**************************************************************************/

u8 HStepper_u8TurnOn(u8 Copy_u8Direction)
{
	u8 Local_u8StatusError = RT_OK;

	switch(Copy_u8Direction)
	{
	case CLOCK_WISE_DIRECTION:
	{
		/*Activate Orange wire*/
		DIO_u8SetPinValue(Stepper_PORT,BLUE_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,PINK_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,YELLOW_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,ORANGE_WIRE_CTRL,DIO_u8PIN_LOW);
		_delay_ms(2);
		/*Activate Yellow wire*/
		DIO_u8SetPinValue(Stepper_PORT,BLUE_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,PINK_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,YELLOW_WIRE_CTRL,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Stepper_PORT,ORANGE_WIRE_CTRL,DIO_u8PIN_HIGH);
		_delay_ms(2);
		/*Activate Pink wire*/
		DIO_u8SetPinValue(Stepper_PORT,BLUE_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,PINK_WIRE_CTRL,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Stepper_PORT,YELLOW_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,ORANGE_WIRE_CTRL,DIO_u8PIN_HIGH);
		_delay_ms(2);
		/*Activate blue wire*/
		DIO_u8SetPinValue(Stepper_PORT,BLUE_WIRE_CTRL,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Stepper_PORT,PINK_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,YELLOW_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,ORANGE_WIRE_CTRL,DIO_u8PIN_HIGH);
		_delay_ms(2);
	}break;
	case COUNTER_CLOCK_WISE_DIRECTION :
	{
		/*Activate blue wire*/
		DIO_u8SetPinValue(Stepper_PORT,BLUE_WIRE_CTRL,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Stepper_PORT,PINK_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,YELLOW_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,ORANGE_WIRE_CTRL,DIO_u8PIN_HIGH);
		_delay_ms(2);
		/*Activate Pink wire*/
		DIO_u8SetPinValue(Stepper_PORT,BLUE_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,PINK_WIRE_CTRL,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Stepper_PORT,YELLOW_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,ORANGE_WIRE_CTRL,DIO_u8PIN_HIGH);
		_delay_ms(2);
		/*Activate Yellow wire*/
		DIO_u8SetPinValue(Stepper_PORT,BLUE_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,PINK_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,YELLOW_WIRE_CTRL,DIO_u8PIN_LOW);
		DIO_u8SetPinValue(Stepper_PORT,ORANGE_WIRE_CTRL,DIO_u8PIN_HIGH);
		_delay_ms(2);
		/*Activate Orange wire*/
		DIO_u8SetPinValue(Stepper_PORT,BLUE_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,PINK_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,YELLOW_WIRE_CTRL,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(Stepper_PORT,ORANGE_WIRE_CTRL,DIO_u8PIN_LOW);
		_delay_ms(2);
	}break;
	default : Local_u8StatusError = RT_NOK;
	}
	return Local_u8StatusError;
}
/**************************************************************************/
void HStepper_voidTurnOff(void)
{
	/*Deactivate all wires*/
	DIO_u8SetPinValue(Stepper_PORT,BLUE_WIRE_CTRL,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_PORT,PINK_WIRE_CTRL,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_PORT,YELLOW_WIRE_CTRL,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(Stepper_PORT,ORANGE_WIRE_CTRL,DIO_u8PIN_HIGH);
	_delay_ms(2);
}
/**************************************************************************/
u8 HStepper_u8DoFullRound(u8 Copy_u8Direction)
{
	u16 Local_u8Iteration;
	u8 Local_u8ErrorStatus= RT_OK;
	for (Local_u8Iteration=0;Local_u8Iteration<FULL_ROUND_ITERATIONS;Local_u8Iteration++)
	{
		switch(Copy_u8Direction)
		{
		case CLOCK_WISE_DIRECTION         : HStepper_u8TurnOn(CLOCK_WISE_DIRECTION);break;
		case COUNTER_CLOCK_WISE_DIRECTION : HStepper_u8TurnOn(COUNTER_CLOCK_WISE_DIRECTION);break;
		default : Local_u8ErrorStatus = RT_NOK;
		}
	}

	return Local_u8ErrorStatus;
}
/**************************************************************************/
u8 HStepper_u8MoveWithSpecifiedAngle(u8 Copy_u8Angle , u8 Copy_u8Direction)
{
	u16 Local_u8Iteration = 0;
	u16 Local_u8NumberOfSteps=0;
	u8 Local_u8ErrorStatus= RT_OK;

	Local_u8NumberOfSteps = (Copy_u8Angle/EACH_STEP_ANGLE)/NUMBER_OF_STEPS_IN_EACH_TURN_ON;

	for (Local_u8Iteration=0 ; Local_u8Iteration<Local_u8NumberOfSteps ; Local_u8Iteration++)
	{
		switch(Copy_u8Direction)
		{
		case CLOCK_WISE_DIRECTION         : HStepper_u8TurnOn(CLOCK_WISE_DIRECTION);break;
		case COUNTER_CLOCK_WISE_DIRECTION : HStepper_u8TurnOn(COUNTER_CLOCK_WISE_DIRECTION);break;
		default : Local_u8ErrorStatus = RT_NOK;
		}
	}
	return Local_u8ErrorStatus;
}
/**************************************************************************/
