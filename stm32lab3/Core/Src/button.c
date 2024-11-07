/*
 * button.c
 *
 *  Created on: Nov 3, 2024
 *      Author: Fung
 */

#include "button.h"
#include "main.h"

int keyReg0 = NORMAL_STATE;
int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;

int keyReg3 = NORMAL_STATE;
int TimeForKeyPress = 200;
int button1_flag = 0;

int isButtonPressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(){
	button1_flag = 1;
}

void getKeyInput(){
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port,BUTTON1_Pin);
	if((keyReg0 == keyReg1) && (keyReg1 == keyReg2)){
		if(keyReg3 != keyReg2){
			keyReg3 = keyReg2;
			if(keyReg2 == PRESSED_STATE){
				subKeyProcess();
				TimeForKeyPress = 200;
			}
		}
		else{
			TimeForKeyPress--;
			if(TimeForKeyPress == 0){
				subKeyProcess();
				TimeForKeyPress = 200;
			}
		}
	}

}
