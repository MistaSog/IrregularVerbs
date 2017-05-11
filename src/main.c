#include "verbs.h"
#include <stdio.h>

int main()
{
	printf("IrregularVerbs\n");
	(ReadDictionary()?printf("Done!\n"):printf("Error!\n"));
	return 0;
}