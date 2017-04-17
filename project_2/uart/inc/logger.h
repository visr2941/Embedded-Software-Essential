#ifndef LOGGER_H
#define LOGGER_H

#include "cirbuf.h"
#include "uart.h"
#include "data.h"

#define LOG_RAW_STRING(str)	log_string(uint8_t * str)
#define LOG_INT(data)	log_integer(int8_t data)


CircBuf * tx_buf;
CircBuf * rx_buf;

buffer_init(tx_buf, 100);
buffer_init(rx_buf, 100);

void log_data(uint8_t * dataptr, uint16_t length);
void log_string(uint8_t * str);
void log_integer(int8_t data);
void log_flush();

#endif

