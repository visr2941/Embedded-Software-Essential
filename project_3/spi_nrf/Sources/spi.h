#ifndef SOURCES_SPI_H_
#define SOURCES_SPI_H_

#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include "MKL25Z4.h"




void SPI_init();
void SPI_write_byte(uint8_t byte);
uint8_t SPI_read_byte();
void SPI_send_packet(uint8_t * p, size_t length);
void SPI_flush();

#endif /* SOURCES_SPI_H_ */
