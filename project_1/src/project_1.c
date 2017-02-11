#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "data.h"


void test_data1(uint32_t * arr, uint32_t length)
{
        uint8_t i=0;
        print_memory(arr, length);
        big_to_little32(arr, length);
        printf("\nBelow is the big_to_little conversion of arr1 data:\n");
        print_memory(arr, length);
        little_to_big32(arr, length);
	printf("\nBelow is little_to_big conversion of arr1 data:\n");
        print_memory(arr, length);
}


void project_1_report(void)
{
	uint8_t i = 0, j = 0;
	uint8_t arr1[32], arr2[32], arr3[32];
	for (i; i<sizeof(arr1); i++)
	{
		if(i>15)
			arr1[i] = j++;
		else 
			arr1[i] = i;
	}
	
	
	for (i=0; i<sizeof(arr2); i++)
        {       
                arr2[i] = i;
        }



	for(i=0, j=0; i<sizeof(arr3); i++)
	{
		if(i<26)
			arr3[i] = 97+i;
		else
			arr3[i] = 65+j++;
	}
	test_data1(arr1, 32);
}


main()
{
	project_1_report();
}
