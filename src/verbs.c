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
	while (fscanf(fdict, "%s%s%s", 
			A[i].inf, A[i].past_simple, A[i].past_participle) != EOF) {
		i++;
	}
	return 1;
}

int PrintDictionary(Record *A)
{	
	int i = 0;
	if (strcmp(A[0].inf,"NULL")==0) {
		return 0;
	}
	printf("|====================+====================+====================|\n");
	printf("|     Infinitive     |     Past Simple    |   Past Participle  |\n");
	printf("|====================+====================+====================|\n");
	for (i = 0; i < VERBS_NUMBER; i++) {
		printf("| %18s | %18s | %18s |\n", 
			A[i].inf, A[i].past_simple, A[i].past_participle);
	}
	printf("|====================+====================+====================|\n");
	return 1;
}

int PrintTask(Record *A)
{
	char task[32];
	int i = 0;
	int correct = 0;
	int mark = 0;
	int v, word;
	printf("|==============================================================|\n");
	printf("|          Fill in the blanks with the correct form            |\n");
	printf("|     Infinitive     |     Past Simple    |   Past Participle  |\n");
	printf("|==============================================================|\n");
	for (i = 0; i < 10; i++) {
		v = (rand() % VERBS_NUMBER) % 2;
		word = rand() % VERBS_NUMBER;
		switch (v) {
		case 0:
			printf("| %18s | %18s |                    |\n", 
				A[word].inf, A[word].past_simple);
			printf("|>");
			scanf("%s", task);
			if ( strcmp(A[word].past_participle, task) == 0) {
				printf("| Correct answer!\n");
				correct++;
			}
			else {
				printf("| Wrong answer! correct form is: %-30s|\n",
					A[word].past_participle);
			}
			break;
		case 1:
			printf("| %18s |                    | %18s |\n", 
				A[word].inf, A[word].past_participle);
			printf("|>");
			scanf("%s", task);
			if ( strcmp(A[word].past_simple, task) == 0) {
				printf("| Correct answer!\n");
				correct++;
			}
			else {
				printf("| Wrong answer! correct form is: %-30s|\n",
					A[word].past_simple);
			}
			break;
		default :
			break;
		}
		switch (correct) {
		case 0:
		case 1:
		case 2:
		case 3:
			mark = 2;
			break;
		case 4:
		case 5:
		case 6:
			mark = 3;
			break;
		case 7:
		case 8:
		case 9:
			mark = 4;
			break;
		case 10:
			mark = 5;
			break;
		default :
			mark = 2;
			break;
		}
	}
	printf("|==============================================================|\n");
	printf("|               Correct: %2d/10      Mark: %d                    |\n",
			correct, mark);
	printf("|==============================================================|\n");
	return 1;
}