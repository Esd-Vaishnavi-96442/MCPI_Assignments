/*
 * switch.c
 *
 *  Created on: 18-Mar-2026
 *      Author: sunbeam
 */
#include<switch.h>

void switch_init(uint8_t pin)
{
	// clock enable for LED GPIO
		RCC->AHB1ENR |= BV(GPIOA_CLK_EN);
		// select mode as output
		// pin 12	-->	25 & 24		-->	pin * 2 + 1 & pin * 2
		SWITCH_GPIO->MODER &= ~(BV(pin * 2) | BV(pin * 2 + 1));

		// disable pull up/down
		SWITCH_GPIO->PUPDR &= ~(BV(pin * 2) | BV(pin * 2 + 1));
}

uint8_t switch_status(uint8_t pin)
{
	return SWITCH_GPIO->IDR & BV(pin) ? 1 : 0;
}


