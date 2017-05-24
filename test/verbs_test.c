#include "verbs.c"
#include "ctest.h"

CTEST(input_suite, correct_test)
{
	Record A[VERBS_NUMBER];
	const int result = ReadDictionary("src/Dictionary", A);
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

CTEST(input_suite, error_test)
{
	Record A[VERBS_NUMBER];
	const int result = ReadDictionary("src/dog", A);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(otput_suite, correct_test)
{
	Record A[VERBS_NUMBER];
	ReadDictionary("src/Dictionary", A);
	const int result = PrintDictionary(A);
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

CTEST(otput_suite, error_test)
{
	Record B[1]={{"NULL", "NULL", "NULL"}};
	const int result = PrintDictionary(B);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}