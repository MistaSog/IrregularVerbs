#include "verbs.h"
#include <stdio.h>

int main()
{
	Record A[VERBS_NUMBER];
	printf("IrregularVerbs\n");
	read_dictionary(DICTIONARY_PATH, A) ? printf("Done!\n") : printf("Error!\n");
	print_dictionary(A);
	print_task(A);
	return 0;
}