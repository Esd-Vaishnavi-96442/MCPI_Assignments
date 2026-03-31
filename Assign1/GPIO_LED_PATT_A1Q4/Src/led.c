/*
 * led.c
 *
 *  Created on: 18-Mar-2026
 *      Author: sunbeam
 */

#include<led.h>


void led_init(uint8_t pin)
{
	RCC -> AHB1ENR |= BV(GPIOD_CLK_EN);

	GPIOD -> MODER &= ~(BV(pin * 2 + 1));
	GPIOD -> MODER |= BV(pin * 2);

	GPIOD -> OTYPER &= ~(BV(pin));

	GPIOD -> OSPEEDR &= ~(BV(pin * 2 + 1) | BV(pin * 2));

	GPIOD -> PUPDR &= ~(BV(pin * 2 + 1) | BV(pin * 2));

}

void led_on(uint8_t pin)
{
	LED_GPIO -> ODR |= BV(pin);

}
void led_off(uint8_t pin)
{
	LED_GPIO -> ODR &= ~BV(pin);

}

void led_toggle(uint8_t pin)
{
	LED_GPIO->ODR ^= BV(pin);
}

