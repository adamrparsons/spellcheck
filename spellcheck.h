/*	spellcheck.h
*/

#ifndef stdio_h
#include <stdio.h>
#endif
#ifndef stdlib_h
#include <stdlib.h>
#endif
#ifndef String_h
#include <String.h>
#endif

#ifndef LINKEDLIST_H
#include "LinkedList.h"
#endif

#ifndef SETTINGS_H
#include "Settings.h"
#endif

#ifndef DICTIONARY_H
#include "dictionary.h"
#endif

void readSettings(SettingsRC *settings, int *success);
void readDictionaryIntoList(SettingsRC *settings, LinkedList *dlist, int *success);
void readDictionaryListIntoArray(LinkedList *dlist, char ***darr, int *darrLen, int *success);
void readUserFileToList(LinkedList *ulist, char** argV, int *success);
void readUserListToArray(LinkedList *ulist, int *success);
