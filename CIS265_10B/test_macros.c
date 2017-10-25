/*************************************************************************
* Title: (CIS265_10B) Macros CUnit test suite.
* File: test_macros.c
* Author: James Eli
* Date: 10/24/2017
*
* CUnit test suite for macros.
*
* Notes:
*  (1) Requires installation of the CUnit test framework (include and
*      library files).
*  (2) Compiled with MS Visual Studio 2017 Community (v141), using C
*      language options.
*
* Submitted in partial fulfillment of the requirements of PCC CIS-265.
*************************************************************************
* Change Log:
*   10/24/2017: Initial release. JME
*************************************************************************/
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

#include "macros.h"

#ifndef NDEBUG

// Computes polynomial used for debug/confirmation purposes.
double poly(double x) {
	double y = 0.;

	y = y + 3. * pow(x, 5.);
	y = y + 2. * pow(x, 4);
	y = y - 5. * pow(x, 3.);
	y = y - x * x;
	y = y + 7. * x;
	y = y - 6.;
	return y;
}

/* Test Suite setup and cleanup functions. */
int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/* Test case functions. */
void test_case_sample(void) {
	CU_ASSERT(CU_TRUE);
	CU_ASSERT_NOT_EQUAL(2, -1);
	CU_ASSERT_STRING_EQUAL("string #1", "string #1");
	CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #2");

	CU_ASSERT(CU_FALSE);
	CU_ASSERT_EQUAL(2, 3);
	CU_ASSERT_STRING_NOT_EQUAL("string #1", "string #1");
	CU_ASSERT_STRING_EQUAL("string #1", "string #2");
}

void check_macro_test(void) {
	CU_ASSERT_FALSE(CHECK(0, 0, 0));
	CU_ASSERT_FALSE(CHECK(1, 1, 1));
	CU_ASSERT_FALSE(CHECK(-1, 1, 1));
	CU_ASSERT_FALSE(CHECK(1, -1, 1));
	CU_ASSERT_FALSE(CHECK(1, 1, -1));
	CU_ASSERT_FALSE(CHECK(-1, -1, -1));
	CU_ASSERT_TRUE(CHECK(0, 0, 1));
	CU_ASSERT_TRUE(CHECK(1, 2, 3));
	CU_ASSERT_TRUE(CHECK(2, 1, 3));
	CU_ASSERT_TRUE(CHECK(2, 2, 3));
}

void median_macro_test(void) {
	CU_ASSERT_EQUAL(MEDIAN(0, 0, 0), 0);
	CU_ASSERT_EQUAL(MEDIAN(1, 2, 3), 2);
	CU_ASSERT_EQUAL(MEDIAN(1, -1, 0), 0);
	CU_ASSERT_EQUAL(MEDIAN(1, 0, -1), 0);
	CU_ASSERT_EQUAL(MEDIAN(-1, 1, 0), 0);
	CU_ASSERT_EQUAL(MEDIAN(-1, 0, 1), 0);
	CU_ASSERT_EQUAL(MEDIAN(0, -1, 1), 0);
	CU_ASSERT_EQUAL(MEDIAN(0, 1, -1), 0);
	CU_ASSERT_EQUAL(MEDIAN(-1, 2, 100), 2);
}

void polynomial_macro_test(void) {
	CU_ASSERT_EQUAL(POLYNOMIAL(1.0), poly(1.0));
	CU_ASSERT_EQUAL(POLYNOMIAL(0), poly(0));
	CU_ASSERT_EQUAL(POLYNOMIAL(-1.0), poly(-1.0));
	CU_ASSERT_EQUAL(POLYNOMIAL(100.0), poly(100.0));
	CU_ASSERT_EQUAL(POLYNOMIAL(-100.0), poly(-100.0));
}

/* Test Runner Code. */
int main(void) {
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* Add a suite to the registry. */
	pSuite = CU_add_suite("maros_test_suite", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Add the tests to the suite. */
	if ((NULL == CU_add_test(pSuite, "check_macro_test", check_macro_test)) ||
		(NULL == CU_add_test(pSuite, "median_macro_test", median_macro_test)) ||
		(NULL == CU_add_test(pSuite, "polynomial_macro_test", polynomial_macro_test))
		)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Run all tests using the basic interface. */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_basic_show_failures(CU_get_failure_list());

	// Pause to see results.
	int c = getchar();

	/* Clean up registry and return. */
	CU_cleanup_registry();
	return CU_get_error();
}

#endif
