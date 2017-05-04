#ifndef __MEMORY_H
#define __MEMORY_H

#include "main.h"
#include <stdint.h>

/***************************************************************************
*    my_memmove():
*   	Description: 
*		move the content from the src pointer to dest pointer 
*   		consdiering the overlap condition.
*	Params:
*		uint8_t * src: the source pointer for the move
*		uint8_t * dst: the destination pointer for the move
*		uint32_t length: number of bytes to move
*	return:
*		int8: pass/fail if succeded
*
*    my_memset():
*	Description: 
*		set memory locations to the given value
*	Params:
*		uint8_t * src: the source pointer
*		uint8_t length: number of bytes to set
*		uint8_t value: the value to set
*	return:
*		int8: pass/fail if succeded
*
*    my_memzero():
*	Description: 
*               set memory locations to zero
*       Params:
*               uint8_t * src: the source pointer
*               uint8_t length: number of bytes to set
*       return:
*               int8: pass/fail if succeded
*
*    my_reverse():
*	Description: 
*		reverse fixed number of bytes from source
*       Params:
*               uint8_t * src: the source pointer
*               uint8_t length: number of bytes to reverse
*       return:
*               int8: pass/fail if succeded 
*   
***************************************************************************/
//typedef enum status {SUCCESS, FAIL} status_e;
//typedef enum status {SUCCESS, FAIL, FULL, NOT_FULL, EMPTY, NOT_EMPTY} status_e;

void my_memmove(uint8_t * src, uint8_t * dst, uint32_t length);
void my_memset(uint8_t * src, uint32_t length, uint8_t value);
void my_memzero(uint8_t * src, uint32_t length);
void my_reverse(uint8_t * src, uint32_t length);

#endif  // end of __MEMORY_H

