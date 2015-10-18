#include "LinkedList.h"

/*void initLinkedList(LinkedList *ll)
{
	if (ll == NULL)
	{
		printf("ERROR: initLinkedList(): LinkedList is NULL\n");
	}
	else 
	{
		if (ll->head != NULL)
		{
			printf("ERROR: initLinkedList(): LinkedList is already initialised\n");
		}
		else
		{
			ll->head = malloc(sizeof(Node));
		}
	}
}*/

void insertWord (char *word, LinkedList *ll)
{
	Node *incoming;

	incoming = malloc(sizeof(Node));
	incoming->data = malloc(strlen(word) * sizeof(char));
	incoming->next = NULL;
	strncpy(incoming->data, word, MAXWORDLEN);
	
	if(getLength(ll) == 0)
	{
		ll->head = incoming;
	}
	else if(getLength(ll) > 0)
	{
		incoming->next = ll->head;
		ll->head = incoming;
	}
	else 
	{
		printf("Something went wrong\n");
	}
}

int getLength (LinkedList *ll)
{
	int length;

	Node *currNode = ll->head;
	if (currNode == NULL)
	{
		length = 0;
	}
	else if (currNode->next == NULL)
	{
		length = 1;
	}
	else
	{
		length = 0;
		while (currNode != NULL)
		{
			length++;
			currNode = currNode->next;
		}
	}

	return length;
}

/* This function will assume words will have punctuation,
whitespace, and newlines anywhere. This will read char-by-char
to fill a single line, process, then move onto the next line */
void readFileToList(FILE *f, LinkedList *ll)
{
	int ch = 0;
	int bufferPosition = 0;
	char* buffer, c;
	int bufferSize = 48;
	buffer = malloc(bufferSize * sizeof(char));
	while (ch != EOF)
	{
		while ((char)ch != '\n')
		{
			if (bufferPosition > bufferSize - 2)
			{
				doubleBuffer(buffer, &bufferSize);
			}
			ch = fgetc(f);
			c = (char)ch;

			/* Eliminates punctuation and other non-letter chars */
			if (((c >= 'a') && (c <= 'z')) ||((c >= 'A') && (c <= 'Z')) || (c == ' '))
			{
				*(buffer + bufferPosition) = ch;
				buffer++;
			}
		}

	}
}

char* doubleBuffer(char* buffer, int *bufferSize)
{
	char* newBuf = malloc(*bufferSize * 2);
	memcpy(newBuf, buffer, *bufferSize);
	free(buffer);
	*bufferSize = *bufferSize * 2;
	return newBuf;
}

