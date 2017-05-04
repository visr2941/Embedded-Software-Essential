#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

void my_memmove(uint8_t * src, uint8_t * dst, uint32_t length)
{	
        uint8_t i;		// loop variable
	if(src==NULL || dst==NULL)
		return ;
        if (dst<= src)		// if destination address is less than source address
        {
                for (i=0; i<length; i++)	// loop for moving the value from source to destination
                        *dst++ = *src++;
        }
        else			// if destination address is larger than the source address
        {
                for (i=0; i<length; i++)	// loop and copy the source to destination in reverse way
                        *(dst+length-1-i) = *(src+length-1-i);
        }

        return ;		// return zero if ful
}


void my_memset(uint8_t * src, uint32_t length, uint8_t value)
{
	uint8_t i;			// loop variable
	if(src==NULL)
		return ;
	for(i=0; i<length; i++)		// looping to copy the value at source locations
		*src++ = value;
	return ;			// return zero if ful
}

void my_memzero(uint8_t * src, uint32_t length)
{
	uint8_t i;			// loop variable 
	if(src==NULL)
		return ;
	for(i=0; i<length; i++)		// looping to copy zero to all the source location
		*src++=0;
	return ;
}

void my_reverse(uint8_t * src, uint32_t length)
{
	uint8_t i = 0; 
	uint32_t temp=0;
	if(src==NULL)
		return ;
	for(i=0; i< length/2; i++)		// looping on half of the length
	{					// and swapping the start and last using a temp variable
		temp=*(src+i);
		*(src+i) = *(src+length-i-1);
		*(src+length-i-1) = temp;	
	}
	return ;			// return zero if ful
}

