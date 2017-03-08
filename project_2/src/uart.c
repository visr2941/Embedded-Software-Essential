#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "uart.h"


#define CLK_DIVIDE 16
#define BUS_CLOCK 24000000

void uart_configure(int16_t baudrate)
{
	uint16_t div;

	/*Setting Tx and Rx Pins*/
	PORTA_PCR1 = PORT_PCR_MUX(2);   // SET PTA1 AS RX
    	PORTA_PCR2 = PORT_PCR_MUX(2);	// SET PTA1 AS TX

	/*Getting the correct baudrate for the UART0*/
	div = (BUS_CLOCK/CLK_DIVIDE)/baudrate-1;	// getting the div value to set the baud rate for UART0
	UART0_BDH = (div >> 8) & UART0_BDH_SBR_MASK;	// setting the higher byte 
    	UART0_BDL = (div & UART0_BDL_SBR_MASK);		// setting the lower byte
	
	/*Clocking*/
        SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;	// setting clock for UART0
        SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;	// setting clock for PORTA
        SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);	// setting maximum clock for UART0

	/*Configuring UART0 control register*/
        UART0_C1 |= 0x00;
        UART0_C2 |= (UART_C2_TIE_MASK|UART_C2_TE_MASK|UART_C2_RE_MASK);	// enabling Tx & Rx and INTR for TDRE
        UART0_C3 |= 0x00;
        UART0_C4 |= UART0_C4_OSR(CLK_DIVIDE-1);	// setting the oversampling ratio
        UART0_C5 |= UART0_C5_BOTHEDGE_MASK;	
	
	NVIC->ISER[0] = (1<<12);	// enable IRQ for UART0
}

void uart_send_byte(uint8_t data)
{
	while(!(UART0_S1 & UART0_S1_TDRE_MASK));
	UART0_D = data;
}


