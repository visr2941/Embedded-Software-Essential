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

#include "MKL25Z4.h"
#include "dma.h"
#include "memory.h"

#define gettime() (TPM0_CNT)


uint32_t loop;
void timer_init(void)
{
	SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;	//clocking the TPM0 module

	SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);	//selecting MCGFLLCLK clock for TPM counter

	TPM0_MOD = 0x100;	//putting value for 50ms interrupt

	NVIC_EnableIRQ(TPM0_IRQn);	//enabling interrupt

	/*setting TPM0 Module*/
	TPM0_SC |= (TPM_SC_TOIE_MASK | TPM_SC_CMOD(1));
}

int main(void)
{
	uint32_t start_time=0, end_time=0, loop_cal_start, loop_cal_end, loop_cal, time;
	uint8_t ar1[1050]={0x32,0x33,0x34,0x35,0x36,0x37,0x38};
	//uint8_t ar2[7]={0,0,0,0,0,0};

	/*Setting MCGIRCLK value*/
	timer_init();

	loop_cal_start = loop;
	start_time = gettime();
	my_memmove(ar1, ar1+2, 1000);
	//memzero_dma(ar1, 2000);
	//memmove_dma(ar1,ar1+2,2000);
	//memmove(ar1+2,ar1,7);
	loop_cal_end = loop;
	end_time = gettime();
	if(end_time > start_time)
		time = end_time - start_time;
	else
		time = start_time - end_time;
	loop_cal = loop_cal_end - loop_cal_start;
}

void TPM0_IRQHandler (void)
{
	loop++;
	TPM0_SC |= TPM_SC_TOF_MASK;
}
