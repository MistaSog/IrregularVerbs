#include "verbs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ReadDictionary(char fname[],Record *A)
{
	FILE *fdict;
	if(!(fdict = fopen(fname, "r"))) return 0;
	int i=0;
	while (fscanf(fdict, "%s%s%s", A[i].inf, A[i].past_simple, A[i].past_participle) != EOF) {
		i++;
	}
	return 1;
}