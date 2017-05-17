#ifndef VERBS
#define VERBS
#define VERBS_NUMBER 374
typedef struct {
	char inf[32];
	char past_simple[32];
	char past_participle[32];
} Record;

int ReadDictionary(char fname[32], Record*);
#endif