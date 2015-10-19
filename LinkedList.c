/* LinkedList.c
*/

# include "LinkedList.h"

/* Set head of list to NULL */
void setList(LinkedList *ll)
{
	if (ll != NULL)
	{
		ll->head = NULL;
	}
	else
	{
		printf("ERROR: LinkedList NOT NULL\n");
	}
}

int insertWord(LinkedList *ll, char *word)
{
	int ret = -1;
	Node *incoming;

	incoming = malloc(sizeof(Node));
	incoming->data = malloc(strlen(word)+1 * sizeof(char));
	incoming->next = ll->head;
	ll->head = incoming;
	/* FIXME: consider using strncpy*/
	strcpy(incoming->data, word);
	if (strcmp(incoming->data, word))
	{
		ret = 0;
	}
	return ret;
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

char* dequeue(LinkedList *ll)
{
	Node *currNode;
	int wordLength;
	char* wordOut = NULL;

	if (ll->head != NULL)
	{	
		currNode = ll->head;
		wordLength = strlen(currNode->data);
		wordOut = malloc(wordLength+1 * sizeof(char));
		strncpy(wordOut, currNode->data, wordLength+1);
		ll->head = currNode->next;
		free(currNode->data);
		free(currNode);
	}
	else 
	{
		fprintf(stderr, "ERROR: Cannot dequeue NULL or empty LinkedList\n");
	}

	return wordOut;
}


void listToArray(LinkedList *list, char ***arr, int *arrLen, int *success)
{
	int listLength, i;

	listLength = getLength(list);
	*arrLen = listLength;
	printf("Processing %d nodes\n", listLength);
	*arr = malloc(listLength * sizeof(char*));
	for (i = 0; i < listLength; i++)
	{
		*(*arr + i) = dequeue(list);
	}
}

void freeList(LinkedList *ll)
{
	Node *currNode, *newNode;
	if (ll != NULL)
	{
		currNode = ll->head;
		while (currNode != NULL)
		{
			newNode = currNode->next;
			free(currNode->data);
			free(currNode);
			currNode = newNode;
		}
	}
}
