/*
 * control_layer.h
 *
 *  Created on: Apr 30, 2017
 *      Author: vishal
 */

#ifndef SOURCES_CONTROL_LAYER_H_
#define SOURCES_CONTROL_LAYER_H_

#include "main.h"
#define MAX_SIZE 10
#define RED		18
#define BLUE	1
#define GREEN	19
#define LED_ON(led)	led_on(led)
#define LED_OFF(led) led_off(led)
#define INC_BRIGHT(led)	inc_brightness(led)
#define DEC_BRIGHT(led)	dec_brightness(led)
#define GET_RTC_TIME(str) get_rtc_time(str)

typedef enum Command {LED_ON, LED_OFF, CONFIG_PWM, INC_BRIGHT, DEC_BRIGHT, SOFT_RESET, CONFIG_RTC, GET_TIME} CMD;	  //commands enumeration

/* Structure to Store Command Message */
typedef struct {
	CMD command;			// command
	uint8_t length;			// size of the message
	uint8_t data[MAX_SIZE];			// pay-load
	uint16_t checksum;		// checksum value
} CMD_msg;

void led_on(uint8_t led);
void led_off(uint8_t led);
void gpio_init_led();
void pwm_config();
void inc_brightness(uint8_t led);
void dec_brightness(uint8_t led);
void get_rtc_time(uint8_t * str);


#endif /* SOURCES_CONTROL_LAYER_H_ */
