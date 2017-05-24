#include "verbs.h"
#include <stdio.h>

int main()
{
	Record A[VERBS_NUMBER];
	printf("IrregularVerbs\n");
	ReadDictionary("src/Dictionary", A) ? printf("Done!\n") : printf("Error!\n");
	for (int i=0; i<VERBS_NUMBER; i++) {
		printf("%s %s %s\n", A[i].inf, A[i].past_simple, A[i].past_participle);
	}
	return 0;
}