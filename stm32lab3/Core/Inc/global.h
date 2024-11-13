/*
 * global.h
 *
 *  Created on: Nov 5, 2024
 *      Author: Fung
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"

#define INIT					1
#define AUTO_RED_NS_GREEN_EW 	2
#define AUTO_RED_NS_YELLOW_EW 	3
#define AUTO_GREEN_NS_RED_EW	4
#define AUTO_YELLOW_NS_RED_EW	5

#define MAN_MODE 	11
#define MAN_RED 	12
#define MAN_YELLOW	13
#define MAN_GREEN	14

extern int status;
extern int led_on;

extern int red_duration;
extern int yellow_duration;
extern int green_duration;
#endif /* INC_GLOBAL_H_ */
