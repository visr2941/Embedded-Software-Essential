nclude <stdio.h>
#include <stdint.h>
#include "cir_buff.h"


uint8_t buffer_add(CircBuf * buf, int8_t data);
{
	if(buffer_full(buf)==FULL)		//if buffer is full
		return FAIL;			// return FAIL status
	else
	{
		if(buf->head != (buf->buffer)+(buf->length)-1)	//if buffer head is not at the top most element
			*(buf->(++head)) = data;	//increase the head and add the data
		else
		{
			buf->head = buf->buffer;	//if head is at the top of buffer, set head equal start of buffer
			*(buf->head) = data;		//add the data at head
		}
		(buf->count)++;		//increase the count
	}
	return SUCCESS;
}

uint8_t buffer_remove(CircBuf * buf);
{
	if(buffer_empty()==EMPTY)	//if buffer is empty
		return FAIL;		//return fail
	else
	{
		if(buf->tail != (buf->buffer)+(buf->length)-1)	//if buffer tail is not at the top
			*(buf->tail++) = NULL;		//make the element at tail equal to null and increase
		else
		{
			*(buf->tail) = NULL;		//if buffer tail is at top, set the element as NULL
			buf->tail = buf->buffer;	//and make tail point to start of buffer
		}
	}
	(buf->count)--;	//decrease the count
	return SUCCESS;
}

uint8_t buffer_full(CircBuf * buf);
{
	if(buf->count==buf->length)	//if buffer count is equal to length
		return FULL;		//return full
}

uint8_t buffer_empty(CircBuf * buf);
{
	if(buf->count==0)		//if buf-> count equal to zero
		return EMPTY;		//return empty
}

uint8_t buffer_peak(CircBuf * buf, uint16_t n);
{
	if(buffer_empty==EMPTY)		//if bufffer is empty
		return FAIL;		//return empty flag
	else
	{
		return *((buf->head)+n-1)	//else return the nth element counted from head
	}
}

uint8_t buffer_init(CircBuf * buf, uint16_t noBytes);
{
	if((buf->buffer = (uint8_t *) malloc(noBytes*sizeof(uint16_t)))==NULL)	//allocate memory of given size
		return FAIL;	//and if memory is not allocated, return failure
	buf->head = buf->buffer;	//set buf->head to point the buffer start
	buf->tail = buf->buffer;	//set buf->tail to point the buffer start
	buf->count = 0;		//initialize buffer->count to 0
	buf->length = noBytes;	//set buf->length to noBytes 
	return SUCCESS;
}

uint8_t buffer_destroy(CircBuf * buf);
{
	free(buf->buffer);	//free the memory pointed through buf->pointer
	buf->buffer = NULL;	//setting it to null
	buf->head = NULL;	//setting head pointer to null
	buf->tail = NULL;	//setting tail pointer to null
}

