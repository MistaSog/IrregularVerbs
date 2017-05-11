#ifndef VERBS
#define VERBS
typedef struct {
	char inf[16];
	char past_simple[16];
	char past_participle[16];
} Record;

int ReadDictionary();
#endif