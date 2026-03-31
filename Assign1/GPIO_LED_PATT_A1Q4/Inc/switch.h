/*
 * switch.h
 *
 *  Created on: 18-Mar-2026
 *      Author: sunbeam
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include<stm32f407xx.h>

#define BV(n)	(1<<(n))

#define GPIOA_CLK_EN	0

#define SWITCH_GPIO		GPIOA
#define SWITCH_PIN		0

void switch_init(uint8_t pin);
uint8_t switch_status(uint8_t pin);




#endif /* SWITCH_H_ */
