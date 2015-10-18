#ifndef stdio_h
#include <stdio.h>
#endif
#ifndef stdlib_h
#include <stdlib.h>
#endif
#ifndef String_h
#include <String.h>
#endif
#include "spellsettings.h"
#ifndef LinkedList_H
#include "LinkedList.h"
#endif

void readDictIntoList(LinkedList*, SettingsRC*);
char** putListIntoArray(LinkedList *dictList);
