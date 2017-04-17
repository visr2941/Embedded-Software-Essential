#include "gpio.h"

void GPIO_nrf_init()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;      // clock gating to port D
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK;       // Enable SPI0 clock
	GPIOD_PDDR|= 0x01;

	PORTD_PCR0 = PORT_PCR_MUX(0x1);    // PTD0: [SPI0_PCS0]
	PORTD_PCR1 = PORT_PCR_MUX(0x2);    // PTD1: [SPI0_SCK]
	PORTD_PCR2 = PORT_PCR_MUX(0x2);    // PTD2: [SPI0_MOSI]
	PORTD_PCR3 = PORT_PCR_MUX(0x2);    // PTD3: [SPIO_MISO]
}
