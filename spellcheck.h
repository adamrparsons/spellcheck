/**
* spellcheck.h
* COMP1000 Assignment 2015S2
* Adam Parsons, 17160357
*/

#ifndef stdio_h
#include <stdio.h>
#endif
#ifndef stdlib_h
#include <stdlib.h>
#endif
#ifndef string_h
#include <string.h>
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

#ifndef USERFILE_H
#include "UserFile.h"
#endif

#ifndef CHECK_H
#include "check.h"
#endif

void readSettings(SettingsRC *settings, int *success);
void readDictionaryIntoList(SettingsRC *settings, LinkedList *dlist, int *success);
void readDictionaryListIntoArray(LinkedList *dlist, char ***darr, int *darrLen, int *success);
void readUserFileToList(LinkedList *ulist, char** argV, int *success);
void readUserListToArray(LinkedList *ulist, char ***uarr, int *uarrLen, int *success);
void printUsage(char** argV);
void checkUserSpelling(char** uarr, int uarrLen, char** darr, int arrLen, SettingsRC *settings);
int promptUser(char *word, char *suggestion);
int doNotPromptUser(char *word, char *suggestion);
int writeFileToDisk (char**, int, char** argV);
