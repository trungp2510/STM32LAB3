/*
 * fsm_manual.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Fung
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
		case MAN_MODE:
			clear_traffic_light();
			status = MAN_RED;
			setTimer2(25);
		case MAN_RED:
			if(timer2_flag == 1){
				if(led_on == 0){
					led_on = 1;
					HAL_GPIO_WritePin(RED_NS_GPIO_Port, RED_NS_Pin,SET);
					HAL_GPIO_WritePin(RED_EW_GPIO_Port, RED_EW_Pin,SET);
				}else{
					clear_traffic_light();
					led_on = 0;
				}
				setTimer2(25);
			}
			if(isButtonPressed(0) == 1){
				status = MAN_YELLOW;
				clear_traffic_light();
			}
			break;
		case MAN_YELLOW:
			if(timer2_flag == 1){
				if(led_on == 0){
					led_on = 1;
					HAL_GPIO_WritePin(YELLOW_NS_GPIO_Port, YELLOW_NS_Pin,SET);
					HAL_GPIO_WritePin(YELLOW_EW_GPIO_Port, YELLOW_EW_Pin,SET);
				}else{
					clear_traffic_light();
					led_on = 0;
				}
				setTimer2(25);
			}
			if(isButtonPressed(0) == 1){
				status = MAN_GREEN;
				clear_traffic_light();
			}
			break;
		case MAN_GREEN:
			if(timer2_flag == 1){
				if(led_on == 0){
					led_on = 1;
					HAL_GPIO_WritePin(GREEN_NS_GPIO_Port, GREEN_NS_Pin,SET);
					HAL_GPIO_WritePin(GREEN_EW_GPIO_Port, GREEN_EW_Pin,SET);
				}else{
					clear_traffic_light();
					led_on = 0;
				}
				setTimer2(25);
			}
			if(isButtonPressed(0) == 1){
				status = INIT;
				clear_traffic_light();
			}
			break;
		default:
			break;
	}
}
