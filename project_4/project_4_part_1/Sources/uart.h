#ifndef SOURCES_UART_H_
#define SOURCES_UART_H_
#include "cirbuf.h"


#define OSR 16
#define UART_CLOCK DEFAULT_SYSTEM_CLOCK

void uart_configure(int32_t baudrate);

void uart_send_byte(uint8_t data);

void uart_send_byte_n(uint8_t * dataptr, uint16_t length);

uint8_t uart_receive_byte();




#endif

