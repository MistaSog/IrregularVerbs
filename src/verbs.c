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

void PrintTask(Record *A)
{
	char task[32];
	int all;
	int i = 0;
	int correct = 0;
	int mark = 0;
	int v, word;
	all = TASK_NUMBER;
	printf("|==============================================================|\n");
	printf("|          Fill in the blanks with the correct form            |\n");
	printf("|   If it has several forms, list them via \"/\" without spaces  |\n");
	printf("|               For example \"example1/example2\"                |\n");
	printf("|     Infinitive     |     Past Simple    |   Past Participle  |\n");
	printf("|==============================================================|\n");
	for (i = 0; i < all; i++) {
		v = (rand() % all) % 2;
		word = rand() % all;
		switch (v) {
		case 0:
			printf("| %18s | %18s |                    |\n", 
				A[word].inf, A[word].past_simple);
			printf("|>");
			scanf("%32s", task);
			CleanBuff();
			if (strcmp(A[word].past_participle, task) == 0) {
				printf("| Correct answer!\n");
				correct++;
			}
			else {
				if (strstr(A[word].past_participle, task))
				printf("| Wrong answer! correct form is: %-30s|\n",
					A[word].past_participle);
			}
			break;
		case 1:
			printf("| %18s |                    | %18s |\n", 
				A[word].inf, A[word].past_participle);
			printf("|>");
			scanf("%32s", task);
			CleanBuff();
			if (strcmp(A[word].past_simple, task) == 0) {
				printf("| Correct answer!\n");
				correct++;
			}
			else {
				printf("| Wrong answer! correct form is: %-30s|\n",
					A[word].past_simple);
			}
		default :
			break;
		}
	}
	mark = TaskMark(all, correct);
	PrintMark(all, correct, mark);
}

int TaskMark(int all, int correct)
{
	int mark = 0;
	double calc = 0;
	calc = correct / (double)all;
	if (calc > 0 && calc <= 0.35) {
		mark = 2;
	}
	if (calc > 0.35 && calc <= 0.60) {
		mark = 3;
	}
	if (calc > 0.60 && calc <= 0.85) {
		mark = 4;
	}
	if (calc > 0.85 && calc <= 1.0) {
		mark = 5;
	}
	return mark;
}

void PrintMark(int all, int correct, int mark)
{
	printf("|==============================================================|\n");
	printf("|               Correct: %3d/%-3d      Mark: %1d                  |\n",
			correct, all, mark);
	printf("|==============================================================|\n");
}

void CleanBuff(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}