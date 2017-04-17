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

#define START_CRITICAL() __enable_irq()
#define END_CRITICAL()	__disable_irq()


void gettime(uint8_t * str)
{
	uint32_t x = RTC_TSR;
	uint8_t hr = x/3600;
	uint8_t min = x/60;
	uint8_t sec = x%60;
	sprintf(str,"%02d:%02d:%02d", hr,min,sec);
}

int main(void)
{
	uint8_t * cur_time;
	uart_configure(57600);

	tx_buf = (CircBuf *) malloc(sizeof(CircBuf));
	rx_buf = (CircBuf *) malloc(sizeof(CircBuf));

	buffer_init(tx_buf, 100);
	buffer_init(rx_buf, 100);

	init_rtc();
	binary_logger_t * heartbeat;
	heartbeat=create_log_item(HEARTBEAT, 9);
	heartbeat->log_payload= "HEARTBEAT";
	while(1)
	{
		gettime(heartbeat->timestamp);
		LOG_ITEM(heartbeat);
	}
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
