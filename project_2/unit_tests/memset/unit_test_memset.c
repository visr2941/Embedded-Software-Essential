#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "memory.h"

void test_null_ptr_memset(void **state)
{
	uint8_t * src = NULL;
	uint8_t value = 32;
	uint32_t length = 5;	 
	status_e status = my_memset(src, length, value);
	assert_int_equal(status, FAIL);
}

void test_set_value_memset(void **state)
{
	uint8_t * src = (uint8_t *) malloc(20*sizeof(uint8_t));
	uint8_t value = 32;
	uint32_t length = 20;

	status_e status = my_memset(src, length, value);
	assert_int_equal(status, SUCCESS);
}


int main(int argc, char **argv)
{
	const struct CMUnitTest tests[] = {
	cmocka_unit_test(test_null_ptr_memset), cmocka_unit_test(test_set_value_memset),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
