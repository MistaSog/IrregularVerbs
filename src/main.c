#include "verbs.h"
#include <stdio.h>

int main()
{
	Record A[VERBS_NUMBER];
	printf("Reading the dictionary file\n");
	if (read_dictionary(DICTIONARY_PATH, A) == 0) {
		printf("Error!\n");
		return 1;
	}
	else {
		printf("Done!\n\n");
	}
	menu(A);
	return 0;
}