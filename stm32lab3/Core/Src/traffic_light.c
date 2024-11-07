/*
 * traffic_light.c
 *
 *  Created on: Nov 7, 2024
 *      Author: Fung
 */

#include "traffic_light.h"
#include "global.h"
#include "main.h"
#include "software_timer.h"


void traffic_light_run(){
	switch(status){
	case INIT:
		HAL_GPIO_WritePin(RED_NS_GPIO_Port, RED_NS_Pin, SET);
		HAL_GPIO_WritePin(RED_EW_GPIO_Port, RED_EW_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin, SET);
		HAL_GPIO_WritePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin, SET);
		HAL_GPIO_WritePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin, SET);
		status = AUTO_RED_NS_GREEN_EW;
		setTimer1(300);
		break;
	case AUTO_RED_NS_GREEN_EW:
		HAL_GPIO_WritePin(RED_NS_GPIO_Port, RED_NS_Pin, SET);
		HAL_GPIO_WritePin(RED_EW_GPIO_Port, RED_EW_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin, SET);
		if(timer1_flag == 1){
			status = AUTO_RED_NS_YELLOW_EW;
		}
		setTimer1(200);
		break;
	case AUTO_RED_NS_YELLOW_EW:
		HAL_GPIO_WritePin(RED_NS_GPIO_Port, RED_NS_Pin, SET);
		HAL_GPIO_WritePin(RED_EW_GPIO_Port, RED_EW_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin, SET);
		HAL_GPIO_WritePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin, RESET);
		if(timer1_flag == 1){
			status = AUTO_GREEN_NS_RED_EW;
		}
		setTimer1(300);
		break;
	case AUTO_GREEN_NS_RED_EW:
		HAL_GPIO_WritePin(RED_NS_GPIO_Port, RED_NS_Pin, RESET);
		HAL_GPIO_WritePin(RED_EW_GPIO_Port, RED_EW_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin, RESET);
		HAL_GPIO_WritePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin, SET);
		HAL_GPIO_WritePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin, RESET);
		if(timer1_flag == 1){
			status = AUTO_YELLOW_NS_RED_EW;
		}
		setTimer1(200);
		break;
	case AUTO_YELLOW_NS_RED_EW:
		HAL_GPIO_WritePin(RED_NS_GPIO_Port, RED_NS_Pin, RESET);
		HAL_GPIO_WritePin(RED_EW_GPIO_Port, RED_EW_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin, SET);
		HAL_GPIO_WritePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin, RESET);
		if(timer1_flag == 1){
			status = AUTO_RED_NS_GREEN_EW;
		}
		setTimer1(300);
	}
}
