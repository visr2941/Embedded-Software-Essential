#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "data.h"
#include "memory.h"


void test_data1(uint8_t * arr, uint32_t length)
{
	uint32_t x, i;
	uint32_t * str = arr;
	printf("\nBelow is test_report_1: \n");
        print_memory(arr, length);
        big_to_little32(str, length);
        printf("\nBelow is the big_to_little conversion of arr1 data:\n");
        print_memory(arr, length);
        little_to_big32(str, length);
	printf("\nBelow is little_to_big conversion of arr1 data:\n");
        print_memory(str, length);
}


void test_data2(uint8_t * arr, uint8_t length)
{
	uint8_t i=0;
	uint8_t str[4] = {0x00};
	printf("\nBelow is test_report_2: \n");	
	for(i=0; i< length; i++)
	{
		my_itoa(str, *(arr+i), 10);
		print_memory(str, 2);
	}	
}

void test_data3(uint8_t * arr, uint8_t length)
{
	int i=0;
	printf("\nBelow is test_report_3: \n");	
	for(i=0; i< length; i++)
	{
		my_atoi(arr+i);
		print_memory(arr+i, 1);
	}	
}


void test_memory(uint8_t * arr, uint8_t length)
{
	print_memory(arr,32);
	my_reverse(arr,12);
	printf("\nafter reversing the starting 12 bytes\n");
	print_memory(arr, 32);
	my_memset(arr+16, 4, 0xEE);
	printf("\nafter memset (0xEE) from 17th to 20th positions\n");
	print_memory(arr, 32);
	my_memmove(arr+25, arr+19, 6);
	printf("\nafter memmove from 26th to 20th positions\n");
	print_memory(arr, 32);
	my_memzero(arr+11, 5);
	printf("\nafter memzero from 12th to 16th positions\n");
	print_memory(arr, 32);
	my_memmove(arr, arr+8, 8);
	printf("\nafter memmove from 1st to 9th positions\n");
	print_memory(arr, 32);
}

void project_1_report(void)
{
	uint8_t i = 0, j = 0;
	uint8_t arr1[32], arr2[32], arr3[32];
	for (i; i<32; i++)
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


	//test_data1(arr1, 32);
	//test_data2(arr2, 32);
	//test_data3(arr2, 32);
	test_memory(arr2, 32);
}


main()
{
	project_1_report();
}
