#ifndef VERBS
#define VERBS
#define VERBS_NUMBER 355
#define TASK_NUMBER 5
#define DICTIONARY_PATH "src/Dictionary"

typedef struct {
	char inf[32];
	char past_simple[32];
	char past_participle[32];
} Record;

void clean_buff(void);

int read_dictionary(char fname[64], Record *);
int task_mark(int, int);
void print_dictionary(Record *);
void print_task(Record *);
void print_mark(int, int, int);
void menu(Record *);
#endif