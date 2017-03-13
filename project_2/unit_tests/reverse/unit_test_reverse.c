#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "memory.h"

void test_null_ptr_reverse(void **state)
{
	uint8_t * src = NULL;
	uint32_t length = 25;	 
	status_e status = my_reverse(src, length);
	assert_int_equal(status, FAIL);
}

void test_odd_reverse(void **state)
{
	uint8_t src[25];
	uint32_t length = 25;	 
	status_e status = my_reverse(src, length);
	assert_int_equal(status, SUCCESS);
}


void test_even_reverse(void **state)
{
	uint8_t src[26];
	uint32_t length = 26;	 
	status_e status = my_reverse(src, length);
	assert_int_equal(status, SUCCESS);
}


void test_character_reverse(void **state)
{
	uint8_t src[30] = {'#', '$', 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,'@','a', 'z', '/', '<', '?', '-', '*'};
	uint32_t length = 30;	 
	status_e status = my_reverse(src, length);
	assert_int_equal(status, SUCCESS);
}


int main(int argc, char **argv)
{
	const struct CMUnitTest tests[] = {
	cmocka_unit_test(test_null_ptr_reverse), cmocka_unit_test(test_even_reverse),
	cmocka_unit_test(test_odd_reverse), cmocka_unit_test(test_character_reverse),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
