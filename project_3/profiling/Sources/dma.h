/*
 * dma.h
 *
 *  Created on: Apr 8, 2017
 *      Author: vishal
 */

#ifndef SOURCES_DMA_H_
#define SOURCES_DMA_H_
#include "main.h"

uint8_t memmove_dma(uint8_t * src_addr, uint8_t * dst_addr, size_t length);
uint8_t memzero_dma(uint8_t * addr, size_t length);


#endif /* SOURCES_DMA_H_ */
