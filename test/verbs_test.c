#include "verbs.c"
#include "ctest.h"

CTEST(verbs_suite, correct_test)
{
	Record A[VERBS_NUMBER];
	const int result = ReadDictionary("src/Dictionary", A);
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}

CTEST(verbs_suite, error_test)
{
	Record A[VERBS_NUMBER];
	const int result = ReadDictionary("src/dog", A);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}
