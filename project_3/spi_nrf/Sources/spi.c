#include "spi.h"

void SPI_init()
{
  /* SPI0 register for master */
  SPI0_C1 = (SPI_C1_SSOE_MASK | SPI_C1_MSTR_MASK);
  SPI0_C2 |= SPI_C2_MODFEN_MASK;   //Master SS pin acts as slave select output
  SPI0_BR |= (SPI_BR_SPPR(0x02) | SPI_BR_SPR(0x06)); // 2 mbps
  SPI0_C1 |= SPI_C1_SPE_MASK;    //Enable SPI0
}

void SPI_write_byte(uint8_t byte)
{
	while(!(SPI_S_SPTEF_MASK & SPI0_S)); //wait for buffer getting empty
	SPI0_D = byte;    //send data
}

uint8_t SPI_read_byte()
{
	uint8_t data;

	while(!(SPI_S_SPRF_MASK & SPI0_S));	//wait for buffer getting empty
	data = SPI0_D;    //read data from SPI
	return data;
}

void SPI_send_packet(uint8_t* p, size_t length)
{
	while(length--)
		SPI_write_byte(*p++);
}

void SPI_flush()
{
	SPI0_C1 &= 0xBF;
	SPI_init();
}
