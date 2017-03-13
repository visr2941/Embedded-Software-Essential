#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "memory.h"

void test_null_ptr_memmove(void **state)
{
	uint8_t * src = NULL;
	uint8_t * dst = NULL;
	uint32_t length = 5;	 

	status_e status = my_memmove(src, dst, length);	
	assert_int_equal(status, FAIL);
}

void test_no_overlap_memmove(void **state)
{
	uint32_t length = 15;
	uint8_t * src = (uint8_t *) malloc(length*sizeof(uint8_t));
	uint8_t * dst = src+18;

	status_e status = my_memmove(src, dst, length);	
	assert_int_equal(status, SUCCESS);
}

void test_src_in_dst_memmove(void **state)
{
	uint32_t length = 15;
	uint8_t dst[32];
	uint8_t * src = dst+4;

	status_e status = my_memmove(src, dst, length);	
	assert_int_equal(status, SUCCESS);
}

void test_dst_in_src_memmove(void **state)
{
	uint32_t length = 15;
	uint8_t src[32];
	uint8_t * dst = src+4;

	status_e status = my_memmove(src, dst, length);	
	assert_int_equal(status, SUCCESS);
}

int main(int argc, char **argv)
{
	const struct CMUnitTest tests[] = {
	cmocka_unit_test(test_null_ptr_memmove), cmocka_unit_test(test_no_overlap_memmove),
	cmocka_unit_test(test_src_in_dst_memmove), cmocka_unit_test(test_dst_in_src_memmove),
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
