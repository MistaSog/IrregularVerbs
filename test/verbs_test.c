#include "verbs.c"
#include "ctest.h"

CTEST(verbs_suite, simple_test)
{
	const int result = ReadDictionary();
	const int expected = 1;
	ASSERT_EQUAL(expected, result);
}