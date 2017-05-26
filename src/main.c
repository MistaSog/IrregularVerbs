#include "verbs.h"
#include <stdio.h>

int main()
{
	Record A[VERBS_NUMBER];
	printf("IrregularVerbs\n");
	ReadDictionary("src/Dictionary", A) ? printf("Done!\n") : printf("Error!\n");
	PrintDictionary(A) ? printf("Done!\n") : printf("Error!\n");
	PrintTask(A) ? printf("Done!\n") : printf("Error!\n");
	return 0;
}