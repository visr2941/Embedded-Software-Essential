#ifndef LOGGER_H
#define LOGGER_H

#include "main.h"

#define LOG_RAW_STRING(str)	log_string(str)
#define LOG_RAW_INT(data)	log_integer(data)


void log_data(uint8_t * dataptr, uint16_t length);
void log_string(uint8_t * str);
void log_integer(int8_t data);
void log_flush();

#endif
