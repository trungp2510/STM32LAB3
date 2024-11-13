/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Fung
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
			status = AUTO_RED_NS_GREEN_EW;
			setTimer1(300);
			break;
		case AUTO_RED_NS_GREEN_EW:
			onRed_NS();
			onGreen_EW();
			if(timer1_flag == 1){
				status = AUTO_RED_NS_YELLOW_EW;
				clear_traffic_light();
				setTimer1(200);
			}
			if(isButtonPressed(0) == 1){
				status = MAN_MODE;
			}
			break;
		case AUTO_RED_NS_YELLOW_EW:
			onRed_NS();
			onYellow_EW();
			if(timer1_flag == 1){
				clear_traffic_light();
				status = AUTO_GREEN_NS_RED_EW;
				setTimer1(300);
			}
			if(isButtonPressed(0) == 1){
				status = MAN_MODE;
			}
			break;
		case AUTO_GREEN_NS_RED_EW:
			onGreen_NS();
			onRed_EW();
			if(timer1_flag == 1){
				clear_traffic_light();
				status = AUTO_YELLOW_NS_RED_EW;
				setTimer1(200);
			}
			if(isButtonPressed(0) == 1){
				status = MAN_MODE;
			}
			break;
		case AUTO_YELLOW_NS_RED_EW:
			onYellow_NS();
			onRed_EW();
			if(timer1_flag == 1){
				clear_traffic_light();
				status = AUTO_RED_NS_GREEN_EW;
				setTimer1(300);
			}
			if(isButtonPressed(0) == 1){
				status = MAN_MODE;
			}
			break;
		default:
			break;
	}
}
