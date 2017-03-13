#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "cirbuf.h"


status_e buffer_add(CircBuf * buf, int8_t data)
{
	if(buffer_full(buf)==FULL)		//if buffer is full
		return FAIL;			// return FAIL status
	else
	{
		if((buf->head != (buf->buffer)+(buf->length)-1) && buf->count!=0)	//if buffer head is not at the top most element and count!=0
			++buf->head;	//increase the head
		else if((buf->head == (buf->buffer)+(buf->length)-1) && buf->count!=0)
			buf->head = buf->buffer;	//if head is at the top of buffer, set head equal start of buffer
		
		*(buf->head) = data;
		(buf->count)++;		//increase the count
	}
	return SUCCESS;
}


status_e buffer_remove(CircBuf * buf)
{
	if(buffer_empty(buf)==EMPTY)	//if buffer is empty
		return FAIL;		//return fail
	else
	{
		*(buf->tail) = 0x0;	//nullify the value
		if((buf->tail != (buf->buffer)+(buf->length)-1) && buf->count!=0)	//if buffer tail is not at the top
			buf->tail++;		//increase the tail
		else if ((buf->tail == (buf->buffer)+(buf->length)-1) && buf->count!=0)	//if buffer tail is at top and count!=0
			buf->tail = buf->buffer;	//and make tail point to start of buffer
		(buf->count)--;	//decrease the count
	}
	return SUCCESS;
}


status_e buffer_full(CircBuf * buf)
{
	if(buf->count==buf->length)	//if buffer count is equal to length
		return FULL;		//return full
	else
		return NOT_FULL;
}


status_e buffer_empty(CircBuf * buf)
{
	if(buf->count==0)		//if buf-> count equal to zero
		return EMPTY;		//return empty
	else
		return NOT_EMPTY;
}


int8_t buffer_peak(CircBuf * buf, uint16_t n)
{
	if(buffer_empty(buf)==EMPTY)	//if bufffer is empty
		return 0x0;		//return empty flag
	else
	{
		if(buf->tail+(n-1) <= buf->buffer+buf->length && n<=buf->count)
			return *(buf->tail+(n-1));	//else return the nth element counted from head
		else if (n<=buf->count)
			return *(buf->buffer + ((int16_t) (buf->tail+n-1) % buf->length));
		else
			return 0x0;
	}
}


status_e buffer_init(CircBuf * buf, uint16_t noBytes)
{
	if((buf->buffer = (uint8_t *) malloc(noBytes*sizeof(uint16_t)))==NULL)	//allocate memory of given size
		return FAIL;	//and if memory is not allocated, return failure
	buf->head = buf->buffer;	//set buf->head to point the buffer start
	buf->tail = buf->buffer;	//set buf->tail to point the buffer start
	buf->count = 0;		//initialize buffer->count to 0
	buf->length = noBytes;	//set buf->length to noBytes 
	return SUCCESS;
}


status_e buffer_destroy(CircBuf * buf)
{
	free(buf->buffer);	//free the memory pointed through buf->pointer
	buf->buffer = NULL;	//setting it to null
	buf->head = NULL;	//setting head pointer to null
	buf->tail = NULL;	//setting tail pointer to null
}

