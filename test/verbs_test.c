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

const int ALL = 100;

CTEST(mark_suite, below_zero_test)
{
	const int result = TaskMark(ALL, -1);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, zero_test)
{
	const int result = TaskMark(ALL, 0);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_two_left_test)
{
	const int result = TaskMark(ALL, 1);
	const int expected = 2;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_two_right_test)
{
	const int result = TaskMark(ALL, 35);
	const int expected = 2;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_three_left_test)
{
	const int result = TaskMark(ALL, 36);
	const int expected = 3;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_three_right_test)
{
	const int result = TaskMark(ALL, 60);
	const int expected = 3;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_four_left_test)
{
	const int result = TaskMark(ALL, 61);
	const int expected = 4;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_four_right_test)
{
	const int result = TaskMark(ALL, 85);
	const int expected = 4;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_five_left_test)
{
	const int result = TaskMark(ALL, 86);
	const int expected = 5;
	ASSERT_EQUAL(expected, result);
}

CTEST(mark_suite, mark_five_right_test)
{
	const int result = TaskMark(ALL, 100);
	const int expected = 5;
	ASSERT_EQUAL(expected, result);
}
CTEST(mark_suite, over_100_test)
{
	const int result = TaskMark(ALL, 101);
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
}