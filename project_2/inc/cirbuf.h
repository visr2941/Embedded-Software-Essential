#ifndef CIR_BUFF_H
#define CIR_BUFF_H

/*******************************************************************************
*    buffer_add():
*   	Description: 
*		add a data into the circular buffer
*	Params:
*		CircBuf * buf: a pointer to circular buffer
*		int8_t data: the data to be added to buffer
*	return:
*		int8: success/failure
*    
*    buffer_remove():
*       Description: 
*               remove a data from the circular buffer
*       Params:
*               CircBuf * buf: a pointer to circular buffers
*       return:
*               int8: success/failure
*
*    buffer_full():
*	Description: 
*		to check if the buffer is full
*	Params:
*		CircBuf * buf: a pointer to circular buffer
*	Return:
*		int8_t: FULL signal
*
*    buffer_empty():
*       Description: 
*               to check if the buffer is empty
*       Params:
*               CircBuf * buf: a pointer to circular buffer
*       Return:
*               int8_t: EMPTY signal
*
*    buffer_peak():
*       Description: 
*               to get the nth element of the buffer
*       Params:
*               CircBuf * buf: a pointer to circular buffer
*		uint16_t n: the nth element to be returned
*       Return:
*               int8_t: the nth element
*
*    buffer_init():
*       Description: 
*               to initilaize the buffer
*       Params:
*               CircBuf * buf: a pointer to circular buffer
*		uint16_t noBytes: number of bytes to initialize buffer with
*       Return:
*               int8_t: success/fail signal
*
*    buffer_destroy():
*       Description: 
*               to destroy the buffer and free the memory
*       Params:
*               CircBuf * buf: a pointer to circular buffer
*       Return:
*               int8_t: success/fail signal
*
*******************************************************************************/

typedef struct CircBuf_t 
{
	int8_t * buffer;		//pointer to the start of location
	int8_t * head;			//pointer to the newest element
	int8_t * tail;			//pointer to the oldest element
	uint16_t count, length;		//variable to track count & length
} CircBuf;

typedef enum status {SUCCESS, FAIL, FULL, NOT_FULL, EMPTY, NOT_EMPTY} status_e;

status_e buffer_add(CircBuf * buf, int8_t data);
status_e buffer_remove(CircBuf * buf);
status_e buffer_full(CircBuf * buf);
status_e buffer_empty(CircBuf * buf);
int8_t buffer_peak(CircBuf * buf, uint16_t n);
status_e buffer_init(CircBuf * buf, uint16_t noBytes);
status_e buffer_destroy(CircBuf * buf);

#endif
