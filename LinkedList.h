#ifndef stdio_h
#include <stdio.h>
#endif
#ifndef stdlib_h
#include <stdlib.h>
#endif
#ifndef String_h
#include <String.h>
#endif
#define MAXWORDLEN 50
typedef struct Node {
	char *data;
	struct Node *next;
} Node;

typedef struct{
	Node *head;
} LinkedList;

/* Forward Declarations */
	/*void initLinkedList(LinkedList *ll);*/
	void insertWord (char *word, LinkedList *ll);
	int getLength (LinkedList *ll);
	void readFileToList(FILE *f, LinkedList *ll);
	char* doubleBuffer(char* buffer, int *bufferSize);