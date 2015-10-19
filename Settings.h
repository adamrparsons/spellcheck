/*	Settings.h
*/
#ifndef SETTINGS_H
# define SETTINGS_H
#endif

#ifndef stdio_h
#include <stdio.h>
#endif
#ifndef stdlib_h
#include <stdlib.h>
#endif
#ifndef string_h
#include <string.h>
#endif

#ifndef FALSE
# define FALSE 0
# define TRUE !FALSE
#endif

#ifndef SettingsRC
typedef struct SettingsRC{
	int maxCorrection;
	char* dictionaryTextFN;
	int autoCorrect;
}SettingsRC;
#endif

# ifndef VOIDFILEFP
# define VOIDFILEFP 3
# define SETTINGSNULL 4
# define INVALIDSETTINGSRC 5
# define INCOMPLETESETTINGSRC 6
# define BADDICTIONARYFILE 7
# define NOARGSGIVEN 8
# define MAX 100
#endif

void processSettingsFile(SettingsRC *settings, int *success);
void setStruct(SettingsRC *settings);
