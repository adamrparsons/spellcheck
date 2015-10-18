#ifndef stdio_h
#include <stdio.h>
#endif
#ifndef stdlib_h
#include <stdlib.h>
#endif
#ifndef String_h
#include <String.h>
#endif

typedef struct SettingsRC{
	int maxCorrection;
	char* dictionaryTextFN;
	int autoCorrect;
}SettingsRC;

# define MAXLEN 100

int parseLine(char* inLine, char* key, char* value);
int parseSettingsFile(FILE *setfp, SettingsRC *settings);
int parseSettings(FILE *setfp, SettingsRC *settings);
