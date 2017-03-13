#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "data.h"

void test_null_ptr_little2big(void **state)
{
	uint32_t * data = NULL;
	uint32_t length = 25;	 
	status_e status = little_to_big32(data, length);
	assert_int_equal(status, FAIL);
}

void test_validity_little2big(void **state)
{
	uint32_t * src = (uint32_t *) malloc(sizeof(uint32_t));
	*src = 0x1234ABCD;
	uint8_t * src_temp = (uint8_t *) src;

	status_e status = little_to_big32(src, 1);
	if(*src_temp==0x12)
		status = SUCCESS;
	else
		status = FAIL;
	assert_int_equal(status, SUCCESS);
}


int main(int argc, char **argv)
{
	const struct CMUnitTest tests[] = {
	cmocka_unit_test(test_validity_little2big), cmocka_unit_test(test_null_ptr_little2big)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
