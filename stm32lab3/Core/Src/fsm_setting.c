/*
 * fsm_setting.c
 *
 *  Created on: Nov 6, 2024
 *      Author: Fung
 */

#include "fsm_setting.h"

int temp_red = red_duration;
int temp_yellow = yellow_duration;
int temp_green = green_duration;

void fsm_setting_run(){
	switch(status){
	case MAN_RED:
		if(isButtonPressed(1) == 1){
			temp_red++;
			if(temp_red >= 100){
				temp_red = red_duration;
			}
		}
		if(isButtonPressed(2) == 1){
			red_duration = temp_red;
			yellow_duration = temp_yellow;
			green_duration = temp_green;
		}
	case MAN_YELLOW:
		if(isButtonPressed(1) == 1){
			temp_yellow++;
			if(temp_yellow >= 100){
				temp_yellow = yellow_duration;
			}
		}

		}
		if(isButtonPressed(2) == 1){
			red_duration = temp_red;
			yellow_duration = temp_yellow;
			green_duration = temp_green;
		}
	case MAN_GREEN:
		if(isButtonPressed(1) == 1){
			temp_green ++;
		}
		if(isButtonPressed(2) == 1){
			red_duration = temp_red;
			yellow_duration = temp_yellow;
			green_duration = temp_green;
		}
	}
}
