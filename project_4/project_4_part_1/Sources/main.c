/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "main.h"
#include <stdint.h>

static int i = 0;


void uart_receive_string(uint8_t * str)
{
	uint8_t i=0;
	do
	{
		str[i] = uart_receive_byte();
		uart_send_byte(str[i++]);
	} while(str[i-1] != 13);

	str[i-1] = '\0';
	uart_send_byte_n("\n\r", 2);
}

int main(void)
{
	uart_configure(57600);
	uint8_t	arr[10] = {0};
	uint8_t * msg = "Please enter command, length, payload and checksum \n\r \
			\r (LED_ON=0, LED_OFF=1, CONFIG_PWM=2, INC_BRIGHT=3, DEC_BRIGHT=4, SOFT_RESET=5, CONFIG_RTC=6, GET_TIME=7)";
	while(1)
	{
		CMD_msg * cmd = (CMD_msg *) malloc(sizeof(CMD_msg));

		uart_send_byte_n(msg, strlen(msg));
		uart_send_byte_n("\n\r",2);

		uart_receive_string(arr);
		cmd->command = (uint8_t) my_atoi(arr);

		uart_receive_string(arr);
		cmd->length = (uint8_t) my_atoi(arr);

		uart_receive_string(arr);
		my_memmove(arr, cmd->data, strlen(arr)+1);

		uart_receive_string(arr);
		cmd->checksum = (uint8_t) my_atoi(arr);

		if(cmd->command==LED_ON)
		{
			if(!(strcmp(cmd->data, "RED")))
				LED_ON(RED);
			else if (!(strcmp(cmd->data, "GREEN")))
				LED_ON(GREEN);
			else if (!(strcmp(cmd->data, "BLUE")))
				LED_ON(BLUE);
		}
		else if (cmd->command==LED_OFF)
		{
			if(!(strcmp(cmd->data, "RED")))
				LED_OFF(RED);
			else if (!(strcmp(cmd->data, "GREEN")))
				LED_OFF(GREEN);
			else if (!(strcmp(cmd->data, "BLUE")))
				LED_OFF(BLUE);
		}
		else if (cmd->command == CONFIG_PWM)
			pwm_config();
		else if (cmd->command==INC_BRIGHT)
		{
			if(!(strcmp(cmd->data, "RED")))
				INC_BRIGHT(RED);
			else if(!(strcmp(cmd->data, "GREEN")))
				INC_BRIGHT(GREEN);
			else if(!(strcmp(cmd->data, "BLUE")))
				INC_BRIGHT(BLUE);
		}
		else if (cmd->command==DEC_BRIGHT)
		{
			if(!(strcmp(cmd->data, "RED")))
				DEC_BRIGHT(RED);
			else if(!(strcmp(cmd->data, "GREEN")))
				DEC_BRIGHT(GREEN);
			else if(!(strcmp(cmd->data, "BLUE")))
				DEC_BRIGHT(BLUE);
		}
		else if (cmd->command==SOFT_RESET)
		{
			NVIC_SystemReset();
		}
		else if (cmd->command == CONFIG_RTC)
			init_rtc();
		else if (cmd->command == GET_TIME)
		{
			GET_RTC_TIME(arr);
			uart_send_byte_n("TIME (since started): ", 22);
			uart_send_byte_n(arr, strlen(arr));
			uart_send_byte_n("\n\r", 2);
		}
	}
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
