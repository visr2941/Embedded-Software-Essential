#include <stdio.h>
#include <stdint.h>
#include "feature.h"


int8_t check_rep(uint8_t * arr, uint16_t len)
{
	uint8_t i = 0, j = 0, temp=0;
	while (i<len)
	{
		j=i+1;
		temp=*(arr+i++);
		while (j<len)
			if(temp==*(arr+j++))
				return -1;
	}
	return 0;
}

