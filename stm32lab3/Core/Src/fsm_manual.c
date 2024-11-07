/*
 * fsm_manual.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Fung
 */

#include "fsm_manual.h"
#include "button.h"
void fsm_manual_run(){
	switch(status){
		case MAN_RED:
			HAL_GPIO_WritePin(RED_NS_GPIO_Port, RED_NS_Pin, SET);
			HAL_GPIO_WritePin(RED_EW_GPIO_Port, RED_EW_Pin, SET);
			HAL_GPIO_WritePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin, RESET);
			HAL_GPIO_WritePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin, RESET);
			HAL_GPIO_WritePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin, RESET);
			if(timer1_flag == 1){
				status  = AUTO_RED_NS_GREEN_EW;
				setTimer1(500);
			}
			if(isButtonPressed() == 1){
				status = MAN_GREEN;
				setTimer1(1000);
			}
			HAL_GPIO_TogglePin(RED_NS_GPIO_Port, RED_NS_Pin);
			HAL_GPIO_TogglePin(RED_EW_GPIO_Port, RED_EW_Pin);
			break;
		case MAN_GREEN:
			HAL_GPIO_WritePin(RED_NS_GPIO_Port, RED_NS_Pin, RESET);
			HAL_GPIO_WritePin(RED_EW_GPIO_Port, RED_EW_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin, RESET);
			HAL_GPIO_WritePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin, SET);
			HAL_GPIO_WritePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin, SET);
			if(timer1_flag == 1){
				status  = AUTO_RED_NS_GREEN_EW;
				setTimer1(500);
			}
			if(isButtonPressed() == 1){
				status = MAN_YELLOW;
				setTimer1(1000);
			}
			HAL_GPIO_TogglePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin);
			HAL_GPIO_TogglePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin);
			break;
		case MAN_YELLOW:
			HAL_GPIO_WritePin(RED_NS_GPIO_Port, RED_NS_Pin, RESET);
			HAL_GPIO_WritePin(RED_EW_GPIO_Port, RED_EW_Pin, RESET);
			HAL_GPIO_WritePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin, SET);
			HAL_GPIO_WritePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin, SET);
			HAL_GPIO_WritePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin, RESET);
			HAL_GPIO_WritePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin, RESET);
			if(timer1_flag == 1){
				status  = AUTO_RED_NS_GREEN_EW;
				setTimer1(500);
			}
			if(isButtonPressed() == 1){
				status = MAN_RED;
				setTimer1(1000);
			}
			HAL_GPIO_TogglePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin);
			HAL_GPIO_TogglePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin);
			break;
		default:
			break;
	}
}
