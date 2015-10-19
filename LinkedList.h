/*	LinkedList.h
*/

# define LINKEDLIST_H

#ifndef stdio_h
#include <stdio.h>
#endif
#ifndef stdlib_h
#include <stdlib.h>
#endif
#ifndef String_h
#include <String.h>
#endif

#ifndef Node
typedef struct Node {
	char *data;
	int dataLen;
	struct Node *next;
} Node;
#endif

typedef struct{
	Node *head;
} LinkedList;


void setList(LinkedList *ll);
int insertWord(LinkedList *, char *word);
int getLength(LinkedList *);
char* dequeue(LinkedList *);
void listToArray(LinkedList *, char ***, int *arrLen, int *success);
