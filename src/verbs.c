#include "verbs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int read_dictionary(char fname[],Record *A)
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

void print_dictionary(Record *A)
{	
	int i = 0;
	printf(
		"|====================+====================+====================|\n");
	printf(
		"|     Infinitive     |     Past Simple    |   Past Participle  |\n");
	printf(
		"|====================+====================+====================|\n");
	for (i = 0; i < VERBS_NUMBER; i++) {
		printf("| %18s | %18s | %18s |\n", 
			A[i].inf, A[i].past_simple, A[i].past_participle);
	}
	printf(
		"|====================+====================+====================|\n");
}

void print_task(Record *A)
{
	char task[32];
	int all;
	int i = 0;
	int correct = 0;
	int mark = 0;
	int v, word;
	all = TASK_NUMBER;
	printf(
		"|==============================================================|\n");
	printf(
		"|          Fill in the blanks with the correct form            |\n");
	printf(
		"|   If it has several forms, list them via \"/\" without spaces  |\n");
	printf(
		"|               For example \"example1/example2\"                |\n");
	printf(
		"|     Infinitive     |     Past Simple    |   Past Participle  |\n");
	printf(
		"|==============================================================|\n");
	for (i = 0; i < all; i++) {
		v = (rand() % VERBS_NUMBER) % 2;
		word = rand() % VERBS_NUMBER;
		switch (v) {
		case 0:
			printf("| %18s | %18s |                    |\n", 
				A[word].inf, A[word].past_simple);
			printf("|>");
			scanf("%32s", task);
			clean_buff();
			if (strcmp(A[word].past_participle, task) == 0) {
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
			scanf("%32s", task);
			clean_buff();
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
	mark = task_mark(all, correct);
	print_mark(all, correct, mark);
}

int task_mark(int all, int correct)
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

void print_mark(int all, int correct, int mark)
{
	printf(
		"|==============================================================|\n");
	printf(
		"|               Correct: %3d/%-3d      Mark: %1d                  |\n",
			correct, all, mark);
	printf(
		"|==============================================================|\n");
}

void clean_buff(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void menu(Record *A)
{
	char c;
	int ext = 0;
	while (!ext) {
		printf(
			"|==============================================================|\n");
		printf(
			"| Enter \"1\" to print list of irregular verbs                   |\n");
		printf(
			"| Enter \"2\" to test your knowledge of irregular verbs          |\n");
		printf(
			"| Enter \"3\" to exit                                            |\n");
		printf(
			"|==============================================================|\n");
		c = getchar();
		clean_buff();
		switch (c) {
		case '1':
			print_dictionary(A);
			break;
		case '2':
			print_task(A);
			break;
		case '3':
			ext = 1;
		default :
			break;
		}
	}
}