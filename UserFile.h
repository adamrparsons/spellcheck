/*	UserFile.h
*/
#ifndef USERFILE_H
#define USERFILE_H
#endif

#ifndef LINKEDLIST_H
#include "LinkedList.h"
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

void readStructuredUserFileToList(LinkedList *ulist, char **argV, int *success);
void stripPunctuation(char* buffer);