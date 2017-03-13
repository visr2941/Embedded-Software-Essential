#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "memory.h"

void test_null_ptr_memzero(void **state)
{
	uint8_t * src = NULL;
	uint32_t length = 25;	 
	status_e status = my_memzero(src, length);
	assert_int_equal(status, FAIL);
}

void test_set_value_memzero(void **state)
{
	uint8_t * src = (uint8_t *) malloc(20*sizeof(uint8_t));
	uint32_t length = 20;

	status_e status = my_memzero(src, length);
	assert_int_equal(status, SUCCESS);
}


int main(int argc, char **argv)
{
	const struct CMUnitTest tests[] = {
	cmocka_unit_test(test_null_ptr_memzero), cmocka_unit_test(test_set_value_memzero),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
