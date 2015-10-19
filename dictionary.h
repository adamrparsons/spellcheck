/*	dictionary.h
*/

# define DICTIONARY_H

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

void readStructuredDictionaryToList(SettingsRC *settings, LinkedList *dlist, int *success);
