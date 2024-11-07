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
		status = AUTO_RED;
		setTimer1(500);
		break;
	case AUTO_RED:
		break;
	case AUTO_YELLOW:
		break;
	case AUTO_GREEN:
		break;
	default:
		break;
	}
}
