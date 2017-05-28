#ifndef VERBS
#define VERBS
#define VERBS_NUMBER 355
#define TASK_NUMBER 5
typedef struct {
	char inf[32];
	char past_simple[32];
	char past_participle[32];
} Record;

void CleanBuff(void);

int ReadDictionary(char fname[32], Record *);
int TaskMark(int, int);
void PrintDictionary(Record *);
void PrintTask(Record *);
void PrintMark(int, int, int);
#endif