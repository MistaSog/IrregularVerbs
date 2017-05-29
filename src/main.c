#include "verbs.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
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