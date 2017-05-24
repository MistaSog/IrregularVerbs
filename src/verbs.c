#include "verbs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ReadDictionary(char fname[],Record *A)
{
	FILE *fdict;
	if (!(fdict = fopen(fname, "r"))) { 
		return 0;
	}
	int i=0;
	while (fscanf(fdict, "%s%s%s", A[i].inf, A[i].past_simple, A[i].past_participle) != EOF) {
		i++;
	}
	return 1;
}

int PrintDictionary(Record *A)
{	
	if (strcmp(A[0].inf,"NULL")==0) {
		return 0;
	}
	printf("|====================+====================+====================|\n");
	printf("|     Infinitive     |     Past Simple    |   Past Participle  |\n");
	printf("|====================+====================+====================|\n");
	for (int i=0; i<VERBS_NUMBER; i++) {
		printf("| %18s | %18s | %18s |\n", A[i].inf, A[i].past_simple, A[i].past_participle);
	}
	printf("|====================+====================+====================|\n");
	return 1;
}