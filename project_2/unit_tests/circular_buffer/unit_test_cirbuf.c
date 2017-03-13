#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "cirbuf.h"

void test_buffer_create_cirbuf(void **state)
{
	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));
	uint16_t noBytes = 10;	 

	status_e status = buffer_init(buf, noBytes);	
	assert_int_equal(status, SUCCESS);
}


void test_null_ptr_cirbuf(void **state)
{
	CircBuf * buf=NULL;

	status_e status = buffer_init(buf, 10);	
	assert_int_equal(status, FAIL);
}


void test_not_init_cirbuf(void **state)
{
	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));

	status_e status = buffer_destroy(buf);	
	assert_int_equal(status, FAIL);
}


void test_add_remove_cirbuf(void **state)
{
	uint8_t data = 15;
	uint16_t n = 1;

	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));	 
	status_e status = buffer_init(buf, 10);

	buffer_add(buf, data);
	if(buffer_peak(buf, n)==data)
		status = SUCCESS;
	else
		status = FAIL;
	assert_int_equal(status, SUCCESS);
}

void test_buffer_full_cirbuf(void **state)
{
	uint8_t data = 15;

	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));	 
	buffer_init(buf, 1);

	buffer_add(buf, data);
	assert_int_equal(buffer_full(buf), FULL);
}

void test_buffer_empty_cirbuf(void **state)
{
	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));	 
	buffer_init(buf, 1);

	assert_int_equal(buffer_empty(buf), EMPTY);
}


void test_add_wrap_cirbuf(void **state)
{
	uint8_t data[3] = {15, 14, 8};

	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));	 
	buffer_init(buf, 3);

	buffer_add(buf, data[0]);
	buffer_add(buf, data[1]);
	buffer_add(buf, data[2]);

	buffer_remove(buf);
	
	assert_int_equal(buffer_add(buf, 11), SUCCESS);
}

void test_remove_wrap_cirbuf(void **state)
{
	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));	 
	buffer_init(buf, 3);

	buffer_add(buf, 11);
	buffer_add(buf, 12);
	buffer_add(buf, 13);
	buffer_remove(buf);
	buffer_add(buf, 14);

	buffer_remove(buf);
	buffer_remove(buf);
	
	assert_int_equal(buffer_remove(buf), SUCCESS);
}


void test_over_fill_cirbuf(void **state)
{
	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));	 
	buffer_init(buf, 3);

	buffer_add(buf, 11);
	buffer_add(buf, 12);
	buffer_add(buf, 13);

	assert_int_equal(buffer_add(buf, 14), FAIL);
}


void test_over_empty_cirbuf(void **state)
{
	CircBuf * buf = (CircBuf *) malloc(sizeof(CircBuf));	 
	buffer_init(buf, 3);

	assert_int_equal(buffer_remove(buf), FAIL);
}


int main(int argc, char **argv)
{
	const struct CMUnitTest tests[] = {
	cmocka_unit_test(test_buffer_create_cirbuf), cmocka_unit_test(test_null_ptr_cirbuf),
	cmocka_unit_test(test_not_init_cirbuf), cmocka_unit_test(test_add_remove_cirbuf),
	cmocka_unit_test(test_buffer_full_cirbuf), cmocka_unit_test(test_buffer_empty_cirbuf),
	cmocka_unit_test(test_add_wrap_cirbuf), cmocka_unit_test(test_remove_wrap_cirbuf),
	cmocka_unit_test(test_over_fill_cirbuf), cmocka_unit_test(test_over_empty_cirbuf)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
