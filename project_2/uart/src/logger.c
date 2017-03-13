#include "uart.h"
#include "data.h"
#include "logger.h"

void log_data(uint8_t * dataptr, uint16_t length)
{
	uint8_t n = 0;
	while(n++<length)
		buffer_add(tx_buf, *dataptr++);
	n=1;
	while(n<length)
	{
		uart_send_byte(buffer_peak(tx_buf, n));
		n++;
	}
}

void log_string(uint8_t * str)
{
	uint8_t n = 1;
	while(*str!='\0')
		buffer_add(tx_buf, *str++);
	
	buffer_add(tx_buf, '\0');
	while(1)
	{
		if(buffer_peak(tx_buf, n)=='\0')
			break;
		uart_send_byte(buffer_peak(tx_buf, n));
		n++;
	}
}

void log_integer(int8_t data)
{
	uint8_t str[5];
	my_itoa(str, data, 10);
	log_string(str);
}

void log_flush()
{
	while(buffer_empty()!=EMPTY)
	{	
		log_integer(buffer_peak(tx_buf, n));
		n++;
	}
}


