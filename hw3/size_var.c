#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void main()
{
	printf("size of int: %ld\n", sizeof(int));
	printf("size of char: %ld\n", sizeof(char));
        printf("size of float: %ld\n", sizeof(float));
        printf("size of double: %ld\n", sizeof(double));
        printf("size of short: %ld\n", sizeof(short));
        printf("size of long: %ld\n", sizeof(long));
        printf("size of long int: %ld\n", sizeof(long int));
        printf("size of long long: %ld\n", sizeof(long long));
        printf("size of int8_t: %ld\n", sizeof(int8_t));
        printf("size of uint8_t: %ld\n", sizeof(uint8_t));
        printf("size of uint16_t: %ld\n", sizeof(uint16_t));
        printf("size of uint32_t: %ld\n", sizeof(uint32_t));
        printf("size of char*: %ld\n", sizeof(char *));
        printf("size of int*: %ld\n", sizeof(int *));
        printf("size of float*: %ld\n", sizeof(float *));
        printf("size of void*: %ld\n", sizeof(void *));
        printf("size of void**: %ld\n", sizeof(void **));
        printf("size of int8_t*: %ld\n", sizeof(int8_t *));
        printf("size of int16_t*: %ld\n", sizeof(int16_t *));
        printf("size of int32_t*: %ld\n", sizeof(int32_t *));
        printf("size of size_t: %ld\n", sizeof(size_t));
}
