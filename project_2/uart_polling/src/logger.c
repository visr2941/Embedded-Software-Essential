#include "uart.h"
#include "data.h"
#include "logger.h"

log_data - Takes a pointer to sequence of bytes and length of bytes to log
● log_string - Takes a c-string and logs that to the terminal
● log_integer - Takes an integer and logs that to the terminal (use itoa)
● log_flush - Blocks until the current logger buffer is empty




void log_data(uint8_t * dataptr, uint16_t length)
{
	int n = 0;
	while(n<length)
	{	
		buffer_add(tx_buf, *dataptr++);
		n++;
	}
	n=0;
	while(n<length)
	{
		uart_send_byte(buffer_peak(tx_buf, n));
		n++;
	}	
}

void log_string(uint8_t * str)
{
	uint16_t length = 0;
	while(*str++!='\0')
		length++;
	uart_send_byte_n(str, length);
}

void log_integer(uint16_t data)
{
	uint8_t * str;
	my_itoa(str, data, 10);
	log_string(str);
}

void log_flush()
{

}
