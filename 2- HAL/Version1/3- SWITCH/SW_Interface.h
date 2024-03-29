/**************************************************************************/
/**************************************************************************/
/**********************      Author  : Omar Bahaa     *********************/
/**********************      Layer   : HAL            *********************/
/**********************      SWC     : SWITCH         *********************/
/**********************      Version : 1.00           *********************/
/**********************      Date    : 21/12/2023     *********************/
/**************************************************************************/
/**************************************************************************/
#ifndef _SW_INTERFACE_H
#define _SW_INTERFECE_H


#define SW_u8PRESSED  		0
#define SW_u8NOT_PRESSED	1

#define SW_u8PULL_UP		0
#define SW_u8PULL_DOWN		1


u8 HSW_u8GetState(u8 Copy_u8Port , u8 Copy_u8Pin ,u8 Copy_u8PullType, u8 *Copy_pu8Status);

#endif
